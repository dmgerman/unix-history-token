begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mount_irix.c	8.1 (Berkeley) 6/6/93  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * IRIX Mount helper  */
end_comment

begin_include
include|#
directive|include
file|"misc-irix.h"
end_include

begin_comment
comment|/*  * Map from conventional mount arguments  * to IRIX style arguments.  */
end_comment

begin_macro
name|irix_mount
argument_list|(
argument|fsname
argument_list|,
argument|dir
argument_list|,
argument|flags
argument_list|,
argument|type
argument_list|,
argument|data
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|fsname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|data
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|size
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|dlog
argument_list|(
literal|"irix_mount: fsname %s, dir %s, type %d"
argument_list|,
name|fsname
argument_list|,
name|dir
argument_list|,
name|type
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
if|if
condition|(
name|type
operator|==
name|MOUNT_TYPE_NFS
condition|)
block|{
name|size
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|nfs_args
argument_list|)
expr_stmt|;
return|return
name|mount
argument_list|(
name|dir
argument_list|,
name|dir
argument_list|,
operator|(
name|MS_FSS
operator||
name|MS_DATA
operator||
name|flags
operator|)
argument_list|,
name|type
argument_list|,
operator|(
expr|struct
name|nfs_args
operator|*
operator|)
name|data
argument_list|,
name|size
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|MOUNT_TYPE_UFS
condition|)
block|{
return|return
name|mount
argument_list|(
name|fsname
argument_list|,
name|dir
argument_list|,
operator|(
name|MS_FSS
operator||
name|flags
operator|)
argument_list|,
name|type
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|EINVAL
return|;
block|}
block|}
end_block

end_unit

