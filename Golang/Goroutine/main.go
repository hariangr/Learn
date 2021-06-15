package main

import (
	"fmt"
	"io"
	"log"
	"net/http"
)

func checkSize(url string, out chan int) {
	resp, err := http.Get(url)
	if err != nil {
		log.Fatalln("Gagal", err)
	}

	body, err := io.ReadAll(resp.Body)
	if err != nil {
		log.Fatalln("Ggal", err)
	}

	out <- len(body)
}

func main() {
	sizeCom := make(chan int)
	defer close(sizeCom)

	go checkSize("http://google.com", sizeCom)
	go checkSize("http://harianugrah.com", sizeCom)
	go checkSize("http://youtube.com", sizeCom)

	for {
		s := <-sizeCom
		fmt.Println("Ukuran ", s)
	}
}
