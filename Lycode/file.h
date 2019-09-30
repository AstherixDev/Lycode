#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "log.h"

namespace lycode {
	class file : std::vector <std::string> {
		std::fstream _Fstream;

		inline bool openFile(std::string _Fname) {
			this->_Fstream.open(
				_Fname, 
				std::ios::in | std::ios::out | std::ios::beg
			);
			if (this->_Fstream.is_open()) {
				log("Opened '" << _Fname << "' ");
				return true;
			}
			else {
				log("Couldn't open '" << _Fname << "'");
				return false;
			}
		}

		inline void loadFile() {
			std::string _Line;
			while (std::getline(this->_Fstream, _Line)) {
				push_back(_Line);
			}
			log("Loaded file successfully");
		}

	public:
		explicit file(std::string _Fname) {
			if (this->openFile(_Fname)) this->loadFile();
		}
	};
}

_DECLARE_LYCODE

std::vector <file> _Files;