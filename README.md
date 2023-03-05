# Day-Night-Digital-Clock
This is a project based C++ that displays a graphical representation of the current time and date along with some visual elements such as a sun, clouds, moon, and stars, based on the time of day.

The program uses several libraries such as conio.h, graphics.h, time.h, dos.h, string.h, stdio.h, stdlib.h, iostream, and sstream.

The cloud function draws a set of white-colored clouds using filled sectors.

The main function uses an infinite loop that retrieves the current time and date using the time function and the localtime function from the time.h library. It then uses the strftime function to format the time and date into strings. The program checks the hour of the day, and if it is between 6 AM and 6 PM, it displays a daytime scene that includes a green background, a red sun, and white-colored clouds. If the time is outside of that range, it displays a night time scene that includes a black background, a half-moon, and stars.

The program uses graphics.h functions such as settextjustify, settextstyle, moveto, outtext, line, circle, sector, setfillstyle, and floodfill to draw the graphical elements on the screen. It also uses getmaxx and getmaxy functions to get the maximum X and Y coordinates of the screen, and putpixel and getpixel functions to manipulate individual pixels. The program ends with a delay of 60,000 milliseconds (1 minute), and the getch and closegraph functions are used to exit the program and close the graphics window.

The main() function begins with initializing the graphics system with initgraph(). Then, it enters an infinite while loop, which allows the program to continue running and updating the display until it is manually exited.

Within the loop, the current time and date are obtained using the time() and localtime() functions from time.h. The current hour is extracted from the time using strftime() and stored as an integer variable called hour.

If the hour variable is between 6 and 18 (inclusive), it is considered day-time. The graphics system is initialized using initgraph() and various graphical elements are drawn, including the current time using outtext(), a green rectangle for the ground using line() and floodfill(), a yellow circle for the sun using circle() and floodfill(), and a white cloud using the cloud() function. The program then loops through every pixel on the screen and fills any black pixels with the color of the sky using getpixel() and floodfill().

If the hour variable is not between 6 and 18, it is considered nighttime. The graphics system is initialized using initgraph() and various graphical elements are drawn, including the current time and date using outtext(), a black rectangle for the sky using floodfill(), a white circle for the full moon using circle() and floodfill(), a black circle for the new moon using circle() and floodfill(), a white cloud using the cloud() function, and random white pixels for stars using putpixel().

After the graphical elements are drawn, the program waits for 60 seconds using delay(), and then the loop starts over again. The program can be manually exited using getch() and closegraph().
