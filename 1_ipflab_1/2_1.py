from tkinter import Tk, messagebox
from tkinter.ttk import Label, Button

root = Tk()
root.title("Program")
root.geometry("500x500")

Label(root, text="Welcome").pack(pady=10)


def welcome():
    messagebox.showinfo("Hello there!", "How are you?")


Button(root, text="Welcome", command=welcome).pack()
Button(root, text="Exit", command=root.destroy).pack()

root.mainloop()
