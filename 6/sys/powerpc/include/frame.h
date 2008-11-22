begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: frame.h,v 1.2 1999/01/10 10:13:15 tsubai Exp $  * $FreeBSD$  */
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
name|int
name|cr
decl_stmt|;
name|int
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
name|dar
decl_stmt|;
comment|/* dar& dsisr are only filled on a DSI trap */
name|int
name|dsisr
decl_stmt|;
name|int
name|exc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is to ensure alignment of the stackpointer  */
end_comment

begin_define
define|#
directive|define
name|FRAMELEN
value|roundup(sizeof(struct trapframe) + 8, 16)
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

begin_struct
struct|struct
name|switchframe
block|{
name|register_t
name|sp
decl_stmt|;
name|register_t
name|fill
decl_stmt|;
name|register_t
name|user_sr
decl_stmt|;
name|register_t
name|cr
decl_stmt|;
name|register_t
name|fixreg2
decl_stmt|;
name|register_t
name|fixreg
index|[
literal|19
index|]
decl_stmt|;
comment|/* R13-R31 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|clockframe
block|{
name|register_t
name|srr1
decl_stmt|;
name|register_t
name|srr0
decl_stmt|;
name|int
name|pri
decl_stmt|;
name|int
name|depth
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Call frame for PowerPC used during fork.  */
end_comment

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
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IFRAMELEN
value|sizeof(struct intrframe)
end_define

begin_struct
struct|struct
name|intrframe
block|{
name|register_t
name|r1
decl_stmt|;
comment|/*  0 */
name|register_t
name|_pad4
decl_stmt|;
comment|/*  4 */
comment|/* 	 * The next 4 fields are "clockframe" 	 */
name|register_t
name|srr1
decl_stmt|;
comment|/*  8 */
name|register_t
name|srr0
decl_stmt|;
comment|/* 12 */
name|int
name|pri
decl_stmt|;
comment|/* 16 */
name|int
name|intr_depth
decl_stmt|;
comment|/* 20 */
name|register_t
name|vrsave
decl_stmt|;
comment|/* 24 */
name|register_t
name|ctr
decl_stmt|;
comment|/* 28 */
name|register_t
name|xer
decl_stmt|;
comment|/* 32 */
name|register_t
name|cr
decl_stmt|;
comment|/* 36 */
name|register_t
name|lr
decl_stmt|;
comment|/* 40 */
name|register_t
name|r12
decl_stmt|;
comment|/* 44 */
name|register_t
name|r11
decl_stmt|;
comment|/* 48 */
name|register_t
name|r10
decl_stmt|;
comment|/* 52 */
name|register_t
name|r9
decl_stmt|;
comment|/* 56 */
name|register_t
name|r8
decl_stmt|;
comment|/* 60 */
name|register_t
name|r7
decl_stmt|;
comment|/* 64 */
name|register_t
name|r6
decl_stmt|;
comment|/* 68 */
name|register_t
name|r5
decl_stmt|;
comment|/* 72 */
name|register_t
name|r4
decl_stmt|;
comment|/* 76 */
name|register_t
name|r3
decl_stmt|;
comment|/* 80 */
name|register_t
name|r0
decl_stmt|;
comment|/* 84 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SPFRAMELEN
value|sizeof(struct spillframe)
end_define

begin_struct
struct|struct
name|spillframe
block|{
name|register_t
name|r1
decl_stmt|;
comment|/*  0 */
name|register_t
name|_pad4
decl_stmt|;
comment|/*  4 */
name|register_t
name|r12
decl_stmt|;
comment|/*  8 */
name|register_t
name|r11
decl_stmt|;
comment|/* 12 */
name|register_t
name|r10
decl_stmt|;
comment|/* 16 */
name|register_t
name|r9
decl_stmt|;
comment|/* 20 */
name|register_t
name|r8
decl_stmt|;
comment|/* 24 */
name|register_t
name|r7
decl_stmt|;
comment|/* 28 */
name|register_t
name|r6
decl_stmt|;
comment|/* 32 */
name|register_t
name|r5
decl_stmt|;
comment|/* 36 */
name|register_t
name|r4
decl_stmt|;
comment|/* 40 */
name|register_t
name|r3
decl_stmt|;
comment|/* 44 */
name|register_t
name|r0
decl_stmt|;
comment|/* 48 */
block|}
struct|;
end_struct

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

begin_define
define|#
directive|define
name|MOREARGS
parameter_list|(
name|sp
parameter_list|)
value|((caddr_t)((int)(sp) + 8))
end_define

begin_comment
comment|/* more args go here */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_FRAME_H_ */
end_comment

end_unit

