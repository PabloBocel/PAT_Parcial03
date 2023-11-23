#pragma once

#include <string>
#include <string>
#include <unordered_map>
#include <map>

using std::string;

class TimeMap
{
public:
    TimeMap();

    void set(string key, string value, int timestamp);

    string get(string key, int timestamp);

private:
    std::unordered_map<string, std::map<int, string>> data;
};

