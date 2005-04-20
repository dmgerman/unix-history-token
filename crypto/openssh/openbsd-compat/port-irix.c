begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Denis Parker.  All rights reserved.  * Copyright (c) 2000 Michael Stone.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WITH_IRIX_PROJECT
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|WITH_IRIX_JOBS
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|WITH_IRIX_ARRAY
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_IRIX_PROJECT
end_ifdef

begin_include
include|#
directive|include
file|<proj.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITH_IRIX_PROJECT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_IRIX_JOBS
end_ifdef

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_IRIX_AUDIT
end_ifdef

begin_include
include|#
directive|include
file|<sat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITH_IRIX_AUDIT */
end_comment

begin_function
name|void
name|irix_setusercontext
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|WITH_IRIX_PROJECT
name|prid_t
name|projid
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|WITH_IRIX_JOBS
name|jid_t
name|jid
init|=
literal|0
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|WITH_IRIX_ARRAY
argument_list|)
name|int
name|jid
init|=
literal|0
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|WITH_IRIX_JOBS
name|jid
operator|=
name|jlimit_startjob
argument_list|(
name|pw
operator|->
name|pw_name
argument_list|,
name|pw
operator|->
name|pw_uid
argument_list|,
literal|"interactive"
argument_list|)
expr_stmt|;
if|if
condition|(
name|jid
operator|==
operator|-
literal|1
condition|)
name|fatal
argument_list|(
literal|"Failed to create job container: %.100s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* WITH_IRIX_JOBS */
ifdef|#
directive|ifdef
name|WITH_IRIX_ARRAY
comment|/* initialize array session */
if|if
condition|(
name|jid
operator|==
literal|0
operator|&&
name|newarraysess
argument_list|()
operator|!=
literal|0
condition|)
name|fatal
argument_list|(
literal|"Failed to set up new array session: %.100s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* WITH_IRIX_ARRAY */
ifdef|#
directive|ifdef
name|WITH_IRIX_PROJECT
comment|/* initialize irix project info */
if|if
condition|(
operator|(
name|projid
operator|=
name|getdfltprojuser
argument_list|(
name|pw
operator|->
name|pw_name
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
name|debug
argument_list|(
literal|"Failed to get project id, using projid 0"
argument_list|)
expr_stmt|;
name|projid
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|setprid
argument_list|(
name|projid
argument_list|)
condition|)
name|fatal
argument_list|(
literal|"Failed to initialize project %d for %s: %.100s"
argument_list|,
operator|(
name|int
operator|)
name|projid
argument_list|,
name|pw
operator|->
name|pw_name
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* WITH_IRIX_PROJECT */
ifdef|#
directive|ifdef
name|WITH_IRIX_AUDIT
if|if
condition|(
name|sysconf
argument_list|(
name|_SC_AUDIT
argument_list|)
condition|)
block|{
name|debug
argument_list|(
literal|"Setting sat id to %d"
argument_list|,
operator|(
name|int
operator|)
name|pw
operator|->
name|pw_uid
argument_list|)
expr_stmt|;
if|if
condition|(
name|satsetid
argument_list|(
name|pw
operator|->
name|pw_uid
argument_list|)
condition|)
name|debug
argument_list|(
literal|"error setting satid: %.100s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* WITH_IRIX_AUDIT */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(WITH_IRIX_PROJECT) || defined(WITH_IRIX_JOBS) || defined(WITH_IRIX_ARRAY) */
end_comment

end_unit

