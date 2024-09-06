#include "MultilevelCache.h"

MultilevelCache::MultilevelCache() {}

void MultilevelCache::addCacheLevel(int size, std::string evictionPolicy) {
    // add a new cache level to the list
    Cache* cache = new Cache(size, evictionPolicy);
    cacheLevels.push_back(cache);
}

std::string MultilevelCache::get(std::string key) {
    // retrieve the value from the highest-priority cache level
    for (Cache* cache : cacheLevels) {
        std::string value = cache->get(key);
        if (!value.empty()) {
            // move the data up to higher cache levels
            promoteData(key, value);
            return value;
        }
    }
    // simulate fetching from main memory and store in L1 cache
    return fetchFromMainMemory(key);
}

void MultilevelCache::put(std::string key, std::string value) {
    // insert the key-value pair into the L1 cache
    Cache* l1Cache = cacheLevels[0];
    l1Cache->put(key, value);
    // evict items if necessary
    l1Cache->evictItems();
}

void MultilevelCache::removeCacheLevel(int level) {
    // remove a cache level by specifying its index
    delete cacheLevels[level];
    cacheLevels.erase(cacheLevels.begin() + level);
}

void MultilevelCache::displayCache() {
    // print the current state of each cache level
    for (int i = 0; i < cacheLevels.size(); i++) {
        Cache* cache = cacheLevels[i];
        std::cout << "L" << (i + 1) << " Cache: ";
        for (auto& entry : cache->cacheMap) {
            std::cout << entry.first << ": " << entry.second << ",
