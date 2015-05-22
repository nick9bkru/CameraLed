#include "FindFifo.h"

FindFifo::FindFifo( const string _dir, const string _mask): direct(_dir), mask(_mask)
{
  cout << "Constructor FindFifo dir == " << _dir<< endl;
}

FindFifo::~FindFifo()
{
  
 cout << "FindFifo::~FindFifo() "<< endl;
}

string FindFifo::findNewFile()
{
  struct dirent *d;
  string buf="";
  dir = opendir(direct.c_str());
  set< string > AllFile_buf = AllFile;
  
  while ( (d = readdir(dir) ) != NULL )
  {   
    buf = d->d_name;
    if ( buf.find( mask ) != string::npos  )
    {
       //cout << "'"<< d->d_name  << "' " << d->d_reclen<< endl;
       if ( AllFile.find(buf) == AllFile.end() )
       {
	 AllFile.insert( buf );
	 return buf;
       } 
       else 
         {
	   AllFile_buf.erase( buf );
	 };
           
    };
  };
  if ( !AllFile_buf.empty() ) //удаляем из списка файлы кторые были удаленны 
  {
    for (set< string >::iterator it = AllFile_buf.begin(); it !=  AllFile_buf.end(); it ++ )
    {
      cout << " FindFifo::findNewFile() DELETE delete file  " <<*it<< endl;
      AllFile.erase( *it );
    };
  };
  closedir( dir);
  return "";
};
