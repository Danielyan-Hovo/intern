import os
from main import gcayin

def test():
    with open('exit.txt','w') as out:
        if(os.path.getsize('test_input.txt') > 2):
            with open('test_input.txt', 'r') as inpt:
                golden = open('golden.txt', 'r')
                result = open('result.txt', 'w')
                x = inpt.readlines()
                for i in x:
                    k = eval(i.strip())
                    v,b = k
                    h = str(gcayin(v, b))
                    out.write(h)
                    out.write('\n')
                    l_elem = golden.readline().strip()  #gets element from golden results
                    if(h == l_elem):
                        result.write(f"{str(h)} is equal to {str(l_elem)}, test passed")
                        result.write('\n')
                    else:
                        result.write(f"{str(h)} is not equal to {str(l_elem)}, test failed!")
                        result.write('\n')
            golden.close(); result.close()
        else:
            out.write(str("Input file is empty!"))

test()
