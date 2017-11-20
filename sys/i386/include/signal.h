begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1986, 1989, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)signal.h	8.1 (Berkeley) 6/11/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SIGNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SIGNAL_H_
end_define

begin_include
include|#
directive|include
file|<x86/signal.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|COMPAT_43
argument_list|)
end_if

begin_comment
comment|/*  * Only the kernel should need these old type definitions.  */
end_comment

begin_struct
struct|struct
name|osigcontext
block|{
name|int
name|sc_onstack
decl_stmt|;
comment|/* sigstack state to restore */
name|osigset_t
name|sc_mask
decl_stmt|;
comment|/* signal mask to restore */
name|int
name|sc_esp
decl_stmt|;
comment|/* machine state follows: */
name|int
name|sc_ebp
decl_stmt|;
name|int
name|sc_isp
decl_stmt|;
name|int
name|sc_eip
decl_stmt|;
name|int
name|sc_efl
decl_stmt|;
name|int
name|sc_es
decl_stmt|;
name|int
name|sc_ds
decl_stmt|;
name|int
name|sc_cs
decl_stmt|;
name|int
name|sc_ss
decl_stmt|;
name|int
name|sc_edi
decl_stmt|;
name|int
name|sc_esi
decl_stmt|;
name|int
name|sc_ebx
decl_stmt|;
name|int
name|sc_edx
decl_stmt|;
name|int
name|sc_ecx
decl_stmt|;
name|int
name|sc_eax
decl_stmt|;
name|int
name|sc_gs
decl_stmt|;
name|int
name|sc_fs
decl_stmt|;
name|int
name|sc_trapno
decl_stmt|;
name|int
name|sc_err
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SIGNAL_H_ */
end_comment

end_unit

