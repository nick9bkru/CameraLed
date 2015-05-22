#include "ManageCmd.h"

ManageCmd::ManageCmd()
{
  cout << "ManageCmd::ManageCmd() "<< endl;
   camera = new Camera ();
 initCmd();
}

ManageCmd::~ManageCmd()
{
  cout << "ManageCmd::~ManageCmd() "<< endl;
  for ( map < string , Cmd*> :: iterator it = mapCmd.begin(); it != mapCmd.end() ; it ++)
  {
    delete  (( *it).second) ;
  };
  delete camera;
}

void ManageCmd::initCmd()
{
  Cmd * cmd;
  cmd = new cmdGetClr ( camera );
  mapCmd [ cmd->getCommand() ] = cmd;
  cmd = new cmdGetRate ( camera );
  mapCmd [ cmd->getCommand() ] = cmd;
  cmd = new cmdGetState ( camera );
  mapCmd [ cmd->getCommand() ] = cmd;
  cmd = new cmdSetClr ( camera );
  mapCmd [ cmd->getCommand() ] = cmd;
  cmd = new cmdSetRate ( camera );
  mapCmd [ cmd->getCommand() ] = cmd;
  cmd = new cmdSetState ( camera );
  mapCmd [ cmd->getCommand() ] = cmd;
  cout << "mapCmd " << mapCmd.size()<< endl;
};

string  ManageCmd::newCmd( string cmd)
{
 lock_guard<std::mutex> locker(_lock);
 cout << "ManageCmd::newCmd cmd == " << cmd << endl; 
 pair< pSTRING > pCmd;
 pCmd =  parseCmd( cmd );
 cout << "Command == '" << pCmd.first << "', arg == '" << pCmd.second << "'" << endl;
 
 map < string , Cmd*>::iterator it = mapCmd.find( pCmd.first);

 if ( it == mapCmd.end() )
 {
    cout << " ERROR COMMAND" << endl;
    return " ERROR COMMAND";
 }
 
 return ((*it).second)->getRequest( pCmd.second ) ;
};

pair< pSTRING > ManageCmd::parseCmd ( string _cmd)
{
  string arg = "", cmd;
  int k = _cmd.find ( " ");
  if ( k != -1)
  {
    arg = _cmd.substr( k + 1, _cmd.length() );
  }
  cmd = _cmd.substr( 0, k );
  return make_pair< pSTRING >(string(cmd),string(arg));
};
