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

	public:
		virtual void Update(Boid* _boid, float _dt);

		void AddBehaviour(Behaviour* _behaviour);
	};
}


