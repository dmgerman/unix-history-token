begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_file2.c,v 1.4 2017/01/13 21:30:41 christos Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002, 2008 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jaromir Dolecek.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__COPYRIGHT
argument_list|(
literal|"@(#) Copyright (c) 2008\  The NetBSD Foundation, inc. All rights reserved."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: t_file2.c,v 1.4 2017/01/13 21:30:41 christos Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/event.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|"h_macros.h"
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|file2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|file2
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Checks EVFILT_READ for regular files. This test used to "
literal|"trigger deadlock caused by problem fixed in revision 1.79.2.10 "
literal|"of sys/kern/kern_descrip.c"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|file2
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|int
name|fd1
decl_stmt|,
name|fd2
decl_stmt|,
name|kq
decl_stmt|;
name|struct
name|kevent
name|event
index|[
literal|1
index|]
decl_stmt|;
name|RL
argument_list|(
name|fd1
operator|=
name|open
argument_list|(
literal|"afile"
argument_list|,
name|O_RDONLY
operator||
name|O_CREAT
argument_list|,
literal|0644
argument_list|)
argument_list|)
expr_stmt|;
name|RL
argument_list|(
name|fd2
operator|=
name|open
argument_list|(
literal|"bfile"
argument_list|,
name|O_RDONLY
operator||
name|O_CREAT
argument_list|,
literal|0644
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
literal|1
comment|/* XXX: why was this disabled? */
name|RL
argument_list|(
name|lseek
argument_list|(
name|fd1
argument_list|,
literal|0
argument_list|,
name|SEEK_END
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|RL
argument_list|(
name|kq
operator|=
name|kqueue
argument_list|()
argument_list|)
expr_stmt|;
name|EV_SET
argument_list|(
operator|&
name|event
index|[
literal|0
index|]
argument_list|,
name|fd1
argument_list|,
name|EVFILT_READ
argument_list|,
name|EV_ADD
operator||
name|EV_ENABLE
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|RL
argument_list|(
name|kevent
argument_list|(
name|kq
argument_list|,
name|event
argument_list|,
literal|1
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
argument_list|)
expr_stmt|;
name|RL
argument_list|(
name|dup2
argument_list|(
name|fd2
argument_list|,
name|fd1
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TP_ADD_TCS
argument_list|(
argument|tp
argument_list|)
end_macro

begin_block
block|{
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|file2
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

