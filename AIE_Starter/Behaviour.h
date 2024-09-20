#pragma once
#include <vector>

namespace UtilityAI
{
	class Boid;

	class Behaviour
	{
	public:
		virtual ~Behaviour() = default;

		virtual void Enter(Boid* _void) {}
		virtual void Update(Boid* _void, float _dt, std::vector<Boid*> _boids) = 0;
		virtual void Exit(Boid* _void) {}

		virtual float Evaluate(Boid* _void, std::vector<Boid*> _boids) { return 0.0f; }
	};
}

