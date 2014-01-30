begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2011 Damien Miller<djm@mindrot.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SANDBOX_NULL
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
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
file|"log.h"
end_include

begin_include
include|#
directive|include
file|"ssh-sandbox.h"
end_include

begin_include
include|#
directive|include
file|"xmalloc.h"
end_include

begin_comment
comment|/* dummy sandbox */
end_comment

begin_struct
struct|struct
name|ssh_sandbox
block|{
name|int
name|junk
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|ssh_sandbox
modifier|*
name|ssh_sandbox_init
parameter_list|(
name|struct
name|monitor
modifier|*
name|monitor
parameter_list|)
block|{
name|struct
name|ssh_sandbox
modifier|*
name|box
decl_stmt|;
comment|/* 	 * Strictly, we don't need to maintain any state here but we need 	 * to return non-NULL to satisfy the API. 	 */
name|box
operator|=
name|xcalloc
argument_list|(
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|box
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|box
return|;
block|}
end_function

begin_function
name|void
name|ssh_sandbox_child
parameter_list|(
name|struct
name|ssh_sandbox
modifier|*
name|box
parameter_list|)
block|{
comment|/* Nothing to do here */
block|}
end_function

begin_function
name|void
name|ssh_sandbox_parent_finish
parameter_list|(
name|struct
name|ssh_sandbox
modifier|*
name|box
parameter_list|)
block|{
name|free
argument_list|(
name|box
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ssh_sandbox_parent_preauth
parameter_list|(
name|struct
name|ssh_sandbox
modifier|*
name|box
parameter_list|,
name|pid_t
name|child_pid
parameter_list|)
block|{
comment|/* Nothing to do here */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SANDBOX_NULL */
end_comment

end_unit

