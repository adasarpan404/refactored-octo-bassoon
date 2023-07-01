#include <bits/stdc++.h>

using namespace std;

class IpHashLoadBalancer
{
private:
    unordered_map<string, string> serverMap;

public:
    void addServer(const string &ipAddress, const string &serverName)
    {
        serverMap[ipAddress] = serverName;
    }
    string getServer(const string &ipAddress)
    {
        auto it = serverMap.find(ipAddress);
        if (it != serverMap.end())
        {
            return it->second;
        }
        return "";
    }
};

int main()
{
    IpHashLoadBalancer iphashLoadBalancer;

    iphashLoadBalancer.addServer("192.168.0.1", "Server 1");
    iphashLoadBalancer.addServer("192.168.0.2", "Server 2");
    iphashLoadBalancer.addServer("192.168.0.3", "Server 3");

    cout << "Request from 192.168.0.1 directed to: " << iphashLoadBalancer.getServer("192.168.0.1") << endl;
    cout << "Request from 192.168.0.2 directed to: " << iphashLoadBalancer.getServer("192.168.0.2") << endl;
    cout << "Request from 192.168.0.3 directed to: " << iphashLoadBalancer.getServer("192.168.0.3") << endl;
    cout << "Request from 192.168.0.4 directed to: " << iphashLoadBalancer.getServer("192.168.0.4") << endl;

    return 0;
}