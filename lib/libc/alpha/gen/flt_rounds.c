begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/*	From: NetBSD: flt_rounds.c,v 1.2 1997/07/18 00:30:30 thorpej Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Christopher G. Demetriou  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

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
literal|0
block|,
comment|/* round to zero */
literal|3
block|,
comment|/* round to negative infinity */
literal|1
block|,
comment|/* round to nearest */
literal|2
comment|/* round to positive infinity */
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|__flt_rounds
parameter_list|()
block|{
name|double
name|fpcrval
decl_stmt|;
name|u_int64_t
name|old
decl_stmt|;
asm|__asm__("trapb");
asm|__asm__("mf_fpcr %0" : "=f" (fpcrval));
asm|__asm__("trapb");
name|old
operator|=
operator|*
operator|(
name|u_int64_t
operator|*
operator|)
operator|&
name|fpcrval
expr_stmt|;
return|return
name|map
index|[
operator|(
name|old
operator|>>
literal|58
operator|)
operator|&
literal|0x3
index|]
return|;
block|}
end_function

end_unit

