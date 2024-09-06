# cachesystem
# Dynamic Multilevel Caching System in C++
This repository implements a dynamic multilevel caching system in C++. The system consists of two main classes: Cache and MultilevelCache.

# Cache Class
The Cache class represents a single cache level. It has the following attributes:

size: the size of the cache level
evictionPolicy: the eviction policy (LRU or LFU)
cacheMap: a map to store key-value pairs
The Cache class has the following methods:

get(key): retrieves the value from the cache map
put(key, value): adds the key-value pair to the cache map and evicts items if necessary
remove(key): removes the key-value pair from the cache map
isFull(): checks if the cache is full
getEvictionPolicy(): returns the eviction policy
evictItems(): evicts items if the cache is full (implementation of LRU and LFU eviction policies is left as an exercise)
MultilevelCache Class
The MultilevelCache class represents the multilevel caching system. It has the following attributes:

# cacheLevels: a vector of cache levels
The MultilevelCache class has the following methods:

addCacheLevel(size, evictionPolicy): adds a new cache level to the list
get(key): retrieves the value from the highest-priority cache level
put(key, value): inserts the key-value pair into the L1 cache
removeCacheLevel(level): removes a cache level by specifying its index
displayCache(): prints the current state of each cache level
Working
Here's how the system works:

# Adding a cache level: 
When a new cache level is added using addCacheLevel(size, evictionPolicy), a new Cache object is created and added to the cacheLevels vector.
Getting a value: When get(key) is called, the system checks each cache level in order of priority (highest to lowest) to see if the key is present. If the key is found, the value is returned, and the data is promoted to higher cache levels using promoteData(key, value). If the key is not found, the system simulates fetching from main memory and stores the value in the L1 cache.
Inserting a value: When put(key, value) is called, the key-value pair is inserted into the L1 cache. If the L1 cache is full, items are evicted using the eviction policy.
Removing a cache level: When removeCacheLevel(level) is called, the specified cache level is removed from the cacheLevels vector.
Displaying the cache: When displayCache() is called, the system prints the current state of each cache level, showing the keys and values.
Eviction Policies
The system supports two eviction policies: LRU (Least Recently Used) and LFU (Least Frequently Used). The implementation of these policies is left as an exercise.

# Concurrency
The system does not implement concurrency, but it can be added by using thread-safe data structures and synchronization mechanisms.

# Getting Started
To use the system, simply create a MultilevelCache object and add cache levels as needed. Then, use the get(key) and put(key, value) methods to interact with the cache.
