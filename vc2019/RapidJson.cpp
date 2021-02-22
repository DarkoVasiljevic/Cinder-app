#include "RapidJson.h"

RapidJson::RapidJson()
{
	std::ofstream out;

	_fileExists = std::filesystem::exists(_rapidJsonPath + _initRapidJsonFileName);
	if (!_fileExists)
	{
		out.open((_rapidJsonPath + _initRapidJsonFileName).c_str(), std::ios::out | std::ios::binary);
		out.close();
		SetInitValuesToJsonFile();
	}
	else
	{
		LoadJsonResources();
	}	
}

void RapidJson::SetInitValuesToJsonFile()
{
	std::string key("jsonFileNameId");
	std::string value("1");
	WriteToProjectJsonFile(_initRapidJsonFileName, key, value);
}

bool RapidJson::LoadJsonResources()
{
	_jsonData = GetJsonString();
	if (_jsonData.empty())
		return false;

	if (_document.Parse(_jsonData.c_str()).HasParseError())
		return false;

	auto it = _document.FindMember("jsonFileNameId");
	if (it != _document.MemberEnd())
	{
		_nextJsonFileId = std::stoi(it->value.GetString());
	}

	return true;
}

std::string RapidJson::GetJsonString()
{
	std::stringstream _jsonBuffer;

	std::ifstream in((_rapidJsonPath + _initRapidJsonFileName).c_str(), std::ios::in | std::ios::binary);
	if (in) 
	{ 
		_jsonBuffer << in.rdbuf();
		in.close();
	}
	else 
	{
		in.close();
		return "";
	}

	return _jsonBuffer.str();
}

void RapidJson::SaveJsonResources()
{
	_newRapidJsonFileName = "project_" + std::to_string(_nextJsonFileId) + ".json";
	std::ofstream out((_rapidJsonPath + _newRapidJsonFileName).c_str(), std::ios::out | std::ios::binary);
	out.close();

	CopyFromProjectJsonFile();

	std::string key("jsonFileNameId");
	WriteToProjectJsonFile(_initRapidJsonFileName, key, std::to_string(++_nextJsonFileId));
}

void RapidJson::WriteToProjectJsonFile(std::string& fileName, std::string& key, std::string& value)
{
	std::ofstream out((_rapidJsonPath + fileName).c_str(), std::ios::out | std::ios::binary);

	rapidjson::StringBuffer s;
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(s);

	writer.StartObject();

	writer.Key(key.c_str());
	writer.String(value.c_str());

	writer.EndObject();

	out << s.GetString();

	out.close();
}

void RapidJson::CopyFromProjectJsonFile()
{	
	_jsonData = GetJsonString();

	_outDocument.Parse(_jsonData.c_str()).HasParseError();

	auto it = _outDocument.FindMember("jsonFileNameId");

	if (it != _outDocument.MemberEnd())
	{
		std::string key = it->name.GetString();
		std::string value = it->value.GetString();

		WriteToProjectJsonFile(_newRapidJsonFileName, key, value);
	}
}

