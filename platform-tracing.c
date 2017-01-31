begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016 Darren Tucker.  All rights reserved.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_PRCTL_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/prctl.h>
end_include

begin_comment
comment|/* For prctl() and PR_SET_DUMPABLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PRIV_H
end_ifdef

begin_include
include|#
directive|include
file|<priv.h>
end_include

begin_comment
comment|/* For setpflags() and __PROC_PROTECT  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_function
name|void
name|platform_disable_tracing
parameter_list|(
name|int
name|strict
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|HAVE_PRCTL
argument_list|)
operator|&&
name|defined
argument_list|(
name|PR_SET_DUMPABLE
argument_list|)
comment|/* Disable ptrace on Linux without sgid bit */
if|if
condition|(
name|prctl
argument_list|(
name|PR_SET_DUMPABLE
argument_list|,
literal|0
argument_list|)
operator|!=
literal|0
operator|&&
name|strict
condition|)
name|fatal
argument_list|(
literal|"unable to make the process undumpable"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SETPFLAGS
argument_list|)
operator|&&
name|defined
argument_list|(
name|__PROC_PROTECT
argument_list|)
comment|/* On Solaris, we should make this process untraceable */
if|if
condition|(
name|setpflags
argument_list|(
name|__PROC_PROTECT
argument_list|,
literal|1
argument_list|)
operator|!=
literal|0
operator|&&
name|strict
condition|)
name|fatal
argument_list|(
literal|"unable to make the process untraceable"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

