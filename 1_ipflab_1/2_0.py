from tkinter import Tk
from tkinter.ttk import Button, Label, Entry

root = Tk()

Label(root, text="First name").grid(row=0, column=0, padx=10, pady=10)
Entry(root).grid(row=0, column=1, columnspan=2)
Label(root, text="Second name").grid(row=1, column=0, padx=10, pady=10)
Entry(root).grid(row=1, column=1, columnspan=2)

Button(root, text="Quit", command=root.destroy).grid(row=10, column=2, padx=4, pady=4)

root.mainloop()