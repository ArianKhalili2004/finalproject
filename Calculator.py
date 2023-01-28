# ----------------------base--------------------------
from tkinter import *
from time import sleep
from numpy import sqrt
from tkinter import messagebox
root = Tk()
root.title("Calculator ®")
root.geometry("500x600")
root.resizable(width=False,height=False)
# root.configure(width=500,height=200)
# -----------------------number_1-------------------------------
frame_1 = Frame(root,width=500,height=200,bg="powder blue",relief=RIDGE)
frame_1.pack(side=TOP)

entry_1 = Entry(root,font=('digital-7 80'),bg="powder blue",relief=RAISED)
entry_1.place(x=0,y=0,width=500,height=200)
# -----------------------list_numbers---------------------------
result_1 = IntVar()
result_2 = IntVar()
math = StringVar()
# -----------------------functions--------------------------

def clear():
    entry_1.delete(0,END)
    return
def remove():
    entry_1.delete(0,END)
    return


def show(number):

    current = entry_1.get()
    entry_1.delete(0,END)
    entry_1.insert(0,str(current)+str(number))
    for things in current:
        if things == type(str):
            entry_1.delete(0,END)
            messagebox.showerror("somthing went wrong")

def float():
    current = entry_1.get()
    entry_1.delete(0,END)
    entry_1.insert(0,str(current)+".")
def plus():
    first_number =entry_1.get()
    global result_1
    global math
    result_1 = int(first_number)
    math = "plus"
    entry_1.delete(0,END)
    return
def minus():
    first_number =entry_1.get()
    global result_1
    global math
    math = "minus"
    result_1 = int(first_number)
    entry_1.delete(0,END)
    return
def multiply():
    first_number =entry_1.get()
    global result_1
    global math
    math = "multiply"
    result_1 = int(first_number)
    entry_1.delete(0,END)
    return
def div():
    first_number =entry_1.get()
    global result_1
    global math
    math = "div"
    result_1 = int(first_number)
    entry_1.delete(0,END)
    return
def power():
    first_number =entry_1.get()
    global result_1
    global math
    math = "power"
    result_1 = int(first_number)
    entry_1.delete(0,END)
    return
def radical():
    first_number =entry_1.get()
    global result_1
    global math
    math = "radical"
    result_1 = int(first_number)
    entry_1.delete(0,END)
    return

def result():
    second_number = entry_1.get()
    entry_1.delete(0,END)
    global math
    if math == "plus":
        entry_1.insert(0, result_1 + int(second_number))
    if math == "multiply":
        entry_1.insert(0, result_1 * int(second_number))
    if math == "minus":
        entry_1.insert(0, result_1 - int(second_number))
    if math == "div":
        entry_1.insert(0, result_1 / int(second_number))
    if math == "power":
        entry_1.insert(0, result_1 **int(second_number))
    if math == "radical":
        entry_1.insert(0, sqrt(result_1))
# ---------------general_buttons---------------------------
frame_2 = Frame(root,width=500,height=400,bg = "light gray")
frame_2.pack(side=TOP)
button_clear =Button(root,text="C",width=25,height=4,font=("Didot 10"),command=lambda :clear(),bg="light blue")
button_clear.place(x=10,y=210)
button_remove = Button(root,text="<-",width=10,height=4,font=("Didot 10"),bg="light blue",command=lambda:remove())
button_remove.place(x=220,y=210)
button_plus = Button(root,text="+",width=10,height=5,font=("Didot 10"),bg="pink",command=lambda:plus())
button_plus.place(x=320,y=210)
button_minus = Button(root,text="_",width=10,height=5,font=("Didot 10"),bg="pink",command=lambda :minus())
button_minus.place(x=410,y=210)
button_multiply = Button(root,text="X",width=10,height=5,font=("Didot 10"),bg="pink",command=lambda :multiply())
button_multiply.place(x=320,y=310)
button_div = Button(root,text="÷",width=10,height=5,font=("Didot 10"),bg="pink",command=lambda:div())
button_div.place(x=410,y=310)
button_power = Button(root,text="x^x",width=10,height=5,font=("Didot 10"),bg="pink",command=lambda :power())
button_power.place(x=320,y=410)
button_radical = Button(root,text="x//2",width=10,height=5,font=("Didot 10"),bg="pink",command=lambda :radical())
button_radical.place(x=410,y=410)
button_result = Button(root,text="=",width=20,height=5,font=("Didot 10"),bg="pink",command=lambda :result())
button_result.place(x=325,y=510)

# ------------------------numbers_buttons------------------------

button_1 = Button(root,text="1",width=10,height=4,font=("Didot 10"),command=lambda :show("1"))
button_1.place(x=10,y=290)
button_2 = Button(root,text="2",width=10,height=4,font=("Didot 10"),command=lambda :show("2"))
button_2.place(x=110,y=290)
button_3 = Button(root,text="3",width=10,height=4,font=("Didot 10"),command=lambda :show("3"))
button_3.place(x=210,y=290)
button_4 = Button(root,text="4",width=10,height=4,font=("Didot 10"),command=lambda :show("4"))
button_4.place(x=10,y=370)
button_5 = Button(root,text="5",width=10,height=4,font=("Didot 10"),command=lambda :show("5"))
button_5.place(x=110,y=370)
button_6 = Button(root,text="6",width=10,height=4,font=("Didot 10"),command=lambda :show("6"))
button_6.place(x=210,y=370)
button_7 = Button(root,text="7",width=10,height=4,font=("Didot 10"),command=lambda :show("7"))
button_7.place(x=10,y=450)
button_8 = Button(root,text="8",width=10,height=4,font=("Didot 10"),command=lambda :show("8"))
button_8.place(x=110,y=450)
button_9 = Button(root,text="9",width=10,height=4,font=("Didot 10"),command=lambda :show("9"))
button_9.place(x=210,y=450)
button_0 = Button(root,text="0",width=22,height=4,font=("Didot 10"),command=lambda :show("0"))
button_0.place(x=10,y=530)
button_int = Button(root,text="•",width=10,height=4,font=("Didot 10"),command=lambda :show("."))
button_int.place(x=210,y=530)
root.mainloop()

