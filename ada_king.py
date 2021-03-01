T = int(input())
for t in range(T):
    K = int(input())
    r = int (K / 8)
    m = int (K % 8)
    chess = []
    for i in range (1, 9):
        temp = []
        for j in range (1, 9):
            if i <= r:
                temp.append('.')
            elif i == r + 1 and j <= m:
                temp.append('.')
            else:
                temp.append('X')
        chess.append(temp)
    chess[0][0] = 'O'
    for i in range(8):
        for j in range(8):
            print (chess[i][j], end = '')
        print()
            