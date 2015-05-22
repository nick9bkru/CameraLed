#include <thread> 


#include "ManageCmd.h"
#include "OperateFifo.h"
#include "FindFifo.h"

#define PROG_NAME "SERVER"

using namespace std;

const string DirFif = "./"; //директория с FIFo
const string maskTo = "FIFO_TO_S"; //маска для поика новых FIFO файлов
const string maskFr = "FIFO_FROM_S"; //маска для поика новых FIFO файлов
ManageCmd * manage; //класс управляющий командами
void start()
{
  cout << "=============================" <<endl;
  cout << "=============================" <<endl;
  cout << "|                           |" <<endl;
  cout << "|    Start "<< PROG_NAME <<" program   |" <<endl;
  cout << "|                           |" <<endl;
  cout << "=============================" <<endl;
  cout << "==========  BUILD  ==========" <<endl;
  cout << "=  " << __TIMESTAMP__ << "  =" <<endl;
  cout << "=============================" <<endl;

}
/**
 * поток обслуживающий один из клиентов
 */
void threadManage(string FIFO_FROM, string FIFO_TO)
{
  cout << "void threadManage(string FIFO_FROM, string FIFO_TO)" << endl;
   string ans;
  OperateFifo FIFO( FIFO_FROM, FIFO_TO );
  while ( 1 )
  {
   ans = FIFO.read();
   if ( ans == "-1" )
   {
     break;
   };
   ans = manage->newCmd( ans );
   cout << "ANS === " << ans << endl;
   
   if ( !FIFO.write( ans ) )
     cerr << "ERROR FIFO WRITE" << endl;
  }
  cout << "Cancel threadManage " << FIFO_FROM << endl;
};

int main(int argc, char **argv)
{
 UNUSED (argc); UNUSED (argv);
 start();

 string fifo_to, fifo_from;
 
 fifo_to = "rm -f " + DirFif + "FIFO*"; 
  system( fifo_to.c_str() );
  
 FindFifo f (DirFif, maskTo);
 
 manage = new ManageCmd() ;
 
 while (1)
 {
  fifo_to = f.findNewFile();
  if ( fifo_to != "")
  {
    fifo_from = fifo_to;
    fifo_from.erase( 0, maskTo.length() );
    fifo_to = "./" + fifo_to;
    fifo_from = "./" + maskFr + fifo_from ;
    
    cout << "fifo_from == " <<  fifo_from <<endl;
    cout << "fifo_to == " <<fifo_to <<endl;
    std::thread ( threadManage ,fifo_from, fifo_to ).detach(); //:TODO надо доделать а то потечет
  };
  usleep (100000);
 }

 return 0;
};