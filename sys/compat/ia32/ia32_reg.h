begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)reg.h	5.5 (Berkeley) 1/18/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_IA32_IA32_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_IA32_IA32_REG_H_
end_define

begin_comment
comment|/*  * Register set accessible via /proc/$pid/regs and PT_{SET,GET}REGS.  */
end_comment

begin_struct
struct|struct
name|reg32
block|{
name|unsigned
name|int
name|r_fs
decl_stmt|;
name|unsigned
name|int
name|r_es
decl_stmt|;
name|unsigned
name|int
name|r_ds
decl_stmt|;
name|unsigned
name|int
name|r_edi
decl_stmt|;
name|unsigned
name|int
name|r_esi
decl_stmt|;
name|unsigned
name|int
name|r_ebp
decl_stmt|;
name|unsigned
name|int
name|r_isp
decl_stmt|;
name|unsigned
name|int
name|r_ebx
decl_stmt|;
name|unsigned
name|int
name|r_edx
decl_stmt|;
name|unsigned
name|int
name|r_ecx
decl_stmt|;
name|unsigned
name|int
name|r_eax
decl_stmt|;
name|unsigned
name|int
name|r_trapno
decl_stmt|;
name|unsigned
name|int
name|r_err
decl_stmt|;
name|unsigned
name|int
name|r_eip
decl_stmt|;
name|unsigned
name|int
name|r_cs
decl_stmt|;
name|unsigned
name|int
name|r_eflags
decl_stmt|;
name|unsigned
name|int
name|r_esp
decl_stmt|;
name|unsigned
name|int
name|r_ss
decl_stmt|;
name|unsigned
name|int
name|r_gs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Register set accessible via /proc/$pid/fpregs.  */
end_comment

begin_struct
struct|struct
name|fpreg32
block|{
name|unsigned
name|int
name|fpr_env
index|[
literal|7
index|]
decl_stmt|;
name|unsigned
name|char
name|fpr_acc
index|[
literal|8
index|]
index|[
literal|10
index|]
decl_stmt|;
name|unsigned
name|int
name|fpr_ex_sw
decl_stmt|;
name|unsigned
name|char
name|fpr_pad
index|[
literal|64
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
name|dbreg32
block|{
name|unsigned
name|int
name|dr
index|[
literal|8
index|]
decl_stmt|;
comment|/* debug registers */
block|}
struct|;
end_struct

begin_comment
comment|/* Environment information of floating point unit */
end_comment

begin_struct
struct|struct
name|env87
block|{
name|int
name|en_cw
decl_stmt|;
comment|/* control word (16bits) */
name|int
name|en_sw
decl_stmt|;
comment|/* status word (16bits) */
name|int
name|en_tw
decl_stmt|;
comment|/* tag word (16bits) */
name|int
name|en_fip
decl_stmt|;
comment|/* floating point instruction pointer */
name|u_short
name|en_fcs
decl_stmt|;
comment|/* floating code segment selector */
name|u_short
name|en_opcode
decl_stmt|;
comment|/* opcode last executed (11 bits ) */
name|int
name|en_foo
decl_stmt|;
comment|/* floating operand offset */
name|int
name|en_fos
decl_stmt|;
comment|/* floating operand segment selector */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__ia64__
end_ifdef

begin_comment
comment|/* Layout of an x87 fpu register (amd64 gets this elsewhere) */
end_comment

begin_struct
struct|struct
name|fpacc87
block|{
name|u_char
name|fp_bytes
index|[
literal|10
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
comment|/* Floating point context */
end_comment

begin_struct
struct|struct
name|save87
block|{
name|struct
name|env87
name|sv_env
decl_stmt|;
comment|/* floating point control/status */
name|struct
name|fpacc87
name|sv_ac
index|[
literal|8
index|]
decl_stmt|;
comment|/* accumulator contents, 0-7 */
name|u_char
name|sv_pad0
index|[
literal|4
index|]
decl_stmt|;
comment|/* padding for (now unused) saved status word */
name|u_char
name|sv_pad
index|[
literal|64
index|]
decl_stmt|;
comment|/* padding; used by emulators */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Alternative layouts for<sys/procfs.h>  * Used in core dumps, the reason for this file existing.  */
end_comment

begin_struct
struct|struct
name|prstatus32
block|{
name|int
name|pr_version
decl_stmt|;
name|u_int
name|pr_statussz
decl_stmt|;
name|u_int
name|pr_gregsetsz
decl_stmt|;
name|u_int
name|pr_fpregsetsz
decl_stmt|;
name|int
name|pr_osreldate
decl_stmt|;
name|int
name|pr_cursig
decl_stmt|;
name|pid_t
name|pr_pid
decl_stmt|;
name|struct
name|reg32
name|pr_reg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|prpsinfo32
block|{
name|int
name|pr_version
decl_stmt|;
name|u_int
name|pr_psinfosz
decl_stmt|;
name|char
name|pr_fname
index|[
name|PRFNAMESZ
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|pr_psargs
index|[
name|PRARGSZ
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Wrappers and converters.  */
end_comment

begin_function_decl
name|int
name|fill_regs32
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|reg32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_regs32
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|reg32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fill_fpregs32
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|fpreg32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_fpregs32
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|fpreg32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fill_dbregs32
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|dbreg32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_dbregs32
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|dbreg32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_COMPAT_IA32_IA32_REG_H_ */
end_comment

end_unit

