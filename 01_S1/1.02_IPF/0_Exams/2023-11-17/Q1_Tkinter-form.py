# 17-11-2023: TEST 1, QUESTION 1 OF 1

from tkinter import Tk, StringVar, IntVar, Text
from tkinter.ttk import Frame, Label, Entry, Checkbutton, Radiobutton, Combobox, Button
from tkinter.constants import W, EW
from tkinter.messagebox import showinfo

root = Tk()
root.title("Feedback")
root.geometry("400x650+600+100")
root.resizable(False, False)

QUESTION_FONT = ("Segoe UI", 10, "bold")

# TITLE

title_frame = Frame(root)
Label(title_frame, text="My Feedback",
      font=("Segoe UI", 21, "bold")).pack(pady=5)
title_frame.pack(pady=10)

form = Frame(root)

# DETAILS

name = StringVar()
email = StringVar()
password = StringVar()

details_grid = Frame(form)

Label(details_grid, text="Name").grid(row=0, column=0, sticky=W, pady=3)
Entry(details_grid, width=30, textvariable=name).grid(row=0, column=1, padx=10)

Label(details_grid, text="Email").grid(row=1, column=0, sticky=W, pady=3)
Entry(details_grid, width=30, textvariable=email).grid(
    row=1, column=1)

Label(details_grid, text="Password").grid(row=2, column=0, sticky=W, pady=3)
Entry(details_grid, width=30, show="*", textvariable=password).grid(
    row=2, column=1)

details_grid.grid(row=0, column=0, sticky=W, pady=5)

# EMOTIONS

emotion_checks = Frame(form)

emotion_question = "Please check all the emotions that apply to you:"
Label(emotion_checks, text=emotion_question,
      font=QUESTION_FONT).grid(row=0, column=0, sticky=W)

anger, sad, happy, ambivalent = IntVar(), IntVar(), IntVar(), IntVar()
Checkbutton(emotion_checks, text="Angry", variable=anger).grid(
    row=1, column=0, sticky=W)
Checkbutton(emotion_checks, text="Sad", variable=sad).grid(
    row=2, column=0, sticky=W)
Checkbutton(emotion_checks, text="Happy", variable=happy).grid(
    row=3, column=0, sticky=W)
Checkbutton(emotion_checks, text="Ambivalent", variable=ambivalent).grid(
    row=4, column=0, sticky=W)

emotion_checks.grid(row=1, column=0, sticky=W, pady=5)

# SATISFACTION

satisfaction_frame = Frame(form)

satisfaction_question = "How satisfied were you with our service?"
Label(satisfaction_frame, text=satisfaction_question,
      font=QUESTION_FONT).grid(row=0, column=0, sticky=W)

satisfaction = IntVar()

Radiobutton(satisfaction_frame, text="Very Satisfied",
            variable=satisfaction, value=5).grid(row=1, column=0, sticky=W)
Radiobutton(satisfaction_frame, text="Satisfied",
            variable=satisfaction, value=4).grid(row=2, column=0, sticky=W)
Radiobutton(satisfaction_frame, text="Didn't care",
            variable=satisfaction, value=3).grid(row=3, column=0, sticky=W)
Radiobutton(satisfaction_frame, text="Dissatisfied",
            variable=satisfaction, value=2).grid(row=4, column=0, sticky=W)
Radiobutton(satisfaction_frame, text="Very dissatisfied",
            variable=satisfaction, value=1).grid(row=5, column=0, sticky=W)

satisfaction_frame.grid(row=2, column=0, sticky=W, pady=5)

# COMMENT

comments_frame = Frame(form)

Label(comments_frame, text="Further comments",
      font=QUESTION_FONT).grid(row=0, column=0, sticky=W)
Text(comments_frame, height=6, width=40, font=(
    "Segoe UI", 10)).grid(row=1, column=0, sticky=W, pady=3)

comments_frame.grid(row=3, column=0, sticky=W, pady=5)

# LOCATION

location_frame = Frame(form)

location = StringVar()
location.set("Select Location")
locations = ("India", "England", "Canada", "Australia")

Label(location_frame, text="Location visited:", font=QUESTION_FONT).grid(
    row=0, column=0, sticky=W, pady=3)

Combobox(location_frame, values=locations, textvariable=location).grid(
    row=0, column=1, sticky=EW, pady=3, padx=5)

location_frame.grid(row=4, column=0, sticky=W, pady=5)

# SUBMIT


def on_submit():
    showinfo("Success", message="Submitted successfully! Thank you for your feedback.")


Button(form, text="Submit", command=on_submit).grid(
    row=5, column=0, sticky=EW, pady=5, padx=10)

form.pack(pady=10)

# trigger the opening of the window
root.mainloop()
