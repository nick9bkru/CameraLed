#ifndef CMD_H
#define CMD_H

#include <iostream>
#include "Camera.h"
#include "define.h"

/** @class Cmd
	@brief Базовый класс для всех команд
*/

using namespace std;

class Cmd
{
public:
  /** @brief конструктор 
	@brief @param arg команда
	*/
  Cmd( string cmd);
  /** @brief получить команду 
	@brief @return команда
	*/
  virtual ~Cmd () {};
  string getCommand();
  /** @brief получить реакцию на команду
	@brief @param arg аргумент к команде 
	@brief @return ответ на команду 	
	*/
  virtual string getRequest( string arg = "") = 0;
  /** @brief присваивает указатель camera  
	@brief @param _camera присваемый указатель camera  	
	*/
  void setCamera ( Camera * _camera );
protected:
  /** @brief название команды  */
  string command;
  /** @brief ответ  */
  string request;
  /** @brief Указатель на экземпляр указателя класса камеры  */
  Camera * camera; 
};

#endif 