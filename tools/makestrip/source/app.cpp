// app.cpp
// One of the Edge tools: Create a single animation strip bitmap from separate image files
//
// Copyright (c) 2004-2017 Elements Interactive B.V.

/////////////////////////////////////////////////////////////////////
// Include and link the library                                    //
/////////////////////////////////////////////////////////////////////

//Include Edge
#include "edgemain.h"

//Link the Edge static library
#pragma comment(lib, "edge.lib")

//Important headers
#include <direct.h>

//Include internal resources
#include "resource.h"

//Contains ClassMain, the application framework
#include "main.h"

/////////////////////////////////////////////////////////////////////
// The program entry point                                         //
/////////////////////////////////////////////////////////////////////

ClassEdge *EdgeMain(EDGESTARTUP *data){	return(new ClassMain); }
