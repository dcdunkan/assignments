from tkinter import W, Tk, Entry as TkEntry
from tkinter.ttk import Frame, Label

root = Tk()
root.resizable(False, False)
root.title("Student Portal: Register")


class Entry(TkEntry):
    def __init__(self, master=None, placeholder="Placeholder", color="grey", **kwargs):
        super().__init__(master, **kwargs)

        self.placeholder = placeholder
        self.placeholder_color = color
        self.default_fg_color = self["fg"]

        self.bind("<FocusIn>", self.foc_in)
        self.bind("<FocusOut>", self.foc_out)

        self.put_placeholder()

    def put_placeholder(self):
        self.insert(0, self.placeholder)
        self["fg"] = self.placeholder_color

    def foc_in(self, *args):
        if self["fg"] == self.placeholder_color:
            self.delete("0", "end")
            self["fg"] = self.default_fg_color

    def foc_out(self, *args):
        if not self.get():
            self.put_placeholder()


title = Frame(root)
title.pack(pady=15, padx=20)

heading = Label(title, text="STUDENT REGISTRATION FORM", font=("", 16, "bold"))
heading.grid(row=0, column=1, sticky=W)

details = Frame(root)
details.pack(pady=5)

first_name_label = Label(details, text="First Name")
first_name_label.grid(row=0, column=0, padx=5, pady=2)
first_name = Entry(details, placeholder="Enter First Name", width=30)
first_name.grid(row=0, column=1, padx=5, pady=2)

last_name_label = Label(details, text="Last Name")
last_name_label.grid(row=1, column=0, padx=5, pady=3)
last_name = Entry(details, placeholder="Enter Last Name", width=30)
last_name.grid(row=1, column=1, padx=5, pady=3)


root.mainloop()
