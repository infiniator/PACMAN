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
int inIndex;
int outIndex;
int maxX;
int maxY;
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
	maxX=getmaxx();
	maxY=getmaxy();
	drawMap();
	drawPacman();
	//drawFood();
	getch();
	closegraph();
	return 0;
}

void drawPacman()
{
	int ghostLegs[20];
	ghostLegs[0]=maxX/2-16;
	ghostLegs[1]=maxY/2+8;
	ghostLegs[2]=maxX/2-16;
	ghostLegs[3]=maxY/2+16;
	ghostLegs[4]=maxX/2-11;
	ghostLegs[5]=maxY/2+8;
	ghostLegs[6]=maxX/2-6;
	ghostLegs[7]=maxY/2+16;
	ghostLegs[8]=maxX/2;
	ghostLegs[9]=maxY/2+8;
	ghostLegs[10]=maxX/2+6;
	ghostLegs[11]=maxY/2+16;
	ghostLegs[12]=maxX/2+10;
	ghostLegs[13]=maxY/2+8;
	ghostLegs[14]=maxX/2+16;
	ghostLegs[15]=maxY/2+16;
	ghostLegs[16]=maxX/2+16;
	ghostLegs[17]=maxY/2+8;
	ghostLegs[18]=maxX/2-16;
	ghostLegs[19]=maxY/2+8;
	//below 5 lines draw pacman
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	sector(maxX/8,maxY/2,30,330,16,12);
	setfillstyle(SOLID_FILL,WHITE);
	setcolor(WHITE);
	//below lines draw the ghost
	sector(maxX/2,maxY/2,0,180,16,8);
	bar(maxX/2-16,maxY/2,maxX/2+16,maxY/2+8);
	fillpoly(10,ghostLegs);
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	fillellipse(maxX/2-6,maxY/2,4,4);
	fillellipse(maxX/2+6,maxY/2,4,4);
}
void drawMap()
{
}