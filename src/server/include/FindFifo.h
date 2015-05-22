#ifndef FINDFIFO_H
#define FINDFIFO_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <set>

#include <sys/types.h>
#include <dirent.h>

/** @class FindFifo
	@brief класс для работы с FIFO файлом
*/
using namespace std;
class FindFifo
{
public:
  /** @brief конструктор
	@brief @param _dir директория для поиска файлов
	@brief @param _mask маска для поиска файлов	
	*/
  FindFifo( const string _dir, const string _mask);
  ~FindFifo();
  /** @brief ищем новый файл в директории 
	@brief @return новый файл или "", если его нет	
	*/
  string findNewFile();
private:
  /** @brief файлы в директории попадающие под маску */
  set< string > AllFile;
  DIR *dir;
  /** @brief директория с файлами */
  string direct;
  /** @brief маска для искомых файлов */
  string mask;
};

#endif // FINDFIFO_H
