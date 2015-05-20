#ifndef CMDGETSTATE_H
#define CMDGETSTATE_H

#include "Cmd.h"

/** @class cmdGetState
	@brief Базовый класс для всех команд
*/

class cmdGetState: public Cmd
{
public:
  cmdGetState(Camera * _camera);
  virtual string getRequest( string arg = "");
private:
    
  
};

#endif 