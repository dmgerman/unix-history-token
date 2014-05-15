begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * services/modstack.h - stack of modules  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions to help maintain a stack of modules.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SERVICES_MODSTACK_H
end_ifndef

begin_define
define|#
directive|define
name|SERVICES_MODSTACK_H
end_define

begin_struct_decl
struct_decl|struct
name|module_func_block
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_env
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Stack of modules.  */
end_comment

begin_struct
struct|struct
name|module_stack
block|{
comment|/** the number of modules */
name|int
name|num
decl_stmt|;
comment|/** the module callbacks, array of num_modules length (ref only) */
name|struct
name|module_func_block
modifier|*
modifier|*
name|mod
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Init a stack of modules  * @param stack: initialised as empty.  */
end_comment

begin_function_decl
name|void
name|modstack_init
parameter_list|(
name|struct
name|module_stack
modifier|*
name|stack
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Read config file module settings and set up the modfunc block  * @param stack: the stack of modules (empty before call).   * @param module_conf: string what modules to insert.  * @return false on error  */
end_comment

begin_function_decl
name|int
name|modstack_config
parameter_list|(
name|struct
name|module_stack
modifier|*
name|stack
parameter_list|,
specifier|const
name|char
modifier|*
name|module_conf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get funcblock for module name  * @param str: string with module name. Advanced to next value on success.  *	The string is assumed whitespace separated list of module names.  * @return funcblock or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|module_func_block
modifier|*
name|module_factory
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get list of modules available.  * @return list of modules available. Static strings, ends with NULL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
modifier|*
name|module_list_avail
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Setup modules. Assigns ids and calls module_init.  * @param stack: if not empty beforehand, it will be desetup()ed.  *	It is then modstack_configged().  * @param module_conf: string what modules to insert.  * @param env: module environment which is inited by the modules.  *	environment should have a superalloc, cfg,  *	env.need_to_validate is set by the modules.  * @return on false a module init failed.  */
end_comment

begin_function_decl
name|int
name|modstack_setup
parameter_list|(
name|struct
name|module_stack
modifier|*
name|stack
parameter_list|,
specifier|const
name|char
modifier|*
name|module_conf
parameter_list|,
name|struct
name|module_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Desetup the modules, deinit, delete.  * @param stack: made empty.  * @param env: module env for module deinit() calls.  */
end_comment

begin_function_decl
name|void
name|modstack_desetup
parameter_list|(
name|struct
name|module_stack
modifier|*
name|stack
parameter_list|,
name|struct
name|module_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find index of module by name.  * @param stack: to look in  * @param name: the name to look for  * @return -1 on failure, otherwise index number.  */
end_comment

begin_function_decl
name|int
name|modstack_find
parameter_list|(
name|struct
name|module_stack
modifier|*
name|stack
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SERVICES_MODSTACK_H */
end_comment

end_unit

