begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: lfunc.h,v 2.8.1.1 2013/04/12 18:48:47 roberto Exp $ ** Auxiliary functions to manipulate prototypes and closures ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lfunc_h
end_ifndef

begin_define
define|#
directive|define
name|lfunc_h
end_define

begin_include
include|#
directive|include
file|"lobject.h"
end_include

begin_define
define|#
directive|define
name|sizeCclosure
parameter_list|(
name|n
parameter_list|)
value|(cast(int, sizeof(CClosure)) + \                          cast(int, sizeof(TValue)*((n)-1)))
end_define

begin_define
define|#
directive|define
name|sizeLclosure
parameter_list|(
name|n
parameter_list|)
value|(cast(int, sizeof(LClosure)) + \                          cast(int, sizeof(TValue *)*((n)-1)))
end_define

begin_function_decl
name|LUAI_FUNC
name|Proto
modifier|*
name|luaF_newproto
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|Closure
modifier|*
name|luaF_newCclosure
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|nelems
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|Closure
modifier|*
name|luaF_newLclosure
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|nelems
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|UpVal
modifier|*
name|luaF_newupval
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|UpVal
modifier|*
name|luaF_findupval
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|StkId
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaF_close
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|StkId
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaF_freeproto
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|Proto
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaF_freeupval
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|UpVal
modifier|*
name|uv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
specifier|const
name|char
modifier|*
name|luaF_getlocalname
parameter_list|(
specifier|const
name|Proto
modifier|*
name|func
parameter_list|,
name|int
name|local_number
parameter_list|,
name|int
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

