#pragma once
#include <iostream>
#include "SecGraphRunner.hpp"
#include "GraphTheory.hpp"

namespace fs = std::filesystem;

class IOHandler
{
	public:
		void printVersion();
		void printExit();
		void printInvalidArgumentError();
		RunnerState chooseRunnerFunctionality();
		bool setInputPathToSourceGraph(fs::path & sourceGraph, int & exitCode);
		bool setInputPathToAnonymizedGraphDirectory(fs::path & anonymizedDirectory, int & exitCode);
		bool setInputAnonymizationMethod(GraphTheory::AnonMethod & anonMethod, int & exitCode);
		bool setInputUtilityMetric(GraphTheory::UtilMetric & utilMetric, int & exitCode);


	private:
		void loadNewInput();
		std::string currentInput;
};