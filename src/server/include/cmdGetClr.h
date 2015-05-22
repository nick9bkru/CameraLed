#ifndef CMDGETCLR_H
#define CMDGETCLR_H
#include "Cmd.h"
/** @class cmdGetClr
	@brief Класс команды для получения цвета LED
*/

class cmdGetClr: public Cmd
{

public:
  cmdGetClr(Camera * _camera);
  
  virtual string getRequest( string arg = "");
private:
   
  
};

#endif 