import matplotlib.pyplot as plt
import numpy as np
from sympy import *


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
    return str(d_funksjon)


def graf(x,y,oppgave_nr,funksjon,count):
    plt.plot(x,y,label=funksjon)
    if count == 0:
        plt.xlabel("x - akse")
        plt.ylabel("y - akse")
        plt.grid()
        plt.legend()
        plt.savefig(f"C:\\Users\\Andreas\\Desktop\\matte_grafer\\{oppgave_nr}")
        plt.close()


def oppgave_2a(funksjon,oppgave_nr,start,stop):
    y_liste = []
    nums = np.linspace(start,stop,num=1000)
    count=0
    for x in nums:
        y = eval(funksjon)
        y_liste.append(y)
    graf(nums,y_liste,oppgave_nr,'f(x)',2)

def oppgave_2b(funksjon,oppgave_nr,start,stop):
    y_liste = []
    funksjon = derivative(funksjon)
    nums = np.linspace(start,stop,num=1000)
    count=0
    for x in nums:
        y = eval(funksjon)
        y_liste.append(y)
    graf(nums,y_liste,oppgave_nr,'f´(x)',2)



def oppgave_2c(funksjon,dx,start,stop,oppgave_nr):
    y_list = []
    nums = np.linspace(start,stop,num=1000)
    for x in nums:
        fx = eval(funksjon)
        x = x+dx
        fdx = eval(funksjon)
        y = (fdx-fx)/dx
        y_list.append(y)
    graf(nums,y_list,oppgave_nr,'g(x)',2)

def oppgave_2d(funksjon,dx,start,stop,oppgave_nr):
    y_list = []
    nums = np.linspace(start,stop,num=1000)
    for x in nums:
        fx = eval(funksjon)
        x = (x+dx)
        fdx = eval(funksjon)
        y = abs(eval(derivative(funksjon))-(fdx-fx)/dx)
        y_list.append(y)
    graf(nums,y_list,oppgave_nr,'E(x)',0)




oppgave_2a('7*(x)**2-8*(x)+1','2a_1',0,2,)          # oppgave 2a_1
oppgave_2b('7*(x)**2-8*(x)+1','2b_1',0,2,)          # oppgave 2b_1
oppgave_2c('7*(x)**2-8*(x)+1',0.00014,0,2,'2c_1')   # oppgave 2c_1
oppgave_2d('7*(x)**2-8*(x)+1',0.00014,0,2,'2_1')    # oppgave 2d_1

oppgave_2a('np.sin(x)','2a_2',0,2*np.pi,)           # oppgave 2a_2
oppgave_2b('np.sin(x)','2b_2',0,2*np.pi,)           # oppgave 2b_2
oppgave_2c('np.sin(x)',0.0028,0,2,'2c_2')           # oppgave 2c_2
oppgave_2d('np.sin(x)',0.0028,0,2*np.pi,'2_2')      # oppgave 2d_2

oppgave_2a('(1-x)/(x+3)**2','2a_3',-2,2,)           # oppgave 2a_3
oppgave_2b('(1-x)/(x+3)**2','2b_3',-2,2,)           # oppgave 2b_3
oppgave_2c('(1-x)/(x+3)**2',0.032,0,2,'2c_3')       # oppgave 2c_3
oppgave_2d('(1-x)/(x+3)**2',0.032,-2,2,'2_3')       # oppgave 2d_4

oppgave_2a('np.sqrt(1+x**2)','2a_4',0,10,)          # oppgave 2a_4
oppgave_2b('np.sqrt(1+x**2)','2b_4',0,10,)          # oppgave 2b_4
oppgave_2c('np.sqrt(1+x**2)',0.27,0,2,'2c_4')       # oppgave 2c_4
oppgave_2d('np.sqrt(1+x**2)',0.27,0,10,'2_4')       # oppgave 2d_4



