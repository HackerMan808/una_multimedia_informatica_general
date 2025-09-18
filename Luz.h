#include <ncurses.h>

#define delay_luz 2

class Luz
{
public:
  Luz(int id, int x, int y, int sizeX, int sizeY);

  void setup();
  void draw();
  void update();

  void mover(int dir);

  int getId();

  void setX(int x);
  void setY(int y);

  int getX();
  int getY();

  void setSizeX(int sizeX);
  void setSizeY(int sizeY);

  int getSizeX();
  int getSizeY();

  void setEncendida(bool estado);
  bool getEncendida();


private:
  int id;
  int x, y;
  int size_x, size_y;
  bool encendida;
  float delay=delay_luz;
};