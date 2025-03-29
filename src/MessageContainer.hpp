#pragma once

#include <string>


struct MessageContainer
{
	public:
		inline static const std::string CURRENT_VERSION =
				"SecGraph-Runner, Version 0.1";
		inline static const std::string INPUT_SOURCE_GRAPH_DIR =
				"Please enter absolute path to the directory with source graphs:";
		inline static const std::string INPUT_RESULT_GRAPH_DIR =
				"Please enter the absolute path to the directory where you want to store the anonymized graph.";
		inline static const std::string PROGRAM_EXITED =
				"Exiting SecGraph-Runner.";
		inline static const std::string INVALID_ARGUMENT =
				"Invalid argument.";
		inline static const std::string INVALID_PATH_TO_DIR =
				"Invalid path to the directory.";
		inline static const std::string INVALID_PATH_TO_GRAPH =
				"Invalid path to the graph.";
		inline static const std::string CHOOSE_ANON_OR_UTIL =
				"Please type \"anon\" for graph anonymization or \"util\" for comparison of graph utility metrics.";
};