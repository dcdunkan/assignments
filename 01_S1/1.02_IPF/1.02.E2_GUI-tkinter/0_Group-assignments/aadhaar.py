from tkinter import IntVar, StringVar, Tk
from tkinter.ttk import Checkbutton, Frame, Label, Entry
from tkinter.font import BOLD, ITALIC, NORMAL
from tkinter.constants import LEFT, CENTER, W


BOLD_ITALIC = BOLD + " " + ITALIC


def font(size, style=NORMAL):
    return ("Open Sans", size, style)


root = Tk()
root.title("Aadhaar Enrolment/Update Form")
root.resizable(False, False)


# Title
title_frame = Frame(root)

# Label(
#     title_frame,
#     text="Under Section 3 of THE AADHAAR (TARGETED DELIVERY OF FINANCIAL AND OTHER SUBSIDIES, BENEFITS AND SERVICES) ACT, 2016 (Aadhaar Act)",
#     font=font(9, BOLD),
# ).pack()
Label(title_frame, text="Aaadhaar Enrolment/Update Form", font=font(16, BOLD)).pack(
    padx=25, pady=10
)
# Label(
#     title_frame,
#     text="Aadhaar enrolment is free and voluntary. No charges are applicable for form and Aadhaar enrolment.",
#     font=font(11, BOLD),
#     foreground="firebrick1",
# ).pack()
# Label(
#     title_frame,
#     text="In case of update, provide your UID, name and only that field which needs update.",
#     font=font(11, BOLD),
#     foreground="firebrick1",
# ).pack()

title_frame.pack(pady=10)

# FORM
form = Frame(root)

# Details
details = Frame(form)

name, uid, pre_enrolment_id = StringVar(), StringVar(), StringVar()

FONT = font(10, NORMAL)

Label(details, text="Pre-enrolment ID", font=FONT).grid(
    row=0, column=0, sticky=W, pady=3
)
Entry(details, width=30, textvariable=pre_enrolment_id).grid(row=1, column=0, sticky=W)

Label(details, text="UID (In case of update)", font=FONT).grid(
    row=0, column=1, sticky=W, pady=3
)
Entry(details, width=30, textvariable=uid).grid(row=1, column=1, sticky=W, padx=3)

Label(details, text="Full Name", font=FONT).grid(row=2, column=0, sticky=W, pady=3)
Entry(details, width=60, textvariable=name).grid(
    row=3, column=0, sticky=W, columnspan=2
)

# GENDER
gender_selector = Frame(details)
gender_check_buttons = Frame(gender_selector)

Label(gender_selector, text="Gender:", font=FONT).grid(row=0, column=0, sticky=W)

male, female, other = IntVar(), IntVar(), IntVar()
Checkbutton(gender_check_buttons, text="Male", variable=male).grid(
    row=0, column=0, sticky=W, padx=4
)
Checkbutton(gender_check_buttons, text="Female", variable=female).grid(
    row=0, column=1, sticky=W, padx=4
)
Checkbutton(gender_check_buttons, text="Other", variable=other).grid(
    row=0, column=2, sticky=W, padx=4
)
gender_check_buttons.grid(row=0, column=1, padx=10)
gender_selector.grid(row=5, column=0, sticky=W, pady=5, columnspan=2)

# DATE OF BIRTH
dob_chooser = Frame(details)
dob_boxes = Frame(dob_chooser)

Label(dob_chooser, text="Date of Birth (DD/MM/YYYY):", font=FONT).grid(
    row=0, column=0, sticky=W
)

day, month, year = IntVar(value=1), IntVar(value=1), IntVar(value=2000)
Entry(dob_boxes, width=7, textvariable=day).grid(row=0, column=0)
Label(dob_boxes, text="/", font=FONT).grid(row=0, column=1)
Entry(dob_boxes, width=7, textvariable=month).grid(row=0, column=2)
Label(dob_boxes, text="/", font=FONT).grid(row=0, column=3)
Entry(dob_boxes, width=14, textvariable=year).grid(row=0, column=4)

dob_boxes.grid(row=0, column=1, padx=10)
dob_chooser.grid(row=6, column=0, sticky=W, pady=5, columnspan=2)

# ADDRESS
address = Frame(details)
Label(address, text="Address", font=FONT).grid(
    row=0,
    column=0,
)
address.grid(row=7, column=0, sticky=W, pady=5, columnspan=2)

details.grid(row=0, column=0, sticky=W)

form.pack(pady=10, padx=20)

root.mainloop()
