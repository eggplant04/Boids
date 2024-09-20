#include "SeparateBehaviour.h"

#include "Boid.h"

void UtilityAI::SeparateBehaviour::Enter(Boid* _boid)
{
	_boid->SetColor({ 255, 0, 0, 255 });
}

void UtilityAI::SeparateBehaviour::Update(Boid* _boid, float _dt)
{
}

float UtilityAI::SeparateBehaviour::Evaluate(Boid* _boid)
{
	return 0;
}
