begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2014, Vsevolod Stakhov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *       * Redistributions of source code must retain the above copyright  *         notice, this list of conditions and the following disclaimer.  *       * Redistributions in binary form must reproduce the above copyright  *         notice, this list of conditions and the following disclaimer in the  *         documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED ''AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL AUTHOR BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LUA_UCL_H_
end_ifndef

begin_define
define|#
directive|define
name|LUA_UCL_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<lua.h>
end_include

begin_include
include|#
directive|include
file|<lauxlib.h>
end_include

begin_include
include|#
directive|include
file|<lualib.h>
end_include

begin_include
include|#
directive|include
file|"ucl.h"
end_include

begin_comment
comment|/**  * Closure structure for lua function storing inside UCL  */
end_comment

begin_struct
struct|struct
name|ucl_lua_funcdata
block|{
name|lua_State
modifier|*
name|L
decl_stmt|;
name|int
name|idx
decl_stmt|;
name|char
modifier|*
name|ret
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Initialize lua UCL API  */
end_comment

begin_function_decl
name|UCL_EXTERN
name|int
name|luaopen_ucl
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Import UCL object from lua state  * @param L lua state  * @param idx index of object at the lua stack to convert to UCL  * @return new UCL object or NULL, the caller should unref object after using  */
end_comment

begin_function_decl
name|UCL_EXTERN
name|ucl_object_t
modifier|*
name|ucl_object_lua_import
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
comment|/**  * Push an object to lua  * @param L lua state  * @param obj object to push  * @param allow_array traverse over implicit arrays  */
end_comment

begin_function_decl
name|UCL_EXTERN
name|int
name|ucl_object_push_lua
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|,
name|bool
name|allow_array
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UCL_EXTERN
name|struct
name|ucl_lua_funcdata
modifier|*
name|ucl_object_toclosure
parameter_list|(
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LUA_UCL_H_ */
end_comment

end_unit

