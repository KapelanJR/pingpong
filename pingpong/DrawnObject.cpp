#include "pch.h"
#include "DrawnObject.h"
#include "Game.h"

template <typename T> DrawnObject<T>::DrawnObject(T* obj) : dObject(obj) {
	sendDrawObject();
}

template <typename T> void DrawnObject<T>::sendDrawObject() {
	Game::addDrawableObjectToDrawVector(dObject);
}
template <typename T> void DrawnObject<T>::deleteDrawObject() {
	Game::deleteDrawableObjectFromDrawVector(dObject);
}

template <typename T> DrawnObject<T>::~DrawnObject() {
	deleteDrawObject();
	delete dObject;
}

template class DrawnObject<sf::CircleShape>;
template class DrawnObject<sf::ConvexShape>;
template class DrawnObject<sf::RectangleShape>;
template class DrawnObject<sf::Shape>;
template class DrawnObject<sf::Sprite>;
template class DrawnObject<sf::Text>;
template class DrawnObject<sf::VertexArray>;
template class DrawnObject<sf::VertexBuffer>;
