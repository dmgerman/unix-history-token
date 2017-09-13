begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: lua.h,v 1.285.1.4 2015/02/21 14:04:50 roberto Exp $ ** Lua - A Scripting Language ** Lua.org, PUC-Rio, Brazil (http://www.lua.org) ** See Copyright Notice at the end of this file */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lua_h
end_ifndef

begin_define
define|#
directive|define
name|lua_h
end_define

begin_include
include|#
directive|include
file|<sys/zfs_context.h>
end_include

begin_include
include|#
directive|include
file|"luaconf.h"
end_include

begin_define
define|#
directive|define
name|LUA_VERSION_MAJOR
value|"5"
end_define

begin_define
define|#
directive|define
name|LUA_VERSION_MINOR
value|"2"
end_define

begin_define
define|#
directive|define
name|LUA_VERSION_NUM
value|502
end_define

begin_define
define|#
directive|define
name|LUA_VERSION_RELEASE
value|"4"
end_define

begin_define
define|#
directive|define
name|LUA_VERSION
value|"Lua " LUA_VERSION_MAJOR "." LUA_VERSION_MINOR
end_define

begin_define
define|#
directive|define
name|LUA_RELEASE
value|LUA_VERSION "." LUA_VERSION_RELEASE
end_define

begin_define
define|#
directive|define
name|LUA_COPYRIGHT
value|LUA_RELEASE "  Copyright (C) 1994-2015 Lua.org, PUC-Rio"
end_define

begin_define
define|#
directive|define
name|LUA_AUTHORS
value|"R. Ierusalimschy, L. H. de Figueiredo, W. Celes"
end_define

begin_comment
comment|/* mark for precompiled code ('<esc>Lua') */
end_comment

begin_define
define|#
directive|define
name|LUA_SIGNATURE
value|"\033Lua"
end_define

begin_comment
comment|/* option for multiple returns in 'lua_pcall' and 'lua_call' */
end_comment

begin_define
define|#
directive|define
name|LUA_MULTRET
value|(-1)
end_define

begin_comment
comment|/* ** pseudo-indices */
end_comment

begin_define
define|#
directive|define
name|LUA_REGISTRYINDEX
value|LUAI_FIRSTPSEUDOIDX
end_define

begin_define
define|#
directive|define
name|lua_upvalueindex
parameter_list|(
name|i
parameter_list|)
value|(LUA_REGISTRYINDEX - (i))
end_define

begin_comment
comment|/* thread status */
end_comment

begin_define
define|#
directive|define
name|LUA_OK
value|0
end_define

begin_define
define|#
directive|define
name|LUA_YIELD
value|1
end_define

begin_define
define|#
directive|define
name|LUA_ERRRUN
value|2
end_define

begin_define
define|#
directive|define
name|LUA_ERRSYNTAX
value|3
end_define

begin_define
define|#
directive|define
name|LUA_ERRMEM
value|4
end_define

begin_define
define|#
directive|define
name|LUA_ERRGCMM
value|5
end_define

begin_define
define|#
directive|define
name|LUA_ERRERR
value|6
end_define

begin_typedef
typedef|typedef
name|struct
name|lua_State
name|lua_State
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|lua_CFunction
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* ** functions that read/write blocks when loading/dumping Lua chunks */
end_comment

begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|lua_Reader
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|void
modifier|*
name|ud
parameter_list|,
name|size_t
modifier|*
name|sz
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|lua_Writer
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|sz
parameter_list|,
name|void
modifier|*
name|ud
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* ** prototype for memory-allocation functions */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|lua_Alloc
function_decl|)
parameter_list|(
name|void
modifier|*
name|ud
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|osize
parameter_list|,
name|size_t
name|nsize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* ** basic types */
end_comment

begin_define
define|#
directive|define
name|LUA_TNONE
value|(-1)
end_define

begin_define
define|#
directive|define
name|LUA_TNIL
value|0
end_define

begin_define
define|#
directive|define
name|LUA_TBOOLEAN
value|1
end_define

begin_define
define|#
directive|define
name|LUA_TLIGHTUSERDATA
value|2
end_define

begin_define
define|#
directive|define
name|LUA_TNUMBER
value|3
end_define

begin_define
define|#
directive|define
name|LUA_TSTRING
value|4
end_define

begin_define
define|#
directive|define
name|LUA_TTABLE
value|5
end_define

begin_define
define|#
directive|define
name|LUA_TFUNCTION
value|6
end_define

begin_define
define|#
directive|define
name|LUA_TUSERDATA
value|7
end_define

begin_define
define|#
directive|define
name|LUA_TTHREAD
value|8
end_define

begin_define
define|#
directive|define
name|LUA_NUMTAGS
value|9
end_define

begin_comment
comment|/* minimum Lua stack available to a C function */
end_comment

begin_define
define|#
directive|define
name|LUA_MINSTACK
value|20
end_define

begin_comment
comment|/* predefined values in the registry */
end_comment

begin_define
define|#
directive|define
name|LUA_RIDX_MAINTHREAD
value|1
end_define

begin_define
define|#
directive|define
name|LUA_RIDX_GLOBALS
value|2
end_define

begin_define
define|#
directive|define
name|LUA_RIDX_LAST
value|LUA_RIDX_GLOBALS
end_define

begin_comment
comment|/* type of numbers in Lua */
end_comment

begin_typedef
typedef|typedef
name|LUA_NUMBER
name|lua_Number
typedef|;
end_typedef

begin_comment
comment|/* type for integer functions */
end_comment

begin_typedef
typedef|typedef
name|LUA_INTEGER
name|lua_Integer
typedef|;
end_typedef

begin_comment
comment|/* unsigned integer type */
end_comment

begin_typedef
typedef|typedef
name|LUA_UNSIGNED
name|lua_Unsigned
typedef|;
end_typedef

begin_comment
comment|/* ** generic extra include file */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUA_USER_H
argument_list|)
end_if

