begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: getdtablesize.c,v 1.10 1999/12/02 16:58:46 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"roken.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TIME_WITH_SYS_TIME
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SYS_TIME_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_RESOURCE_H
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
name|HAVE_SYS_SYSCTL_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|getdtablesize
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|files
init|=
operator|-
literal|1
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYSCONF
argument_list|)
operator|&&
name|defined
argument_list|(
name|_SC_OPEN_MAX
argument_list|)
name|files
operator|=
name|sysconf
argument_list|(
name|_SC_OPEN_MAX
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* !defined(HAVE_SYSCONF) */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GETRLIMIT
argument_list|)
operator|&&
name|defined
argument_list|(
name|RLIMIT_NOFILE
argument_list|)
name|struct
name|rlimit
name|res
decl_stmt|;
if|if
condition|(
name|getrlimit
argument_list|(
name|RLIMIT_NOFILE
argument_list|,
operator|&
name|res
argument_list|)
operator|==
literal|0
condition|)
name|files
operator|=
name|res
operator|.
name|rlim_cur
expr_stmt|;
else|#
directive|else
comment|/* !definded(HAVE_GETRLIMIT) */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYSCTL
argument_list|)
operator|&&
name|defined
argument_list|(
name|CTL_KERN
argument_list|)
operator|&&
name|defined
argument_list|(
name|KERN_MAXFILES
argument_list|)
name|int
name|mib
index|[
literal|2
index|]
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|mib
index|[
literal|0
index|]
operator|=
name|CTL_KERN
expr_stmt|;
name|mib
index|[
literal|1
index|]
operator|=
name|KERN_MAXFILES
expr_stmt|;
name|len
operator|=
sizeof|sizeof
argument_list|(
name|files
argument_list|)
expr_stmt|;
name|sysctl
argument_list|(
operator|&
name|mib
argument_list|,
literal|2
argument_list|,
operator|&
name|files
argument_list|,
sizeof|sizeof
argument_list|(
name|nfil
argument_list|)
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* defined(HAVE_SYSCTL) */
endif|#
directive|endif
comment|/* !definded(HAVE_GETRLIMIT) */
endif|#
directive|endif
comment|/* !defined(HAVE_SYSCONF) */
ifdef|#
directive|ifdef
name|OPEN_MAX
if|if
condition|(
name|files
operator|<
literal|0
condition|)
name|files
operator|=
name|OPEN_MAX
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NOFILE
if|if
condition|(
name|files
operator|<
literal|0
condition|)
name|files
operator|=
name|NOFILE
expr_stmt|;
endif|#
directive|endif
return|return
name|files
return|;
block|}
end_function

end_unit

