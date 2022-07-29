from main import qarakusayin
import os

def test():
    out = open('exit.txt','w')
    if(os.path.getsize('test_input.txt') > 2):
        inpt = open('test_input.txt', 'r')
        golden = open('golden.txt', 'r')
        result = open('result.txt', 'w')
        x = inpt.readlines()
        for i in x:
            k = eval(i.strip())
            v, b, n = k
            h = str(qarakusayin(v,b,n))
            out.write(str(h))
            out.write('\n')
            q_elem = golden.readline().strip()
            if(h == q_elem):
                result.write(f"{str(h)} is equal to {str(q_elem)}, test passed")
                result.write('\n')
            else:
                result.write(f"{str(h)} is not equal to {str(q_elem)}, test failed!")
                result.write('\n')
        out.close(); inpt.close()
        golden.close(); result.close()
    else:
        out.write(str("Input file is empty!"))

test()
