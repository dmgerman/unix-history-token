begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Ilmar S. Habibulin  * Copyright (c) 2000-2001 Robert N. M. Watson  * Copyright (c) 2001 Thomas Moestl  * All rights reserved.  *  * This software was developed by Robert Watson, Thomas Moestl, and Ilmar  * Habibulin for the TrustedBSD Project.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Developed by the TrustedBSD Project.  * Support for POSIX.1e process capabilities.  *  * XXX: Currently just syscall stubs.  */
end_comment

begin_include
include|#
directive|include
file|"opt_cap.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysproto.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/acct.h>
end_include

begin_include
include|#
directive|include
file|<sys/capability.h>
end_include

begin_include
include|#
directive|include
file|<sys/extattr.h>
end_include

begin_include
include|#
directive|include
file|<sys/jail.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/namei.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CAPABILITIES
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|capabilities_enabled
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_kern_security
argument_list|,
name|OID_AUTO
argument_list|,
name|capabilities
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"POSIX.1e Capabilities"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_kern_security_capabilities
argument_list|,
name|OID_AUTO
argument_list|,
name|enabled
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|capabilities_enabled
argument_list|,
literal|0
argument_list|,
literal|"POSIX.1e Capabilities enabled"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Syscall to allow a process to get it's currently capability set  */
end_comment

begin_function
name|int
name|__cap_get_proc
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|__cap_get_proc_args
modifier|*
name|uap
parameter_list|)
block|{
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Syscall to allow a process to set it's current capability set, if  * permitted.  */
end_comment

begin_function
name|int
name|__cap_set_proc
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|__cap_set_proc_args
modifier|*
name|uap
parameter_list|)
block|{
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Syscalls to allow a process to retrieve capabilities associated with  * files, if permitted.  */
end_comment

begin_function
name|int
name|__cap_get_fd
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|__cap_get_fd_args
modifier|*
name|uap
parameter_list|)
block|{
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_function
name|int
name|__cap_get_file
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|__cap_get_file_args
modifier|*
name|uap
parameter_list|)
block|{
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Syscalls to allow a process to set capabilities associated with files,  * if permitted.  */
end_comment

begin_function
name|int
name|__cap_set_fd
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|__cap_set_fd_args
modifier|*
name|uap
parameter_list|)
block|{
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_function
name|int
name|__cap_set_file
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|__cap_set_file_args
modifier|*
name|uap
parameter_list|)
block|{
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

end_unit

