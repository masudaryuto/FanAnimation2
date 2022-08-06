#include "Definition.h"

/*
* 扇風機と風鈴のアニメーションを作成します。
*/
int main(void){

	View* aView = newView();
	(*aView).createFan(aView);

	while(1){
	
		break;

	}
    HgGetChar();
    HgClose();
	return EXIT_SUCCESS;
}

