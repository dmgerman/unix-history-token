begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fpu_emu.h	8.1 (Berkeley) 6/11/93  *	$NetBSD: fpu_emu.h,v 1.4 2000/08/03 18:32:07 eeh Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Floating point emulator (tailored for SPARC, but structurally  * machine-independent).  *  * Floating point numbers are carried around internally in an `expanded'  * or `unpacked' form consisting of:  *	- sign  *	- unbiased exponent  *	- mantissa (`1.' + 112-bit fraction + guard + round)  *	- sticky bit  * Any implied `1' bit is inserted, giving a 113-bit mantissa that is  * always nonzero.  Additional low-order `guard' and `round' bits are  * scrunched in, making the entire mantissa 115 bits long.  This is divided  * into four 32-bit words, with `spare' bits left over in the upper part  * of the top word (the high bits of fp_mant[0]).  An internal `exploded'  * number is thus kept within the half-open interval [1.0,2.0) (but see  * the `number classes' below).  This holds even for denormalized numbers:  * when we explode an external denorm, we normalize it, introducing low-order  * zero bits, so that the rest of the code always sees normalized values.  *  * Note that a number of our algorithms use the `spare' bits at the top.  * The most demanding algorithm---the one for sqrt---depends on two such  * bits, so that it can represent values up to (but not including) 8.0,  * and then it needs a carry on top of that, so that we need three `spares'.  *  * The sticky-word is 32 bits so that we can use `OR' operators to goosh  * whole words from the mantissa into it.  *  * All operations are done in this internal extended precision.  According  * to Hennesey& Patterson, Appendix A, rounding can be repeated---that is,  * it is OK to do a+b in extended precision and then round the result to  * single precision---provided single, double, and extended precisions are  * `far enough apart' (they always are), but we will try to avoid any such  * extra work where possible.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC64_FPU_FPU_EMU_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPARC64_FPU_FPU_EMU_H_
end_define

begin_include
include|#
directive|include
file|"fpu_reg.h"
end_include

begin_struct
struct|struct
name|fpn
block|{
name|int
name|fp_class
decl_stmt|;
comment|/* see below */
name|int
name|fp_sign
decl_stmt|;
comment|/* 0 => positive, 1 => negative */
name|int
name|fp_exp
decl_stmt|;
comment|/* exponent (unbiased) */
name|int
name|fp_sticky
decl_stmt|;
comment|/* nonzero bits lost at right end */
name|u_int
name|fp_mant
index|[
literal|4
index|]
decl_stmt|;
comment|/* 115-bit mantissa */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FP_NMANT
value|115
end_define

begin_comment
comment|/* total bits in mantissa (incl g,r) */
end_comment

begin_define
define|#
directive|define
name|FP_NG
value|2
end_define

begin_comment
comment|/* number of low-order guard bits */
end_comment

begin_define
define|#
directive|define
name|FP_LG
value|((FP_NMANT - 1)& 31)
end_define

begin_comment
comment|/* log2(1.0) for fp_mant[0] */
end_comment

begin_define
define|#
directive|define
name|FP_LG2
value|((FP_NMANT - 1)& 63)
end_define

begin_comment
comment|/* log2(1.0) for fp_mant[0] and fp_mant[1] */
end_comment

begin_define
define|#
directive|define
name|FP_QUIETBIT
value|(1<< (FP_LG - 1))
end_define

begin_comment
comment|/* Quiet bit in NaNs (0.5) */
end_comment

begin_define
define|#
directive|define
name|FP_1
value|(1<< FP_LG)
end_define

begin_comment
comment|/* 1.0 in fp_mant[0] */
end_comment

begin_define
define|#
directive|define
name|FP_2
value|(1<< (FP_LG + 1))
end_define

begin_comment
comment|/* 2.0 in fp_mant[0] */
end_comment

begin_comment
comment|/*  * Number classes.  Since zero, Inf, and NaN cannot be represented using  * the above layout, we distinguish these from other numbers via a class.  * In addition, to make computation easier and to follow Appendix N of  * the SPARC Version 8 standard, we give each kind of NaN a separate class.  */
end_comment

begin_define
define|#
directive|define
name|FPC_SNAN
value|-2
end_define

begin_comment
comment|/* signalling NaN (sign irrelevant) */
end_comment

begin_define
define|#
directive|define
name|FPC_QNAN
value|-1
end_define

begin_comment
comment|/* quiet NaN (sign irrelevant) */
end_comment

begin_define
define|#
directive|define
name|FPC_ZERO
value|0
end_define

begin_comment
comment|/* zero (sign matters) */
end_comment

begin_define
define|#
directive|define
name|FPC_NUM
value|1
end_define

begin_comment
comment|/* number (sign matters) */
end_comment

begin_define
define|#
directive|define
name|FPC_INF
value|2
end_define

begin_comment
comment|/* infinity (sign matters) */
end_comment

begin_define
define|#
directive|define
name|ISNAN
parameter_list|(
name|fp
parameter_list|)
value|((fp)->fp_class< 0)
end_define

begin_define
define|#
directive|define
name|ISZERO
parameter_list|(
name|fp
parameter_list|)
value|((fp)->fp_class == 0)
end_define

begin_define
define|#
directive|define
name|ISINF
parameter_list|(
name|fp
parameter_list|)
value|((fp)->fp_class == FPC_INF)
end_define

begin_comment
comment|/*  * ORDER(x,y) `sorts' a pair of `fpn *'s so that the right operand (y) points  * to the `more significant' operand for our purposes.  Appendix N says that  * the result of a computation involving two numbers are:  *  *	If both are SNaN: operand 2, converted to Quiet  *	If only one is SNaN: the SNaN operand, converted to Quiet  *	If both are QNaN: operand 2  *	If only one is QNaN: the QNaN operand  *  * In addition, in operations with an Inf operand, the result is usually  * Inf.  The class numbers are carefully arranged so that if  *	(unsigned)class(op1)> (unsigned)class(op2)  * then op1 is the one we want; otherwise op2 is the one we want.  */
end_comment

begin_define
define|#
directive|define
name|ORDER
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{ \ 	if ((u_int)(x)->fp_class> (u_int)(y)->fp_class) \ 		SWAP(x, y); \ }
end_define

begin_define
define|#
directive|define
name|SWAP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{ \ 	register struct fpn *swap; \ 	swap = (x), (x) = (y), (y) = swap; \ }
end_define

begin_comment
comment|/*  * Floating point operand types. FTYPE_LNG is syntethic (it does not occur in  * instructions).  */
end_comment

begin_define
define|#
directive|define
name|FTYPE_INT
value|INSFP_i
end_define

begin_define
define|#
directive|define
name|FTYPE_SNG
value|INSFP_s
end_define

begin_define
define|#
directive|define
name|FTYPE_DBL
value|INSFP_d
end_define

begin_define
define|#
directive|define
name|FTYPE_EXT
value|INSFP_q
end_define

begin_define
define|#
directive|define
name|FTYPE_LNG
value|-1
end_define

begin_comment
comment|/*  * Emulator state.  */
end_comment

begin_struct
struct|struct
name|fpemu
block|{
name|u_long
name|fe_fsr
decl_stmt|;
comment|/* fsr copy (modified during op) */
name|int
name|fe_cx
decl_stmt|;
comment|/* exceptions */
name|int
name|pad
decl_stmt|;
comment|/* align access to following fields */
name|struct
name|fpn
name|fe_f1
decl_stmt|;
comment|/* operand 1 */
name|struct
name|fpn
name|fe_f2
decl_stmt|;
comment|/* operand 2, if required */
name|struct
name|fpn
name|fe_f3
decl_stmt|;
comment|/* available storage for result */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Arithmetic functions.  * Each of these may modify its inputs (f1,f2) and/or the temporary.  * Each returns a pointer to the result and/or sets exceptions.  */
end_comment

begin_define
define|#
directive|define
name|__fpu_sub
parameter_list|(
name|fe
parameter_list|)
value|((fe)->fe_f2.fp_sign ^= 1, __fpu_add(fe))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FPU_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|FPE_INSN
value|0x1
end_define

begin_define
define|#
directive|define
name|FPE_REG
value|0x2
end_define

begin_decl_stmt
specifier|extern
name|int
name|__fpe_debug
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|__fpu_dumpfpn
parameter_list|(
name|struct
name|fpn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|if (__fpe_debug& (x)) printf y
end_define

begin_define
define|#
directive|define
name|DUMPFPN
parameter_list|(
name|x
parameter_list|,
name|f
parameter_list|)
value|if (__fpe_debug& (x)) __fpu_dumpfpn((f))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DUMPFPN
parameter_list|(
name|x
parameter_list|,
name|f
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SPARC64_FPU_FPU_EXTERN_H_ */
end_comment

end_unit

