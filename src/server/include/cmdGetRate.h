#ifndef CMDGETRATE_H
#define CMDGETRATE_H

#include "Cmd.h"
/** @class cmdGetRate
	@brief Базовый класс для всех команд
*/

class cmdGetRate: public Cmd
{
public:
  cmdGetRate(Camera * _camera);
  virtual string getRequest( string arg = "");
private:
  
  
};

#endif 