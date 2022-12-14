/*
自由制作
handy_fan.c
HgGraphicを使って扇風機と風鈴のアニメーションを作る。
扇風機の回る強さを変えたり、方向を変えるなどする事ができる。(実際の扇風機を再現した)
また、風鈴を横に置き、扇風機が風鈴の方向に向くと、風鈴が風で、押されていることを再現した。強さによっても変わる。
＜参考文献＞Handy Graphicユーザーズガイド、http://www7a.biglobe.ne.jp/~ogihara/Hg/products/guide0.64.pdf
//######＜訂正箇所＞ドッドエディタのように、ボタンの条件を配列を使ってまとめる。

また、このプログラムは、1回生の基礎プログラミング演習の自由制作で作成したプログラムに対して、
初学者から玄人が行うようなプログラムに変更した。
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
	Fan* aFan = (*aView).createFan(aView);
	Bell* aBell = (*aView).createBell(aView);
	
	Sound* aSound = (*aModel).sound;
	HgSoundPlay((*aSound).outSound);
	HgSoundVolume((*aSound).outSound, 15.0, 100);

	
	//アニメーション処理開始します。
	while(1){
		//マウスイベント
		(*aController).updateEvent(aController);

		//主に風鈴、扇風機の処理を行います。
		(*aView).processJob(aView, aFan, aBell);

		HgSleep(0.1);

	}

	free(aController);
	free(aModel);
	free(aView);
	

    HgGetChar();
    HgClose();

	return EXIT_SUCCESS;
}
