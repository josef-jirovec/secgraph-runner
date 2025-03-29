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

bool IOHandler::setInputPathToSourceGraph(fs::path & sourceGraph)
{
	std::cout << MessageContainer::INPUT_SOURCE_GRAPH << '\n';
	std::cin >> currentInput;
	sourceGraph.clear();
	sourceGraph.assign(currentInput);
	if(fs::exists(sourceGraph))
	{
		if(fs::is_directory(sourceGraph))
		{
			std::cout << MessageContainer::INVALID_PATH_TO_GRAPH << '\n';
			std::cout << MessageContainer::PATH_TO_DIR_INSTEAD_OF_GRAPH << '\n';
			sourceGraph.clear();
			return false;
		}
		return true;
	}
	else
	{
		std::cout << MessageContainer::INVALID_PATH_TO_GRAPH << '\n';
		sourceGraph.clear();
		return false;
	}
}

bool IOHandler::setInputPathToAnonymizedGraphDirectory(fs::path & anonymizedDirectory)
{
	std::cout << MessageContainer::INPUT_RESULT_GRAPH_DIR << '\n';
	std::cin >> currentInput;
	anonymizedDirectory.clear();
	anonymizedDirectory.assign(currentInput);
	if(fs::exists(anonymizedDirectory))
	{
		if(!fs::is_directory(anonymizedDirectory))
		{
			std::cout << MessageContainer::INVALID_PATH_TO_DIR << '\n';
			std::cout << MessageContainer::PATH_TO_GRAPH_INSTEAD_OF_DIR << '\n';
			anonymizedDirectory.clear();
			return false;
		}
		return true;
	}
	else
	{
		std::cout << MessageContainer::INVALID_PATH_TO_DIR << '\n';
		anonymizedDirectory.clear();
		return false;
	}
}
