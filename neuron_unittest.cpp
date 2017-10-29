#include "neuron.hpp"
#include "gtest/gtest.h"
#include <iostream>

TEST (NeuronTest, TestSimpleValue)
{
	int x(10);
	
	EXPECT_EQ(10, x);
	///<this test is to be sure that the tests are functional
}

TEST (NeuronTest, NoSpikeForExcitatory)
{
	Neuron neuron(excitatory);
	
	neuron.setIExt(1.0); 
	///<with this value the membrane potential is supposed to tend to 20
	///<but normally it shouldn't pass this value so the neuron should not spike 
	///<even after a lot of time
	
	neuron.update(10000);
	
	///<as the neuron shouldn't spike, the value of getNbSpikes should be equal to 0
	EXPECT_EQ(0, neuron.getNbSpikes());
	
	///<as the membrane potential should tend to 20, the value of 20 - getMembranePot should be near 0
	EXPECT_GT(1e-3, 19.999 - neuron.getMembranePot());
	
	
	neuron.setIExt(0.0);
	///<with this new current value the membrane potential should decrease and tend to 0
	
	neuron.update(20000);
	
	///<the neuron should still not spike
	EXPECT_EQ(0, neuron.getNbSpikes());
	
	///<the membrane potential should tend to 0 again
	EXPECT_NEAR(0, neuron.getMembranePot(), 1e-3);
}


TEST (NeuronTest, NoSpikeForInhibitory)
{
	Neuron neuron(inhibitory);
	
	neuron.setIExt(1.0); 
	///<with this value the membrane potential is supposed to tend to 20
	///<but normally it shouldn't pass this value so the neuron should not spike 
	///<even after a lot of time
	
	neuron.update(10000);
	
	///<as the neuron shouldn't spike, the value of getNbSpikes should be equal to 0
	EXPECT_EQ(0, neuron.getNbSpikes());
	
	///<as the membrane potential should tend to 20, the value of 20 - getMembranePot should be near 0
	EXPECT_GT(1e-3, 19.999 - neuron.getMembranePot());
	
	
	neuron.setIExt(0.0);
	///<with this new current value the membrane potential should decrease and tend to 0
	
	neuron.update(20000);
	
	///<the neuron should still not spike
	EXPECT_EQ(0, neuron.getNbSpikes());
	
	///<the membrane potential should tend to 0 again
	EXPECT_NEAR(0, neuron.getMembranePot(), 1e-3);
}

TEST (NeuronTest, SpikeForExcitatory)
{
	Neuron neuron(excitatory);
	
	neuron.setIExt(2);
	///<with an input bigger than 1 the neuron is supposed to spike
	
	neuron.update(20000);
	
	///<as the neuron should spike, the value of getNbSpikes should be different to 0
	EXPECT_NE(0, neuron.getNbSpikes());
}

TEST (NeuronTest, SpikeForInhibitory)
{
	Neuron neuron(inhibitory);
	
	neuron.setIExt(2);
	///<with an input bigger than 1 the neuron is supposed to spike
	
	neuron.update(20000);
	
	///<as the neuron should spike, the value of getNbSpikes should be different to 0
	EXPECT_NE(0, neuron.getNbSpikes());
}

TEST (NeuronTest, SpikeTimeForExcitatory)
{
	Neuron neuron(excitatory);
	
	neuron.setIExt(1.01);
	///<with this input the first two spike times are supposed to be at 924 steps and 1868 steps
	
	neuron.update(924);
	
	///<as it's just at the time of the spike the value of getNbSpike should be 0
	EXPECT_EQ(0, neuron.getNbSpikes());
	
	neuron.update(1);
	
	///<just one step after the spike has now occured so the value of getNbSpike should be 1
	EXPECT_EQ(1, neuron.getNbSpikes());
	
	///<and the value of the potential should be 0 as the neuron should be refractory
	EXPECT_EQ(0.0, neuron.getMembranePot());
	
	neuron.update(943);
	
	///<as it's just at the time of the second spike the value of getNbSpike should still be 1
	EXPECT_EQ(1, neuron.getNbSpikes());
	
	neuron.update(1);
	
	///<just the steps after the second spike has now occured so the value of getNbSpike should be 2
	EXPECT_EQ(2, neuron.getNbSpikes());
	
	///<and the value of the potential should be 0 as the neuron should be refractory
	EXPECT_EQ(0.0, neuron.getMembranePot());	
}

