I am breaking down and exploring the 3FS code codebase to understand how high performance/low-latency software like it is written and what I can learn from it. The original readme is [here](https://github.com/timitaiwo/deepseek-3FS/blob/main/README.md)

The project added the below libraries as submodules. Note that in addition to the docs I used AI to assist me in understanding the codebase,


File/Stream Processing
1. [Toml11](https://github.com/ToruNiina/toml11) - https://github.com/ToruNiina/toml11 - TOML file processing 
2. [fmt](https://github.com/fmtlib/fmt) - https://github.com/fmtlib/fmt - output stream replacement
3. [scnlib](https://github.com/eliaskosunen/scnlib) - https://github.com/eliaskosunen/scnlib - input stream replacement


Testing
1. [GoogleTest](https://github.com/google/googletest) - https://github.com/google/googletest - unit testing and mocking
2. [GTest Parallel](https://github.com/google/gtest-parallel) - https://github.com/google/gtest-parallel - run gtest binaries in parallel


Core Infra and utilites
1. [Folly](https://github.com/facebook/folly) - https://github.com/facebook/folly - specialized data structures
2. [zstd](https://github.com/facebook/zstd) - https://github.com/facebook/zstd - compression algorithm
3. [mimalloc](https://github.com/microsoft/mimalloc) - https://github.com/microsoft/mimalloc - performant memory allocator
4. [jemalloc](https://github.com/jemalloc/jemalloc) (archived)


Low-level IO
1. [liburing](https://github.com/axboe/liburing) - https://github.com/axboe/liburing 


Data Storage Layer
1. [RocksDB](https://github.com/facebook/rocksdb) (fork of leveldb) - https://github.com/facebook/rocksdb - KV store
2. [LevelDB](https://github.com/google/leveldb) - https://github.com/google/leveldb - KV store


Interopatability
1. [PyBind11](https://github.com/pybind/pybind11) - https://github.com/pybind/pybind11 - bind python to c++ code
2. [Clickhouse Client](https://github.com/ClickHouse/clickhouse-cpp?tab=readme-ov-file)

