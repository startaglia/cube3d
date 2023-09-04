/*
Copyright (c) 2004-2019, Lode Vandevenne

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <cmath>
#include <string>
#include <vector>
#include <iostream>

#include "quickcg.h"
using namespace QuickCG;

/*
g++ *.cpp -lSDL -O3 -W -Wall -ansi -pedantic
g++ *.cpp -lSDL
*/


// Tutto il codice è più o meno simile solo che per fare gli oggetti con la texture non possiamo piu disegnare una linea verticale e basta ma dobbiamo ciclare sulla colonna per determinare quale texel(texture pixel) utilizzare. Per inserire le texture è più comodo utilizzare un array buffer 2d che contiene volta per volta i pixel che devono essere disegnati in quella texture. Avremo anche bisogno di un altro array per memorizzare le texture (di base però le texture vengono caricate da un file). In questo esempio genereremo texture di prova.


#define screenWidth 640
#define screenHeight 480
//texWidth e texHeight sono la larghezza e l'altezza in texel della texture
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};

//dichiarazione array di buffer per i texel uint32 è un tipo di dato che va da 0 a 4294967295. Questo buffer conterrà dei numeri interi positivi che rappresentaranno il colore del pixel che ci serve in quella texture
Uint32 buffer[screenHeight][screenWidth];

