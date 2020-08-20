# Metodo de iteración del punto fijo

import math

def f(x):
    return x * x * x + x * x - 1

# Reescribiendo f(x)=0 a x = g(x)
def g(x):
    return 1 / math.sqrt(1 + x)

# Implementando el método de iteración del punto fijo.
def fixedPointIteration(x0, e, N):
    print('\n\n*** ITERACIÓN PUNTO FIJO ***')
    step = 1
    flag = 1
    condition = True
    while condition:
        x1 = g(x0)
        print('Iteracion-%d, x1 = %0.6f y f(x1) = %0.6f' % (step, x1, f(x1)))
        x0 = x1

        step = step + 1

        if step > N:
            flag = 0
            break

        condition = abs(f(x1)) > e

    if flag == 1:
        print('\nRaiz requerida: %0.8f' % x1)
    else:
        print('\nLa sucesión no es convergente.')

# Input
x0 = input('Ingrese valor inicial: ')
e = input('Error de tolerancia: ')
N = input('Máximo número de iteraciones: ')

# Convertiendo x0 y e a float
x0 = float(x0)
e = float(e)

# Convertiendo N a integer
N = int(N)

# Llamando al método
fixedPointIteration(x0, e, N)
