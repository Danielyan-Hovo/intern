import sys, os
sys.path.append(os.path.join(os.path.dirname(sys.path[0]),"../py_class"))
from matrix import Matrix
from main import gaus

def test():
    out = open('exit.txt','r')
    golden = open('golden.txt', 'r')
    result = open('result.txt', 'w')
    for i in out:
        h = i.strip()
        l_elem = golden.readline().strip()  #gets element from golden results
        if(h == l_elem):
            result.write(f"{str(h)} is equal to {str(l_elem)}, test passed")
            result.write('\n')
        else:
            result.write(f"{str(h)} is not equal to {str(l_elem)}, test failed!")
            result.write('\n')
    golden.close(); result.close(); out.close()


def calculation():
    matrixes = []
    toxer = []
    try:
        out = open('exit.txt','w')
        if(os.path.getsize('test_input.txt') > 1):
            with open('test_input.txt', 'r') as inpt:
                for line in inpt:
                    if line != "\n" :
                            toxer.append(list(map(int, line.split())))
                    else:
                        matrixes.append(toxer)
                        toxer = []
            for i in matrixes:
                n = len(i[0]) - 1
                m = n + 1
                curr_matr = Matrix(n, m)
                for j in range(len(i)):
                    curr_matr.set_line(j, i[j])
                x =  gaus(n, curr_matr)
                for i in range(n):
                    out.write(f" X{i+1} = "+str(round(x[i], 4)))
                out.write('\n')
            out.close()
            test()
        else:
            out.wriite("Input file is empty")
            out.close()
    except FileNotFoundError:
        print("FileNotFoundError: No such file or directory!")
    except ValueError:
        print("ValueError: given input is invalid")
    except IndexError:
        print("IndexError: given index is out of range")


calculation()

