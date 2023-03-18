#RadixSort = complexitate-timp de 0(n+k) si spatiu de 0(max)
def radixsort(linie4):
    #aici ne alegem baza in care lucram si initializam "bucket-urile"
    placement=1
    radix=10
    buckets=[[]for i in range(radix)]
    maxlenght=False
    #rulam pana ajungem la lungimemaxina in baza
    while not maxlenght:
        maxlenght=True
        #punem in "buckets" ca la bucketsort elementele in functie de fiecare cifra
        for i in linie4:
            tmp = i // placement
            buckets[tmp % radix].append(i)
            if maxlenght and tmp > 0:
                maxlenght=False
        i=0
        #rearanjam in vector elementele in functie de ce gasim in "buckets"
        for bucket in buckets:
            for num in bucket:
                linie4[i]=num
                i+=1
            bucket.clear()
        placement*=radix

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
        radixsort(linie)
        print(time.time() - inceput)
        linie2=sorted(linie)
        if linie==linie2:
            print("Programul ruleaza ok")
        else:
            print("Este o problema in program")