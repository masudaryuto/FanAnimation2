#include "Definition.h"

/*
* 扇風機と風鈴のアニメーションを作成します。
*/
int main(void){
	//イベント発生
	Controller* aController = newController();
	Model* aModel = newModel(aController);
	View* aView = newView(aController, aModel);
	(*aView).createFan(aView);
	(*aView).createBell(aView);
	

	while(1){
		
		(*aController).updateEvent(*aController);

	}
    HgGetChar();
    HgClose();
	return EXIT_SUCCESS;
}
