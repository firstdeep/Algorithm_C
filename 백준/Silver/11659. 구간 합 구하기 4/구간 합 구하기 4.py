import sys
input = sys.stdin.readline
n,m = map(int, input().split())
data = list(map(int, input().split()))
sum = [0 for _ in range(n+1)]

# 누적합 구헤서 저장 하기
for i in range(1, len(data)+1):
    sum[i] = data[i-1] + sum[i-1]

for _ in range(m):
    start, finish = map(int, input().split())
    print(sum[finish] - sum[start-1])

