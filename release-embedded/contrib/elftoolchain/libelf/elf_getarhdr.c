begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006,2008,2010 Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<libelf.h>
end_include

begin_include
include|#
directive|include
file|"_libelf.h"
end_include

begin_expr_stmt
name|ELFTC_VCSID
argument_list|(
literal|"$Id: elf_getarhdr.c 2225 2011-11-26 18:55:54Z jkoshy $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|Elf_Arhdr
modifier|*
name|elf_getarhdr
parameter_list|(
name|Elf
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|==
name|NULL
condition|)
block|{
name|LIBELF_SET_ERROR
argument_list|(
name|ARGUMENT
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
if|if
condition|(
name|e
operator|->
name|e_flags
operator|&
name|LIBELF_F_AR_HEADER
condition|)
return|return
operator|(
name|e
operator|->
name|e_hdr
operator|.
name|e_arhdr
operator|)
return|;
return|return
operator|(
name|_libelf_ar_gethdr
argument_list|(
name|e
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

