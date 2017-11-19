""" Node is defined as
class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
"""

def checkBST(root):
    return isBST(root, float('-inf'), float('inf'))

def isBST(node, min_val, max_val):
    if node is None:
        return True

    if node.data <= min_val or node.data >= max_val:
        return False

    return isBST(node.left, min_val, node.data) and isBST(node.right, node.data, max_val)
