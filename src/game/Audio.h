#pragma once
#include <jellybeanengine/jellybeanengine.h>

using namespace JellyBean_Engine;

struct Audio : Component
{
	void onInit();

	void onInput();

	bool audioStart;
};