#include "LoadBalancer.h"
#include <iostream>
#include <queue>
#include "WebServer.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * @file LoadBalancer.cpp
 * @brief Implementation of the LoadBalancer class member functions.
 */

/**
 * @brief Generate a random IP address.
 * @return A randomly generated IP address as a string.
 */
std::string LoadBalancer::generateRandomIPAddress() {
    std::stringstream ipAddress;
    for (int i = 0; i < 4; ++i) {
        ipAddress << rand() % 256;
        if (i < 3) ipAddress << ".";
    }
    return ipAddress.str();
}

// Check if IP address is in the range 10.0.0.0 to 10.255.255.255
bool isInRange(const std::string& ipAddress) {
    std::istringstream ss(ipAddress);
    std::string octet;
    std::vector<int> octets;

    while (getline(ss, octet, '.')) {
        octets.push_back(stoi(octet));
    }

    if (octets.size() == 4 && octets[0] == 10 &&
        octets[1] >= 0 && octets[1] <= 255 &&
        octets[2] >= 0 && octets[2] <= 255 &&
        octets[3] >= 0 && octets[3] <= 255) {
        return true;
    }

    return false;
}

/**
 * @brief Run load balancing cycles.
 * @param cycles The number of load balancing cycles to run.
 * @param webservers The number of web servers in the load balancing system.
 */
void LoadBalancer::run(int cycles, int webservers) {

    std::queue<Request> requestQueue;
    WebServer server(webservers);
    vector<Request> activeRequests;

    int numServersAdded = 0, numServersRemoved = 0;
    int numRequestsProcessed = 0, numRequestsBlocked = 0;

    std::ofstream outputFile("log.txt");
    outputFile << "Number of cycles: " << cycles << endl;
    outputFile << "Number of web servers: " << webservers << endl;
    outputFile << "Task time range: 1-50 seconds" << endl << endl;

    // Generate initial requests
    for (int i = 0; i < webservers * 20; ++i) {
        string incomingIP = generateRandomIPAddress();
        if (!isInRange(incomingIP)) {
            int processTime = rand() % 50;
            requestQueue.push(Request(incomingIP, generateRandomIPAddress(), processTime));
            outputFile << "Incoming request " << incomingIP << " with process time of " << processTime << endl;
        } else {
            outputFile << "Request from " << incomingIP << " blocked (within restricted range)" << endl;
            numRequestsBlocked++;
        }
    }

    // Fill initial servers
    for (int i = 0; i < webservers; ++i) {
        activeRequests.push_back(requestQueue.front());
        requestQueue.pop();
    }

    // Run load balancing cycles
    for (int cycle = 1; cycle <= cycles; ++cycle) {
        outputFile << "Cycle: " << cycle << endl;

        // Random incoming requests
        int newRequests = rand() % 4;
        for (int i = 0; i < newRequests; ++i) {
            string incomingIP = generateRandomIPAddress();
            if (!isInRange(incomingIP)) {
                int processTime = rand() % 50;
                requestQueue.push(Request(incomingIP, generateRandomIPAddress(), processTime));
                outputFile << "Incoming request " << incomingIP << " with process time of " << processTime << endl;
            } else {
                outputFile << "Request from " << incomingIP << " blocked (within restricted range)" << endl;
                numRequestsBlocked++;
            }
        }

        // Add or remove servers dynamically based on queue size
        if (requestQueue.size() >= server.getTotalServers() * 20 && activeRequests.size() < webservers + 15) {
            activeRequests.push_back(requestQueue.front());
            requestQueue.pop();
            server.setTotalServers(server.getTotalServers() + 1);
            outputFile << "Added server #" << server.getTotalServers() << endl;
            numServersAdded++;
        } else if (requestQueue.size() <= 300 && activeRequests.size() > webservers - 15 && server.getTotalServers() > 1) {
            for (auto it = activeRequests.begin(); it != activeRequests.end(); ++it) {
                if (it->timeLeft <= 0) {
                    activeRequests.erase(it);
                    server.setTotalServers(server.getTotalServers() - 1);
                    outputFile << "Removed server #" << server.getTotalServers() + 1 << endl;
                    numServersRemoved++;
                    break;
                }
            }
        }

        // Process active requests
        bool allServersFree = true;
        for (auto& request : activeRequests) {
            request.timeLeft--;

            if (request.timeLeft <= 0 && !request.completed) {
                outputFile << "Server process completed. Sending response to " << request.ipOut << " from " << request.ipIn << endl;
                request.completed = true;
                numRequestsProcessed++;
            }

            if (request.timeLeft <= 0 && !requestQueue.empty()) {
                request = requestQueue.front();
                requestQueue.pop();
            } else if (requestQueue.empty()) {
                allServersFree = false;
            }
        }

        if (allServersFree) {
            outputFile << "No incoming requests at this moment. Available server(s)." << endl;
        }
    }

    // Final log summary
    outputFile << "\nNumber of servers added: " << numServersAdded << endl;
    outputFile << "Number of servers removed: " << numServersRemoved << endl;
    outputFile << "Final total servers: " << server.getTotalServers() << endl;
    outputFile << "Initial queue size: " << webservers * 20 << endl;
    outputFile << "Final queue size: " << requestQueue.size() << endl;
    outputFile << "Number of requests processed: " << numRequestsProcessed << endl;
    outputFile << "Number of requests blocked: " << numRequestsBlocked << endl;
}
