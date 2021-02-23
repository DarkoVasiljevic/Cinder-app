#include "../vc2019/Shape.h"
#include "../vc2019/Circle.h"
#include "../vc2019/Square.h"
#include "../vc2019/Rectangle.h"
#include "../vc2019/ShapePark.h"
#include "../vc2019/RapidJson.h"

typedef struct {

	float x = 0.0f, y = 0.0f;
	float r = 0.0f, g = 0.0f, b = 0.0f;
	float radius = 0.0f;
	float size = 0.0f;
	float width = 0.0f, height = 0.0f;

}Property_t;

class MyFirstCinderApp : public App {

public:

	void mouseDown(MouseEvent event) override;
	void keyDown(KeyEvent event) override;
	void keyUp(KeyEvent event) override;

	void setup() override;
	void draw() override;
	void update() override;

	void CreateNewWindow(const std::string&);
	int FindShapeId(std::string&);
	void UpdatePropertyData(int);
	void UpdatePropertyWindow(std::string&);
	void ResetPropertyData();

private:

	float _time = 0.0f;

	bool _START_Shapes_Animation = false;
	bool Rogue = true;

	bool _keyDownW = false;
	bool _keyDownA = false;
	bool _keyDownS = false;
	bool _keyDownD = false;

	bool _saveJSONresources = false;
	bool _loadJSONresources = false;

	std::string _selectedShape = "No selected shape";
	int _selectedItem = -1;

	ShapePark _shapePark;
	Shape::Enum_Shape _shape;
	Property_t _propData;
	RapidJson _json;
};


void prepareSettings(MyFirstCinderApp::Settings* settings)
{
	settings->setWindowSize(1200, 700);
	settings->setResizable(false);
}

void MyFirstCinderApp::setup()
{
	ImGui::Initialize();
}

void MyFirstCinderApp::update()
{
	CreateNewWindow("List");
	CreateNewWindow("Properties");
	CreateNewWindow("File");

	if (getElapsedSeconds() - _time < 0.2f)
	{
		if (_START_Shapes_Animation)
		{
			_shapePark.UpdateShapeList();
		}

		if (_keyDownW || _keyDownA || _keyDownS || _keyDownD)
		{
			_shapePark.UpdateShapeListWASD(_keyDownW, _keyDownA, _keyDownS, _keyDownD);
		}
	}

	_time = getElapsedSeconds();
}

void MyFirstCinderApp::draw()
{
	gl::clear(Color::gray(0.1f));

	gl::begin(GL_LINE_STRIP);

	_shapePark.DrawShapeList();

	gl::end();
}

void MyFirstCinderApp::mouseDown(MouseEvent event)
{
	_shapePark.AddShape(new Circle(event.getPos().x, event.getPos().y));
	
	if (event.isRight())
	{
		_shapePark.IsClickingOnShapes(event.getPos());
		_shapePark.RemoveShape();
	}
}

void MyFirstCinderApp::keyDown(KeyEvent event)
{
	switch (event.getCode())
	{
	case KeyEvent::KEY_w:
		_keyDownW = true;
		break;
	case KeyEvent::KEY_a:
		_keyDownA = true;
		break;
	case KeyEvent::KEY_s:
		_keyDownS = true;
		break;
	case KeyEvent::KEY_d:
		_keyDownD = true;
		break;
	case KeyEvent::KEY_ESCAPE:
		ResetPropertyData();
		break;
	case KeyEvent::KEY_SPACE:
		_START_Shapes_Animation = !_START_Shapes_Animation;
		break;
	default:
		break;
	}
}

void MyFirstCinderApp::keyUp(KeyEvent event)
{
	switch (event.getCode())
	{
	case KeyEvent::KEY_w:
		_keyDownW = false;
		break;
	case KeyEvent::KEY_a:
		_keyDownA = false;
		break;
	case KeyEvent::KEY_s:
		_keyDownS = false;
		break;
	case KeyEvent::KEY_d:
		_keyDownD = false;
		break;
	default:
		break;
	}
}

