#pragma once

#ifndef __R_JSON_HPP__
#define __R_JSON_HPP__

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <rapidjson/prettywriter.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>

#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>

class RapidJson {

public:
	RapidJson();
	~RapidJson() = default;

	void SaveJsonResources();
	bool LoadJsonResources();
	std::string GetJsonString();
	void SetInitValuesToJsonFile();
	void WriteToProjectJsonFile(std::string&, std::string&, std::string&);
	void CopyFromProjectJsonFile();

public:

	std::string _rapidJsonPath = "../vc2019/json/";
	std::string _initRapidJsonFileName = "project.json";
	std::string _newRapidJsonFileName;
	rapidjson::Document _document;
	rapidjson::Document _outDocument;
	std::string _jsonData;

	bool _fileExists = false;
	int _nextJsonFileId = 1;
};

#endif
