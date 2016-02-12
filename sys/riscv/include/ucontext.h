begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Portions of this software were developed by the University of Cambridge  * Computer Laboratory as part of the CTSRD Project, with support from the  * UK Higher Education Innovation Fund (HEIF).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_UCONTEXT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_UCONTEXT_H_
end_define

begin_struct
struct|struct
name|gpregs
block|{
name|__register_t
name|gp_ra
decl_stmt|;
name|__register_t
name|gp_sp
decl_stmt|;
name|__register_t
name|gp_gp
decl_stmt|;
name|__register_t
name|gp_tp
decl_stmt|;
name|__register_t
name|gp_t
index|[
literal|7
index|]
decl_stmt|;
name|__register_t
name|gp_s
index|[
literal|12
index|]
decl_stmt|;
name|__register_t
name|gp_a
index|[
literal|8
index|]
decl_stmt|;
name|__register_t
name|gp_sepc
decl_stmt|;
name|__register_t
name|gp_sstatus
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fpregs
block|{
name|__uint64_t
name|fp_x
index|[
literal|64
index|]
name|__aligned
argument_list|(
literal|16
argument_list|)
decl_stmt|;
name|__uint64_t
name|fp_fcsr
decl_stmt|;
name|int
name|fp_flags
decl_stmt|;
name|int
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|__mcontext
block|{
name|struct
name|gpregs
name|mc_gpregs
decl_stmt|;
name|struct
name|fpregs
name|mc_fpregs
decl_stmt|;
name|int
name|mc_flags
decl_stmt|;
define|#
directive|define
name|_MC_FP_VALID
value|0x1
comment|/* Set when mc_fpregs has valid data */
name|int
name|mc_pad
decl_stmt|;
name|__uint64_t
name|mc_spare
index|[
literal|8
index|]
decl_stmt|;
comment|/* Space for expansion */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|__mcontext
name|mcontext_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_UCONTEXT_H_ */
end_comment

end_unit

