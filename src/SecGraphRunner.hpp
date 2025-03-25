#pragma once

#include <string>
#include "IOHandler.hpp"

class SecGraphRunner
{
	public:
		SecGraphRunner();
		int run();
		static std::string getCurrentVersion();
	private:
		enum RunnerState {Init, Anon, Util};

		IOHandler ioHandler;
		RunnerState runnerState;
		bool exitFlag;


};