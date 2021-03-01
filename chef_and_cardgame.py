T = int(input())

def power(n):
        p = 0
        while n != 0:
            rem = int(n) % 10
            p = p + rem
            n = int(n) / 10
        return p
    
for i in range(T):
    N = int(input())
    chef_pt = 0
    morty_pt = 0
    for j in range(N):
        cards = list(map(int, input().split()))
        c = power(cards[0])
        d = power(cards[1])
        if (c > d):
            chef_pt += 1
        elif (c < d):
            morty_pt += 1
        else:
            chef_pt += 1
            morty_pt += 1
    if chef_pt > morty_pt:
        print (0, chef_pt)
    elif chef_pt < morty_pt:
        print (1, morty_pt)
    else:
        print (2, chef_pt)