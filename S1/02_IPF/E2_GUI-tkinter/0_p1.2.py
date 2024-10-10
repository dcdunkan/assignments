from tkinter import Tk, Text, Menu
from tkinter.constants import NS, EW, HORIZONTAL, VERTICAL, NONE, LEFT
from tkinter.ttk import Button, Frame, Scrollbar

root = Tk()

menubar = Menu(root)
root.config(menu=menubar)

file_menu = Menu(menubar, tearoff=False)
file_menu.add_command(label="New file")
menubar.add_cascade(label="File", menu=file_menu)

notepad = Frame(root)
notepad.pack()

xscroll = Scrollbar(notepad, orient=HORIZONTAL)
yscroll = Scrollbar(notepad, orient=VERTICAL)
textbox = Text(notepad, width=80, height=20, wrap=NONE)

xscroll.config(command=textbox.xview)
yscroll.config(command=textbox.yview)
textbox.config(xscrollcommand=xscroll.set, yscrollcommand=yscroll.set)

textbox.grid(row=0, column=0)
xscroll.grid(row=1, column=0, sticky=EW)
yscroll.grid(row=0, column=1, sticky=NS)

textbox.focus()

root.mainloop()
