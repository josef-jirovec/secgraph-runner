#pragma once

#include <vector>
#include <string>
#include "GraphTheory.hpp"

class ApplicationScenario
{
	public:
		ApplicationScenario();
		ApplicationScenario(const std::string & name);

		void addMetric(unsigned int metricRowIndex, double weight);
	private:

		std::string name;
		std::vector<unsigned int> metricRowIndices;
		std::vector<double> weights;


};

