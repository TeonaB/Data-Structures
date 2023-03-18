#MergeSort = complexitate-timp de 0(n*log n) si spatiu de 0(n)
def mergeSort(linie5):
    if len(linie5) > 1:

        #  r =va fi mijlocul
        r = len(linie5)//2
        #cream doi vectori auxiliari cu care lucram
        L = linie5[:r]
        M = linie5[r:]

        # sortam cele 2 jumatati cu merge
        mergeSort(L)
        mergeSort(M)

        i = j = k = 0

        # ne luam doua pozitii care vor rearanja vectorul initial
        while i < len(L) and j < len(M):
            if L[i] < M[j]:
                linie5[k] = L[i]
                i += 1
            else:
                linie5[k] = M[j]
                j += 1
            k += 1

        # asta e pentru cazul cand ramanem fara elemente intr-o parte si trebuie sa adaugam restul de elemente sortate
        while i < len(L):
            linie5[k] = L[i]
            i += 1
            k += 1

        while j < len(M):
            linie5[k] = M[j]
            j += 1
            k += 1


import time
import random
with open("de_sortat.txt", "r") as f:
    nr = int(f.readline())
    for i in range(1,nr):
        n,maxim=[int(x) for x in f.readline().split()]
        poz=1
        linie=[0]*n
        for j in range(1,n):
            linie[poz]=random.randint(0,maxim)
        inceput = time.time()
        mergeSort(linie)
        print(time.time() - inceput)
        linie2=sorted(linie)
        if linie==linie2:
            print("Programul ruleaza ok")
        else:
            print("Este o problema in program")
