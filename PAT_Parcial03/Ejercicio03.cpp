
#include "Ejercicio03.h"
#include <unordered_map>
#include <map>

using namespace std;

TimeMap::TimeMap() {
}

void TimeMap::set(string key, string value, int timestamp) {
    data[key].emplace(timestamp, move(value));
}

string TimeMap::get(string key, int timestamp) {
    auto it = data.find(key);
    if (it == data.end()) {
        return "";
    }

    const map<int, string>& values = it->second;

    auto itValue = values.upper_bound(timestamp);

    if (itValue != values.begin()) {
        --itValue;
        return itValue->second;
    }

    return "";
}

