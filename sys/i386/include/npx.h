begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)npx.h	5.3 (Berkeley) 1/18/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * 287/387 NPX Coprocessor Data Structures and Constants  * W. Jolitz 1/90  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_NPX_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_NPX_H_
end_define

begin_comment
comment|/* Environment information of floating point unit */
end_comment

begin_struct
struct|struct
name|env87
block|{
name|long
name|en_cw
decl_stmt|;
comment|/* control word (16bits) */
name|long
name|en_sw
decl_stmt|;
comment|/* status word (16bits) */
name|long
name|en_tw
decl_stmt|;
comment|/* tag word (16bits) */
name|long
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
name|long
name|en_foo
decl_stmt|;
comment|/* floating operand offset */
name|long
name|en_fos
decl_stmt|;
comment|/* floating operand segment selector */
block|}
struct|;
end_struct

begin_comment
comment|/* Contents of each floating point accumulator */
end_comment

begin_struct
struct|struct
name|fpacc87
block|{
ifdef|#
directive|ifdef
name|dontdef
comment|/* too unportable */
name|u_long
name|fp_mantlo
decl_stmt|;
comment|/* mantissa low (31:0) */
name|u_long
name|fp_manthi
decl_stmt|;
comment|/* mantissa high (63:32) */
name|int
name|fp_exp
range|:
literal|15
decl_stmt|;
comment|/* exponent */
name|int
name|fp_sgn
range|:
literal|1
decl_stmt|;
comment|/* mantissa sign */
else|#
directive|else
name|u_char
name|fp_bytes
index|[
literal|10
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

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
name|u_long
name|sv_ex_sw
decl_stmt|;
comment|/* status word for last exception */
comment|/* 	 * Bogus padding for emulators.  Emulators should use their own 	 * struct and arrange to store into this struct (ending here) 	 * before it is inspected for ptracing or for core dumps.  Some 	 * emulators overwrite the whole struct.  We have no good way of 	 * knowing how much padding to leave.  Leave just enough for the 	 * GPL emulator's i387_union (176 bytes total). 	 */
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
comment|/* Intel prefers long real (53 bit) precision */
end_comment

begin_define
define|#
directive|define
name|__iBCS_NPXCW__
value|0x262
end_define

begin_comment
comment|/* wfj prefers temporary real (64 bit) precision */
end_comment

begin_define
define|#
directive|define
name|__386BSD_NPXCW__
value|0x362
end_define

begin_comment
comment|/*  * bde prefers 53 bit precision and all exceptions masked.  *  * The standard control word from finit is 0x37F, giving:  *  *	round to nearest  *	64-bit precision  *	all exceptions masked.  *  * Now I want:  *  *	affine mode for 287's (if they work at all) (1 in bitfield 1<<12)  *	53-bit precision (2 in bitfield 3<<8)  *	overflow exception unmasked (0 in bitfield 1<<3)  *	zero divide exception unmasked (0 in bitfield 1<<2)  *	invalid-operand exception unmasked (0 in bitfield 1<<0).  *  * 64-bit precision often gives bad results with high level languages  * because it makes the results of calculations depend on whether  * intermediate values are stored in memory or in FPU registers.  *  * The "Intel" and wfj control words have:  *  *	underflow exception unmasked (0 in bitfield 1<<4)  *  * but that causes an unexpected exception in the test program 'paranoia'  * and makes denormals useless (DBL_MIN / 2 underflows).  It doesn't make  * a lot of sense to trap underflow without trapping denormals.  *  * Later I will want the IEEE default of all exceptions masked.  See the  * 0.0 math manpage for why this is better.  The 0.1 math manpage is empty.  */
end_comment

begin_define
define|#
directive|define
name|__BDE_NPXCW__
value|0x1272
end_define

begin_define
define|#
directive|define
name|__BETTER_BDE_NPXCW__
value|0x127f
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__BROKEN_NPXCW__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|__INITIAL_NPXCW__
value|__386BSD_NPXCW__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__INITIAL_NPXCW__
value|__iBCS_NPXCW__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__INITIAL_NPXCW__
value|__BDE_NPXCW__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|npxdna
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|npxexit
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|npxinit
name|__P
argument_list|(
operator|(
name|int
name|control
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|npxsave
name|__P
argument_list|(
operator|(
expr|struct
name|save87
operator|*
name|addr
operator|)
argument_list|)
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
comment|/* !_MACHINE_NPX_H_ */
end_comment

end_unit

