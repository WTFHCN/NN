
import tkinter
import numpy as np
from PIL import ImageGrab, Image, ImageDraw


class Segment(tkinter.Canvas):
    def __init__(self, master=None, **kw):
        super().__init__(master=master, width=280, height=280, bd=4, ** kw)
        self.lastx, self.lasty = 0, 0
        self.bind("<Button-1>", self.xy)  # 绑定鼠标左键
        self.bind("<B1-Motion>", self.add_line)  # 拖动鼠标左键

    def xy(self, event):
        '''更新坐标'''
        self.lastx, self.lasty = event.x, event.y

    def add_line(self, event):
        '''画一条线段'''
        self.create_line(self.lastx, self.lasty, event.x,
                         event.y, fill='black', width=3)
        global draw
        draw.line((self.lastx, self.lasty, event.x,
                   event.y), fill=(0, 0, 0), width=15)
        self.xy(event)

    def layout(self):
        self.grid(column=0, row=0, sticky='nwes')


def getter():
    global image1
    tmp = image1
    tmp = tmp.convert('L')
    tmp = tmp.resize((28, 28))
    arr = np.array(tmp)
    A = np.where(arr > 230, 0, 1)
    A = A.tolist()
    # b = b.flatten()
    with open("1.txt", "w") as f:
        for i in range(len(A)):
            for j in range(len(A[i])):
                f.write(str(A[i][j]))
                f.write(' ')
            f.write('\n')
# def main():


# def __init__():
#     main()

white = (255, 255, 255)
green = (0, 128, 0)

image1 = Image.new("RGB", (280, 280), white)
draw = ImageDraw.Draw(image1)

root = tkinter .Tk()
root.columnconfigure(0, weight=1)
root.rowconfigure(0, weight=1)
segment = Segment(root)

corretB = tkinter.Button(root, text="点我", width=28, command=getter)
segment.pack()
corretB.pack()

root.mainloop()
