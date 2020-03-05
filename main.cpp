#include <iostream>
using namespace std;

#include "System.h"
#include "Singleton.h"
using namespace yazi::utility;

#include "Workflow.h"
using namespace yazi::engine;

#include "Server.h"
using namespace yazi::server;

int main()
{
    System * sys = Singleton<System>::instance();
    sys->init();

    // initialize the work flow
    Workflow * workflow = Singleton<Workflow>::instance();
    workflow->load(sys->get_root_path() + "/workflow.xml");
    
    Server * server = Singleton<Server>::instance();
    server->listen("127.0.0.1", 8080);
    server->start();
    
    return 0;
}
