begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006,2008,2011 Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

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
literal|"$Id: elf.c 2225 2011-11-26 18:55:54Z jkoshy $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|_libelf_globals
name|_libelf
init|=
block|{
operator|.
name|libelf_arch
operator|=
name|LIBELF_ARCH
block|,
operator|.
name|libelf_byteorder
operator|=
name|LIBELF_BYTEORDER
block|,
operator|.
name|libelf_class
operator|=
name|LIBELF_CLASS
block|,
operator|.
name|libelf_error
operator|=
literal|0
block|,
operator|.
name|libelf_fillchar
operator|=
literal|0
block|,
operator|.
name|libelf_version
operator|=
name|EV_NONE
block|}
decl_stmt|;
end_decl_stmt

end_unit

