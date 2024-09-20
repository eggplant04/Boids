#include "AlignBehaviour.h"

#include "Boid.h"

void UtilityAI::AlignBehaviour::Enter(Boid* _boid)
{
	_boid->SetColor({ 255, 0, 0, 255 });
}

void UtilityAI::AlignBehaviour::Update(Boid* _boid, float _dt)
{
}

float UtilityAI::AlignBehaviour::Evaluate(Boid* _boid)
{
	return 0;
}
