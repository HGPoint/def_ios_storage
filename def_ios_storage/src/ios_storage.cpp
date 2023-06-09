#define EXTENSION_NAME IOSStorageExt
#define LIB_NAME "IOSStorage"
#define MODULE_NAME "def_ios_storage"

#define DLIB_LOG_DOMAIN LIB_NAME

#include <dmsdk/sdk.h>

#if  defined(DM_PLATFORM_IOS)

#include <stdlib.h>
#include "ios_storage.h"

namespace dmAppsflyerAdRevenue {

static int Lua_get_string(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    const char* key = (const char*)luaL_checkstring(L, 1);
    const char* typeName = (const char*)luaL_typename(L, 2);
    const char* defaultValue = NULL;
    if (typeName != "nil" && typeName != "no value")
        defaultValue = (const char*)luaL_checkstring(L, 2);

    const char* value = GetStringValue(key);

    if (value == NULL)
        value = defaultValue;

    lua_pushstring(L, value);
    return 1;
}

static int Lua_set_string(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);
    const char* key = (const char*)luaL_checkstring(L, 1);
    const char* value = (const char*)luaL_checkstring(L, 2);
    SetStringValue(key, value);
    return 1;
}

static const luaL_reg Module_methods[] =
{
    {"get_string", Lua_get_string},
    {"set_string", Lua_set_string},
    {0, 0}
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);
    luaL_register(L, MODULE_NAME, Module_methods);
    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

static dmExtension::Result AppInitializeAppsflyerAdRevenue(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

static dmExtension::Result InitializeAppsflyerAdRevenue(dmExtension::Params* params)
{
    LuaInit(params->m_L);
    dmLogInfo("Registered extension def_ios_storage");
    return dmExtension::RESULT_OK;
}

static dmExtension::Result UpdateAppsflyerAdRevenue(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

static dmExtension::Result AppFinalizeAppsflyerAdRevenue(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

static dmExtension::Result FinalizeAppsflyerAdRevenue(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

} // namespace

DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, dmAppsflyerAdRevenue::AppInitializeAppsflyerAdRevenue, dmAppsflyerAdRevenue::AppFinalizeAppsflyerAdRevenue, dmAppsflyerAdRevenue::InitializeAppsflyerAdRevenue, dmAppsflyerAdRevenue::UpdateAppsflyerAdRevenue,  0, dmAppsflyerAdRevenue::FinalizeAppsflyerAdRevenue)

#else // platform
DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, 0, 0, 0, 0,  0, 0)

#endif // platform
