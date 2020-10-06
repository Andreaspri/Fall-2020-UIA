import numpy as np
from sympy import *
import os




def dx(funksjon,x,dx):
    x1=x
    fx = eval(funksjon)
    print(fx,"Dette er f(x)")
    x = (x+dx)
    fdx = eval(funksjon)
    print(fdx,"Dette er f(dx)")
    x=x1
    return abs(eval(derivative(funksjon))-(fdx-fx)/dx)


def derivative(funksjon):
    x = symbols('x')
    funksjon1 = funksjon.split('.')
    if len(funksjon1)>1:
        funksjon=str(funksjon1[1])
    else:
        funksjon=str(funksjon1[0])
    d_funksjon = diff(funksjon)
    d_funksjon = str(d_funksjon)
    if d_funksjon.find('sqrt') != -1:
        where = d_funksjon.find('sqrt')
        d_funksjon = d_funksjon[:where] + 'np.' + d_funksjon[where:]
    print(d_funksjon)
    return str(d_funksjon)


os.system('cls') # Denne må endres fra 'cls' til 'clear' i linux

print(f'Tilnærmingen i funksjon 1 har {round(dx("7*(x)**2-8*(x)+1",1,0.1),3)} i avik\n')

print(f"Tilnærmingen i funksjon 2 har {round(dx('np.sin(x)',np.pi/4,0.1),3)} i avik\n")

print(f"Tilnærmingen i funksjon 3 har {round(dx('(1-x)/(x+3)**2',1,0.1),3)} i avik\n")

print(f"Tilnærmingen i funksjon 4 har {round(dx('np.sqrt(1+x**2)',5,0.1),5)} i avik\n")
