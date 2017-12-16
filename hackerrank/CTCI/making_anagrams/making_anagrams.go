// Given two strings, a and b, that may or may not be of the same length, determine the minimum number of character
// deletions required to make a and b anagrams. Any characters can be deleted from either of the strings.
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	var r = bufio.NewReader(os.Stdin)
	var strA, strB string
	fmt.Fscanf(r, "%s\n%s", &strA, &strB)

	fmt.Println(anagramDiff(strA, strB))
}

func anagramDiff(strA, strB string) int {
	c := make(chan map[rune]int, 2)
	go charCount(c, strA)
	go charCount(c, strB)

	return charCountDiff(c)
}

func charCount(c chan<- map[rune]int, str string) {
	m := make(map[rune]int, 26)
	for _, c := range str {
		if _, ok := m[c]; ok {
			m[c]++
		} else {
			m[c] = 1
		}
	}

	// send map to channel
	c <- m
}

func charCountDiff(c <-chan map[rune]int) int {
	strA, strB := <-c, <-c
	alphabet := "abcdefghijklmnopqrstuvwxyz"

	var diffCount int
	for _, char := range alphabet {
		// eww... where are generics when you need them :/
		diffCount += int(math.Abs(float64(strA[char] - strB[char])))
	}

	return diffCount
}
