#pragma once

#include <exception>
#include <string>

namespace JellyBean_Engine
{
	/*
	*	This is the exception class that throws errors whenever the 
	*	program may break on us. This can also provide us with more
	*	detailed errors than the standard debugger can provide us 
	*	with.
	*/

	struct Exception : public std::exception
	{
		Exception(const std::string& message);
		virtual ~Exception() throw();
		virtual const char* what() const throw();

	private:
		std::string message;

	};
}