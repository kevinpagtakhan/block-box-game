/***********************************
*                                  *
*Program Title:  BlockBox          *
*ID number:      11040734          *
*Student's name: Kevin Pagtakhan   *
*Block:          S22               *
*                                  *
*Subject:        COMPRO1           *
*Prof:           Dr. Nelson Marcos *
*                                  *
*Date Started:   July 21, 2010     *
*Date Finished:  August 18, 2010   *
*                                  *
***********************************/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

void gotoxy(int x, int y);
void Color(int nColor);

int Random(int nMod, int nPlus);
int sRandom(int nMod, int nPlus);

void Border(int Delay);
void SmallBorder();
void BorderMulti();

void Title(int Delay);
void MainMenu(int LogoSleep);
void Menu();
int Choice();
int PlayerMode();
int PlayGame();
int Diff();

int HowtoPlay1();
int HowtoPlay2();

void Player(int xx, int yy, int nSize);
void ErasePlayer(int xx, int yy, int nSize);
void PrintEnemy1(int a, int b, int face);
void EraseEnemy1(int a, int b);
void PrintEnemy2(int a, int b, int face);
void EraseEnemy2(int a, int b);
void PrintEnemy3(int a, int b, int face);
void EraseEnemy3(int a, int b);
void PrintEnemy4(int a, int b, int face);
void EraseEnemy4(int a, int b);
void SinglePlayer(int x, int y, int  nDifficulty);

void Player1(int aa, int bb);
void Player2(int cc, int dd);
void abPrintEnemy(int x1, int y1);
void abEraseEnemy(int x1, int y1);
void MultiPlayer();

void GameOver();
void Result(float Score1, float Score2);

int Close(int Kevin_Close);

main()
{ int Kevin_Choice;
  int Kevin_Close;
  int nHowto;
  int x = 1;
  int LogoSleep;
  int nLoopCtr=1;
  int Mode=0, Mode2 = 0;
  int nDifficulty;
  
while(x != 5)
{
  system("cls");
  if (nLoopCtr < 2)
  LogoSleep = 75;
  else if (nLoopCtr > 1)
    LogoSleep = 0;
  MainMenu(LogoSleep);
  Kevin_Choice = Choice();
  if(Kevin_Choice == 1)
  { 
    Mode = PlayerMode();
    if (Mode == 1)
    {
    nDifficulty = PlayGame();    
    SinglePlayer(37,11,nDifficulty);
    GameOver();
    }
    else if (Mode == 2)
    {
    MultiPlayer();     
    }
  }  
  else if (Kevin_Choice == 2)     
  {  
    Mode2 = PlayerMode();
    if (Mode2 == 1)
    {
    HowtoPlay1();
    }
    else if (Mode2 == 2)
    {
    HowtoPlay2();     
    }
  }  
  else if (Kevin_Choice == 3)
  { x = Close(x);
  if (x == 1)
    x = 1;
  else if (x == 2)
    x = 5;
  }
  nLoopCtr++;
}
}

void gotoxy(int x, int y)
{
 COORD coord;
 
 coord.X = x;
 coord.Y = y;
 
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
 
 //Source:
 //http://www.cplusplus.com/forum/beginner/4234/
}

void Color(int nColor)
{
 HANDLE hStdout;
 hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(hStdout, nColor);
 
 //Source:
 //http://www.dreamincode.net/forums/topic/21022-change-font-color-in-c-program/
}

int Random(int nMod, int nPlus)
{
  return rand()%nMod+nPlus;
}
int sRandom(int nMod, int nPlus)
{

  srand((unsigned)time( NULL ) );

  return rand()%nMod+nPlus;
}

