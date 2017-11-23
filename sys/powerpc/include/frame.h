begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-4-Clause  *  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: frame.h,v 1.2 1999/01/10 10:13:15 tsubai Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_FRAME_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_FRAME_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * We have to save all registers on every trap, because  *	1. user could attach this process every time  *	2. we must be able to restore all user registers in case of fork  * Actually, we do not save the fp registers on trap, since  * these are not used by the kernel. They are saved only when switching  * between processes using the FPU.  *  * Change ordering to cluster together these register_t's.		XXX  */
end_comment

begin_struct
struct|struct
name|trapframe
block|{
name|register_t
name|fixreg
index|[
literal|32
index|]
decl_stmt|;
name|register_t
name|lr
decl_stmt|;
name|register_t
name|cr
decl_stmt|;
name|register_t
name|xer
decl_stmt|;
name|register_t
name|ctr
decl_stmt|;
name|register_t
name|srr0
decl_stmt|;
name|register_t
name|srr1
decl_stmt|;
name|register_t
name|exc
decl_stmt|;
name|register_t
name|dar
decl_stmt|;
comment|/* DAR/DEAR filled in on DSI traps */
union|union
block|{
struct|struct
block|{
comment|/* dsisr only filled on a DSI trap */
name|register_t
name|dsisr
decl_stmt|;
block|}
name|aim
struct|;
struct|struct
block|{
name|register_t
name|esr
decl_stmt|;
name|register_t
name|dbcr0
decl_stmt|;
block|}
name|booke
struct|;
block|}
name|cpu
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FRAMELEN is the size of the stack region used by the low-level trap  * handler. It is the size of its data (trapframe) plus the callframe  * header (sizeof(struct callframe) - 3 register widths). It must also  * be 16-byte aligned.  */
end_comment

begin_define
define|#
directive|define
name|FRAMELEN
value|roundup(sizeof(struct trapframe) + \ 			    sizeof(struct callframe) - 3*sizeof(register_t), 16)
end_define

begin_define
define|#
directive|define
name|trapframe
parameter_list|(
name|td
parameter_list|)
value|((td)->td_frame)
end_define

begin_comment
comment|/*  * Call frame for PowerPC used during fork.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_struct
struct|struct
name|callframe
block|{
name|register_t
name|cf_dummy_fp
decl_stmt|;
comment|/* dummy frame pointer */
name|register_t
name|cf_cr
decl_stmt|;
name|register_t
name|cf_lr
decl_stmt|;
name|register_t
name|cf_compiler
decl_stmt|;
name|register_t
name|cf_linkeditor
decl_stmt|;
name|register_t
name|cf_toc
decl_stmt|;
name|register_t
name|cf_func
decl_stmt|;
name|register_t
name|cf_arg0
decl_stmt|;
name|register_t
name|cf_arg1
decl_stmt|;
name|register_t
name|_padding
decl_stmt|;
comment|/* Maintain 16-byte alignment */
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|callframe
block|{
name|register_t
name|cf_dummy_fp
decl_stmt|;
comment|/* dummy frame pointer */
name|register_t
name|cf_lr
decl_stmt|;
comment|/* space for link register save */
name|register_t
name|cf_func
decl_stmt|;
name|register_t
name|cf_arg0
decl_stmt|;
name|register_t
name|cf_arg1
decl_stmt|;
name|register_t
name|_padding
decl_stmt|;
comment|/* Maintain 16-byte alignment */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Definitions for syscalls */
end_comment

begin_define
define|#
directive|define
name|FIRSTARG
value|3
end_define

begin_comment
comment|/* first arg in reg 3 */
end_comment

begin_define
define|#
directive|define
name|NARGREG
value|8
end_define

begin_comment
comment|/* 8 args in regs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_FRAME_H_ */
end_comment

end_unit

