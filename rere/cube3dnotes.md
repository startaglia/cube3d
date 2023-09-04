## Raycasting
Il raycasting è una tecnica per generare un'immagine bidimensionale o tridimensionale da una scena tridimensionale. Uno dei vantaggi principali del raycasting è la velocità. Rende possibile la creazione di un' immagine 3D in modo rapido ed efficiente, in più può consentire una simulazione accurata di ombre e riflessi.
Di contro il raycasting è incline all'aliasing e al rumore. Inoltre richiede una maggiore quantità di dati per produrre un'immagine accurata, il che la rende più impegnativa in termini di memoria rispetto ad altre tecniche.

## Come funziona
Lavoriamo di base su una mappa griglia quadrata composta da blocchi(quadrati) uguali tra di loro. Il meccanismo base dell'algoritmo di raycasting è un raggio che inizia dalla posizione iniziale del personaggio e punta nella direzione in cui sta guardando. Questo raggio parte da una certa lunghezza e viene testato continuamente per verificarne l'intesezione con gli oggetti presenti nella scena. Se viene trovata un'intersezione viene determinato il colore e l'altezza dell'oggetto colpito. Se non viene trovata nessuna intersezione si aggiunge un certo valore di lunghezza al raggio e, puntando alla direzione precedente, si controlla ancora se trova un intersezione.
Di fatto il raggio viene testato solo alla fine della sua lunghezza. E' importante quindi testare il raggio considerando lunghezze non troppo lunghe altrimenti si rischia che tra una lunghezza e l'altra un oggetto non venga individuato. Più volte si testa il raggio minore è la possibilità che non venga individuato un muro. Questo sistema però presenta ancora dei problemi; anche con una serie di test del raggio molto elevata può capitare che si individui un oggetto ma non nella posizione esatta in cui si trova. Supponiamo di controllare il raggio ogni centimetro, è possibile che uno di quei segmenti si intersechi con un' oggetto però toccando un altro suo lato(del quadrato-oggetto) e non il primo che incontra il raggio, quindi quello visibile all'occhio del personaggio. Inoltre stringere sempre di più la lunghezza del raggio è meno performante perchè richiede molti più calcoli, quindi più memoria.
Esistono diversi algoritmi di raycasting per risolvere questo problema. Noi prenderemo in considerazione il DDA "Digital Differential Analyzer".

## DDA "Digital Differential Analyzer"
L'idea di base del DDA è quella di testare il raggio calcolando gli incrementi, quindi non testare il raggio ad incrementi uguali tra di loro. Avendo una griglia quadrata composta da quadrati è conveniente che un incremento equivalga ad ogni lato di un quadrato che incontrerà il raggio. Una volta che troviamo il punto preciso in cui viene colpito il primo quadrato che la visuale del personaggio incontra possiamo fermare l'algoritmo.

## Casting ray "raggio di lancio" e direzione
Il casting ray è il raggio che parte dalla posizione del giocatore. Per rappresentare la direzione del giocatore bisogna considerare la posizione del giocatore. La posizione è sempre un vettore, quindi avrà sempre una coordinata X e una coordinata Y. Se consideriamo anche la direzione del giocatore come un vettore avremo che ogni punto della linea di direzione è la somma della posizione del giocatore e un multiplo della direzione vettore. Nel pratico se moltiplichiamo X e Y del vettore direzione per lo stesso valore cambia la lunghezza ma mantiene la stessa direzione. Per ora non ci preoccupiamo della lunghezza del vettore direzione.

## Camera plane vector"vettore del piano della telecamera"
Per definire effettivamente dove il giocatore sta guardando però abbiamo bisogno di un' altro vettore, il camera plane vector. Nel nostro progetto lavoriamo in un' ambientazione 2D, quindi il vettore della camera di fatto è una linea che sarà sempre perpendicolare al vettore di direzione. Il piano della telecamera rappresenta la superficie dello schermo del computer, mentre il vettore di direzione è perpendicolare ad esso e punta all'interno dello schermo. La posizione del giocatore è quindi un punto davanti al vettore della camera e sarà collegata con un raggio, il casting ray.

## FOV-field of vision "campo visivo" e ray dir
Per ray dir si intende la direzione di un casting ray. Per creare l'effetto di un campo visivo realistico dobbiamo considerare che partano piu raggi (raggi di campionamento o raggi secondari) dal personaggio. La direzione dei raggi di campionamento è data dalla somma del casting ray e una parte del camera plane vector. IL FOV (campo visivo) è quindi determinato dai raggi di campionamento agli estremi.
Se il casting ray e il camera vector hanno la stessa lunghezza il FOV sarà di 90°.
Se il casting ray è più lungo del camera vector il FOV sarà molto piu piccolo di 90° e si avrà una visuale molto ristretta, si vedrà tutto in modo più dettagliato e la profondità sarà minore, come si facesse uno zoom.
Se il casting ray è più corto del camera vector il FOV sarà molto piu grande di 90° (180° è il massimo) e si avrà una visuale molto più ampia, come se si facesse un zoom out. Quando il giocatore ruota il vector camera deve ruotare con lui e con esso anche il casting ray e i raggi di campionamento.

# Analisi di un codice c++ raycasting senza texture (raycaster_flat.cpp)
Leggere il codice raycaster_flat.cpp
(CHIEDERE DOVE SI TROVA IL CAMERA PLANE. SE È UN VETTORE CHE SI TROVA DI FRONTA IL PLAYER O SE È IL PLAYER CHE SI TROVA SUL CAMERA PLANE. PERCHÈ IN 42 DOCS NELLE IMG SONO RAPPRESENTATI TUTTI E DUE)
(CAPIRE SE QUANDO SI DISEGNA UNA LINEA VERTICALE LA DISEGNA PIXEL PER PIXEL O A DIMENSIONI FISSE AD ESEMPIO 64 PX O 32 PX)

# Analisi di un codice c++ raycasting con texture (raycaster_flat.cpp)
Leggere il codice raycaster_flat.cpp.




  double time = 0; //time of current frame
  double oldTime = 0; //time of previous frame










+-------------------------------+
|           Fotocamera          |
|                               |
|         []                    |
|                               |
|              *                |
|                               |
|                               |
|                               |
+-------------------------------+
|             Raggio            |
|             di                |
|            lancio             |
|              |                |
|              |                |
|              |                |
|-------------------------------|
|           Oggetti             |
|           nella               |
|           scena               |
|                               |
|                               |
+-------------------------------+

+-------------------------------+
|    [][        Muro        ][]  |
|    [][                    ][]  |
|    [][         *          ][]  |
|    [][                    ][]  |
|    [][                    ][]  |
|    [][                    ][]  |
|    [][                    ][]  |
+--------------------------------+

+------------Muro---------------+
|    /                          |
|   /                           |
|  *                            |
| /                             |
|/                              |
|              \                |
|               \               |
+-------------------------------+



