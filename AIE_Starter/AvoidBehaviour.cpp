#include "AvoidBehaviour.h"

#include "Boid.h"

void UtilityAI::AvoidBehaviour::Enter(Boid* _boid)
{
	_boid->SetColor({ 255, 0, 0, 255 });
}

void UtilityAI::AvoidBehaviour::Update(Boid* _boid, float _dt)
{
}

float UtilityAI::AvoidBehaviour::Evaluate(Boid* _boid)
{
	return 0;
}
