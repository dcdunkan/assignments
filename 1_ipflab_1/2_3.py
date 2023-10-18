from tkinter import Tk, StringVar, messagebox
from tkinter.ttk import Label, Entry, Button

root = Tk()
root.title("Textboxes")

name = StringVar()
branch = StringVar()
year = StringVar()

Label(root, text="Name:").pack()
Entry(root, textvariable=name).pack()

Label(root, text="Branch:").pack()
Entry(root, textvariable=branch).pack()

Label(root, text="Year:").pack()
Entry(root, textvariable=year).pack()

def show_details():
    text = name.get() + " " + branch.get() + " " + year.get()
    messagebox.showinfo("Submitted Successfully!", text)
    
Button(root, text="Submit", command=show_details).pack()

root.mainloop()