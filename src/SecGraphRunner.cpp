#include "SecGraphRunner.hpp"

SecGraphRunner::SecGraphRunner() : exitFlag(false), exitCode(0), runnerState(RunnerState::Init),
								   anonMethod(GraphTheory::AnonMethod::Undefined), utilMetric(GraphTheory::UtilMetric::Undefined)
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
				runnerState = ioHandler->chooseRunnerFunctionality();
				break;
			case RunnerState::Anon:
				if(ioHandler->setInputPathToSourceGraph(pathToSourceGraph, exitCode) &&
				   ioHandler->setInputPathToAnonymizedGraphDirectory(pathToAnonymizedGraphDirectory, exitCode) &&
				   ioHandler->setInputAnonymizationMethod((anonMethod), exitCode) &&
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
			case RunnerState::Exit:
				exitFlag = true;
				ioHandler->printExit();
				break;
		}
	}
	return exitCode;
}
