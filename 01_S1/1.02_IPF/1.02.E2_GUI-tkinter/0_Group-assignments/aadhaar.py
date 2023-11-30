from tkinter import Canvas, IntVar, StringVar, Tk
from tkinter.ttk import (
    Button,
    Combobox,
    Frame,
    Label,
    Entry,
    Scrollbar,
    Radiobutton,
)
from tkinter.font import BOLD, ITALIC, NORMAL
from tkinter.constants import BOTH, LEFT, NW, RIGHT, VERTICAL, W, Y
from tkinter.filedialog import askopenfilename

def font(size, style=NORMAL):
    return ("Open Sans", size, style)



BOLD_ITALIC = BOLD + " " + ITALIC
FONT = font(11, NORMAL)

root = Tk()
root.title("Aadhaar Enrolment/Update Form")
root.resizable(False, False)
root.geometry("900x600+100+100")

# Scrollbar configuration
main_frame = Frame(root)
main_frame.pack(fill=BOTH, expand=1)
canvas = Canvas(main_frame)
canvas.pack(side=LEFT, fill=BOTH, expand=1)
scrollbar = Scrollbar(main_frame, orient=VERTICAL, command=canvas.yview)
scrollbar.pack(side=RIGHT, fill=Y)
canvas.configure(yscrollcommand=scrollbar.set)
canvas.bind("<Configure>", lambda e: canvas.configure(scrollregion=canvas.bbox("all")))
root_frame = Frame(canvas)
canvas.create_window((0, 0), window=root_frame, anchor=NW)

# Title
title_frame = Frame(root_frame)
Label(
    title_frame,
    text="Under Section 3 of THE AADHAAR (TARGETED DELIVERY OF FINANCIAL AND OTHER SUBSIDIES, BENEFITS AND SERVICES) ACT, 2016 (Aadhaar Act)",
    font=font(9, BOLD),
).pack()
Label(title_frame, text="Aadhaar Enrolment/Update Form", font=font(16, BOLD)).pack(
    padx=25, pady=10
)
Label(
    title_frame,
    text="Aadhaar enrolment is free and voluntary. No charges are applicable for form and Aadhaar enrolment.",
    font=font(11, BOLD),
    foreground="firebrick1",
).pack()
Label(
    title_frame,
    text="In case of update, provide your UID, name and only that field which needs update.",
    font=font(11, BOLD),
    foreground="firebrick1",
).pack()
title_frame.pack(pady=10)

# FORM
form = Frame(root_frame)

# Details
details = Frame(form)

name, uid, pre_enrolment_id = StringVar(), StringVar(), StringVar()

Label(details, text="Pre-enrolment ID", font=FONT).grid(
    row=0, column=0, sticky=W, pady=3
)
Entry(details, width=52, textvariable=pre_enrolment_id, font=FONT).grid(row=1, column=0, sticky=W)

Label(details, text="UID (In case of update)", font=FONT).grid(
    row=0, column=1, sticky=W, pady=3
)
Entry(details, width=52, textvariable=uid, font=FONT).grid(row=1, column=1, sticky=W, padx=3)

Label(details, text="Full Name", font=FONT).grid(row=2, column=0, sticky=W, pady=3)
Entry(details, width=105, textvariable=name, font=FONT).grid(
    row=3, column=0, sticky=W, columnspan=2
)

# GENDER
gender_selector = Frame(details)
gender_check_buttons = Frame(gender_selector)

Label(gender_selector, text="Gender:", font=FONT).grid(row=0, column=0, sticky=W)

gender = IntVar()
Radiobutton(gender_check_buttons, text="Male", variable=gender, value=0).grid(
    row=0, column=0, sticky=W, padx=4
)
Radiobutton(gender_check_buttons, text="Female", variable=gender, value=1).grid(
    row=0, column=1, sticky=W, padx=4
)
Radiobutton(gender_check_buttons, text="Other", variable=gender, value=2).grid(
    row=0, column=2, sticky=W, padx=4
)
gender_check_buttons.grid(row=0, column=1, padx=10)
gender_selector.grid(row=5, column=0, sticky=W, pady=5, columnspan=2)

