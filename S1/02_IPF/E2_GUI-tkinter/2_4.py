from tkinter import Tk, scrolledtext, Listbox, WORD, messagebox, IntVar, END
from tkinter.ttk import Progressbar, Button, Label
from time import sleep

root = Tk()

Label(root, text="Address:").pack(pady=10)
address = scrolledtext.ScrolledText(root, wrap=WORD, height=4, width=35)
address.pack()


def submit():
    messagebox.showinfo("Address", address.get("1.0", END))


Button(root, text="Submit", command=submit).pack()

progress = IntVar()
progress_bar = Progressbar(root, mode="determinate", length=100, variable=progress)


def update_progress():
    for i in range(0, 100):
        progress.set(i)
        root.update_idletasks()
        sleep(0.005)


progress_bar.pack(pady=10)

Button(root, text="Install", command=update_progress).pack()

listbox = Listbox(root)
listbox.insert(0, "Banana")
listbox.insert(1, "Pineapple")
listbox.insert(2, "Orange")
listbox.pack()

root.mainloop()
