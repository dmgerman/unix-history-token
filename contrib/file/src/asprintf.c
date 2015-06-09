begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) Ian F. Darwin 1986-1995.  * Software written by Ian F. Darwin and others;  * maintained 1995-present by Christos Zoulas and others.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *    * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"file.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_macro
name|FILE_RCSID
argument_list|(
literal|"@(#)$File: asprintf.c,v 1.4 2010/07/21 16:47:17 christos Exp $"
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|asprintf
parameter_list|(
name|char
modifier|*
modifier|*
name|ptr
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|vargs
decl_stmt|;
name|int
name|retval
decl_stmt|;
name|va_start
argument_list|(
name|vargs
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|retval
operator|=
name|vasprintf
argument_list|(
name|ptr
argument_list|,
name|fmt
argument_list|,
name|vargs
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|vargs
argument_list|)
expr_stmt|;
return|return
name|retval
return|;
block|}
end_function

end_unit

