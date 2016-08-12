begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_rename.c,v 1.2 2011/05/16 00:03:36 christos Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001, 2008, 2010 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|_NETBSD_SOURCE
end_define

begin_comment
comment|/* strlcat/random */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__COPYRIGHT
argument_list|(
literal|"@(#) Copyright (c) 2008, 2010\  The NetBSD Foundation, inc. All rights reserved."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: t_rename.c,v 1.2 2011/05/16 00:03:36 christos Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
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
file|"../../h_macros.h"
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|rename
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|rename
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
literal|"Checks rename(2)"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|rename
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|struct
name|stat
name|sb
decl_stmt|;
name|REQUIRE_LIBC
argument_list|(
name|open
argument_list|(
literal|"t1"
argument_list|,
name|O_CREAT
operator||
name|O_TRUNC
operator||
name|O_WRONLY
argument_list|,
literal|0600
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|REQUIRE_LIBC
argument_list|(
name|link
argument_list|(
literal|"t1"
argument_list|,
literal|"t2"
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* Check if rename to same name works as expected */
name|REQUIRE_LIBC
argument_list|(
name|rename
argument_list|(
literal|"t1"
argument_list|,
literal|"t1"
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* Rename removed file? */
name|REQUIRE_LIBC
argument_list|(
name|stat
argument_list|(
literal|"t1"
argument_list|,
operator|&
name|sb
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|REQUIRE_LIBC
argument_list|(
name|rename
argument_list|(
literal|"t1"
argument_list|,
literal|"t2"
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
if|#
directive|if
name|BSD_RENAME
comment|/* check if rename of hardlinked file works the BSD way */
name|ATF_REQUIRE_MSG
argument_list|(
name|stat
argument_list|(
literal|"t1"
argument_list|,
operator|&
name|sb
argument_list|)
operator|!=
literal|0
argument_list|,
literal|"BSD rename should remove file t1"
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_EQ
argument_list|(
name|errno
argument_list|,
name|ENOENT
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* check if rename of hardlinked file works as the standard says */
name|REQUIRE_LIBC
argument_list|(
name|stat
argument_list|(
literal|"t1"
argument_list|,
operator|&
name|sb
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* check if we get the expected error */
comment|/* this also exercises icky shared libraries goo */
name|ATF_REQUIRE_MSG
argument_list|(
name|rename
argument_list|(
literal|"no/such/file/or/dir"
argument_list|,
literal|"no/such/file/or/dir"
argument_list|)
operator|!=
literal|0
argument_list|,
literal|"No error renaming nonexistent file"
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_EQ
argument_list|(
name|errno
argument_list|,
name|ENOENT
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
name|rename
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

