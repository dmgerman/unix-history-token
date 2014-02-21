begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"archive_platform.h"
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
file|"archive.h"
end_include

begin_include
include|#
directive|include
file|"archive_private.h"
end_include

begin_if
if|#
directive|if
name|ARCHIVE_VERSION_NUMBER
operator|<
literal|4000000
end_if

begin_comment
comment|/* Deprecated; remove in libarchive 4.0 */
end_comment

begin_function
name|int
name|archive_read_support_compression_none
parameter_list|(
name|struct
name|archive
modifier|*
name|a
parameter_list|)
block|{
return|return
name|archive_read_support_filter_none
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Uncompressed streams are handled implicitly by the read core,  * so this is now a no-op.  */
end_comment

begin_function
name|int
name|archive_read_support_filter_none
parameter_list|(
name|struct
name|archive
modifier|*
name|a
parameter_list|)
block|{
name|archive_check_magic
argument_list|(
name|a
argument_list|,
name|ARCHIVE_READ_MAGIC
argument_list|,
name|ARCHIVE_STATE_NEW
argument_list|,
literal|"archive_read_support_filter_none"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ARCHIVE_OK
operator|)
return|;
block|}
end_function

end_unit

