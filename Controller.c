#include "Definition.h"

Controller* newController(void){

	Controller* this = NULL;
	this = (Controller*)malloc(sizeof(Controller));
	if (this == NULL) exit(EXIT_FAILURE);

	(*this).point = NULL;
	(*this).x = 0;
	(*this).y = 0;

	//(*this).createFan = &createFan;
	(*this).getPointOfController = &getPointOfController;
	(*this).setPointOfController = setPointOfController;
	(*this).judgeButton = judgeButton;
	(*this).updateEvent = updateEvent;

	//クリック判定
    hgevent *event;

	(*this).event = event;

	return this;
}

Point getPointOfController(Controller* this){
	Point aPoint = {0,0};
	return aPoint;
}

void setPointOfController(Controller* this){

	return;
}

void judgeButton(Controller* this){

	return;
}

void updateEvent(Controller* this){
	double clickx, clicky;
	//クリック判定
	HgSetEventMask(HG_MOUSE_DOWN);
	(*this).event = HgEventNonBlocking();
	if((*this).event != NULL) {
		clickx=(*this).event->x;
		clicky=(*this).event->y;
		printf("x=%5.2f, y=%5.2f\n", clickx, clicky);
	}
	return;
}