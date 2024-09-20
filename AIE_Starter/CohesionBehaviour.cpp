#include "CohesionBehaviour.h"

#include "Boid.h"

void UtilityAI::CohesionBehaviour::Enter(Boid* _boid)
{

	_boid->SetColor({ 255, 0, 0, 255 });
}

void UtilityAI::CohesionBehaviour::Update(Boid* _boid, float _dt)
{
}

float UtilityAI::CohesionBehaviour::Evaluate(Boid* _boid)
{
	return 0;
}
