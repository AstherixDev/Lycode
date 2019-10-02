#include "graphicsWrapper.h"
#include "ly\base.h"

using namespace lycode;

#define moveLeft  Editor.getLine().moveCursor(direction::left, 1);
#define moveRight Editor.getLine().moveCursor(direction::right, 1);
/*
#define moveUp    Editor.getCursor().move(direction::up   , 1);
#define moveDown  Editor.getCursor().move(direction::down , 1);
*/
void gw::onSpKey() {
	switch (gw::Key.kCode) {
		/*
		case sf::Keyboard::Up   : moveUp; break;
		case sf::Keyboard::Down : moveDown; break;
		*/
		case sf::Keyboard::Left : moveLeft; break;
		case sf::Keyboard::Right: moveRight; break;
		default:;
	}
}

void gw::onKey() {
	switch (gw::Key.kCode) {
		case 127: Editor.deleteChars(direction::right, 1); break;
		case 8  : Editor.deleteChars(direction::left, 1); break;
		case 13 : Editor.insertLine(); break;
		default : Editor.getLine().insertStr((char)gw::Key.kCode); break;
	}
}
