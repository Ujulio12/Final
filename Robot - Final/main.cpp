#include <iostream>
#include "player.h"
#include "mapcell.h"
#include "gamemap.h"

using namespace std;

int main()
{
    gamemap map;
    player hero;
    map.drawPortada();
    //map.draw();
    while(map.isGameOver==false)
    {
      cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
      hero.callInput();

      //Actualizar información del jugador en el mapa
      if(map.setPlayerCell(hero.getValueX(), hero.getValueY()))
      {
     //   system("cls");
        map.draw();
      } else
      {
       // system("cls");
        hero.resetToSafePosition();
        //Dibujamos el mapa
        map.draw();
      }
      //map.draw();

    }

    return 0;
}

