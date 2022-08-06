#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<handy.h>

#define WINDOWSIZEx 600
#define WINDOWSIZEy 600



/*Main*/
int main(void);

/*Point*/
typedef struct point{
	double* x;
	double* y;
}Point;

/*Model*/
typedef struct model{
	struct Controller* controller;
	Point point;
	int power;
	int faceFanBellFlag;


	Point* (*getPoint)(struct model*);
	Point* (*setPoint)(struct model*);
	void (*setPower)(struct model*);
	void (*mathFanToBell)(struct model*);
	void (*setSoundDate)(struct model*);
	double* (*getSoundDate)(struct model*);

}Model;

/*View*/
typedef struct view
{
	struct Controller* controller;
	Model* model;
	Point* point;
	int power;
	int sound;
	int windowid;

	void (*createFan)(struct view*);
	void (*createBell)(struct view*);
	void (*setModel)(struct view*);
	void (*setController)(struct view*);
	void (*moveFan)(struct view*);
	void (*moveBell)(struct view*);
	void (*soundFan)(struct view*);
	void (*soundBell)(struct view*);
} View;

/*Controller*/
typedef struct controller
{
	Point* point;
	double x;
	double y;
	hgevent* event;

	Point (*getPointOfController)(struct controller);
	void (*setPointOfController)(struct controller);
	void (*judgeButton)(struct controller);
	void (*updateEvent)(struct controller);

} Controller;


/*Model*/
Model* newModel(Controller*);
Point getPoint(Model*);
Point setPoint(Model*);
void setPower(Model*);
void mathFanToBell(Model*);
void setSoundDate(Model*);
double getSoundDate(Model*);

/*View*/
View* newView(Controller*, Model*);
void createFan(View*);
void createBell(View*);
void setModel(View*);
void setController(View*);
void moveFan(View*);
void moveBell(View*);
void soundFan(View*);
void soundBell(View*);

/*Controller*/
Controller* newController(void);
Point getPointOfController(Controller*);
void setPointOfController(Controller*);
void judgeButton(Controller*);
void updateEvent(Controller*);



/*parts*/
//構造体
typedef struct fan{
    //扇風機の円
    double fancircle_x;
    double fancircle_y;
    double bigfancircle_r1;
    double bigfancircle_r2;
    //円の中の小さな円
    double smallfancircle_r1;
    double smallfancircle_r2;
    //フラグ
    int red_button_flag;
    //spin
    int spin_button_flag;
    //関数内で、首を回す判定で必要なフラグ
    int fan_face_flag;
    //HgSleepで速さを調節する。
    double add;
    //fanの回転カウント
    double counter;
    //プログラム終了フラグ
    int end_flag;


	//void (*stringDraw)(int, struct fan*);
} Fan;





//風鈴の構造体
typedef struct bell{
    //風鈴のガラスの部分
    double bellx[3];
    double belly[3];
    double bellr;

    //風鈴の長方形の部分
    double line_under_bell[4];
    double box_under_bell[4];

    double line_up_bell[4];
    double bell_main[5];

    double bell_str_x;
    double bell_str_y[5];
    //長方形の部分を動かす量
    double move;
    //フラグ
    int bell_flag;

}Bell;

/*扇風機*/
Fan fanSetup(double, double, double, double, double, double, int, int, int, double, double, int);
void stringDraw(int, Fan);
void fan_blade(int, Fan);
void fan_body(Fan);
void fan_cover(int, Fan);
void wide_bell_Draw(int, Bell);
double rotation_x(double, double, double);
double rotation_y(double, double, double, double, double);
