# Hashmap Implementation (WIP)

The general idea is to implement two versions of a hashmap - swiss tables inspired by Google's absl one and Open Addressing Linear probing 

The Key Operations for a hashmap is

1. Get - extract the value of a given key 
2. Update - update the value of a key already in memory 
3. Delete - remove a key value pair from memory 
4. Put - add a new key-value pair that doesn't already exist 
5. Scan - request a range of values i.e. multiple consecutive keys and their values e.g. a scan operation could request all key and values between 100 and 200  

For most implementations, put and update are the same i.e update the value if the key exists else insert the new key-value pair.

## Open Addressing Hash Map
The open addressing linear probing hashmap is WIP and has some bugs 

## Swiss Table Hash Map (Not implemented)

Implement the swiss table hashmap implemented in abseil's cpp library and described in the absl docs [here](https://abseil.io/blog/20180927-swisstables) and [here](https://abseil.io/about/design/swisstables).

The Go programming language also has a description [here](https://go.dev/blog/swisstable)


It was described in a CppCon talk recorded [here](https://www.youtube.com/watch?v=ncHmEUmJZf4)

