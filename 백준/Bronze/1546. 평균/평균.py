n = int(input())
a = list(map(int, input().split()))
a_max = max(a)

new_list = []
for idx in a:
    new_list.append(idx/a_max * 100)
test_avg = sum(new_list)/n
print(test_avg)