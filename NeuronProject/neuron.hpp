#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>

class Neuron
{
    private : 
    // static int neuronTime_;
    double membranePot_; // membrane potential
    double nbSpikes_; //number of spikes    
    vector <double> spikesOccured_; //times when the spikes occured
    bool isExcited_; //determine if the neuron is excited or inhibated
    sf::Time tau_;
    sf::Time tauRef_;
    double C_;
    double maxPot_;
    vector <double> membranePotentials_; // all the membrane potential between tstart and tstop

    
    public :
    Neuron(sf::Time tau, double C); //constructor
    ~Neuron(); //destructor
    
    /*
    //getter
    double getMembranePot() const;
    double getNbSpikes() const;
    vector getSpikesOccured() const;
    
    //setter
    void setMembranePot(double);
    void setNbSpikes(double);
    void setSpikesOccured(vector <double>);
    */
    
    //update
    void update(sf::Time dt, double current, sf::Time simTime);
    
};

#endif
