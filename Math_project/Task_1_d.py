import numpy as np
from sympy import *
import os




def derivative(funksjon):
    x = symbols('x')
    funksjon1 = funksjon.split('.')
    if len(funksjon1)>1:
        funksjon=str(funksjon1[1])
    else:
        funksjon=str(funksjon1[0])
    d_funksjon = diff(funksjon)
    d_funksjon = str(d_funksjon)
    return str(d_funksjon)



def dxdx(funksjon,x,dx):
    while True:        
        x1=x
        fx = eval(funksjon)
        x = (x+dx)
        fdx = eval(funksjon)
        x=x1
        E = abs(eval(derivative(funksjon))-(fdx-fx)/dx)
        if E <= 0.001:
            return dx
        else:
            dx*=49/50



os.system('cls') # Denne må endres fra 'cls' til 'clear' i linux

print(f"{round(dxdx('7*(x)**2-8*(x)+1',x=1,dx=1),5)} Er den største delta x som gjør E(x) <= 0.001\n")
print(f"{round(dxdx('np.sin(x)',x=np.pi/4,dx=1),4)} Er den største delta x som gjør E(x) <= 0.001\n")
print(f"{round(dxdx('(1-x)/(x+3)**2',x=1,dx=1),3)} Er den største delta x som gjør E(x) <= 0.001\n")
print(f"{dxdx('np.sqrt(1+x**2)',x=5,dx=1):.2f} Er den største delta x som gjør E(x) <= 0.001\n")
