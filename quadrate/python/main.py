#quadric equation
import os
from math import sqrt

def dkrmnt(a,b,c):
    d = b * b - 4 * a * c
    return d

def gcayin(a, b):
     x = 0
     if(a != 0):
         x = b / a
         return round(x, 2)
     elif(a == 0 and b == 0):
         string = "solutions are ininite"
         return string
     else:
         string = "there is no solution"
         return string


x1,x2 = 0, 0
def qarakusayin(a, b, c):
    d = dkrmnt(a, b, c)
    if (a == 0):
        x1 = gcayin(b, c)
        return x1
    elif (d > 0):
        x1 = round((-b - sqrt(d)) / (2*a), 2)
        x2 = round((-b + sqrt(d)) / (2*a), 2)
        return (x1, x2)
    elif(d == 0):
        x1 = -b / (2*a)
        return round(x1, 2)
    else:
        string = "there is no solution"
        return string

def main():
    out = open('exit.txt','w')
    if(os.path.getsize('input.txt') > 2):
        inpt = open('input.txt', 'r')
        golden = open('golden.txt', 'r')
        result = open('result.txt', 'w')
        x = inpt.readlines()
        for i in x:
            k = eval(i.strip())
            v, b, n = k
            h = str(qarakusayin(v,b,n))
            out.write(str(h))
            out.write('\n')
        out.close(); inpt.close()
    else:
        out.write(str("Input file is empty!"))

main()
