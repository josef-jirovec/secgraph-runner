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
					fs::path appILResult = calculateAppIL(applicationScenario);
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
	return fs::path();
}

void SecGraphRunner::loadUtilityMetricFileNames()
{
	ioHandler->loadFileNamesFromDirectory(pathToUtilityMetricsDirectory, utilityMetricFileNames);
}

void SecGraphRunner::loadUtilityMetricValues()
{
	ioHandler->loadAllFilesContentFromDirectory(pathToUtilityMetricsDirectory, utilityMetricValues);
}