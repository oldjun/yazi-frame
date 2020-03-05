#include "UserPlugin.h"
using namespace yazi::engine;
using namespace yazi::plugin;

#include "Json.h"
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

    Json json;
    json.parse(input);

    holder.ref<string>("output") += "hello, " + json["name"].asString() + " user plugin run!\n";
    return true;
}

