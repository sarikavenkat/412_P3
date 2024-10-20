#ifndef WEBSERVER_H
#define WEBSERVER_H

/**
 * @file WebServer.h
 * @brief Declaration of the WebServer class and Request structure.
 */

#include <string>

/**
 * @struct Request
 * @brief Represents a network request, containing source and destination IPs, processing time, and completion status.
 */
struct Request {
    std::string ipIn;     ///< Source IP address.
    std::string ipOut;    ///< Destination IP address.
    int time;             ///< Total time required to process the request.
    int timeLeft;         ///< Remaining time for the request to be processed.
    bool completed;       ///< Whether the request has been completed or not.

    /**
     * @brief Constructor for the Request struct.
     * 
     * Initializes the Request object with the given source IP, destination IP, and total time. 
     * Also sets the timeLeft to the total time and marks the request as not completed.
     * 
     * @param in Source IP address.
     * @param out Destination IP address.
     * @param t Total time for the request.
     */
    Request(const std::string& in, const std::string& out, int t)
        : ipIn(in), ipOut(out), time(t), timeLeft(t), completed(false) {}
};

/**
 * @class WebServer
 * @brief Represents a web server system, tracking the total number of servers and how many are in use.
 */
class WebServer {
private:
    int totalServers;   ///< Total number of web servers in the system.
    int serversInUse;   ///< Number of web servers currently in use.

public:
    /**
     * @brief Constructs a WebServer object.
     * 
     * Initializes the WebServer object with a specified total number of servers.
     * 
     * @param total Total number of web servers.
     */
    WebServer(int total);

    // Getter methods

    /**
     * @brief Retrieves the total number of web servers.
     * 
     * @return The total number of web servers.
     */
    int getTotalServers() const;

    /**
     * @brief Retrieves the number of web servers currently in use.
     * 
     * @return The number of web servers in use.
     */
    int getServersInUse() const;

    // Setter methods

    /**
     * @brief Sets the total number of web servers.
     * 
     * Updates the total number of web servers in the system.
     * 
     * @param total The total number of web servers to set.
     */
    void setTotalServers(int total);

    /**
     * @brief Sets the number of web servers currently in use.
     * 
     * Updates the number of web servers that are actively handling requests.
     * 
     * @param inUse The number of web servers in use to set.
     */
    void setServersInUse(int inUse);
};

#endif // WEBSERVER_H
