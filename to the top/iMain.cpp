 
#include "iGraphics.h"

int upjump, jump_height;    //upjump;
int downjump;   //downjump;
int menu = 0;
int obx0 = 0, oby0 = 0, obx1 = 70, oby1 = 100, obx2 = 85, oby2 = 200, i = 0, dir1 = 1, dir2 = 1, dir3 = 1, dir4 = 1;
int oby3 = 300, oby4 = 400, oby5 = 500, obx3 = 300, obx4 = 60, obx5 = 0;
int obx6 = 0, obx7 = 250, obx8 = 450, obx9 = 10, obx10 = 0, obx11 = 480, oby6 = 0, oby7 = 100, oby8 = 200, oby9 = 300, oby10 = 400, oby11 = 500;
int dir6 = 1, dir7 = 1, dir9 = 1, dir10 = 1;
int obx12 = 400, oby12 = 0, obx13 = 150, oby13 = 100, obx14 = 400, oby14 = 200, obx15 = 300, oby15 = 300, obx16 = 0, oby16 = 400, obx17 = 400, oby17 = 400, obx18 = 250, oby18 = 500;
int dir13 = 1, dir15 = 1, dir18 = 1;
int dx = 200, dy = 20;
int coindx = 32, coindy = 32, coin1x = 0, coin1y = 600, coin2x = 300, coin2y = 600;
int bombdx = 32, bombdy = 32, bomb1x = 50, bomb1y = 800, bomb2x = 300, bomb2y = 600, bomb3x = 400, bomb3y = 800, bomb4x = 550, bomb4y = 800;
int right, left;
int smurf_x = 100, smurf_y = 20, smurf_dx = 50, smurf_dy = 50;
int bg_x = 0, bg_y = 0;

char scoreArr[1000];
char lifeChar[10];
int timer1, timer2, timer3;

int stage = 1, life = 3, score = 0;
//rocket
int rktx = 136, rkty = 0, rdx = 64, rdy = 128;
int minedx = 32, minedy = 32, mine1x, mine1y = 600, mine2x, mine2y = 600, mine3x, mine3y = 600, mine4x, mine4y = 601;
int rflag = 0, lflag = 0, uflag = 0, dflag = 0;
int meteordx = 64, meteordy = 64, meteorx, meteory = 600, meteory1, meteorx1 = 0;
int fueldx = 32, fueldy = 32, fuel1x = 0, fuel1y = 600, fuel2x = 300, fuel2y = 600;
int enemydx = 64, enemydy = 32, enemyx = 600, enemyy;

