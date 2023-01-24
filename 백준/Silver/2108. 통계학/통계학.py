from collections import Counter
def static():
    N = int(input())
    data = [int(input()) for _ in range(N)]
    data.sort()
    data_count = Counter(data).most_common(2) # 이것만 알면 끝
    # data_count = sorted(data_count.items(), key=lambda x:x[1], reverse=True)

    print(round(sum(data)/len(data)))
    print(sorted(data)[int((len(data)-1)/2)])
    if len(data_count) > 1:
        if data_count[0][1] == data_count[1][1]:
            print(data_count[1][0])
        else:
            print(data_count[0][0])
    else:
        print(data_count[0][0])
    print(max(data)-min(data))


if __name__ == '__main__':
    static()