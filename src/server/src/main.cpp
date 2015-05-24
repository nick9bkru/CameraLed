#include <thread> 
#include <map> 
#include <queue>
#include <chrono>

#include "ManageCmd.h"
#include "OperateFifo.h"
#include "FindFifo.h"

#define PROG_NAME "SERVER"

using namespace std;

const string DirFif = "./"; //директория с FIFo
const string maskTo = "FIFO_TO_S"; //маска для поика новых FIFO файлов
const string maskFr = "FIFO_FROM_S"; //маска для поика новых FIFO файлов

std::map< std::thread::id , std::thread*> mapThread;
std::queue< std::thread::id > id_queue;

std::mutex              lock_;
//std::condition_variable g_queuecheck;

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
  std::lock_guard<std::mutex> locker(lock_);
  id_queue.push( std::this_thread::get_id() );
  cout << "Cancel threadManage " << FIFO_FROM << " id= "<< std::this_thread::get_id()<< endl;
};
/**
 * потоковая функция подчищающая память в случае завершения threadManage 
 */
void deleteThead()
{
  std::thread::id id;
  std::thread * thr;
  while(1)
  {
    std::this_thread::sleep_for( std::chrono::microseconds(100));
    std::lock_guard<std::mutex> locker(lock_);
      if( !id_queue.empty() )
      {
	while ( !id_queue.empty() )
	{
	  id = id_queue.front() ;
	  std::cout << "DELETE THREAD id = "<< id<< std::endl;
	  id_queue.pop();
	  thr = mapThread.find(id)->second;
	  thr->join();
	  delete ( thr );
	  mapThread.erase( id );
	};
      };     
  };
};

int main(int argc, char **argv)
{
 UNUSED (argc); UNUSED (argv);
 start();

 string fifo_to, fifo_from;
 
 fifo_to = "rm -f " + DirFif + "FIFO*"; // удаляем старые файлы
  system( fifo_to.c_str() );
  
 FindFifo f (DirFif, maskTo);
 
 manage = new ManageCmd() ;
 
 std::thread ThrDelThr( deleteThead ); //поток очищающий память умерших потоков
 while (1)
 {
  fifo_to = f.findNewFile();
  if ( fifo_to != "")
  {
    fifo_from = fifo_to;
    fifo_from.erase( 0, maskTo.length() );
    fifo_to = DirFif + fifo_to;
    fifo_from = DirFif + maskFr + fifo_from ;
    
    cout << "fifo_from == " <<  fifo_from <<endl;
    cout << "fifo_to == " <<fifo_to <<endl;
    std::thread* Thr=  new std::thread( threadManage ,fifo_from, fifo_to );
    mapThread[Thr->get_id()] = Thr;
  };
  usleep (100000);
 }

 ThrDelThr.join();
 return 0;
};