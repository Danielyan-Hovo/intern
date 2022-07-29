class Matrix:
    __size = 0
    __line_len = 0
    __matrix = []
    def __init__(self, row, column):
        self.__size = row
        self.__line_len = column
        self.__matrix = [[0 for j in range(self.__line_len)] for i in range(self.__size)]


    def get(self, row, column):
        return self.__matrix[row][column]


    def set(self, row, column, data):
        self.__matrix[row][column] = data


    def set_line(self, row, data):
        self.__matrix[row] = data


    def get_line(self, row):
        return self.__matrix[row]


    def display(self):
        print(self.__matrix)


