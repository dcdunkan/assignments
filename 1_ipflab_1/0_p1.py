import os
from tkinter import END, Tk, Text, filedialog
from tkinter.constants import NS, EW, HORIZONTAL, VERTICAL, NONE, W
from tkinter.ttk import Button, Frame, Scrollbar

root = Tk()

toolbar = Frame(root)
toolbar.pack(anchor=W)

new_file_btn = Button(toolbar, text="New")
new_file_btn.grid(row=0, column=0)

open_file_btn = Button(toolbar, text="Open")
open_file_btn.grid(row=0, column=1)

save_file_btn = Button(toolbar, text="Save")
save_file_btn.grid(row=0, column=2)

notepad = Frame(root)
notepad.pack()

xscroll = Scrollbar(notepad, orient=HORIZONTAL)
yscroll = Scrollbar(notepad, orient=VERTICAL)
textbox = Text(notepad, width=80, height=20, wrap=NONE)


def save_file_as():
    filename = filedialog.asksaveasfilename(defaultextension=".txt",title="Save file as...")
    
    return textbox.get(0.0, END)


xscroll.config(command=textbox.xview)
yscroll.config(command=textbox.yview)
textbox.config(xscrollcommand=xscroll.set, yscrollcommand=yscroll.set)

textbox.grid(row=0, column=0)
xscroll.grid(row=1, column=0, sticky=EW)
yscroll.grid(row=0, column=1, sticky=NS)

textbox.focus()

root.mainloop()
