begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: lapi.h,v 2.7.1.1 2013/04/12 18:48:47 roberto Exp $ ** Auxiliary functions from Lua API ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lapi_h
end_ifndef

begin_define
define|#
directive|define
name|lapi_h
end_define

begin_include
include|#
directive|include
file|"llimits.h"
end_include

begin_include
include|#
directive|include
file|"lstate.h"
end_include

begin_define
define|#
directive|define
name|api_incr_top
parameter_list|(
name|L
parameter_list|)
value|{L->top++; api_check(L, L->top<= L->ci->top, \ 				"stack overflow");}
end_define

begin_define
define|#
directive|define
name|adjustresults
parameter_list|(
name|L
parameter_list|,
name|nres
parameter_list|)
define|\
value|{ if ((nres) == LUA_MULTRET&& L->ci->top< L->top) L->ci->top = L->top; }
end_define

begin_define
define|#
directive|define
name|api_checknelems
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|)
value|api_check(L, (n)< (L->top - L->ci->func), \ 				  "not enough elements in the stack")
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

