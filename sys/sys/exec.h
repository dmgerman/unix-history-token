begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)exec.h	8.3 (Berkeley) 1/21/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_EXEC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_EXEC_H_
end_define

begin_comment
comment|/*  * The following structure is found at the top of the user stack of each  * user process. The ps program uses it to locate argv and environment  * strings. Programs that wish ps to display other information may modify  * it; normally ps_argvstr points to the argv vector, and ps_nargvstr  * is the same as the program's argc. The fields ps_envstr and ps_nenvstr  * are the equivalent for the environment.  */
end_comment

begin_struct
struct|struct
name|ps_strings
block|{
name|char
modifier|*
modifier|*
name|ps_argvstr
decl_stmt|;
comment|/* first of 0 or more argument strings */
name|int
name|ps_nargvstr
decl_stmt|;
comment|/* the number of argument strings */
name|char
modifier|*
modifier|*
name|ps_envstr
decl_stmt|;
comment|/* first of 0 or more environment strings */
name|int
name|ps_nenvstr
decl_stmt|;
comment|/* the number of environment strings */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Address of ps_strings structure (in user space).  */
end_comment

begin_define
define|#
directive|define
name|PS_STRINGS
value|(USRSTACK - sizeof(struct ps_strings))
end_define

begin_define
define|#
directive|define
name|SPARE_USRSPACE
value|256
end_define

begin_struct_decl
struct_decl|struct
name|image_params
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|execsw
block|{
name|int
function_decl|(
modifier|*
name|ex_imgact
function_decl|)
parameter_list|(
name|struct
name|image_params
modifier|*
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|ex_name
decl_stmt|;
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|<machine/exec.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|int
name|exec_map_first_page
parameter_list|(
name|struct
name|image_params
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|exec_unmap_first_page
parameter_list|(
name|struct
name|image_params
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|exec_register
parameter_list|(
specifier|const
name|struct
name|execsw
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|exec_unregister
parameter_list|(
specifier|const
name|struct
name|execsw
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * note: name##_mod cannot be const storage because the  * linker_file_sysinit() function modifies _file in the  * moduledata_t.  */
end_comment

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_define
define|#
directive|define
name|EXEC_SET
parameter_list|(
name|name
parameter_list|,
name|execsw_arg
parameter_list|)
define|\
value|static int name ## _modevent(module_t mod, int type, void *data) \ 	{ \ 		struct execsw *exec = (struct execsw *)data; \ 		int error = 0; \ 		switch (type) { \ 		case MOD_LOAD: \
comment|/* printf(#name " module loaded\n"); */
value|\ 			error = exec_register(exec); \ 			if (error) \ 				printf(#name "register failed\n"); \ 			break; \ 		case MOD_UNLOAD: \
comment|/* printf(#name " module unloaded\n"); */
value|\ 			error = exec_unregister(exec); \ 			if (error) \ 				printf(#name " unregister failed\n"); \ 			break; \ 		default: \ 			break; \ 		} \ 		return error; \ 	} \ 	static moduledata_t name ## _mod = { \ 		#name, \ 		name ## _modevent, \ 		(void *)& execsw_arg \ 	}; \ 	DECLARE_MODULE(name, name ## _mod, SI_SUB_EXEC, SI_ORDER_ANY)
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

