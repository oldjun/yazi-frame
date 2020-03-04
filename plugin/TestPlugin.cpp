#include "TestPlugin.h"
using namespace yazi::engine;
using namespace yazi::plugin;

#include "Json.h"
#include "Parser.h"
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

    Parser parser;
    parser.load(input);
    Json json = parser.parse();

    holder.ref<string>("output") += "hello, " + json["name"].asString() + " test plugin run!\n";
    return true;
}

