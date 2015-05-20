#ifndef CMDSETRATE_H
#define CMDSETRATE_H

#include "Cmd.h"
/** @class cmdSetRate
	@brief Базовый класс для всех команд
*/

class cmdSetRate: public Cmd
{
public:
  cmdSetRate(Camera * _camera);
  virtual string getRequest( string arg = "");
private:
  
  
};

#endif 