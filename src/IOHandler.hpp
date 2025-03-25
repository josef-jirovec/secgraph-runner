#pragma once
#include <iostream>

class IOHandler
{
	public:
		void printGreeting();

	private:

		void loadNewInput();
		std::string currentInput;
};