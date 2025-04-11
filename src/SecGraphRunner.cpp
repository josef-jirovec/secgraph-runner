#include <fstream>
#include "SecGraphRunner.hpp"

SecGraphRunner::SecGraphRunner() : exitFlag(false), exitCode(0), runnerState(RunnerState::Init),
								   anonMethod(GraphTheory::AnonMethod::Undefined), utilMetric(GraphTheory::UtilMetric::Undefined)
{
	this->ioHandler = std::make_unique<IOHandler>();
	this->utilityMetricFileNames = std::make_unique<std::vector<std::string>>();
	this->utilityMetricValues = std::make_unique<std::vector<double>>();
	pathToConfig.assign("secgraph-runner.config");
}

int SecGraphRunner::run()
{
	ioHandler->printVersion();
	while(!exitFlag)
	{
		switch (runnerState)
		{
			case RunnerState::Init:
				if(fs::is_regular_file(pathToConfig))
				{
					if(loadDataFromConfigFile())
						runnerState = RunnerState::ModeChoice;
				}
				else
				{
					if(createConfigFile())
						runnerState = RunnerState::ModeChoice;
					else
						runnerState = RunnerState::Exit;
				}
				break;
			case RunnerState::ModeChoice:
				runnerState = ioHandler->chooseRunnerFunctionality();
				break;
			case RunnerState::Anon:
				if(ioHandler->setInputPathToSourceGraph(pathToSourceGraph, exitCode) &&
				   ioHandler->setInputPathToAnonymizedGraphDirectory(pathToAnonymizedGraphDirectory, exitCode) &&
				   ioHandler->setInputAnonymizationMethod(anonMethod, exitCode) &&
				   ioHandler->setInputUtilityMetric(utilMetric, exitCode))
				{
					//TODO: anonymize with multiple threads
				}
				else
				{
					ioHandler->printInvalidArgumentError();
				}
				runnerState = RunnerState::Exit;
				break;
			case RunnerState::Util:
				//TODO:implement
				runnerState = RunnerState::Exit;
				break;
			case RunnerState::AppIL:
				if(ioHandler->setInputPathToAppILScenario(pathToAppILScenario, exitCode) &&
				   ioHandler->setInputPathToUtilityMetricsDirectory(pathToUtilityMetricsDirectory, exitCode) &&
				   ioHandler->setInputPathToAppILResultsDirectory(pathToAppILResultsDirectory, exitCode))
				{
					applicationScenario = ApplicationScenario(pathToAppILScenario);
					loadUtilityMetricFileNames();
					loadUtilityMetricValues();
					fs::path appILResultFile = calculateAppIL(applicationScenario);
				}
				else
				{
					ioHandler->printInvalidArgumentError();
				}
				runnerState = RunnerState::Exit;
				break;
			case RunnerState::Exit:
				exitFlag = true;
				ioHandler->printExit();
				break;
		}
	}
	return exitCode;
}

bool SecGraphRunner::createConfigFile()
{
	std::string command = "touch " + pathToConfig.string();
	std::system(command.c_str());
	return ioHandler->setInputPathToSecGraph(pathToSecGraph, exitCode) &&
		ioHandler->writeSecGraphPathToConfigFile(pathToSecGraph, pathToConfig);
}

bool SecGraphRunner::loadDataFromConfigFile()
{
	return ioHandler->readDataFromConfigFile(pathToConfig, pathToSecGraph);
}

fs::path SecGraphRunner::calculateAppIL(const ApplicationScenario & applicationScenario)
{
	fs::path pathToResult = pathToAppILResultsDirectory;
	pathToResult = pathToResult / applicationScenario.getName();
	if(fs::exists(pathToResult))
		fs::remove(pathToResult);
	std::string command = "touch ";
	command.append(pathToResult.string());
	std::system(command.c_str());

	std::ofstream resultFile(pathToResult);
	if(resultFile.is_open())
	{
		unsigned int utilityMetricIndex = 0;
		unsigned int datasetNamesIndex = 0;
		double sumOfWeightedMetrics = 0;
		while (utilityMetricIndex < utilityMetricValues->size())
		{
			for (size_t i = 0; i < applicationScenario.getMetricRowIndices().size(); i++)
			{
				unsigned int currentMetricRow = applicationScenario.getMetricRowIndices().at(i) + utilityMetricIndex;
				double currentMetricWeight = applicationScenario.getWeights().at(i);
				double currentMetricValue = utilityMetricValues->at(currentMetricRow);
				double weightedMetricValue = currentMetricValue * currentMetricWeight;
				sumOfWeightedMetrics += weightedMetricValue;
			}
			double appIL = 1 - sumOfWeightedMetrics;
			resultFile << utilityMetricFileNames->at(datasetNamesIndex) << ' ' << appIL << std::endl;
			utilityMetricIndex += applicationScenario.getMetricRowCount();
			datasetNamesIndex++;
			sumOfWeightedMetrics = 0;
		}
		resultFile.close();
	}
	return pathToResult;
}

void SecGraphRunner::loadUtilityMetricFileNames()
{
	ioHandler->loadFileNamesFromDirectory(pathToUtilityMetricsDirectory, utilityMetricFileNames);
}

void SecGraphRunner::loadUtilityMetricValues()
{
	ioHandler->loadAllFilesContentFromDirectory(pathToUtilityMetricsDirectory, utilityMetricValues);
}