#include "Annotation.h"

using namespace std;

namespace cppkin
{
    Annotation::EndPoint::EndPoint(const std::string &serviceName, std::string host, uint_fast16_t port)
            : Port(port), ServiceName(serviceName)
    {
        size_t pos;
        int index = 3;
        while ((pos = host.find('.')) != std::string::npos) {
            string subAddress = host.substr(0, pos);
            host.erase(0, pos + 1);
            Host = Host | stoi(subAddress) << 8 * index--;
        }
        Host = Host | stoi(host) << 8 * index;
    }
}

