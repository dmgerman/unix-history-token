begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<libelf.h>
end_include

begin_include
include|#
directive|include
file|"_libelf.h"
end_include

begin_function
name|int
name|elf_errno
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|old
decl_stmt|;
name|old
operator|=
name|LIBELF_PRIVATE
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|LIBELF_PRIVATE
argument_list|(
name|error
argument_list|)
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|old
operator|&
name|LIBELF_ELF_ERROR_MASK
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBELF_TEST_HOOKS
argument_list|)
end_if

begin_function
name|int
name|_libelf_get_max_error
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|ELF_E_NUM
return|;
block|}
end_function

begin_function
name|void
name|_libelf_set_error
parameter_list|(
name|int
name|error
parameter_list|)
block|{
name|LIBELF_PRIVATE
argument_list|(
name|error
argument_list|)
operator|=
name|error
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBELF_TEST_HOOKS */
end_comment

end_unit

