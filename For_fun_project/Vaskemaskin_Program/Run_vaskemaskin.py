import os
from time import sleep
import xlrd
from openpyxl import load_workbook
from datetime import datetime

vaskemaskin_program = "/home/pi/Desktop/Vaskemaskin_Program/Vaskemaskin_v1.4.py"
excel_fil = "/home/pi/Desktop/Vaskemaskin_Program/vaskemaskin_data.xlsx"
error_log_file = "/home/pi/Desktop/Vaskemaskin_Program/error_log.txt"

def prep():
    count = int(les_av_excel())
    return count

def open_excel():
    excel = load_workbook(excel_fil)
    excel_ark = excel["vaskemaskin_data"]
    excel1 = xlrd.open_workbook(excel_fil)
    excel_ark1 = excel1.sheet_by_name("vaskemaskin_data")
    return excel,excel_ark1

def les_av_excel():
    excel,excel_ark5 = open_excel()
    count=0
    count = excel_ark5.cell_value(2,26)
    if count == "":
        count=0
    excel.save(excel_fil)
    count1=int(count)
    return count1
def antall_error():
    count = 0
    try:
        with open(error_log_file,"r") as fil:
            for i in fil.readlines():
                count+=1
            return count
    except:
        return 0
def start():   
    count = prep()
    while True:
        os.system(f"python3 {vaskemaskin_program}")
        count+=1
        os.system("clear")
        print(f"Antall ganger kjørt: {count}")
        print(f"Antall error: {antall_error()}")
        try:
            with open(error_log_file,"r") as fil:
                print("Nylige error: \n")
                date = datetime.now().date().day
                for i in fil.readlines():
                    first = i.split("-")[2]
                    done = int(first.split(" ")[0])
                    if date == done:
                        print(i)
        except:
            pass
        sleep(400)

if __name__=='__main__':
    start()

    