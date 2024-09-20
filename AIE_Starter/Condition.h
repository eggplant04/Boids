#pragma once

namespace UtilityAI
{
	class Condition
	{
	public:
		virtual bool IsTrue(Boid* _boid) = 0;
	};
}
