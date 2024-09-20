#pragma once

namespace UtilityAI
{
	class Boid;

	class Behaviour
	{
	public:
		virtual ~Behaviour() = default;

		virtual void Enter(Boid* _void) {}
		virtual void Update(Boid* _void, float _dt) = 0;
		virtual void Exit(Boid* _void) {}

		virtual float Evaluate(Boid* _void) { return 0.0f; }
	};
}

