#include "WebServer.h"
#include <iostream>

/**
 * @file WebServer.cpp
 * @brief Implementation of the WebServer class member functions.
 */

/**
 * @brief Constructor for the WebServer class.
 * @param total Total number of web servers.
 */
WebServer::WebServer(int total) : totalServers(total), serversInUse(0) {}

/**
 * @brief Get the total number of web servers.
 * @return The total number of web servers.
 */
int WebServer::getTotalServers() const {
    return totalServers;
}

/**
 * @brief Get the number of web servers currently in use.
 * @return The number of web servers in use.
 */
int WebServer::getServersInUse() const {
    return serversInUse;
}

/**
 * @brief Set the total number of web servers.
 * @param total The total number of web servers to set.
 */
void WebServer::setTotalServers(int total) {
    totalServers = total;
}

/**
 * @brief Set the number of web servers currently in use.
 * @param inUse The number of web servers in use to set.
 */
void WebServer::setServersInUse(int inUse) {
    serversInUse = inUse;
}
