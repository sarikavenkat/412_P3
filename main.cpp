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
 * This function prompts the user for the number of clock cycles and web servers,
 * initializes the LoadBalancer object, and runs the simulation based on user input.
 *
 * @return 0 on successful execution.
 */
int main() {
    int cycles;       ///< Number of clock cycles for the simulation.
    int webservers;   ///< Number of web servers for the simulation.

    // Friendly greeting
    cout << "Howdy! I hope you're having a splendid day!" << endl;

    // Prompt user for number of clock cycles
    cout << "How many clock cycles do you want?" << endl;
    cin >> cycles;

    // Prompt user for number of web servers
    cout << "How many web servers do you want?" << endl;
    cin >> webservers;

    // Instantiate LoadBalancer object
    LoadBalancer loadBalancer;

    // Run the load balancer simulation
    loadBalancer.run(cycles, webservers);

    return 0;
}
