#include "ApplicationScenario.hpp"

ApplicationScenario::ApplicationScenario() : name("default") {};

ApplicationScenario::ApplicationScenario(const std::string & name) : name(name) {};

void ApplicationScenario::addMetric(const GraphTheory::UtilMetric metric, const double weight)
{
	metrics.emplace_back(metric);
	weights.emplace_back(weight);
}