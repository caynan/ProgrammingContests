package linkedlist

import "testing"

func Test_hasCycle(t *testing.T) {
	OneNodeWithCycle := &Node{1, nil}
	OneNodeWithCycle.next = OneNodeWithCycle

	TwoNodesWithCycle := &Node{1, nil}
	n2 := &Node{2, TwoNodesWithCycle}
	TwoNodesWithCycle.next = n2

	tests := []struct {
		name string
		head *Node
		want bool
	}{
		{"No Cycle (0 node)", &Node{}, false},
		{"No Cycle (1 node)", &Node{1, nil}, false},
		{"No Cycle (3 nodes)", &Node{1, &Node{2, &Node{3, &Node{}}}}, false},
		{"Cycle (2 nodes)", OneNodeWithCycle, true},
		{"Cycle (2 nodes)", TwoNodesWithCycle, true},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := hasCycle(tt.head); got != tt.want {
				t.Errorf("hasCycle() = %v, want %v", got, tt.want)
			}
		})
	}
}