int main(int /*argc*/, char */*argv*/[])
{
  double posX = 22.0, posY = 11.5;  //x and y start position
  double dirX = -1.0, dirY = 0.0; //initial direction vector
  double planeX = 0.0, planeY = 0.66; //the 2d raycaster version of camera plane

  double time = 0; //time of current frame
  double oldTime = 0; //time of previous frame

  //array delle texture. Il cicolo sotto serve per dare le dimensioni alle 8 texture
  std::vector<Uint32> texture[8];
  for(int i = 0; i < 8; i++) texture[i].resize(texWidth * texHeight);

  screen(screenWidth,screenHeight, 0, "Raycaster");

  //di seguito nel blocco di codice dove non entra c'è la generazione di texture casuali. Con un doppio ciclo entriamo in ogni pixel delle texture (texule) e gli assegniamo un determinato colore.
  //generate some textures
#if 0
  for(int x = 0; x < texWidth; x++)
  for(int y = 0; y < texHeight; y++)
  {
    int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
    //int xcolor = x * 256 / texWidth;
    int ycolor = y * 256 / texHeight;
    int xycolor = y * 128 / texHeight + x * 128 / texWidth;
    texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
    texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
    texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
    texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
    texture[4][texWidth * y + x] = 256 * xorcolor; //xor green
    texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
    texture[6][texWidth * y + x] = 65536 * ycolor; //red gradient
    texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
  }
  //in questa altra parte di codice stiamo caricando delle texture da dei file
#else
 //generate some textures
  unsigned long tw, th;
  loadImage(texture[0], tw, th, "pics/eagle.png");
  loadImage(texture[1], tw, th, "pics/redbrick.png");
  loadImage(texture[2], tw, th, "pics/purplestone.png");
  loadImage(texture[3], tw, th, "pics/greystone.png");
  loadImage(texture[4], tw, th, "pics/bluestone.png");
  loadImage(texture[5], tw, th, "pics/mossy.png");
  loadImage(texture[6], tw, th, "pics/wood.png");
  loadImage(texture[7], tw, th, "pics/colorstone.png");
#endif

  //start the main loop
  while(!done())
  {
    for(int x = 0; x < w; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
      double rayDirX = dirX + planeX*cameraX;
      double rayDirY = dirY + planeY*cameraX;

      //which box of the map we're in
      int mapX = int(posX);
      int mapY = int(posY);

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

      //length of ray from one x or y-side to next x or y-side
      double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?

      //calculate step and initial sideDist
      if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if(worldMap[mapX][mapY] > 0) hit = 1;
      }

      //Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(h / perpWallDist);


      int pitch = 100;

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + h / 2 + pitch;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + h / 2 + pitch;
      if(drawEnd >= h) drawEnd = h - 1;




      //texturing calculations
      //nella matrix mappa ci sono come elementi gli 8 tipi di texture. Texnum è l'indice della texture che voglio utilizzare quindi ho bisogno di sottrarre 1 per poter utilizzare anche la tex 0
      int texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!

      //wallX rappresenta il valore esatto del punto in cui è stato colpito il muro, quindi non sono solo le coordinate interne del muro. Questo ci serve per capire quale coordinata x della texture dobbiamo usare
      //calculate value of wallX
      double wallX; //where exactly the wall was hit
      if(side == 0) wallX = posY + perpWallDist * rayDirY;
      //da notare che, in questo caso(side==1) anche se utilizziamo sempre la var wallX in realtà stiamo parlando della coordinata y del muro. Ma di fatto è sempre la coordinata x della texture
      else          wallX = posX + perpWallDist * rayDirX;
      //floor arrotonda, a noi serve un numero intero per calcolare la coordinata x della texture (texure)
      wallX -= floor((wallX));

      //qui mi calcolo la coordinata x della texture
      //x coordinate on the texture
      int texX = int(wallX * double(texWidth));
      //questo serve per vedere in che direzione sta girando la linea di vista
      if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
      if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;

      // TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
      //step è la velocità di incremento della coordinata della texture per pixel. In pratica step dice quanto veloce devono scorrere i pixel della texture in base ai pixel delle coordinate verticali dello schermo. Essendo un valore in virgola mobile abbiamo bisogno di trasformalo in intero per poter selezionare il pixel della texture che ci interessa
      // How much to increase the texture coordinate per screen pixel
      double step = 1.0 * texHeight / lineHeight;
      
      // qui trovo la coordinata iniziale della texture. drawStart è la posizione del primo pixel da disegnare. pitch è la larghezza dei pixel (ovvero la distanza tra i centri di due pixel adiacenti sullo schermo), h è l'altezza dello schermo, lineHeight è l'altezza della linea di texture che dobbiamo disegnare, step è la velocità di incremento della coordinata della texture per pixel dello schermo. In parole più semplici sto calcolando la posizione del primo pixel della linea di texture rispetto all'angolo in alto a sinistra dello schermo. Ad esempio se drawStart è 100, pitch è 8, h è 640, lineHeight è 32 e step è 0.01, la formula restituirà il valore 26.25. Questo significa che il primo pixel della linea di texture sarà posizionato a 26.25 pixel dall'angolo in alto a sinistra dello schermo.
      // Starting texture coordinate
      double texPos = (drawStart - pitch - h / 2 + lineHeight / 2) * step;

      for(int y = drawStart; y < drawEnd; y++)
      {
        //texY è la coordinata y della texture, a differenza di texX ho bisogno di farlo per ogni pixel della colonna orizzontale che voglio stampare (in una matrix le y è l'asse orizzontale) perchè la visuale del giocatore in questo gioco si muoverà solo orizzontalmente e non verticalmente. Si trova castando ad int texPos e dandogli una maschera di texHeight - 1(questo per evitare overflow).
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (texHeight - 1);
        //trovata la coordinata texY incremento la coordinata del pixel della texture step volte(che è la velocità con cui si devono scorrere i pixel della texture)
        texPos += step;
        //mi calcolo il pixel esatto della texture che poi andrò a mettere dentro buffer. ad esempio se texNum è 0, texY è 10 e texX è 20, la formula restituirà il valore 200. Questo significa che il pixel a cui si fa riferimento è il pixel numero 200 nella texture.
        Uint32 color = texture[texNum][texHeight * texY + texX];

        //questo serve per rendere leggermente piu scuro se viene colpito un lato y del muro, rende la grafica un tantino piu realistica. Lo faccio dividendo il numero per 2, quindi posso farlo con l'operatore & binario.
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        if(side == 1) color = (color >> 1) & 8355711;
        buffer[y][x] = color;
      }
    }
    //stampo 
    drawBuffer(buffer[0]);
    //azzero tutti i valori del buffer. equivarrebbe a cancellare tutto lo schermo, ma è importante farlo cosi perchè è piu efficiente, non richiedendo ogni volta di aggiornare l'intero schermo ma aggiornando solo le aree di memoria che vengono effettivamente utilizzate non richiedo molto consumo di memoria. 
    for(int y = 0; y < h; y++) for(int x = 0; x < w; x++) buffer[y][x] = 0; //clear the buffer instead of cls()
    //timing for input and FPS counter
    oldTime = time;
    time = getTicks();
    double frameTime = (time - oldTime) / 1000.0; //frametime is the time this frame has taken, in seconds
    print(1.0 / frameTime); //FPS counter
    redraw();

    //speed modifiers
    double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    double rotSpeed = frameTime * 3.0; //the constant value is in radians/second

    readKeys();
    //move forward if no wall in front of you
    if(keyDown(SDLK_UP))
    {
      if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
    }
    //move backwards if no wall behind you
    if(keyDown(SDLK_DOWN))
    {
      if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    }
    //rotate to the right
    if(keyDown(SDLK_RIGHT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    //rotate to the left
    if(keyDown(SDLK_LEFT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
    if(keyDown(SDLK_ESCAPE))
    {
      break;
    }
  }
}
// Nota: solitamente le immagini vengono archiviate tramite linee di scansione orizzontali, ma per un raycaster le texture vengono disegnate come strisce verticali. Pertanto, per utilizzare in modo ottimale la cache della CPU ed evitare errori di pagina, potrebbe essere più efficiente archiviare le texture in memoria striscia verticale per striscia verticale, invece che per linea di scansione orizzontale. Per fare ciò, dopo aver generato le texture, scambia le loro X e Y con (questo codice funziona solo se texWidth e texHeight sono uguali):

  //scambia la texture X/Y poiché verranno utilizzate come strisce verticali
  //    for(dimensione_t i = 0; i < 8; i++)
  //    for(dimensione_t x = 0; x < dimensione tex; x++)
  //    for(dimensione_t y = 0; y < x; y++)
  //    std::swap(texture[i][texSize * y + x], texture[i][texSize * x + y]);

// Oppure semplicemente scambia X e Y dove vengono generate le texture, ma in molti casi dopo aver caricato un'immagine o ottenuto una texture da altri formati la avrai comunque nelle linee di scansione e dovrai scambiarla in questo modo.

// Quando ottieni il pixel dalla texture, usa invece il seguente codice:
  // Uint32 color = texture[texNum][texSize * texX + texY];
