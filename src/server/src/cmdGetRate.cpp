#include "cmdGetRate.h"

cmdGetRate::cmdGetRate(Camera * _camera):Cmd("get-led-rate")
{
  cout << "Constructor cmdGetRate"<< endl;
  setCamera( _camera );
};

string cmdGetRate::getRequest( string arg )
{
  UNUSED(arg);
 request = camera -> getRate();
 if ( request == "" )
   request = FAILED;
  else 
    request = OK + " " + request;
 return request;
};
