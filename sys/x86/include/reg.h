begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2003 Peter Wemm.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)reg.h	5.5 (Berkeley) 1/18/91  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<machine/_types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_comment
comment|/*  * Indices for registers in `struct trapframe' and `struct regs'.  *  * This interface is deprecated.  In the kernel, it is only used in FPU  * emulators to convert from register numbers encoded in instructions to  * register values.  Everything else just accesses the relevant struct  * members.  In userland, debuggers tend to abuse this interface since  * they don't understand that `struct regs' is a struct.  I hope they have  * stopped accessing the registers in the trap frame via PT_{READ,WRITE}_U  * and we can stop supporting the user area soon.  */
end_comment

begin_define
define|#
directive|define
name|tFS
value|(0)
end_define

begin_define
define|#
directive|define
name|tES
value|(1)
end_define

begin_define
define|#
directive|define
name|tDS
value|(2)
end_define

begin_define
define|#
directive|define
name|tEDI
value|(3)
end_define

begin_define
define|#
directive|define
name|tESI
value|(4)
end_define

begin_define
define|#
directive|define
name|tEBP
value|(5)
end_define

begin_define
define|#
directive|define
name|tISP
value|(6)
end_define

begin_define
define|#
directive|define
name|tEBX
value|(7)
end_define

begin_define
define|#
directive|define
name|tEDX
value|(8)
end_define

begin_define
define|#
directive|define
name|tECX
value|(9)
end_define

begin_define
define|#
directive|define
name|tEAX
value|(10)
end_define

begin_define
define|#
directive|define
name|tERR
value|(12)
end_define

begin_define
define|#
directive|define
name|tEIP
value|(13)
end_define

begin_define
define|#
directive|define
name|tCS
value|(14)
end_define

begin_define
define|#
directive|define
name|tEFLAGS
value|(15)
end_define

begin_define
define|#
directive|define
name|tESP
value|(16)
end_define

begin_define
define|#
directive|define
name|tSS
value|(17)
end_define

begin_comment
comment|/*  * Indices for registers in `struct regs' only.  *  * Some registers live in the pcb and are only in an "array" with the  * other registers in application interfaces that copy all the registers  * to or from a `struct regs'.  */
end_comment

begin_define
define|#
directive|define
name|tGS
value|(18)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __i386__ */
end_comment

begin_comment
comment|/* Rename the structs below depending on the machine architecture. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_define
define|#
directive|define
name|__reg32
value|reg
end_define

begin_define
define|#
directive|define
name|__fpreg32
value|fpreg
end_define

begin_define
define|#
directive|define
name|__dbreg32
value|dbreg
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__reg32
value|reg32
end_define

begin_define
define|#
directive|define
name|__reg64
value|reg
end_define

begin_define
define|#
directive|define
name|__fpreg32
value|fpreg32
end_define

begin_define
define|#
directive|define
name|__fpreg64
value|fpreg
end_define

begin_define
define|#
directive|define
name|__dbreg32
value|dbreg32
end_define

begin_define
define|#
directive|define
name|__dbreg64
value|dbreg
end_define

begin_define
define|#
directive|define
name|__HAVE_REG32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Register set accessible via /proc/$pid/regs and PT_{SET,GET}REGS.  */
end_comment

