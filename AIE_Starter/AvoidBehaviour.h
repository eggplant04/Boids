#pragma once
#include "Behaviour.h"

namespace UtilityAI
{
	class AvoidBehaviour : public Behaviour
	{
	public:
		virtual void Enter(Boid* _boid);
		virtual void Update(Boid* _boid, float _dt);
		virtual float Evaluate(Boid* _boid);
	};
}

