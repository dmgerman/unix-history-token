begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Andriy Gapon<avg@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|"libzfs.h"
end_include

begin_macro
name|__attribute__
argument_list|(
argument|(weak)
argument_list|)
end_macro

begin_function
name|int
name|zfs_parsedev
parameter_list|(
name|struct
name|zfs_devdesc
modifier|*
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|devspec
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|path
parameter_list|)
block|{
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(weak)
argument_list|)
end_macro

begin_function
name|char
modifier|*
name|zfs_fmtdev
parameter_list|(
name|void
modifier|*
name|vdev
parameter_list|)
block|{
specifier|static
name|char
name|buf
index|[
literal|128
index|]
decl_stmt|;
return|return
operator|(
name|buf
operator|)
return|;
block|}
end_function

end_unit

