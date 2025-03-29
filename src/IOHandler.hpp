#pragma once
#include <iostream>
#include "SecGraphRunner.hpp"

class IOHandler
{
	public:
		void printVersion();
		void printExit();
		void printInvalidArgumentError();
		RunnerState chooseRunnerFunctionality();
		bool setInputPathToSourceGraph(std::string & sourceGraph);
		bool setInputPathToAnonymizedGraphDirectory(std::string & anonymizedDirectory);

	private:
		void loadNewInput();
		std::string currentInput;
};