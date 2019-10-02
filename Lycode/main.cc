#include "ly\renderer.h"
#include "ly\base.h"
#include "ly\input.h"

graphicsWrapper graphics;

using namespace lycode;

int main() {
	graphics.init(800, 600, "This works", false);
	return 0;
}