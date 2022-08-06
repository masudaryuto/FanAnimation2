#include "Definition.h"

View* newView(void){

	View* this = NULL;

	this = (View*)malloc(sizeof(View));
	if (this == NULL) exit(EXIT_FAILURE);

	(*this).controller = NULL;
	(*this).model = NULL;
	(*this).point = NULL;
	(*this).power = 1;
	(*this).sound = 1;

	(*this).createFan = &createFan;
	(*this).createBell = &createBell;
	(*this).setModel = &setModel;
	(*this).setController = &setController;
	(*this).moveFan = &moveFan;
	(*this).moveBell = &moveBell;
	(*this).soundFan = &soundFan;
	(*this).soundBell = &soundBell;

	return this;
}

void createFan(void){
	
	//window表示
	int widowid = HgWOpen(300, 100, WINDOWSIZEx, WINDOWSIZEy);

	



	

	return;
}


void createBell(View* this){
	(*this).power = 1;

	return;
}
void setModel(View* this){
	(*this).power = 1;

	return;
}
void setController(View* this){
	(*this).power = 1;

	return;
}
void moveFan(View* this){
	(*this).power = 1;

	return;
}
void moveBell(View* this){
	(*this).power = 1;

	return;
}
void soundFan(View* this){
	(*this).power = 1;

	return;
}
void soundBell(View* this){
	(*this).power = 1;

	return;
}
