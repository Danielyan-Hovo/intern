#Gcd python
import os
def bajanarar(a,b):
    if (b==0):
        return a
    else:
        return bajanarar(b,a%b)

def main():
    out = open('exit.txt','w')
    if(os.path.getsize('input.txt')>2):
        inpt = open('input.txt', 'r')
        x = inpt.readlines()
        for i in x:
            #giving values to function
            k = eval(i.strip())
            v,b = k
            h = bajanarar(v,b)
            out.write(str(h))
            out.write('\n')
        out.close(); inpt.close()
    else:
        out.write(str("Input file is empty"))

main()
