begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015 Joyent, Inc  * Author: Alex Wilson<alex.wilson@joyent.com>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
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
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"platform.h"
end_include

begin_include
include|#
directive|include
file|"openbsd-compat/openbsd-compat.h"
end_include

begin_comment
comment|/*  * Drop any fine-grained privileges that are not needed for post-startup  * operation of ssh-agent  *  * Should be as close as possible to pledge("stdio cpath unix id proc exec", ...)  */
end_comment

begin_function
name|void
name|platform_pledge_agent
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|USE_SOLARIS_PRIVS
comment|/* 	 * Note: Solaris priv dropping is closer to tame() than pledge(), but 	 * we will use what we have. 	 */
name|solaris_drop_privs_root_pinfo_net
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * Drop any fine-grained privileges that are not needed for post-startup  * operation of sftp-server  */
end_comment

begin_function
name|void
name|platform_pledge_sftp_server
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|USE_SOLARIS_PRIVS
name|solaris_drop_privs_pinfo_net_fork_exec
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * Drop any fine-grained privileges that are not needed for the post-startup  * operation of the SSH client mux  *  * Should be as close as possible to pledge("stdio proc tty", ...)  */
end_comment

begin_function
name|void
name|platform_pledge_mux
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|USE_SOLARIS_PRIVS
name|solaris_drop_privs_root_pinfo_net_exec
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

