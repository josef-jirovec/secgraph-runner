#include <fstream>
#include "IOHandler.hpp"
#include "MessageContainer.hpp"

void IOHandler::printVersion()
{
	std::cout << MessageContainer::CURRENT_VERSION << std::endl;
}

void IOHandler::loadNewInput()
{
	std::cin >> currentInput;
}

RunnerState IOHandler::chooseRunnerFunctionality()
{
	std::cout << MessageContainer::CHOOSE_ANON_OR_UTIL << std::endl;
	loadNewInput();
	if(currentInput == "anon")
		return RunnerState::Anon;
	if(currentInput == "util")
		return RunnerState::Util;
	if(currentInput == "appil" || "AppIL")
		return RunnerState::AppIL;
	if(currentInput == "exit" || std::cin.eof())
		return RunnerState::Exit;
	printInvalidArgumentError();
	return RunnerState::Exit;
}

void IOHandler::printExit()
{
	std::cout << MessageContainer::PROGRAM_EXITED << std::endl;
}

void IOHandler::printInvalidArgumentError()
{
	std::cout << MessageContainer::INVALID_ARGUMENT << std::endl;
}

bool IOHandler::setInputPathToSecGraph(fs::path & secgraph, int & exitCode)
{
	std::cout << MessageContainer::INPUT_SECGRAPH_PATH << std::endl;
	loadNewInput();
	secgraph.clear();
	secgraph.assign(currentInput);
	if(!fs::is_regular_file(secgraph))
	{
		std::cout << MessageContainer::INVALID_PATH_TO_SECGRAPH<< std::endl;
		secgraph.clear();
		exitCode = 6;
		return false;
	}
	else
		return true;

}

bool IOHandler::setInputPathToSourceGraph(fs::path & sourceGraph, int & exitCode)
{
	std::cout << MessageContainer::INPUT_SOURCE_GRAPH << std::endl;
	loadNewInput();
	sourceGraph.clear();
	sourceGraph.assign(currentInput);
	if(fs::exists(sourceGraph))
	{
		if(fs::is_directory(sourceGraph))
		{
			std::cout << MessageContainer::INVALID_PATH_TO_GRAPH << std::endl;
			std::cout << MessageContainer::PATH_TO_DIR_INSTEAD_OF_GRAPH << std::endl;
			sourceGraph.clear();
			exitCode = 1;
			return false;
		}
		return true;
	}
	else
	{
		std::cout << MessageContainer::INVALID_PATH_TO_GRAPH << std::endl;
		sourceGraph.clear();
		exitCode = 2;
		return false;
	}
}

bool IOHandler::setInputPathToAnonymizedGraphDirectory(fs::path & anonymizedDirectory, int & exitCode)
{
	std::cout << MessageContainer::INPUT_RESULT_GRAPH_DIR << std::endl;
	loadNewInput();
	anonymizedDirectory.clear();
	anonymizedDirectory.assign(currentInput);
	if(fs::exists(anonymizedDirectory))
	{
		if(!fs::is_directory(anonymizedDirectory))
		{
			std::cout << MessageContainer::INVALID_PATH_TO_DIR << std::endl;
			std::cout << MessageContainer::PATH_TO_GRAPH_INSTEAD_OF_DIR << std::endl;
			anonymizedDirectory.clear();
			exitCode = 3;
			return false;
		}
		return true;
	}
	else
	{
		std::cout << MessageContainer::INVALID_PATH_TO_DIR << std::endl;
		anonymizedDirectory.clear();
		exitCode = 4;
		return false;
	}
}

bool IOHandler::setInputAnonymizationMethod(GraphTheory::AnonMethod & anonMethod, int & exitCode)
{
	std::cout << MessageContainer::INPUT_ANON_METHOD << std::endl;
	std::cin >> currentInput;
	anonMethod = GraphTheory::anonMethodFromString(currentInput);
	if(anonMethod == GraphTheory::AnonMethod::Undefined)
	{
		std::cout << MessageContainer::INVALID_ANON_METHOD_NAME << std::endl;
		exitCode = 4;
		return false;
	}
	return true;
}

bool IOHandler::setInputUtilityMetric(GraphTheory::UtilMetric & utilMetric, int & exitCode)
{
	std::cout << MessageContainer::INPUT_UTIL_METRIC << std::endl;
	loadNewInput();
	utilMetric = GraphTheory::utilMetricFromString(currentInput);
	if(utilMetric == GraphTheory::UtilMetric::Undefined)
	{
		std::cout << MessageContainer::INVALID_UTIL_METRIC_NAME << std::endl;
		exitCode = 5;
		return false;
	}
	return true;
}

bool IOHandler::writeSecGraphPathToConfigFile(const fs::path & secgraph, const fs::path & config)
{
	std::ofstream configFile(config.c_str());
	if(configFile.is_open())
	{
		configFile << secgraph.c_str() << std::endl;
		configFile.close();
		return true;
	}
	return false;
}

bool IOHandler::readDataFromConfigFile(fs::path &config, fs::path & secgraph)
{
	std::ifstream configFile(config.c_str());
	std::string currentLine;
	if(configFile.is_open())
	{
		std::getline(configFile, currentLine);
		secgraph.assign(currentLine);
		configFile.close();
		if(fs::is_regular_file(currentLine.c_str()))
		{
			return true;
		}
		else
		{
			std::string removeInvalidConfigFile = "rm " + config.string();
			std::system(removeInvalidConfigFile.c_str());
			secgraph.clear();
		}
	}
	std::cout << MessageContainer::ERROR_CONFIG_FILE << std::endl;
	return false;
}

bool IOHandler::setInputPathToUtilityMetricsDirectory(fs::path & utilMetricDir, int & exitCode)
{
	std::cout << MessageContainer::INPUT_UTIL_METRIC_DIR << std::endl;
	loadNewInput();
	utilMetricDir.clear();
	utilMetricDir.assign(currentInput);
	if(fs::is_directory(utilMetricDir))
		return true;
	else
	{
		std::cout << MessageContainer::INVALID_PATH_TO_DIR << std::endl;
		exitCode = 6;
		return false;
	}
}
bool IOHandler::setInputPathToAppILResultsDirectory(fs::path & appILResultsDir, int & exitCode)
{
	std::cout << MessageContainer::INPUT_APPIL_RESULTS_DIR << std::endl;
	loadNewInput();
	appILResultsDir.clear();
	appILResultsDir.assign(currentInput);
	if(fs::is_directory(appILResultsDir))
		return true;
	else
	{
		std::cout << MessageContainer::INVALID_PATH_TO_DIR << std::endl;
		exitCode = 7;
		return false;
	}
}
bool IOHandler::setInputPathToAppILScenario(fs::path & appILScenario, int & exitCode)
{
	std::cout << MessageContainer::INPUT_SCENARIO_FILE << std::endl;
	loadNewInput();
	appILScenario.clear();
	appILScenario.assign(currentInput);
	if(fs::is_regular_file(appILScenario))
		return true;
	else
	{
		std::cout << MessageContainer::INVALID_PATH_TO_SCENARIO << std::endl;
		exitCode = 7;
		return false;
	}
}