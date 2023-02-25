#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace sf;
using namespace std;

int main()
{
    int bikeX=0;
    int carx=rand()%4;
    float carY=-100;
    int score=0;
    float speed=4;
    string pr="";
    bool game,key = false;
    RenderWindow app(VideoMode(500, 800), "Street Bike");   //creating window
    app.setFramerateLimit(30);
    Texture tbg,tbike,tcar;
    tbg.loadFromFile("images/roadbg.png");
    tbike.loadFromFile("images/bike.png");
    tcar.loadFromFile("images/car.png");

    Font font;
    font.loadFromFile("font/MATURASC.TTF");

    Sprite sbg(tbg),sbike(tbike),scar(tcar);
    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed)
                app.close();
        }

        app.draw(sbg);


        if(!game)
        {
        pr="Score"+to_string(score);
        Text tscore(pr,font,30);
        tscore.setPosition(40,20);
        app.draw(tscore);

        if(Keyboard::isKeyPressed(Keyboard::Right) && !key)
        {
            key=true;
            if(bikeX<3)   bikeX++;
        }
        if(Keyboard::isKeyPressed(Keyboard::Left) && !key)
        {
            key=true;
            if(bikeX>0)   bikeX--;
        }
        if(!Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right)) key = false;
        if(carY>900)
        {
            carY=-100;
            carx=rand()%4;
            speed=4+1*score;
            score++;
        }
        else    carY+=speed;
        for(int i=0;i<4;i++)
        {
            if(i!=carx)
            {
                scar.setPosition(50+i*100,carY);
                app.draw(scar);
            }
        }
        if(carx!=bikeX&&carY>600&&carY<770)
        {
            game=true;
        }

        sbike.setPosition(50+bikeX*100,700);
        app.draw(sbike);

        }
        else
        {
            pr="STREET BIKE\n\tGame Over!!\n\t\tscore:"+to_string(score);
            Text tscore(pr,font,30);
            tscore.setPosition(130,300);
            app.draw(tscore);

        }
        app.display();
    }

}