void iDraw()
{
	iClear();
	if (stage<5)
	{
		iShowBMP(0, 0, "stage1_bg.bmp");
		iSetColor(20, 44, 78);
		iFilledRectangle(smurf_x, smurf_y, smurf_dx, smurf_dy);
		//iShowBMP2(smurf_x, smurf_y,"character_right_walk.bmp",255*256*256+255*256+255);
		iSetColor(2, 255, 255);
		if (stage == 1)
		{
			iShowBMP(obx0, oby0, "wall.bmp");
			iShowBMP(obx1, oby1, "wall.bmp");
			iShowBMP(obx2, oby2, "wall.bmp");
			iShowBMP(obx3, oby3, "wall.bmp");
			iShowBMP(obx4, oby4, "wall.bmp");
			iShowBMP(obx5, oby5, "wall.bmp");
		}
		if (stage == 2)
		{
			iShowBMP(obx6, oby6, "wall.bmp");
			iShowBMP(obx7, oby7, "wall.bmp");
			iShowBMP(obx8, oby8, "wall.bmp");
			iShowBMP(obx9, oby9, "wall.bmp");
			iShowBMP(obx10, oby10, "wall.bmp");
			iShowBMP(obx11, oby11, "wall.bmp");
		}
		if (stage == 3)
		{
			iShowBMP(obx12, oby12, "wall.bmp");
			iShowBMP(obx13, oby13, "wall.bmp");
			iShowBMP(obx14, oby14, "wall.bmp");
			iShowBMP(obx15, oby15, "wall.bmp");
			iShowBMP(obx16, oby16, "wall.bmp");
			iShowBMP(obx17, oby17, "wall.bmp");
			iShowBMP(obx18, oby18, "wall.bmp");
		}
		if (stage == 4)
		{
			//iFilledRectangle(50, 0, 500, 20);
			//iFilledRectangle(60, 20, 64, 128);
			iShowBMP(rktx, rkty, "rocketstraight.bmp");
		}
		iShowBMP(coin1x, coin1y, "coin.bmp");
		iShowBMP(coin2x, coin2y, "coin.bmp");
		iShowBMP(bomb1x, bomb1y, "bombbag.bmp");
		iShowBMP(bomb3x, bomb3y, "bombbag.bmp");

	}


	if (stage == 5)//rocket
	{
		iShowBMP(0, 0, "space_bg.bmp");
		iSetColor(122, 121, 200);
		iFilledRectangle(enemyx, enemyy, enemydx, enemydy);
		//iFilledRectangle(rktx, rkty, 64, 128); //rocket
		iShowBMP(rktx, rkty, "rocketstraight.bmp");
		iSetColor(12, 255, 23);
		iFilledRectangle(mine1x, mine1y, minedx, minedy);
		iShowBMP(meteorx, meteory, "meteor.bmp");
		iFilledRectangle(mine3x, mine3y, minedx, minedy);
		iSetColor(255, 255, 0);
		iFilledRectangle(fuel1x, fuel1y, fueldx, fueldy);
		iFilledRectangle(fuel2x, fuel2y, fueldx, fueldy);
		//iShowBMP(1, 1, "space background2.bmp");
		//iShowBMP(rktx, rkty, "rocketstraight");
	}

	iSetColor(255, 255, 255);
	iText(600, 550, "SCORE :", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(600, 500, scoreArr, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(600, 430, "LIFE", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(600, 380, lifeChar, GLUT_BITMAP_TIMES_ROMAN_24);
	if (life == 0)
	{
		//exit(0);
	}
	//printf("%d",score);

}
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{





	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

void iPassiveMouseMove(int mx, int my)
{
	//place your code here

	if (mx == 2){}        /*Something to do with mx*/
	else if (my == 2){}   /*Something to do with my*/

}


void iKeyboard(unsigned char key)
{
	if (key == '1')
	{
		menu = 1;
	}

	if (key == '2')
	{
		menu = 2;
	}
	if (key == '3')
	{
		menu = 3;
	}

	//place your codes for other keys here
}


void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	//up key diya right jump koraisi
	if (key == GLUT_KEY_UP)
	{
		if (stage<5)
		{
			if (upjump == 0 && downjump == 0 && smurf_x < 560)
			{
				upjump = 1;
				downjump = 0;
				jump_height = smurf_y;
			}
		}


		uflag = 1;

	}

	if (key == GLUT_KEY_RIGHT)
	{
		if (stage<5)
		{
			if (downjump == 0 && right == 0 && left == 0 && smurf_x <535)
			{
				right = 1;
			}
		}


		lflag = 0;
		rflag = 1;

	}
	if (key == GLUT_KEY_LEFT)
	{
		if (stage<5)
		{
			if (downjump == 0 && right == 0 && left == 0 && smurf_x > 23)
			{
				left = 1;
			}
		}
		else
		{
			rflag = 0;
			lflag = 1;
		}
	}
	if (key == GLUT_KEY_DOWN)
	{
		dflag = 1;
	}
}

void move()
{
	int check_left, check_right;
	if (right == 1)
	{
		check_right = smurf_x;
		smurf_x = smurf_x + 35;

		if (check_right + 35 == smurf_x)
		{
			right = 0;
		}
	}

	if (left == 1)
	{
		check_left = smurf_x;
		smurf_x = smurf_x - 35;

		if (check_left - 35 == smurf_x)
		{
			left = 0;
		}
	}

}

void jump()
{
	if (upjump == 1)
	{
		smurf_y = smurf_y + 10;
		if (smurf_y == jump_height + 130)
		{
			upjump = 0;
			downjump = 1;
		}
	}
	if (downjump == 1)
	{
		smurf_y = smurf_y - 5;
		if (smurf_y == 0)
		{
			downjump = 0;
		}
	}
	if (smurf_y > 580)
	{
		smurf_y = 20;
		//smurf_x = 20;
		upjump = 0;
		stage++;
	}


}


//background

void background()
{
	if (bg_y <= 100)
	{
		bg_y = bg_y + 5;
		if (bg_y == 100)
		{
			bg_y = 0;
		}
	}
}

void obstacle0()
{

	if (smurf_x + smurf_dx >= obx0 + 1 && smurf_x + 1 <= obx0 + dx && oby0 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby0 + dy;
	}
	if (smurf_x + smurf_dx >= obx0 + 1 && smurf_x + 1 <= obx0 + dx && oby0 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx0 || smurf_x >= obx0 + dx) && (oby0 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}

}


void obstacle1()
{
	if (obx1 == 300)
		dir1 = -1;

	if (obx1 == 150)
		dir1 = 1;


	obx1 = obx1 + dir1;

	//for changing y
	if (smurf_x + smurf_dx >= obx1 + 1 && smurf_x + 1 <= obx1 + dx && oby1 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby1 + dy;
	}
	if (smurf_x + smurf_dx >= obx1 + 1 && smurf_x + 1 <= obx1 + dx && oby1 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx1 || smurf_x >= obx1 + dx) && (oby1 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}

}

void obstacle2()
{
	if (obx2 == 180)
		dir2 = 1;

	if (obx2 == 50)
		dir2 = -1;


	obx2 = obx2 - dir2;

	if (smurf_x + smurf_dx >= obx2  && smurf_x + 1 <= obx2 + dx && oby2 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby2 + dy;
	}
	if (smurf_x + smurf_dx >= obx2 + 1 && smurf_x + 1 <= obx2 + dx && oby2 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx2 || smurf_x >= obx2 + dx) && (oby2 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}

}

void obstacle3()
{
	if (obx3 == 400)
		dir3 = -1;

	if (obx3 == 150)
		dir3 = 1;


	obx3 = obx3 + dir3;

	if (smurf_x + smurf_dx >= obx3 + 1 && smurf_x + 1 <= obx3 + dx && oby3 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby3 + dy;
	}
	if (smurf_x + smurf_dx >= obx3 + 1 && smurf_x + 1 <= obx3 + dx && oby3 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx3 || smurf_x >= obx3 + dx) && (oby3 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}

}

void obstacle4()
{
	if (obx4 == 400)
		dir4 = 1;

	if (obx4 == 10)
		dir4 = -1;


	obx4 = obx4 - dir4;

	if (smurf_x + smurf_dx >= obx4 + 1 && smurf_x + 1 <= obx4 + dx && oby4 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby4 + dy;
	}
	if (smurf_x + smurf_dx >= obx4 + 1 && smurf_x + 1 <= obx4 + dx && oby4 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx4 || smurf_x >= obx4 + dx) && (oby4 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}

}

void obstacle5()
{

	if (smurf_x + smurf_dx >= obx5 + 1 && smurf_x + 1 <= obx5 + dx && oby5 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby5 + dy;
	}
	if (smurf_x + smurf_dx >= obx5 + 1 && smurf_x + 1 <= obx5 + dx && oby5 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx5 || smurf_x >= obx5 + dx) && (oby5 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}

}

void obstacle6()
{

	if (obx6 == 250)
		dir6 = -1;

	if (obx6 == 0)
		dir6 = 1;


	obx6 = obx6 + dir6;

	if (smurf_x + smurf_dx >= obx6 + 1 && smurf_x + 1 <= obx6 + dx && oby6 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby6 + dy;
	}
	if (smurf_x + smurf_dx >= obx6 + 1 && smurf_x + 1 <= obx6 + dx && oby6 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx6 || smurf_x >= obx6 + dx) && (oby6 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}

}
void obstacle7()
{
	if (obx7 == 400)
		dir7 = -1;

	if (obx7 == 250)
		dir7 = 1;


	obx7 = obx7 + dir7;


	if (smurf_x + smurf_dx >= obx7 + 1 && smurf_x + 1 <= obx7 + dx && oby7 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby7 + dy;
	}
	if (smurf_x + smurf_dx >= obx7 + 1 && smurf_x + 1 <= obx7 + dx && oby7 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx7 || smurf_x >= obx7 + dx) && (oby7 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}

}
void obstacle8()
{

	if (smurf_x + smurf_dx >= obx8 + 1 && smurf_x + 1 <= obx8 + dx && oby8 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby8 + dy;
	}
	if (smurf_x + smurf_dx >= obx8 + 1 && smurf_x + 1 <= obx8 + dx && oby8 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx8 || smurf_x >= obx8 + dx) && (oby8 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}

}
void obstacle9()
{
	if (obx9 == 500)
		dir9 = -1;

	if (obx9 == 0)
		dir9 = 1;


	obx9 = obx9 + dir9;

	if (smurf_x + smurf_dx >= obx9 + 1 && smurf_x + 1 <= obx9 + dx && oby9 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby9 + dy;
	}
	if (smurf_x + smurf_dx >= obx9 + 1 && smurf_x + 1 <= obx9 + dx && oby9 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx9 || smurf_x >= obx9 + dx) && (oby9 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}

}
void obstacle10()
{
	if (obx10 == 550)
		obx10 = 0;

	obx10++;

	if (smurf_x + smurf_dx >= obx10 + 1 && smurf_x + 1 <= obx10 + dx && oby10 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby10 + dy;
	}
	if (smurf_x + smurf_dx >= obx10 + 1 && smurf_x + 1 <= obx10 + dx && oby10 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx10 || smurf_x >= obx10 + dx) && (oby10 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}

}

void obstacle11()
{

	if (smurf_x + smurf_dx >= obx11 + 1 && smurf_x + 1 <= obx11 + dx && oby11 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby11 + dy;
	}
	if (smurf_x + smurf_dx >= obx11 + 1 && smurf_x + 1 <= obx11 + dx && oby11 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx11 || smurf_x >= obx11 + dx) && (oby11 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}

}
void obstacle12()
{

	if (smurf_x + smurf_dx >= obx12 + 1 && smurf_x + 1 <= obx12 + dx && oby12 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby12 + dy;
	}
	if (smurf_x + smurf_dx >= obx12 + 1 && smurf_x + 1 <= obx12 + dx && oby12 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx12 || smurf_x >= obx12 + dx) && (oby12 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}

}
void obstacle13()
{
	if (obx13 == 320)
		dir13 = -1;

	if (obx13 == 150)
		dir13 = 1;


	obx13 = obx13 + dir13;

	if (smurf_x + smurf_dx >= obx13 + 1 && smurf_x + 1 <= obx13 + dx && oby13 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby13 + dy;
	}
	if (smurf_x + smurf_dx >= obx13 + 1 && smurf_x + 1 <= obx13 + dx && oby13 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx13 || smurf_x >= obx13 + dx) && (oby13 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}

}void obstacle14()
{

	if (smurf_x + smurf_dx >= obx14 + 1 && smurf_x + 1 <= obx14 + dx && oby14 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby14 + dy;
	}
	if (smurf_x + smurf_dx >= obx14 + 1 && smurf_x + 1 <= obx14 + dx && oby14 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx14 || smurf_x >= obx14 + dx) && (oby14 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}
}
void obstacle15()
{
	if (obx15 == 350)
		dir15 = -1;

	if (obx15 == 150)
		dir15 = 1;


	obx15 = obx15 + dir15;

	if (smurf_x + smurf_dx >= obx15 + 1 && smurf_x + 1 <= obx15 + dx && oby15 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby15 + dy;
	}
	if (smurf_x + smurf_dx >= obx15 + 1 && smurf_x + 1 <= obx15 + dx && oby15 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx15 || smurf_x >= obx15 + dx) && (oby15 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}


}
void obstacle16()
{

	if (smurf_x + smurf_dx >= obx16 + 1 && smurf_x + 1 <= obx16 + dx && oby16 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby16 + dy;
	}
	if (smurf_x + smurf_dx >= obx16 + 1 && smurf_x + 1 <= obx16 + dx && oby16 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx16 || smurf_x >= obx16 + dx) && (oby16 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}


}
void obstacle17()
{

	if (smurf_x + smurf_dx >= obx17 + 1 && smurf_x + 1 <= obx17 + dx && oby17 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby17 + dy;
	}
	if (smurf_x + smurf_dx >= obx17 + 1 && smurf_x + 1 <= obx17 + dx && oby17 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx17 || smurf_x >= obx17 + dx) && (oby17 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}


}
void obstacle18()
{
	if (obx18 == 400)
		dir18 = -1;

	if (obx18 == 0)
		dir18 = 1;


	obx18 = obx18 + dir18;

	if (smurf_x + smurf_dx >= obx18 + 1 && smurf_x + 1 <= obx18 + dx && oby18 + dy == smurf_y)//stand
	{
		downjump = 0;
		smurf_y = oby18 + dy;
	}
	if (smurf_x + smurf_dx >= obx18 + 1 && smurf_x + 1 <= obx18 + dx && oby18 == smurf_y + smurf_dy)
	{
		upjump = 0;
		downjump = 1;
	}
	if ((smurf_x + smurf_dx <= obx18 || smurf_x >= obx18 + dx) && (oby18 + dy == smurf_y) && upjump == 0)
	{
		downjump = 1;
	}


}
//coin
void coin(){

	if (coin1y == 0)
	{
		coin1y = 600;
		coin1x = rand() % 500 + 50;
	}
	if (coin1x + coindx >= smurf_x + 1 && coin1x + 1 <= smurf_x + smurf_dx && coin1y <= smurf_y + smurf_dy)
	{
		score++;
		coin1y = 600;
		coin1x = rand() % 500 + 50;
	}


	coin1y--;

	if (coin2y == 0)
	{
		coin2y = 600;
		coin2x = rand() % 500 + 50;//meteorx chilo
	}
	if (coin2x + coindx >= smurf_x + 1 && coin2x + 1 <= smurf_x + smurf_dx && coin2y <= smurf_y + smurf_dy)
	{
		score++;
		coin2y = 600;
		coin2x = rand() % 500 + 50;
	}


	coin2y--;



}
//bomb
void bomb()
{



	if (bomb1y == 0)
	{
		bomb1y = 600;
		bomb1x = rand() % 550 + 32;
	}
	if (bomb1x + bombdx >= smurf_x + 1 && bomb1x + 1 <= smurf_x + smurf_dx && bomb1y <= smurf_y + smurf_dy)
	{
		life--;
		bomb1y = 600;
		bomb1x = rand() % 550 + 32;
	}

	bomb1y = bomb1y - 2;



	if (bomb2y == 0)
	{
		bomb2y = 600;
		bomb2x = rand() % 550 + 40;
	}
	if (bomb2x + bombdx >= smurf_x + 1 && bomb2x + 1 <= smurf_x + smurf_dx && bomb2y <= smurf_y + smurf_dy)
	{
		life--;
		bomb2y = 600;
		bomb2x = rand() % 550 + 40;
	}

	bomb2y--;




}
void bomb2()
{



	if (bomb3y == 0)
	{
		bomb3y = 600;
		bomb3x = rand() % 550 + 32;
	}
	if (bomb3x + bombdx >= smurf_x + 1 && bomb3x + 1 <= smurf_x + smurf_dx && bomb3y <= smurf_y + smurf_dy)
	{
		life--;
		bomb3y = 600;
		bomb3x = rand() % 550 + 32;
	}

	bomb3y = bomb3y - 2;



	if (bomb4y == 0)
	{
		bomb4y = 600;
		bomb4x = rand() % 550 + 40;
	}
	if (bomb4x + bombdx >= smurf_x + 1 && bomb4x + 1 <= smurf_x + smurf_dx && bomb4y <= smurf_y + smurf_dy)
	{
		life--;
		bomb4y = 600;
		bomb4x = rand() % 550 + 40;
	}

	bomb4y--;




}
void stage4()
{
	if (smurf_x <= 200 && stage == 4)
		stage = 5;


	//printf("%d", stage);
}

//rocket
void mines()
{



	if (mine1y == 0)
	{
		mine1y = 600;
		mine1x = rand() % 550 + 32;
	}
	if (mine1x + minedx >= rktx + 1 && mine1x + 1 <= rktx + rdx && mine1y <= rkty + rdy)
	{
		life--;
		mine1y = 600;
		mine1x = rand() % 550 + 32;
	}

	mine1y = mine1y - 2;



	if (mine2y == 0)
	{
		mine2y = 600;
		mine2x = rand() % 550 + 40;
	}
	if (mine2x + minedx >= rktx + 1 && mine2x + 1 <= rktx + rdx && mine2y <= rkty + rdy)
	{
		life--;
		mine2y = 600;
		mine2x = rand() % 550 + 40;
	}

	mine2y--;




}
void mines2()
{



	if (mine3y == 0)
	{
		mine3y = 600;
		mine3x = rand() % 550 + 32;
	}
	if (mine3x + minedx >= rktx + 1 && mine3x + 1 <= rktx + rdx && mine3y <= rkty + rdy)
	{
		life--;
		mine3y = 600;
		mine3x = rand() % 550 + 32;
	}

	mine3y = mine3y - 2;



	if (mine4y == 0)
	{
		mine4y = 600;
		mine4x = rand() % 550 + 40;
	}
	if (mine4x + minedx >= rktx + 1 && mine4x + 1 <= rktx + rdx && mine4y <= rkty + rdy)
	{
		life--;
		mine4y = 600;
		mine4x = rand() % 550 + 40;
	}

	mine4y--;




}


void meteor()
{
	int meteorx2, meteory2, meteorx3, meteory3;
	int m = 0, n = 0;
	if (meteory == 0)
	{
		meteory = 600;
		meteorx = rand() % 600 + 32;
	}
	if (meteorx + meteordx >= rktx + 1 && meteorx + 1 <= rktx + rdx && meteory <= rkty + rdy)//eta thik
	{
		life--;
		meteory = 600;
		meteorx = rand() % 600 + 32;
	}


	meteory = meteory - 5;



	if (meteory == 0)
	{
		meteory = 600;
		meteorx = rand() % 500 + 64;
	}
	if (meteorx + 64 >= rktx && meteorx <= rktx - 1 && meteory <= rkty + rdy) // collison
	{
		life--;
		meteory = 600;
		meteorx = rand() % 500 + 64;
	}


	meteory = meteory - 5;





	if (meteory1 == 0 && meteorx1 == 0)
	{
		meteory1 = 600;
		meteorx1 = rand() % 600 + 50;
	}
	if (meteorx1 + 64 >= rktx && meteorx1 <= rktx - 1 && meteory1 <= rkty + rdy) // collison
	{
		life--;
		meteory1 = 600;
		meteorx1 = rand() % 600 + 50;
	}

	if (m == 0 && n == 0){
		meteory1 = meteory1 - 100;
		m = 1;
	}

	if (m == 1 && n == 0){
		meteorx1 = meteorx1 - 100;
		n = 1;
	}

	if (m == 0 && n == 1){
		meteory1 = meteory1 - 100;
		n = 1;
		m = 1;
	}

	if (m == 1 && n == 1){
		meteorx1 = meteorx1 + 200;
		n = 0;
		m = 0;
	}
}



void enemy()
{

	if (enemyx == 600)
	{
		enemyx = 0;
		enemyy = rand() % 500 + 20;
	}
	if (enemyx + enemydx >= rktx + 1 && enemyx + 1 <= rktx + rdx && enemyy <= rkty + rdy)
	{
		life--;
		enemyx = 0;
		enemyy = rand() % 500 + 20;
	}


	enemyx++;

}





void fly()
{
	if (rflag == 1 && rktx>600)
	{
		rktx = 0;


	}
	if (lflag == 1 && rktx<0)
	{
		rktx = 600;

	}
	if (rflag == 1)
	{

		lflag = 0;
		rktx++;

	}
	if (lflag == 1)
	{

		rflag = 0;
		rktx--;

	}
	if (uflag == 1 && rkty>472)
	{
		rkty = rkty - 10;

	}
	if (dflag == 1 && rkty<0)
	{
		rkty = rkty + 10;


	}

	if (uflag == 1)
	{
		rkty = rkty + 10;
		uflag = 0;

	}

	if (dflag == 1)
	{
		rkty = rkty - 10;
		dflag = 0;

	}

}

void fuel(){

	if (fuel1y == 0)
	{
		fuel1y = 600;
		fuel1x = rand() % 500 + 50;//meteorx chilo
	}
	if (fuel1x + fueldx >= rktx + 1 && fuel1x + 1 <= rktx + rdx && fuel1y <= rkty + rdy)
	{
		score++;
		fuel1y = 600;
		fuel1x = rand() % 500 + 50;
	}


	fuel1y--;

	if (fuel2y == 0)
	{
		score++;
		fuel2y = 600;
		fuel2x = rand() % 500 + 50;//meteorx chilo
	}
	if (fuel2x + fueldx >= rktx + 1 && fuel2x + 1 <= rktx + rdx && fuel2y <= rkty + rdy)
	{
		score++;
		fuel2y = 600;
		fuel2x = rand() % 500 + 50;
	}


	fuel2y--;



}
/*
void life_stage()
{
if((stage<5)&&(smurf_y==0))
{
life--;
}



}
*/

void scoretoString(int score){
	int i;
	if (score == 0)
	{
		scoreArr[0] = '0';
	}
	else
	{
		for (i = 0; score; i++)
		{
			scoreArr[i] = score % 10 + '0';
			score = score / 10;

		}
		scoreArr[i] = '\0';
		strrev(scoreArr);
	}

}

void lifetoString(int life)
{
	int i;
	for (i = 0; life; i++)
	{
		lifeChar[i] = life % 10 + '0';
		life = life / 10;

	}
	lifeChar[i] = '\0';
}
//all timer related functions;
void all()
{
	if (stage<5)
	{
		background();
		if (stage == 1)
		{
			obstacle0();
			obstacle1();
			obstacle2();
			obstacle3();
			obstacle4();
			obstacle5();
		}
		if (stage == 2)
		{
			obstacle6();
			obstacle7();
			obstacle8();
			obstacle9();
			obstacle10();
			obstacle11();
		}
		if (stage == 3)
		{
			obstacle12();
			obstacle13();
			obstacle14();
			obstacle15();
			obstacle16();
			obstacle17();
			obstacle18();
		}
		jump();
		move();
		bomb();
		bomb2();
		coin();
	}
	if (stage == 4)
	{
		stage4();
	}
	//life_stage();
	scoretoString(score);
	lifetoString(life);
}

void rocket()
{
	if (stage >= 5)
	{

		fly();
		mines();
		mines2();
	}
}

void rocket2()
{
	if (stage >= 5)
	{
		meteor();
		fuel();
		enemy();
	}
}

int main()
{

	//place your own initialization codes here. 
	timer1 = iSetTimer(1, all);
	timer2 = iSetTimer(1, rocket);
	timer3 = iSetTimer(10, rocket2);
	iInitialize(800, 600, "demooo");
	return 0;
}