#ifndef CMDGETSTATE_H
#define CMDGETSTATE_H

#include "Cmd.h"

/** @class cmdGetState
	@brief Класс для получения состояния
*/

class cmdGetState: public Cmd
{
public:
  cmdGetState(Camera * _camera);
  virtual string getRequest( string arg = "");
private:
    
  
};

#endif 