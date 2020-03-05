#include "TestPlugin.h"
using namespace yazi::engine;
using namespace yazi::plugin;

#include "Json.h"
using namespace yazi::json;

TestPlugin::TestPlugin() : Plugin()
{

}

TestPlugin::~TestPlugin()
{

}

bool TestPlugin::run(Holder & holder)
{
    string & input = holder.ref<string>("input");

    Json json;
    json.parse(input);

    holder.ref<string>("output") += "hello, " + json["name"].asString() + " test plugin run!\n";
    return true;
}

