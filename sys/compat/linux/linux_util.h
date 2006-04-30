begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 Christos Zoulas  * Copyright (c) 1995 Frank van der Linden  * Copyright (c) 1995 Scott Bartram  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * from: svr4_util.h,v 1.5 1994/11/18 02:54:31 christos Exp  * from: linux_util.h,v 1.2 1995/03/05 23:23:50 fvdl Exp  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This file is pretty much the same as Christos' svr4_util.h  * (for now).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_UTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_UTIL_H_
end_define

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_function_decl
specifier|static
name|__inline
name|caddr_t
name|stackgap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
modifier|*
name|stackgap_alloc
parameter_list|(
name|caddr_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|szsigcode
value|(*(curthread->td_proc->p_sysent->sv_szsigcode))
end_define

begin_define
define|#
directive|define
name|psstrings
value|(curthread->td_proc->p_sysent->sv_psstrings)
end_define

begin_function
specifier|static
name|__inline
name|caddr_t
name|stackgap_init
parameter_list|()
block|{
return|return
call|(
name|caddr_t
call|)
argument_list|(
name|psstrings
operator|-
name|szsigcode
operator|-
name|SPARE_USRSPACE
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|stackgap_alloc
parameter_list|(
name|sgp
parameter_list|,
name|sz
parameter_list|)
name|caddr_t
modifier|*
name|sgp
decl_stmt|;
name|size_t
name|sz
decl_stmt|;
block|{
name|void
modifier|*
name|p
init|=
operator|(
name|void
operator|*
operator|)
operator|*
name|sgp
decl_stmt|;
name|sz
operator|=
name|ALIGN
argument_list|(
name|sz
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|sgp
operator|+
name|sz
operator|>
call|(
name|caddr_t
call|)
argument_list|(
name|psstrings
operator|-
name|szsigcode
argument_list|)
condition|)
return|return
name|NULL
return|;
operator|*
name|sgp
operator|+=
name|sz
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|linux_emul_path
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|linux_emul_convpath
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|enum
name|uio_seg
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LCONVPATH
parameter_list|(
name|td
parameter_list|,
name|upath
parameter_list|,
name|pathp
parameter_list|,
name|i
parameter_list|)
define|\
value|do {								\ 		int _error;						\ 									\ 		_error = linux_emul_convpath(td, upath, UIO_USERSPACE,  \ 		    pathp, i);						\ 		if (*(pathp) == NULL)					\ 			return (_error);				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|LCONVPATHEXIST
parameter_list|(
name|td
parameter_list|,
name|upath
parameter_list|,
name|pathp
parameter_list|)
value|LCONVPATH(td, upath, pathp, 0)
end_define

begin_define
define|#
directive|define
name|LCONVPATHCREAT
parameter_list|(
name|td
parameter_list|,
name|upath
parameter_list|,
name|pathp
parameter_list|)
value|LCONVPATH(td, upath, pathp, 1)
end_define

begin_define
define|#
directive|define
name|LFREEPATH
parameter_list|(
name|path
parameter_list|)
value|free(path, M_TEMP)
end_define

begin_define
define|#
directive|define
name|DUMMY
parameter_list|(
name|s
parameter_list|)
define|\
value|int									\ linux_ ## s(struct thread *td, struct linux_ ## s ## _args *args)	\ {									\ 	static pid_t pid;						\ 									\ 	if (pid != td->td_proc->p_pid) {				\ 		linux_msg(td, "syscall %s not implemented", #s);	\ 		pid = td->td_proc->p_pid;				\ 	};								\ 	return (ENOSYS);						\ }									\ struct __hack
end_define

begin_function_decl
name|void
name|linux_msg
parameter_list|(
specifier|const
name|struct
name|thread
modifier|*
name|td
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LINUX_UTIL_H_ */
end_comment

end_unit

