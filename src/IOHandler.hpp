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
		bool setInputPathToSecGraph(fs::path & secgraph, int & exitCode);
		bool setInputPathToSourceGraph(fs::path & sourceGraph, int & exitCode);
		bool setInputPathToAnonymizedGraphDirectory(fs::path & anonymizedDirectory, int & exitCode);
		bool setInputAnonymizationMethod(GraphTheory::AnonMethod & anonMethod, int & exitCode);
		bool setInputUtilityMetric(GraphTheory::UtilMetric & utilMetric, int & exitCode);
		bool setInputPathToUtilityMetricsDirectory(fs::path & utilMetricDir, int & exitCode);
		bool setInputPathToAppILResultsDirectory(fs::path & appILResultsDir, int & exitCode);
		bool setInputPathToAppILScenario(fs::path & appILScenario, int & exitCode);
		bool writeSecGraphPathToConfigFile(const fs::path & secgraph, const fs::path & config);
		bool readDataFromConfigFile(fs::path & config, fs::path & secgraph);
		void loadFileNamesFromDirectory(const fs::path & directory, std::unique_ptr<std::vector<std::string>> & fileNames);
		void loadAllFilesContentFromDirectory(const fs::path & directory, std::unique_ptr<std::vector<std::string>> & linesRead);
		void loadAllFilesContentFromDirectory(const fs::path & directory, std::unique_ptr<std::vector<double>> & valuesRead);


	private:
		void loadNewInput();
		void setupTemporaryFile();
		void loadTemporaryFileToStrings(std::unique_ptr<std::vector<std::string>> & lines);
		void loadTemporaryFileToDoubles(std::unique_ptr<std::vector<double>> & values);
		std::string currentInput;
};