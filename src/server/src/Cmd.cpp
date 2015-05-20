#include "Cmd.h"

Cmd::Cmd ( string cmd): command( cmd )
{
};

string Cmd::getCommand()
{
  return command;
};

void Cmd::setCamera ( Camera * _camera )
{
  cout << "void Cmd::setCamera ( Camera * _camera )  "<< command<< endl;
  camera = _camera;
};