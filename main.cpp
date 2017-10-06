#include <iostream>
#include "neuron.cpp"
#include <fstream>

using namespace std;

double const membranePotIni(0); //initial membrane potential 
sf::Time const refractoryPeriod(milliseconds(2)); //refractory period after a threshold

int main()
{
    //Time
    sf::Time start(milliseconds(0));
    sf::Time stop(milliseconds(1000));
    
    sf::Time h(milliseconds(0.1));
    
    sf::Time simTime(start);
    
    sf::Time refractoryTime(milliseconds(3));
    
    //External Current
    double Iext(400);
    
    //choice of the user
    sf::Time timeInterval(milliseconds(100));
    double I(600);
    
    //test
    Neuron n1(milliseconds(20), 1);
    
    while(simTime < stop) {
        if (timeInterval > start and simTime < timeInterval and I >= 0)
                n1.update(h, I, simTime)
        else
                n1.update(h, Iext, simTime);
        simTime += h;
    }
    
        return 0;
}
