Initially started as I explored the 3FS code codebase to understand how high performance/low-latency distributed systems are written in systems programming languages and what I can learn from it. Now it is a collection of C/C++ projects that I would like to learn more about.


File/Stream Processing
1. [Toml11](https://github.com/ToruNiina/toml11) - https://github.com/ToruNiina/toml11 - TOML file processing 
2. [fmt](https://github.com/fmtlib/fmt) - https://github.com/fmtlib/fmt - output stream replacement
3. [scnlib](https://github.com/eliaskosunen/scnlib) - https://github.com/eliaskosunen/scnlib - input stream replacement
4. [rapidjson](https://github.com/Tencent/rapidjson) - https://github.com/Tencent/rapidjson - json file processing

Testing
1. [GoogleTest](https://github.com/google/googletest) - https://github.com/google/googletest - unit testing and mocking
2. [GTest Parallel](https://github.com/google/gtest-parallel) - https://github.com/google/gtest-parallel - run gtest binaries in parallel
3. [FuzzTest](https://github.com/google/fuzztest) - https://github.com/google/fuzztest - fuzztesting


Core Infra and utilites
1. [Folly](https://github.com/facebook/folly) - https://github.com/facebook/folly - specialized data structures
2. [Abseil](https://abseil.io/) - google equivalent to folly I guess 
3. [zstd](https://github.com/facebook/zstd) - https://github.com/facebook/zstd - compression algorithm
4. [mimalloc](https://github.com/microsoft/mimalloc) - https://github.com/microsoft/mimalloc - performant memory allocator
5. [jemalloc](https://github.com/jemalloc/jemalloc) - performant memory allocator


Low-level IO
1. [liburing](https://github.com/axboe/liburing) - https://github.com/axboe/liburing 


Data Storage Layer
1. [RocksDB](https://github.com/facebook/rocksdb) (fork of leveldb) - https://github.com/facebook/rocksdb - KV store
2. [LevelDB](https://github.com/google/leveldb) - https://github.com/google/leveldb - KV store
3. [FoundationDB](https://www.foundationdb.org/) - highly consistent db - Used for metadata storage in Deepseek's 3FS and HRT's Blooby
4. [Clickhouse](https://clickhouse.com/) - long term storage of metrics
5. [Clickhouse Client](https://github.com/ClickHouse/clickhouse-cpp?tab=readme-ov-file)

Interopatability
1. [PyBind11](https://github.com/pybind/pybind11) - https://github.com/pybind/pybind11 - bind python to c++ code



Other  Stuff

[llvm project](https://github.com/llvm/llvm-project) - https://github.com/llvm/llvm-project - llvm project repo

[mold](https://github.com/rui314/mold) - https://github.com/rui314/mold - linker for unix system

[FexEmu](https://github.com/FEX-Emu/FEX) - https://github.com/FEX-Emu/FEX - emulate x86 on ARM

[memglass](https://github.com/HFTrader/memglass) - https://github.com/HFTrader/memglass - realtime observability of C++ pod objects


Graphics System Programming 

[HipScript](https://github.com/lights0123/hipscr)ipt) - https://github.com/lights0123/hipscript - CUDA/HIP in the browser

[SPIRV-Tools](https://github.com/KhronosGroup/SPIRV-Tools) - https://github.com/KhronosGroup/SPIRV-Tools - tools for working with spir-v e.g assembler, disassembler, validator etc.

[SPIR-V Cross](https://github.com/KhronosGroup/SPIRV-Cross) - https://github.com/KhronosGroup/SPIRV-Cross - SPIR-V dissassembly

[glslang](https://github.com/KhronosGroup/glslang) - https://github.com/KhronosGroup/glslang - 

[ChipStar](https://github.com/CHIP-SPV/chipStar) - https://github.com/CHIP-SPV/chipStar - HIP/CUDA to SPIR-V

[clspv](https://github.com/google/clspv) - https://github.com/google/clspv - opencl c to vulkan compute

[Tint](https://dawn.googlesource.com/dawn/+/refs/heads/main/src/tint/) -https://dawn.googlesource.com/dawn/+/refs/heads/main/src/tint/ - WebGPU shader compiler

[Dawn](https://dawn.googlesource.com/dawn/) - https://dawn.googlesource.com/dawn/ - WebGPU implementation



