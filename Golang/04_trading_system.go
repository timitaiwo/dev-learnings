package main

import (
    "fmt"
    "math/rand/v2"
    "time"
    "sync"
)

func sendHeartbeat(exchange string) {
    delay := time.Duration(rand.IntN(40) + 10) * time.Millisecond
    fmt.Printf("%v with delay %v\n", exchange, delay)
    time.Sleep(delay)
    fmt.Printf("[%v] Heartbeat sent\n", exchange)
}


func FetchQuote(lp string) float64 {
    delay := time.Duration(rand.IntN(40)) * time.Millisecond
    time.Sleep(delay)
    return rand.Float64()
}


func q1() {
    exhanges := []string{
        "NASDAQ",
        "NYSE",
        "BATS",
    }

    for _, exchange := range exhanges {
        go sendHeartbeat(exchange)
    }
}


func q2(lps []string) (quotes []float64) {
    var wg sync.WaitGroup
    quotes = make([]float64, len(lps))
    
    for idx, lp := range lps {
        wg.Add(1)

        go func(idx int, lp string) {
            defer wg.Done()
            quotes[idx] = FetchQuote(lp)
        }(idx, lp)
    }

    wg.Wait()
    return
}

func main() {

    q1()

    lps := []string{
        "lp1",
        "lp2",
        "lp3",
        "lp4",
        "lp5",
    }
    quotes := q2(lps)
    fmt.Println("quotes", quotes)

    
}