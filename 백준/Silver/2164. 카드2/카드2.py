from collections import deque

def card2():
    N = int(input())
    q = deque(list(x+1 for x in range(N)))

    cnt = 0
    while len(q)!=1:
        if cnt%2==0:
            q.popleft()
            cnt+=1
        else:
            q.append(q.popleft())
            cnt += 1
    print(*list(q))


if __name__ == "__main__":
    card2()