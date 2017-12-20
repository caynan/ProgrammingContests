"""
Detect a cycle in a linked list. Note that the head pointer may be 'None' if the list is empty.

A Node is defined as: 
 
    class Node(object):
        def __init__(self, data = None, next_node = None):
            self.data = data
            self.next = next_node
"""


def has_cycle(head):
    return hare_algorithm(head)

def hare_algorithm(head):
    turtle_pointer = head
    hare_pointer = head

    while True:
        # Hare walks 2 nodes
        for i in range(2):
            if hare_pointer.next is None:
                return False
            hare_pointer = hare_pointer.next
        # Turtle walks 1 node
        turtle_pointer = turtle_pointer.next

        if hare_pointer == turtle_pointer:
            return True
