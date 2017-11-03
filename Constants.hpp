#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP


    const double tau_ = 20.0; ///<membrane time constant = Membrane resistance * C
    const double tauRef_ = 2.0; ///<refractory time(ms)
	const double R_ = 20.0; ///<membrane resistance
    const double spikeThr_ = 20.0; ///<Spike threshold
    const double h_ = 0.1; ///<stepsize
    const long refractorySteps_ = tauRef_/h_; ///<steps per tauRef_
    
    const double amplitudeExcitatory_ = 0.1; ///<the amplitude (J) of the excitatory neuron
    const double amplitudeInhibitory_ = -0.5; ///<the amplitude (J) of the inhibitory neuron
    const double D_ = 1.5; ///<the delay
    
    const double connexionExcitatory_ = 1000; ///<the number of connexion that the neuron receives from exctitatories neurons
    const double connexionInhibitory_ = 250; ///<the number of connexion that the neuron receives from inhibitories neurons
    
    const double Vext_ = 20; ///<the number of spikes per connexion / ms
    
    ///
    ///Steps
    ///
    const double start(0);
    const double stop(10000);
    const double h(0.1); ///<1 step = 0.1ms
    
    ///
    ///External Current
    ///
    const double Iext(0.0);
    
    ///
    ///test with a network of 12'500 neurons with 80% of excitatory neurons and 20% of inhibitory
    ///
    const double numberNeurons(12500);


#endif
