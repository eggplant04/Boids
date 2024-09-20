#include "SeparateBehaviour.h"

#include "Boid.h"

void UtilityAI::SeparateBehaviour::Enter(Boid* _boid)
{
	_boid->SetColor({ 255, 0, 0, 255 });
}

void UtilityAI::SeparateBehaviour::Update(Boid* _boid, float _dt, std::vector<Boid*> _boids)
{
    std::vector<Boid*> nearbyBoids = _boids; // Assume this method exists and retrieves nearby boids
    Vector2 separationForce = { 0.f, 0.f };

    // Calculate the separation vector
    for (Boid* other : nearbyBoids)
    {
        if (other != _boid)
        {
        	float dx = other->GetPosition().x - _boid->GetPosition().x; // Calculate difference in x
            float dy = other->GetPosition().y - _boid->GetPosition().y; // Calculate difference in y
            float distance = sqrt(dx * dx + dy * dy); // Calculate Euclidean distance

            // Avoid too close proximity
            if (distance < m_separationDistance && distance > 0)
            {
                // Normalize and scale the force
                float directionX = dx / distance;
                float directionY = dy / distance;

                separationForce.x += directionX / distance;
                separationForce.y += directionY / distance;
            }
        }
    }

    // Apply the separation force to the boid
    _boid->AddForce(separationForce); // Assume this method exists to apply forces to the boid

}

float UtilityAI::SeparateBehaviour::Evaluate(Boid* _boid, std::vector<Boid*> _boids)
{
    std::vector<Boid*> nearbyBoids = _boids;
    float score = 0.0f;

    // Calculate a score based on the distance to nearby boids
    for (Boid* other : nearbyBoids)
    {
        if (other != _boid)
        {
            Vector2 otherPos = other->GetPosition();

            float dx = otherPos.x - _boid->GetPosition().x; // Calculate difference in x
            float dy = otherPos.y - _boid->GetPosition().y; // Calculate difference in y
            float distance = sqrt(dx * dx + dy * dy); // Calculate Euclidean distance

            // Inverse score based on distance; closer boids decrease the score
            if (distance < m_separationDistance)
            {
                score += (m_separationDistance - distance); // Higher score for being closer
            }
        }
    }

    return score; // Return the calculated score for separation
}
