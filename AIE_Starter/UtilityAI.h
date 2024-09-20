#pragma once
#include <vector>

#include "Behaviour.h"

namespace UtilityAI
{
	class UtilityAI : public Behaviour
	{
	public:
		~UtilityAI();
	private:
		std::vector<Behaviour*> m_behaviours;
		Behaviour* m_currentBehaviour;
		std::vector<Boid*> m_boids;

	public:
		virtual void Update(Boid* _boid, float _dt, std::vector<Boid*> _boids);

		void AddBehaviour(Behaviour* _behaviour);
		void AddBoid(Boid* _boid);

		std::vector<Boid*> GetBoids() { return m_boids; }
	};
}


