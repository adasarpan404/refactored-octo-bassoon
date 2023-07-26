#include <iostream>
#include <vector>

using namespace std;
struct Server
{
    string name;
    int weight;

    Server(const string &n, int w) : name(n), weight(w) {}
};

class WeightedRoundRobinLoadBalancer
{
private:
    vector<Server> servers;
    size_t currentServerIndex;
    int currentWeight;
    int gcd; // Greatest Common Divisor
    int maxWeight;

public:
    WeightedRoundRobinLoadBalancer() : currentServerIndex(0), currentWeight(0), gcd(0), maxWeight(0) {}

    // Utility function to calculate the greatest common divisor (gcd) of two numbers
    int getGCD(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Utility function to calculate the maximum weight among the servers
    int getMaxWeight()
    {
        int max = 0;
        for (const auto &server : servers)
        {
            if (server.weight > max)
            {
                max = server.weight;
            }
        }
        return max;
    }

    void addServer(const string &serverName, int serverWeight)
    {
        Server server(serverName, serverWeight);
        servers.push_back(server);
        gcd = getGCD(gcd, serverWeight);
        maxWeight = getMaxWeight();
    }

    string getNextServer()
    {
        if (servers.empty())
        {
            return ""; // No servers available
        }

        while (true)
        {
            currentServerIndex = (currentServerIndex + 1) % servers.size();
            if (currentServerIndex == 0)
            {
                currentWeight -= gcd;
                if (currentWeight <= 0)
                {
                    currentWeight = maxWeight;
                    if (currentWeight == 0)
                    {
                        return ""; // No servers available
                    }
                }
            }

            if (servers[currentServerIndex].weight >= currentWeight)
            {
                return servers[currentServerIndex].name;
            }
        }
    }
};

int main()
{
    WeightedRoundRobinLoadBalancer loadBalancer;

    // Add servers with weights
    loadBalancer.addServer("Server 1", 3);
    loadBalancer.addServer("Server 2", 1);
    loadBalancer.addServer("Server 3", 2);

    // Retrieve servers in weighted round-robin fashion
    for (int i = 0; i < 10; ++i)
    {
        string server = loadBalancer.getNextServer();
        cout << "Request " << i + 1 << " directed to: " << server << endl;
    }

    return 0;
}
