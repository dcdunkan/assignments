from tkinter import Tk, Text, StringVar, messagebox, IntVar
from tkinter.ttk import Progressbar, Label, Button
from time import sleep

root = Tk()
root.title("Anonymous Instant Messaging!")
root.geometry("400x300")

Label(root, text="Send messages anoynmously to a stranger:").pack(pady=10)

text_field = Text(root, width=30, height=10)
text_field.insert("1.0", "-This is an example for programs-")
text_field.insert("1.24", "GUI ")
text_field.delete("1.0")
text_field.delete("end - 2c")

text_field.pack(pady=5)

DEFAULT_BUTTON_TEXT = "Send message"
btn_text = StringVar(value=DEFAULT_BUTTON_TEXT)
progress = IntVar()


def send():
    btn_text.set("Sending...")
    for i in range(0, 101):
        progress.set(i)
        root.update_idletasks()
        sleep(0.0000001)
    messagebox.showinfo("Success", "Message sent successfully!")
    progress.set(0)
    btn_text.set(DEFAULT_BUTTON_TEXT)


Progressbar(root, length=200, variable=progress).pack(pady=5)
Button(root, textvariable=btn_text, command=send).pack()

root.mainloop()
