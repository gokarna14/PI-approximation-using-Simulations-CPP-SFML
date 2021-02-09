#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

int ni = 1, no = 1;


int main()
{
    RenderWindow window(VideoMode(600, 600), "Pi Approximator");
    CircleShape bullet(1);
    RectangleShape R(Vector2f(1000, 35));
    R.setFillColor(Color::Black);
    R.setPosition(0, 0);
    bullet.setFillColor(Color::Green);
    float x, y, d, r = 250, dx, dy;
    long double pi;
    Font font;
    font.loadFromFile("LASER.ttf");
    Text text;
    text.setFont(font);
    text.setFillColor(Color::White);
    text.setPosition(0, 0);
    text.setCharacterSize(15);
    string s;

    while (window.isOpen())
    {
        x = float(rand() % 500 + 50);
        y = float(rand() % 500 + 50);
        dx = 300 - x;
        dy = 300 - y;
        d = sqrt(pow(dx, 2) + pow(dy, 2));
        bullet.setPosition(x, y);

        if (d < r)
        {
            bullet.setFillColor(Color::Green);
            ni++;
        }
        else
        {
            bullet.setFillColor(Color::Red);
            no++;
        }
        pi = (float(ni) / (float(ni + no))) * 4.0;

        s = "PI = " + to_string(pi) + "\nIterations = " + to_string(ni + no);

        text.setString(s);

        // cout << "Pi =  " << pi << "\n" << "Inside: " << ni << "\nOutside: " << no << "\n";

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.draw(bullet);
        window.draw(R);
        window.draw(text);
        window.display();
    }

    return 0;
}