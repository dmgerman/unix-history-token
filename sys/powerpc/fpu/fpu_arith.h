begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: fpu_arith.h,v 1.4 2005/12/24 20:07:28 perry Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fpu_arith.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_comment
comment|/*  * Extended-precision arithmetic.  *  * We hold the notion of a `carry register', which may or may not be a  * machine carry bit or register.  On the SPARC, it is just the machine's  * carry bit.  *  * In the worst case, you can compute the carry from x+y as  *	(unsigned)(x + y)< (unsigned)x  * and from x+y+c as  *	((unsigned)(x + y + c)<= (unsigned)x&& (y|c) != 0)  * for example.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FPE_USE_ASM
end_ifndef

begin_comment
comment|/* set up for extended-precision arithemtic */
end_comment

begin_define
define|#
directive|define
name|FPU_DECL_CARRY
value|quad_t fpu_carry, fpu_tmp;
end_define

begin_comment
comment|/*  * We have three kinds of add:  *	add with carry:					  r = x + y + c  *	add (ignoring current carry) and set carry:	c'r = x + y + 0  *	add with carry and set carry:			c'r = x + y + c  * The macros use `C' for `use carry' and `S' for `set carry'.  * Note that the state of the carry is undefined after ADDC and SUBC,  * so if all you have for these is `add with carry and set carry',  * that is OK.  *  * The same goes for subtract, except that we compute x - y - c.  *  * Finally, we have a way to get the carry into a `regular' variable,  * or set it from a value.  SET_CARRY turns 0 into no-carry, nonzero  * into carry; GET_CARRY sets its argument to 0 or 1.  */
end_comment

begin_define
define|#
directive|define
name|FPU_ADDC
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(r) = (x) + (y) + (!!fpu_carry)
end_define

begin_define
define|#
directive|define
name|FPU_ADDS
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|{ \ 		fpu_tmp = (quad_t)(x) + (quad_t)(y); \ 		(r) = (u_int)fpu_tmp; \ 		fpu_carry = ((fpu_tmp& 0xffffffff00000000LL) != 0); \ 	}
end_define

begin_define
define|#
directive|define
name|FPU_ADDCS
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|{ \ 		fpu_tmp = (quad_t)(x) + (quad_t)(y) + (!!fpu_carry); \ 		(r) = (u_int)fpu_tmp; \ 		fpu_carry = ((fpu_tmp& 0xffffffff00000000LL) != 0); \ 	}
end_define

begin_define
define|#
directive|define
name|FPU_SUBC
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(r) = (x) - (y) - (!!fpu_carry)
end_define

begin_define
define|#
directive|define
name|FPU_SUBS
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|{ \ 		fpu_tmp = (quad_t)(x) - (quad_t)(y); \ 		(r) = (u_int)fpu_tmp; \ 		fpu_carry = ((fpu_tmp& 0xffffffff00000000LL) != 0); \ 	}
end_define

begin_define
define|#
directive|define
name|FPU_SUBCS
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|{ \ 		fpu_tmp = (quad_t)(x) - (quad_t)(y) - (!!fpu_carry); \ 		(r) = (u_int)fpu_tmp; \ 		fpu_carry = ((fpu_tmp& 0xffffffff00000000LL) != 0); \ 	}
end_define

begin_define
define|#
directive|define
name|FPU_GET_CARRY
parameter_list|(
name|r
parameter_list|)
value|(r) = (!!fpu_carry)
end_define

begin_define
define|#
directive|define
name|FPU_SET_CARRY
parameter_list|(
name|v
parameter_list|)
value|fpu_carry = ((v) != 0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* set up for extended-precision arithemtic */
end_comment

begin_define
define|#
directive|define
name|FPU_DECL_CARRY
end_define

begin_comment
comment|/*  * We have three kinds of add:  *	add with carry:					  r = x + y + c  *	add (ignoring current carry) and set carry:	c'r = x + y + 0  *	add with carry and set carry:			c'r = x + y + c  * The macros use `C' for `use carry' and `S' for `set carry'.  * Note that the state of the carry is undefined after ADDC and SUBC,  * so if all you have for these is `add with carry and set carry',  * that is OK.  *  * The same goes for subtract, except that we compute x - y - c.  *  * Finally, we have a way to get the carry into a `regular' variable,  * or set it from a value.  SET_CARRY turns 0 into no-carry, nonzero  * into carry; GET_CARRY sets its argument to 0 or 1.  */
end_comment

begin_define
define|#
directive|define
name|FPU_ADDC
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|__asm volatile("adde %0,%1,%2" : "=r"(r) : "r"(x), "r"(y))
end_define

begin_define
define|#
directive|define
name|FPU_ADDS
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|__asm volatile("addc %0,%1,%2" : "=r"(r) : "r"(x), "r"(y))
end_define

begin_define
define|#
directive|define
name|FPU_ADDCS
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|__asm volatile("adde %0,%1,%2" : "=r"(r) : "r"(x), "r"(y))
end_define

begin_define
define|#
directive|define
name|FPU_SUBC
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|__asm volatile("subfe %0,%2,%1" : "=r"(r) : "r"(x), "r"(y))
end_define

begin_define
define|#
directive|define
name|FPU_SUBS
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|__asm volatile("subfc %0,%2,%1" : "=r"(r) : "r"(x), "r"(y))
end_define

begin_define
define|#
directive|define
name|FPU_SUBCS
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|__asm volatile("subfe %0,%2,%1" : "=r"(r) : "r"(x), "r"(y))
end_define

begin_define
define|#
directive|define
name|FPU_GET_CARRY
parameter_list|(
name|r
parameter_list|)
value|__asm volatile("li %0,0; addie %0,%0,0" : "=r"(r))
end_define

begin_comment
comment|/* This one needs to destroy a temp register. */
end_comment

begin_define
define|#
directive|define
name|FPU_SET_CARRY
parameter_list|(
name|v
parameter_list|)
value|do { int __tmp;				\ 		__asm volatile("addic %0,%0,-1" : "r"(__tmp) : "r"(v)); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|FPU_SHL1_BY_ADD
end_define

begin_comment
comment|/* shift left 1 faster by ADDC than (a<<1)|(b>>31) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

