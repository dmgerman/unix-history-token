begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: pcb.h,v 1.4 2000/06/04 11:57:17 tsubai Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PCB_H_
end_define

begin_typedef
typedef|typedef
name|int
name|faultbuf
index|[
literal|23
index|]
typedef|;
end_typedef

begin_struct
struct|struct
name|pcb
block|{
name|register_t
name|pcb_context
index|[
literal|18
index|]
decl_stmt|;
comment|/* non-volatile r14-r31 */
name|register_t
name|pcb_cr
decl_stmt|;
comment|/* Condition register */
name|register_t
name|pcb_sp
decl_stmt|;
comment|/* stack pointer */
name|register_t
name|pcb_lr
decl_stmt|;
comment|/* link register */
name|struct
name|pmap
modifier|*
name|pcb_pm
decl_stmt|;
comment|/* pmap of our vmspace */
name|struct
name|pmap
modifier|*
name|pcb_pmreal
decl_stmt|;
comment|/* real address of above */
name|faultbuf
modifier|*
name|pcb_onfault
decl_stmt|;
comment|/* For use during 						    copyin/copyout */
name|int
name|pcb_flags
decl_stmt|;
define|#
directive|define
name|PCB_FPU
value|1
comment|/* Process had FPU initialized */
struct|struct
name|fpu
block|{
name|double
name|fpr
index|[
literal|32
index|]
decl_stmt|;
name|double
name|fpscr
decl_stmt|;
comment|/* FPSCR stored as double for easier access */
block|}
name|pcb_fpu
struct|;
comment|/* Floating point processor */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|md_coredump
block|{
name|struct
name|trapframe
name|frame
decl_stmt|;
name|struct
name|fpu
name|fpstate
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|curpcb
end_ifndef

begin_decl_stmt
specifier|extern
name|struct
name|pcb
modifier|*
name|curpcb
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|pmap
modifier|*
name|curpm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|proc
modifier|*
name|fpuproc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PCB_H_ */
end_comment

end_unit

