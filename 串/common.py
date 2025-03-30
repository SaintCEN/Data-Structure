import sys
from typing import List

maxlen = 255
chunksize = 80

class SString:
    def __init__(self):
        self.ch = [''] * (maxlen + 1)
        self.length = 0

class Chunk:
    def __init__(self):
        self.ch = [''] * chunksize
        self.next = None

class LString:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

def BF(s: SString, t: SString, pos: int) -> int:
    i = pos
    j = 1
    while i <= s.length and j <= t.length:
        if s.ch[i] == t.ch[j]:
            i += 1
            j += 1
        else:
            i = i - j + 2
            j = 1
    if j > t.length:
        return i - t.length
    else:
        return 0

def compute_next(pattern: str) -> List[int]:
    m = len(pattern)
    next_arr = [0] * (m + 1)
    k = 0
    next_arr[0] = -1
    for i in range(1, m):
        while k >= 0 and pattern[i] != pattern[k]:
            k = next_arr[k]
        k += 1
        next_arr[i + 1] = k
    return next_arr

def KMP(text: str, pattern: str) -> None:
    n = len(text)
    m = len(pattern)
    if m == 0:
        print("Not Found")
        return
    next_arr = compute_next(pattern)
    i = 0
    k = 0
    while i < n:
        if k == -1 or text[i] == pattern[k]:
            i += 1
            k += 1
            if k == m:
                print(text[i - m:])
                return
        else:
            k = next_arr[k]
    print("Not Found")

def main():
    t = sys.stdin.readline().strip()
    n = int(sys.stdin.readline())
    for _ in range(n):
        j = sys.stdin.readline().strip()
        KMP(t, j)

if __name__ == "__main__":
    main()