void Border(int Delay)
{ int lefty=1, righty=1;
  Color(8);
  int i;
  
  gotoxy(0,0);
  printf("%c", 201);
  for (i = 1; i <= 77; i++)
  { printf("%c", 205);
    sleep(Delay);
  }
  printf("%c\n", 187);
  
  while(righty<=21)
  {
  gotoxy(78,righty);
  printf("%c", 186);
  righty++;
  sleep(Delay);
  }
  
  gotoxy(0,1);
  while(lefty<=21)
  {
  printf("%c", 186);
  lefty++;
  gotoxy(0,lefty);
  sleep(Delay);
  }
  
  gotoxy(0,22);
  printf("%c", 200);
  for (i = 1; i <= 77; i++)
  {
    printf("%c", 205);
    sleep(Delay);
  }
  printf("%c\n", 188);
}

void SmallBorder()
{
 int i, j = 1, k = 1;
 
   Color(8);
  
  gotoxy(20,0);
  printf("%c", 201);
  for(i = 1; i <= 37; i++)
    printf("%c", 205);
  printf("%c\n", 187);
  
  while(j <= 22)
  {
  gotoxy(20,j);
  printf("%c", 186);
  j++;
  }
  
  while(k <= 22)
  {
  gotoxy(58,k);
  printf("%c", 186);
  k++;
  }
  
    gotoxy(20,23);
  printf("%c", 200);
  for (i = 1; i <= 37; i++)
    printf("%c", 205);
  printf("%c\n", 188);
       
}

void BorderMulti()
{ int i, j = 1, k = 1;
  int l, m = 1, n = 1;
  
  Color(8);
  
  //Player 1 border
  gotoxy(0,0);
  printf("%c", 201);
  for(i = 1; i <= 37; i++)
    printf("%c", 205);
  printf("%c\n", 187);
  
  while(j <= 20)
  {
  gotoxy(0,j);
  printf("%c", 186);
  j++;
  }
  
  while(k <= 20)
  {
  gotoxy(38,k);
  printf("%c", 186);
  k++;
  }
  
  gotoxy(0,21);
  printf("%c", 200);
  for (i = 1; i <= 37; i++)
    printf("%c", 205);
  printf("%c\n", 188);
  
  //Player 2 border
  gotoxy(40,0);
  printf("%c", 201);
  for(i = 1; i <= 37; i++)
    printf("%c", 205);
  printf("%c\n", 187);
  
  while(m <= 20)
  {
  gotoxy(40,m);
  printf("%c", 186);
  m++;
  }
  
  while(n <= 20)
  {
  gotoxy(78,n);
  printf("%c", 186);
  n++;
  }
  
  gotoxy(40,21);
  printf("%c", 200);
  for (i = 1; i <= 37; i++)
    printf("%c", 205);
  printf("%c\n", 188);
}

void Title(int Delay)
{ int i;
  Color(10);
  printf("\n");                                                                                sleep(Delay);
  gotoxy(10,3); printf("{__ {__      {__           {____           {__     {__   {__\n");      sleep(Delay);
  gotoxy(10,4);printf("{_     {__   {__         {__    {__     {__   {__  {__  {__\n");        sleep(Delay);
  gotoxy(10,5);printf("{_     {__   {__       {__        {__  {__         {__ {__\n");         sleep(Delay);
  gotoxy(10,6);printf("{___ {_      {__       {__        {__  {__         {_ {_\n");           sleep(Delay);
  gotoxy(10,7);printf("{_     {__   {__       {__        {__  {__         {__ {__\n");         sleep(Delay);
  gotoxy(10,8);printf("{_     {__   {__         {__     {__    {__   {__  {__  {__\n");        sleep(Delay);
  gotoxy(10,9);printf("{__ {__      {________     {____          {____    {__   {__\n\n");     sleep(Delay);
  gotoxy(10,11);printf("\n");                                                                  sleep(Delay);
  gotoxy(30,12);printf("{__ {__          {____      {__      {__\n");                          sleep(Delay);
  gotoxy(30,13);printf("{_     {__     {__    {__    {__   {__\n");                            sleep(Delay);
  gotoxy(30,14);printf("{_     {__   {__        {__   {__ {__\n");                             sleep(Delay);
  gotoxy(30,15);printf("{___ {_      {__        {__     {__ \n");                              sleep(Delay);
  gotoxy(30,16);printf("{_     {__   {__        {__   {__ {__\n");                             sleep(Delay);
  gotoxy(30,17);printf("{_     {__     {__     {__   {__   {__\n");                            sleep(Delay);
  gotoxy(30,18);printf("{__ {__          {____      {__      {__\n");
  Color(14);
  gotoxy(63,23); printf("K.PAGTAKHAN S22");
}

