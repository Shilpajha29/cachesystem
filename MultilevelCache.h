#ifndef MultilevelCache_h
#define MultilevelCache_h

#include <vector>
#include "Cache.h"

class MultilevelCache {
private:
    std::vector<Cache*> cacheLevels; // list of cache levels

public:
    MultilevelCache();
    void addCacheLevel(int size, std::string evictionPolicy);
    std::string get(std::string key);
    void put(std::string key, std::string value);
    void removeCacheLevel(int level);
    void displayCache();
};

#endif /* MultilevelCache_h */
