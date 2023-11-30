from tkinter import Tk, BooleanVar
from tkinter.ttk import Label, Checkbutton, Combobox

root = Tk()
root.title("Order Fruits")
root.geometry("500x500")

Label(root, text="Choose Fruits:").pack()

FRUITS = ("Orange", "Apple", "Grapes", "Banana")
Combobox(root, values=FRUITS).pack()

check_value = BooleanVar()
Checkbutton(root, text="Submit", variable=check_value).pack()

root.mainloop()
