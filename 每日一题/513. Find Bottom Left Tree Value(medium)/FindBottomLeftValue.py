from collections import deque
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# 方法一：深度优先搜索: 递归或迭代（栈实现）
class Solution1:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        curVal = curHeight = 0
        def dfs(node: Optional[TreeNode], height: int) -> None:
            if node is None:
                return
            height += 1
            dfs(node.left, height)
            dfs(node.right, height)
            nonlocal curVal, curHeight
            if height > curHeight:
                height = curHeight
                curVal = node.val
        
        dfs(root, 0)
        return curVal

        
# 方法二：广度优先搜索: 队列
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        q = deque([root])
        while q:
            node = q.popleft()
            if node.right:
                q.append(node.right)
            if node.left:
                q.append(node.left)
            ans = node.val
        # while 下的ans变量可以返回
        # 有点像if..else下的变量可以返回一样
        return ans


def stringToTreeNode(input):
    input = input.strip()
    input = input[1:-1]
    if not input:
        return None

    inputValues = [s.strip() for s in input.split(',')]
    root = TreeNode(int(inputValues[0]))
    nodeQueue = [root]
    front = 0
    index = 1
    while index < len(inputValues):
        node = nodeQueue[front]
        front = front + 1

        item = inputValues[index]
        index = index + 1
        if item != "null":
            leftNumber = int(item)
            node.left = TreeNode(leftNumber)
            nodeQueue.append(node.left)

        if index >= len(inputValues):
            break

        item = inputValues[index]
        index = index + 1
        if item != "null":
            rightNumber = int(item)
            node.right = TreeNode(rightNumber)
            nodeQueue.append(node.right)
    return root

def main():
    import sys
    import io
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            root = stringToTreeNode(line)
            
            ret = Solution().findBottomLeftValue(root)

            out = str(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()
