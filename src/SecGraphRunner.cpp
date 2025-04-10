#include <fstream>
#include "SecGraphRunner.hpp"

SecGraphRunner::SecGraphRunner() : exitFlag(false), exitCode(0), runnerState(RunnerState::Init),
								   anonMethod(GraphTheory::AnonMethod::Undefined), utilMetric(GraphTheory::UtilMetric::Undefined),
								   pathToConfig("secgraph-runner.config")
{
	this->ioHandler = std::make_unique<IOHandler>();
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
					//TODO:implement
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

