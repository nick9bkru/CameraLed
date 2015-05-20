#ifndef MANAGECMD_H
#define MANAGECMD_H

#define pSTRING string, string
#include <map>
#include "cmdGetClr.h"
#include "cmdGetRate.h"
#include "cmdGetState.h"
#include "cmdSetClr.h"
#include "cmdSetRate.h"
#include "cmdSetState.h"
/** @class ManageCmd
	@brief Класс управляющий командами 
*/

using namespace std; 

class ManageCmd
{
public:
  ManageCmd();
  ~ManageCmd();
  
  /** @brief метод принемает команду , парсит её и получает ответ
	@brief @param cmd команда 
	@brief @return ответ на команду 	
	*/
  string newCmd( string cmd);
private:
  /** @brief инициализируем команды*/
  void initCmd ();
  /** @brief пары команда и указатель на её класс*/
  map < string , Cmd*> mapCmd;
  
  /** @brief указатель на класс описывающий состояние камеры*/
  Camera * camera; 
  
  /** @brief разбираем команду пришедшую от клиента */
  pair< pSTRING > parseCmd ( string _cmd);
  
};

#endif // MANAGECMD_H
