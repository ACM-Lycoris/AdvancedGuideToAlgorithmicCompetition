n = int(input())
kingL,kingR = map(int,input().split())
arr = []

for i in range (n):
    Left,Right = map(int,input().split())
    arr.append((Left,Right))

arr.sort(key = lambda x:x[0]*x[1])

curLeft = kingL
maxAns = 0

for le,ri in arr:
    curAns = curLeft // ri
    maxAns = max(maxAns,curAns)
    curLeft*= le

print (maxAns)    