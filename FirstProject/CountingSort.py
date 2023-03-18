#CountSort = complexitate-timp de 0(n+valoarea maxima) si spatiu de 0(valoarea maxima)
def countingSort(linie6):
    #cream vectorul de numarare(frecventa) dupa ce aflam elementul maxim
    maxim=0
    for i in range(0,len(linie6)):
        if linie6[i]>maxim:
            maxim=linie6[i]
    fr=[0]*(maxim+1)

    for i in range(0,len(linie6)):
        fr[linie6[i]]+=1
    #nu uitam sa rescriem vectorul initial
    nr=0
    for i in range(0,len(fr)):
        while fr[i]>0:
            linie6[nr]=i
            nr+=1
            fr[i]-=1

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
        countingSort(linie)
        print(time.time() - inceput)
        linie2=sorted(linie)
        if linie==linie2:
            print("Programul ruleaza ok")
        else:
            print("Este o problema in program")
