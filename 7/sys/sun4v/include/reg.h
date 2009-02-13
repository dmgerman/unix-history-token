begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)reg.h	5.5 (Berkeley) 1/18/91  *	from: FreeBSD: src/sys/i386/include/reg.h,v 1.23 2000/09/21  * $FreeBSD$  */
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
comment|/*  * Register set accessible via /proc/$pid/regs and PT_{SET,GET}REGS.  *  * NOTE: DO NOT CHANGE THESE STRUCTURES.  The offsets of the fields are  * hardcoded in gdb.  Changing them and recompiling doesn't help, the  * constants in nm-fbsd.h must also be updated.  */
end_comment

begin_struct
struct|struct
name|reg32
block|{
name|uint32_t
name|r_global
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|r_out
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|r_npc
decl_stmt|;
name|uint32_t
name|r_pc
decl_stmt|;
name|uint32_t
name|r_psr
decl_stmt|;
name|uint32_t
name|r_wim
decl_stmt|;
name|uint32_t
name|r_pad
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|reg
block|{
name|uint64_t
name|r_global
index|[
literal|8
index|]
decl_stmt|;
name|uint64_t
name|r_out
index|[
literal|8
index|]
decl_stmt|;
name|uint64_t
name|r_fprs
decl_stmt|;
name|uint64_t
name|r_fsr
decl_stmt|;
name|uint64_t
name|r_gsr
decl_stmt|;
name|uint64_t
name|r_level
decl_stmt|;
name|uint64_t
name|r_pil
decl_stmt|;
name|uint64_t
name|r_sfar
decl_stmt|;
name|uint64_t
name|r_sfsr
decl_stmt|;
name|uint64_t
name|r_tar
decl_stmt|;
name|uint64_t
name|r_tnpc
decl_stmt|;
name|uint64_t
name|r_tpc
decl_stmt|;
name|uint64_t
name|r_tstate
decl_stmt|;
name|uint64_t
name|r_type
decl_stmt|;
name|uint64_t
name|r_y
decl_stmt|;
name|uint64_t
name|r_wstate
decl_stmt|;
name|uint64_t
name|r_pad
index|[
literal|2
index|]
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
name|uint32_t
name|fr_regs
index|[
literal|32
index|]
decl_stmt|;
name|uint32_t
name|fr_fsr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fpreg
block|{
name|uint32_t
name|fr_regs
index|[
literal|64
index|]
decl_stmt|;
comment|/* our view is 64 32-bit registers */
name|int64_t
name|fr_fsr
decl_stmt|;
comment|/* %fsr */
name|int32_t
name|fr_gsr
decl_stmt|;
comment|/* %gsr */
name|int32_t
name|fr_pad
index|[
literal|1
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
name|int
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

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

