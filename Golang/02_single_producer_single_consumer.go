package main

import (
    "fmt"
    "sync"
)

func producer(queue chan int, wg *sync.WaitGroup) {
    defer wg.Done()
    
    for i := 1; i < cap(queue) + 20; i++ {
        queue <- (i*i)
    }
    close(queue)
}

func consumer(queue chan int, wg *sync.WaitGroup) {
    defer wg.Done()
    
    for val := range queue {
        fmt.Println(val)
    }
}

func main() {
    buf_chan := make(chan int, 5)
    wg := sync.WaitGroup{}

    wg.Add(2)
    go producer(buf_chan, &wg)
    go consumer(buf_chan, &wg)

    wg.Wait()
}