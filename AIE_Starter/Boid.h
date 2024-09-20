#pragma once
#include <raylib.h>
#include <vector>

#include "Behaviour.h"

namespace UtilityAI
{
	class Boid
	{
	private:
		Vector2 m_position;
		Color m_color;
		UtilityAI::Behaviour* m_currentBehaviour;
		Vector2 m_velocity;

	public:
		Boid(Vector2 _position, Color _color, Behaviour* _behaviour) : m_position(_position), m_color(_color), m_currentBehaviour(_behaviour) {}
		~Boid();

		void Update(float _dt);
		void Draw();

		std::vector<Boid*> GetNearbyBoids(std::vector<Boid*>& allBoids, float radius);

		// Gets And Sets
		void SetColor(Color _color) { m_color = _color; }

		Vector2 GetPosition() { return m_position; }
	};
}


