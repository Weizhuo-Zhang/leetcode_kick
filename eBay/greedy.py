
n = 3
W = 6

weight_list = [1, 2, 3]



sorted_weight_list = sorted(weight_list)
i = 0
j = n - 1
count = 0
for x in range(n):
    sum = 0
    if (i <= j):
        break
    sum = sorted_weight_list[i] + sorted_weight_list[j]
    while sum < W:
        i += 1
        count += 1
        sum += sorted_weight_list[i]
    j -= 1
    count += 1
print(count)
