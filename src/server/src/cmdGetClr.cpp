#include "cmdGetClr.h"

cmdGetClr::cmdGetClr(Camera * _camera):Cmd("get-led-color")
{
  cout << "Constructor cmdGetClr"<< endl;
  setCamera( _camera );  
};

string cmdGetClr::getRequest( string arg )
{
  UNUSED(arg);
 request = camera -> getColor();
 if ( request == "" )
   request = FAILED;
  else 
    request = OK + " " + request;
 return request;
};

