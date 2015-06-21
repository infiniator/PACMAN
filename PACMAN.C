#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
void movePacman();//tracks the movement of the pacman
void drawPacman();//draws the pacman on the screen
void drawMap();//draws the map on the screen
void gameOver();//stops the game and displays the screen
void drawFood();//draws the food on the screen
void enemyMovement();//tracks the enemy AI movement on the screen
void drawEnemy();//draws the enemy AI on the screen
void scoreCalc();//tracks the score
void keyListener();//listens for any key inputs
int pacman[9][9]={{0,0,1,1,1,1,1,0,0},
		  {0,1,1,1,1,1,1,1,0},
		  {1,1,1,1,1,1,1,0,0},
		  {1,1,1,1,1,1,0,0,0},
		  {1,1,1,1,1,0,0,0,0},
		  {1,1,1,1,1,1,0,0,0},
		  {1,1,1,1,1,1,1,0,0},
		  {0,1,1,1,1,1,1,1,0},
		  {0,0,1,1,1,1,1,0,0}};  //pacman bitmap  array
int inIndex;
int outIndex;

int main()
{
	int gdriver = DETECT, gmode, errorcode; //640 * 480 screen
	initgraph(&gdriver, &gmode, "");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);
	}

	drawMap();
	drawPacman();
	drawFood();
	getch();
	closegraph();
	return 0;
}

void drawPacman()
{
	for(outIndex=0;outIndex<9;outIndex++)
		for(inIndex=0;inIndex<9;inIndex++)
			if(pacman[inIndex][outIndex]==1)
				putpixel(getmaxx()/8+outIndex,getmaxy()/2+inIndex,YELLOW);
}

void drawMap()
{
	line(5,5,635,5);
	line(5,5,5,475);
	line(5,475,635,475);
	line(635,475,635,5);
}