void MainMenu(int LogoSleep)
{ 
  system("cls");
  Border(5);
  Title(LogoSleep); 
  Menu();

}

void Menu()
{
  Color(9);
  gotoxy(10,13); printf("[1]");
  Color(7);
  gotoxy(14,13); printf("Play Game"); sleep(100);
  Color(9);
  gotoxy(10,15); printf("[2]");
  Color(7);
  gotoxy(14,15); printf("How to Play"); sleep(100);
  Color(9);
  gotoxy(10,17); printf("[3]");
  Color(7);
  gotoxy(14,17); printf("Exit"); sleep(100);
}

int Choice()
{
  int Kevin=0;
  char key;
  int Kevin_Choice = 0;
  while(Kevin != 1)
  {
    key = getch();
    switch (key)
    {
    case '1': Kevin = 1;
              Kevin_Choice = 1;
              break;
    case '2': Kevin = 1;
              Kevin_Choice = 2;
              break;
    case '3': Kevin = 1;
              Kevin_Choice = 3;
              break;
    }
  }
  
  return Kevin_Choice;
}

int PlayerMode()
{ int x = 29;
  int y = 1;
  int nOne = 1;
  int nTwo = 2;
  int Kevin = 20;
  char key;
  
  system("cls");
  SmallBorder();
  
  Color(10); gotoxy(x,y+8);    printf("PLAYER MODE");
  Color(15); gotoxy(x+4,y+10); printf("[S]ingle Player");
  Color(15); gotoxy(x+4,y+12); printf("[T]wo Player");
  
  while (Kevin != 23)
  {
  key = getch();
  switch (key)
  {
  case 's':
  case 'S': return nOne; Kevin = 23; break;
  case 'T':
  case 't': return nTwo; Kevin = 23; break;
  default: Kevin = 20;
  }
}
}

int PlayGame()
{
  Diff();
}

int Diff()
{
  int x = 30;
  int y = 6;
  char key;
  int nEasy = 750;
  int nMedium  = 500;
  int nHard = 300;
  int nImpossible = 100;
  
  int Kevin = 20;

  system("cls");
  SmallBorder();

  Color(15); gotoxy(x-2,y); printf("Select difficulty:");
  Color(11); gotoxy(x+3,y+2); printf("[E]asy");
  Color(6); gotoxy(x+3,y+4); printf("[M]edium");
  Color(5);  gotoxy(x+3,y+6); printf("[H]ard");
  Color(4); gotoxy(x+3,y+8); printf("[I]mpossible");

  while(Kevin != 23)
  {
    key = getch();

    switch(key)
    {
      case 'E':
      case 'e': return nEasy;
                Kevin=23;
                break;
      case 'M':
      case 'm': return nMedium;
                Kevin=23;
                break;
      case 'H':
      case 'h': return nHard;
                Kevin=23;
                break;
      case 'I':
      case 'i': return nImpossible;
                Kevin=23;
                break;
                
      default: Kevin=20; 
    }
  }
}

