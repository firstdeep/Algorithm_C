from itertools import combinations, chain
import copy

def bfs(combi, graph, n, m):
    q = []
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]

    # combi에서 찾은 대로 벽 세우기
    for x,y in combi:
        graph[x][y] = 1

    for nn in range(n):
        for mm in range(m):
            if graph[nn][mm] == 2:
                q.append((nn,mm))
                while q:
                    xx, yy = q.pop() # q까지 while 후에 q에서 값을 가져와야 하기 때문에 pop 을 한다.
                    for i in range(4):
                        x = xx+dx[i]
                        y = yy+dy[i]
                        if x>=0 and y>=0 and x<n and y<m: # 와... 0 포함이다... 부등호 생각하자 
                            if graph[x][y] == 0:
                                graph[x][y] = 2
                                q.append((x,y)) 

    return list(chain.from_iterable(graph)).count(0)



def research():
    n, m = map(int, input().split())
    zero = []
    graph = [list(map(int, input().split())) for _ in range(n)]

    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0:
                zero.append((i,j))

    combi = list(combinations(zero, 3))

    answer = 0
    for i in combi:
        result_temp = bfs(i, copy.deepcopy(graph), n, m)
        if answer < result_temp:
            answer = result_temp

    print(answer)


research()