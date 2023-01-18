from collections import deque
def miro():
    D = ((-1,0), (1,0), (0,-1), (0,1))
    N,M = map(int, input().split())
    graph = [list(input()) for _ in range(N)]

    def bfs(sr,sc, dr,dc):
        visited = [[False for _ in range(M)] for _ in range(N)]
        data = deque()
        data.append((sr, sc, 1))
        visited[sr][sc] = True

        while data:
            curr = data.popleft()
            if curr[0] == dr and curr[1]==dc: return curr[2]
            for i in range(4):
                nr = curr[0]+D[i][0]
                nc = curr[1]+D[i][1]
                if 0<=nr<N and 0<=nc<M:
                    if not visited[nr][nc] and graph[nr][nc] == '1':
                        visited[nr][nc] = True
                        data.append((nr,nc,curr[2]+1))



    print(bfs(0,0,N-1,M-1))

if __name__ =='__main__':
    miro()