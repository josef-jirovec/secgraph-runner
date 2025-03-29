#pragma once
#include <iostream>
#include "SecGraphRunner.hpp"

namespace fs = std::experimental::filesystem;

class IOHandler
{
	public:
		void printVersion();
		void printExit();
		void printInvalidArgumentError();
		RunnerState chooseRunnerFunctionality();
		bool setInputPathToSourceGraph(fs::path & sourceGraph);
		bool setInputPathToAnonymizedGraphDirectory(fs::path & anonymizedDirectory);

	private:
		void loadNewInput();
		std::string currentInput;
};