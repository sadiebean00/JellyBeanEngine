#include "Controller.h"

namespace JellyBean_Engine
{
	void Controller::removeKey(int keyCode)
	{
		for (size_t i = 0; i < keyCodes.size(); i++)
		{
			if (keyCodes.at(i) == keyCode)
			{
				keyCodes.erase(keyCodes.begin() + i);
				i--;
			}
		}
	}

	bool Controller::getKey(int keyCode)
	{
		for (size_t i = 0; i < keyCodes.size(); i++)
		{
			if (keyCodes.at(i) == keyCode)
			{
				return true;
			}
		}
		return false;
	}

	bool Controller::getKeyDown(int keyCode)
	{
		return true;
	}

	bool Controller::getKeyUp(int keyCode)
	{
		return false;
	}
}