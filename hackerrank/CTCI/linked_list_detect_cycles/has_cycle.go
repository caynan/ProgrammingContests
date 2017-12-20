package linkedlist

import (
	"reflect"
)

type Node struct {
	data interface{}
	next *Node
}

func hasCycle(head *Node) bool {
	hare := head
	turtle := head

	for {
		for i := 0; i < 2; i++ {
			if hare.next == nil {
				return false
			}
			hare = hare.next
		}

		turtle = turtle.next

		if reflect.DeepEqual(hare, turtle) {
			return true
		}
	}
}
