begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: frame.h,v 1.5 2002/10/19 00:10:54 bjh21 Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1994-1997 Mark Brinicombe.  * Copyright (c) 1994 Brini.  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Brini.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BRINI ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BRINI OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RiscBSD kernel project  *  * frame.h  *  * Stack frames structures  *  * Created      : 30/09/94  *  * $FreeBSD$  *  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucontext.h>
end_include

begin_comment
comment|/*  * Trap frame.  Pushed onto the kernel stack on a trap (synchronous exception).  */
end_comment

begin_struct
struct|struct
name|trapframe
block|{
name|register_t
name|tf_spsr
decl_stmt|;
comment|/* Zero on arm26 */
name|register_t
name|tf_r0
decl_stmt|;
name|register_t
name|tf_r1
decl_stmt|;
name|register_t
name|tf_r2
decl_stmt|;
name|register_t
name|tf_r3
decl_stmt|;
name|register_t
name|tf_r4
decl_stmt|;
name|register_t
name|tf_r5
decl_stmt|;
name|register_t
name|tf_r6
decl_stmt|;
name|register_t
name|tf_r7
decl_stmt|;
name|register_t
name|tf_r8
decl_stmt|;
name|register_t
name|tf_r9
decl_stmt|;
name|register_t
name|tf_r10
decl_stmt|;
name|register_t
name|tf_r11
decl_stmt|;
name|register_t
name|tf_r12
decl_stmt|;
name|register_t
name|tf_usr_sp
decl_stmt|;
name|register_t
name|tf_usr_lr
decl_stmt|;
name|register_t
name|tf_svc_sp
decl_stmt|;
comment|/* Not used on arm26 */
name|register_t
name|tf_svc_lr
decl_stmt|;
comment|/* Not used on arm26 */
name|register_t
name|tf_pc
decl_stmt|;
name|register_t
name|tf_pad
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Register numbers */
end_comment

begin_define
define|#
directive|define
name|tf_r13
value|tf_usr_sp
end_define

begin_define
define|#
directive|define
name|tf_r14
value|tf_usr_lr
end_define

begin_define
define|#
directive|define
name|tf_r15
value|tf_pc
end_define

begin_comment
comment|/*  * Signal frame.  Pushed onto user stack before calling sigcode.  * The pointers are used in the trampoline code to locate the ucontext.  */
end_comment

begin_struct
struct|struct
name|sigframe
block|{
name|siginfo_t
name|sf_si
decl_stmt|;
comment|/* actual saved siginfo */
name|ucontext_t
name|sf_uc
decl_stmt|;
comment|/* actual saved ucontext */
name|mcontext_vfp_t
name|sf_vfp
decl_stmt|;
comment|/* actual saved VFP context */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Switch frame.  *  * It is important this is a multiple of 8 bytes so the stack is correctly  * aligned when we create new threads.  */
end_comment

begin_struct
struct|struct
name|switchframe
block|{
name|register_t
name|sf_r4
decl_stmt|;
name|register_t
name|sf_r5
decl_stmt|;
name|register_t
name|sf_r6
decl_stmt|;
name|register_t
name|sf_r7
decl_stmt|;
name|register_t
name|sf_r8
decl_stmt|;
name|register_t
name|sf_r9
decl_stmt|;
name|register_t
name|sf_r10
decl_stmt|;
name|register_t
name|sf_r11
decl_stmt|;
name|register_t
name|sf_r12
decl_stmt|;
name|register_t
name|sf_sp
decl_stmt|;
name|register_t
name|sf_lr
decl_stmt|;
name|register_t
name|sf_pc
decl_stmt|;
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
name|register_t
name|sf_tpidrurw
decl_stmt|;
name|register_t
name|sf_spare0
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Stack frame. Used during stack traces (db_trace.c)  */
end_comment

begin_struct
struct|struct
name|frame
block|{
name|u_int
name|fr_fp
decl_stmt|;
name|u_int
name|fr_sp
decl_stmt|;
name|u_int
name|fr_lr
decl_stmt|;
name|u_int
name|fr_pc
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_FRAME_H_ */
end_comment

end_unit

