#include<stdio.h>
#include<stdlib.h>
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

	void (*createFan)(void);
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

	Point* (*getPointOfController)(struct controller);
	void (*setPointOfController)(struct controller);
	void (*judgeButton)(struct controller);

} Controller;


/*Model*/
Model* newModel(void);
Point* getPoint(Model*);
Point* setPoint(Model*);
void setPower(Model*);
void mathFanToBell(Model*);
void setSoundDate(Model*);
double getSoundDate(Model*);

/*View*/
View* newView(void);
void createFan(void);
void createBell(View*);
void setModel(View*);
void setController(View*);
void moveFan(View*);
void moveBell(View*);
void soundFan(View*);
void soundBell(View*);

/*Controller*/
Controller* newController(void);
Point* getPointOfController(Controller*);
void setPointOfController(Controller*);
void judgeButton(Controller*);
