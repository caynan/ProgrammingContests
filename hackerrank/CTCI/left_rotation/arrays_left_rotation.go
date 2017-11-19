package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(w, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(r, f, a...) }

func main() {
	defer w.Flush()
	var n, d int
	fmt.Fscanf(r, "%d %d\n", &n, &d)

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(r, "%d", &arr[i])
	}

	// arr = lRotate(arr, d)
	arr = fastLRotate(arr, d)

	fmt.Fprintln(w, strings.Trim(fmt.Sprint(arr), "[]"))
}

func lRotate(arr []int, d int) []int {
	for i := 0; i < d; i++ {
		arr = append(arr[1:], arr[0])
	}

	return arr
}

func fastLRotate(arr []int, d int) []int {
	c := d % len(arr)

	return append(arr[c:], arr[:c]...)
}
