#include "WebServer.h"
#include <iostream>

/**
 * @file WebServer.cpp
 * @brief Implementation of the WebServer class member functions.
 */

/**
 * @brief Constructs a WebServer object.
 * 
 * Initializes the WebServer with a specified total number of servers and sets the number of servers in use to zero.
 * 
 * @param total Total number of web servers.
 */
WebServer::WebServer(int total) : totalServers(total), serversInUse(0) {}

// Getter methods

/**
 * @brief Retrieves the total number of web servers.
 * 
 * @return The total number of web servers.
 */
int WebServer::getTotalServers() const {
    return totalServers;
}

/**
 * @brief Retrieves the number of web servers currently in use.
 * 
 * @return The number of web servers currently in use.
 */
int WebServer::getServersInUse() const {
    return serversInUse;
}

// Setter methods

/**
 * @brief Sets the total number of web servers.
 * 
 * Updates the total number of web servers in the system.
 * 
 * @param total The total number of web servers to set.
 */
void WebServer::setTotalServers(int total) {
    totalServers = total;
}

/**
 * @brief Sets the number of web servers currently in use.
 * 
 * Updates the number of web servers that are currently active or processing requests.
 * 
 * @param inUse The number of web servers in use to set.
 */
void WebServer::setServersInUse(int inUse) {
    serversInUse = inUse;
}
