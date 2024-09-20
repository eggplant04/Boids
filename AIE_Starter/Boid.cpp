#include "Boid.h"
#include "glm/vec2.hpp"
#include <vector>

UtilityAI::Boid::~Boid()
{
	delete m_currentBehaviour;
}

void UtilityAI::Boid::Update(float _dt)
{
	if (m_currentBehaviour)
	{
		m_currentBehaviour->Update(this, _dt);
	}
}

void UtilityAI::Boid::Draw()
{
	DrawCircle(m_position.x, m_position.y, 8.f, m_color);
}

std::vector<UtilityAI::Boid*> UtilityAI::Boid::GetNearbyBoids(std::vector<Boid*>& _boids, float _radius)
{
    std::vector<Boid*> nearbyBoids;

    for (Boid* other : _boids)
    {
        if (other != this) // Don't include itself
        {
            Vector2 otherPos = other->GetPosition();

            float dx = otherPos.x - this->GetPosition().x; // Calculate difference in x
            float dy = otherPos.y - this->GetPosition().y; // Calculate difference in y
            float distance = sqrt(dx * dx + dy * dy); // Calculate Euclidean distance

            if (distance < _radius)
            {
                nearbyBoids.push_back(const_cast<Boid*>(other)); // Add to nearby list
            }
        }
    }

    return nearbyBoids;
}
