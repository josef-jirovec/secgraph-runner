#include "ApplicationScenario.hpp"

ApplicationScenario::ApplicationScenario() : name("default") {};

ApplicationScenario::ApplicationScenario(const std::string & name) : name(name) {};

void ApplicationScenario::addMetric(unsigned int metricRowIndex, double weight)
{
	metricRowIndices.emplace_back(metricRowIndex);
	weights.emplace_back(weight);
}