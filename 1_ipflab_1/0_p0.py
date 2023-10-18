from tkinter import W, StringVar, Tk, Entry as TkEntry
from tkinter.ttk import Frame, Label, Radiobutton

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
first_name = Entry(details, placeholder="Enter First Name", width=30)
first_name_label.grid(row=0, column=0, padx=5, pady=2, sticky=W)
first_name.grid(row=0, column=1, padx=5, pady=2)

last_name_label = Label(details, text="Last Name")
last_name = Entry(details, placeholder="Enter Last Name", width=30)
last_name_label.grid(row=1, column=0, padx=5, pady=3, sticky=W)
last_name.grid(row=1, column=1, padx=5, pady=3)

# GENDER
gender_label = Label(details, text="Gender")
gender_label.grid(row=2, column=0, sticky=W, padx=5, pady=2)

gender_chooser_frame = Frame(details)
gender_chooser_frame.grid(sticky=W, row=2, column=1, padx=5, pady=3)

gender_value = StringVar()

gender_male_check = Radiobutton(
    gender_chooser_frame, text="Male", value="male", variable=gender_value
)
gender_male_check.grid(row=0, column=0)

gender_female_check = Radiobutton(
    gender_chooser_frame, text="Female", value="female", variable=gender_value
)
gender_female_check.grid(row=0, column=1, padx=3)

# AGE
age_label = Label(details, text="Age")
age = Entry(details, placeholder="Enter your age", width=30)
age_label.grid(row=3, column=0, padx=5, pady=3, sticky=W)
age.grid(row=3, column=1, padx=5, pady=3)

# DATE OF BIRTH

root.mainloop()
