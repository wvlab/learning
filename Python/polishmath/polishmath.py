// TODO comments
from collections import deque

stack = deque()
inp = list(input().split())
for i in inp:
    try:
        i = float(i)
    except ValueError:
        tmp = stack.pop()
        i = eval(f"{stack.pop()} {i} {tmp}")
    finally:
        stack.append(i)

print(stack.pop())