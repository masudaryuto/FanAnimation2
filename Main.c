/*
自由制作
handy_fan.c
HgGraphicを使って扇風機と風鈴のアニメーションを作る。
扇風機の回る強さを変えたり、方向を変えるなどする事ができる。(実際の扇風機を再現した)
また、風鈴を横に置き、扇風機が風鈴の方向に向くと、風鈴が風で、押されていることを再現した。強さによっても変わる。
＜参考文献＞Handy Graphicユーザーズガイド、http://www7a.biglobe.ne.jp/~ogihara/Hg/products/guide0.64.pdf
//######＜訂正箇所＞ドッドエディタのように、ボタンの条件を配列を使ってまとめる。
*/

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
	//(*aView).createBell(aView);
	

	while(1){
		//マウスイベント
		(*aController).updateEvent(aController);
		//(*aView).setController(aView, aController);
		//(*aController).setPointOfController(*aController);
		HgSleep(0.5);

		(*aView).processJob(aView);

	}

	free(aController);
	free(aModel);
	free(aView);
	

    HgGetChar();
    HgClose();

	return EXIT_SUCCESS;
}
