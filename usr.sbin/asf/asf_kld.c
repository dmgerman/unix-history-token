begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 The FreeBSD Project  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"asf.h"
end_include

begin_comment
comment|/*  * Get the linker file list using the kld interface.  * Works with a live kernel only.  */
end_comment

begin_function
name|void
name|asf_kld
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|kld_file_stat
name|kfs
decl_stmt|;
name|int
name|fid
init|=
literal|0
decl_stmt|;
comment|/* indicates the beginning of the linker file list */
while|while
condition|(
operator|(
name|fid
operator|=
name|kldnext
argument_list|(
name|fid
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|fid
operator|==
operator|-
literal|1
condition|)
name|err
argument_list|(
literal|2
argument_list|,
literal|"kldnext"
argument_list|)
expr_stmt|;
name|kfs
operator|.
name|version
operator|=
sizeof|sizeof
argument_list|(
name|kfs
argument_list|)
expr_stmt|;
comment|/* must be set for kldstat(2) */
comment|/* Get info on this linker file */
if|if
condition|(
name|kldstat
argument_list|(
name|fid
argument_list|,
operator|&
name|kfs
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|err
argument_list|(
literal|2
argument_list|,
literal|"kldstat"
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|kfs
operator|.
name|name
argument_list|,
name|KERNFILE
argument_list|)
operator|==
literal|0
condition|)
continue|continue;
comment|/* Add to our list of linker files */
name|kfile_add
argument_list|(
name|kfs
operator|.
name|name
argument_list|,
name|kfs
operator|.
name|address
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

