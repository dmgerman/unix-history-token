begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: mcontext.h,v 1.4 2003/10/08 22:43:01 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001, 2002 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Klaus Klein and by Jason R. Thorpe of Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_MCONTEXT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_MCONTEXT_H_
end_define

begin_comment
comment|/*  * General register state  */
end_comment

begin_define
define|#
directive|define
name|_NGREG
value|17
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__greg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__greg_t
name|__gregset_t
index|[
name|_NGREG
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_REG_R0
value|0
end_define

begin_define
define|#
directive|define
name|_REG_R1
value|1
end_define

begin_define
define|#
directive|define
name|_REG_R2
value|2
end_define

begin_define
define|#
directive|define
name|_REG_R3
value|3
end_define

begin_define
define|#
directive|define
name|_REG_R4
value|4
end_define

begin_define
define|#
directive|define
name|_REG_R5
value|5
end_define

begin_define
define|#
directive|define
name|_REG_R6
value|6
end_define

begin_define
define|#
directive|define
name|_REG_R7
value|7
end_define

begin_define
define|#
directive|define
name|_REG_R8
value|8
end_define

begin_define
define|#
directive|define
name|_REG_R9
value|9
end_define

begin_define
define|#
directive|define
name|_REG_R10
value|10
end_define

begin_define
define|#
directive|define
name|_REG_R11
value|11
end_define

begin_define
define|#
directive|define
name|_REG_R12
value|12
end_define

begin_define
define|#
directive|define
name|_REG_R13
value|13
end_define

begin_define
define|#
directive|define
name|_REG_R14
value|14
end_define

begin_define
define|#
directive|define
name|_REG_R15
value|15
end_define

begin_define
define|#
directive|define
name|_REG_CPSR
value|16
end_define

begin_comment
comment|/* Convenience synonyms */
end_comment

begin_define
define|#
directive|define
name|_REG_FP
value|_REG_R11
end_define

begin_define
define|#
directive|define
name|_REG_SP
value|_REG_R13
end_define

begin_define
define|#
directive|define
name|_REG_LR
value|_REG_R14
end_define

begin_define
define|#
directive|define
name|_REG_PC
value|_REG_R15
end_define

begin_comment
comment|/*  * Floating point register state  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|__uint64_t
name|mcv_reg
index|[
literal|32
index|]
decl_stmt|;
name|__uint32_t
name|mcv_fpscr
decl_stmt|;
block|}
name|mcontext_vfp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|__gregset_t
name|__gregs
decl_stmt|;
comment|/* 	 * Originally, rest of this structure was named __fpu, 35 * 4 bytes 	 * long, never accessed from kernel.  	 */
name|size_t
name|mc_vfp_size
decl_stmt|;
name|void
modifier|*
name|mc_vfp_ptr
decl_stmt|;
name|unsigned
name|int
name|mc_spare
index|[
literal|33
index|]
decl_stmt|;
block|}
name|mcontext_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UC_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_MCONTEXT_H_ */
end_comment

end_unit

