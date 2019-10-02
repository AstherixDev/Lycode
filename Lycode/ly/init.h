#pragma once
#include "graphicsWrapper.h"
#include "ly\file.h"

_DECLARE_LYCODE

sf::Font* pFont = nullptr;
const int textSize = 32;

void gw::onClose() {
	window->close();
}

void gw::setup() {
	#ifndef _LYCODE_LOG_CONSOLE
		gw::hideConsole();
	#else
		gw::showConsole();
	#endif
	file _File1("test.cc");
	gw::setTextColor(0, 0, 0);
	pFont = gw::initFont("UbuntuMonoRegular.ttf", textSize);
}