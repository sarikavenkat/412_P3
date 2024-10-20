#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <string>

/**
 * @file LoadBalancer.h
 * @brief Declaration of the LoadBalancer class.
 */

/**
 * @class LoadBalancer
 * @brief Manages load balancing operations, including IP generation and handling multiple load balancing cycles.
 */
class LoadBalancer {
public:
    /**
     * @brief Generates a random IP address.
     * 
     * The generated IP address is in the form of "X.X.X.X" where each 'X' is a random number between 0 and 255.
     * 
     * @return A randomly generated IP address as a string.
     */
    std::string generateRandomIPAddress();

    /**
     * @brief Executes load balancing operations over a set number of cycles and manages a given number of web servers.
     * 
     * This function simulates incoming network requests, distributes them across web servers, dynamically adds/removes 
     * servers based on request load, and processes each request in the queue.
     * 
     * @param cycles The number of load balancing cycles to run.
     * @param webservers The initial number of web servers available in the system.
     */
    void run(int cycles, int webservers);
};

#endif // LOADBALANCER_H
