begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: platform.c,v 1.3 2009/12/20 23:49:22 dtucker Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2006 Darren Tucker.  All rights reserved.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
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

begin_function
name|void
name|platform_pre_listen
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|LINUX_OOM_ADJUST
comment|/* Adjust out-of-memory killer so listening process is not killed */
name|oom_adjust_setup
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
name|void
name|platform_pre_fork
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|USE_SOLARIS_PROCESS_CONTRACTS
name|solaris_contract_pre_fork
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
name|void
name|platform_post_fork_parent
parameter_list|(
name|pid_t
name|child_pid
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|USE_SOLARIS_PROCESS_CONTRACTS
name|solaris_contract_post_fork_parent
argument_list|(
name|child_pid
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
name|void
name|platform_post_fork_child
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|USE_SOLARIS_PROCESS_CONTRACTS
name|solaris_contract_post_fork_child
argument_list|()
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LINUX_OOM_ADJUST
name|oom_adjust_restore
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
name|char
modifier|*
name|platform_krb5_get_principal_name
parameter_list|(
specifier|const
name|char
modifier|*
name|pw_name
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|USE_AIX_KRB_NAME
return|return
name|aix_krb5_get_principal_name
argument_list|(
name|pw_name
argument_list|)
return|;
else|#
directive|else
return|return
name|NULL
return|;
endif|#
directive|endif
block|}
end_function

end_unit

