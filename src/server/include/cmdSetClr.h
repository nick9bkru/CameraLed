#ifndef CMDSETCLR_H
#define CMDSETCLR_H

#include "Cmd.h"
/** @class cmdSetClr
	@brief Класс команды для установки цвета
*/
const string RED = "red";
const string GREEN = "green";
const string BLUE = "blue";

class cmdSetClr: public Cmd
{

public:
  cmdSetClr(Camera * _camera);
  virtual string getRequest( string arg = "");
private:
  
  
};

#endif 