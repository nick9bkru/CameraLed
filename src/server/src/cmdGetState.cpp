#include "cmdGetState.h"

cmdGetState::cmdGetState(Camera * _camera):Cmd("get-led-state")
{
  cout << "Constructor cmdGetState"<< endl;
  setCamera( _camera );
};

string cmdGetState::getRequest( string arg )
{
  UNUSED(arg);
 request = camera -> getState();
 if ( request == "" )
   request = FAILED;
  else 
    request = OK + " " + request;
 return request;
};