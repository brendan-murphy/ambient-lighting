import serial
import autopy


#arduino = serial.Serial("COM3", 9600)

resX, resY = autopy.screen.get_size()
xLED = 90
xLED = 90

def WriteSection(xStart, yStart, xFinish, yFinish, scr):
    R = 0
    G = 0
    B = 0
    count = 0
    for x in range(xStart,  xFinish, 2):
        for y in range(yStart, yFinish):
            r, g, b = autopy.color.hex_to_rgb(scr.get_color(x, y))
            R += r; G += g; B += b
            count += 1

    R = R/count
    G = G/count
    B = B/count
    print R,G,B
    #arduino.wri


while True:
    screen = autopy.bitmap.capture_screen()
    WriteSection(0, 0, resX/3, resY/2, screen)

#screen = autopy.bitmap.capture_screen()
#print autopy.color.hex_to_rgb(screen.get_color(100, 101))
