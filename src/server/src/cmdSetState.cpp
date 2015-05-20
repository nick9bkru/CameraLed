#include "cmdSetState.h"

cmdSetState::cmdSetState(Camera * _camera):Cmd("set-led-state")
{
  cout << "Constructor cmdSetState"<< endl;
  setCamera( _camera );
};

string cmdSetState::getRequest( string arg )
{
  if ( ( arg == "on" ) ||  ( arg == "off" ) )
  {
   request =  OK;
   camera->setState( arg );
  } else 
    request =  FAILED;
   return request;
};