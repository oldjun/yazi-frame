# yazi-frame
a c++ tcp server with work flow

|Author|junping|
|---|---|
|E-mail|oldjun@sina.com|
|Wechat|chenjunping1024|

## How to write your plugin
the yazi-frame is based on [yazi-engine](https://github.com/oldjunren/yazi-engine "yazi-engine"), yazi-engine a c++ work flow based on plugin, it shows the details of how to write a user plugin.

## Start the server
```c++
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
```
## Compile & Run the project
download the source code, cd into the yazi-frame project working directory
### compile the plugin
```bash
cd ./yazi-frame
make plugin
```
### compile the main
```bash
cd ./yazi-frame
make
./main
```

