#include "graphicsWrapper.h"
#include "base.h"
#include "scheme.h"
#include "file.h"

_DECLARE_LYCODE

#include "init.h"

void gw::draw() {
	window->clear(sf::Color::White);
	gw::drawString(0, 17*textSize, Editor.getCursorPos());
	for (int i = 0; i < Editor.getLineCount(); i++) {
		gw::drawString(0, i*textSize, Editor.getLine(i));
	}
	gw::clearScreen(sf::Color::White);
}



