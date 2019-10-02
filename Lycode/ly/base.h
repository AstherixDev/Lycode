#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include "ly\util.h"

#define l this->_Pos.y
#define c this->_Pos.x

const vec2i _defaultPos = vec2i(-1, -1);

namespace moveMode {
	constexpr bool Absolute = true, Relative = false;
}

namespace direction {
	constexpr int up = 0, down = 1, left = 2, right = 3;
}

namespace lycode {
	class splitBuffer {
		std::vector <char> _Left, _Right;

	public:
		splitBuffer(std::vector <char> _Left  = {}, 
					std::vector <char> _Right = {}) {
			this->_Left  = _Left;
			this->_Right = _Right;
		}
		inline void insertStr(std::string _Str, int _Where = direction::left) {
			switch (_Where) {
				case direction::left:
					for (char _Char : _Str) {
						this->_Left.push_back(_Char);
					}
				break;
				case direction::right:
					for (char _Char : _Str) {
						this->_Right.insert(this->_Right.begin(), _Char);
					}
				break;
			}
		
		}

		inline void insertStr(char _Char) {
			this->_Left.push_back(_Char);
		}

		inline void deleteChars(int _Where, int _Count) {
			switch (_Where) {
				case direction::left:
					while(_Count--) {
						if (_Left.size()) {
							_Left.pop_back();
						} else { break; }
					}
				break;
				case direction::right:
					while(_Count--) {
						if (_Right.size()) {
							_Right.pop_back();
						} else { break; }
					}
				break;
			}
		}

		inline void moveCursor(int _Where, int _Count) {
			switch (_Where) {
				case direction::left:
					while(_Count--) {
						if (_Left.size()) {
							_Right.push_back(_Left.back());
							_Left.pop_back();
						} else { break; }
					}
				break;
				case direction::right:
					while(_Count--) {
						if (_Right.size()) {
							_Left.push_back(_Right.back());
							_Right.pop_back();
						} else { break; }
					}
				break;
			}
		}

		inline void moveToEdge(int _Which) {
			switch (_Which) {
				case direction::left:
					while (_Left.size()) {
						_Right.push_back(_Left.back());
						_Left.pop_back();
					}
				break;
				case direction::right:
					while (_Right.size()) {
						_Left.push_back(_Right.back());
						_Right.pop_back();
					}
				break;
			}
		}

		inline std::string getString() {
			std::vector <char> _ReversedRight = this->_Right;
			reverse(_ReversedRight);
			std::string _Left = std::string(
				this->_Left.begin(),
				this->_Left.end()
			);
			std::string _Right = std::string(
				_ReversedRight.begin(),
				_ReversedRight.end()
			);
			return _Left + _Right;
		}

		inline operator std::string() { return this->getString(); }

		inline std::vector <char>  getLeft    () { return this->_Left ; }
		inline std::vector <char>  getRight   () { return this->_Right; }
		inline std::vector <char>& getLeftRef () { return this->_Left ; }
		inline std::vector <char>& getRightRef() { return this->_Right; }
	};

	class editor : std::vector <splitBuffer> {
		#define thisLine getLine(this->y)
		int y = 0;
	public:
		editor(void) { push_back(splitBuffer()); }

		inline void moveCursor(int _Where) {
			vec2i _Cur = getCursorPos();
		}

		inline splitBuffer& getLine(int _Where = -1) { 
			if (_Where == -1) {
				_Where = this->y;
			}
			return at(_Where);
		}

		inline void deleteChars(int _Where, int _Count) {
			if (getLine().getLeft().size()) {
				getLine().deleteChars(_Where, _Count);
			}
			else {
				deleteLine();
			}
		}

		inline void deleteLine() {
			if (this->getLineCount() > 1) {
				std::vector <char> _Right = at(this->y).getRight();
				at(this->y).getRightRef() = {};
				reverse(_Right);
				erase(begin() + this->y);
				--this->y;
				thisLine.moveToEdge(direction::right);
				thisLine.insertStr(string(_Right), direction::right);
			}
		}

		inline void insertLine() {
			std::vector <char> _Right = at(this->y).getRight();
			at(this->y).getRightRef() = {};
			reverse(_Right);
			insert(
				begin() + (this->y + 1),
				(size_t)1,
				splitBuffer(_Right)
			);
			++this->y;
			thisLine.moveToEdge(direction::left);
		}

		inline vec2i getCursorPos() {
			return vec2i(thisLine.getLeftRef().size(), this->y);
		}
	
		inline size_t getLineCount() {
			return size();
		}
	};

	editor Editor;
}