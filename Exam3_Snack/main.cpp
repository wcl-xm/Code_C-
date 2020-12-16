//
// Created by 夏木 on 20/10/27.
//
#include<iostream>
#include <graphics.h>
#include <cmath>
#include <ctime>
#include <conio.h>
#define OK 1
#define SCR_WIDTH 800 //屏幕宽度
#define SCR_HEIGHT 800//屏幕高度
using namespace std;
typedef struct {
	int x;
	int y;
	int r;
} ElemType;

typedef struct {
	ElemType elem;
} Food;

typedef struct QNode {
	ElemType elem;
	QNode *next;
} QNode,*QueuePtr;

typedef struct {
	QueuePtr front,rear;
	int len;
	int dir;
	int vx,vy;
	int r;
} Snake;

MUSIC bgMusic;
PIMAGE bjImg;
void Init_jiemian() {
	initgraph(SCR_WIDTH,SCR_HEIGHT,0);//初始化界面大小
	setcaption("沙碧蛇");
	setcolor(EGERGB(255,0,0));//EGERGB(255,0,0) 红色
	setfillcolor(WHITE);//	白色
	//bjImg = newimage();
	//getimage(bjImg, "img\\background.png");
	bgMusic.OpenFile("./bjmusic.mp3");
	bgMusic.SetVolume(1.0f);
	if (bgMusic.IsOpen()) {
		bgMusic.Play(0);
	}
}

Snake Init_Snake() {  
	Snake Q;
	Q.front = Q.rear = new QNode;
	int hight=400,width=300;
	Q.len = 3;
	Q.dir = 4;
	Q.vx = 5;
	Q.vy = 0;
	Q.r = 5;
	for(int i = 0; i<Q.len; i++) {
		width+=10;
		QueuePtr s = new QNode;
		s->next = 0;
		s->elem.x = width;
		s->elem.y = hight;
		Q.rear->next = s;
		Q.rear = s;
	}
	return Q;
}

int Food_NUM=0;
Food Produce_Food(Snake Q) {
	Food food;
	srand((unsigned int)time(NULL));
	if(Food_NUM<1) {
		QueuePtr p = Q.front->next;
		int InBody = 1;
		food.elem.x = rand()%(SCR_WIDTH-1)+1;
		food.elem.y = rand()%(SCR_HEIGHT-1)+1;
		while(InBody) {
			while(p) {
				if(food.elem.x==p->elem.x&&food.elem.y==p->elem.y) {
					food.elem.x = rand()%(SCR_WIDTH-5)+5;
					food.elem.y = rand()%(SCR_HEIGHT-5)+5;
				}
				p = p->next;  
			}
			InBody = 0;
		}
		Food_NUM+=1;
	}
	return food;
}

int Eat_Food(Snake &Q,Food &food) {
	int jlx,jly;
	jlx= Q.rear->elem.x-food.elem.x;
	jly= Q.rear->elem.y-food.elem.y;
	if(jlx*jlx<=100&&jly*jly<=100) {
		food.elem.x=-5;
		food.elem.y=-5;
		Q.len++;
		Food_NUM-=1;
		return 1;
	}
	return 0;
}

int Move(Snake &Q,Food &food) {
	if(Q.rear->elem.x<0||Q.rear->elem.x>SCR_WIDTH||Q.rear->elem.y<0||Q.rear->elem.y>SCR_HEIGHT) {
		cout<<"菜鸡";
		exit(0);
	}
	QueuePtr s,p;
	s = new QNode;
	s->elem.x =Q.rear->elem.x + Q.vx;
	s->elem.y =Q.rear->elem.y + Q.vy;
	s->next = 0;
	Q.rear->next = s;
	Q.rear = s;
	if(!Eat_Food(Q,food)) {
		p = Q.front->next;
		Q.front->next = p->next;
		delete p;
	}
	return 1;
}


void Move_Dir(Snake &Q) {
	if(kbhit()) {
		char ch=getch();
		switch (ch) {
			case 40:
				if(Q.dir!=2) {
					Q.dir=1;
					Q.vx=0,Q.vy=5;
				}
				break;
			case 38:
				if(Q.dir!=1) {
					Q.dir=2;
					Q.vx=0,Q.vy=-5;
				}
				break;
			case 37:
				if(Q.dir!=4) {
					Q.dir=3;
					Q.vx=-5,Q.vy=0;
				}
				break;
			case 39:
				if(Q.dir!=3) {
					Q.dir=4;
					Q.vx=5,Q.vy=0;
				}
				break;
		}
	}
}

void Show(Snake Q,Food food) {
	setfillcolor(BLUE);
	fillellipse(food.elem.x,food.elem.y,10,10);
	QueuePtr p = Q.front->next;
	for(int i = 0; i<Q.len; i++,p = p->next) {//绘制蛇身
		setfillcolor(WHITE);
		fillellipse(p->elem.x,p->elem.y,Q.r,Q.r);
	}
}

int main() {
	Init_jiemian();
	Snake Q = Init_Snake();
	for(; is_run(); delay_fps(60)) {
		cleardevice();
		Food food=Produce_Food(Q);
		Move(Q,food);
		Move_Dir(Q);
		Show(Q,food);
	}
	getch();//等待用户按键
	closegraph();//关闭图形界面
	return 0;
}