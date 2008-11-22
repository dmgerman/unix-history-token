begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: flt_rounds.c,v 1.4.10.3 2002/03/22 20:41:53 nathanw Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Mark Brinicombe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Mark Brinicombe  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/float.h>
end_include

begin_decl_stmt
specifier|static
specifier|const
name|int
name|map
index|[]
init|=
block|{
literal|1
block|,
comment|/* round to nearest */
literal|0
block|,
comment|/* round to zero */
literal|2
block|,
comment|/* round to positive infinity */
literal|3
comment|/* round to negative infinity */
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|__flt_rounds
parameter_list|()
block|{
name|uint64_t
name|fpscr
decl_stmt|;
name|__asm__
name|__volatile
argument_list|(
literal|"mffs %0"
operator|:
literal|"=f"
operator|(
name|fpscr
operator|)
argument_list|)
decl_stmt|;
return|return
name|map
index|[
operator|(
name|fpscr
operator|&
literal|0x03
operator|)
index|]
return|;
block|}
end_function

end_unit

