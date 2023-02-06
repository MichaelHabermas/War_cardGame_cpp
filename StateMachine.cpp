#include "StateMachine.hpp"

namespace hcc
{
	void StateMachine::AddState(StateRef newState, bool isReplacing)
	{
		this->m_IsAdding = true;
		this->m_IsReplacing = isReplacing;

		this->m_NewState = std::move(newState);
	}

	void StateMachine::RemoveState()
	{
		this->m_IsRemoving = true;
	}

	void StateMachine::ProcessStateChanges()
	{
		if (this->m_IsRemoving && !this->m_States.empty())
		{
			this->m_States.pop();

			if (!this->m_States.empty())
			{
				this->m_States.top()->Resume();
			}

			this->m_IsRemoving = false;
		}

		if (this->m_IsAdding)
		{
			if (!this->m_States.empty())
			{
				if (this->m_IsReplacing)
				{
					this->m_States.pop();
				}
				else
				{
					this->m_States.top()->Pause();
				}
			}

			this->m_States.push(std::move(this->m_NewState));
			this->m_States.top()->Init();
			this->m_IsAdding = false;
		}
	}

	StateRef& StateMachine::GetActiveState()
	{
		return this->m_States.top();
	}
}