begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: NetBSD: ieee.h,v 1.2 1997/04/06 08:47:27 cgd Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ieee.h	8.1 (Berkeley) 6/11/93  *  * from: Header: ieee.h,v 1.7 92/11/26 02:04:37 torek Exp   */
end_comment

begin_comment
comment|/*  * ieee.h defines the machine-dependent layout of the machine's IEEE  * floating point.  It does *not* define (yet?) any of the rounding  * mode bits, exceptions, and so forth.  */
end_comment

begin_comment
comment|/*  * Define the number of bits in each fraction and exponent.  *  *		     k	         k+1  * Note that  1.0 x 2  == 0.1 x 2      and that denorms are represented  *  *					  (-exp_bias+1)  * as fractions that look like 0.fffff x 2             .  This means that  *  *			 -126  * the number 0.10000 x 2    , for instance, is the same as the normalized  *  *		-127			   -128  * float 1.0 x 2    .  Thus, to represent 2    , we need one leading zero  *  *				  -129  * in the fraction; to represent 2    , we need two, and so on.  This  *  *						     (-exp_bias-fracbits+1)  * implies that the smallest denormalized number is 2  *  * for whichever format we are talking about: for single precision, for  *  *						-126		-149  * instance, we get .00000000000000000000001 x 2    , or 1.0 x 2    , and  *  * -149 == -127 - 23 + 1.  */
end_comment

begin_define
define|#
directive|define
name|SNG_EXPBITS
value|8
end_define

begin_define
define|#
directive|define
name|SNG_FRACBITS
value|23
end_define

begin_define
define|#
directive|define
name|DBL_EXPBITS
value|11
end_define

begin_define
define|#
directive|define
name|DBL_FRACBITS
value|52
end_define

begin_struct
struct|struct
name|ieee_single
block|{
name|u_int
name|sng_frac
range|:
literal|23
decl_stmt|;
name|u_int
name|sng_exp
range|:
literal|8
decl_stmt|;
name|u_int
name|sng_sign
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee_double
block|{
name|u_int
name|dbl_fracl
decl_stmt|;
name|u_int
name|dbl_frach
range|:
literal|20
decl_stmt|;
name|u_int
name|dbl_exp
range|:
literal|11
decl_stmt|;
name|u_int
name|dbl_sign
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Floats whose exponent is in [1..INFNAN) (of whatever type) are  * `normal'.  Floats whose exponent is INFNAN are either Inf or NaN.  * Floats whose exponent is zero are either zero (iff all fraction  * bits are zero) or subnormal values.  *  * A NaN is a `signalling NaN' if its QUIETNAN bit is clear in its  * high fraction; if the bit is set, it is a `quiet NaN'.  */
end_comment

begin_define
define|#
directive|define
name|SNG_EXP_INFNAN
value|255
end_define

begin_define
define|#
directive|define
name|DBL_EXP_INFNAN
value|2047
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|SNG_QUIETNAN
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|DBL_QUIETNAN
value|(1<< 19)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Exponent biases.  */
end_comment

begin_define
define|#
directive|define
name|SNG_EXP_BIAS
value|127
end_define

begin_define
define|#
directive|define
name|DBL_EXP_BIAS
value|1023
end_define

end_unit

