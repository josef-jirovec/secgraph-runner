#pragma once

#include <string>
#include <memory>
#include <filesystem>
#include "RunnerState.hpp"
#include "IOHandler.hpp"
#include "GraphTheory.hpp"

namespace fs = std::filesystem;

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
		GraphTheory::AnonMethod anonMethod;
		GraphTheory::UtilMetric utilMetric;
};