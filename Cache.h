#ifndef Cache_h
#define Cache_h

#include <unordered_map>
#include <string>

class Cache {
private:
    int size; // size of the cache level
    std::string evictionPolicy; // eviction policy (LRU or LFU)
    std::unordered_map<std::string, std::string> cacheMap; // map to store key-value pairs

public:
    Cache(int size, std::string evictionPolicy);
    std::string get(std::string key);
    void put(std::string key, std::string value);
    void remove(std::string key);
    bool isFull();
    std::string getEvictionPolicy();
};

#endif /* Cache_h */
