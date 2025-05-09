#pragma once
#include <string>

class GraphTheory
{
	public:
		enum class AnonMethod {kDA, USC, DP, RW, Undefined};
		enum class UtilMetric {Deg, EV, CC, BC, Undefined};

		static std::string anonMethodToString(AnonMethod method)
		{
			switch (method)
			{
				case AnonMethod::kDA:
					return "kDA";
				case AnonMethod::USC:
					return "USC";
				case AnonMethod::DP:
					return "DP";
				case AnonMethod::RW:
					return "RW";
				default:
					return "Undefined";
			}

		}

		static AnonMethod anonMethodFromString(const std::string & methodString)
		{
			if (methodString == "kDA" || methodString == "KDA" || methodString == "kda")
				return AnonMethod::kDA;
			if (methodString == "USC" || methodString == "usc")
				return AnonMethod::USC;
			if (methodString == "DP" || methodString == "dp")
				return AnonMethod::DP;
			if (methodString == "RW" || methodString == "rw")
				return AnonMethod::RW;
			return AnonMethod ::Undefined;
		}

		static std::string utilMetricToString(UtilMetric metric)
		{
			switch (metric)
			{
				case UtilMetric::Deg:
					return "deg";
				case UtilMetric::EV:
					return "EV";
				case UtilMetric::CC:
					return "CC";
				case UtilMetric::BC:
					return "BC";
				default:
					return "Undefined";
			}
		}

		static UtilMetric utilMetricFromString(const std::string & metricString)
		{
			if (metricString == "Deg" || metricString == "deg")
				return UtilMetric::Deg;
			if (metricString == "EV" || metricString == "ev")
				return UtilMetric::EV;
			if (metricString == "CC" || metricString == "cc")
				return UtilMetric::CC;
			if (metricString == "BC" || metricString == "bc")
				return UtilMetric::BC;
			return UtilMetric::Undefined;
		}
};