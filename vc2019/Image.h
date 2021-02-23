#pragma once

#ifndef __IMAGE__
#define __IMAGE__

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace gl;

#include <vector>
#include <set>

class Image {

public:
	Image() = default;
	~Image() = default;

	void SetToList();
	void SetBackgroundImage(const fs::path&);
	void SaveImage(fs::path&);
	void DrawBackgroundImage(Area&);

public:
	std::set<std::string> _imagesFileSet;
	std::vector<std::string> _imagesFileList;
	TextureRef _backgroundTexture;
	fs::path _imagesSavePath = "../data/images/";
};




#endif
