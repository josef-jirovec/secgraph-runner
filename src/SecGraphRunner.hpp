#pragma once

#include <string>
#include <memory>
#include "RunnerState.hpp"
#include "IOHandler.hpp"

class IOHandler;

class SecGraphRunner
{
	public:
		SecGraphRunner();
		int run();

	private:
		std::unique_ptr<IOHandler> ioHandler;
		RunnerState runnerState;
		bool exitFlag;
		std::string pathToSourceGraph;
		std::string pathToAnonymizedGraphDirectory;
};