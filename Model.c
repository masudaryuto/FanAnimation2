#include "Definition.h"

Model* newModel(Controller* aController){
	Model* this = NULL;
	this = malloc(sizeof(Model));
	if (this == NULL) exit(EXIT_FAILURE);

	(*this).controller = aController;
	(*this).point = *(*aController).point;
	(*this).power = 0;
	(*this).faceFanBellFlag = 0;

	(*this).getPoint = &getPoint;
	(*this).setPoint = setPoint;
	(*this).setPower = setPower;
	(*this).mathFanToBell = mathFanToBell;
	(*this).setSoundDate = setSoundDate;
	(*this).getSoundDate = getSoundDate;
	
	return this;
}

Point getPoint(Model* this){
	Controller* aController = ((*this).controller);
	
	
	return *(*aController).point;
}

void setPoint(Model* this){
	Controller* aController = ((*this).controller);


	(*this).point = *(*aController).point;

	return;
}

void setPower(Model* this){

}

void mathFanToBell(Model* this){

}

void setSoundDate(Model* this){

}

double getSoundDate(Model* this){

}
