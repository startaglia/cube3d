/*
Copyright (c) 2004-2021, Lode Vandevenne

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

//place the example code below here:

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int main(int /*argc*/, char */*argv*/[])
{
  // coordinate del giocatore
  double posX = 22, posY = 12;
  // coordinate del casting ray
  double dirX = -1, dirY = 0;
  //coordinate del camera vector. le coordinate del casting ray e del camera vector sono già settate per avere un FOV di 66 gradi, che è il campo visivo tipico di molti giochin sparatutto. La formula per trovare il FOV è: FOV = 2 * arctan(diry / sqrt(dirx^2 + diry^2)). Considerando che la x del casting ray è negativa la formula corrisponde a FOV = 2 * arctan(0.66 / sqrt(1 + 1^2)). Questo calcolo permette di mantenere tutti valori corretti anche quando il player ruota la camera.
  double planeX = 0, planeY = 0.66;
  
  //la differenza tra le variabili time e oldtime determina quanto velocemente si muove il player
  double time = 0; //tempo del fotogramma corrente
  double oldTime = 0; //tempo del fotogramma precedente
  
  //crea lo schermo 
  screen(screenWidth, screenHeight, 0, "Raycaster");

  //di base quaesto loop disegna un intero fotogramma
  while(!done())
  {
  //qui inizia il vero e proprio raycasting. w è una var globale definita in Quickcg. Rappresenta la larghezza dello schermo. Quindi qui sto di fatto ciclando su ogni linea verticale dello schermo
    for(int x = 0; x < w; x++)
    {
      //formula che setta l'ultima x a destra dello schermo a 1, quella centrale a 0 e la prima a sinistra a -1. Questo mi serve per calcolare la direzione del casting ray, o meglio la direzione dei campionamento. Nello specifico:

      //questa formula converte la coordinata x della finestra grafica nella coordinata x nello spazio della camera(camera vector)
      double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space

      //queste formule servono per calcolare tutti i raggi che partono dal giocatore fino al camera vector. Quando raydirx = 0 quello sarà il casting ray centrale.
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;

      //queste sono le coordinate del quadrato in cui si trova il raggio. Partono da dove si trova il giocatore
      int mapX = int(posX);
      int mapY = int(posY);


      // sideDistX e sideDistY sono inizialmente la distanza che il raggio deve percorrere dalla sua posizione iniziale al primo lato x e al primo lato y. Successivamente nel codice verranno incrementati man mano che vengono eseguiti i passaggi.
      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

      //length of ray from one x or y-side to next x or y-side
      //these are derived as:
      //deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
      //deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
      //which can be simplified to abs(|rayDir| / rayDirX) and abs(|rayDir| / rayDirY)
      //where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
      //unlike (dirX, dirY) is not 1, however this does not matter, only the
      //ratio between deltaDistX and deltaDistY matters, due to the way the DDA
      //stepping further below works. So the values can be computed as below.
      // Division through zero is prevented, even though technically that's not
      // needed in C++ with IEEE 754 floating point values.

      //deltaDistX e deltaDistY sono la distanza che il raggio deve percorrere per andare da 1 lato x al lato x successivo, o da 1 lato y al lato y successivo. VEDERE IMG SU 42DOCS PER AVERE PIU CHIARO IL CONCETTO.
      double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);
      
      //la variabile perpWallDist è la distanza non euclidea del punto del piano della telecamera da cui parte la linea perpendicolare verso l'oggetto che interseca. La utilizzeremo per calcolare la lunghezza del raggio.
      double perpWallDist;

      //variabili che indicano in che direzione rispetto ai blocchi deve andare il raggio. Saranno sempre -1 o 1
      int stepX;
      int stepY;

      //flag che indica se il raggio ha colpito qualcosa, quindi se il ciclo può essere terminato o no
      int hit = 0; //was there a wall hit?
      //side flagga se è stato colpito un lato x o un lato y. Se è stato colpito un lato x side=0, se è stato colpito un lato y side=1
      int side; //was a NS or a EW wall hit?
      
      //calcolo stepx, stepy iniziali e il primo sideDistx e sideDisty.
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
      //ciclo finche il raggio non colpisce qualcosa. NB in questo codice non ci interessa sapere dove è stato colpito il muro perchè è un progetto senza texture
      while(hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        //se la distanza corrente di x è minore della distanza corrente di y allora la distanza corrente di x sarà la stessa sommata alla successiva. la nuova coordinata x del raggio sarà la precedente + o - 1 e side = 0 (side è il flag che indica in che direzione si sta andando, in questo caso 0, quindi ci si muove sulle x) 
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


      //Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
      //hit to the camera plane. Euclidean to center camera point would give fisheye effect!
      //This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
      //for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
      //because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
      //steps, but we subtract deltaDist once because one step more into the wall was taken above.
      
      //questa formula serve a trovare la distanza dal piano della telecamera al muro. Da specificare che di solito non si utilizza la distanza Euclidea dal punto di vista del giocatore altrimenti si avrebbe l'effetto fisheye che non vogliamo. Si deve calcolare la distanza dal piano della telecamera in linea retta con l'oggetto. (VEDERE IMG 42 DOCS PER AVERE LE IDEE PIU CHIARE.)
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

      //Calculate height of line to draw on screen
      //lineHeght sarebbe l'altezza in pixel dell'oggetto che il casting ray ha colpito.
      int lineHeight = (int)(h / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      //drawStart e drawEnd sono di fatto gli indici dei pixel di inizio e fine della colonna che devono essere disegnati. Se ad esempio l'altezza del muro (linehieght) che dobbiamo disegnare è di 10px drawstart e drawend saranno anchessi separati da 10 px. Ad esempio potranno essere drawstart 32 e drawend 42.
      int drawStart = -lineHeight / 2 + h / 2;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + h / 2;
      if(drawEnd >= h) drawEnd = h - 1;

      // a seconda del valore che il raggio ha colpito viene settato un colore e con la funzione verLine viene tracciata una linea verticale, ovvero la colonna di pixel.
      //choose wall color
      ColorRGB color;
      switch(worldMap[mapX][mapY])
      {
        case 1:  color = RGB_Red;    break; //red
        case 2:  color = RGB_Green;  break; //green
        case 3:  color = RGB_Blue;   break; //blue
        case 4:  color = RGB_White;  break; //white
        default: color = RGB_Yellow; break; //yellow
      }

      //give x and y sides different brightness
      if(side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
      verLine(x, drawStart, drawEnd, color);
    }

    //calcolo il tempo del fotogramma corrente e di quello precedente. getTicks ritorna il numero di millisecondi da quando il sistema è stato avviato. Frame time è un valore che viene utilizzato per modificare la velocità di movimento del player ed è l'inverso degli FPS(se frametime è 0.3 allora il numero di FPS è 30, ovvero il gioco è in grado di vedere 30 fotogrammi al secondo). I fotogrammi al secondo (FPS) indica di fatto la frequenza con cui un videogioco o un' altra forma di media video viene aggiornato. Piu sono alti gli FPS più il gioco è fluido e realistico.
    //timing for input and FPS counter
    oldTime = time;
    time = getTicks();
    double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    print(1.0 / frameTime); //FPS counter
    redraw();
    cls();

    // è importante impostare la velocità di movimento e di rotazione con un parametro fisso perchè altrimenti dipenderebbe dalla velocità del processore e dai processi aperti.
    //speed modifiers
    double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    double rotSpeed = frameTime * 3.0; //the constant value is in radians/second

    //readkeys è una funzione che legge i keycode. Questo blocco di codice si occupa del movimento del personaggio. In pratica si muove solo è uguale a false, quindi se incontra uno 0
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
    //formule per ruotare a destra e sinistra
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
  }
}
