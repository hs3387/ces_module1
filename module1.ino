#include "TFT_eSPI.h"
#include "image.h"
TFT_eSPI tft= TFT_eSPI();
TFT_eSprite sprite=TFT_eSprite(&tft);


#image dimensions
int imageW=590;
int imageH=291;

int screenW=240;
int screenH=135;
int screenArea=screenW*screenH;

int start=1;
int endFlag=1;
int m=imageW;

unsigned short imageS[screenArea]={0}; 


void setup() 
{
	tft.init();
	tft.setRotation(1);
	tft.setSwapBytes(true);
	tft.fillScreen(TFT_WHITE);
}


//Start Position
int x=0;
int y=4;

//Current Position
int pos=0;

//Steps
int changeX=1;
int changeY=1;

void loop()
{
	if (endFlag ==1)
	{
		tft.fillScreen(TFT_WHITE);
		tft.setCursor(12, 12, 2);
		tft.setTextColor(TFT_BLACK,TFT_WHITE);
		tft.setTextSize(2);
	
		delay(1000);
		tft.print("Po");
		delay(250);
		tft.print(" Nee");
		delay(250);
		tft.println(" Po...");
		delay(1000);
		
		tft.print("	The");
		delay(250);
		tft.print(" Pain");
		delay(250);
		tft.print(" of");
		delay(250);
		tft.println(" Love!");
		delay(1000);
		
		tft.print("By");
		delay(250);
		tft.print(" Anirudh");
		delay(250);
		tft.println(".R");
		delay(1000);
		
		tft.fillScreen(TFT_WHITE);
	}
	
	scrollNotes();
	
}

void scrollNotes()
{
	endFlag=0;
	
	pos=x+imageW*y;
	start=pos;
	m=screenW+pos;
	for(int i=0;i<screenW*screenH;i++)
	{
		if(start%m==0)
		{
			start=start+(imageW-screenW);
			m=m+imageW;
		}

		imageS[i]=pnp_chorus_sheet[start];
		start++;

	}

	x=x+changeX;

	if((x==imageW-screenW-1 || x<0) && y == 4)
	{
		x=0;
		y=27;
		delay(500);
	}

	else if((x==imageW-screenW-1 || x<0) && y == 27)
	{
		x=0;
		y=4;
		delay(500);
		endFlag=1;
	}

	tft.pushImage(0,0,screenW,screenH,imageS);

	delay(25);


}
