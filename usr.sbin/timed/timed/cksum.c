begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)cksum.c	8.1 (Berkeley) 6/6/93";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id: cksum.c,v 1.2 1997/10/22 06:19:48 charnier Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  *			I N _ C K S U M  *  * Checksum routine for Internet Protocol family headers (C Version)  *  * There is no profit in a specialized version of the checksum  * function for any machine where int's are 32 bits and shorts are 16.  *  * All timed packets are smaller than 32K shorts, so there is no need to  * worry about carries except at the end.  */
end_comment

begin_function
name|int
name|in_cksum
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|)
name|u_short
modifier|*
name|addr
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
specifier|register
name|int
name|nleft
init|=
name|len
decl_stmt|;
specifier|register
name|u_short
modifier|*
name|w
init|=
name|addr
decl_stmt|;
specifier|register
name|u_short
name|answer
decl_stmt|;
specifier|register
name|int
name|sum
init|=
literal|0
decl_stmt|;
comment|/* 	 *  Our algorithm is simple, using a 32 bit accumulator (sum), 	 *  we add sequential 16 bit words to it, and at the end, fold 	 *  back all the carry bits from the top 16 bits into the lower 	 *  16 bits. 	 */
while|while
condition|(
name|nleft
operator|>
literal|1
condition|)
block|{
name|sum
operator|+=
operator|*
name|w
operator|++
expr_stmt|;
name|nleft
operator|-=
literal|2
expr_stmt|;
block|}
comment|/* mop up an odd byte, if necessary */
if|if
condition|(
name|nleft
operator|==
literal|1
condition|)
name|sum
operator|+=
operator|(
operator|*
operator|(
name|u_char
operator|*
operator|)
name|w
operator|)
operator|<<
literal|8
expr_stmt|;
comment|/* 	 * add back carry outs from top 16 bits to low 16 bits 	 */
name|sum
operator|=
operator|(
name|sum
operator|>>
literal|16
operator|)
operator|+
operator|(
name|sum
operator|&
literal|0xffff
operator|)
expr_stmt|;
comment|/* add hi 16 to low 16 */
name|sum
operator|+=
operator|(
name|sum
operator|>>
literal|16
operator|)
expr_stmt|;
comment|/* add carry */
name|answer
operator|=
operator|~
name|sum
expr_stmt|;
comment|/* truncate to 16 bits */
return|return
operator|(
name|answer
operator|)
return|;
block|}
end_function

end_unit

