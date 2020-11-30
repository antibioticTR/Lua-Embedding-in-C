#include <iostream>
#include <string.h>

extern "C"
{
#include "Lua540/include/lua.h"
#include "Lua540/include/lauxlib.h"
#include "Lua540/include/lualib.h"
}

#ifdef _WIN32
#pragma comment(lib, "/Lua540/liblua54.a")
#endif

bool CheckLua(lua_State* L, int r)
{
    if (r != LUA_OK)
    {
        std::string errormsg = lua_tostring(L, -1);
        std::cout << errormsg << std::endl;
        return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    
    
    std::cout << "Lua Emulator by anti.\n\nPress to continue..." << std::endl;
    std::cin.ignore();
    system("cls");
    std::cout << "[START]\n" << std::endl;
    
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    int r = luaL_dofile(L, "main.lua");

    if (CheckLua(L, r))
    {
        lua_getglobal(L, "Script2Run");
        if (lua_isfunction(L, -1))
        {
            if (CheckLua(L, lua_pcall(L, 0, 1, 0)))
                std::cout << "\n[END]\n";
        }
    }

    system("pause");
    lua_close(L);
    return 0;
}