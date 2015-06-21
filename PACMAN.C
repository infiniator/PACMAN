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
int enemy[9][9]={{0,0,0,1,1,1,0,0,0},
		 {0,0,1,1,1,1,1,0,0},
		 {0,1,1,2,1,2,1,1,0},
		 {0,1,1,1,1,1,1,1,0},
		 {0,1,1,1,1,1,1,1,0},
		 {1,1,1,1,1,1,1,1,1},
		 {1,1,0,1,1,1,0,1,1},
		 {1,1,0,1,1,1,0,1,1},
		 {1,0,0,0,1,0,0,0,1}};

int inIndex;
int outIndex;
int count;

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
	drawEnemy();
	getch();
	closegraph();
	return 0;
}

void drawPacman()
{
	for(outIndex=0;outIndex<9;outIndex++)	//pacman facing right
		for(inIndex=0;inIndex<9;inIndex++)
			if(pacman[outIndex][inIndex]==1)
				putpixel(getmaxx()/8+inIndex,getmaxy()/2+outIndex,YELLOW);

	for(outIndex=0;outIndex<9;outIndex++)	//pacman facing down
		for(inIndex=0;inIndex<9;inIndex++)
			if(pacman[outIndex][inIndex]==1)
				putpixel(getmaxx()/8+outIndex+50,getmaxy()/2+inIndex,YELLOW);

	for(outIndex=0;outIndex<9;outIndex++)	//pacman facing left
		for(inIndex=8,count=0;inIndex>=0;inIndex--,count++)
			if(pacman[outIndex][inIndex]==1)
				putpixel(getmaxx()/8+count+100,getmaxy()/2+outIndex,YELLOW);

	for(outIndex=8,count=0;outIndex>=0;outIndex--,count++)	//pacman facing up
		for(inIndex=0;inIndex<9;inIndex++)
			if(pacman[inIndex][outIndex]==1)
				putpixel(getmaxx()/8+inIndex+150,getmaxy()/2+count,YELLOW);
}

void drawMap()
{
	line(5,5,635,5);
	line(5,5,5,475);
	line(5,475,635,475);
	line(635,475,635,5);
}

void drawEnemy()
{
	for(outIndex=0;outIndex<9;outIndex++)	//red enemy
		for(inIndex=0;inIndex<9;inIndex++)
		{
			if(enemy[inIndex][outIndex]==1)
				putpixel(getmaxx()/8+outIndex,getmaxy()/2+inIndex-100,RED);
			if(enemy[inIndex][outIndex]==2)
				putpixel(getmaxx()/8+outIndex,getmaxy()/2+inIndex-100,WHITE);
		}
	for(outIndex=0;outIndex<9;outIndex++)	//green enemy
		for(inIndex=0;inIndex<9;inIndex++)
		{
			if(enemy[inIndex][outIndex]==1)
				putpixel(getmaxx()/8+outIndex+50,getmaxy()/2+inIndex-100,GREEN);
			if(enemy[inIndex][outIndex]==2)
				putpixel(getmaxx()/8+outIndex+50,getmaxy()/2+inIndex-100,WHITE);
		}

	for(outIndex=0;outIndex<9;outIndex++)	//blue enemy
		for(inIndex=0;inIndex<9;inIndex++)
		{
			if(enemy[inIndex][outIndex]==1)
				putpixel(getmaxx()/8+outIndex+100,getmaxy()/2+inIndex-100,BLUE);
			if(enemy[inIndex][outIndex]==2)
				putpixel(getmaxx()/8+outIndex+100,getmaxy()/2+inIndex-100,WHITE);
		}
	for(outIndex=0;outIndex<9;outIndex++)   //black enemy
		for(inIndex=0;inIndex<9;inIndex++)
		{
			if(enemy[inIndex][outIndex]==1)
				putpixel(getmaxx()/8+outIndex+150,getmaxy()/2+inIndex-100,BLACK);
			if(enemy[inIndex][outIndex]==2)
				putpixel(getmaxx()/8+outIndex+150,getmaxy()/2+inIndex-100,WHITE);
		}
}