TEST (NeuronTest, SpikeTimeForInhibitory)
{
	Neuron neuron(inhibitory);
	
	neuron.setIExt(1.01);
	///<with this input the first two spike times are supposed to be at 924 steps and 1868 steps
	
	neuron.update(924);
	
	///<as it's just at the time of the spike the value of getNbSpike should be 0
	EXPECT_EQ(0, neuron.getNbSpikes());
	
	neuron.update(1);
	
	///<just the step after the spike has now occured so the value of getNbSpike should be 1
	EXPECT_EQ(1, neuron.getNbSpikes());
	
	///<and the value of the potential should be 0 as the neuron should be refractory
	EXPECT_EQ(0.0, neuron.getMembranePot());
	
	neuron.update(943);
	
	///<as it's just at the time of the second spike the value of getNbSpike should still be 1
	EXPECT_EQ(1, neuron.getNbSpikes());
	
	neuron.update(1);
	
	///<just the step after the second spike has now occured so the value of getNbSpike should be 2
	EXPECT_EQ(2, neuron.getNbSpikes());
	
	///<and the value of the potential should be 0 as the neuron should be refractory
	EXPECT_EQ(0.0, neuron.getMembranePot());	
}

/*
TEST (NeuronTest, SimpleConnectionExcitatoryExcitatoryWithNoSpikeForTheSecond)
{
	Neuron neuron1(excitatory);
	Neuron neuron2(excitatory);
	
	int delay(15);
	
	neuron1.setIExt(1.01);
	///<neuron1 will spike at steps 924 
	
	neuron2.setIExt(0.0);
	///<neuron2 won't spike 
	
	///<during the 924 first steps neuron1 is not supposed to spike and the potential of neuron2 should stay at 0
	for (int i(0); i < 925 + delay; ++i) {
		
		if(neuron1.update(1)) {
		
		neuron2.receive(i + delay, neuron1.getAmplitude()); 
		
		}
		
		neuron2.update(1);
		
		EXPECT_EQ(0.0, neuron2.getMembranePot());
		
	}
	
	/*
	///<one step after neuron1 should spike and so the update should return true
	neuron1.update(1);
	
	EXPECT_EQ(1, neuron1.getNbSpikes());
	EXPECT_EQ(0.0, neuron1.getMembranePot());
	
	neuron2.receive(925 + delay, neuron1.getAmplitude()); 
	
	EXPECT_EQ(0.0, neuron2.getMembranePot());
	
	///<during the delay the membrane potential of neuron2 should still be 0
	for (int i(0); i < delay; ++i) {
		neuron2.update(1);
		EXPECT_EQ(0.0, neuron2.getMembranePot());
	}
	
	///<after the delay the membrane potential of neuron 2 should be equal to the amplitude of neuron1
	neuron2.update(1);
	
	
	EXPECT_EQ(neuron1.getAmplitude(), neuron2.getMembranePot());
	
}

TEST (NeuronTest, SimpleConnectionInhibitoryInhibitoryWithNoSpikeForTheSecond)
{
	Neuron neuron1(inhibitory);
	Neuron neuron2(inhibitory);
	
	int delay(15);
	
	neuron1.setIExt(1.01);
	///<neuron1 will spike at steps 924 
	
	neuron2.setIExt(0.0);
	///<neuron2 won't spike 
	
	///<during the 924 first steps neuron1 is not supposed to spike and the potential of neuron2 should stay at 0
	for (int i(1); i <= 924; ++i) {
		
		neuron1.update(1);
		
		EXPECT_EQ(0, neuron1.getNbSpikes());
		
		neuron2.update(1);
		
		EXPECT_EQ(0.0, neuron2.getMembranePot());
		
	}
	
	///<one step after neuron1 should spike and so the update should return true
	if (neuron1.update(1)) {
	
	EXPECT_EQ(1, neuron1.getNbSpikes());
	EXPECT_EQ(0.0, neuron1.getMembranePot());
	
	neuron2.receive(925 + delay, neuron1.getAmplitude()); 
	
	EXPECT_EQ(0.0, neuron2.getMembranePot());
	
	}
	
	///<during the delay the membrane potential of neuron2 should still be 0
	for (int i(1); i < delay; ++i) {
		neuron2.update(1);
		EXPECT_EQ(0.0, neuron2.getMembranePot());
	}
	
	///<after the delay the membrane potential of neuron 2 should be equal to the amplitude of neuron1
	neuron2.update(1);
	
	EXPECT_EQ(neuron1.getAmplitude(), neuron2.getMembranePot());
	
}

TEST (NeuronTest, SimpleConnectionExcitatoryInhibitoryWithNoSpikeForTheSecond)
{
	Neuron neuron1(excitatory);
	Neuron neuron2(inhibitory);
	
	int delay(15);
	
	neuron1.setIExt(1.01);
	///<neuron1 will spike at steps 924 
	
	neuron2.setIExt(0.0);
	///<neuron2 won't spike 
	
	///<during the 924 first steps neuron1 is not supposed to spike and the potential of neuron2 should stay at 0
	for (int i(1); i <= 924; ++i) {
		
		neuron1.update(1);
		
		EXPECT_EQ(0, neuron1.getNbSpikes());
		
		neuron2.update(1);
		
		EXPECT_EQ(0.0, neuron2.getMembranePot());
		
	}
	
	///<one step after neuron1 should spike and so the update should return true
	if (neuron1.update(1)) {
	
	EXPECT_EQ(1, neuron1.getNbSpikes());
	EXPECT_EQ(0.0, neuron1.getMembranePot());
	
	neuron2.receive(925 + delay, neuron1.getAmplitude()); 
	
	EXPECT_EQ(0.0, neuron2.getMembranePot());
	
	}
	
	///<during the delay the membrane potential of neuron2 should still be 0
	for (int i(1); i < delay; ++i) {
		neuron2.update(1);
		EXPECT_EQ(0.0, neuron2.getMembranePot());
	}
	
	///<after the delay the membrane potential of neuron 2 should be equal to the amplitude of neuron1
	neuron2.update(1);
	
	EXPECT_EQ(neuron1.getAmplitude(), neuron2.getMembranePot());
	
}

TEST (NeuronTest, SimpleConnectionInhibitoryExcitatoryWithNoSpikeForTheSecond)
{
	Neuron neuron1(inhibitory);
	Neuron neuron2(excitatory);
	
	int delay(15);
	
	neuron1.setIExt(1.01);
	///<neuron1 will spike at steps 924 
	
	neuron2.setIExt(0.0);
	///<neuron2 won't spike 
	
	///<during the 924 first steps neuron1 is not supposed to spike and the potential of neuron2 should stay at 0
	for (int i(1); i <= 924; ++i) {
		
		neuron1.update(1);
		
		EXPECT_EQ(0, neuron1.getNbSpikes());
		
		neuron2.update(1);
		
		EXPECT_EQ(0.0, neuron2.getMembranePot());
		
	}
	
	///<one step after neuron1 should spike and so the update should return true
	if (neuron1.update(1)) {
	
	EXPECT_EQ(1, neuron1.getNbSpikes());
	EXPECT_EQ(0.0, neuron1.getMembranePot());
	
	neuron2.receive(925 + delay, neuron1.getAmplitude()); 
	
	EXPECT_EQ(0.0, neuron2.getMembranePot());
	
	}
	
	///<during the delay the membrane potential of neuron2 should still be 0
	for (int i(1); i < delay; ++i) {
		neuron2.update(1);
		EXPECT_EQ(0.0, neuron2.getMembranePot());
	}
	
	///<after the delay the membrane potential of neuron 2 should be equal to the amplitude of neuron1
	neuron2.update(1);
	
	EXPECT_EQ(neuron1.getAmplitude(), neuron2.getMembranePot());
	
}

TEST (NeuronTest, SimpleConnectionExcitatoryExcitatoryWithSpikeForTheSecond)
{
	Neuron neuron1(excitatory);
	Neuron neuron2(excitatory);
	
	int delay(15);
	
	neuron1.setIExt(1.01);
	///<neuron1 will spike at steps 924 and 1868
	
	neuron2.setIExt(1.0);
	///<neuron2 won't spike alone but as it's a post synaptic neuron it will spike after that neuron1 spikes
	
	///<we have to wait until the second spike to observe the effect on neuron2
	for (int i(0); i < 1869 + delay; ++i) {
		
		if (neuron1.update(1)) {
			
			neuron2.receive(i + delay, neuron1.getAmplitude());
			EXPECT_EQ(0.0, neuron1.getMembranePot()); ///<neuron 1 should be refractory after a spike
		}
		
		neuron2.update(1);
	}
	
	///<just before neuron 2 spike
	EXPECT_EQ(0, neuron2.getNbSpikes());
	
	///<one step after
	EXPECT_EQ(1, neuron2.getNbSpikes());
	EXPECT_EQ(0.0, neuron2.getMembranePot());
}

TEST (NeuronTest, SimpleConnectionExcitatoryInhibitoryWithSpikeForTheSecond)
{
	Neuron neuron1(excitatory);
	Neuron neuron2(inhibitory);
	
	int delay(15);
	
	neuron1.setIExt(1.01);
	///<neuron1 will spike at steps 924 and 1868
	
	neuron2.setIExt(1.0);
	///<neuron2 won't spike alone but as it's a post synaptic neuron it will spike after that neuron1 spikes
	
	///<we have to wait until the second spike to observe the effect on neuron2
	for (int i(0); i < 1869 + delay; ++i) {
		
		if (neuron1.update(1)) {
			
			neuron2.receive(i + delay, neuron1.getAmplitude());
			EXPECT_EQ(0.0, neuron1.getMembranePot()); ///<neuron 1 should be refractory after a spike
		}
		
		neuron2.update(1);
	}
	
	///<just before neuron 2 spike
	EXPECT_EQ(0, neuron2.getNbSpikes());
	
	///<one step after
	EXPECT_EQ(1, neuron2.getNbSpikes());
	EXPECT_EQ(0.0, neuron2.getMembranePot());
}

TEST (NeuronTest, SimpleConnectionInhibitoryExcitatoryWithCurrentForTheSecondToo)
{
	Neuron neuron1(inhibitory);
	Neuron neuron2(excitatory);
	
	int delay(15);
	
	neuron1.setIExt(1.01);
	///<neuron1 will spike at steps 924 and 1868
	
	neuron2.setIExt(1.0);
	///<neuron2 won't spike because neuron 1 in an inhibitory neuron
	
	///<we wait until the second spike 
	for (int i(0); i < 1869 + delay; ++i) {
		
		if (neuron1.update(1)) {
			
			neuron2.receive(i + delay, neuron1.getAmplitude());
			EXPECT_EQ(0.0, neuron1.getMembranePot()); ///<neuron 1 should be refractory after a spike
		}
		
		neuron2.update(1);
	}
	
	///<just before neuron 2 receive the post synaptic signal
	EXPECT_EQ(0, neuron2.getNbSpikes());
	
	///<one step after --> as the pre synaptic neuron is an inhibitory neuron, neuron 2 won't spike
	EXPECT_EQ(0, neuron2.getNbSpikes());
	EXPECT_NEAR(19.999 + neuron1.getAmplitude(), neuron2.getMembranePot(), 1e-3);
}

TEST (NeuronTest, SimpleConnectionInhibitoryInhibitoryWithCurrentForTheSecondToo)
{
	Neuron neuron1(inhibitory);
	Neuron neuron2(inhibitory);
	
	int delay(15);
	
	neuron1.setIExt(1.01);
	///<neuron1 will spike at steps 924 and 1868
	
	neuron2.setIExt(1.0);
	///<neuron2 won't spike because neuron 1 in an inhibitory neuron
	
	///<we wait until the second spike 
	for (int i(0); i < 1869 + delay; ++i) {
		
		if (neuron1.update(1)) {
			
			neuron2.receive(i + delay, neuron1.getAmplitude());
			EXPECT_EQ(0.0, neuron1.getMembranePot()); ///<neuron 1 should be refractory after a spike
		}
		
		neuron2.update(1);
	}
	
	///<just before neuron 2 receive the post synaptic signal
	EXPECT_EQ(0, neuron2.getNbSpikes());
	
	///<one step after --> as the pre synaptic neuron is an inhibitory neuron, neuron 2 won't spike
	EXPECT_EQ(0, neuron2.getNbSpikes());
	EXPECT_NEAR(19.999 + neuron1.getAmplitude(), neuron2.getMembranePot(), 1e-3);
}
*/

	
int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
