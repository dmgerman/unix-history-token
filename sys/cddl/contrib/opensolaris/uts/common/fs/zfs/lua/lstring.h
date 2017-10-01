begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: lstring.h,v 1.49.1.1 2013/04/12 18:48:47 roberto Exp $ ** String table (keep all strings handled by Lua) ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lstring_h
end_ifndef

begin_define
define|#
directive|define
name|lstring_h
end_define

begin_include
include|#
directive|include
file|"lgc.h"
end_include

begin_include
include|#
directive|include
file|"lobject.h"
end_include

begin_include
include|#
directive|include
file|"lstate.h"
end_include

begin_define
define|#
directive|define
name|sizestring
parameter_list|(
name|s
parameter_list|)
value|(sizeof(union TString)+((s)->len+1)*sizeof(char))
end_define

begin_define
define|#
directive|define
name|sizeudata
parameter_list|(
name|u
parameter_list|)
value|(sizeof(union Udata)+(u)->len)
end_define

begin_define
define|#
directive|define
name|luaS_newliteral
parameter_list|(
name|L
parameter_list|,
name|s
parameter_list|)
value|(luaS_newlstr(L, "" s, \                                  (sizeof(s)/sizeof(char))-1))
end_define

begin_define
define|#
directive|define
name|luaS_fix
parameter_list|(
name|s
parameter_list|)
value|l_setbit((s)->tsv.marked, FIXEDBIT)
end_define

begin_comment
comment|/* ** test whether a string is a reserved word */
end_comment

begin_define
define|#
directive|define
name|isreserved
parameter_list|(
name|s
parameter_list|)
value|((s)->tsv.tt == LUA_TSHRSTR&& (s)->tsv.extra> 0)
end_define

begin_comment
comment|/* ** equality for short strings, which are always internalized */
end_comment

begin_define
define|#
directive|define
name|eqshrstr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|check_exp((a)->tsv.tt == LUA_TSHRSTR, (a) == (b))
end_define

begin_function_decl
name|LUAI_FUNC
name|unsigned
name|int
name|luaS_hash
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|l
parameter_list|,
name|unsigned
name|int
name|seed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|int
name|luaS_eqlngstr
parameter_list|(
name|TString
modifier|*
name|a
parameter_list|,
name|TString
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|int
name|luaS_eqstr
parameter_list|(
name|TString
modifier|*
name|a
parameter_list|,
name|TString
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaS_resize
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|newsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|Udata
modifier|*
name|luaS_newudata
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|size_t
name|s
parameter_list|,
name|Table
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|TString
modifier|*
name|luaS_newlstr
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|TString
modifier|*
name|luaS_new
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

