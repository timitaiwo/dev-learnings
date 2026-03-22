Series of Exercises to 

1. SPSC
2. MPSC
3. SPMC
4. MPMC
5. Trading System
6. Worker Pool to process burst orders
7. ring decomposed MPSC as in [ringmpsc](https://github.com/boonzy00/ringmpsc)



## Key Optimizations to wo
1. 128-byte Cache Line Alignment: Head and tail pointers are separated by 128 bytes to prevent prefetcher-induced false sharing (Intel/AMD prefetchers may pull adjacent lines).

2. Cached Sequence Numbers: Producers cache the consumer's head position to minimize cross-core cache traffic. Cache refresh only occurs when the ring appears full.

3. Batch Operations: The consumeBatch API processes all available items with a single atomic head update, amortizing synchronization overhead.

4. Adaptive Backoff: Crossbeam-style exponential backoff (spin → yield → park) reduces contention without wasting CPU cycles.

5. Zero-Copy API: The reserve/commit pattern allows producers to write directly into the ring buffer without intermediate copies.