import sys, os
sys.path.append(os.path.join(os.path.dirname(sys.path[0]),"../py_class"))
from matrix import Matrix

with open ('exit.txt', 'w') as out:
    out.write("")


def gaus(n, matrix):
    mat = matrix
    with open ('exit.txt', 'a') as out:
        x = [0 for i in range(n) ]
        for i in range(n):
            if mat.get(i, i) == 0:
                out.write("There is no solution")
                break
            for j in range(i+1, n):
                tem = mat.get(j, i) / mat.get(i, i)
                for k in range(n+1):
                    h = mat.get(j, k)
                    d = tem * mat.get(i, k)
                    mat.set(j, k, h - d)
        x[n-1] = mat.get(n-1, n) / mat.get(n-1, n-1)
        for i in range(n-2, -1, -1):
            x[i] = mat.get(i, n)
            for j in range(i+1, n):
                x[i] = x[i] - mat.get(i, j) * x[j]
            x[i] = x[i]/mat.get(i, i)
    return x


def call():
    matrixes = []
    toxer = []
    try:
        out = open('exit.txt','w')
        if(os.path.getsize('input.txt') > 2):
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
                x =  gaus(n, curr_matr)
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


call()

