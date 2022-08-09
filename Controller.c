#include "Definition.h"

/* コントローラのメモリ確保を行います。 */
Controller* newController(void){

	Controller* this = NULL;
	this = (Controller*)malloc(sizeof(Controller));
	if (this == NULL) exit(EXIT_FAILURE);

	Point* aPoint = NULL;
	aPoint = (Point*)malloc(sizeof(Point));
	if (aPoint == NULL) exit(EXIT_FAILURE);

	(*aPoint).x = 0.0;
	(*aPoint).y = 0.0;
	(*this).point = aPoint;
	(*this).x = 0.0;
	(*this).y = 0.0;

	(*this).getPointOfController = &getPointOfController;
	(*this).setPointOfController = setPointOfController;
	(*this).updateEvent = &updateEvent;

	//クリック判定
    hgevent *event;

	(*this).event = event;

	return this;
}

/* クリックした画面の座標を返します。*/
Point getPointOfController(Controller* this){

	return *(*this).point;
}

/* Point座標へ変換します。 */
void setPointOfController(Controller* this){

	((*this).point)->x = (*this).x;
	((*this).point)->y = (*this).y;
	
	return;
}

/* クリックした位置を取得します。 */
void updateEvent(Controller* this){

	//クリック判定
	HgSetEventMask(HG_MOUSE_DOWN);
	(*this).event = HgEventNonBlocking();
	if((*this).event != NULL) {
		(*this).x = (*this).event->x;
		(*this).y = (*this).event->y;

		puts("click!");
	}
	else{
		(*this).x = 0.0;
		(*this).y = 0.0;
	}
	(*this).setPointOfController(this);

	return;
}
