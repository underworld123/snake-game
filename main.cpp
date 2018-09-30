#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x,y,fruitX,fruitY,score;
int tailX[20],tailY[20];
int tail_len;
enum eDirection{ STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
void setup(){
    gameOver=false;
    dir = STOP;
    x=width / 2;
    y=height/ 2;
    fruitX = (rand())%width+5;
    fruitY = (rand())%height+1;
    score=0;
}
void Draw(){
    system("cls");
    int i,j;
    //upper border
    for(i=0;i<width+2;i++){
        cout<<"#";
    }
    cout<<endl;
    //loading map side border
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            if(j==0) 
              cout<<"#";
            if(i==y&&j==x){
                //printing snake body
                cout<<"O";
            }
            else if(i==fruitY&&j==fruitX){
				cout<<"F";
            }
            else {
            	bool print=false;
            	for(int k=0;k<tail_len;k++){
            		if(tailX[k]==j&&tailY[k]==i){
            			cout<<"o";
            			print=true;
					}
				}
				if(print==false)
            	cout<<" ";
			}
            if(j==width-1) cout<<"#";
        }
        cout<<endl;
    }
    //lower border
    for(i=0;i<width+2;i++){
        cout<<"#";
    }
    cout<<endl;
}
void Input(){
	//check which key is pressed
	//w=up; 
	if(_kbhit()){
		switch (_getch()){
			case 'a': dir = LEFT;
				break;
			case 'd': dir = DOWN;
				break;
			case 'w': dir = UP;
				break;
			case 's': dir = RIGHT;
				break;
			case 'x': gameOver = true;
				break;
		}
	}

}
void Logic(){
	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X, prev2Y, i;
	tailX[0]=x;
	tailY[0]=y;
	for(i=1;i<tail_len;i++){
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
	switch(dir){
		case LEFT: x--;
			break;
		case RIGHT: x++;
			break;
		case UP: y--;
			break;
		case DOWN: y++;
			break;
		default :
			break;
	}
	if(x>width||x<0||y<0||y>height){
		gameOver=true;
	}
	
	/*
	For a proper implementation we should add this
	for fun we can ignore
	for(i=0;i<tail_len;i++){
		if(tailX[i]==x||tailY[i]==y){
			gameOver=true;
		}
	}
	*/
	
	if(x==fruitX&&y==fruitY){
		score+=10;
		fruitX = (rand())%width;
    	fruitY = (rand())%height;
    	tail_len++;
	}
}
int main(){
    setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        cout<<"Score:  "<<score<<endl;
        Sleep(80); //it will slow our game
        //can be used to control the speed of snake
    }
    return 0;
}
