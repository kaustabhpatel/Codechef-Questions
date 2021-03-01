T = int(input())

for t in range(T):
    N = int(input())
    X = {}
    Y = {}
    
    for n in range(4 * N - 1):
        temp = list(map(int, input().split()))
        if X.get(temp[0]) == None:
            X[temp[0]] = 1
        else:
            X[temp[0]] += 1
        
        if Y.get(temp[1]) == None:
            Y[temp[1]] = 1
        else:
            Y[temp[1]] += 1
            
    for i in X:
        if X[i] % 2 != 0:
            print (i, end = ' ')
            break
    for i in Y:
        if Y[i] % 2 != 0:
            print (i)
            break