int HowtoPlay1()
{ int nC;
  char key;
  int x = 3;

  int i = 30, j = 1;
  
  system("cls");
  Color(15);
  Border(0);
  
  Color(14);
  gotoxy(i+6,1); printf("OBJECTIVE");
  Color(15);
  gotoxy(1,3); printf("In the Single Player mode, objects will come out from 4 sides/walls. You are");
  gotoxy(1,4); printf(" to block the object for it not to reach the side/wall across the side/wall");
  gotoxy(6,5); printf("it originated. Allowing it to cross will decrease your Player size.");
  gotoxy(3,6); printf("By pressing ENTER, your Player size will increase but 25 points will be");
  gotoxy(6,7); printf("deducted from your score. Blocking the object will increase points.");
  Color(12);
  gotoxy(15,9);printf("%c = 1 point %c = 2 points %c = 3 points %c = 4 points", 3,4,5,6);
    
  Color(14);
  gotoxy(i+7,j+10); printf("CONTROLS");
  Color(15);
  gotoxy(i,j+12); printf("        _____        ");
  gotoxy(i,j+13); printf("       || %c ||       ", 24);
  gotoxy(i,j+14); printf("       ||___||       ");
  gotoxy(i,j+15); printf("       |/___\\|       ");
  gotoxy(i,j+16); printf(" _____  _____  _____ ");
  gotoxy(i,j+17); printf("|| %c |||| %c |||| %c ||", 27, 25, 26);
  gotoxy(i,j+18); printf("||___||||___||||___||");
  gotoxy(i,j+19); printf("|/___\\||/___\\||/___\\|");
  
  do
  {
  Color(2);
  gotoxy(24,23); printf("PRESS ENTER TO GO BACK TO MAIN MENU");
  } while(getch() != ENTER);
}

int HowtoPlay2()
{
  int i = 20, j = 1;
  int x = 3;
  char key;

    system("cls");
  Color(15);
  Border(0);
  
  Color(14);
  gotoxy(i+17,1); printf("OBJECTIVE");
  Color(15);
  gotoxy(4,3); printf("In the Two Player mode, an object will fall from the top. The goal is to");
  gotoxy(3,4); printf("prevent the object from reaching the bottom by blocking it. Player 1 will");
  gotoxy(3,5); printf("battle against Player 2. Turns will change every after a ball is dropped.");
  gotoxy(6,6); printf("Player 1 goes first. Each player will be given 50 objects to block.");
  gotoxy(15,7);printf("The player who gets to block more objects, wins!");
  
  Color(14);
  gotoxy(38,10); printf("CONTROLS");  
 Color(15);
  gotoxy(i,j+11);   printf("        _____        ");                 printf("         _____        ");
  gotoxy(i,j+12); printf("       || %c ||       ", 'W');             printf("        || %c ||       ", 24);
  gotoxy(i,j+13); printf("       ||___||       ");                   printf("        ||___||       ");
  gotoxy(i,j+14); printf("       |/___\\|       ");                  printf("        |/___\\|       ");
  gotoxy(i,j+15); printf(" _____  _____  _____ ");                   printf("  _____  _____  _____ ");
  gotoxy(i,j+16); printf("|| %c |||| %c |||| %c ||", 'A', 'S', 'D'); printf(" || %c |||| %c |||| %c ||", 27, 25, 26);
  gotoxy(i,j+17); printf("||___||||___||||___||");                   printf(" ||___||||___||||___||");
  gotoxy(i,j+18); printf("|/___\\||/___\\||/___\\|");                printf(" |/___\\||/___\\||/___\\|");
  gotoxy(i,j+19); Color(9); printf("       Player1      ");          Color(12); printf("         Player2");     

  do
  {
  Color(2);
  gotoxy(24,23); printf("PRESS ENTER TO GO BACK TO MAIN MENU");
  } while(getch() != ENTER);
}

void Player(int xx, int yy, int nSize)
{ gotoxy(xx,yy);
  Color(15);
  int i;
  for (i = 1; i <= nSize; i++)
  printf("%c", 223);
}
 
 void ErasePlayer(int xx, int yy, int nSize)
{ gotoxy(xx,yy);
  int i;
  for (i = 1; i <= nSize; i++)
  printf(" ");
}

void PrintEnemy1(int a, int b, int face)
{ gotoxy(a,b);
  printf("%c", face);
}

void EraseEnemy1(int a, int b)                                                  
{ gotoxy(a,b);
  printf(" ");
}

void PrintEnemy2(int a, int b, int face)
{ gotoxy(a,b);
  printf("%c", face);
}


