#python gcayin havasarum
import os
def gcayin1(a,b):
    x=0
    if(a!=0):
        x=b/a
        return x
    elif(a==0 and b==0):
        return True
    else:
        return False


with open('exitLinear.txt','w') as q:
    if(os.path.getsize('/home/studentid/scripts/git/Python/test2.txt') > 10):
         with open('inputLinear.txt', 'r') as pt:
            x = pt.readlines()
            for i in x:
                k = eval(i.strip())
                v,b = k
                h = gcayin1(v,b)
                q.write(str(h))
                q.write('\n')
    else:
        q.write(str("Input file is empty!"))

