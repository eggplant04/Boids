#pragma once
#include "Behaviour.h"

namespace UtilityAI
{
	class SeparateBehaviour : public Behaviour
	{
	public:
		float m_separationDistance = 500;
	public:
		virtual void Enter(Boid* _boid);
		virtual void Update(Boid* _boid, float _dt, std::vector<Boid*> _boids);
		virtual float Evaluate(Boid* _boid, std::vector<Boid*> _boids);
	};
}

