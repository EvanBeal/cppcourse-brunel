#include "neuron.hpp"
#include "gtest/gtest.h"
#include <iostream>

TEST (NeuronTest, testSimpleValue)
{
	int x(10);
	
	EXPECT_EQ(10, x);
	
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
