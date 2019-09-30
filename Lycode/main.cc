#include "renderer.h"
#include "base.h"
#include "input.h"

graphicsWrapper graphics;

using namespace lycode;

int main() {
	graphics.init(800, 600, "This works", false);
	return 0;
}