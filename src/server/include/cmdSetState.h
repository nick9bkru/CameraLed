#ifndef CMDSETSTATE_H
#define CMDSETSTATE_H

#include "Cmd.h"

/** @class Cmd
	@brief Класс команды для установки состояния
*/

class cmdSetState: public Cmd
{
public:
  cmdSetState(Camera * _camera);
  virtual string getRequest( string arg = "") ;
private:
  
};

#endif 
