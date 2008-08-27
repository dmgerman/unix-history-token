begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 John Birrell (jb@freebsd.org)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBPROC_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBPROC_H_
end_define

begin_include
include|#
directive|include
file|<gelf.h>
end_include

begin_struct_decl
struct_decl|struct
name|proc_handle
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|proc_child_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Values returned by proc_state(). */
end_comment

begin_define
define|#
directive|define
name|PS_IDLE
value|1
end_define

begin_define
define|#
directive|define
name|PS_STOP
value|2
end_define

begin_define
define|#
directive|define
name|PS_RUN
value|3
end_define

begin_define
define|#
directive|define
name|PS_UNDEAD
value|4
end_define

begin_define
define|#
directive|define
name|PS_DEAD
value|5
end_define

begin_define
define|#
directive|define
name|PS_LOST
value|6
end_define

begin_typedef
typedef|typedef
struct|struct
name|prmap
block|{
name|uintptr_t
name|pr_vaddr
decl_stmt|;
comment|/* Virtual address. */
block|}
name|prmap_t
typedef|;
end_typedef

begin_comment
comment|/* Function prototype definitions. */
end_comment

begin_function_decl
name|__BEGIN_DECLS
specifier|const
name|prmap_t
modifier|*
name|proc_addr2map
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|prmap_t
modifier|*
name|proc_name2map
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|proc_objname
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_addr2sym
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|GElf_Sym
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_attach
parameter_list|(
name|pid_t
name|pid
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|proc_handle
modifier|*
modifier|*
name|pphdl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_continue
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_clearflags
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_create
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
name|proc_child_func
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|proc_handle
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_detach
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_getflags
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_name2sym
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|GElf_Sym
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_setflags
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_state
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_wait
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|proc_getpid
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|proc_free
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBPROC_H_ */
end_comment

end_unit

