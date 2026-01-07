#include "parser.h"
#include <fstream>
#include <sstream>
#include <algorithm>

bool ConfigParser::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    std::string line;
    while (std::getline(file, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;

        size_t pos = line.find('=');
        if (pos == std::string::npos) continue;

        std::string key = trim(line.substr(0, pos));
        std::string value = trim(line.substr(pos + 1));

        data[key] = value;
    }
    return true;
}

std::string ConfigParser::get(const std::string& key, const std::string& defaultValue) const {
    auto it = data.find(key);
    return it != data.end() ? it->second : defaultValue;
}

std::string ConfigParser::trim(const std::string& str) {
    const char* whitespace = " \t\n\r";
    size_t start = str.find_first_not_of(whitespace);
    size_t end = str.find_last_not_of(whitespace);
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}
