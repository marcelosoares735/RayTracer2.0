#pragma once

#include <fstream>
#include <string>
#include "Canvas.h"
#include "World.h"


struct Config {
	int screen_width = 0;
	int screen_height = 0;

	void Load() {
		std::fstream config_file("config.txt");
		
		for (std::string line; std::getline(config_file, line);) {
			if(line == "[Screen Dimensions]") {
				config_file >> screen_width >> screen_height;
			}else if(line.empty()) {
				
			}
		}
	}

	
};
