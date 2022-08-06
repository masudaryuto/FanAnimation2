#include "Definition.h"

View* newView(Controller* aController, Model* aModel){
	View* this = NULL;
	this = (View*)malloc(sizeof(View));
	if (this == NULL) exit(EXIT_FAILURE);

	(*this).controller = aController;
	(*this).model = aModel;
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

	Fan fan = fanSetup(WINDOWSIZEx / 2, 5 * WINDOWSIZEy / 9, 120, 120, 40, 40, 1, 1, 0, 1, 0, 0);
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
    
	//window表示
	int windowid = HgWOpen(300, 100, WINDOWSIZEx, WINDOWSIZEy);
    //羽のレイヤ
    int bladelayerid = HgWAddLayer(windowid);
    //fanの頭のレイヤ
    int fancoverlayerid = HgWAddLayer(windowid);
    //fanの体のレイヤ
    int fanbodylayerid = HgWAddLayer(windowid);
    //文字列のレイヤ
    int strlayerid = HgWAddLayer(windowid);
    //風鈴のレイヤ
    int wide_bell_layerid = HgWAddLayer(windowid);
	

    //文字列描写
    stringDraw(strlayerid, fan);
    //羽の描写
    fan_blade(bladelayerid, fan, bell);
    //fanの体の部分
    fan_body( fan );
    //fanの頭の部分(網)の描写
    fan_cover(fancoverlayerid, fan);
    //風鈴の描写
    wide_bell_Draw(wide_bell_layerid, bell);









	/*
	//頭
	double head_r = 100.0;
	HgWCircle(windowid, WINDOWSIZEx/2, WINDOWSIZEy/2, head_r);
	HgWCircle(windowid, WINDOWSIZEx/2, WINDOWSIZEy/2, 10);

	//首
	HgWLine(windowid, (WINDOWSIZEx/2)+10, WINDOWSIZEy/2,  (WINDOWSIZEx/2)+15, 100);
	HgWLine(windowid, (WINDOWSIZEx/2)-10, WINDOWSIZEy/2,  (WINDOWSIZEx/2)-15, 100);

	//体
	HgWOval(windowid, (WINDOWSIZEx/2), 100, WINDOWSIZEx/5, WINDOWSIZEy/8, 0);
	HgWOval(windowid, WINDOWSIZEx/2, 100, 15, 5, 0);

	//羽
	double blade_x1[3] = {WINDOWSIZEx/2, 10+(head_r/2) + WINDOWSIZEx/2 ,10 + (WINDOWSIZEx/2) - (head_r/2)};
	double blade_y1[3] = {WINDOWSIZEy/2, (WINDOWSIZEy/2)+head_r-20, (WINDOWSIZEy/2)+head_r-20};
	HgPolygon(3, blade_x1, blade_y1);

	
	//ボタン
	int buttonlayerid = HgWAddLayer(windowid);
	//切
	HgWSetColor(buttonlayerid, HG_RED);
	HgWSetFillColor(buttonlayerid, HG_RED);
	HgWOvalFill(buttonlayerid, 250, 60, 15, 15, 0, 1);

	//弱
	HgWSetColor(buttonlayerid, HG_BLUE);
	HgWSetFillColor(buttonlayerid, HG_BLUE);
	HgWOvalFill(buttonlayerid, 285, 60, 15, 15, 0, 1);
	//中
	HgWSetColor(buttonlayerid, HG_BLUE);
	HgWSetFillColor(buttonlayerid, HG_BLUE);
	HgWOvalFill(buttonlayerid, 320, 60, 15, 15, 0, 1);
	//強
	HgWSetColor(buttonlayerid, HG_BLUE);
	HgWSetFillColor(buttonlayerid, HG_BLUE);
	HgWOvalFill(buttonlayerid, 355, 60, 15, 15, 0, 1);*/

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
