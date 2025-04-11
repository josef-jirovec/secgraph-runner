#pragma once

#include <vector>
#include <filesystem>
#include <string>
#include "GraphTheory.hpp"

namespace fs = std::filesystem;

class ApplicationScenario
{
	public:
		ApplicationScenario();
		ApplicationScenario(const std::string & name);
		ApplicationScenario(const fs::path & path);
		const std::string & getName() const;
		const unsigned int getMetricRowCount() const;
		const std::vector<unsigned int> & getMetricRowIndices() const;
		const std::vector<double> & getWeights() const;


	private:
		void addMetric(unsigned int metricRowIndex, double weight);

		std::string name;
		unsigned int metricRowCount;
		std::vector<unsigned int> metricRowIndices;
		std::vector<double> weights;


};

