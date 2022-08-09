#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<handy.h>

#define WINDOWSIZEx 600
#define WINDOWSIZEy 600

/*Mainメソッド*/
int main(void);



/*Point構造体*/
typedef struct point{
	double x;
	double y;
}Point;

/*Fan構造体*/
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

	void (*fanSetup)(struct fan*, double, double, double, double, double, double, int, int, int, double, double, int);
	void (*judgeFan)(struct fan*, struct View*);
	void (*stringDraw)(struct fan*, int);
	void (*fan_blade)(struct fan*, int);
	void (*fan_body)(struct fan*);
	void (*fan_cover)(struct fan*, int);
	double (*rotation_x)(struct fan*, double, double, double);
	double (*rotation_y)(struct fan*, double, double, double, double, double);
	void (*button_judge)(struct fan*, int, Point*);
	void (*spin_fan_judge)(struct fan*);

} Fan;


/*風鈴構造体*/
typedef struct bell{
    //風鈴のガラスの部分
    double* bellx;

    double* belly;
    double bellr;

    //風鈴の長方形の部分
    double* line_under_bell;
    double* box_under_bell;

    double* line_up_bell;
    double* bell_main;

    double bell_str_x;
    double* bell_str_y;
    //長方形の部分を動かす量
    double move;
    //フラグ
    int bell_flag;

	void (*bellSetup)(struct bell*);
	double (*bell_rotation_x)(double, double, int);
	double (*bell_rotation_y)(double, double, int);
	void (*wide_bell_Draw)(struct bell*, int);
	void (*move_bell)(struct bell*, Fan*, int);


}Bell;


/*Model構造体*/
typedef struct model{
	struct Controller* controller;
	Point point;
	int power;
	int faceFanBellFlag;


	Point* (*getPoint)(struct model*);
	void (*setPoint)(struct model*);
	void (*setPower)(struct model*);
	void (*mathFanToBell)(struct model*);
	void (*setSoundDate)(struct model*);
	double* (*getSoundDate)(struct model*);

}Model;

/*View構造体*/
typedef struct view
{
	struct Controller* controller;
	Model* model;
	Point* point;
	int power;
	int sound;
	int windowid;
	int bladelayerid;

	int fancoverlayerid;
	int strlayerid;
	int wide_bell_layerid;
	int fanbodylayerid;



	Fan* (*createFan)(struct view*);
	Bell* (*createBell)(struct view*);
	void (*soundFan)(struct view*);
	void (*soundBell)(struct view*);
	void (*processJob)(struct view*, Fan*, Bell*);
} View;

/*Controller構造体*/
typedef struct controller
{
	Point* point;
	double x;
	double y;
	hgevent* event;

	Point (*getPointOfController)(struct controller*);
	void (*setPointOfController)(struct controller*);
	void (*updateEvent)(struct controller*);

} Controller;

/*扇風機メソッド*/
Fan* newFan(void);
void fanSetup(Fan*, double, double, double, double, double, double, int, int, int, double, double, int);
void judgeFan(Fan*, View*);
void stringDraw(Fan*, int);
void fan_blade(Fan*, int);
void fan_body(Fan*);
void fan_cover(Fan*, int);
double rotation_x(Fan*, double, double, double);
double rotation_y(Fan*, double, double, double, double, double);
void button_judge(Fan*, int, Point*);
void spin_fan_judge(Fan*);

/*風鈴メソッド*/
Bell* newBell(void);
void bellSetup(Bell*);
double bell_rotation_x(double, double, int);
double bell_rotation_y(double, double, int);
void wide_bell_Draw(Bell*, int);
void move_bell(Bell*, Fan*, int);

/*Modelメソッド*/
Model* newModel(Controller*);
Point getPoint(Model*);
void setPoint(Model*);
void setPower(Model*);
void mathFanToBell(Model*);
void setSoundDate(Model*);
double getSoundDate(Model*);

/*Viewメソッド*/
View* newView(Controller*, Model*);
Fan* createFan(View*);
Bell* createBell(View*);
void setModel(View*);
void setController(View*, Controller*);
void moveFan(View*);
void moveBell(View*);
void soundFan(View*);
void soundBell(View*);
void processJob(View*, Fan*, Bell*);

/*Controllerメソッド*/
Controller* newController(void);
Point getPointOfController(Controller*);
void setPointOfController(Controller*);
void updateEvent(Controller*);