void EraseEnemy2(int a, int b)
{ gotoxy(a,b);
  printf(" ");
}

void PrintEnemy3(int a, int b, int face)
{ gotoxy(a,b);    
  printf("%c", face);
}

void EraseEnemy3(int a, int b)
{ gotoxy(a,b);
  printf(" ");
}

void PrintEnemy4(int a, int b, int face)
{ gotoxy(a,b);
  printf("%c", face);
}

void EraseEnemy4(int a, int b)
{ gotoxy(a,b);
  printf(" ");
}

void SinglePlayer(int x, int y, int  nDifficulty)
{ int a1 = sRandom(76,1);
  int b1 = 1;
  int a2 = 1;
  int b2 = sRandom(21,1);
  int a3 = sRandom(76,1);
  int b3 = 21;
  int a4 = 76;
  int b4 = sRandom(21,1);
  int i;
  int Kevin, Pagtakhan = 0;
  int score=0;
  char key;
  int color;
  int face1,face2,face3,face4;
  int hehe;
  int righty = 1, lefty = 1;
  
  int nSize = 7;
  
  system("cls");
  Border(1);

  sleep(1000);
  Player(x,y,nSize);
  
  gotoxy(1,23);
  Color(2);
  sleep(1000);
  printf("Score: ");
  Color(15);
  printf("%3.3d", score);
        
  face1 = Random(4,3);
  face2 = Random(4,3);
  face3 = Random(4,3);
  face4 = Random(4,3);
  
  sleep(1000);
  while (Kevin != 100)
  {
    gotoxy(1,23);
    Color(2);
    printf("Score: ");
    Color(15);
    printf("%3.3d", score);
       
    if (y == b1 && x <= a1 && a1 <= x+nSize-1)
      {
      gotoxy(1,23);
      score+=face1-2;
      Color(2);
      printf("Score: ");
      Color(15);
      printf("%3.3d", score);
      b1 = 1;
      a1 = Random(77,1);
      face1 = Random(4,3);
      }
      
    if (y == b2 && x <= a2 && a2 <= x+nSize-1)
      {
      gotoxy(1,23);
      score+=face2-2;
      Color(2);
      printf("Score: ");
      Color(15);
      printf("%3.3d", score);
      a2 = 1;
      b2 = Random(21,1);
      face2 = Random(4,3);
      }
      
    if (y == b3 && x <= a3 && a3 <= x+nSize-1)
       {
       gotoxy(1,23);
       score+=face3-2;
       Color(2);
       printf("Score: ");
       Color(15);
       printf("%3.3d", score);
       b3 = 21;
       a3 = Random(77,1);
       face3 = Random(4,3);
       }
       
    if (y == b4 && x <= a4 && a4 <= x+nSize-1)
       {
       gotoxy(1,23);
       score+=face4-2;
       Color(2);
       printf("Score: ");
       Color(15);
       printf("%3.3d", score);
       a4 = 76;
       b4 = Random(21,1);
       face4 = Random(4,3);
       }
           
          
   if ( key = kbhit() )
   {
     key = getch(); 
     ErasePlayer(x, y, nSize);

     switch (key)
     {
     case UP   :  if(y>1)
                   y--; 
                 break;
     case DOWN :  if(y<21)
                   y++;
                 break;
     case LEFT :  if(x>1)
                   {
                   if (nSize >= 2)
                   x-=2;
                   else if (nSize == 1)
                   x-=1;
                   }
                 break;
     case RIGHT:  if(x<77-nSize)
                   {
                   if (nSize >= 2)
                   x+=2;
                   else if (nSize == 1)
                   x+=1;
                   }
                 break;
     case ENTER: if (score > 25)
                 { nSize++;
                   score-=25;
                 }
    }
   Player(x,y,nSize);
   } 
   else 
   {
   Color(face1+6);
   PrintEnemy1(a1,b1,face1);
   Color(face2+6);
   PrintEnemy2(a2,b2,face2);
   Color(face3+6);
   PrintEnemy3(a3,b3,face3);
   Color(face4+6);
   PrintEnemy4(a4,b4,face4);  
   sleep(nDifficulty);
   EraseEnemy1(a1,b1);
   EraseEnemy2(a2,b2);
   EraseEnemy3(a3,b3);
   EraseEnemy4(a4,b4);
   
   
   if (b1++>20)
   {
   b1 = 1;
   a1 = Random(77,1);
   ErasePlayer(x, y, nSize);
   nSize--;
   Player(x,y,nSize);
   face1 = Random(4,3);
   } 
        
   if (a2++>76)
   {
   b2 = Random(21,1);
   a2 = 1;
   ErasePlayer(x, y, nSize);
   nSize--;
   Player(x,y,nSize);
   face2 = Random(4,3);
   } 
        
   if (b3--<2)
   {
   b3 = 21;
   a3 = Random(77,1);
   ErasePlayer(x, y, nSize);
   nSize--;
   Player(x,y,nSize);
   face3 = Random(4,3);
   } 
        
   if (a4--<2)
   {
   b4 = Random(21,1);
   a4 = 76;
   ErasePlayer(x, y, nSize);
   nSize--;
   Player(x,y,nSize);
   face4 = Random(4,3);
   } 
        
   if (nSize < 1)
   Kevin = 100;
   }
   }
}

