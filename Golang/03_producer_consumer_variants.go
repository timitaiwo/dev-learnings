package main

import (
    "fmt"
    "sync"
    "time"
    "math/rand/v2"
    "math"
)

func producer(queue chan int, wg *sync.WaitGroup, producer_id int,  start_idx int, span int) {
    defer wg.Done()
    
    for i := start_idx; i < cap(queue) + 20; i += span {
        time.Sleep(time.Duration(rand.IntN(100)) * time.Millisecond)
        val := i * i
        queue <- val

        fmt.Println("Published", val, "from producer", producer_id)
    }
}

func consumer(queue chan int, wg *sync.WaitGroup, consumer_id int) {
    defer wg.Done()

    delay := time.Duration(consumer_id) * time.Millisecond
    time.Sleep(delay)
    
    for val := range queue {
        fmt.Println("Consumed", val, "from consumer", consumer_id, "with original value", math.Sqrt(float64(val)))
    }
}

func spsc() {
    fmt.Println("Single Producer Single Consumer")
    mpmc(1, 1)
}


func spmc(c_count int) {
    fmt.Println("Single Producer Multi Consumer")
    mpmc(c_count, 1)
}


func mpsc(p_count int) {
    fmt.Println("Multi Producer Single Consumer")
    mpmc(1, p_count)
}


func mpmc(c_count int, p_count int) {

    if c_count != 1 && p_count != 1 {
        fmt.Println("Multi Producer Multi Consumer")
    }

    var prod_wg, consume_wg sync.WaitGroup
    buf := make(chan int, 20)

    prod_span := p_count 
    for ; p_count > 0; p_count-- {
        prod_wg.Add(1)
        go producer(buf, &prod_wg, p_count, p_count, prod_span)
    }

    for ; c_count > 0; c_count-- {
        consume_wg.Add(1)
        go consumer(buf, &consume_wg, c_count)
    }

    go func() {
        prod_wg.Wait()
        close(buf)
    }()

    consume_wg.Wait()
}

func main() {
    /*
    SP - Single Producer 
    MP - Multi Producer 
    SC - Single Consumer 
    MC - Multi Consumer 
    */
    
    spsc()
    fmt.Println("")
    
    c_count := 4
    spmc(c_count)
    fmt.Println("")
    
    p_count := 2
    mpsc(p_count)
    fmt.Println("")

    mpmc(c_count, p_count)
    fmt.Println("")
}