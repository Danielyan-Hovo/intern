
with open ('exit.txt', 'w') as exit:
        exit.write("")


def gaus(n, matr):
    with open ('exit.txt', 'a') as exit:
        x = [0 for i in range(n) ]
        mat = matr
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
        exit.write('\n')
        
        

def call():
        matrix = []
        with open('input.txt', 'r') as inpt:
                for line in inpt:               
                        if line != "\n" :
                                t = len(line.split())-1
                                curr = []
                                matrix.append(list(map(int, line.split())))
                        else:
                                gaus(t, matrix)
                                matrix = []    
call()

