#include "util.h"

class cursor {
	// The cursor's position
	vec2i _Pos = vec2i(0, 0);
	editor* Editor = nullptr;

public:
	cursor(editor* Editor) : Editor(Editor) { }

	[[ deprecated ]] inline void move(vec2i _Npos, bool _Absolute = true) {
		if (_Absolute) {
			this->_Pos = _Npos;
		}
		else {
			this->_Pos += _Npos;
		}
	}

	inline void move(int _Where, int _Count = 1) {
		/*switch (_Where) {
			case direction::up   : 
				if (this->_Pos.y > 0) { 
					--this->_Pos.y; 
					this->_Pos.x = this->_Pos.x > Editor->getLine(this->_Pos.y).size() ? Editor->getLine(this->_Pos.y).size() : this->_Pos.x;
				} 
			break;
			case direction::down : 
				if (this->_Pos.y+1 < Editor->lineCount()) { 
					++this->_Pos.y;
					this->_Pos.x = this->_Pos.x > Editor->getLine(this->_Pos.y).size() ? Editor->getLine(this->_Pos.y).size() : this->_Pos.x;
				} 
			break;
			case direction::left : if (this->_Pos.x > 0) { 
				--this->_Pos.x; 
			}
			else {
				if (this->_Pos.y > 0) {
					--this->_Pos.y;
					this->_Pos.x = Editor->getLine(this->_Pos.y).size();
				}
			}
			break;
			case direction::right: if (this->_Pos.x < Editor->getLine(this->_Pos.y).size()) {
				++this->_Pos.x;
			} else {
				if (this->_Pos.y+1 < Editor->lineCount()) {
					++this->_Pos.y;
					this->_Pos.x = 0;
				}
			}
			break;
		}*/
	}

	inline void resetX() { this->_Pos.x = 0; }

	inline vec2i& getPosition() { return this->_Pos; }
};