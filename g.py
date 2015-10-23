import subprocess
from Tkinter import *
import tkMessageBox
def out(q, s="1"):
    q = str(int(q)+1)
    process = subprocess.Popen("./" + q, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    output = process.communicate(s + "\n")[0]
    tkMessageBox.showinfo("output answer", output)
    print output

root = Tk()
root.configure()
root.title('TOC Code')
root.geometry('{}x{}'.format(600, 240))
LL = Label(root, text = "Please select the question, input the string and then hit run!")
LL.pack(side=TOP)
Lb = Listbox(root, relief = SUNKEN, width = 20, height = 4)
Lb.insert(1, " q1.c")
Lb.insert(2, " q2.c")
Lb.insert(3, " q3.c")
Lb.pack(side=TOP, padx=35, pady=5)
L = Label(root, text="Please Enter Input String",pady=15)
L.pack(side=TOP)
E1 = Entry(root)
B = Button(root, text="Run", background = 'yellow', activeforeground = 'black', relief=SUNKEN, command=lambda: out(Lb.curselection()[0], E1.get()))
E1.pack(padx=15, pady=5)
B.pack(padx=15, pady=15)
root.mainloop()