void Player1(int aa, int bb)
{ int i;
  gotoxy(aa,bb);
  Color(9);
  for(i = 1; i <= 7; i++)
    printf("%c", 223);

}

void Player2(int cc, int dd)
{ int i;
  gotoxy(cc,dd);
  Color(12);
  for(i = 1; i <= 7; i++)
    printf("%c", 223);
}

void abPrintEnemy(int x1, int y1)
{
  gotoxy(x1,y1);
  printf("%c", 2);
}
void abEraseEnemy(int x1, int y1)
{
  gotoxy(x1,y1);
  printf(" ");
}

void MultiPlayer()
{
  char key;
  int i, j;
  
  int x = sRandom(37,1);
  int y = 1;
  
  int nNum = sRandom(70,1);
  
  int Score1 = 0, Score2 = 0;
  
  int Speed = 120;
  
  int balls1 = 0, balls2 = 0;
  
  int aa = 17, bb = 17;
  int cc = 57, dd = 17;
     
  system("cls");
  sleep(500);
  BorderMulti();

  Color(15);
  sleep(1000);
  Player1(aa,bb);
  sleep(1000);
  Player2(cc,dd);
  sleep(1000);
  
  
  Color(15);
  gotoxy(15,0); printf("Player 1");
  gotoxy(55,0);printf("Player 2");
  
  gotoxy(0,22); Color(9);
  printf("%d", Score1);
  gotoxy(0,23); Color(15);
  printf("SCORE");
  gotoxy(77,22); Color(12);
  printf("%2d", Score2);
  gotoxy(74,23); Color(15);
  printf("SCORE");
  
  Color(9);
  gotoxy(36,22); printf("%2d", 50-balls1);
  Color(15);
  gotoxy(28,23); printf("BALLS LEFT");
  
  Color(12);
  gotoxy(41,22); printf("%2d", 50-balls2);
  Color(15);
  gotoxy(41,23); printf("BALLS LEFT");
  sleep(1000);

  while(balls2 != 50)
  {
  
  nNum = sRandom(70,1);
  
  Color(15);
  gotoxy(15,0); printf("Player 1");
  gotoxy(55,0);printf("Player 2");
  
  gotoxy(0,22); Color(9);
  printf("%d", Score1);
  gotoxy(0,23); Color(15);
  printf("SCORE");
  gotoxy(77,22); Color(12);
  printf("%2d", Score2);
  gotoxy(74,23); Color(15);
  printf("SCORE");
  
  Color(9);
  gotoxy(36,22); printf("%2d", 50-balls1);
  Color(15);
  gotoxy(28,23); printf("BALLS LEFT");
  
  Color(12);
  gotoxy(41,22); printf("%2d", 50-balls2);
  Color(15);
  gotoxy(41,23); printf("BALLS LEFT");

  if (bb == y && aa <= x && x <= aa+6)
        {
        Score1++;
        y = 1;
        if (Speed%2 == 1) 
          x = Random(37,1); 
        else if (Speed%2 == 0)
          x = Random(37,41);
        Speed--;
        balls1++;
        }
        
  if (dd == y && cc <= x && x <= cc+6)
        {
        Score2++;
        y = 1;
        if (Speed%2 == 1) 
          x = Random(37,1); 
        else if (Speed%2 == 0)
          x = Random(37,41);
        Speed--;
        balls2++;
        }
  
  if (key = kbhit())    
  {
  if (x<39) 
  { key = getch(); 
    ErasePlayer(aa,bb,7);
  
    switch (key)
      {
      case 'W':     
      case 'w':  if(bb>1)
                   bb--; 
                 break;
      case 'S':
      case 's':  if(bb<20)
                   bb++;
                 break;
      case 'A':
      case 'a':  if(aa>1)
                   aa-=2;
                 break;
      case 'D':
      case 'd':  if(aa<31)
                   aa+=2;
                 break;
    default: aa=aa; bb=bb; break;
    } 
    Player1(aa,bb);
  }
   else if (x>40)
   { key = getch(); 
     ErasePlayer(cc,dd,7);
  
     switch (key)
     {
     case UP:  if(dd>1)
                   dd--; 
                 break;
     case DOWN:  if(dd<20)
                   dd++;
                 break;
     case LEFT:  if(cc>41)
                   cc-=2;
                 break;
     case RIGHT:  if(cc<71)
                   cc+=2;
                 break;
    }
     Player2(cc,dd);
   }
   } 
   else
   {
   Color(15);
   abPrintEnemy(x,y);
   sleep(Speed);
   abEraseEnemy(x,y);
   
   if (y++>19)
   {
   y = 1;
   if (Speed%2 == 1) 
   { x = Random(37,1); 
     balls2++;
   }
   else if (Speed%2 == 0)
   { x = Random(37,41);
   balls1++;
   }
   Speed--;
   } 
  }
  }
  Sleep(500);
  Result(Score1, Score2);
}

