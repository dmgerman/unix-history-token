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
literal|"@(#)floatdidf.c	8.1 (Berkeley) 6/4/93"
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

begin_comment
comment|/*  * Convert (signed) quad to double.  */
end_comment

begin_function
name|double
name|__floatdidf
parameter_list|(
name|x
parameter_list|)
name|quad_t
name|x
decl_stmt|;
block|{
name|double
name|d
decl_stmt|;
name|union
name|uu
name|u
decl_stmt|;
name|int
name|neg
decl_stmt|;
comment|/* 	 * Get an unsigned number first, by negating if necessary. 	 */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
name|u
operator|.
name|q
operator|=
operator|-
name|x
operator|,
name|neg
operator|=
literal|1
expr_stmt|;
else|else
name|u
operator|.
name|q
operator|=
name|x
operator|,
name|neg
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Now u.ul[H] has the factor of 2^32 (or whatever) and u.ul[L] 	 * has the units.  Ideally we could just set d, add LONG_BITS to 	 * its exponent, and then add the units, but this is portable 	 * code and does not know how to get at an exponent.  Machine- 	 * specific code may be able to do this more efficiently. 	 */
name|d
operator|=
operator|(
name|double
operator|)
name|u
operator|.
name|ul
index|[
name|H
index|]
operator|*
operator|(
operator|(
literal|1
operator|<<
operator|(
name|LONG_BITS
operator|-
literal|2
operator|)
operator|)
operator|*
literal|4.0
operator|)
expr_stmt|;
name|d
operator|+=
name|u
operator|.
name|ul
index|[
name|L
index|]
expr_stmt|;
return|return
operator|(
name|neg
condition|?
operator|-
name|d
else|:
name|d
operator|)
return|;
block|}
end_function

end_unit

