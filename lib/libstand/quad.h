begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)quad.h	8.1 (Berkeley) 6/4/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Quad arithmetic.  *  * This library makes the following assumptions:  *  *  - The type long long (aka quad_t) exists.  *  *  - A quad variable is exactly twice as long as `long'.  *  *  - The machine's arithmetic is two's complement.  *  * This library can provide 128-bit arithmetic on a machine with 128-bit  * quads and 64-bit longs, for instance, or 96-bit arithmetic on machines  * with 48-bit longs.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_comment
comment|/*  * Depending on the desired operation, we view a `long long' (aka quad_t) in  * one or more of the following formats.  */
end_comment

begin_union
union|union
name|uu
block|{
name|quad_t
name|q
decl_stmt|;
comment|/* as a (signed) quad */
name|quad_t
name|uq
decl_stmt|;
comment|/* as an unsigned quad */
name|long
name|sl
index|[
literal|2
index|]
decl_stmt|;
comment|/* as two signed longs */
name|u_long
name|ul
index|[
literal|2
index|]
decl_stmt|;
comment|/* as two unsigned longs */
block|}
union|;
end_union

begin_comment
comment|/*  * Define high and low longwords.  */
end_comment

begin_define
define|#
directive|define
name|H
value|_QUAD_HIGHWORD
end_define

begin_define
define|#
directive|define
name|L
value|_QUAD_LOWWORD
end_define

begin_comment
comment|/*  * Total number of bits in a quad_t and in the pieces that make it up.  * These are used for shifting, and also below for halfword extraction  * and assembly.  */
end_comment

begin_define
define|#
directive|define
name|QUAD_BITS
value|(sizeof(quad_t) * CHAR_BIT)
end_define

begin_define
define|#
directive|define
name|LONG_BITS
value|(sizeof(long) * CHAR_BIT)
end_define

begin_define
define|#
directive|define
name|HALF_BITS
value|(sizeof(long) * CHAR_BIT / 2)
end_define

begin_comment
comment|/*  * Extract high and low shortwords from longword, and move low shortword of  * longword to upper half of long, i.e., produce the upper longword of  * ((quad_t)(x)<< (number_of_bits_in_long/2)).  (`x' must actually be u_long.)  *  * These are used in the multiply code, to split a longword into upper  * and lower halves, and to reassemble a product as a quad_t, shifted left  * (sizeof(long)*CHAR_BIT/2).  */
end_comment

begin_define
define|#
directive|define
name|HHALF
parameter_list|(
name|x
parameter_list|)
value|((x)>> HALF_BITS)
end_define

begin_define
define|#
directive|define
name|LHALF
parameter_list|(
name|x
parameter_list|)
value|((x)& ((1<< HALF_BITS) - 1))
end_define

begin_define
define|#
directive|define
name|LHUP
parameter_list|(
name|x
parameter_list|)
value|((x)<< HALF_BITS)
end_define

begin_decl_stmt
name|quad_t
name|__divdi3
name|__P
argument_list|(
operator|(
name|quad_t
name|a
operator|,
name|quad_t
name|b
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|quad_t
name|__moddi3
name|__P
argument_list|(
operator|(
name|quad_t
name|a
operator|,
name|quad_t
name|b
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_quad_t
name|__qdivrem
name|__P
argument_list|(
operator|(
name|u_quad_t
name|u
operator|,
name|u_quad_t
name|v
operator|,
name|u_quad_t
operator|*
name|rem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_quad_t
name|__udivdi3
name|__P
argument_list|(
operator|(
name|u_quad_t
name|a
operator|,
name|u_quad_t
name|b
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_quad_t
name|__umoddi3
name|__P
argument_list|(
operator|(
name|u_quad_t
name|a
operator|,
name|u_quad_t
name|b
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * XXX  * Compensate for gcc 1 vs gcc 2.  Gcc 1 defines ?sh?di3's second argument  * as u_quad_t, while gcc 2 correctly uses int.  Unfortunately, we still use  * both compilers.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|2
end_if

begin_typedef
typedef|typedef
name|unsigned
name|int
name|qshift_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|u_quad_t
name|qshift_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

