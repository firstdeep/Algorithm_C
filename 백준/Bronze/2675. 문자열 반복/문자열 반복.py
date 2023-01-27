n = int(input())

repeat_list = []
str_list = []

for idx in range(n):
    cnt, word = input().split()
    for x in word:
        print(x*int(cnt),end='')
    print()    
                    