#include "Canvas.h"
#include "Canvas.h"

Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;
    c.resize(height, std::vector<char>(width, ' '));
}

void Canvas::DrawCircle(int x0, int y0, int radius, char ch) {
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        SetPoint(x0 + x, y0 + y, ch);
        SetPoint(x0 + y, y0 + x, ch);
        SetPoint(x0 - y, y0 + x, ch);
        SetPoint(x0 - x, y0 + y, ch);
        SetPoint(x0 - x, y0 - y, ch);
        SetPoint(x0 - y, y0 - x, ch);
        SetPoint(x0 + y, y0 - x, ch);
        SetPoint(x0 + x, y0 - y, ch);

        if (err <= 0) {
            y++;
            err = err + 2 * y + 1;
        }
        if (err > 0) {
            x--;
            err = err - 2 * x + 1;
        }
    }
}

void Canvas::FillCircle(int x, int y, int radius, char ch) {
    for (int h = -radius; h <= radius; ++h)
        for (int w = -radius; w <= radius; ++w)
            if (w * w + h * h <= radius * radius)
                SetPoint(x + w, y + h, ch);
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    DrawLine(left, top, right, top, ch);
    DrawLine(left, bottom, right, bottom, ch);
    DrawLine(left, top, left, bottom, ch);
    DrawLine(right, top, right, bottom, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int h = top; h <= bottom; h++)
        for (int w = left; w <= right; w++)
            SetPoint(w, h, ch);
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < height && y >= 0 && y < width)
        c[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {

    int deltaX = abs(x2 - x1);
    int deltaY = abs(y2 - y1);
    int signX = 0, signY = 0;

    if (x1 < x2)
        signX++;
    else
        signX--;

    if (y1 < y2)
        signY++;
    else
        signY--;

    int error = deltaX - deltaY;

    SetPoint(x1, y1, ch);

    while (x1 != x2 || y1 != y2) {
        SetPoint(x1, y1, ch);
        int error2 = error * 2;

        if (error2 > -deltaY) {
            error -= deltaY;
            x1 += signX;
        }
        if (error2 < deltaX) {
            error += deltaX;
            y1 += signY;
        }
    }
}

void Canvas::Print() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++)
            std::cout << (char)c[i][j];
        std::cout << '\n';
    }
}

void Canvas::Clear() {
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            c[i][j] = ' ';
}
