begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: ldebug.h,v 2.7.1.1 2013/04/12 18:48:47 roberto Exp $ ** Auxiliary functions from Debug Interface module ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ldebug_h
end_ifndef

begin_define
define|#
directive|define
name|ldebug_h
end_define

begin_include
include|#
directive|include
file|"lstate.h"
end_include

begin_define
define|#
directive|define
name|pcRel
parameter_list|(
name|pc
parameter_list|,
name|p
parameter_list|)
value|(cast(int, (pc) - (p)->code) - 1)
end_define

begin_define
define|#
directive|define
name|getfuncline
parameter_list|(
name|f
parameter_list|,
name|pc
parameter_list|)
value|(((f)->lineinfo) ? (f)->lineinfo[pc] : 0)
end_define

begin_define
define|#
directive|define
name|resethookcount
parameter_list|(
name|L
parameter_list|)
value|(L->hookcount = L->basehookcount)
end_define

begin_comment
comment|/* Active Lua function (given call info) */
end_comment

begin_define
define|#
directive|define
name|ci_func
parameter_list|(
name|ci
parameter_list|)
value|(clLvalue((ci)->func))
end_define

begin_function_decl
name|LUAI_FUNC
name|l_noret
name|luaG_typeerror
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|TValue
modifier|*
name|o
parameter_list|,
specifier|const
name|char
modifier|*
name|opname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|l_noret
name|luaG_concaterror
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|StkId
name|p1
parameter_list|,
name|StkId
name|p2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|l_noret
name|luaG_aritherror
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|TValue
modifier|*
name|p1
parameter_list|,
specifier|const
name|TValue
modifier|*
name|p2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|l_noret
name|luaG_ordererror
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|TValue
modifier|*
name|p1
parameter_list|,
specifier|const
name|TValue
modifier|*
name|p2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|l_noret
name|luaG_runerror
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
name|LUAI_FUNC
name|l_noret
name|luaG_errormsg
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

