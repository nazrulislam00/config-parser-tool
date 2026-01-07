#include <iostream>
#include "parser.h"

int main() {
    ConfigParser config;

    if (!config.load("example.conf")) {
        std::cerr << "Failed to load config file\n";
        return 1;
    }

    std::cout << "Host: " << config.get("host") << "\n";
    std::cout << "Port: " << config.get("port") << "\n";
    std::cout << "Debug: " << config.get("debug", "false") << "\n";

    return 0;
}
