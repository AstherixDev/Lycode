#pragma once
#include "global.h"

#ifdef _LYCODE_LOG
	#include <iostream>
	#include <fstream>
	namespace lycode {
	std::ofstream _LogFile(_LYCODE_LOG_FNAME);
		std::string functionName(std::string _Name) { 
			auto _Pos = _Name.find_last_of("::");
			return _Name.substr(_Pos+1);
		}
	}
	#ifdef _LYCODE_LOG_CONSOLE
		#define log(d) \
			std::cout << "[" << functionName(__FUNCTION__) << "] " << d << "\n"; \
			lycode::_LogFile << "[" << functionName(__FUNCTION__) << "] " << d << "\n";
	#else
		#define log(d) \
			lycode::_LogFile << "[" << functionName(__FUNCTION__) << "] " << d << "\n"; \
	#endif
	#endif
#else
	#define log(d)
#endif