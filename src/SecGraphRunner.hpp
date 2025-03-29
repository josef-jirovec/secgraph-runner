#pragma once

#include <string>
#include <memory>
#include <experimental/filesystem>
#include "RunnerState.hpp"
#include "IOHandler.hpp"

namespace fs = std::experimental::filesystem;

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
		int exitCode;
		fs::path pathToSourceGraph;
		fs::path pathToAnonymizedGraphDirectory;
};