#include "Cache.h"

Cache::Cache(int size, std::string evictionPolicy) : size(size), evictionPolicy(evictionPolicy) {}

std::string Cache::get(std::string key) {
    // retrieve the value from the cache map
    if (cacheMap.find(key) != cacheMap.end()) {
        return cacheMap[key];
    }
    return ""; // not found
}

void Cache::put(std::string key, std::string value) {
    // add the key-value pair to the cache map
    cacheMap[key] = value;
    // evict items if necessary
    if (isFull()) {
        evictItems();
    }
}

void Cache::remove(std::string key) {
    // remove the key-value pair from the cache map
    cacheMap.erase(key);
}

bool Cache::isFull() {
    // check if the cache is full
    return cacheMap.size() == size;
}

std::string Cache::getEvictionPolicy() {
    // get the eviction policy
    return evictionPolicy;
}

void Cache::evictItems() {
    // evict items if the cache is full
    if (isFull()) {
        // evict the least recently used item
        if (evictionPolicy == "LRU") {
            // remove the eldest entry
            // implement LRU eviction policy
        } else if (evictionPolicy == "LFU") {
            // remove the least frequently used item
            // implement LFU eviction policy
        }
    }
}
