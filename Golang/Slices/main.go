package main

import (
	"fmt"
	"math"
)

func main() {
	var arr []int
	for i := 0; i < 33; i++ {
		arr = append(arr, int(math.Pow(float64(i), 2)))
	}
	printSlice(arr)
}

func printSlice(s []int) {
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s)
}