# DATE OF BIRTH
dob_chooser = Frame(details)
dob_boxes = Frame(dob_chooser)

Label(dob_chooser, text="Date of Birth:", font=FONT).grid(row=0, column=0, sticky=W)

Combobox(dob_boxes, values=[str(i) for i in range(1, 32)], width=4).grid(
    row=0, column=0, padx=3
)
Combobox(
    dob_boxes,
    values=[
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
    ],
    width=10,
).grid(row=0, column=1, padx=3)
Combobox(dob_boxes, values=[str(i) for i in range(1970, 2024)], width=6).grid(
    row=0, column=2, padx=3
)

dob_boxes.grid(row=0, column=1, padx=10)
dob_chooser.grid(row=6, column=0, sticky=W, pady=5, columnspan=2)

# ADDRESS
address = Frame(details)

(
    care_of,
    house_no,
    street,
    landmark,
    area,
    village,
    po,
    district,
    subdistrict,
    state,
    email,
    mobile,
    pin,
) = (
    StringVar(),
    StringVar(),
    StringVar(),
    StringVar(),
    StringVar(),
    StringVar(),
    StringVar(),
    StringVar(),
    StringVar(),
    StringVar(),
    StringVar(),
    StringVar(),
    StringVar(),
)

Label(address, text="Address", font=font(13, BOLD)).grid(row=0, column=0, sticky=W, pady=3)

address1 = Frame(address)

Label(address1, text="C/o", font=FONT).grid(row=0, column=0, sticky=W, pady=3)
Entry(address1, width=100, textvariable=care_of, font=FONT).grid(row=0, column=1, padx=12, pady=3)

address1.grid(row=1, column=0, sticky=W)

address2 = Frame(address)

Label(address2, text="House no./Building/Apartment", font=FONT).grid(
    row=1, column=0, sticky=W, padx=3, pady=3
)
Entry(address2, width=51, textvariable=house_no, font=FONT).grid(
    row=2, column=0, padx=3, pady=3
)
Label(address2, text="Street/Road/Lane", font=FONT).grid(
    row=1, column=1, sticky=W, padx=3, pady=3
)
Entry(address2, width=52, textvariable=street, font=FONT).grid(row=2, column=1, padx=3, pady=3)

Label(address2, text="Landmark", font=FONT).grid(row=3, column=0, sticky=W, padx=3, pady=3)
Entry(address2, width=51, textvariable=landmark, font=FONT).grid(
    row=4, column=0, padx=3, pady=3
)
Label(address2, text="Area/Locality/Sector", font=FONT).grid(
    row=3, column=1, sticky=W, padx=3, pady=3
)
Entry(address2, width=52, textvariable=area, font=FONT).grid(row=4, column=1, padx=3, pady=3)

Label(address2, text="Village/Town/City", font=FONT).grid(
    row=5, column=0, sticky=W, padx=3, pady=3
)
Entry(address2, width=51, textvariable=village, font=FONT).grid(
    row=6,
    column=0,
    padx=3, pady=3,
)
Label(address2, text="Post Office", font=FONT).grid(row=5, column=1, sticky=W, padx=3)
Entry(address2, width=52, textvariable=po, font=FONT).grid(
    row=6,
    column=1,
    padx=3, pady=3,
)

address2.grid(row=2, column=0, sticky=W)

address3 = Frame(address)

Label(address3, text="District", font=FONT).grid(row=1, column=0, sticky=W, pady=3)
Entry(address3, width=34, textvariable=district, font=FONT).grid(row=2, column=0, pady=3)
Label(address3, text="Sub-district", font=FONT).grid(row=1, column=1, sticky=W, padx=7, pady=3)
Entry(address3, width=34, textvariable=subdistrict, font=FONT).grid(
    row=2, column=1, padx=7, pady=3
)
Label(address3, text="State", font=FONT).grid(row=1, column=2, sticky=W, pady=3)
Entry(address3, width=34, textvariable=state, font=FONT).grid(row=2, column=2, pady=3)

