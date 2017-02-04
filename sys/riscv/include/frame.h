begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Portions of this software were developed by the University of Cambridge  * Computer Laboratory as part of the CTSRD Project, with support from the  * UK Higher Education Innovation Fund (HEIF).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|LOCORE
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
comment|/*  * NOTE: keep this structure in sync with struct reg and struct mcontext.  */
end_comment

begin_struct
struct|struct
name|trapframe
block|{
name|uint64_t
name|tf_ra
decl_stmt|;
name|uint64_t
name|tf_sp
decl_stmt|;
name|uint64_t
name|tf_gp
decl_stmt|;
name|uint64_t
name|tf_tp
decl_stmt|;
name|uint64_t
name|tf_t
index|[
literal|7
index|]
decl_stmt|;
name|uint64_t
name|tf_s
index|[
literal|12
index|]
decl_stmt|;
name|uint64_t
name|tf_a
index|[
literal|8
index|]
decl_stmt|;
name|uint64_t
name|tf_sepc
decl_stmt|;
name|uint64_t
name|tf_sstatus
decl_stmt|;
name|uint64_t
name|tf_sbadaddr
decl_stmt|;
name|uint64_t
name|tf_scause
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|riscv_frame
block|{
name|struct
name|riscv_frame
modifier|*
name|f_frame
decl_stmt|;
name|u_long
name|f_retaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Signal frame. Pushed onto user stack before calling sigcode.  */
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
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_comment
comment|/* Definitions for syscalls */
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
comment|/* !_MACHINE_FRAME_H_ */
end_comment

end_unit

