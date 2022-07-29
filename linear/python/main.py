#python Linear equation
import os
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


with open('exit.txt','w') as out:
    if(os.path.getsize('input.txt') > 2):
        with open('input.txt', 'r') as inpt:
            x = inpt.readlines()
            for i in x:
                k = eval(i.strip())
                v,b = k
                h = str(gcayin(v, b))
                out.write(h)
                out.write('\n')
    else:
        out.write(str("Input file is empty!"))

