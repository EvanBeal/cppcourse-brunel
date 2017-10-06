#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>

class Neuron
{
    private : 
    double membranePot_; // membrane potential
    double nbSpikes_; //number of spikes    
    vector <double> spikesOccured_; //times when the spikes occured
    bool isRefractory_; //determine if the neuron is refractory or not
    sf::Time tau_; //Time constant = Membrane resistance * C
    sf::Time tauRef_;
    double C_; //Number of connections
    double maxPot_; //Neuron threshold potential
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
    
    //update (will update the membrane potential and determine when there is a threshold)
    void update(sf::Time dt, double current, sf::Time simTime);
    
};

#endif
