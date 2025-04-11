#pragma once

#include <string>
#include <memory>
#include <filesystem>
#include <queue>
#include "RunnerState.hpp"
#include "IOHandler.hpp"
#include "GraphTheory.hpp"
#include "ApplicationScenario.hpp"

namespace fs = std::filesystem;

class IOHandler;

class SecGraphRunner
{
	public:
		SecGraphRunner();
		int run();

	private:
		bool createConfigFile();
		bool loadDataFromConfigFile();
		void loadUtilityMetricFileNames();
		void loadUtilityMetricValues();
		fs::path calculateAppIL(const ApplicationScenario & applicationScenario);

		std::unique_ptr<IOHandler> ioHandler;
		RunnerState runnerState;
		bool exitFlag;
		int exitCode;
		fs::path pathToConfig;
		fs::path pathToSecGraph;
		fs::path pathToSourceGraph;
		fs::path pathToAnonymizedGraphDirectory;
		fs::path pathToUtilityMetricsDirectory;
		fs::path pathToAppILResultsDirectory;
		fs::path pathToAppILScenario;
		GraphTheory::AnonMethod anonMethod;
		GraphTheory::UtilMetric utilMetric;
		ApplicationScenario applicationScenario;
		std::unique_ptr<std::vector<std::string>> utilityMetricFileNames;
		std::unique_ptr<std::vector<double>> utilityMetricValues;
};