def str_to_int(lin):
    lst = lin.split(" ")
    int_list = [int(i) for i in lst]
    return int_list


def create_list(inpt, num):
    matrix = []
    for i in range (num):
        k = inpt.readline()
        j = k.strip()
        matrix.append(str_to_int(j))
    return matrix



#smthing like Main
try:
    with open ('input.txt', 'r') as inpt:
        line_num = int((inpt.readline()).strip())
        mat = create_list(inpt, line_num)
        inpt.close()
except:
    with open ('exit.txt', 'w') as exit:
        exit.write('There is no such file')
        exit.close()


with open ('exit.txt', 'w') as exit:
    x = [0 for i in range(line_num) ]
    n = line_num
    for i in range(n):
        if mat[i][i] == 0.0:
            exit.write("There is no solution")
            break
        for j in range(i+1, n):
            temp = mat[j][i]/mat[i][i]

            for k in range(n+1):
                mat[j][k] = mat[j][k] - temp * mat[i][k]


    x[n-1] = mat[n-1][n]/mat[n-1][n-1]

    for i in range(n-2,-1,-1):
        x[i] = mat[i][n]

        for j in range(i+1,n):
            x[i] = x[i] - mat[i][j]*x[j]

        x[i] = x[i]/mat[i][i]

    for i in range(n):
        exit.write(str(x[i]))
        exit.write('\t')
