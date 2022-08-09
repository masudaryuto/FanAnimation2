#include "Definition.h"

/*Modelのメモリを確保します。*/
Model* newModel(Controller* aController){
	Model* this = NULL;
	this = (Model*)malloc(sizeof(Model));
	if (this == NULL) exit(EXIT_FAILURE);

	Sound* aSound = NULL;
	aSound = (Sound*)malloc(sizeof(Sound));
	if (aSound == NULL) exit(EXIT_FAILURE);

	(*this).sound = aSound;
	(*this).controller = aController;
	(*this).point = *(*aController).point;
	(*this).power = 0;
	(*this).faceFanBellFlag = 0;

	(*this).getPoint = &getPoint;
	(*this).setPoint = setPoint;
	(*this).setSoundDate = setSoundDate;
	(*this).getSoundDate = getSoundDate;

	(*this).setSoundDate(this);
	
	return this;
}

/* 座標を返します。*/
Point getPoint(Model* this){
	Controller* aController = ((*this).controller);
	
	
	return *(*aController).point;
}

/*座標をコントローラから受け取ります。*/
void setPoint(Model* this){
	Controller* aController = ((*this).controller);


	(*this).point = *(*aController).point;

	return;
}



/*音データを設定します。*/
void setSoundDate(Model* this){
	Sound* aSound = (*this).sound;

	(*aSound).highFanSound = HgSoundLoad("./Sounds/High.mp3");
	(*aSound).highFanFlag = 0;

	(*aSound).middleFanSound = HgSoundLoad("./Sounds/Mid.mp3");
	(*aSound).middleFanFlag = 0;

	(*aSound).weakFanSound = HgSoundLoad("./Sounds/Low.mp3");
	(*aSound).weakFanFlag = 0;

	(*aSound).bellSound =  HgSoundLoad("./Sounds/BellSound.mp3");
	(*aSound).bellFlag = 0;

	(*aSound).buttonSound = HgSoundLoad("./Sounds/ButtonSound.mp3");
	(*aSound).buttonFlag = 0;

	(*aSound).outSound = HgSoundLoad("./Sounds/OutSound.mp3");
	(*aSound).outSound = 0;

	(*this).sound = aSound;
	return;
}

/*音データを渡します。*/
double getSoundDate(Model* this){

	return 0.0;
}
