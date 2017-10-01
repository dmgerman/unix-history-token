begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: ldo.h,v 2.20.1.1 2013/04/12 18:48:47 roberto Exp $ ** Stack and Call structure of Lua ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ldo_h
end_ifndef

begin_define
define|#
directive|define
name|ldo_h
end_define

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

begin_include
include|#
directive|include
file|"lzio.h"
end_include

begin_define
define|#
directive|define
name|luaD_checkstack
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|)
value|if (L->stack_last - L->top<= (n)) \ 				    luaD_growstack(L, n); else condmovestack(L);
end_define

begin_define
define|#
directive|define
name|incr_top
parameter_list|(
name|L
parameter_list|)
value|{L->top++; luaD_checkstack(L,0);}
end_define

begin_define
define|#
directive|define
name|savestack
parameter_list|(
name|L
parameter_list|,
name|p
parameter_list|)
value|((char *)(p) - (char *)L->stack)
end_define

begin_define
define|#
directive|define
name|restorestack
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|)
value|((TValue *)((char *)L->stack + (n)))
end_define

begin_comment
comment|/* type of protected functions, to be ran by `runprotected' */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|Pfunc
function_decl|)
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|void
modifier|*
name|ud
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|LUAI_FUNC
name|int
name|luaD_protectedparser
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|ZIO
modifier|*
name|z
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaD_hook
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|event
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|int
name|luaD_precall
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|StkId
name|func
parameter_list|,
name|int
name|nresults
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaD_call
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|StkId
name|func
parameter_list|,
name|int
name|nResults
parameter_list|,
name|int
name|allowyield
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|int
name|luaD_pcall
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|Pfunc
name|func
parameter_list|,
name|void
modifier|*
name|u
parameter_list|,
name|ptrdiff_t
name|oldtop
parameter_list|,
name|ptrdiff_t
name|ef
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|int
name|luaD_poscall
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|StkId
name|firstResult
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaD_reallocstack
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
name|void
name|luaD_growstack
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
name|LUAI_FUNC
name|void
name|luaD_shrinkstack
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|l_noret
name|luaD_throw
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|errcode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|int
name|luaD_rawrunprotected
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|Pfunc
name|f
parameter_list|,
name|void
modifier|*
name|ud
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

