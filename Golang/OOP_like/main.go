package main

import "fmt"
import "harianugrah.com/oop_like/models"

type kilometer float64
type desimeter float64

func (dm desimeter) toMeter() float64 {
	return float64(dm) * 10
}

func (k kilometer) toMeter() float64 {
	return float64(k) * 1000
}

func main() {
	var jarakKm kilometer = 30
	var jarakDm desimeter = 300

	fmt.Println("KM ke meter", jarakKm.toMeter())
	fmt.Println("DM ke meter", jarakDm.toMeter())

	segitiga := models.Triangle{Width: 30, Height: 20}
	fmt.Println(segitiga.Area())

	kotak := models.Rectangle{Width: 15, Height: 15}
	fmt.Println(kotak.Area())

	fmt.Println(models.Describe(segitiga))
	fmt.Println(models.Describe(kotak))
}
