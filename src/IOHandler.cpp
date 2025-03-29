#include "IOHandler.hpp"
#include "MessageContainer.hpp"

void IOHandler::printVersion()
{
	std::cout << MessageContainer::CURRENT_VERSION << '\n';
}

void IOHandler::loadNewInput()
{
	std::cin >> currentInput;
}

RunnerState IOHandler::chooseRunnerFunctionality()
{
	std::cout << MessageContainer::CHOOSE_ANON_OR_UTIL << '\n';
	loadNewInput();
	if(currentInput == "anon")
			return RunnerState::Anon;
	if(currentInput == "util")
			return RunnerState::Util;
	if(currentInput == "exit" || std::cin.eof())
		return RunnerState::Exit;
	printInvalidArgumentError();
	return RunnerState::Exit;
}

void IOHandler::printExit()
{
	std::cout << MessageContainer::PROGRAM_EXITED << '\n';
}

void IOHandler::printInvalidArgumentError()
{
	std::cout << MessageContainer::INVALID_ARGUMENT << '\n';
}

bool IOHandler::setInputPathToSourceGraph(std::string & sourceGraph)
{
	return true;
}

bool IOHandler::setInputPathToAnonymizedGraphDirectory(std::string & anonymizedDirectory)
{
	return true;
}