void GameOver()
{ int x1 = 20;
  int x2 = 22;
  int y, j, k, z;
  int i = 1;

  sleep(1000);
  while(i <= 3)
  {
  Color(12);
  z=1;
  gotoxy(1,1);
  for(j = 1; j <= 21; j++)
  { for(k = 1; k <= 77; k++)
      printf(" ");
      z++;
      gotoxy(1,z);
  }
  sleep(300);
  y = 2;   
  gotoxy(x1,y); printf(" .d8888b."); 
  gotoxy(x1,y+1); printf("d88P  Y88b");      
  gotoxy(x1,y+2); printf("888    888");
  gotoxy(x1,y+3); printf("888         8888b.  88888b.d88b.   .d88b.");
  gotoxy(x1,y+4); printf("888  88888     \"88b 888 \"888 \"88b d8P  Y8b ");
  gotoxy(x1,y+5); printf("888    888 .d888888 888  888  888 88888888 ");
  gotoxy(x1,y+6); printf("Y88b  d888 888  888 888  888  888 Y8b.");
  gotoxy(x1,y+7); printf(" \"Y888P8P  \"Y888888 888  888  888  \"Y8888");
  
  y = 11;
  gotoxy(x2,y);   printf(" .d88888b."); 
  gotoxy(x2,y+1); printf("d88P\" \"Y88b");      
  gotoxy(x2,y+2); printf("888     888");
  gotoxy(x2,y+3); printf("888     888 888  888  .d88b.  888d888");
  gotoxy(x2,y+4); printf("888     888 888  888 d8P  Y8b 888P\" ");
  gotoxy(x2,y+5); printf("888     888 Y88  88P 88888888 888");
  gotoxy(x2,y+6); printf("Y88b. .d88P  Y8bd8P  Y8b.     888");
  gotoxy(x2,y+7); printf(" \"Y88888P\"    Y88P    \"Y8888  888");
  i++;
  sleep(600);
  }

  sleep(300);
  do
  {
  gotoxy(28,20);
  Color(15);
  printf("PRESS ENTER TO CONTINUE");
  } while(getch() != ENTER);
}

