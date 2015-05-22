#include "cmdSetRate.h"
#include <cstdlib>
cmdSetRate::cmdSetRate(Camera * _camera):Cmd("set-led-rate")
{
  cout << "Constructor cmdSetRate"<< endl;
  setCamera( _camera );
};

string cmdSetRate::getRequest( string arg )
{
  int freq = stoi(arg.c_str());
  if ( ( freq < 0 ) || ( freq > 5 ))
  {
    request =  FAILED;
  } else 
    {
      request =  OK;
      camera -> setRate( arg );
    };
  return request;
};

