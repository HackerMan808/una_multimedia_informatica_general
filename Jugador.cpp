#include "Jugador.h"

Jugador::Jugador(int x, int y,Cuarto *c){
  cuarto=c;
  inicioX=x; inicioY=y;
}

void Jugador::setup()
{  
  m_x=inicioX; m_y=inicioY;
  max_energia = 5;
  m_energia=max_energia;

  m_explotar = false;
  en_luz = false;

  cambiar_cuarto=cuarto->get_idCuarto();
}

int Jugador::update()
{
  detectar_luz();
  if(en_luz){
    if(m_energia<max_energia){
      m_energia+=0.05;
    }
  }else{
    m_energia -= 0.02;
  }


  if (m_energia <= 0)
	{
    m_explotar = true;
  }
  return cambiar_cuarto;
}

void Jugador::draw()
{
  if (!m_explotar)
  {
    if(en_luz){
      attron(COLOR_PAIR(iluminado));
      mvaddch(m_y, m_x, 'o');
      mvaddch(m_y+1, m_x, '^');
      attroff(COLOR_PAIR(iluminado));
    }else{
      attron(COLOR_PAIR(oscuro));
      mvaddch(m_y, m_x, 'o');
      mvaddch(m_y+1, m_x, '^');
      attroff(COLOR_PAIR(oscuro));
    }
    
  }
  if(mostrar_texto){
    int y_aux= 0;
    for (int y = 0; y < buffer_texto.size(); y++) {
      int ch = 0;
      erase();
      mvaddstr(texto_y+y_aux, texto_x, buffer_texto[y].c_str());
      y_aux++;
      if((y+1)%texto_max==0){
        y_aux=0;
      }
      while (ch!='e')
      {
        ch=getch();
      }
    }
    mostrar_texto=false;
  }
  
}

void Jugador::mover(int dir){
  int new_x=m_x;
  int new_y=m_y;
  switch (dir)
  {
    case arriba:
    new_y--;
    break;
  
  case abajo:
      new_y++;
    break;

  case izq:
     new_x--;
    break;

  case der:
    new_x++;
    break;
    
    default:
    break;
  }
  
  if(!colision(new_x, new_y, 0, 1)){
    m_x=new_x;
    m_y=new_y;
  }
}

void Jugador::resistir(){
  if(!en_luz){
    m_energia+=0.05;
  }
}

bool Jugador::colision(int x, int y, int xOffset, int yOffset){
  vector<Objeto> limites = cuarto->get_objetos();
  bool colision = false;
  for(int i=0;i<limites.size();i++){
    if((y>=limites[i].pos[yPos]-yOffset && y<(limites[i].layout.size()+limites[i].pos[yPos]))){
      if(x>=limites[i].pos[xPos]-xOffset && x<(limites[i].layout[0].size()+limites[i].pos[xPos])){
        //interaccion
        if(limites[i].tipo==obj_puerta){
          cambiar_cuarto=limites[i].id_cuarto;
        }

        if(limites[i].tipo==obj_texto){
          buffer_texto=limites[i].texto;
          mostrar_texto=true;
          draw();
          cuarto->borrarObjeto(limites[i].idObj);
        }
        
        if(limites[i].tipo!=obj_nulo) colision=true;
      }
    }
  }
  return colision;
}

void Jugador::detectar_luz(){
  //Luces
  en_luz=false;
  vector<Luz> luces = cuarto->get_luces();
  for(int i=0;i<luces.size();i++){
    if(luces[i].getEncendida()){
      if(m_y>=luces[i].getY() && m_y<(luces[i].getSizeY()+luces[i].getY())
      && m_x>=luces[i].getX() && m_x<(luces[i].getSizeX()+luces[i].getX())){
        en_luz=true; 
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////
void Jugador::setX(int x) { m_x = x; }
void Jugador::setY(int y) { m_y = y; }
int Jugador::getX() { return m_x; }
int Jugador::getY() { return m_y; }
void Jugador::setEnergia(float energia) { m_energia = energia; }
float Jugador::getEnergia() { return m_energia; }
void Jugador::set_cuarto(Cuarto *c){cuarto=c;}
Cuarto *Jugador::get_cuarto(){return cuarto;}