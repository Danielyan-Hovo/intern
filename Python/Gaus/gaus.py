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
temp = []
t = 3
matric = []
#smthing like Main

def gaus( n, mat):
    with open ('exit.txt', 'w') as exit:
        x = [0 for i in range(n) ]
        print(x)
        for i in range(n):
            if mat[i][i] == 0:
                exit.write("There is no solution")
                break
            for j in range(i+1, n):
                tem = mat[j][i]/mat[i][i]

                for k in range(n+1):
                    mat[j][k] = mat[j][k] - tem * mat[i][k]


        x[n-1] = mat[n-1][n]/mat[n-1][n-1]

        for i in range(n-2,-1,-1):
            x[i] = mat[i][n]

            for j in range(i+1,n):
                x[i] = x[i] - mat[i][j]*x[j]

            x[i] = x[i]/mat[i][i]

        for i in range(n):
            exit.write(f"X{i+1} = "+str(round(x[i], 4)))
            exit.write('\t')
        exit.close()
        
        
'''try:
    with open ('input.txt', 'r') as inpt:
    
        for line in inpt:
            if len(line) != 2:
                if len(line.split()) != len(temp):
                    t = len(line.split())-1
                    print(matric)
                    gaus(t,matric)
                    matric = []
                    print(t)
                temp = list(map(int, line.split()))
                t = len(temp) -1
                matric.append(temp)
            else:
                size = line
                #print(size)
        print(matric)


        #for elem in matric:
            #print(elem,end='\n')

        inp = inpt.readline()
        line_num = int((inp).strip())
        print(inp)
        mat = create_list(inpt, line_num)
        print(mat)
        inpt.close()
except:
    with open ('exit.txt', 'w') as exit:
        exit.write('There is no such file')
        exit.close()'''
        
        
with open ('input.txt', 'r') as inpt:
        for line in inpt:
            if len(line) != 2:
                if len(line.split()) != t+1:
                    gaus(t,matric)
                    t = len(line.split())-1
                    print(matric)
                    #gaus(t,matric)

                    matric = []
                    print(t)
                temp = list(map(int, line.split()))
                t = len(temp) -1
                matric.append(temp)
            else:
                size = line
                #print(size)
        
        print(matric)


        #for elem in matric:
            #print(elem,end='\n')

        '''inp = inpt.readline()
        line_num = int((inp).strip())
        print(inp)
        mat = create_list(inpt, line_num)
        print(mat)'''
        inpt.close()


#gaus(line_num, mat)
