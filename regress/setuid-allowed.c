begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Damien Miller<djm@mindrot.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $OpenBSD$ */
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STATVFS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/statvfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_function
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"check-setuid [path]\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
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
specifier|const
name|char
modifier|*
name|path
init|=
literal|"."
decl_stmt|;
name|struct
name|statvfs
name|sb
decl_stmt|;
if|if
condition|(
name|argc
operator|>
literal|2
condition|)
name|usage
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|argc
operator|==
literal|2
condition|)
name|path
operator|=
name|argv
index|[
literal|1
index|]
expr_stmt|;
if|if
condition|(
name|statvfs
argument_list|(
name|path
argument_list|,
operator|&
name|sb
argument_list|)
operator|!=
literal|0
condition|)
block|{
comment|/* Don't return an error if the host doesn't support statvfs */
if|if
condition|(
name|errno
operator|==
name|ENOSYS
condition|)
return|return
literal|0
return|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"statvfs for \"%s\" failed: %s\n"
argument_list|,
name|path
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|sb
operator|.
name|f_flag
operator|&
name|ST_NOSUID
operator|)
condition|?
literal|1
else|:
literal|0
return|;
block|}
end_function

end_unit

