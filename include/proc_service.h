begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 David Xu<davidxu@freebsd.org>  * Copyright (c) 2004 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PROC_SERVICE_H_
end_ifndef

begin_define
define|#
directive|define
name|_PROC_SERVICE_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/procfs.h>
end_include

begin_typedef
typedef|typedef
enum|enum
block|{
name|PS_OK
init|=
literal|0
block|,
comment|/* No errors. */
name|PS_ERR
block|,
comment|/* Generic error. */
name|PS_BADADDR
block|,
comment|/* Bad address. */
name|PS_BADLID
block|,
comment|/* Bad LWP Id. */
name|PS_BADPID
block|,
comment|/* Bad process Id. */
name|PS_NOFREGS
block|,
comment|/* FPU register set not available. */
name|PS_NOSYM
comment|/* Symbol not found. */
block|}
name|ps_err_e
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|ps_prochandle
struct_decl|;
end_struct_decl

begin_comment
comment|/* Opaque type. Defined by the implementor. */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|ps_err_e
name|ps_lcontinue
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
parameter_list|,
name|lwpid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ps_err_e
name|ps_lgetfpregs
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
parameter_list|,
name|lwpid_t
parameter_list|,
name|prfpregset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ps_err_e
name|ps_lgetregs
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
parameter_list|,
name|lwpid_t
parameter_list|,
name|prgregset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ps_err_e
name|ps_lsetfpregs
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
parameter_list|,
name|lwpid_t
parameter_list|,
specifier|const
name|prfpregset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ps_err_e
name|ps_lsetregs
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
parameter_list|,
name|lwpid_t
parameter_list|,
specifier|const
name|prgregset_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_function_decl
name|ps_err_e
name|ps_lgetxmmregs
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
parameter_list|,
name|lwpid_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ps_err_e
name|ps_lsetxmmregs
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
parameter_list|,
name|lwpid_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ps_err_e
name|ps_lstop
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
parameter_list|,
name|lwpid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ps_err_e
name|ps_linfo
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
parameter_list|,
name|lwpid_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ps_err_e
name|ps_pcontinue
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ps_err_e
name|ps_pdmodel
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ps_err_e
name|ps_pglobal_lookup
parameter_list|(
name|struct
name|ps_prochandle
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
name|psaddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ps_plog
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ps_err_e
name|ps_pread
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
parameter_list|,
name|psaddr_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ps_err_e
name|ps_pstop
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ps_err_e
name|ps_pwrite
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
parameter_list|,
name|psaddr_t
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
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
comment|/* _PROC_SERVICE_H_ */
end_comment

end_unit