void Result(float Score1, float Score2)
{
  int x = 21, y = 1;
  
  system("cls");
  SmallBorder();

  Color(14);
  gotoxy(x,y); printf("RESULTS");
  Color(9);
  gotoxy(x+1,y+3); printf("Player 1");
  Color(10);
  gotoxy(x+3,y+4); printf("Blocked: "); printf("%.0f", Score1);
  Color(8);
  gotoxy(x+3,y+5); printf("Missed: "); printf("%.0f", 50-Score1);
  Color(15);
  gotoxy(x+3,y+6); printf("Block Percentage: "); printf("%.0f\%c", (Score1/50.0)*100, 37);
  
  Color(12);
  gotoxy(x+1,y+9); printf("Player 2");
  Color(10);
  gotoxy(x+3,y+10); printf("Blocked: "); printf("%.0f", Score2);
  Color(8);
  gotoxy(x+3,y+11); printf("Missed: "); printf("%.0f", 50-Score2);
  Color(15);
  gotoxy(x+3,y+12); printf("Block Percentage: "); printf("%.0f%c", (Score2/50.0)*100, 37);
  
  
  Color(14);
  if (Score1>Score2)
  { gotoxy(x+10,y+16);
    printf("Winner: Player1");                    
  }
  else if (Score1<Score2)
  { gotoxy(x+10,y+16);
    printf("Winner: Player2");                    
  }
  else if (Score1==Score2)
  { gotoxy(x+16,y+16);
    printf("DRAW!");                    
  }
  
  do
  {
  gotoxy(28,21);
  Color(15);
  printf("PRESS ENTER TO CONTINUE");
  } while(getch() != ENTER);
}

int Close(int Kevin_Close)
{ char key;
  system("cls");
  Border(0);
  Color(15);
  int x = 21, y = 13;
  sleep(500);
  while(y>=5)
  {
  gotoxy(x,y+1); printf("                               ,------.");
  gotoxy(x,y+2); printf(",------.          ,--.  ,--.  '  .--.  '");
  gotoxy(x,y+3); printf("|  .---',--.  ,--.`--',-'  '-.'--' _|  |");
  gotoxy(x,y+4); printf("|  `--,  \\  `'  / ,--.'-.  .-' .--' __' "); 
  gotoxy(x,y+5); printf("|  `---. /  /.  \\ |  |  |  |   `---'    ");
  gotoxy(x,y+6); printf("`------''--'  '--'`--'  `--'   .---.");
  gotoxy(x,y+7); printf("                               '---'");
  gotoxy(x,y+8); printf("                                    ");
  y--;
  sleep(150);
  }
  Color(Random(15,1));
  gotoxy(32,12); printf("[Y]es or [N]o?");
  Kevin_Close = 0;
  while(Kevin_Close == 0)
  {
  if(kbhit())
  {
  key=getch();
  switch(key)
  {
  case 'n' : 
  case 'N' : Kevin_Close = 1;
             return Kevin_Close;
             break;
  case 'y' :
  case 'Y' : Kevin_Close = 2;
             return Kevin_Close;
             break;
  }
  }
  }
}

/*
COLORS
BLACK = 0,
DARK_BLUE = 1,
DARK_GREEN = 2,
TEAL = 3,
DARK_RED = 4,
DARK_PURPLE = 5,
GOLD = 6,
GREY = 7,
DARK_WHITE = 8,
BLUE = 9,
GREEN = 10,
CYAN = 11,
RED = 12,
PURPLE = 13,
YELLOW = 14,
WHITE = 15
*/
