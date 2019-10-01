# Lycode
A minimalistic code editor written in C++.

### Developer documentation
This project aims to create a fully modular, hackable code editor.
It shall be compiled along with the inmutable "Core" package, which is represented by the following header files:
- **lybase.h:** Contains the text editor, based on an implementation of a [Split Buffer](http://briansteffens.com/2017/06/19/split-buffers.html "Split Buffer")
- **lyfile.h:** Contains a wrapper for file I/O, and a files vector `_Files`
- **lyglobal.h:** Contains several switches and defines used through the whole project
- **lyinit.h:** Contains an implementation of `gw::onClose()` and `gw::setup()`
- **lyinput.h:** Contains the input handler
- **lylog.h:** Provides logging capabilities
- **lyprops.h:** Should provide a parser for *Lycode Property Files* (.lyprops) **(UNIMPLEMENTED)**
- **lyrenderer.h:** Contains the renderer implementation, as well as a syntax highlighter
- **lyscheme.h:** Depends on `lyprops.h`. Contains a class defining a color scheme **(UNIMPLEMENTED)**
- **lysyntax.h:** Depends on `lyprops.h`. Contains a class defining a syntax definition **(UNIMPLEMENTED)**
- **lyui.h:** Provides a modular UI renderer (?) **(UNIMPLEMENTED)**
- **lyutil.h:** Provides a modular UI renderer (?) **(UNIMPLEMENTED)**
