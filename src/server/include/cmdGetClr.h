#ifndef CMDGETCLR_H
#define CMDGETCLR_H
#include "Cmd.h"
/** @class cmdGetClr
	@brief Базовый класс для всех команд
*/

class cmdGetClr: public Cmd
{

public:
  cmdGetClr(Camera * _camera);
  
  virtual string getRequest( string arg = "");
private:
   
  
};

#endif 