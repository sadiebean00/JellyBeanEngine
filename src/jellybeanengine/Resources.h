#pragma once
#include <memory>
#include <string>
#include <vector>


namespace JellyBean_Engine
{
	struct Resource;

	/*
	*	This is our main resource class, which has a template function
	*	similar to our entity class. This function allows us to load
	*	in a custom path to our resource that we are utilising, 
	*	therefore using less memory storage.
	*/

	struct Resources
	{
		template <typename T>
		std::shared_ptr<T> load(const std::string& _path)
		{
			std::shared_ptr<T> rtn;

			for (size_t ri = 0; ri < resources.size(); ri++)
			{
				std::shared_ptr<Resource> r = resources.at(ri);
				if (r->path != path) continue;
				rtn = std::dynamic_pointer_cast<T>(r);
				if (rtn) return rtn;
			}

			rtn = std::make_shared<T>();
			rtn->path = _path;
			rtn->resources = self;
			rtn->onInit();
			resources.push_back(rtn);
			return rtn;
		}

	private:
		std::string path;
		std::weak_ptr<Resources> self;
		std::vector <std::shared_ptr<Resource>> resources;
	};


}