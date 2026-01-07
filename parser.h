#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include <string>
#include <unordered_map>

class ConfigParser {
public:
    bool load(const std::string& filename);
    std::string get(const std::string& key, const std::string& defaultValue = "") const;

private:
    std::unordered_map<std::string, std::string> data;
    static std::string trim(const std::string& str);
};

#endif
