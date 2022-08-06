#include "Definition.h"

Model* newModel(Controller* aController){
	Model* this = NULL;
	this = malloc(sizeof(Model));
	if (this == NULL) exit(EXIT_FAILURE);

	(*this).controller = aController;
	return NULL;
}

Point getPoint(Model* this){


}

Point setPoint(Model* this){

}

void setPower(Model* this){

}

void mathFanToBell(Model* this){

}

void setSoundDate(Model* this){

}

double getSoundDate(Model* this){

}