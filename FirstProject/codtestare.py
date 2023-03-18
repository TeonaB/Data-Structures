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
        #Sort(linie)
        print(time.time() - inceput)
        linie2=sorted(linie)
        if linie==linie2:
            print("Programul ruleaza ok")
        else:
            print("Este o problema in program")
