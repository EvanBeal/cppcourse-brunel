#include "neuron.hpp"
#include <cmath>

Neuron::Neuron()
        : refractorySteps_(tauRef_/h_),
          membranePot_(0.0),
          nbSpikes_(0),
          iExt_(0.0),
          clock_(0),
          timeSpike_(0),
          amplitude_(0.1),
          D_(1.5),
          ringBuffer_()
          {
            c1_ = std::exp(-h_/tau_);
            c2_ = R_ * (1 - c1_);
            ringBuffer_.empty();
            ringBuffer_.resize(D_/h_ + 1);
           }

double Neuron::getMembranePot() const
{
	return membranePot_;
}

double Neuron::getNbSpikes() const
{
	return nbSpikes_;
}

long Neuron::getTimeSpike() const
{
	return timeSpike_;
}

long Neuron::getClock() const 
{
	return clock_;
}

double Neuron::getJ() const
{
	return amplitude_;
}
    
void Neuron::setIExt(double iExt)
{
	iExt_ = iExt;
}

void Neuron::setRingBuffer(int position)
{
	ringBuffer_[position] += amplitude_;
}


bool Neuron::update(long steps)
{   
    bool spikeState = false;
    
    int x(D_/h_ + 1);
    
    if (steps <= 0) return false; 
    
		
		if (membranePot_ >= spikeThr_) {
			
			++nbSpikes_;
			timeSpike_ = clock_;
			spikeState = true;
			
		}
		
		//see if the neuron is refractory after the spike or enough time has passed and we won't enter in this if case
		
		if (timeSpike_ > 0 and (clock_ - timeSpike_ < refractorySteps_)) {    //if neuron is refractory we have to reset the membrane potential
			
			membranePot_ = 0.0;
			
		}
		
		else {
			
			membranePot_ = c1_ * membranePot_ + iExt_ * c2_ + ringBuffer_[steps % x];
			ringBuffer_[steps % x] = 0.0;
		}
		
		++clock_;
    
    return spikeState;
} 

void Neuron::receive(long steps, double amplitude)
{
	int x(D_/h_ + 1);
	ringBuffer_[steps % x] += amplitude;
} 
    
    
    /*if (isRefractory_ or refractoryTime < refractoryPeriod) {
		membranePot_ = 0;
		membranePotentials_.push_back(0);
	}
	
	else {
					//spike ? (if the membrane pot is bigger than the threshold potential then there is a spike)
    if (membranePot_ >= maxPot_) {
			++nbSpikes_;
			spikesOccured_.push_back(simTime);
			writeSpikeTime(simTime);			//need to store spike time in a file
			membranePot_ = membranePotIni;
			refractoryTime = sf::Milliseconds(0); //after the spike there is a refractory time of 2ms where the membrane potential is equal to 0
		}
    
    membranePot_ = exp(-h/tau) * membranePot_ + current * (tau_/C_) * (1- exp(-h/tau));
    
    membranePotentials_.push_back(membranePot_);
    //membranePotentials_.push_back(simTime);
	}
	*/

/*
void Neuron::writeSpikeTime(sf::Time simTime)
{
	ofstream data(spikes.txt);
    if (data.fail()) {
        cerr << "Erreur : impossible d'ecrire"
                << " dans le fichier spikes.txt " << endl;
        } else {
            data << simTime << endl;
            }
       //data.close();	
}
*/
