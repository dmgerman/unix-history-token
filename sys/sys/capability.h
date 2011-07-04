begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2010 Robert N. M. Watson  * All rights reserved.  *  * This software was developed at the University of Cambridge Computer  * Laboratory with support from a grant from Google, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for FreeBSD capabilities facility.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CAPABILITY_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CAPABILITY_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_comment
comment|/*  * Possible rights on capabilities.  *  * Notes:  * Some system calls don't require a capability in order to perform an  * operation on an fd.  These include: close, dup, dup2.  *  * sendfile is authorized using CAP_READ on the file and CAP_WRITE on the  * socket.  *  * mmap() and aio*() system calls will need special attention as they may  * involve reads or writes depending a great deal on context.  */
end_comment

begin_define
define|#
directive|define
name|CAP_READ
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* read/recv */
end_comment

begin_define
define|#
directive|define
name|CAP_WRITE
value|0x0000000000000002ULL
end_define

begin_comment
comment|/* write/send */
end_comment

begin_define
define|#
directive|define
name|CAP_MMAP
value|0x0000000000000004ULL
end_define

begin_comment
comment|/* mmap */
end_comment

begin_define
define|#
directive|define
name|CAP_MAPEXEC
value|0x0000000000000008ULL
end_define

begin_comment
comment|/* mmap(2) as exec */
end_comment

begin_define
define|#
directive|define
name|CAP_MASK_VALID
value|0x000000000000000fULL
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IN_CAPABILITY_MODE
parameter_list|(
name|td
parameter_list|)
value|(td->td_ucred->cr_flags& CRED_FLAG_CAPMODE)
end_define

begin_comment
comment|/*  * Unwrap a capability if its rights mask is a superset of 'rights'.  *  * Unwrapping a non-capability is effectively a no-op; the value of fp_cap  * is simply copied into fpp.  */
end_comment

begin_function_decl
name|int
name|cap_funwrap
parameter_list|(
name|struct
name|file
modifier|*
name|fp_cap
parameter_list|,
name|cap_rights_t
name|rights
parameter_list|,
name|struct
name|file
modifier|*
modifier|*
name|fpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cap_funwrap_mmap
parameter_list|(
name|struct
name|file
modifier|*
name|fp_cap
parameter_list|,
name|cap_rights_t
name|rights
parameter_list|,
name|u_char
modifier|*
name|maxprotp
parameter_list|,
name|struct
name|file
modifier|*
modifier|*
name|fpp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * For the purposes of procstat(1) and similar tools, allow kern_descrip.c to  * extract the rights from a capability.  However, this should not be used by  * kernel code generally, instead cap_funwrap() should be used in order to  * keep all access control in one place.  */
end_comment

begin_function_decl
name|cap_rights_t
name|cap_rights
parameter_list|(
name|struct
name|file
modifier|*
name|fp_cap
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * cap_enter(): Cause the process to enter capability mode, which will  * prevent it from directly accessing global namespaces.  System calls will  * be limited to process-local, process-inherited, or file descriptor  * operations.  If already in capability mode, a no-op.  *  * Currently, process-inherited operations are not properly handled -- in  * particular, we're interested in things like waitpid(2), kill(2), etc,  * being properly constrained.  One possible solution is to introduce process  * descriptors.  */
name|int
name|cap_enter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * cap_getmode(): Are we in capability mode?  */
end_comment

begin_function_decl
name|int
name|cap_getmode
parameter_list|(
name|u_int
modifier|*
name|modep
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
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_CAPABILITY_H_ */
end_comment

end_unit

