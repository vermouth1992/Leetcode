"""
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
"""



class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

    def __repr__(self):
        return 'val: ' + str(self.val) + '\n' + 'left: ' + self.left.__repr__() + '\n' + 'right: ' + self.right.__repr__()

class Solution(object):
    def __init__(self):
        self.trees = []
        # all the rest trees will be generated using this two trees
        self.trees.append([None])
        self.trees.append([TreeNode(1)])

    def addConstantTree(self, node, constant):
        # construct a new tree, where each element 
        # in the new tree is val of old tree add constant
        if node is None:
            return None
        else:
            newNode = TreeNode(node.val + constant)
            newNode.left = self.addConstantTree(node.left, constant)
            newNode.right = self.addConstantTree(node.right, constant)
        return newNode

    def generateSubTreeList(self, subTreeLength, start_index):
        trees = []
        # print subTreeLength, start_index, self.trees[subTreeLength]
        for tree in self.trees[subTreeLength]:
            trees.append(self.addConstantTree(tree, start_index - 1))
        return trees

    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n == 0:
            return []
        for i in range(2, n + 1):
            self.trees.append([])
            for root_index in range(1, i + 1):
                len_left_tree = root_index - 1
                left_trees = self.generateSubTreeList(len_left_tree, 1)
                len_right_tree = i - root_index
                right_trees = self.generateSubTreeList(len_right_tree, root_index + 1)
                for left_tree in left_trees:
                    for right_tree in right_trees:
                        root_node = TreeNode(root_index)
                        root_node.left = left_tree
                        root_node.right = right_tree
                        self.trees[i].append(root_node)
        return self.trees[n]


def numTrees(n):
    """
    :type n: int
    :rtype: int
    >>> Solution().numTrees(1)
    1
    >>> Solution().numTrees(2)
    2
    >>> Solution().numTrees(3)
    5
    >>> Solution().numTrees(4)
    14
    """
    if n <= 1:
        return 1
    vec = [1, 1]
    for i in range(2, n + 1):
        total = 0
        if i % 2 == 0:
            for j in range(i // 2):
                total += vec[j] * vec[i - j - 1]
            total *= 2
        else:
            for j in range((i - 1) // 2):
                total += vec[j] * vec[i - j - 1]
            total = total * 2 + vec[(i - 1) // 2] ** 2
        vec.append(total)
    return vec[n]


if __name__ == '__main__':
    n = 4
    a = Solution().generateTrees(4)
    assert len(a) == numTrees(4)


