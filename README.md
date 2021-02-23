# cinder-app

Simple Cinder & ImGui application.

## Compiling and running

```bash
git clone https://github.com/DarkoVasiljevic/cinder-app.git
cd cinder-app

running   >>  cinder-app/vc2019/MyFirstCinderApp.sln
building  >>  [ select: Build -> Batch Build -> checking: Debug|x64 and Release|x64 -> press: Build ]
starting app application
```

## Info
```bash
Application contains: Main window and three ImGui windows ( List, Properties, Header ).

'Main' window functions:
   >> create a shapes and draw it on the screen by clicking inside window space,
   >> modify last objects location by pressing WASD keys,
   >> delete objects by right mouse click,
   >> animate objects in random direction by pressing SPACE button.

'List' window functions:
   >> hold dynamically list box of all added/removed shapes.

'Properties' window functions:
   >> show properties of the selected object,
   >> unselect object by pressing ESCAPE button.

'Header' window functions:
  >> contain a menu item 'File' witch holds two additional items, 
  >> create a `project.json` file by clicking on 'Save',
  >> load project settings by clicking on 'Open'.
```