void MyFirstCinderApp::CreateNewWindow(const std::string& name)
{
	if (name._Equal("List"))
	{
		ImGui::SetNextWindowPos(vec2(5, 0), 0, vec2(0, 0));
		ImGui::SetNextWindowSize(vec2(200, getWindowHeight()), 0);

		ImGui::Begin("List");

		int len = _shapePark._shapeList.size();

		std::vector<std::string> shapeTypes;
		
		std::for_each(_shapePark._shapeList.begin(), _shapePark._shapeList.end(),
			[&shapeTypes](std::pair<unsigned, Shape*> a) 
			{ shapeTypes.push_back(a.second->Type() + "_id: " + std::to_string(a.first)); });

		ImGui::ListBox("", &_selectedItem, shapeTypes, shapeTypes.size());

		if (_selectedItem != -1)
		{
			_selectedShape = shapeTypes[_selectedItem];
			UpdatePropertyWindow(_selectedShape);
		}

		if (shapeTypes.size() == 0)
		{
			ResetPropertyData();
		}

		ImGui::End();
	}
	else if (name._Equal("Properties"))
	{
		ImGui::SetNextWindowPos(vec2(getWindowWidth() - 205, 0), 0, vec2(0, 0));
		ImGui::SetNextWindowSize(vec2(200, getWindowHeight()), 0);

		ImGui::Begin("Properties");

		ImGui::Checkbox("Change properties!", &Rogue);
		ImGui::Separator();
		ImGui::Separator();
		ImGui::Text("Selected shape:");
		ImGui::Separator();
		ImGui::Text(_selectedShape.c_str());
		ImGui::Separator();
		ImGui::Separator();
		ImGui::Text("Location");
		ImGui::Separator();
		ImGui::DragFloat("X", &_propData.x, 0.1f, 205.0f, 995.0f);
		ImGui::DragFloat("Y", &_propData.y, 0.1f, 205.0f, 995.0f);
		ImGui::Text("Color");
		ImGui::Separator();
		ImGui::DragFloat("R", &_propData.r, 0.1f, 0.0f, 1.0f);
		ImGui::DragFloat("G", &_propData.g, 0.1f, 0.0f, 1.0f);
		ImGui::DragFloat("B", &_propData.b, 0.1f, 0.0f, 1.0f);
		ImGui::Text("Circle");
		ImGui::Separator();
		ImGui::DragFloat("Radius", &_propData.radius, 0.1f, 2.5f, getWindowWidth() / 15.0f);
		ImGui::Text("Square");
		ImGui::Separator();
		ImGui::DragFloat("Size", &_propData.size, 0.1f, 2.5f, getWindowWidth() / 15.0f);
		ImGui::Text("Triangle");
		ImGui::Separator();
		ImGui::DragFloat("Height", &_propData.height, 0.1f, 2.5f, getWindowWidth() / 15.0f);
		ImGui::DragFloat("Width", &_propData.width, 0.1f, 2.5f, getWindowWidth() / 15.0f);

		if (!Rogue)
		{
			// TODO:: Enable DragFloat editing!
		}

		ImGui::End();
	}
	else if (name._Equal("File"))
	{
		ImGui::SetNextWindowPos(vec2(270, 0), 0, vec2(0, 0));
		ImGui::SetNextWindowSize(vec2(getWindowWidth() - 205*2 - 140, 50), 0);

		ImGui::Begin("Header\t\t\t\t\tpress SPACE to animate shapes");

		if (ImGui::BeginMenu("File")) {

			ImGui::MenuItem("Save", "", &_saveJSONresources);
			if (_saveJSONresources)
			{
				_json.SaveJsonResources();
				_saveJSONresources = !_saveJSONresources;
			}

			ImGui::MenuItem("Open", "", &_loadJSONresources);
			if (_loadJSONresources)
			{
				_json.LoadJsonResources();
				_loadJSONresources = !_loadJSONresources;
			}

			ImGui::EndMenu();
		}	

		ImGui::End();
	}
}

int MyFirstCinderApp::FindShapeId(std::string& shapeName)
{
	int pos = shapeName.find(' ');

	if (pos == std::string::npos)
		return 0;
	
	return std::stoi(shapeName.substr(pos));
}

void MyFirstCinderApp::UpdatePropertyData(int shapeId)
{
	auto it = _shapePark._shapeList.find(shapeId);

	if (it != _shapePark._shapeList.end())
	{
		_propData.x = it->second->GetLocation().X;
		_propData.y = it->second->GetLocation().Y;
		_propData.r = it->second->GetColor().R;
		_propData.g = it->second->GetColor().G;
		_propData.b = it->second->GetColor().B;

		if (it->second->Type()._Equal("Circle"))
		{
			Circle* c = dynamic_cast<Circle*>(it->second);

			_propData.radius = c->GetRadius();
		}
		else if (it->second->Type()._Equal("Square"))
		{
			Square* s = dynamic_cast<Square*>(it->second);

			_propData.size = s->GetSize();
		}
		else if (it->second->Type()._Equal("Rectangle"))
		{
			Rectangle* r = dynamic_cast<Rectangle*>(it->second);

			_propData.height = r->GetHeight();
			_propData.width = r->GetWidth();
		}
	}
}

void MyFirstCinderApp::UpdatePropertyWindow(std::string& shapeName)
{
	int id = FindShapeId(shapeName);
	UpdatePropertyData(id);
}

void MyFirstCinderApp::ResetPropertyData()
{
	_selectedItem = -1;
	_selectedShape = "No selected shape";

	_propData.x = 0.0f;
	_propData.y = 0.0f;
	_propData.r = 0.0f;
	_propData.g = 0.0f;
	_propData.b = 0.0f;
	_propData.radius = 0.0f;
	_propData.size = 0.0f;
	_propData.height = 0.0f;
	_propData.width = 0.0f;
}

CINDER_APP(MyFirstCinderApp, RendererGl, prepareSettings)