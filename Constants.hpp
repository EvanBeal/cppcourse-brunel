//**** FINAL VERSION ****//

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

///
///@file Constants that stores all the constants used in the programm
///

    const double tau_ = 20.0; ///<membrane time constant = Membrane resistance * C
    const double tauRef_ = 2.0; ///<refractory time(ms)
	const double R_ = 20.0; ///<membrane resistance
    const double spikeThr_ = 20.0; ///<Spike threshold
    const double h_ = 0.1; ///<stepsize
    const long refractorySteps_ = tauRef_/h_; ///<steps per tauRef_
    
    const double amplitudeExcitatory_ = 0.1; ///<the amplitude (J) of the excitatory neuron
    //const double amplitudeInhibitory_ = -0.5; ///<the amplitude (J) of the inhibitory neuron
    const double D_ = 1.5; ///<the delay
    
    const double connexionExcitatory_ = 1000; ///<the number of connexion that the neuron receives from exctitatories neurons
    const double connexionInhibitory_ = 250; ///<the number of connexion that the neuron receives from inhibitories neurons
    
    //const double Vext_ = 20; ///<the number of spikes per connexion / ms
    
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
    
    /*
    ///< graph A
    const double amplitudeInhibitory_ = -0.3; ///<the amplitude (J) of the inhibitory neuron
    const double Vext_ = 20; ///<the number of spikes per connexion / ms    
    const double startCollectingData = 5000; ///<the time in steps where we start to collect data
    const double stopCollectingData = 6000; ///<the time in steps where we stop to collect data
    */
 
	/*
    ///< graph B
    const double amplitudeInhibitory_ = -0.6; ///<the amplitude (J) of the inhibitory neuron
    const double Vext_ = 40; ///<the number of spikes per connexion / ms  
    const double startCollectingData = 10000; ///<the time in steps where we start to collect data
    const double stopCollectingData = 12000; ///<the time in steps where we stop to collect data 
    */
    
    
    ///< graph C
    const double amplitudeInhibitory_ = -0.5; ///<the amplitude (J) of the inhibitory neuron
    const double Vext_ = 20; ///<the number of spikes per connexion / ms
    const double startCollectingData = 10000; ///<the time in steps where we start to collect data
    const double stopCollectingData = 12000; ///<the time in steps where we stop to collect data 
    
    
    /*
    ///< graph D
    const double amplitudeInhibitory_ = -0.45; ///<the amplitude (J) of the inhibitory neuron
    const double Vext_ = 9; ///<the number of spikes per connexion / ms    
    const double startCollectingData = 10000; ///<the time in steps where we start to collect data
    const double stopCollectingData = 12000; ///<the time in steps where we stop to collect data 
    */


#endif
