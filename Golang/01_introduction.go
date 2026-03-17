package main

import (
    "fmt"
    "math"
) 

type ComplexNumberCartesian struct {
    realComp float64
    imagComp float64
}

type ComplexNumberRadial struct {
    magnitude float64
    angle float64
}

type AddSub interface {
    Add()
    Sub()
}

func (c ComplexNumberCartesian) String() string {
    return fmt.Sprintf("%g+%gi", c.realComp, c.imagComp)
}

func (c *ComplexNumberCartesian) toRadial() ComplexNumberRadial {
    return ComplexNumberRadial{c.Magnitude(), c.AngleRadians()}
}

func (c *ComplexNumberCartesian) Magnitude() float64 {
    return math.Sqrt(c.realComp * c.realComp + c.imagComp * c.imagComp)
}

func (c *ComplexNumberCartesian) AngleRadians() float64 {
    return math.Atan2(c.imagComp, c.realComp)
}

func (c *ComplexNumberCartesian) Add(o ComplexNumberCartesian) ComplexNumberCartesian {
    return ComplexNumberCartesian{c.realComp+o.realComp, c.imagComp+o.imagComp}
}

func (c *ComplexNumberCartesian) Sub(o ComplexNumberCartesian) (res ComplexNumberCartesian) {
    return ComplexNumberCartesian{c.realComp-o.realComp, c.imagComp-o.imagComp}
}

func (c *ComplexNumberCartesian) Multiply(o ComplexNumberCartesian) ComplexNumberCartesian {
    new_angle := c.AngleRadians() + o.AngleRadians()
    new_magnitude := c.Magnitude() * o.Magnitude()

    realComp := new_magnitude * math.Cos(new_angle)
    imagComp := new_magnitude * math.Sin(new_angle)
    
    return ComplexNumberCartesian{realComp, imagComp}
}

func (c ComplexNumberCartesian) Divide(o ComplexNumberCartesian) (res ComplexNumberCartesian) {
    new_angle := c.AngleRadians() - o.AngleRadians()
    new_magnitude := c.Magnitude() / o.Magnitude()
    
    realComp := new_magnitude * math.Cos(new_angle)
    imagComp := new_magnitude * math.Sin(new_angle)
    
    return ComplexNumberCartesian{realComp, imagComp}
}

func main() {
    c := ComplexNumberCartesian{3, 4}
    c_ := ComplexNumberCartesian{-1, 1}

    c1 := &c_
    fmt.Println(c1)

    c1.imagComp = 2
    fmt.Println(c1)
    c1.imagComp = 1

    fmt.Println("\nMagnitude of", c1, "is", c1.Magnitude())
    fmt.Println("Angle of", c1, "is", c1.AngleRadians())
    fmt.Println("Radial of", c1, "is", c1.toRadial())
    
    fmt.Println("\nAdd", c, "and", c_, "gives", c.Add(c_))
    fmt.Println("Sub", c, "and", c_, "gives", c.Sub(c_))
    fmt.Println("Multiply", c, "and", c_, "gives", c.Multiply(c_))
    fmt.Println("Divide", c, "and", c_, "gives", c.Divide(c_))
    
    var numsArray = [5]ComplexNumberCartesian{
        {3, 4},
        {-1, 1},
        {7, 4},
        {2, 8},
        {66, -93},
    }

    numArray2 := [2]ComplexNumberCartesian{
        {7, 9},
        {67, 99},
    }

    fmt.Println("\nnumsArray2", numArray2)
    fmt.Println("numsArray", numsArray)

    numsSlice := numsArray[1 : 3]
    fmt.Println("numsSlice", numsSlice)

    numsSlice[1] = ComplexNumberCartesian{6, 9}
    fmt.Println("\nnumsArray", numsArray)
    fmt.Println("numsSlice", numsSlice)

    var sliceLiteral = []ComplexNumberCartesian{
        {11, 86},
        {99, 130},
        {8, 6},
    }
    fmt.Println("\nSlice Literal", sliceLiteral)

    for _, val := range sliceLiteral {
        fmt.Println(val)
    }
    
    var m = make(map[string]ComplexNumberCartesian)
    m["origin"] = ComplexNumberCartesian{0,0}
    fmt.Printf("Origin from map %v\n", m["origin"])

    var m_ = map[string]ComplexNumberCartesian{
        "origin" : ComplexNumberCartesian{
            0, 0,
        },
        "c1" : ComplexNumberCartesian{
            1, 1,
        },
        "c2" : ComplexNumberCartesian{
            0, 1,
        },
    }

    m_["c3"] = ComplexNumberCartesian{1, 0}
    
    number, ok := m_["c3"]
    if !ok {
        fmt.Printf("c3 not declared")
    } else {
        fmt.Printf("Added third corner %v\n", number)
    }

    delete(m_, "c3")

    number, ok = m_["c3"]
    if !ok {
        fmt.Printf("c3 not found in m_")
    } else {
        fmt.Printf("Added third corner %v\n", m_["c3"])
    }

    // Type assertion
    //t, ok := AddSub.(ComplexNumberRadial)
    //if !ok {
        //fmt.Println("Wrong type")
    //} else {
        //fmt.Println("Selected", t)
    //}
}