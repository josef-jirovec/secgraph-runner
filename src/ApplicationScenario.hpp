#pragma once

#include <vector>
#include <string>
#include "GraphTheory.hpp"

class ApplicationScenario
{
	public:
		ApplicationScenario();
		ApplicationScenario(const std::string & name);

		void addMetric(GraphTheory::UtilMetric metric, double weight);
	private:

		std::string name;
		std::vector<GraphTheory::UtilMetric> metrics;
		std::vector<double> weights;


};

