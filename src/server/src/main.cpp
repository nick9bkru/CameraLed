#include "ManageCmd.h"
#include "OperateFifo.h"


#define PROG_NAME "SERVER"

using namespace std;

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


int main(int argc, char **argv)
{
 UNUSED (argc); UNUSED (argv);
 start();
 string ans;

 OperateFifo FIFO( fifo_name );
 if (!FIFO.isReady())
 {
   return -1;
 };

 ManageCmd * manage = new ManageCmd() ;
 while ( 1 )
 {
   ans = manage->newCmd( FIFO.read());
   cout << "ANS === " << ans << endl;
   if ( !FIFO.write( ans ) )
     cerr << "ERROR FIFO WRITE" << endl;
   
 }

 return 0;
};