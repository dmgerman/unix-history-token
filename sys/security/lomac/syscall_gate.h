begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by NAI Labs, the  * Security Research Division of Network Associates, Inc. under  * DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA  * CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYSCALL_GATE_H
end_ifndef

begin_define
define|#
directive|define
name|SYSCALL_GATE_H
end_define

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|syscall_gate
block|{
name|struct
name|sx
name|sg_lock
decl_stmt|;
comment|/* syscalls entered into the kernel */
name|struct
name|sysent
modifier|*
name|sg_table
decl_stmt|;
name|struct
name|sysent
name|sg_oldsyscalls
index|[
name|SYS_MAXSYSCALL
index|]
decl_stmt|;
name|struct
name|sysent
name|sg_newsyscalls
index|[
name|SYS_MAXSYSCALL
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_function_decl
name|int
name|syscall_gate_register
parameter_list|(
name|int
name|offset
parameter_list|,
name|sy_call_t
modifier|*
name|func
parameter_list|,
name|int
name|nargs
parameter_list|,
name|int
name|mpsafe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|syscall_gate_deregister
parameter_list|(
name|int
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSCALL_GATE_H */
end_comment

end_unit

