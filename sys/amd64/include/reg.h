begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Peter Wemm.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)reg.h	5.5 (Berkeley) 1/18/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_REG_H_
end_define

begin_comment
comment|/*  * Register set accessible via /proc/$pid/regs and PT_{SET,GET}REGS.  */
end_comment

begin_struct
struct|struct
name|reg
block|{
name|register_t
name|r_r15
decl_stmt|;
name|register_t
name|r_r14
decl_stmt|;
name|register_t
name|r_r13
decl_stmt|;
name|register_t
name|r_r12
decl_stmt|;
name|register_t
name|r_r11
decl_stmt|;
name|register_t
name|r_r10
decl_stmt|;
name|register_t
name|r_r9
decl_stmt|;
name|register_t
name|r_r8
decl_stmt|;
name|register_t
name|r_rdi
decl_stmt|;
name|register_t
name|r_rsi
decl_stmt|;
name|register_t
name|r_rbp
decl_stmt|;
name|register_t
name|r_rbx
decl_stmt|;
name|register_t
name|r_rdx
decl_stmt|;
name|register_t
name|r_rcx
decl_stmt|;
name|register_t
name|r_rax
decl_stmt|;
name|register_t
name|r_trapno
decl_stmt|;
name|register_t
name|r_err
decl_stmt|;
name|register_t
name|r_rip
decl_stmt|;
name|register_t
name|r_cs
decl_stmt|;
name|register_t
name|r_rflags
decl_stmt|;
name|register_t
name|r_rsp
decl_stmt|;
name|register_t
name|r_ss
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Register set accessible via /proc/$pid/fpregs.  */
end_comment

begin_struct
struct|struct
name|fpreg
block|{
comment|/* 	 * XXX should get struct from fpu.h.  Here we give a slightly 	 * simplified struct.  This may be too much detail.  Perhaps 	 * an array of unsigned longs is best. 	 */
name|unsigned
name|long
name|fpr_env
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|fpr_acc
index|[
literal|8
index|]
index|[
literal|16
index|]
decl_stmt|;
name|unsigned
name|char
name|fpr_xacc
index|[
literal|16
index|]
index|[
literal|16
index|]
decl_stmt|;
name|unsigned
name|long
name|fpr_spare
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Register set accessible via /proc/$pid/dbregs.  */
end_comment

begin_struct
struct|struct
name|dbreg
block|{
name|unsigned
name|long
name|dr
index|[
literal|16
index|]
decl_stmt|;
comment|/* debug registers */
comment|/* Index 0-3: debug address registers */
comment|/* Index 4-5: reserved */
comment|/* Index 6: debug status */
comment|/* Index 7: debug control */
comment|/* Index 8-15: reserved */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DBREG_DR7_EXEC
value|0x00
end_define

begin_comment
comment|/* break on execute       */
end_comment

begin_define
define|#
directive|define
name|DBREG_DR7_WRONLY
value|0x01
end_define

begin_comment
comment|/* break on write         */
end_comment

begin_define
define|#
directive|define
name|DBREG_DR7_RDWR
value|0x03
end_define

begin_comment
comment|/* break on read or write */
end_comment

begin_define
define|#
directive|define
name|DBREG_DRX
parameter_list|(
name|d
parameter_list|,
name|x
parameter_list|)
value|((d)->dr[(x)])
end_define

begin_comment
comment|/* reference dr0 - dr15 by                                          register number */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * XXX these interfaces are MI, so they should be declared in a MI place.  */
end_comment

begin_function_decl
name|int
name|fill_regs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_regs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fill_fpregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|fpreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_fpregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|fpreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fill_dbregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|dbreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_dbregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|dbreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_REG_H_ */
end_comment

end_unit

