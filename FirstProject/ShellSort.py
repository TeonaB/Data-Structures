#Shellsort = complexitate-timp de 0(n*log n) si spatiu de 0(n)
def shellsort(linie6,n):
    #lucram pe intervale de la n//2, n//4 etc. pana ajungem la 1
    interval=n//2
    while interval>0:
        #ne luam un i care va reprezenta elementele din interval
        for i in range(interval, n):
            temp = linie6[i]
            j = i
            # j va reprezenta elementul cu care comparam elementul i
            while j >= interval and linie6[j - interval] > temp:
                linie6[j] = linie6[j - interval]
                j -= interval
            linie6[j] = temp
        interval=interval//2

import time
import random
with open("de_sortat.txt", "r") as f:
    nr = int(f.readline())
    for i in range(0,nr):
        n,maxim=[int(x) for x in f.readline().split()]
        poz=1
        linie=[0]*n
        for j in range(1,n):
            linie[poz]=random.randint(0,maxim)
            poz+=1
        inceput = time.time()
        shellsort(linie,n)
        print(time.time() - inceput)
        linie2=sorted(linie)
        if linie==linie2:
            print("Programul ruleaza ok")
        else:
            print("Este o problema in program")