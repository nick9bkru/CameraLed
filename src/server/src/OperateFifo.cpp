#include "OperateFifo.h"

OperateFifo::OperateFifo(string _fifo): fifo( _fifo )
{
 cout << "Constructor OperateFifo _fifo == " << fifo<< endl;
 init_file();
};

OperateFifo::~OperateFifo()
{
 if ( isReady() )
   close (fdes);
};

bool OperateFifo::isReady()
{
  if ( fdes >= 1)
  {
   return true;
  }
    else 
    {
      return false;
    };
};

void OperateFifo::init_file()
{
 /* unlink (fifo.c_str());
  mkfifo (fifo.c_str(), 0666);   
 */ fdes = open (fifo.c_str(), O_RDWR | O_SYNC);
};

string OperateFifo::read ()
{
  char buf;
  int len = 0;
  string ret;
  if ( ! isReady() )
    return "";
  while (1)
  {
    len = ::read( fdes , &buf, 1 );
    if ( len ==1 )
    {
      if ( buf == '\n')
	break;
      ret += buf;
    } else 
      {
	usleep(100000);
      }
  };
  cout << "!!! = "<< ret << endl;
  return ret;
};

bool OperateFifo::write ( string ans )
{
  if ( isReady() )
  {
    int ret = ::write ( fdes, ans.c_str(), ans.length());
     if ( ret == ans.length() )
       return true;
  }
  return false;
};

