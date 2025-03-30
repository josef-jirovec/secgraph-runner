#pragma once

#include <string>


struct MessageContainer
{
	public:
		inline static const std::string CURRENT_VERSION =
				"SecGraph-Runner, Version 0.1";
		inline static const std::string INPUT_SECGRAPH_PATH =
				"Please enter the absolute path to the SecGraph .jar file:";
		inline static const std::string INPUT_SOURCE_GRAPH =
				"Please enter the absolute path to the source graph:";
		inline static const std::string INPUT_RESULT_GRAPH_DIR =
				"Please enter the absolute path to the directory where you want to store the anonymized graph:";
		inline static const std::string INPUT_ANON_METHOD =
				"Please enter the anonymization method you want to use:";
		inline static const std::string INPUT_UTIL_METRIC =
				"Please enter the utility metric you want to measure:";
		inline static const std::string PROGRAM_EXITED =
				"Exiting SecGraph-Runner.";
		inline static const std::string INVALID_ARGUMENT =
				"Invalid argument.";
		inline static const std::string INVALID_PATH_TO_DIR =
				"Invalid path to the directory.";
		inline static const std::string INVALID_PATH_TO_GRAPH =
				"Invalid path to the graph.";
		inline static const std::string INVALID_PATH_TO_SECGRAPH =
				"Invalid path to the SecGraph .jar file.";
		inline static const std::string PATH_TO_DIR_INSTEAD_OF_GRAPH =
				"The path provided leads to a directory, not a graph.";
		inline static const std::string PATH_TO_GRAPH_INSTEAD_OF_DIR =
				"The path provided leads to a file, not a directory.";
		inline static const std::string INVALID_ANON_METHOD_NAME =
				"The anonymization method entered is not currently supported.";
		inline static const std::string INVALID_UTIL_METRIC_NAME =
				"The utility metric entered is not currently supported.";
		inline static const std::string CHOOSE_ANON_OR_UTIL =
				"Please type \"anon\" for graph anonymization, \"util\" for comparison of graph utility metrics or \"exit\" to quit the program.";
		inline static const std::string ERROR_CONFIG_FILE =
				"An error occurred with the secgraph-runner.config file.";
};