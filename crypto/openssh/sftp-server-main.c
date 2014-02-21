begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: sftp-server-main.c,v 1.4 2009/02/21 19:32:04 tobias Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008 Markus Friedl.  All rights reserved.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_include
include|#
directive|include
file|"sftp.h"
end_include

begin_include
include|#
directive|include
file|"misc.h"
end_include

begin_function
name|void
name|cleanup_exit
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|sftp_server_cleanup_exit
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|struct
name|passwd
modifier|*
name|user_pw
decl_stmt|;
comment|/* Ensure that fds 0, 1 and 2 are open or directed to /dev/null */
name|sanitise_stdfd
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|user_pw
operator|=
name|getpwuid
argument_list|(
name|getuid
argument_list|()
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"No user found for uid %lu\n"
argument_list|,
operator|(
name|u_long
operator|)
name|getuid
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
return|return
operator|(
name|sftp_server_main
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|user_pw
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

