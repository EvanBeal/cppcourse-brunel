# cppcourse-brunel-EvanBeal
Neuron Program

This project represents a simulation of a network of neurons based on the work of Nicolas Brunel "Dynamics of Sparsely Connected Networks of Excitatory and Inhibitory Spiking Neurons".
It's a simulation of 12'500 neurons composed by 80% of excitatory and 20% of inhibitory neurons.
The difference of these neurons is that they send a different post-synaptic signal.
This project simulate the network in order to see which neuron is spiking at what time.

To run the project the user should go directly to the main and use cmake. After doing a make, two executables are created. Neurons, to run the simulation by doing ./Neurons and neuron_unittest, to run the different tests by doing ./neuron_unittest. The user can reproduce the four graphs of the figure 8 of Brunel's work. To do so he has to go in the constants file and uncomment the part of the graph he wants. Note : By default the graph C is uncommented.

There are two classes in this project : Neuron, that represents the simulation of one neuron and determine wether it's spiking or not and Network, that represents the simulation of a lot of neurons with their connections between them.
There are three other files : main, that runs the programm, Constants, where the different constants of the programm are stored and neuron_unittest, where there are different tests that test the programm.

To create the documentation associated to the code, the user can use Doxygen. By entering make doc in the terminal this will directly create all the documentation.
To visualize the results, the user has to go to the following site : https://cs116-plot.antoinealb.net and upload the file spikes.txt that has been created during the simulation and where there is the spike's time and the id of the neuron that spike.