begin_struct
struct|struct
name|__reg32
block|{
name|__uint32_t
name|r_fs
decl_stmt|;
name|__uint32_t
name|r_es
decl_stmt|;
name|__uint32_t
name|r_ds
decl_stmt|;
name|__uint32_t
name|r_edi
decl_stmt|;
name|__uint32_t
name|r_esi
decl_stmt|;
name|__uint32_t
name|r_ebp
decl_stmt|;
name|__uint32_t
name|r_isp
decl_stmt|;
name|__uint32_t
name|r_ebx
decl_stmt|;
name|__uint32_t
name|r_edx
decl_stmt|;
name|__uint32_t
name|r_ecx
decl_stmt|;
name|__uint32_t
name|r_eax
decl_stmt|;
name|__uint32_t
name|r_trapno
decl_stmt|;
name|__uint32_t
name|r_err
decl_stmt|;
name|__uint32_t
name|r_eip
decl_stmt|;
name|__uint32_t
name|r_cs
decl_stmt|;
name|__uint32_t
name|r_eflags
decl_stmt|;
name|__uint32_t
name|r_esp
decl_stmt|;
name|__uint32_t
name|r_ss
decl_stmt|;
name|__uint32_t
name|r_gs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|__reg64
block|{
name|__int64_t
name|r_r15
decl_stmt|;
name|__int64_t
name|r_r14
decl_stmt|;
name|__int64_t
name|r_r13
decl_stmt|;
name|__int64_t
name|r_r12
decl_stmt|;
name|__int64_t
name|r_r11
decl_stmt|;
name|__int64_t
name|r_r10
decl_stmt|;
name|__int64_t
name|r_r9
decl_stmt|;
name|__int64_t
name|r_r8
decl_stmt|;
name|__int64_t
name|r_rdi
decl_stmt|;
name|__int64_t
name|r_rsi
decl_stmt|;
name|__int64_t
name|r_rbp
decl_stmt|;
name|__int64_t
name|r_rbx
decl_stmt|;
name|__int64_t
name|r_rdx
decl_stmt|;
name|__int64_t
name|r_rcx
decl_stmt|;
name|__int64_t
name|r_rax
decl_stmt|;
name|__uint32_t
name|r_trapno
decl_stmt|;
name|__uint16_t
name|r_fs
decl_stmt|;
name|__uint16_t
name|r_gs
decl_stmt|;
name|__uint32_t
name|r_err
decl_stmt|;
name|__uint16_t
name|r_es
decl_stmt|;
name|__uint16_t
name|r_ds
decl_stmt|;
name|__int64_t
name|r_rip
decl_stmt|;
name|__int64_t
name|r_cs
decl_stmt|;
name|__int64_t
name|r_rflags
decl_stmt|;
name|__int64_t
name|r_rsp
decl_stmt|;
name|__int64_t
name|r_ss
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Register set accessible via /proc/$pid/fpregs.  *  * XXX should get struct from fpu.h.  Here we give a slightly  * simplified struct.  This may be too much detail.  Perhaps  * an array of unsigned longs is best.  */
end_comment

begin_struct
struct|struct
name|__fpreg32
block|{
name|__uint32_t
name|fpr_env
index|[
literal|7
index|]
decl_stmt|;
name|__uint8_t
name|fpr_acc
index|[
literal|8
index|]
index|[
literal|10
index|]
decl_stmt|;
name|__uint32_t
name|fpr_ex_sw
decl_stmt|;
name|__uint8_t
name|fpr_pad
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|__fpreg64
block|{
name|__uint64_t
name|fpr_env
index|[
literal|4
index|]
decl_stmt|;
name|__uint8_t
name|fpr_acc
index|[
literal|8
index|]
index|[
literal|16
index|]
decl_stmt|;
name|__uint8_t
name|fpr_xacc
index|[
literal|16
index|]
index|[
literal|16
index|]
decl_stmt|;
name|__uint64_t
name|fpr_spare
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Register set accessible via PT_GETXMMREGS (i386).  */
end_comment

begin_struct
struct|struct
name|xmmreg
block|{
comment|/* 	 * XXX should get struct from npx.h.  Here we give a slightly 	 * simplified struct.  This may be too much detail.  Perhaps 	 * an array of unsigned longs is best. 	 */
name|__uint32_t
name|xmm_env
index|[
literal|8
index|]
decl_stmt|;
name|__uint8_t
name|xmm_acc
index|[
literal|8
index|]
index|[
literal|16
index|]
decl_stmt|;
name|__uint8_t
name|xmm_reg
index|[
literal|8
index|]
index|[
literal|16
index|]
decl_stmt|;
name|__uint8_t
name|xmm_pad
index|[
literal|224
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
name|__dbreg32
block|{
name|__uint32_t
name|dr
index|[
literal|8
index|]
decl_stmt|;
comment|/* debug registers */
comment|/* Index 0-3: debug address registers */
comment|/* Index 4-5: reserved */
comment|/* Index 6: debug status */
comment|/* Index 7: debug control */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|__dbreg64
block|{
name|__uint64_t
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
name|DBREG_DR7_LOCAL_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|DBREG_DR7_GLOBAL_ENABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|DBREG_DR7_LEN_1
value|0x00
end_define

begin_comment
comment|/* 1 byte length          */
end_comment

begin_define
define|#
directive|define
name|DBREG_DR7_LEN_2
value|0x01
end_define

begin_define
define|#
directive|define
name|DBREG_DR7_LEN_4
value|0x03
end_define

begin_define
define|#
directive|define
name|DBREG_DR7_LEN_8
value|0x02
end_define

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
name|DBREG_DR7_MASK
parameter_list|(
name|i
parameter_list|)
define|\
value|((__u_register_t)(0xf)<< ((i) * 4 + 16) | 0x3<< (i) * 2)
end_define

begin_define
define|#
directive|define
name|DBREG_DR7_SET
parameter_list|(
name|i
parameter_list|,
name|len
parameter_list|,
name|access
parameter_list|,
name|enable
parameter_list|)
define|\
value|((__u_register_t)((len)<< 2 | (access))<< ((i) * 4 + 16) | 	\ 	(enable)<< (i) * 2)
end_define

begin_define
define|#
directive|define
name|DBREG_DR7_GD
value|0x2000
end_define

begin_define
define|#
directive|define
name|DBREG_DR7_ENABLED
parameter_list|(
name|d
parameter_list|,
name|i
parameter_list|)
value|(((d)& 0x3<< (i) * 2) != 0)
end_define

begin_define
define|#
directive|define
name|DBREG_DR7_ACCESS
parameter_list|(
name|d
parameter_list|,
name|i
parameter_list|)
value|((d)>> ((i) * 4 + 16)& 0x3)
end_define

begin_define
define|#
directive|define
name|DBREG_DR7_LEN
parameter_list|(
name|d
parameter_list|,
name|i
parameter_list|)
value|((d)>> ((i) * 4 + 18)& 0x3)
end_define

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
comment|/* reference dr0 - dr7 by 					   register number */
end_comment

begin_undef
undef|#
directive|undef
name|__reg32
end_undef

begin_undef
undef|#
directive|undef
name|__reg64
end_undef

begin_undef
undef|#
directive|undef
name|__fpreg32
end_undef

begin_undef
undef|#
directive|undef
name|__fpreg64
end_undef

begin_undef
undef|#
directive|undef
name|__dbreg32
end_undef

begin_undef
undef|#
directive|undef
name|__dbreg64
end_undef

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
name|fill_frame_regs
parameter_list|(
name|struct
name|trapframe
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

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_FREEBSD32
end_ifdef

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

