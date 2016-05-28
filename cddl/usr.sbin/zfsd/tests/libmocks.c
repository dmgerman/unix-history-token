begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Spectra Logic Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * Authors: Alan Somers     (Spectra Logic Corporation)  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|"libmocks.h"
end_include

begin_comment
comment|/*  * This file mocks shared library functions that are used by zfsd.  Every  * function present will be used for all tests in all test suites instead of the  * normal function.  */
end_comment

begin_decl_stmt
name|int
name|syslog_last_priority
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|syslog_last_message
index|[
literal|4096
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|syslog
parameter_list|(
name|int
name|priority
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|syslog_last_priority
operator|=
name|priority
expr_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|message
argument_list|)
expr_stmt|;
name|vsnprintf
argument_list|(
name|syslog_last_message
argument_list|,
literal|4096
argument_list|,
name|message
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|zpool_iter
parameter_list|(
name|libzfs_handle_t
modifier|*
name|handle
parameter_list|,
name|zpool_iter_f
name|iter
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

