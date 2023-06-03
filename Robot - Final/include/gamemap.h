#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "mapcell.h"
// Encabezado que define toda la funcionabilidad del mapa del juego

class gamemap
{
    public:
        gamemap();
        mapcell* playerCell;
        mapcell cell [15][10];
        void draw();
        // método que obtiene las coordenadas del jugador y actualiza el mapa
        bool setPlayerCell(int playerX, int playerY);
        void drawPortada();
        void drawVictoria();
        void drawVictoria2();
        void drawVictoria3();
        void drawVictoria4();
        virtual ~gamemap();
        bool isGameOver = false;


    protected:

    private:
        void loadMapFromFile();
        void loadMapFromFile2();
        void loadMapFromFile3();
        void loadMapFromFile4();
        void createMapToFile();
        void createMapToFile2();
        void createMapToFile3();
        void createMapToFile4();
};

#endif // GAMEMAP_H
