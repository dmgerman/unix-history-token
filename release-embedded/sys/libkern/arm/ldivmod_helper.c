begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2012 Andrew Turner  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_EABI__
end_ifdef

begin_include
include|#
directive|include
file|<libkern/quad.h>
end_include

begin_comment
comment|/*  * Helper for __aeabi_ldivmod.  * TODO: __divdi3 calls __qdivrem. We should do the same and use the  * remainder value rather than re-calculating it.  */
end_comment

begin_function_decl
name|long
name|long
name|__kern_ldivmod
parameter_list|(
name|long
name|long
parameter_list|,
name|long
name|long
parameter_list|,
name|long
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|long
name|long
name|__kern_ldivmod
parameter_list|(
name|long
name|long
name|n
parameter_list|,
name|long
name|long
name|m
parameter_list|,
name|long
name|long
modifier|*
name|rem
parameter_list|)
block|{
name|long
name|long
name|q
decl_stmt|;
name|q
operator|=
name|__divdi3
argument_list|(
name|n
argument_list|,
name|m
argument_list|)
expr_stmt|;
comment|/* q = n / m */
operator|*
name|rem
operator|=
name|n
operator|-
name|m
operator|*
name|q
expr_stmt|;
return|return
name|q
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

