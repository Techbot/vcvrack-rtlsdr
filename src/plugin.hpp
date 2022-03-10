//----------------------------------------------------------------------------
//	EMC23 Tech tools Plugin for VCV Rack - 
//  Copyright (C) 2021  EMC23
//----------------------------------------------------------------------------

#include <cmath>

#include <rack.hpp>

using namespace rack;

// Forward-declare the Plugin
extern Plugin *pluginInstance;
extern Model *modelScanner;


// settings file
json_t * readSettings();
void saveSettings(json_t *rootJ);

// settings functions
int readDefaultIntegerValue(std::string);
void saveDefaultIntegerValue(std::string setting, int value);




