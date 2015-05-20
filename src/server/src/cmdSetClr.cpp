#include "cmdSetClr.h"


cmdSetClr::cmdSetClr(Camera * _camera):Cmd("set-led-color")
{
  cout << "Constructor cmdSetClr"<< endl;
  setCamera( _camera );
};

string cmdSetClr::getRequest( string arg )
{
  if ( ( arg == RED ) ||  ( arg == GREEN ) || ( arg == BLUE ) )
  {
   request =  OK;
   camera->setColor( arg );
  } else 
  {
    request =  FAILED;
  }
   return request;
};