#include "Definition.h"


/* Viewのメモリを確保します。 */
View* newView(Controller* aController, Model* aModel){
	View* this = NULL;
	this = (View*)malloc(sizeof(View));
	if (this == NULL) exit(EXIT_FAILURE);

	Point* aPoint = NULL;
	aPoint = (Point*)malloc(sizeof(Point));
	if (aPoint == NULL) exit(EXIT_FAILURE);

	(*this).controller = aController;
	(*this).model = aModel;
	(*this).point = aPoint;
	(*this).power = 0;
	(*this).sound = 0;
	(*this).windowid = 0;
	(*this).bladelayerid = 0;
	(*this).fancoverlayerid = 0;
	(*this).strlayerid = 0;
	(*this).wide_bell_layerid = 0;
	(*this).fanbodylayerid = 0;

	//メソッド
	(*this).createFan = &createFan;
	(*this).createBell = &createBell;
	(*this).soundFan = &soundFan;
	(*this).soundBell = &soundBell;
	(*this).processJob = &processJob;


	return this;
}

/* 描画処理を行います。*/
void processJob(View* this, Fan* aFan, Bell* aBell){
	Model* aModel = (*this).model;
	Point* aPoint = (*aModel).getPoint(aModel);
	Controller* aController = (*this).controller;
	
	//printf("x=%5.2f, y=%5.2f\n", (*aPoint).x, (*aPoint).y);
	
	//ボタン判定
	(*aFan).button_judge(aFan, (*this).strlayerid, aPoint);
	
	//扇風機の制御
	(*aFan).judgeFan(aFan, this);

	//風鈴の制御
	(*aBell).move_bell(aBell, aFan, (*this).wide_bell_layerid);

	return;
}

/* 扇風機を描画します。*/
Fan* createFan(View* this){
	Fan* aFan = newFan();

	(*aFan).fanSetup(aFan, WINDOWSIZEx / 2, 5 * WINDOWSIZEy / 9, 120, 120, 40, 40, 1, 1, 0, 1, 0, 0);

	//window表示
	(*this).windowid = HgWOpen(300, 100, WINDOWSIZEx, WINDOWSIZEy);
	
    //羽のレイヤ
    (*this).bladelayerid = HgWAddLayer((*this).windowid);
    //fanの頭のレイヤ
    (*this).fancoverlayerid = HgWAddLayer((*this).windowid);
    //fanの体のレイヤ
    (*this).fanbodylayerid = HgWAddLayer((*this).windowid);
    //文字列のレイヤ
    (*this).strlayerid = HgWAddLayer((*this).windowid);

	

    //文字列描写
    (*aFan).stringDraw(aFan, (*this).strlayerid);
    //羽の描写
    (*aFan).fan_blade(aFan, (*this).bladelayerid);
    //fanの体の部分
    (*aFan).fan_body(aFan);
    //fanの頭の部分(網)の描写
    (*aFan).fan_cover(aFan, (*this).fancoverlayerid);

	return aFan;
}

/* 風鈴を描画します */
Bell* createBell(View* this){
	Bell* aBell = newBell();
	(*aBell).bellSetup(aBell);

	//風鈴のレイヤ
    (*this).wide_bell_layerid = HgWAddLayer((*this).windowid);
    //風鈴の描写
    (*aBell).wide_bell_Draw(aBell, (*this).wide_bell_layerid);

	return aBell;
}

/* 扇風機の音を再現します。 */
void soundFan(View* this){
	(*this).power = 1;

	return;
}

/* 風鈴の音を再現します。 */
void soundBell(View* this){
	(*this).power = 1;

	return;
}
