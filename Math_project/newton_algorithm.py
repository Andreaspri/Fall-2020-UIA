from sympy import *
import multiprocessing

# In sympy there is no need to for np. For example you could just write sin(x) and sqrt(2+x**2) instead of np.sin(x) np.sqrt(2+x**2) 
# np.sin(x) would just couse an error

function_to_test_as_string = '3*x**2+4*x-4'
which_x_do_you_want_to_use = -1

def newton(function,x):
    x0=0
    count=0
    symbols('x')
    der_fx = str(diff(function))
    while abs(x0-x) >= 10**-12:
        if count == 1000: 
            print("There's no real answer")
            return 0
        if x0!=0: x=x0
        if eval(der_fx)==0: 
            print('The algorithm is dividing by zero, pick another x')
            return 0
        count+=1
        x0 = x-(eval(function)/eval(der_fx))
        print('{0}, {1:.12f}, {2:.12f}, {3:.12f}'.format(count,float(x0),float(abs(eval(function)/eval(der_fx))),float(abs(eval(function)/eval(der_fx)/x))))
    return 0

if __name__=='__main__':
    timer = multiprocessing.Process(target=newton,name='Newton',args=(function_to_test_as_string,which_x_do_you_want_to_use))
    timer.start()   # I'm just making a sub-process to make sure it doesn't run for too long
    timer.join(10)  # Timer is 10 seconds
    if str(timer).rfind('exitcode=0') == -1 :
        print('Function timed out, try something else')
        timer.terminate()
