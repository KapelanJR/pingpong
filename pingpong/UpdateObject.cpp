#include "pch.h"
#include "UpdateObject.h"
#include "Game.h"

UpdateObject::UpdateObject() {
	sendUpdateObject();
}

void UpdateObject::getElapsedTime() {
	elapsedTime = Game::getElapsedTime();
}

void UpdateObject::sendUpdateObject() {
	Game::getUpdateVector()._add(this);
}

void UpdateObject::deleteUpdateObject() {
	Game::getUpdateVector()._delete(this);
}

UpdateObject::~UpdateObject() {
	deleteUpdateObject();
}


