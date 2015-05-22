#ifndef OPERATEFIFO_H
#define OPERATEFIFO_H

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <errno.h>
#include <string>
#include <string.h>
/** @class OperateFifo
	@brief класс для работы с FIFO файлом
*/
using namespace std;
class OperateFifo
{
  enum //количество считываний перед переоткрытием
  {
    COUNT_ERR = 100
  };
public:
  /** @brief Конструктор
	@brief @param _fifo_from_serv файл для чтения команд 
	@brief @param _fifo_to_serv файл для отправки команд	
	*/
  OperateFifo(string _fifo_from_serv, string _fifo_to_serv);
  ~OperateFifo();
  /** @brief метод читающий команды из файла 
	@brief @return принятая команда или "-1" в случае ошибки
	*/
  string read ();
  /** @brief метод пишущий команды в файла 
	@brief @param ans записываемая строка в файл
	@brief @return true в случае нормы , false в случае ошибки 
	*/
  bool write ( string ans );
private:
  /** @brief открыть файл для чтения*/
  bool OpenRead();
  /** @brief дескриптор файла */
  int fdes_to, fdes_from;
  /** @brief адрес к файлу */
  string fifo_to_serv, fifo_from_serv;
};

#endif // OPERATEFIFO_H
