import sys, os
sys.path.append(os.path.join(os.path.dirname(sys.path[0]),"../py_class"))
from matrix import Matrix

def calc(matrix, curr, prev, count):
    for i in range(count):
        curr[i] = matrix.get(i, count)
        for j in range(count):
            if (i != j):
                curr[i] -= prev[j]*matrix.get(i, j)
        try:
            curr[i] /= matrix.get(i, i)
        except:
            out.write("SMTHNG WENT WRONG, CHECK THE INPUT FILE\n")
            return False
    return curr, prev


out = open('exit.txt', 'w')
def iterat(var_count, mat):
    matrix = mat
    EPSYLON = 1/ 1000
    cycle = True
    curr = [0 for i in range(var_count)]
    prev = [0 for i in range(var_count)]
    iteration = 0
    abslut = 0
    while (cycle):
        try:
            curr, prev =  calc(matrix, curr, prev,  var_count)
        except:
            out.write("SMTHNG WENT WRONG, CHECK THE INPUT MATRIX\n")
            break
        iteration +=1
        count = 0
        for i in range(var_count):
            abslut = curr[i] - prev[i]
            if (abs(abslut) <= EPSYLON):
                count +=1
            if (count >= var_count):
                cycle = False
            elif(iteration >=30):
                inf = "There is no solution"
                cycle = False
                return inf
            prev[i] = curr[i]
    return prev

out.close()

def call():
    matrixes = []
    toxer = []
    try:
        out = open('exit.txt','w')
        if(os.path.getsize('input.txt') > 1):
            with open('input.txt', 'r') as inpt:
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
                x = iterat(n, curr_matr)
                for i in range(n):
                    out.write(f" X{i+1} = "+str(round(x[i], 4)))
                out.write('\n')
            out.close()
        else:
            out.write("Input file is empty")
            out.close()
    except FileNotFoundError:
        print("FileNotFoundError: No such file or directory!")
    except ValueError:
        print("ValueError: given input is invalid")
    except IndexError:
        print("IndexError: given index is out of range")

call()


