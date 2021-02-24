#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int toRed(double h) 
{
    double r;
    if ( (0 <= h && h < 60) || (300 <= h && h < 360) ) 
    {
        r = 1; 
    }
    if ( (60 <= h && h < 120) || (240 <= h && h < 300) ) 
    {
        r = (1 - fabs(fmod(h/60, 2.0) - 1)); 
    }
    if ( 120 <= h && h < 240 ) 
    {
        r = 0; 
    }
    return (int) floor(r * 255) % 256; 
}

int toGreen(double h)
{
    double g;
    if ( 60 <= h && h < 180 ) 
    {
        g = 1; 
    }
    if ( (0 <= h && h < 60) || (180 <= h && h < 240) ) 
    {
        g = (1 - fabs(fmod(h/60, 2.0) - 1)); 
    }
    if ( 240 <= h && h < 360 ) 
    {
        g = 0; 
    }
    return (int) floor(g * 255) % 256; 
}

int toBlue(double h) {
    double b;
    if ( 180 <= h && h < 300 ) 
    {
        b = 1; 
    }
    if ( (120 <= h && h < 180) || (300 <= h && h < 360) ) 
    {
        b = (1 - fabs(fmod(h/60, 2.0) - 1)); 
    }
    if ( 0 <= h && h < 120 ) 
    {
        b = 0; 
    }
    return (int) floor(b * 255) % 256; 
}

int main() 
{
    screen s1;
    color c; 

    clear_screen(s1);

    int degree;
    for(degree = 0; degree < 120; degree += 5) 
    {

        double x1 = 200 * cos((degree * M_PI) / 180.0) + 250;
        double y1 = 200 * sin((degree * M_PI) / 180.0) + 250;

        double x2 = 200 * cos(((degree + 120) * M_PI) / 180.0) + 250;
        double y2 = 200 * sin(((degree + 120) * M_PI) / 180.0) + 250;

        double x3 = 200 * cos(((degree + 240) * M_PI) / 180.0) + 250;
        double y3 = 200 * sin(((degree + 240) * M_PI) / 180.0) + 250;

        c.red = toRed(degree * 3);
        c.green = toGreen(degree * 3);
        c.blue = toBlue(degree * 3);

        draw_line(round(x1), round(y1), round(x2), round(y2), s1, c);
        draw_line(round(x2), round(y2), round(x3), round(y3), s1, c);
        draw_line(round(x3), round(y3), round(x1), round(y1), s1, c);
 
    }
    display(s1);
    save_extension(s1, "triangle.png");
}