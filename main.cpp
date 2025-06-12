#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
using namespace sf;
using namespace std;
Vector2u sizewin = { 800,800 };
float fl=500.f;
Vector3f offset ={0,0,-fl};
Vector2f out3d(Vector3f in,float f=fl) {
    in = in + offset;
    float newx=(f*in.x)/(f+in.z);
    float newy=(f*in.y)/(f+in.z);
    return Vector2f(newx,newy);
}
class Cube3d {
    Vector2f positionPoints2d[8];
    Vector3f positionPoints3d[8];
    Vector3f center = {0,0,0.f};
    Vector3f Pos3d = { 0.f,0.f,0.f };
public:
    void movePos3d(Vector3f in) {
        positionPoints3d[0] = positionPoints3d[0] + in;
        positionPoints3d[1] = positionPoints3d[1] + in;
        positionPoints3d[2] = positionPoints3d[2] + in;
        positionPoints3d[3] = positionPoints3d[3] + in;

        positionPoints3d[4] = positionPoints3d[4] + in;
        positionPoints3d[5] = positionPoints3d[5] + in;
        positionPoints3d[6] = positionPoints3d[6] + in;
        positionPoints3d[7] = positionPoints3d[7] + in;
        center += in;
    }
    float radius = 100;
    Color color;
    Cube3d(Vector3f a={0,0,0}, Color c=Color::White) {
        Pos3d = a;
        color = c;
        positionPoints3d[0] = Vector3f(Pos3d.x + radius, Pos3d.y + radius, Pos3d.z + radius);
        positionPoints3d[1] = Vector3f(Pos3d.x - radius, Pos3d.y + radius, Pos3d.z + radius);
        positionPoints3d[2] = Vector3f(Pos3d.x + radius, Pos3d.y + radius, Pos3d.z - radius);
        positionPoints3d[3] = Vector3f(Pos3d.x - radius, Pos3d.y + radius, Pos3d.z - radius);

        positionPoints3d[4] = Vector3f(Pos3d.x + radius, Pos3d.y - radius, Pos3d.z + radius);
        positionPoints3d[5] = Vector3f(Pos3d.x - radius, Pos3d.y - radius, Pos3d.z + radius);
        positionPoints3d[6] = Vector3f(Pos3d.x + radius, Pos3d.y - radius, Pos3d.z - radius);
        positionPoints3d[7] = Vector3f(Pos3d.x - radius, Pos3d.y - radius, Pos3d.z - radius);
    }
    void setPos3d(Vector3f a = { 0,0,0 }, Color c = Color::White) {
        Pos3d = a;
        color = c;
        positionPoints3d[0] = Vector3f(Pos3d.x + radius, Pos3d.y + radius, Pos3d.z + radius);
        positionPoints3d[1] = Vector3f(Pos3d.x - radius, Pos3d.y + radius, Pos3d.z + radius);
        positionPoints3d[2] = Vector3f(Pos3d.x + radius, Pos3d.y + radius, Pos3d.z - radius);
        positionPoints3d[3] = Vector3f(Pos3d.x - radius, Pos3d.y + radius, Pos3d.z - radius);

        positionPoints3d[4] = Vector3f(Pos3d.x + radius, Pos3d.y - radius, Pos3d.z + radius);
        positionPoints3d[5] = Vector3f(Pos3d.x - radius, Pos3d.y - radius, Pos3d.z + radius);
        positionPoints3d[6] = Vector3f(Pos3d.x + radius, Pos3d.y - radius, Pos3d.z - radius);
        positionPoints3d[7] = Vector3f(Pos3d.x - radius, Pos3d.y - radius, Pos3d.z - radius);
    }
    float rotX=0, rotY=0, rotZ=0;
    void rotateX(float angle) {
        rotX += angle;
        angle = angle * (M_PI / 180);
        for (int i=0; i <= 7; i++) {
            positionPoints3d[i] = Vector3f(positionPoints3d[i].x, positionPoints3d[i].y * cos(angle) - positionPoints3d[i].z * sin(angle), positionPoints3d[i].y * sin(angle)
                + positionPoints3d[i].z * cos(angle));
        }center = Vector3f(center.x, center.y * cos(angle) - center.z * sin(angle), center.y * sin(angle)
            + center.z * cos(angle));
    };
    void rotateY(float angle) {
        double rottX = rotX;
        rotY += angle;
        rotateX(-rottX);
        angle = angle * (M_PI / 180);
        for (int i = 0; i <= 7; i++) {
            positionPoints3d[i] = Vector3f(positionPoints3d[i].x * cos(angle) + positionPoints3d[i].z * sin(angle), positionPoints3d[i].y, -positionPoints3d[i].x * sin(angle) + positionPoints3d[i].z * cos(angle));
        }center = Vector3f(center.x * cos(angle) + center.z * sin(angle), center.y, -center.x * sin(angle) + center.z * cos(angle));
        rotateX(rottX);
    };
    void rotateZ(float angle) {
        rotZ += angle;
        angle = angle * (M_PI / 180);
        for (int i = 0; i <= 7; i++) {
            positionPoints3d[i] = Vector3f(positionPoints3d[i].x * cos(angle) - positionPoints3d[i].y * sin(angle), positionPoints3d[i].x * sin(angle) + positionPoints3d[i].y * cos(angle), positionPoints3d[i].z);
        }center = Vector3f(center.x * cos(angle) - center.y * sin(angle), center.x * sin(angle) + center.y * cos(angle), center.z);
    };
    VertexArray GetObj() {
        VertexArray CubeLines(PrimitiveType::Lines, 24);
            if(positionPoints3d[0].z>0)positionPoints2d[0] = out3d(positionPoints3d[0]);
            if (positionPoints3d[1].z > 0)positionPoints2d[1] = out3d(positionPoints3d[1]);
            if (positionPoints3d[2].z > 0)positionPoints2d[2] = out3d(positionPoints3d[2]);
            if (positionPoints3d[3].z > 0)positionPoints2d[3] = out3d(positionPoints3d[3]);

            if (positionPoints3d[4].z > 0)positionPoints2d[4] = out3d(positionPoints3d[4]);
            if (positionPoints3d[5].z > 0)positionPoints2d[5] = out3d(positionPoints3d[5]);
            if (positionPoints3d[6].z > 0)positionPoints2d[6] = out3d(positionPoints3d[6]);
            if (positionPoints3d[7].z > 0)positionPoints2d[7] = out3d(positionPoints3d[7]);

            CubeLines[0].position = positionPoints2d[0];
            CubeLines[1].position = positionPoints2d[1];
            CubeLines[2].position = positionPoints2d[1];
            CubeLines[3].position = positionPoints2d[3];
            CubeLines[4].position = positionPoints2d[2];
            CubeLines[5].position = positionPoints2d[3];
            CubeLines[6].position = positionPoints2d[2];
            CubeLines[7].position = positionPoints2d[0];

            CubeLines[8].position = positionPoints2d[0];
            CubeLines[9].position = positionPoints2d[4];
            CubeLines[10].position = positionPoints2d[1];
            CubeLines[11].position = positionPoints2d[5];
            CubeLines[12].position = positionPoints2d[2];
            CubeLines[13].position = positionPoints2d[6];
            CubeLines[14].position = positionPoints2d[3];
            CubeLines[15].position = positionPoints2d[7];

            CubeLines[16].position = positionPoints2d[4];
            CubeLines[17].position = positionPoints2d[5];
            CubeLines[18].position = positionPoints2d[4];
            CubeLines[19].position = positionPoints2d[6];
            CubeLines[20].position = positionPoints2d[6];
            CubeLines[21].position = positionPoints2d[7];
            CubeLines[22].position = positionPoints2d[7];
            CubeLines[23].position = positionPoints2d[5];

            for (int i = 0; i < 24; i++) {
                CubeLines[i].color = color;
            }
            return CubeLines;
        }
};
const int xqcubes = 5;
const int zqcubes = 5;
const int yqcubes = 5;
Cube3d cubes[xqcubes][zqcubes][yqcubes];
void movecubes(Vector3f in) {
    for (int i = 0; i < xqcubes; i++) {
        for (int j= 0; j < zqcubes; j++) {
            for (int t = 0; t < yqcubes; t++) {
                cubes[i][j][t].movePos3d(in);
            }
        }
    }
}
void rotateYcubes(float a) {
    for (int i = 0; i < xqcubes; i++) {
        for (int j = 0; j < zqcubes; j++) {
            for (int t = 0; t < yqcubes; t++) {
                cubes[i][j][t].rotateY(a);
            }
        }
    }
}
void rotateXcubes(float a) {
    for (int i = 0; i < xqcubes; i++) {
        for (int j = 0; j < zqcubes; j++) {
            for (int t = 0; t < yqcubes; t++) {
                cubes[i][j][t].rotateX(a);
            }
        }
    }
}
int main() {
    RenderWindow window(VideoMode(sizewin), "SFML works!");
    View view;
    view.setCenter({ 0, 0 });
    view.setSize(Vector2f(window.getSize().x, window.getSize().y));
    window.setView(view);

    for (int i = 0; i < xqcubes; i++) {
        for (int j = 0; j < zqcubes; j++) {
            for (int t = 0; t < zqcubes; t++) {
                cubes[i][j][t].setPos3d({ 200.f * i,200.f*t,200.f * j });
            }
        }
    }
        while (window.isOpen())
        {
            while (const optional event = window.pollEvent())
            {
                if (event->is<Event::Closed>())
                    window.close();
            };
            window.display();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))movecubes({ -0.5f,0,0 });
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))movecubes({ 0.5f,0,0 });
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))movecubes({ 0.0,-0.5f,0 });
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) movecubes({ 0,0.5f,0 });
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))movecubes({ 0,0,0.5f });
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))movecubes({ 0,0,-0.5f });
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))rotateYcubes(0.1f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))rotateYcubes(-0.1f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))rotateXcubes(-0.1f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))rotateXcubes(0.1f);
            window.clear();
            for (int i = 0; i < xqcubes; i++) {
                for (int j = 0; j < zqcubes; j++) {
                    for (int t = 0; t < yqcubes; t++) {
                        window.draw(cubes[i][j][t].GetObj());
                    }
                }
            }
        }
        return 0;
}