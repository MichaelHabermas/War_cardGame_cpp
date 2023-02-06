#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

namespace hcc
{
	typedef std::unique_ptr<State> StateRef;

	class StateMachine
	{
	public:
		StateMachine() { }
		~StateMachine() { }

		void AddState(StateRef newState, bool isReplacing = true);
		void RemoveState();
		// Run at start of each loop in Game.cpp
		void ProcessStateChanges();

		StateRef& GetActiveState();

	private:
		std::stack<StateRef> m_States;
		StateRef m_NewState;

		bool m_IsRemoving;
		bool m_IsAdding, m_IsReplacing;
	};
}