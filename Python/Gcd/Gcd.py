#amenamec bajanairar python
def bajanarar(a,b):   
    if (b==0):
        return a
    else:
        return bajanarar(b,a%b)

with open('exitGcd.txt','w') as q:
 with open('inputGcd.txt', 'r') as pt:
   x = pt.readlines()
   for i in x:
       k = eval(i.strip())
       v,b = k
       h = bajanarar(v,b)
       q.write(str(h))
       q.write('\n')
