/* Plane Motion Program */
#include<stdio.h>
#include<iostream>
#include<fstream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<math.h>

class high
{
 public:
 char nam[30];
 int score;
}obj,s1;

int x2, y2; char ch; char name[30]; char m ;int chint; char ch3;char m2; char s[80]; char name2[4]; char s2[80];int j = 10; char xvalue[50];  char x2value[80];

int main ( )
{AA:
int gd=DETECT,gm;
int point = 0; int fuel = 500;
initgraph(&gd,&gm,"D:\\BC5\\BGI");
int x = 0, y = 100; // select initial values for x and y - coordinates of top of tail fin
float xmove = 10, ymove = 10; // set values for distance to move in x and y directions
int new_page, old_page; // declare integer variables representing two graphics pages
outtextxy(250,250,"LOADING...");

for(int i=0;i<650;i=i+10)
{
setcolor(4);
settextstyle(7,0,5);
outtextxy(0+i,190,"Flight Simulator X");
delay(100);
setcolor(0);
settextstyle(7,0,5);
outtextxy(0+i,190,"Flight Simulator X");
 }
AB: cleardevice();
 setcolor(4);
  settextstyle(7,0,5);
outtextxy(40,200,"Choose one of the following options");
 outtextxy(40,230,"HIT S. Start Game");
 outtextxy(40,250,"HIT I. Instructions");
 outtextxy(40,270,"HIT H. High Scores");
 outtextxy(40,290,"HIT E. Exit");
 outtextxy(100,310,"Done by");
 outtextxy(100,330,"Sunil Divakar");
 outtextxy(100,350,"Vinay Manikandan");

 m = getch();
setfillstyle(1, LIGHTBLUE);
int x2 = random(30)*10;
if(x2 == 0)
x2 = 100;
int y2 = 100; //int y2 = random(30)*10;
//if(y2 == 0)

if(m == 's' || m == 'S')
goto BC;
else if(m == 'e' || m == 'E')
goto CD;
else if(m == 'i' || m == 'I')
{ cleardevice();
ifstream infile;
    infile.open ("readme.txt");
    if (infile)
    {
        while (infile.good())
            cout << (char) infile.get();
    }
    else
    {
        cout << "Unable to open file.";
    }
    infile.close();
    getch();
    goto AB;
}

else if(m == 'h' || m == 'H')
{ cleardevice();
fstream f1;
    f1.open ("hscore.dat", ios::binary | ios:: in);

    if (f1)
    {
        while (f1.good())
           {cout << "Name "<<"          "<<"Scores"<<endl;
           f1.read((char*)&s1,sizeof(s1));
           while(!f1.eof())
              {cout<<s1.nam<<"             "<<s1.score;
              f1.read((char*)&s1,sizeof(s1));   }
           }
    }
    else
    {
        cout << "Unable to open file.";
    }
    f1.close();
    getch();
    goto AB;
}

else if(m != 's' || m != 'S' || m != 'e' || m != 'E' || m !='i' || m!='I' || m!= 'h' || m!='H')
goto AB;

CD: cleardevice();
 setcolor(4);
settextstyle(7,0,5);
 outtextxy(100,260,"Done by");
 outtextxy(100,280,"Sunil Divakar");
 outtextxy(100,300,"Vinay Manikandan");

outtextxy(10,350,"Hope you enjoyed FSX.  HIT E to exit HIT M key to go back to main menu");
m2 = getch();
if(m2 == 'E' || m2 == 'e')
{ closegraph( );
// close the graph
return (0);}
else if(m2 == 'M' || m2 == 'm')
goto AB;
else
goto CD;


BC : for (int move = 1; move <= 500; move++ ) // move jet 500 times
{    itoa(fuel,s,10);
      itoa(point,s2,10);
      outtextxy(10,20,"Fuel Quantity :");
     outtextxy(150,20,s);
     outtextxy(500,20,"Score :");
     outtextxy(550,20,s2);


        int bkground[ ] = {0,0, 639,0, 639,479, 0,479, 0,0};
		  fillpoly(5,bkground);


        setcolor( WHITE ); // set outline color for jet to WHITE
        setfillstyle(1,RED);
        int fuselage[ ] = {x,y+350, x+70,y+350, x+20,y+360, x+90,y+360, x+120,y+370, x+20,y+370, x,y+350};
        fillpoly(7,fuselage); // fill in the body of the plane with RED

        setfillstyle(1,BLACK);
        int frontWing[ ] = {x+60,y+365, x+40,y+380, x+20,y+380, x+30,y+380, x+50,y+365, x+60,y+365};
        fillpoly(6,frontWing); // fill in the front wing with BLACK

        int topWing[ ] = {x+46,y+360, x+30,y+350, x+20,y+350, x+40,y+350, x+58,y+360, x+46,y+360};
        fillpoly(6,topWing); // fill in the top wing with BLACK

        int pilotArea[ ] = {x+82,y+360, x+90,y+365, x+105,y+365, x+90,y+360, x+82,y+360};
        fillpoly(5,pilotArea); // fill in the pilot area with BLACK

       itoa(fuel,s,10);
      itoa(point,s2,10);
      outtextxy(10,20,"Fuel Quantity :");
     outtextxy(150,20,s);
     outtextxy(500,20,"Score :");
     outtextxy(550,20,s2);

     setcolor(15);
       setcolor(9);
       fillellipse(x2,y2,8,8);

       if(x2 == (x+100) && y2 == 360+y)
       {point +=10; s.point = point;
       x2 = random(50)*10;
       y2 = random(50)*10;
       setcolor(15);
       setcolor(9);
       fillellipse(x2,y2,8,8);
       }
        ch = getch();
        chint = ch;
        if (chint == 27)
         {outtextxy(230,10, "HIT Y to EXIT");
         char ch4;
         ch4 = getch();
         if(ch4 == 'y' || ch4 == 'Y')
         goto EF;
         }

         if(!(ch == 'd' || ch == 'w' || ch == 's' || ch == 'a'))
         {move--;continue; }

        if(((ch == 'w' || ch == 'W' || ch == 'S' || ch == 's') && move<20))
        {move--;continue;}


        if((ch == 's' || ch == 'S'))
        y = y + ymove;

        else if(ch == 'd' || ch == 'D')
         x = x + xmove;

        else if((ch == 'w' || ch == 'W'))
        y = y - ymove;

        else if(ch =='A' || ch =='a')
        x = x - xmove;


     setcolor(4);
     settextstyle(7,0,5);
     fuel-=1;
       itoa(fuel,s,10);
      itoa(point,s2,10);
		outtextxy(10,20,"Fuel Quantity :");
	  outtextxy(150,20,s);
	  outtextxy(500,20,"Score :");
	  outtextxy(550,20,s2);

	  setfillstyle(1, LIGHTBLUE);

}


LM : if(point >=100)
{cleardevice();
setcolor(6);
settextstyle(11,0,20);
outtextxy(220,250,"Congratulations YOU WON THE GAME !!!!!!!!");
outtextxy(220,300,"Hit 'c' to continue");
ch3 = getch( );
if(ch3 == 'c' || ch3 == 'C')
goto IJ;
else
goto LM;
}
IJ: cleardevice();

fstream f;
 f.open("hscore.dat", ios::out|ios::app|ios::binary);
 outtextxy(220,300,"New High Score Enter your name");
gotoxy(60,50);gets(s.name);strcpy(name2,name);
f.write((char*)&s, sizeof(s));
outtextxy(220,350,"Hit any key to continue");
getch();

 f.close();
clrscr();
	cleardevice();
	outtextxy(250,250,"GAME OVER");
	 for(int i=0;i<50;i=i+10)
{
setcolor(4);
settextstyle(7,0,5);
outtextxy(255,450-i,"Thank You for playing");
delay(250);
setcolor(0);
settextstyle(7,0,5);
outtextxy(255,450-i,"Thank You for playing");
delay(500);
setcolor(4);                                          
settextstyle(7,0,5);
outtextxy(255,450-i+5,"Special Thanks to our computer teachers");
delay(500);
setcolor(0);
settextstyle(7,0,5);
outtextxy(255,450-i+5,"Special Thanks to our computer teachers");
 }
EF: cleardevice();
 setcolor(4);
settextstyle(7,0,5);
 outtextxy(100,260,"Done by");
 outtextxy(100,280,"Sunil Divakar");
 outtextxy(100,300,"Vinay Manikandan");

outtextxy(10,350,"Hope you enjoyed FSX.  HIT E to exit HIT M key to go back to main menu");
m2 = getch();

if(m2 == 'E' || m2 == 'e')
{ closegraph( );
// close the graph
return (0);}
else if(m2 == 'M' || m2 == 'm')
goto AA;
else
 goto EF;
}
