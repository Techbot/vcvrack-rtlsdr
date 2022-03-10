//----------------------------------------------------------------------------
//	EMC23 Tech tools Plugin for VCV Rack -
//  Copyright (C) 2021  EMC23
//----------------------------------------------------------------------------
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

#include "plugin.hpp"


Plugin *pluginInstance;

void init(Plugin *p) {
	pluginInstance = p;
	p->addModel(modelScanner);

}

// save the given global count modula settings`
void saveSettings(json_t *rootJ) {
	std::string settingsFilename = asset::user("techtools.json");//: undefined reference to `rack::asset::user(std::string)'
	FILE *file = fopen(settingsFilename.c_str(), "w");

	if (file) {
		json_dumpf(rootJ, file, JSON_INDENT(2) | JSON_REAL_PRECISION(9));
		fclose(file);
	}
}

// read the global count modula settings
json_t * readSettings() {
	std::string settingsFilename = asset::user("techtools.json");
	FILE *file = fopen(settingsFilename.c_str(), "r");
	if (!file) {
		return json_object();
	}
	json_error_t error;
	json_t *rootJ = json_loadf(file, 0, &error);
	fclose(file);
	return rootJ;
}

// read the given default integer value from the global count modula settings file
int readDefaultIntegerValue(std::string setting) {
	int value = 0; // default to the standard value
	// read the settings file
	json_t *rootJ = readSettings();
	// get the default value
	json_t* jsonValue = json_object_get(rootJ, setting.c_str());
	if (jsonValue)
		value = json_integer_value(jsonValue);
	// houskeeping
	json_decref(rootJ);
	return value;
}

// save the given integer value in the global count modula settings file
void saveDefaultIntegerValue(std::string setting, int value) {
	// read the settings file
	json_t *rootJ = readSettings();
	// set the default theme value
	json_object_set_new(rootJ, setting.c_str(), json_integer(value));
	// save the updated data
	saveSettings(rootJ);
	// houskeeping
	json_decref(rootJ);
}
