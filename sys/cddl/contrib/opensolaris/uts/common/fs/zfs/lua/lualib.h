begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: lualib.h,v 1.43.1.1 2013/04/12 18:48:47 roberto Exp $ ** Lua standard libraries ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lualib_h
end_ifndef

begin_define
define|#
directive|define
name|lualib_h
end_define

begin_include
include|#
directive|include
file|"lua.h"
end_include

begin_function_decl
name|LUAMOD_API
name|int
function_decl|(
name|luaopen_base
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LUA_COLIBNAME
value|"coroutine"
end_define

begin_function_decl
name|LUAMOD_API
name|int
function_decl|(
name|luaopen_coroutine
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LUA_TABLIBNAME
value|"table"
end_define

begin_function_decl
name|LUAMOD_API
name|int
function_decl|(
name|luaopen_table
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LUA_IOLIBNAME
value|"io"
end_define

begin_function_decl
name|LUAMOD_API
name|int
function_decl|(
name|luaopen_io
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LUA_OSLIBNAME
value|"os"
end_define

begin_function_decl
name|LUAMOD_API
name|int
function_decl|(
name|luaopen_os
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LUA_STRLIBNAME
value|"string"
end_define

begin_function_decl
name|LUAMOD_API
name|int
function_decl|(
name|luaopen_string
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LUA_BITLIBNAME
value|"bit32"
end_define

begin_function_decl
name|LUAMOD_API
name|int
function_decl|(
name|luaopen_bit32
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LUA_MATHLIBNAME
value|"math"
end_define

begin_function_decl
name|LUAMOD_API
name|int
function_decl|(
name|luaopen_math
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LUA_DBLIBNAME
value|"debug"
end_define

begin_function_decl
name|LUAMOD_API
name|int
function_decl|(
name|luaopen_debug
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LUA_LOADLIBNAME
value|"package"
end_define

begin_function_decl
name|LUAMOD_API
name|int
function_decl|(
name|luaopen_package
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* open all previous libraries */
end_comment

begin_function_decl
name|LUALIB_API
name|void
function_decl|(
name|luaL_openlibs
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lua_assert
argument_list|)
end_if

begin_define
define|#
directive|define
name|lua_assert
parameter_list|(
name|x
parameter_list|)
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

