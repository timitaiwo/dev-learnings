package main

import (
    "fmt"
    "math/rand/v2"
    "sync"
    "time"
)

type Order struct {
    orderID string
}

func processRisk(order Order) bool {
    return rand.Float64() > 0.5
}

func process_order(orderChan chan Order, approvedChan chan Order, wg *sync.WaitGroup) {
    defer wg.Done()
    for order := range orderChan {
        if order_approve := processRisk(order); order_approve {
            time.Sleep(1 * time.Millisecond)
            approvedChan <- order
        } else {
            time.Sleep(2 * time.Millisecond)
        }
    }
}


func main() {
    
    // Mocks a request management system for orders
    // process 10k requests with 20 workers

    var workerWg sync.WaitGroup
    var consumerWg sync.WaitGroup

    req_pool := make(chan Order, 100)
    approvedOrders := make(chan Order, 100)

    pool_size := 20
    workerWg.Add(pool_size)
    for i := pool_size; i > 0; i-- {
        go process_order(req_pool, approvedOrders, &workerWg)
    }

    consumerWg.Add(1)
    go func() {
        defer consumerWg.Done()
        for order := range approvedOrders {
            fmt.Println(order, "approved")
        }
    }()

    max := 10000 // Replace with 10k 
    for i := max; i > 0; i-- {
        req_pool <- Order{orderID: fmt.Sprintf("ORDER_%d", i)}
    }
    close(req_pool)
    
    workerWg.Wait()
    close(approvedOrders)
    consumerWg.Wait()
}