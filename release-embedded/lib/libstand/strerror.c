begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: strerror.c,v 1.12 1997/01/25 00:37:50 cgd Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|"stand.h"
end_include

begin_struct
specifier|static
struct|struct
block|{
name|int
name|err
decl_stmt|;
name|char
modifier|*
name|msg
decl_stmt|;
block|}
name|errtab
index|[]
init|=
block|{
block|{
literal|0
block|,
literal|"no error"
block|}
block|,
comment|/* standard errors */
block|{
name|EPERM
block|,
literal|"operation not permitted"
block|}
block|,
block|{
name|ENOENT
block|,
literal|"no such file or directory"
block|}
block|,
block|{
name|EIO
block|,
literal|"input/output error"
block|}
block|,
block|{
name|ENXIO
block|,
literal|"device not configured"
block|}
block|,
block|{
name|ENOEXEC
block|,
literal|"exec format error"
block|}
block|,
block|{
name|EBADF
block|,
literal|"bad file descriptor"
block|}
block|,
block|{
name|ENOMEM
block|,
literal|"cannot allocate memory"
block|}
block|,
block|{
name|ENODEV
block|,
literal|"operation not supported by device"
block|}
block|,
block|{
name|ENOTDIR
block|,
literal|"not a directory"
block|}
block|,
block|{
name|EISDIR
block|,
literal|"is a directory"
block|}
block|,
block|{
name|EINVAL
block|,
literal|"invalid argument"
block|}
block|,
block|{
name|EMFILE
block|,
literal|"too many open files"
block|}
block|,
block|{
name|EFBIG
block|,
literal|"file too large"
block|}
block|,
block|{
name|EROFS
block|,
literal|"read-only filesystem"
block|}
block|,
block|{
name|EOPNOTSUPP
block|,
literal|"operation not supported"
block|}
block|,
block|{
name|ETIMEDOUT
block|,
literal|"operation timed out"
block|}
block|,
block|{
name|ESTALE
block|,
literal|"stale NFS file handle"
block|}
block|,
block|{
name|EBADRPC
block|,
literal|"RPC struct is bad"
block|}
block|,
block|{
name|EFTYPE
block|,
literal|"inappropriate file type or format"
block|}
block|,
block|{
name|EADAPT
block|,
literal|"bad adaptor number"
block|}
block|,
block|{
name|ECTLR
block|,
literal|"bad controller number"
block|}
block|,
block|{
name|EUNIT
block|,
literal|"bad unit number"
block|}
block|,
block|{
name|ESLICE
block|,
literal|"bad slice number"
block|}
block|,
block|{
name|EPART
block|,
literal|"bad partition"
block|}
block|,
block|{
name|ERDLAB
block|,
literal|"can't read disk label"
block|}
block|,
block|{
name|EUNLAB
block|,
literal|"disk unlabelled"
block|}
block|,
block|{
name|EOFFSET
block|,
literal|"illegal seek"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
struct|;
end_struct

begin_function
name|char
modifier|*
name|strerror
parameter_list|(
name|int
name|err
parameter_list|)
block|{
specifier|static
name|char
name|msg
index|[
literal|32
index|]
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|errtab
index|[
name|i
index|]
operator|.
name|msg
operator|!=
name|NULL
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|errtab
index|[
name|i
index|]
operator|.
name|err
operator|==
name|err
condition|)
return|return
operator|(
name|errtab
index|[
name|i
index|]
operator|.
name|msg
operator|)
return|;
name|sprintf
argument_list|(
name|msg
argument_list|,
literal|"unknown error (%d)"
argument_list|,
name|err
argument_list|)
expr_stmt|;
return|return
operator|(
name|msg
operator|)
return|;
block|}
end_function

end_unit

