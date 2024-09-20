#include "UtilityAI.h"

#include <iostream>

UtilityAI::UtilityAI::~UtilityAI()
{
	for (Behaviour* b : m_behaviours)
	{
		delete b;
	}
}

void UtilityAI::UtilityAI::Update(Boid* _boid, float _dt, std::vector<Boid*> _boids)
{
	float bestEval = 0;
	Behaviour* newBehaviour = nullptr;
	for (Behaviour* b : m_behaviours)
	{
		float eval = b->Evaluate(_boid, m_boids);
		if (eval > bestEval)
		{
			bestEval = eval;
			newBehaviour = b;
		}
	}

	if (newBehaviour != nullptr && newBehaviour != m_currentBehaviour)
	{
		if (m_currentBehaviour)
		{
			m_currentBehaviour->Exit(_boid);
		}
		m_currentBehaviour = newBehaviour;
		m_currentBehaviour->Enter(_boid);
	}
	if (m_currentBehaviour)
	{
		m_currentBehaviour->Update(_boid, _dt);
	}
}

void UtilityAI::UtilityAI::AddBehaviour(UtilityAI::Behaviour* _behaviour)
{
	m_behaviours.emplace_back(_behaviour);
}

void UtilityAI::UtilityAI::AddBoid(Boid* _boid)
{
	m_boids.emplace_back(_boid);
}
