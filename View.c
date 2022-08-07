#include "Definition.h"

View* newView(Controller* aController, Model* aModel){
	View* this = NULL;
	this = (View*)malloc(sizeof(View));
	if (this == NULL) exit(EXIT_FAILURE);

	Point* aPoint = NULL;
	aPoint = malloc(sizeof(Point));
	if (aPoint == NULL) exit(EXIT_FAILURE);


	/*
	Fan* aFan = NULL;
	aFan = malloc(sizeof(Fan));
	if (aFan == NULL) exit(EXIT_FAILURE);
	(*this).fan = aFan;
	aFan = malloc(sizeof(Fan));
	if (aFan == NULL) exit(EXIT_FAILURE);
	(*this).fan = aFan;
	Bell* aBell = NULL;
	aBell = malloc(sizeof(Bell));
	if (aBell == NULL) exit(EXIT_FAILURE);
	(*this).bell = NULL;
	(*this).fan = NULL;
	(*this).bell = NULL;
	*/


	(*this).controller = aController;
	(*this).model = aModel;
	(*this).point = aPoint;
	(*this).power = 0;
	(*this).sound = 0;
	(*this).windowid = 0;
	(*this).bladelayerid = 0;

	(*this).createFan = &createFan;
	(*this).createBell = &createBell;
	(*this).setModel = &setModel;
	(*this).setController = &setController;
	(*this).moveFan = &moveFan;
	(*this).moveBell = &moveBell;
	(*this).soundFan = &soundFan;
	(*this).soundBell = &soundBell;
	(*this).processJob = &processJob;


	return this;
}

void processJob(View* this, Fan* aFan){
	Model* aModel = (*this).model;
	Point* aPoint = (*aModel).getPoint(aModel);
	
	printf("x=%5.2f, y=%5.2f\n", (*aPoint).x, (*aPoint).y);
	
	//Fan* aFan = (*this).fan;
	//Fan* aFan = 
	(*aFan).fan_blade(aFan, (*this).bladelayerid);

	return;
}





Fan* createFan(View* this){
	Fan* aFan = newFan();

	(*aFan).fanSetup(aFan, WINDOWSIZEx / 2, 5 * WINDOWSIZEy / 9, 120, 120, 40, 40, 1, 1, 0, 1, 0, 0);

	//window表示
	(*this).windowid = HgWOpen(300, 100, WINDOWSIZEx, WINDOWSIZEy);
	
    //羽のレイヤ
    (*this).bladelayerid = HgWAddLayer((*this).windowid);
    //fanの頭のレイヤ
    int fancoverlayerid = HgWAddLayer((*this).windowid);
    //fanの体のレイヤ
    int fanbodylayerid = HgWAddLayer((*this).windowid);
    //文字列のレイヤ
    int strlayerid = HgWAddLayer((*this).windowid);

	

    //文字列描写
    (*aFan).stringDraw(aFan, strlayerid);
    //羽の描写
    (*aFan).fan_blade(aFan, (*this).bladelayerid);
    //fanの体の部分
    (*aFan).fan_body(aFan);
    //fanの頭の部分(網)の描写
    (*aFan).fan_cover(aFan, fancoverlayerid);

	

	return aFan;
}


void createBell(View* this){

	Bell* aBell = newBell();
	//(*aBell).bellSetup(aBell);
    //printf("%f\n",(*aBell).bell_str_y[0]);
	

	//風鈴のレイヤ
    int wide_bell_layerid = HgWAddLayer((*this).windowid);
    //風鈴の描写
    (*aBell).wide_bell_Draw(aBell, wide_bell_layerid);

	//*(*this).bell = bell;


	return;
}

void setModel(View* this){
	(*this).power = 1;

	return;
}
void setController(View* this, Controller* aController){
	
	(*this).controller = aController;

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
