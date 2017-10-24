#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP


    const double tau_ = 20.0; //membrane time constant = Membrane resistance * C
    const double tauRef_ = 2.0; //refractory time(ms)
	const double R_ = 20.0; //membrane resistance
    const double spikeThr_ = 20.0; //Spike threshold
    const double h_ = 0.1; //stepsize
    const long refractorySteps_ = tauRef_/h_; //steps per tauRef_
    
    const double amplitudeExcitatory_ = 0.1; //the amplitude (J) of the excitatory neuron
    const double amplitudeInhibitory_ = -0.5; //the amplitude (J) of the inhibitory neuron
    const double D_ = 1.5; //the delay
    
    const double connexionExcitatory_ = 1000; //the number of connexion that the neuron receives from exctitatories neurons
    const double connexionInhibitory_ = 250; //the number of connexion that the neuron receives from inhibitories neurons
    
    const double Vext_ = 0.02; //the number of spikes per connexion * ms


#endif
