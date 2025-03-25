#include <memory>
#include "SecGraphRunner.hpp"


int main()
{
	std::unique_ptr<SecGraphRunner> secGraphRunner = std::make_unique<SecGraphRunner>();
	return secGraphRunner->run();
}
