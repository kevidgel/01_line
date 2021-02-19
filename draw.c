#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    int x = x0; 
    int y = y0;

    int A = y1 - y0;
    int B = x0 - x1;

    int d = 2 * A + B; 

    //Octant 1
    if (A <= -1 * B && A > 0) 
    {
        printf("1\n");
        while (x <= x1)
        {
            plot(s, c, x, y); 
            if (d > 0) 
            {
                y ++;
                d += 2 * B;
            }
            x++;
            d += 2 * A; 
        }
    }
    //2 
    else if (A > -1 * B && -1 * B > 0) 
    {
        printf("2\n");
        while (y <= y1)
        {
            plot(s, c, x, y); 
            if (d < 0) 
            {
                x ++;
                d += 2 * A;
            }
            y++;
            d += 2 * B; 
        }
    }
    //3
    else if (A > B && -1 * B < 0) 
    {
        printf("3\n");
        while (y <= y1)
        {
            plot(s, c, x, y); 
            if (d > 0) 
            {
                x --;
                d -= 2 * A;
            }
            y++;
            d += 2 * B; 
        }
    }
    //4
    else if (A <= B && A > 0) 
    {
        printf("4\n");
        while (x >= x1)
        {
            plot(s, c, x, y); 
            if (d < 0) 
            {
                y ++;
                d += 2 * B;
            }
            x--;
            d -= 2 * A; 
        }
    }
    //5
    else if (-1 * A <= B && -1* A > 0) 
    {
        printf("5\n");
        while (x >= x1)
        {
            plot(s, c, x, y); 
            if (d > 0) 
            {
                y --;
                d -= 2 * B;
            }
            x--;
            d -= 2 * A; 
        }
    }
    //6
    else if (-1 * A > B && B > 0) 
    {
        printf("6\n");
        while (y >= y1)
        {
            plot(s, c, x, y); 
            if (d < 0) 
            {
                x --;
                d -= 2 * A;
            }
            y--;
            d -= 2 * B; 
        }
    }
    //7
    else if (-1 * A > -1 * B && -1 * B > 0) 
    {
        printf("7\n");
        while (y >= y1)
        {
            plot(s, c, x, y); 
            if (d > 0) 
            {
                x ++;
                d += 2 * A;
            }
            y--;
            d -= 2 * B; 
        }
    }
    //8
    else if (-1 * A <= -1 * B && -1 * A > 0) 
    {
        printf("8\n");
        while (x <= x1)
        {
            plot(s, c, x, y); 
            if (d < 0) 
            {
                y --;
                d -= 2 * B;
            }
            x++;
            d += 2 * A; 
        }
    }
    // horizontal
    else if (A == 0)
    {
        if(B < 0)
        {
            while(x <= x1)
            {
                plot(s, c, x, y);
                x++;
            }
        }
        else
        {
            while(x >= x1)
            {
                plot(s, c, x, y);
                x--;
            }
        }
    }
    // vertical
    else if (B == 0)
    {
        if(A > 0)
        {
            while(y <= y1)
            {
                plot(s, c, x, y);
                y++;
            }
        }
        else
        {
            while(y >= y1)
            {
                plot(s, c, x, y);
                y--;
            }
        }
    }
}
