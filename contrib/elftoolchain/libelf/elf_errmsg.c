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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"_libelf.h"
end_include

begin_expr_stmt
name|ELFTC_VCSID
argument_list|(
literal|"$Id: elf_errmsg.c 3174 2015-03-27 17:13:41Z emaste $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Retrieve a human readable translation for an error message.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|_libelf_errors
index|[]
init|=
block|{
define|#
directive|define
name|DEFINE_ERROR
parameter_list|(
name|N
parameter_list|,
name|S
parameter_list|)
value|[ELF_E_##N] = S
name|DEFINE_ERROR
argument_list|(
name|NONE
argument_list|,
literal|"No Error"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|ARCHIVE
argument_list|,
literal|"Malformed ar(1) archive"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|ARGUMENT
argument_list|,
literal|"Invalid argument"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|CLASS
argument_list|,
literal|"ELF class mismatch"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|DATA
argument_list|,
literal|"Invalid data buffer descriptor"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|HEADER
argument_list|,
literal|"Missing or malformed ELF header"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|IO
argument_list|,
literal|"I/O error"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|LAYOUT
argument_list|,
literal|"Layout constraint violation"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|MODE
argument_list|,
literal|"Incorrect ELF descriptor mode"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|RANGE
argument_list|,
literal|"Value out of range of target"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|RESOURCE
argument_list|,
literal|"Resource exhaustion"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|SECTION
argument_list|,
literal|"Invalid section descriptor"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|SEQUENCE
argument_list|,
literal|"API calls out of sequence"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|UNIMPL
argument_list|,
literal|"Unimplemented feature"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|VERSION
argument_list|,
literal|"Unknown ELF API version"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
argument|NUM
argument_list|,
literal|"Unknown error"
argument_list|)
undef|#
directive|undef
name|DEFINE_ERROR
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|const
name|char
modifier|*
name|elf_errmsg
parameter_list|(
name|int
name|error
parameter_list|)
block|{
name|int
name|oserr
decl_stmt|;
if|if
condition|(
name|error
operator|==
name|ELF_E_NONE
operator|&&
operator|(
name|error
operator|=
name|LIBELF_PRIVATE
argument_list|(
name|error
argument_list|)
operator|)
operator|==
literal|0
condition|)
return|return
name|NULL
return|;
elseif|else
if|if
condition|(
name|error
operator|==
operator|-
literal|1
condition|)
name|error
operator|=
name|LIBELF_PRIVATE
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|oserr
operator|=
name|error
operator|>>
name|LIBELF_OS_ERROR_SHIFT
expr_stmt|;
name|error
operator|&=
name|LIBELF_ELF_ERROR_MASK
expr_stmt|;
if|if
condition|(
name|error
operator|<
name|ELF_E_NONE
operator|||
name|error
operator|>=
name|ELF_E_NUM
condition|)
return|return
name|_libelf_errors
index|[
name|ELF_E_NUM
index|]
return|;
if|if
condition|(
name|oserr
condition|)
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
operator|(
name|char
operator|*
operator|)
name|LIBELF_PRIVATE
argument_list|(
name|msg
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|LIBELF_PRIVATE
argument_list|(
name|msg
argument_list|)
argument_list|)
argument_list|,
literal|"%s: %s"
argument_list|,
name|_libelf_errors
index|[
name|error
index|]
argument_list|,
name|strerror
argument_list|(
name|oserr
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
specifier|const
name|char
operator|*
operator|)
operator|&
name|LIBELF_PRIVATE
argument_list|(
name|msg
argument_list|)
return|;
block|}
return|return
name|_libelf_errors
index|[
name|error
index|]
return|;
block|}
end_function

end_unit

