#include "SecGraphRunner.hpp"
#include "MessageContainer.hpp"

SecGraphRunner::SecGraphRunner()
{
	this->runnerState = SecGraphRunner::RunnerState::Init;
	exitFlag = false;
}

int SecGraphRunner::run()
{
	ioHandler.printGreeting();
	while(!exitFlag)
	{
		switch (runnerState)
		{
			case Init:
				break;
			case Anon:
				break;
			case Util:
				break;
		}
	}


	return 0;
}

std::string SecGraphRunner::getCurrentVersion()
{
	return MessageContainer::CURRENT_VERSION;
}