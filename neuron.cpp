//**** FINAL VERSION ****//

#include "neuron.hpp"
#include <cmath>
#include <random>
#include <iostream>
#include <cassert>

///
///@class Neuron that updates a neuron and determine if it spikes or not
///

///
/// constructor of neuron whith the type given in parametre that determines the amplitude
///

Neuron::Neuron(Type type)
        : type_(type),
          membranePot_(0.0),
          nbSpikes_(0),
          iExt_(0.0),
          clock_(0),
          timeSpike_(0),
          ringBuffer_()
          {
			if (type_ == excitatory) {
				amplitude_ = amplitudeExcitatory_;
			}
			else {
				amplitude_ = amplitudeInhibitory_;
			}
            c1_ = std::exp(-h_/tau_);
            c2_ = R_ * (1 - c1_);
            ringBuffer_.empty();
            ringBuffer_.resize(D_/h_ + 1);
           }
           
///
/// getter of the membrane potential
/// @return membranePot_
///

double Neuron::getMembranePot() const
{
	return membranePot_;
}

///
/// getter of the number of spikes that occured until now
/// @return nbSpikes_
///

double Neuron::getNbSpikes() const
{
	return nbSpikes_;
}

/// 
/// getter of time spike (gives us the time of the last spike)
/// @return timeSpike_
///

long Neuron::getTimeSpike() const
{
	return timeSpike_;
}

///
/// getter of the clock of the neuron
/// @return clock_
///

long Neuron::getClock() const 
{
	return clock_;
}

///
/// getter of the amplitude of the neuron so the signal that it gives to the post synaptic neuron
/// @return amplitude_
///

double Neuron::getAmplitude() const
{
	return amplitude_;
}

/// 
/// setter of the current IExt
/// @param iExt
///
    
void Neuron::setIExt(double iExt)
{
	iExt_ = iExt;
}

///
/// setter of the position of the amplitude signal in the ringbuffer 
/// @param position
///

void Neuron::setRingBuffer(int position)
{
	ringBuffer_[position] += amplitude_;
}

///
/// boolean update a neuron
/// will determine whether the neuron is spiking or not
/// @param steps
/// @return true if the neuron spike
///


bool Neuron::update(long steps)
{   
    bool spikeState = false; ///< initiate the spike state that will be return at the end of the function at false
    
    size_t x(D_/h_ + 1); ///< will be used for the ringbuffer
    
    if (steps < 0) return false; ///< we can't update if there isn't a positive number of steps
    
    const long t_stop(clock_ + steps);
    
    
    while (clock_ < t_stop) {
    
		///
		/// if case to see of the neuron is spiking 
		/// test if the membrane potential is higher that the spike threshold
		/// if it's the case the spike state becomes true, we add a spike to the number of spike and we take the current time of the neuron to be the time spike which represent last time a spike occured
		///
		
		if (membranePot_ >= spikeThr_) {
			
			++nbSpikes_;
			timeSpike_ = clock_;
			spikeState = true;
		}
		
		///
		/// if case to see if the neuron is refractory after the spike or enough time has passed and we won't enter in this if case
		///
		
		if (timeSpike_ > 0 and (clock_ - timeSpike_ < refractorySteps_)) {    ///<if neuron is refractory we have to reset the membrane potential
			
			membranePot_ = 0.0;
			
		}
		
		///
		/// if the neuron is not refractory we have to calculate the membrane potential
		///
		
		else {
			static std::poisson_distribution<> poisson(Vext_ * h); ///< static so it exists only once and like this we don't create pattern
			static std::random_device rd;
			static std::mt19937 gen(rd());
			membranePot_ = c1_ * membranePot_ + iExt_ * c2_ + ringBuffer_[clock_ % x] + amplitudeExcitatory_ * poisson(gen);
			//assert((clock_ % x) >= 0);
			//assert((clock_ % x) <= ringBuffer_.size());
			//ringBuffer_[clock_ % x] = 0.0;
		}
		
		ringBuffer_[clock_ % x] = 0.0;
		
		
		++clock_;
		
	}
    
    return spikeState;
} 

///
/// boolean update a neuron without the poisson function to see is the rest if running correctly
/// will determine whether the neuron is spiking or not
/// @param steps
/// @return true if the neuron spike
///
bool Neuron::updateTest(long steps)
{   
    bool spikeState = false; ///< initiate the spike state that will be return at the end of the function at false
    
    size_t x(D_/h_ + 1); ///< will be used for the ringbuffer
    
    if (steps < 0) return false; ///< we can't update if there isn't a positive number of steps
    
    const long t_stop(clock_ + steps);
    
    
    while (clock_ < t_stop) {
    
		///
		/// if case to see of the neuron is spiking 
		/// test if the membrane potential is higher that the spike threshold
		/// if it's the case the spike state becomes true, we add a spike to the number of spike and we take the current time of the neuron to be the time spike which represent last time a spike occured
		///
		
		if (membranePot_ >= spikeThr_) {
			
			++nbSpikes_;
			timeSpike_ = clock_;
			spikeState = true;
		}
		
		///
		/// if case to see if the neuron is refractory after the spike or enough time has passed and we won't enter in this if case
		///
		
		if (timeSpike_ > 0 and (clock_ - timeSpike_ < refractorySteps_)) {    ///<if neuron is refractory we have to reset the membrane potential
			
			membranePot_ = 0.0;
			
		}
		
		///
		/// if the neuron is not refractory we have to calculate the membrane potential
		///
		
		else {
			membranePot_ = c1_ * membranePot_ + iExt_ * c2_ + ringBuffer_[clock_ % x]; ///<without the poisson factor to avoid the random parametre 
			//assert((clock_ % x) >= 0);
			//assert((clock_ % x) <= ringBuffer_.size());
			//ringBuffer_[clock_ % x] = 0.0;
		}
		
		ringBuffer_[clock_ % x] = 0.0;
		
		++clock_;
		
	}
    
    return spikeState;
}

///
/// void function that can store the spike signal of a pre synaptic neuron in the post synaptic neuron on order to use it after the delay
/// @param steps and amplitude of the pre synaptic neuron
///

void Neuron::receive(long steps, double amplitude)
{
	size_t x(D_/h_ + 1);
	//assert(((steps) % (x)) >= 0);
	//assert(((steps) % (x)) <= ringBuffer_.size());
	ringBuffer_[steps % x] += amplitude;
} 
    
    
