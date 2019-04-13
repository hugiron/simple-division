import ctypes

div_lib = ctypes.cdll.LoadLibrary('./div.so')
div_lib.simple_division.restype = ctypes.c_char_p

a = int(input('Enter A: '))
b = int(input('Enter B: '))
n = int(input('Enter N: '))
print('Result: {}'.format(div_lib.simple_division(a, b, n).decode()))
#print(div_lib.simple_division(a, b, n))
