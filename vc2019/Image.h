#pragma once

#ifndef __IMAGE__
#define __IMAGE__

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/Shader.h"
#include"cinder/gl/Fbo.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/ImageIo.h"

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
	void DrawBackgroundImage(Area&, Texture2dRef);
	void InitSheaders();
	void DrawShadedImages();
	void CreateBackgroundShadedImage(const std::vector<fs::path>&);
	void CalculateAreaCoordinates(std::vector<Area>*, int);

public:
	std::set<std::string> _imagesFileSet;
	std::vector<std::string> _imagesFileList;
	TextureRef _imageBackground;
	fs::path _imagesSavePath = "../data/images/";

	FboRef _frameBuffer;
	BatchRef _shaderBatch;
	GlslProgRef	_shaderSolid;

	std::vector<Texture2dRef> _textureList;
	vec2 _window;
	int sx1 = 0, sy1 = 0, sx2, sy2;
};




#endif
