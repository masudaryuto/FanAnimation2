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
