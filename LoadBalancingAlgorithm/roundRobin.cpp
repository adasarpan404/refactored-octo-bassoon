#include <bits/stdc++.h>

using namespace std;

class RoundRobinLoadBalancer
{
private:
    vector<string> servers;
    size_t currentServerIndex;

public:
    RoundRobinLoadBalancer() : currentServerIndex(0){};

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
        string nextServer = servers[currentServerIndex];
        currentServerIndex = (currentServerIndex + 1) % servers.size();
        return nextServer;
    }
};

int main()
{
    RoundRobinLoadBalancer loadBalancer;
    loadBalancer.addServer("Server 1");
    loadBalancer.addServer("Server 2");
    loadBalancer.addServer("Server 3");

    for (int i = 0; i < 10; ++i)
    {
        string server = loadBalancer.nextServer();
        cout << "Request " << i + 1 << " directed to: " << server << endl;
    }
    return 0;
}
