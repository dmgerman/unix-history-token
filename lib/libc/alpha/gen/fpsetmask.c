begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: fpsetmask.c,v 1.1 1995/04/29 05:11:01 cgd Exp $	*/
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
file|<ieeefp.h>
end_include

begin_include
include|#
directive|include
file|<machine/sysarch.h>
end_include

begin_struct
struct|struct
name|params
block|{
name|u_int64_t
name|mask
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|fp_except
name|fpsetmask
parameter_list|(
name|mask
parameter_list|)
name|fp_except
name|mask
decl_stmt|;
block|{
name|struct
name|params
name|p
decl_stmt|;
name|p
operator|.
name|mask
operator|=
operator|(
name|u_int64_t
operator|)
name|mask
expr_stmt|;
name|sysarch
argument_list|(
name|ALPHA_SET_FPMASK
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|fp_except
operator|)
name|p
operator|.
name|mask
operator|)
return|;
block|}
end_function

end_unit

