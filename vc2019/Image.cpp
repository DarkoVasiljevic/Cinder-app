#include "Image.h"

void Image::SetToList()
{
	//std::copy(_imagesFileSet.begin(), _imagesFileSet.end(), std::back_inserter(_imagesFileList));
}

void Image::SetBackgroundImage(const fs::path& path)
{
	_backgroundTexture = gl::Texture::create(loadImage(path));
}

void Image::SaveImage(fs::path& path)
{
	if (!_imagesSavePath.empty()) 
	{
		Surface s8(_backgroundTexture->createSource());

		writeImage(writeFile(_imagesSavePath.string() + path.string()), s8);
	}
}

void Image::DrawBackgroundImage(Area& window)
{
	if (_backgroundTexture)
	{
		Rectf dest = Rectf(_backgroundTexture->getBounds()).getCenteredFill(window, true);
		gl::draw(_backgroundTexture, dest);
	}
}
