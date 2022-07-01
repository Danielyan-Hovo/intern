#qarakusayin havasarman armatnery
from math import sqrt

def dkrmnt(a,b,c):
    d = b*b-4*a*c
    return d


def gcayin1(b,c):
    if(b!=0):
        x=c/b
        return x
    elif(b==0 and c==0):
        return True
    else:
        return False

x1,x2 = 0, 0
def qarakusayin(a, b, c):
    d = dkrmnt(a,b,c)
    if (a == 0):
        x1 = gcayin1(b,c)
        return x1
    elif (d>0):
        x1 = (-b-sqrt(d))/(2*a)
        x2 = (-b+sqrt(d))/(2*a)
        return (x1,x2)
    elif(d==0):
        x1 = -b/(2*a)
        return x1
    else:
        return False

with open('exitQuadric.txt','w') as q:
 with open('inputQuadric.txt', 'r') as pt:
   x = pt.readlines()
   for i in x:
       k = eval(i.strip())
       v,b,n = k
       h = qarakusayin(v,b,n)
       q.write(str(h))
       q.write('\n')
