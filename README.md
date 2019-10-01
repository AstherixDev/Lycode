![Lycode](https://i.lensdump.com/i/i7iUBT.png "Lycode")
A minimalistic code editor written in C++.

### Developer documentation
This project aims to create a fully modular, hackable code editor.
It shall be compiled along with the inmutable "Core" package, which is represented by the following header files:
- **ly\base.h:** Contains the text editor, based on an implementation of a [Split Buffer](http://briansteffens.com/2017/06/19/split-buffers.html "Split Buffer")
- **ly\file.h:** Contains a wrapper for file I/O, and a files vector `_Files`
- **ly\global.h:** Contains several switches and defines used through the whole project
- **ly\init.h:** Contains an implementation of `gw::onClose()` and `gw::setup()`
- **ly\input.h:** Contains the input handler
- **ly\log.h:** Provides logging capabilities
- **ly\props.h:** Should provide a parser for *Lycode Property Files* (.lyprops) **(UNIMPLEMENTED)**
- **ly\renderer.h:** Contains the renderer implementation, as well as a syntax highlighter
- **ly\scheme.h:** Depends on `lyprops.h`. Contains a class defining a color scheme **(UNIMPLEMENTED)**
- **ly\syntax.h:** Depends on `lyprops.h`. Contains a class defining a syntax definition **(UNIMPLEMENTED)**
- **ly\ui.h:** Provides a modular UI renderer (?) **(UNIMPLEMENTED)**
- **ly\util.h:** Contains various utility classes and functions
