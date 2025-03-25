#include "IOHandler.hpp"
#include "SecGraphRunner.hpp"

void IOHandler::printGreeting()
{
	std::cout << "secgraph-runner, version " << SecGraphRunner::getCurrentVersion();
}

void IOHandler::loadNewInput()
{
	std::cin >> currentInput;
}