Label(address3, text="E-mail", font=FONT).grid(row=3, column=0, sticky=W, pady=3)
Entry(address3, width=34, textvariable=email, font=FONT).grid(row=4, column=0, pady=3)
Label(address3, text="Mobile No.", font=FONT).grid(row=3, column=1, sticky=W, padx=7, pady=3)
Entry(address3, width=34, textvariable=mobile, font=FONT).grid(row=4, column=1, padx=7, pady=3)
Label(address3, text="Pin Code", font=FONT).grid(row=3, column=2, sticky=W, pady=3)
Entry(address3, width=34, textvariable=pin, font=FONT).grid(row=4, column=2, pady=3)

address3.grid(row=3, column=0, sticky=W)
address.grid(row=7, column=0, sticky=W, pady=5, columnspan=2)

# RELATIONSHIP
relation, relname = IntVar(), StringVar()
relationship = Frame(details)
relationship_options = Frame(relationship)

Label(relationship, text="Details of:", font=FONT).grid(row=0, column=0, sticky=W)
Radiobutton(relationship_options, text="Father", variable=relation, value=0).grid(
    row=0, column=0, sticky=W, padx=4
)
Radiobutton(relationship_options, text="Mother", variable=relation, value=1).grid(
    row=0, column=1, sticky=W, padx=4
)
Radiobutton(relationship_options, text="Guardian", variable=relation, value=2).grid(
    row=0, column=2, sticky=W, padx=4
)
Radiobutton(relationship_options, text="Husband", variable=relation, value=3).grid(
    row=0, column=3, sticky=W, padx=4
)
Radiobutton(relationship_options, text="Wife", variable=relation, value=4).grid(
    row=0, column=4, sticky=W, padx=4
)
Label(relationship, text="Name of the selected person", font=FONT).grid(
    row=1, column=0, sticky=W, pady=3, columnspan=2
)
Entry(relationship, width=105, textvariable=relname, font=FONT).grid(
    row=2, column=0, sticky=W, columnspan=2
)
Label(relationship, text="EID / Aadhaar number of the selected person", font=FONT).grid(
    row=3, column=0, sticky=W, pady=3, columnspan=2
)
Entry(relationship, width=105, textvariable=relname, font=FONT).grid(
    row=4, column=0, sticky=W, columnspan=2
)
relationship_options.grid(row=0, column=1, padx=10)
relationship.grid(row=8, column=0, sticky=W, pady=5, columnspan=2)


def dummy_open_file():
    return askopenfilename(filetypes=[("PDF Documents", ".pdf")])


# VERIFICATION
verification_type = IntVar()
verification = Frame(details)
verification_types = Frame(relationship)

Label(verification, text="Verification Documents", font=font(13, BOLD)).grid(
    row=0, column=0, sticky=W
)
files = Frame(verification)

Label(files, text="Proof of Identity", font=FONT).grid(
    row=0, column=0, sticky=W, pady=6
)
Label(files, text="Proof of Address", font=FONT).grid(row=0, column=1, sticky=W, padx=12)
Label(files, text="Proof of Relationship", font=FONT).grid(
    row=0, column=2, sticky=W
)
Label(files, text="Proof of Date of Birth", font=FONT).grid(
    row=0, column=3, sticky=W, padx=12
)
Button(files, text="Browse", padding=5, command=dummy_open_file).grid(
    row=1, column=0, sticky=W
)
Button(files, text="Browse", padding=5, command=dummy_open_file).grid(
    row=1, column=1, sticky=W, padx=12
)
Button(files, text="Browse", padding=5, command=dummy_open_file).grid(
    row=1, column=2, sticky=W
)
Button(files, text="Browse", padding=5, command=dummy_open_file).grid(
    row=1, column=3, sticky=W, padx=12
)

files.grid(row=2, column=0, sticky=W, columnspan=2, pady=5)
verification_types.grid(row=0, column=1, padx=10)
verification.grid(row=9, column=0, sticky=W, pady=5, columnspan=2)

# Ending
details.grid(row=0, column=0, sticky=W)
form.pack(pady=10, padx=20)


Button(root_frame, text="Submit").pack()

root.mainloop()
