#include "UserPlugin.h"
using namespace yazi::engine;
using namespace yazi::plugin;

#include "Json.h"
#include "Parser.h"
using namespace yazi::json;

UserPlugin::UserPlugin() : Plugin()
{

}

UserPlugin::~UserPlugin()
{

}

bool UserPlugin::run(Holder & holder)
{
    string & input = holder.ref<string>("input");

    Parser parser;
    parser.load(input);
    Json json = parser.parse();

    holder.ref<string>("output") += "hello, " + json["name"].asString() + " user plugin run!\n";
    return true;
}

