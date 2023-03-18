#HeapSort = complexitate-timp de 0(n*logn) si spatiu de 0(1)
#practic avem nevoie de 2 functii
#heapify ne ajuta sa cream un arbore in care elementul maxim sa fie in varf si restul sa porneasca de la el
def heapify(linie2, n, i):
      #gasim elementul maxim intre varf si copiii sai
      maxim = i
      stg = 2 * i + 1
      dr = 2 * i + 2
  
      if stg < n and linie2[i] < linie2[stg]:
          maxim = stg
      if dr < n and linie2[maxim] < linie2[dr]:
          maxim = dr
  
      #daca maximul nu este in varf, il mutam acolo si reluam codul
      if maxim != i:
          linie2[i],linie2[maxim] = linie2[maxim],linie2[i]
          heapify(linie2, n, maxim)

#heapsort este programul de sortare care pune elementul maxim in coada si apoi elimina nivelul 0
def heapsort(linie2):
      n = len(linie2)
      #construim maximul
      for i in range(n//2, -1, -1):
          heapify(linie2, n, i)

      #realizam mutarea si aplicam heapify
      for i in range(n-1, 0, -1):
          linie2[i],linie2[0] = linie2[0],linie2[i]
          heapify(linie2, i, 0)

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
        heapsort(linie)
        print(time.time() - inceput)
        linie2=sorted(linie)
        if linie==linie2:
            print("Programul ruleaza ok")
        else:
            print("Este o problema in program")