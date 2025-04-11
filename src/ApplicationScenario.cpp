#include <fstream>
#include "ApplicationScenario.hpp"

ApplicationScenario::ApplicationScenario() : name("default") {};

ApplicationScenario::ApplicationScenario(const std::string & name) : name(name) {};

ApplicationScenario::ApplicationScenario(const fs::path & path) : name(path.filename())
{

	std::ifstream scenario(path.c_str());
	if(scenario.is_open())
	{
		std::string currentLine;
		std::getline(scenario, currentLine);
		metricRowCount = static_cast<unsigned int>(std::stoul(currentLine));
		while(std::getline(scenario, currentLine))
		{
			size_t spaceIndex = currentLine.find(' ');
			std::string rowIndex = currentLine.substr(0, spaceIndex);
			std::string weight = currentLine.substr(spaceIndex + 1);
			addMetric(std::stoul(rowIndex), std::stod(weight));
		}
		scenario.close();
	}
}


void ApplicationScenario::addMetric(unsigned int metricRowIndex, double weight)
{
	metricRowIndices.emplace_back(metricRowIndex);
	weights.emplace_back(weight);
}

const std::string & ApplicationScenario::getName() const
{
	return name;
}

unsigned int ApplicationScenario::getMetricRowCount() const
{
	return metricRowCount;
}

const std::vector<unsigned int> & ApplicationScenario::getMetricRowIndices() const
{
	return metricRowIndices;
}

