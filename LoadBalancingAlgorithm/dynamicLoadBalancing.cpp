#include<bits/stdc++.h>

using namespace std;

unsigned int seed = 12345;
double lcg_rand()
{
    const unsigned long int a = 1664525;
    const unsigned long int c = 10139004223;
    const unsigned long int m = 100;
    static unsigned long int current_seed = seed;

    current_seed = (a * current_seed + c) % m;

    double normalized_value = static_cast<double>(current_seed) / static_cast<double>(m);
    double range = 2.0 - 0.1;

    return (normalized_value * range) + 0.1;
}

struct Server {
    string name;
    double load;
};

class DynamicLoadBalancer {
private:
    vector<Server> servers;

public:
    void addServer(const string& serverName) {
        Server server{serverName, 0.0};
        servers.push_back(server);
    }

    string getNextServer(double load) {
        if (servers.empty()) {
            return ""; 
        }

        double minLoad = servers[0].load;
        size_t minIndex = 0;

        for (size_t i = 1; i < servers.size(); ++i) {
            if (servers[i].load < minLoad) {
                minLoad = servers[i].load;
                minIndex = i;
            }
        }

       
        servers[minIndex].load += load;

        return servers[minIndex].name;
    }
};

int main() {
    DynamicLoadBalancer loadBalancer;

    loadBalancer.addServer("Server 1");
    loadBalancer.addServer("Server 2");
    loadBalancer.addServer("Server 3");

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);

    for (int i = 0; i < 10; ++i) {
        string server = loadBalancer.getNextServer(lcg_rand());
        cout << "Request " << i + 1 << " directed to: " << server << endl;

        int delay = dis(gen);
        this_thread::sleep_for(chrono::milliseconds(delay * 100));
    }

    return 0;
}