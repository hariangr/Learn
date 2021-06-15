package models

import (
	"fmt"
	"math"
)

type Shape interface {
	Area() float64
	Perimeter() float64
}

type Triangle struct {
	Width  float64
	Height float64
}

type Rectangle struct {
	Width  float64
	Height float64
}

func (t Triangle) Area() float64 {
	return 1.0 / 2 * t.Width * t.Height
}

func (r Rectangle) Area() float64 {
	return r.Height * r.Width
}

func (t Triangle) Perimeter() float64 {
	miring := math.Sqrt(math.Pow(t.Width/2.0, 2) + math.Pow(t.Height, 2))
	return t.Width + (2 * miring)
}

func (r Rectangle) Perimeter() float64 {
	return 2 * (r.Height + r.Width)
}

func Describe(g Shape) string {
	return fmt.Sprintln("Luas area adalah", g.Area(), ", lalu keliling adalah", g.Perimeter())
}
