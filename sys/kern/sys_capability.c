begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2011 Robert N. M. Watson  * Copyright (c) 2010-2011 Jonathan Anderson  * All rights reserved.  *  * This software was developed at the University of Cambridge Computer  * Laboratory with support from a grant from Google, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * FreeBSD kernel capability facility.  *  * Currently, this file implements only capability mode; capabilities  * (rights-refined file descriptors) will follow.  *  */
end_comment

begin_include
include|#
directive|include
file|"opt_capabilities.h"
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/capability.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/filedesc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
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
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysproto.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_include
include|#
directive|include
file|<security/audit/audit.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CAPABILITIES
end_ifdef

begin_expr_stmt
name|FEATURE
argument_list|(
name|security_capabilities
argument_list|,
literal|"Capsicum Capability Mode"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * We don't currently have any MIB entries for sysctls, but we do expose  * security.capabilities so that it's easy to tell if options CAPABILITIES is  * compiled into the kernel.  */
end_comment

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_security
argument_list|,
name|OID_AUTO
argument_list|,
name|capabilities
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"Capsicum"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * System call to enter capability mode for the process.  */
end_comment

begin_function
name|int
name|cap_enter
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|cap_enter_args
modifier|*
name|uap
parameter_list|)
block|{
name|struct
name|ucred
modifier|*
name|newcred
decl_stmt|,
modifier|*
name|oldcred
decl_stmt|;
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
if|if
condition|(
name|IN_CAPABILITY_MODE
argument_list|(
name|td
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|newcred
operator|=
name|crget
argument_list|()
expr_stmt|;
name|p
operator|=
name|td
operator|->
name|td_proc
expr_stmt|;
name|PROC_LOCK
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|oldcred
operator|=
name|p
operator|->
name|p_ucred
expr_stmt|;
name|crcopy
argument_list|(
name|newcred
argument_list|,
name|oldcred
argument_list|)
expr_stmt|;
name|newcred
operator|->
name|cr_flags
operator||=
name|CRED_FLAG_CAPMODE
expr_stmt|;
name|p
operator|->
name|p_ucred
operator|=
name|newcred
expr_stmt|;
name|PROC_UNLOCK
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|crfree
argument_list|(
name|oldcred
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * System call to query whether the process is in capability mode.  */
end_comment

begin_function
name|int
name|cap_getmode
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|cap_getmode_args
modifier|*
name|uap
parameter_list|)
block|{
name|u_int
name|i
decl_stmt|;
name|i
operator|=
operator|(
name|IN_CAPABILITY_MODE
argument_list|(
name|td
argument_list|)
operator|)
condition|?
literal|1
else|:
literal|0
expr_stmt|;
return|return
operator|(
name|copyout
argument_list|(
operator|&
name|i
argument_list|,
name|uap
operator|->
name|modep
argument_list|,
sizeof|sizeof
argument_list|(
name|i
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !CAPABILITIES */
end_comment

begin_function
name|int
name|cap_enter
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|cap_enter_args
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
name|cap_getmode
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|cap_getmode_args
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CAPABILITIES */
end_comment

end_unit

