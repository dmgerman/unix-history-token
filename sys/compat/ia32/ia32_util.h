begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998-1999 Andrew Gallatin  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_IA32_IA32_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_IA32_IA32_UTIL_H
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
file|<sys/cdefs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__ia64__
end_ifdef

begin_define
define|#
directive|define
name|FREEBSD32_MAXUSER
value|((1ul<< 32) - IA32_PAGE_SIZE * 2)
end_define

begin_define
define|#
directive|define
name|FREEBSD32_SHAREDPAGE
value|0
end_define

begin_define
define|#
directive|define
name|FREEBSD32_USRSTACK
value|FREEBSD32_MAXUSER
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FREEBSD32_MAXUSER
value|((1ul<< 32) - IA32_PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|FREEBSD32_SHAREDPAGE
value|(FREEBSD32_MAXUSER - IA32_PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|FREEBSD32_USRSTACK
value|FREEBSD32_SHAREDPAGE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IA32_PAGE_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|IA32_MAXDSIZ
value|(512*1024*1024)
end_define

begin_comment
comment|/* 512MB */
end_comment

begin_define
define|#
directive|define
name|IA32_MAXSSIZ
value|(64*1024*1024)
end_define

begin_comment
comment|/* 64MB */
end_comment

begin_define
define|#
directive|define
name|IA32_MAXVMEM
value|0
end_define

begin_comment
comment|/* Unlimited */
end_comment

begin_struct_decl
struct_decl|struct
name|syscall_args
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ia32_fetch_syscall_args
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|syscall_args
modifier|*
name|sa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ia32_set_syscall_retval
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

