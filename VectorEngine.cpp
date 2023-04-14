#include<iostream>
#include <windows.h>
#include <wingdi.h>
#include "Colors.h"
#include "JoyStick.h"
#include <time.h>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	int64_t fX = 10;
	int64_t fY = 10;
	int64_t r = 1;
	int64_t g = 1;
	int64_t b = 1;
	int64_t fLXPos = 0;
	int64_t fLYPos = 0;
	int64_t fRXPos = 0;
	int64_t fRYPos = 0;
	int64_t fRXC = 0;
	int64_t fRYC = 0;
	int64_t fLXC = 0;
	int64_t fLYC = 0;
	int64_t fRandR = 0;
    int64_t fRandG = 0; 
    int64_t fRandB = 0;
    int64_t fScreenX = 320;
    int64_t fScreenY = 240;
    int64_t fScrX[] = {320,640,800,1280,1920};
    int64_t fScrY[] = {240,480,600,720,1080};
    int64_t fScreenSelX = 0;
    int64_t fScreenSelY = 0;
    	int (*fUnitMain)(int,char**);
		fUnitMain = &main;
	int64_t fRandAlgoritm  = 1;
	HWND hWin = GetConsoleWindow();
	COLORREF fCol = 212344;
	HDC fDC = GetDC(hWin);
	tagPOINT fPos;
	CXBOXController* xController1;
	 xController1 = new CXBOXController(1);
	HANDLE fHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	cout<<"(R) - Clear (ESC) - Exit "<<endl;
	system("cls");
		ConsoleFullScreen(GetConsoleWindow(),3);
  for(int64_t fC = 1; fC > 0; fC++)
  {
  	if(GetAsyncKeyState('A'))
  	{
  	      fRandAlgoritm++;
  	      if(fRandAlgoritm > 1)
  	      {
  	      	fRandAlgoritm = 0;
		  }
  	      if(fRandAlgoritm == 0)
  	      {
  	      		fX = rand() % 1280;
  		        fY = rand() % 720;
		  }
		  if(fRandAlgoritm == 1)
  	      {
  	      		fX = fX;
  		        fY = fY;
		  }
	  }
  	cls(fHandle);
  	SetColorAMD64(240);
  	cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: 3DVectorsEngine :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
  	SetColorAMD64(15);
  	cout<<"fStack = "<<&fHandle<<" \t fStack_DC = "<<&fDC<<"[::::Mouse Pos:"<<fPos.x<<":"<<fPos.y<<"::] Xinput_Axis = [LX:"<<fLXC<<":LY:"<<fLYC<<"RX:"<<fRXC<<":RY:"<<fRYC<<"]"<<endl;
  	cout<<" Start Benchmark GPU (4) (R) Clear Window (ESC) Exit Right key Mouse and Move to Paint!!"<<endl;
  	    fLXPos = (xController1->GetState().Gamepad.sThumbLX) ;
		fLYPos = (xController1->GetState().Gamepad.sThumbLY) ;
		fRXPos = (xController1->GetState().Gamepad.sThumbRX) ;
		fRYPos = (xController1->GetState().Gamepad.sThumbRY) ;
		fRXC = fRXPos / 10;
		fRYC = fRYPos / 10;
		fLXC = fLXPos / 10;
		fLYC = fLYPos / 10;
  	GetCursorPos(&fPos);	
  	srand(time(0));
  	fRandR = rand() % 255;
  	fRandG = rand() % 255;
  	fRandB = rand() % 255;
  //	SetPixel(fDC,fX,fY,RGB(fRandR,fRandG,fRandB));
   for(int64_t fGenX = 1;fGenX <= 100; fGenX++)
   {
   	fX++;
   	SetPixel(fDC,fX,fY,RGB(fRandR,fRandG,fRandB));
   }
   for(int64_t fGenY = 1;fGenY <= 100; fGenY++)
   {
   	fY++;
   	SetPixel(fDC,fX,fY,RGB(fRandR,fRandG,fRandB));
   }
   if(GetAsyncKeyState(XBUTTON2))
   {
    fX = fPos.x;
    fY = fPos.y;
   }
   if(GetAsyncKeyState(XBUTTON2))
   {
    r++;
   }
   if(GetAsyncKeyState('4'))
   {
   	system("cls");
   for(int64_t fRandomVec = 1;fRandomVec > 0;fRandomVec++)
   {
   	ofstream fRenderList("ConGLRender.log");
   	fRenderList.is_open();
   	fRenderList<<"[ENGINE][X = "<<fX<<" : Y = "<<fY<<"]"<<"ColorREF = "<<RGB(fRandR,fRandG,fRandB)<<"[R("<<fRandR<<"),G("<<fRandG<<"),B("<<fRandB<<")]\n";
   	if(!fRenderList.is_open())
   	{
   		cout<<"Error Create Log file!!"<<endl;
	}
  	SetWindowText(hWin,":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: 3DVectorsEngine ::::::::::::::::::::: Build 0.8 ::::::::::::::::::::::::::::::::::::");
   	 //srand(time(0));
   	 if(!fUnitMain)
  {
  	cout<<" Ooops!! Out of memory!! Stack = "<<&fUnitMain<<endl;
  }
   		fY = rand() % fScreenX;
   	    fX = rand() % fScreenY;
   	    fScreenX = 1920;
   	    fScreenY = 1080;
  	    fRandR = rand() % 255;
  	    fRandG = rand() % 255;
  	    fRandB = rand() % 255;
   	    SetPixel(fDC,fX,fY,RGB(fRandR,fRandG,fRandB));
   	    if(GetAsyncKeyState(VK_ESCAPE))
   	    {
   	    	fRenderList.close();
   	    	fRandomVec = -1;
		}
		if(GetAsyncKeyState(VK_RBUTTON))
		{
			fScreenX = fScrX[fScreenSelX++];
			fScreenY = fScrY[fScreenSelY++];
		}
   }
   }
    if(GetAsyncKeyState(VK_UP))
   {
    r++;
   }
   if(GetAsyncKeyState(VK_DOWN))
   {
    g++;
   }
   if(GetAsyncKeyState(VK_LEFT))
   {
    b++;
   }
   if(GetAsyncKeyState('R')){system("cls");}
  }
  
}
