#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP


    const double tau_ = 20.0; //membrane time constant = Membrane resistance * C
    const double tauRef_ = 2.0; //refractory time(ms)
	const double R_ = 20.0; //membrane resistance
    const double spikeThr_ = 20.0; //Spike threshold
    const double h_ = 0.1; //stepsize
    const long refractorySteps_ = tauRef_/h_; //steps per tauRef_
    
    const double amplitude_ = 0.1; //the amplitude (J)
    const double D_ = 1.5; //the delay


#endif
