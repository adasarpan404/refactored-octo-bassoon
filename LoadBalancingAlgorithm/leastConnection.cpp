#include <bits/stdc++.h>

using namespace std;




struct Server
{
    string name;
    int connectionCount;
    Server(const string &n) : name(n), connectionCount(0) {}
};

class LeastConnectionLoadBalancer
{
private:
    vector<Server> servers;
    size_t currentServerIndex;

public:
    LeastConnectionLoadBalancer() : currentServerIndex(0){};

    void addServer(const string &server)
    {
        servers.push_back(server);
    }

    string nextServer()
    {
        if (servers.empty())
        {
            return ""; // if server is empty
        }
        int minConnections = servers[0].connectionCount;
        int minIndex = 0;

        for (size_t i = 0; i < servers.size(); i++)
        {
            if (servers[i].connectionCount < minConnections)
            {
                minConnections = servers[i].connectionCount;
                minIndex = i;
            }
        }
        servers[minIndex].connectionCount++;

        return servers[minIndex].name;
    }
};
int main()
{
    LeastConnectionLoadBalancer loadBalancer;

    // Add servers
    loadBalancer.addServer("Server 1");
    loadBalancer.addServer("Server 2");
    loadBalancer.addServer("Server 3");

    // Simulate connections and retrieve servers using least connection load balancing
    for (int i = 0; i < 10; ++i)
    {
        string server = loadBalancer.nextServer();
        cout << "Request " << i + 1 << " directed to: " << server << endl;
    }

    return 0;
}