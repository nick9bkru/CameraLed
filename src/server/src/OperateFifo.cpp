#include "OperateFifo.h"

OperateFifo::OperateFifo(string _fifo_from_serv, string _fifo_to_serv): 
     fifo_to_serv( _fifo_to_serv ),fifo_from_serv(_fifo_from_serv)
{
 cout << "Constructor OperateFifo " << endl;
 cout << "fifo_from_serv -- " << _fifo_from_serv << endl;
 cout << "fifo_to_serv " <<  _fifo_to_serv <<endl; 
 fdes_from = 0; fdes_to = 0;
};

OperateFifo::~OperateFifo()
{
};


string OperateFifo::read ()
{
  char buf ;
  int err_count = 0;
  string ret = ""; // количество раз когда не была принята команда 
  if ( ! OpenRead() )
  {
   return "-1"; 
  };
  while (1)
  {
    if ( ::read( fdes_to , &buf, 1 ) >= 1 )
    {
      err_count = 0;
      if ( buf != '\n' )
      {
	ret+= buf;
      } else break;
    } else 
    {
     // cout << strerror( errno) <<fdes_from  << endl;
      if ( ( err_count++ > COUNT_ERR ) ) //условие сделанно для того, что бы убить поток в случае стирания FIFo файла 
      {
	if ( OpenRead() )
	{
	  err_count = 0;
	} else 
	  {
	    return "-1";
	  };
      } ;
      usleep( 100000 );
    }
  }
//  cout << "!!! = "<< ret << endl;
  close (fdes_to);
  return ret;
  
};

bool OperateFifo::write ( string ans )
{
  fdes_from = open (fifo_from_serv.c_str(),O_WRONLY);
  if ( fdes_from >= 1)
  {
    int ret = ::write ( fdes_from, ans.c_str(), ans.length());
    //cout << strerror( errno) <<fdes_from  << endl;
    //cout << ans << " len == " << ans.length()<< endl ;
    close (fdes_from);
     if ( ret == int ( ans.length() ) )
       return true;
  }
  return false;
};

bool OperateFifo::OpenRead()
{
//  cout << "OperateFifo::OpenRead()" << endl;
  if (  fdes_to >= 1  )
  {
    close ( fdes_to );
    //return false;
  };
  fdes_to = open (fifo_to_serv.c_str(), O_NONBLOCK | O_RDONLY);
  if ( fdes_to < 1 )
  {
    cerr << "Error OperateFifo::OpenRead() "<<endl;
    return false;
  };
  return true;
};
