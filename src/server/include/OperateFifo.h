#ifndef OPERATEFIFO_H
#define OPERATEFIFO_H

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <string>
/** @class OperateFifo
	@brief класс для работы с FIFO файлом
*/
using namespace std;
class OperateFifo
{
public:
  OperateFifo(string _fifo);
  ~OperateFifo();
  bool isReady();
  string read ();
  bool write ( string ans );
private:
  /** @brief дескриптор файла */
  int fdes;
  /** @brief адрес к файлу */
  string fifo;
  void init_file();
};

#endif // OPERATEFIFO_H
