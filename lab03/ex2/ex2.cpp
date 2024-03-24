#include <iostream>
#include "Canvas.h" 

int main() {
    Canvas canvas(21, 21);

    // border
    //canvas.DrawLine(0, 0, 0, 20, '-');
    //canvas.DrawLine(0, 20, 20, 20, '|');
    //canvas.DrawLine(20, 0, 20, 20, '-');
    //canvas.DrawLine(0, 0, 20, 0, '|');

    // o linie diagonala
     //canvas.DrawLine(1, 3, 17, 14, '.');

    // cerc cu centrul in (10, 9) cu raza 7
     //canvas.DrawCircle(10, 9, 7, '*');
    // canvas.FillCircle(10, 9, 7, '*');

    // dreptunghi
     canvas.DrawRect(2, 2, 8, 8, '#');
     canvas.FillRect(2, 2, 8, 8, '#');


    canvas.Print();

    canvas.Clear();

    return 0;
}
