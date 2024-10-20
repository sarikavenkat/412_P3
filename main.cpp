#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "LoadBalancer.h"
#include <vector>

using namespace std;

/**
 * @file main.cpp
 * @brief Main entry point for the Load Balancer simulation. Input for number of cycles and number of web servers.
 */

/**
 * @brief The main function to execute the Load Balancer simulation.
 * 
 * Prompts the user for the number of clock cycles and web servers, and runs the simulation accordingly.
 * 
 * @return 0 on successful execution.
 */
int main() {
    int cycles;       ///< Number of clock cycles for the simulation.
    int webservers;   ///< Number of web servers for the simulation.

    cout << "Howdy!" << endl;

    // Get the number of clock cycles
    cout << "How many clock cycles do you want?" << endl;
    cin >> cycles;

    // Get the number of web servers
    cout << "How many web servers do you want?" << endl;
    cin >> webservers;

    LoadBalancer loadBalancer;

    // Run the load balancing simulation
    loadBalancer.run(cycles, webservers);

    return 0;
}
