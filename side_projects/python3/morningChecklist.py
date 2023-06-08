import tkinter as tk
import pathlib
import datetime


file_path = pathlib.Path.home().joinpath("Documents", "vyvanse.txt")
today = datetime.datetime.today()
today_str = today.date().strftime("%m%d%y")

class MainGUI(tk.Frame):
    def __init__(self, parent):
        self.currentVyvanseStatus = self.getVyvanseStatus()
        tk.Frame.__init__(self, parent, bg="white")
        parent.attributes("-fullscreen", False)
        self.setupGUI()

    def getVyvanseStatus(self) -> int:
        with open(file_path, "r") as f:
            vyvanse_status = f.read().strip('\n').split(';')
            f.close()
        last_logged_date = datetime.datetime.strptime(vyvanse_status[1], "%m%d%y")
        if last_logged_date.date() != today.date():
            with open(file_path, "w") as f:
                f.write("0;{}".format(today_str))
                f.close()
            return 0
        else:
            return int(vyvanse_status[0])
    
    def setupGUI(self):
        self.display = tk.Label(self, text="DID YOU TAKE VYVANCE YET?", anchor=tk.CENTER,
                                bg="white", height=2, font=("Arial", 40))
        self.display.grid(row=0, column=0, columnspan=4, sticky=tk.N+tk.E+tk.S+tk.W)

        if self.currentVyvanseStatus == 0:
            update_button = tk.Button(self, bg="white", text="I will take it now.", font=("Arial", 20),
                                    command=lambda:self.process("took"), anchor=tk.CENTER)
            update_button.grid(row=1,column=1, columnspan=2, sticky=tk.N+tk.S+tk.E+tk.W)
        else:
            update_label = tk.Label(self, bg="white", text="Already taken it.", font=("Arial", 20))
            update_label.grid(row=1,column=1, columnspan=2, sticky=tk.N+tk.S+tk.E+tk.W)


        self.pack()
    
    def process(self, command):
        if command == "took":
            if self.currentVyvanseStatus == 0:
                self.currentVyvanseStatus = 1
                update_label = tk.Label(self, bg="white", text="Already taken it.", font=("Arial", 20))
                update_label.grid(row=1,column=1, columnspan=2, sticky=tk.N+tk.S+tk.E+tk.W)
                with open(file_path, "w") as f:
                    f.write("1;{}".format(today_str))
                    f.close()

#################################
#           Main Code           #
#################################
window = tk.Tk()
window.title("Reminder!")
p = MainGUI(window)
window.mainloop()