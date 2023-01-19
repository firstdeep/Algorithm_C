from collections import deque
def wall_re():
    N, M = map(int, input().split())
    graph = [list(map(int, input())) for _ in range(N)]
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]

    def bfs():
        q = deque()
        q.append([0,0,0])
        visited = [[[0]*2 for i in range(M)] for _ in range(N)]
        visited[0][0][0] = 1
        while q:
            x,y,crash = q.popleft()
            if x == N-1 and y == M-1:
                return visited[x][y][crash]
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < N and 0 <= ny < M:
                    if graph[nx][ny] == 0 and visited[nx][ny][crash] == 0:
                        q.append([nx,ny,crash])
                        visited[nx][ny][crash] = visited[x][y][crash] + 1
                    if graph[nx][ny] == 1 and crash ==0: # 딱 한번만 해야 하니까 다음과 같이 구성
                        q.append([nx,ny,crash+1])
                        visited[nx][ny][crash+1] = visited[x][y][crash] + 1
        return -1

    print(bfs())

if __name__ =="__main__":
    wall_re()
