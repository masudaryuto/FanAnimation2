#include "Definition.h"

View* newView(Controller* aController, Model* aModel){
	View* this = NULL;
	this = (View*)malloc(sizeof(View));
	if (this == NULL) exit(EXIT_FAILURE);



	(*this).controller = aController;
	(*this).model = aModel;
	(*this).point = NULL;
	(*this).power = 0;
	(*this).sound = 0;
	(*this).windowid = 0;

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

void processJob(View* this, Controller* aController){
	
	
	printf("x=%5.2f, y=%5.2f\n", (*aController).x, (*aController).y);
	
	return;
}





void createFan(View* this){

	Fan fan = fanSetup(WINDOWSIZEx / 2, 5 * WINDOWSIZEy / 9, 120, 120, 40, 40, 1, 1, 0, 1, 0, 0);

	//window表示
	(*this).windowid = HgWOpen(300, 100, WINDOWSIZEx, WINDOWSIZEy);
	
    //羽のレイヤ
    int bladelayerid = HgWAddLayer((*this).windowid);
    //fanの頭のレイヤ
    int fancoverlayerid = HgWAddLayer((*this).windowid);
    //fanの体のレイヤ
    int fanbodylayerid = HgWAddLayer((*this).windowid);
    //文字列のレイヤ
    int strlayerid = HgWAddLayer((*this).windowid);

	

    //文字列描写
    stringDraw(strlayerid, fan);
    //羽の描写
    fan_blade(bladelayerid, fan);
    //fanの体の部分
    fan_body(fan);
    //fanの頭の部分(網)の描写
    fan_cover(fancoverlayerid, fan);
	

	return;
}


void createBell(View* this){
	Bell bell = { {2 * WINDOWSIZEx / 9 - 50 * cos(M_PI/3), 2 * WINDOWSIZEx / 9 + 50 * cos(M_PI/3), 2 * WINDOWSIZEx / 9}, //bellx[3]
		{7 * WINDOWSIZEy / 8 - 50 * sin(M_PI/3), 7 * WINDOWSIZEy / 8 - 50 * sin(M_PI/3), 7 * WINDOWSIZEy / 8}, //belly[3]
		50,                                                                                  //bellr
		{2 * WINDOWSIZEx / 9, 7 * WINDOWSIZEy / 8 + 50, 2 * WINDOWSIZEx / 9, 6 * WINDOWSIZEy / 8},          //line_under_bell[4]
		{2 * WINDOWSIZEx / 9 - 50 * cos(M_PI/3), WINDOWSIZEy / 2, 2 * 50*cos(M_PI/3), 6 * WINDOWSIZEy / 8 - WINDOWSIZEy / 2},//box_under_bell[5]
		{2 * WINDOWSIZEx / 9, 7 * WINDOWSIZEy / 8 + 50, 2 * WINDOWSIZEx / 9, WINDOWSIZEy},     //line_up_bell[4]
		{2 * WINDOWSIZEx / 9, 7 * WINDOWSIZEy / 8, 50, -M_PI / 3, 4 * M_PI / 3},              //bell_main[6]
		2 * WINDOWSIZEx / 9 - bell.bellr * cos(M_PI/3) + 17,                              //bell_str_x
		{(6 * WINDOWSIZEy / 8) - 30 * (0 + 1), (6 * WINDOWSIZEy / 8) - 30 * (1 + 1), (6 * WINDOWSIZEy / 8) - 30 * (2 + 1), (6 * WINDOWSIZEy / 8) - 30 * (3 + 1), (6 * WINDOWSIZEy / 8) - 30 * (4 + 1)}, //bell_str_y
		0.0,
		0};//move

	//風鈴のレイヤ
    int wide_bell_layerid = HgWAddLayer((*this).windowid);
    //風鈴の描写
    wide_bell_Draw(wide_bell_layerid, bell);

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
