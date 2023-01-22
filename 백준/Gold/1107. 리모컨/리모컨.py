def remote():
    current_num = 100
    key = [i for i in range(10)]
    N = int(input())
    M = int(input())
    if M>0:
        broken = list(map(int, input().split()))
        for i in broken:
            key.remove(i)
    else:
        broken = []

    min_count = abs(current_num - N)

    for temp in range(1000000):
        num = str(temp)
        for i in range(len(num)):
            if int(num[i]) in broken: break
            elif i == len(num)-1:
                min_count = min(min_count, abs(N-temp)+len(num))

    print(min_count)

if __name__ =='__main__':
    remote()