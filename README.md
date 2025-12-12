I am breaking down and exploring the 3FS code codebase to understand how high performance/low-latency software like it is written and what I can learn from it. The original readme is [here](https://github.com/timitaiwo/deepseek-3FS/blob/main/README.md)

The project added the below libraries as submodules. Note that in addition to the docs I used AI to assist me in understanding the codebase,

Core Infra and utilites
1. [Folly](https://github.com/facebook/folly)
2. [fmt](https://github.com/fmtlib/fmt)
3. [scnlib](https://github.com/eliaskosunen/scnlib)
4. [zstd](https://github.com/facebook/zstd)

Memory Allocators
1. [mimalloc](https://github.com/microsoft/mimalloc)
2. [jemalloc](https://github.com/jemalloc/jemalloc) (archived)

Low-level IO
1. [liburing](https://github.com/axboe/liburing)

Data Storage Layer
1. [RocksDB](https://github.com/facebook/rocksdb) (fork of leveldb)
2. [LevelDB](https://github.com/google/leveldb)

Testing
1. [GoogleTest](https://github.com/google/googletest)
2. [GTest Parallel](https://github.com/google/gtest-parallel)
3. [Toml11](https://github.com/ToruNiina/toml11)


Interopatability
1. [PyBind11](https://github.com/pybind/pybind11)
2. [Clickhouse Client](https://github.com/ClickHouse/clickhouse-cpp?tab=readme-ov-file)


What the libraries are good for
1. High-Performance (Folley, mimalloc/jemalloc, liburing): It's designed for concurrency, high I/O throughput, and has highly optimized memory management.

2. Data-Intensive (RocksDB/LevelDB, ClickHouse-CPP, Zstd): It reads, writes, and compresses data, and connects to a high-speed analytical database.

3. Well-Engineered (Googletest, fmt, scnlib): The code is built on a solid testing foundation and uses modern, type-safe utility libraries.

4. Extensible (pybind11): It's designed to be usable and accessible from Python, which is great for scripting, data analysis, or machine learning integration.
