def ATM():
    N = int(input())
    data = list(map(int, input().split()))
    data.sort()
    sum = 0
    total = 0
    for i in data:
        sum+=i
        total += sum
    print(total)
if __name__=="__main__":
    ATM()