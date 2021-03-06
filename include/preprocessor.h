#pragma once

#ifdef REBOOT_LIB
#ifdef REBOOT_DYNAMIC
#define REBOOT_API __declspec(dllexport)
#else
#define REBOOT_API __declspec(dllimport)
#endif
#else
#define REBOOT_API
#endif

//RENDERING CANVAS
#define CANVAS_GLFW 0
#define CANVAS_FRAME 0x0010

//RENDERING CONTEXT
#define CONTEXT_OPENGL4 0
#define CONTEXT_VULKAN 0x0020

//PIPELINE
#define RENDER_FORWARD 0
#define RENDER_DEFERRED 0x0030

//DEBUGGING, VISUAL HELPERS
#define DEBUG_DISABLED false
#define DEBUG_ENABLED true

//THREADED LOADING
#define THREADING_DISABLED false
#define THREADING_ENABLED true

//WINDOW TYPE
#define WINDOW_TYPE_WINDOW 0
#define WINDOW_TYPE_BORDERLESS 0x0001
#define WINDOW_TYPE_FULLSCREEN 0x0002

//SHADER TYPE
#define SHADER_VERTEX 0
#define SHADER_FRAGMENT 0x0041
#define SHADER_GEOMETRY 0x0042

//BUFFER TYPE
#define BUFFER_TYPE_INDEXBUFFER 0
#define BUFFER_TYPE_VERTEXARRAY 0x0051
#define BUFFER_TYPE_BUFFER 0x0052
#define BUFFER_TYPE_FRAME 0x0053

//SCRIPT TYPE
#define SCRIPT_LUA 0


//Camera type
#define CAMERA_PERSPECTIVE 0
#define CAMERA_ORTHOGRAPHIC 0x0061

#define MAX_LAYERS 12    //required?

//ERRORS
#define REBOOT_UNAVAILABLE 0x1000
#define REBOOT_CONTEXT_ERROR 0x1001
#define REBOOT_SHADER_FAILED 0x1002



typedef unsigned char BYTE;

#include <iostream>
#define errorCheck(c)({GLenum err; err = glGetError();if(err!=GL_NO_ERROR)std::cout<<"_______________________________________________________________"<<std::endl<<"["<<c<<"] THERE WAS AN ERROR: "<<err<<std::endl<<"_______________________________________________________________"<<std::endl;})


#ifdef TYPE_FN
#include <string>
#include <cstdlib>
#include <cxxabi.h>
#include <GL/glew.h>
#include <iostream>


template<typename T>
std::string type_name() {
    int status;
    std::string tname = typeid(T).name();
    char *demangled_name = abi::__cxa_demangle(tname.c_str(), NULL, NULL, &status);
    if (status == 0) {
        tname = demangled_name;
        std::free(demangled_name);
    }
    return tname;
}
#endif
#ifdef WITH_TOSTRING
#include <string>
#include <sstream>
namespace std{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
#endif