begin_include
include|#
directive|include
include|LUA_USER_H
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** RCS ident string */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|lua_ident
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ** state manipulation */
end_comment

begin_function_decl
name|LUA_API
name|lua_State
modifier|*
function_decl|(
name|lua_newstate
function_decl|)
parameter_list|(
name|lua_Alloc
name|f
parameter_list|,
name|void
modifier|*
name|ud
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_close
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|lua_State
modifier|*
function_decl|(
name|lua_newthread
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|lua_CFunction
function_decl|(
name|lua_atpanic
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|lua_CFunction
name|panicf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
specifier|const
name|lua_Number
modifier|*
function_decl|(
name|lua_version
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** basic stack manipulation */
end_comment

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_absindex
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_gettop
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_settop
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_pushvalue
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_remove
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_insert
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_replace
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_copy
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|fromidx
parameter_list|,
name|int
name|toidx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_checkstack
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|sz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_xmove
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|from
parameter_list|,
name|lua_State
modifier|*
name|to
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** access functions (stack -> C) */
end_comment

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_isnumber
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_isstring
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_iscfunction
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_isuserdata
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_type
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
specifier|const
name|char
modifier|*
function_decl|(
name|lua_typename
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|lua_Number
function_decl|(
name|lua_tonumberx
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|,
name|int
modifier|*
name|isnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|lua_Integer
function_decl|(
name|lua_tointegerx
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|,
name|int
modifier|*
name|isnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|lua_Unsigned
function_decl|(
name|lua_tounsignedx
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|,
name|int
modifier|*
name|isnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_toboolean
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
specifier|const
name|char
modifier|*
function_decl|(
name|lua_tolstring
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|size_t
function_decl|(
name|lua_rawlen
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|lua_CFunction
function_decl|(
name|lua_tocfunction
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
modifier|*
function_decl|(
name|lua_touserdata
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|lua_State
modifier|*
function_decl|(
name|lua_tothread
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
specifier|const
name|void
modifier|*
function_decl|(
name|lua_topointer
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** Comparison and arithmetic functions */
end_comment

begin_define
define|#
directive|define
name|LUA_OPADD
value|0
end_define

begin_comment
comment|/* ORDER TM */
end_comment

begin_define
define|#
directive|define
name|LUA_OPSUB
value|1
end_define

begin_define
define|#
directive|define
name|LUA_OPMUL
value|2
end_define

begin_define
define|#
directive|define
name|LUA_OPDIV
value|3
end_define

begin_define
define|#
directive|define
name|LUA_OPMOD
value|4
end_define

begin_define
define|#
directive|define
name|LUA_OPPOW
value|5
end_define

begin_define
define|#
directive|define
name|LUA_OPUNM
value|6
end_define

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_arith
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LUA_OPEQ
value|0
end_define

begin_define
define|#
directive|define
name|LUA_OPLT
value|1
end_define

begin_define
define|#
directive|define
name|LUA_OPLE
value|2
end_define

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_rawequal
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx1
parameter_list|,
name|int
name|idx2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_compare
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx1
parameter_list|,
name|int
name|idx2
parameter_list|,
name|int
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** push functions (C -> stack) */
end_comment

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_pushnil
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_pushnumber
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|lua_Number
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_pushinteger
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|lua_Integer
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_pushunsigned
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|lua_Unsigned
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
specifier|const
name|char
modifier|*
function_decl|(
name|lua_pushlstring
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
specifier|const
name|char
modifier|*
function_decl|(
name|lua_pushstring
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
specifier|const
name|char
modifier|*
function_decl|(
name|lua_pushvfstring
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|argp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
specifier|const
name|char
modifier|*
function_decl|(
name|lua_pushfstring
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_pushcclosure
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|lua_CFunction
name|fn
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_pushboolean
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_pushlightuserdata
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_pushthread
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** get functions (Lua -> stack) */
end_comment

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_getglobal
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|char
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_gettable
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_getfield
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|,
specifier|const
name|char
modifier|*
name|k
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_rawget
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_rawgeti
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_rawgetp
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|,
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_createtable
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|narr
parameter_list|,
name|int
name|nrec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
modifier|*
function_decl|(
name|lua_newuserdata
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|size_t
name|sz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_getmetatable
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|objindex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_getuservalue
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** set functions (stack -> Lua) */
end_comment

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_setglobal
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|char
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_settable
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_setfield
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|,
specifier|const
name|char
modifier|*
name|k
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_rawset
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_rawseti
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_rawsetp
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|,
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_setmetatable
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|objindex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_setuservalue
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** 'load' and 'call' functions (load and run Lua code) */
end_comment

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_callk
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|nargs
parameter_list|,
name|int
name|nresults
parameter_list|,
name|int
name|ctx
parameter_list|,
name|lua_CFunction
name|k
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|lua_call
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|,
name|r
parameter_list|)
value|lua_callk(L, (n), (r), 0, NULL)
end_define

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_getctx
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_pcallk
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|nargs
parameter_list|,
name|int
name|nresults
parameter_list|,
name|int
name|errfunc
parameter_list|,
name|int
name|ctx
parameter_list|,
name|lua_CFunction
name|k
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|lua_pcall
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|,
name|r
parameter_list|,
name|f
parameter_list|)
value|lua_pcallk(L, (n), (r), (f), 0, NULL)
end_define

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_load
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|lua_Reader
name|reader
parameter_list|,
name|void
modifier|*
name|dt
parameter_list|,
specifier|const
name|char
modifier|*
name|chunkname
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_dump
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|lua_Writer
name|writer
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** coroutine functions */
end_comment

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_yieldk
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|nresults
parameter_list|,
name|int
name|ctx
parameter_list|,
name|lua_CFunction
name|k
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|lua_yield
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|)
value|lua_yieldk(L, (n), 0, NULL)
end_define

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_resume
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|lua_State
modifier|*
name|from
parameter_list|,
name|int
name|narg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_status
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** garbage-collection function and options */
end_comment

begin_define
define|#
directive|define
name|LUA_GCSTOP
value|0
end_define

begin_define
define|#
directive|define
name|LUA_GCRESTART
value|1
end_define

begin_define
define|#
directive|define
name|LUA_GCCOLLECT
value|2
end_define

begin_define
define|#
directive|define
name|LUA_GCCOUNT
value|3
end_define

begin_define
define|#
directive|define
name|LUA_GCCOUNTB
value|4
end_define

begin_define
define|#
directive|define
name|LUA_GCSTEP
value|5
end_define

begin_define
define|#
directive|define
name|LUA_GCSETPAUSE
value|6
end_define

begin_define
define|#
directive|define
name|LUA_GCSETSTEPMUL
value|7
end_define

begin_define
define|#
directive|define
name|LUA_GCSETMAJORINC
value|8
end_define

begin_define
define|#
directive|define
name|LUA_GCISRUNNING
value|9
end_define

begin_define
define|#
directive|define
name|LUA_GCGEN
value|10
end_define

begin_define
define|#
directive|define
name|LUA_GCINC
value|11
end_define

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_gc
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|what
parameter_list|,
name|int
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** miscellaneous functions */
end_comment

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_error
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_next
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_concat
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_len
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|lua_Alloc
function_decl|(
name|lua_getallocf
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|void
modifier|*
modifier|*
name|ud
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_setallocf
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|lua_Alloc
name|f
parameter_list|,
name|void
modifier|*
name|ud
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** =============================================================== ** some useful macros ** =============================================================== */
end_comment

begin_define
define|#
directive|define
name|lua_tonumber
parameter_list|(
name|L
parameter_list|,
name|i
parameter_list|)
value|lua_tonumberx(L,i,NULL)
end_define

begin_define
define|#
directive|define
name|lua_tointeger
parameter_list|(
name|L
parameter_list|,
name|i
parameter_list|)
value|lua_tointegerx(L,i,NULL)
end_define

begin_define
define|#
directive|define
name|lua_tounsigned
parameter_list|(
name|L
parameter_list|,
name|i
parameter_list|)
value|lua_tounsignedx(L,i,NULL)
end_define

begin_define
define|#
directive|define
name|lua_pop
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|)
value|lua_settop(L, -(n)-1)
end_define

begin_define
define|#
directive|define
name|lua_newtable
parameter_list|(
name|L
parameter_list|)
value|lua_createtable(L, 0, 0)
end_define

begin_define
define|#
directive|define
name|lua_register
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|,
name|f
parameter_list|)
value|(lua_pushcfunction(L, (f)), lua_setglobal(L, (n)))
end_define

begin_define
define|#
directive|define
name|lua_pushcfunction
parameter_list|(
name|L
parameter_list|,
name|f
parameter_list|)
value|lua_pushcclosure(L, (f), 0)
end_define

begin_define
define|#
directive|define
name|lua_isfunction
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|)
value|(lua_type(L, (n)) == LUA_TFUNCTION)
end_define

begin_define
define|#
directive|define
name|lua_istable
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|)
value|(lua_type(L, (n)) == LUA_TTABLE)
end_define

begin_define
define|#
directive|define
name|lua_islightuserdata
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|)
value|(lua_type(L, (n)) == LUA_TLIGHTUSERDATA)
end_define

begin_define
define|#
directive|define
name|lua_isnil
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|)
value|(lua_type(L, (n)) == LUA_TNIL)
end_define

begin_define
define|#
directive|define
name|lua_isboolean
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|)
value|(lua_type(L, (n)) == LUA_TBOOLEAN)
end_define

begin_define
define|#
directive|define
name|lua_isthread
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|)
value|(lua_type(L, (n)) == LUA_TTHREAD)
end_define

begin_define
define|#
directive|define
name|lua_isnone
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|)
value|(lua_type(L, (n)) == LUA_TNONE)
end_define

begin_define
define|#
directive|define
name|lua_isnoneornil
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|)
value|(lua_type(L, (n))<= 0)
end_define

begin_define
define|#
directive|define
name|lua_pushliteral
parameter_list|(
name|L
parameter_list|,
name|s
parameter_list|)
define|\
value|lua_pushlstring(L, "" s, (sizeof(s)/sizeof(char))-1)
end_define

begin_define
define|#
directive|define
name|lua_pushglobaltable
parameter_list|(
name|L
parameter_list|)
define|\
value|lua_rawgeti(L, LUA_REGISTRYINDEX, LUA_RIDX_GLOBALS)
end_define

begin_define
define|#
directive|define
name|lua_tostring
parameter_list|(
name|L
parameter_list|,
name|i
parameter_list|)
value|lua_tolstring(L, (i), NULL)
end_define

begin_comment
comment|/* ** {====================================================================== ** Debug API ** ======================================================================= */
end_comment

begin_comment
comment|/* ** Event codes */
end_comment

begin_define
define|#
directive|define
name|LUA_HOOKCALL
value|0
end_define

begin_define
define|#
directive|define
name|LUA_HOOKRET
value|1
end_define

begin_define
define|#
directive|define
name|LUA_HOOKLINE
value|2
end_define

begin_define
define|#
directive|define
name|LUA_HOOKCOUNT
value|3
end_define

begin_define
define|#
directive|define
name|LUA_HOOKTAILCALL
value|4
end_define

begin_comment
comment|/* ** Event masks */
end_comment

begin_define
define|#
directive|define
name|LUA_MASKCALL
value|(1<< LUA_HOOKCALL)
end_define

begin_define
define|#
directive|define
name|LUA_MASKRET
value|(1<< LUA_HOOKRET)
end_define

begin_define
define|#
directive|define
name|LUA_MASKLINE
value|(1<< LUA_HOOKLINE)
end_define

begin_define
define|#
directive|define
name|LUA_MASKCOUNT
value|(1<< LUA_HOOKCOUNT)
end_define

begin_typedef
typedef|typedef
name|struct
name|lua_Debug
name|lua_Debug
typedef|;
end_typedef

begin_comment
comment|/* activation record */
end_comment

begin_comment
comment|/* Functions to be called by the debugger in specific events */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|lua_Hook
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|lua_Debug
modifier|*
name|ar
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_getstack
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|level
parameter_list|,
name|lua_Debug
modifier|*
name|ar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_getinfo
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|char
modifier|*
name|what
parameter_list|,
name|lua_Debug
modifier|*
name|ar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
specifier|const
name|char
modifier|*
function_decl|(
name|lua_getlocal
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|lua_Debug
modifier|*
name|ar
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
specifier|const
name|char
modifier|*
function_decl|(
name|lua_setlocal
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|lua_Debug
modifier|*
name|ar
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
specifier|const
name|char
modifier|*
function_decl|(
name|lua_getupvalue
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|funcindex
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
specifier|const
name|char
modifier|*
function_decl|(
name|lua_setupvalue
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|funcindex
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
modifier|*
function_decl|(
name|lua_upvalueid
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|fidx
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|void
function_decl|(
name|lua_upvaluejoin
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|fidx1
parameter_list|,
name|int
name|n1
parameter_list|,
name|int
name|fidx2
parameter_list|,
name|int
name|n2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_sethook
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|lua_Hook
name|func
parameter_list|,
name|int
name|mask
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|lua_Hook
function_decl|(
name|lua_gethook
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_gethookmask
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUA_API
name|int
function_decl|(
name|lua_gethookcount
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|lua_Debug
block|{
name|int
name|event
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* (n) */
specifier|const
name|char
modifier|*
name|namewhat
decl_stmt|;
comment|/* (n) 'global', 'local', 'field', 'method' */
specifier|const
name|char
modifier|*
name|what
decl_stmt|;
comment|/* (S) 'Lua', 'C', 'main', 'tail' */
specifier|const
name|char
modifier|*
name|source
decl_stmt|;
comment|/* (S) */
name|int
name|currentline
decl_stmt|;
comment|/* (l) */
name|int
name|linedefined
decl_stmt|;
comment|/* (S) */
name|int
name|lastlinedefined
decl_stmt|;
comment|/* (S) */
name|unsigned
name|char
name|nups
decl_stmt|;
comment|/* (u) number of upvalues */
name|unsigned
name|char
name|nparams
decl_stmt|;
comment|/* (u) number of parameters */
name|char
name|isvararg
decl_stmt|;
comment|/* (u) */
name|char
name|istailcall
decl_stmt|;
comment|/* (t) */
name|char
name|short_src
index|[
name|LUA_IDSIZE
index|]
decl_stmt|;
comment|/* (S) */
comment|/* private part */
name|struct
name|CallInfo
modifier|*
name|i_ci
decl_stmt|;
comment|/* active function */
block|}
struct|;
end_struct

begin_comment
comment|/* }====================================================================== */
end_comment

begin_comment
comment|/****************************************************************************** * Copyright (C) 1994-2015 Lua.org, PUC-Rio. * * Permission is hereby granted, free of charge, to any person obtaining * a copy of this software and associated documentation files (the * "Software"), to deal in the Software without restriction, including * without limitation the rights to use, copy, modify, merge, publish, * distribute, sublicense, and/or sell copies of the Software, and to * permit persons to whom the Software is furnished to do so, subject to * the following conditions: * * The above copyright notice and this permission notice shall be * included in all copies or substantial portions of the Software. * * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. ******************************************************************************/
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

