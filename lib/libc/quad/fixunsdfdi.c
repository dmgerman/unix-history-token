begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)fixunsdfdi.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"quad.h"
end_include

begin_define
define|#
directive|define
name|ONE_FOURTH
value|(1<< (LONG_BITS - 2))
end_define

begin_define
define|#
directive|define
name|ONE_HALF
value|(ONE_FOURTH * 2.0)
end_define

begin_define
define|#
directive|define
name|ONE
value|(ONE_FOURTH * 4.0)
end_define

begin_comment
comment|/*  * Convert double to (unsigned) quad.  * Not sure what to do with negative numbers---for now, anything out  * of range becomes UQUAD_MAX.  */
end_comment

begin_function
name|u_quad_t
name|__fixunsdfdi
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
name|double
name|toppart
decl_stmt|;
name|union
name|uu
name|t
decl_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
return|return
operator|(
name|UQUAD_MAX
operator|)
return|;
comment|/* ??? should be 0?  ERANGE??? */
ifdef|#
directive|ifdef
name|notdef
comment|/* this falls afoul of a GCC bug */
if|if
condition|(
name|x
operator|>=
name|UQUAD_MAX
condition|)
return|return
operator|(
name|UQUAD_MAX
operator|)
return|;
else|#
directive|else
comment|/* so we wire in 2^64-1 instead */
if|if
condition|(
name|x
operator|>=
literal|18446744073709551615.0
condition|)
return|return
operator|(
name|UQUAD_MAX
operator|)
return|;
endif|#
directive|endif
comment|/* 	 * Get the upper part of the result.  Note that the divide 	 * may round up; we want to avoid this if possible, so we 	 * subtract `1/2' first. 	 */
name|toppart
operator|=
operator|(
name|x
operator|-
name|ONE_HALF
operator|)
operator|/
name|ONE
expr_stmt|;
comment|/* 	 * Now build a u_quad_t out of the top part.  The difference 	 * between x and this is the bottom part (this may introduce 	 * a few fuzzy bits, but what the heck).  With any luck this 	 * difference will be nonnegative: x should wind up in the 	 * range [0..ULONG_MAX].  For paranoia, we assume [LONG_MIN.. 	 * 2*ULONG_MAX] instead. 	 */
name|t
operator|.
name|ul
index|[
name|H
index|]
operator|=
operator|(
name|unsigned
name|long
operator|)
name|toppart
expr_stmt|;
name|t
operator|.
name|ul
index|[
name|L
index|]
operator|=
literal|0
expr_stmt|;
name|x
operator|-=
operator|(
name|double
operator|)
name|t
operator|.
name|uq
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
block|{
name|t
operator|.
name|ul
index|[
name|H
index|]
operator|--
expr_stmt|;
name|x
operator|+=
name|ULONG_MAX
expr_stmt|;
block|}
if|if
condition|(
name|x
operator|>
name|ULONG_MAX
condition|)
block|{
name|t
operator|.
name|ul
index|[
name|H
index|]
operator|++
expr_stmt|;
name|x
operator|-=
name|ULONG_MAX
expr_stmt|;
block|}
name|t
operator|.
name|ul
index|[
name|L
index|]
operator|=
operator|(
name|u_long
operator|)
name|x
expr_stmt|;
return|return
operator|(
name|t
operator|.
name|uq
operator|)
return|;
block|}
end_function

end_unit

