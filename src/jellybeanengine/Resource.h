#pragma once
#include <string>
#include <memory>


namespace JellyBean_Engine
{
	struct Resources;

	/*
	*	This is our resource class who's main function is to get a 
	*	path from the file specified. This makes it easier for the 
	*	resources to have one unified response rather than a lot of
	*	similar functions.
	*/
	struct Resource
	{
		virtual void onInit();

		std::string getPath();

	private:
		friend struct JellyBean_Engine::Resources;
		
		std::string path;
		
		std::weak_ptr<Resource> self;
		
		std::weak_ptr<Resources> resources;
	};
}