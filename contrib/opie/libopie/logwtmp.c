begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* logwtmp.c: Put an entry in the wtmp file.  %%% portions-copyright-cmetz-96 Portions of this software are Copyright 1996-1998 by Craig Metz, All Rights Reserved. The Inner Net License Version 2 applies to these portions of the software. You should have received a copy of the license with this software. If you didn't get a copy, you may request one from<license@inner.net>.  Portions of this software are Copyright 1995 by Randall Atkinson and Dan McDonald, All Rights Reserved. All Rights under this copyright are assigned to the U.S. Naval Research Laboratory (NRL). The NRL Copyright Notice and License Agreement applies to this software.  	History:  	Modified by cmetz for OPIE 2.32. Don't leave line=NULL, skip 		past /dev/ in line. Fill in ut_host on systems with UTMPX and 		ut_host. 	Modified by cmetz for OPIE 2.31. Move wtmp log functions here, to 		improve portability. Added DISABLE_WTMP. 	Modified by cmetz for OPIE 2.22. Call gettimeofday() properly. 	Modified by cmetz for OPIE 2.2. Use FUNCTION declaration et al.         	Ifdef around some headers. Added file close hook. 	Modified at NRL for OPIE 2.1. Set process type for HPUX. 	Modified at NRL for OPIE 2.0. 	Originally from BSD. */
end_comment

begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|"opie_cfg.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_TIME_H */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<utmp.h>
end_include

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UNISTD_H */
end_comment

begin_if
if|#
directive|if
name|HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STRING_H */
end_comment

begin_include
include|#
directive|include
file|"opie.h"
end_include

begin_decl_stmt
specifier|static
name|int
name|fd
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|DOUTMPX
end_if

begin_decl_stmt
specifier|static
name|int
name|fdx
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<utmpx.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DOUTMPX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_WTMP
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|WTMP_FILE
end_ifdef

begin_define
define|#
directive|define
name|_PATH_WTMP
value|WTMP_FILE
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* WTMP_FILE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PATH_WTMP_AC
end_ifdef

begin_define
define|#
directive|define
name|_PATH_WTMP
value|PATH_WTMP_AC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PATH_WTMP_AC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WTMP_FILE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_WTMP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_WTMPX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|WTMPX_FILE
end_ifdef

begin_define
define|#
directive|define
name|_PATH_WTMPX
value|WTMPX_FILE
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* WTMPX_FILE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PATH_WTMPX_AC
end_ifdef

begin_define
define|#
directive|define
name|_PATH_WTMPX
value|PATH_WTMPX_AC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PATH_WTMPX_AC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WTMPX_FILE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_WTMPX */
end_comment

begin_comment
comment|/*  * Modified version of logwtmp that holds wtmp file open  * after first call, for use with ftp (which may chroot  * after login, but before logout).  */
end_comment

begin_decl_stmt
name|VOIDRET
name|opielogwtmp
name|FUNCTION
argument_list|(
operator|(
name|line
operator|,
name|name
operator|,
name|host
operator|)
argument_list|,
name|char
operator|*
name|line
name|AND
name|char
operator|*
name|name
name|AND
name|char
operator|*
name|host
argument_list|)
block|{
if|#
directive|if
operator|!
name|DISABLE_WTMP
name|struct
name|utmp
name|ut
decl_stmt|;
if|#
directive|if
name|DOUTMPX
operator|&&
name|defined
argument_list|(
name|_PATH_WTMPX
argument_list|)
name|struct
name|utmpx
name|utx
decl_stmt|;
endif|#
directive|endif
comment|/* DOUTMPX&& defined(_PATH_WTMPX) */
name|struct
name|stat
name|buf
decl_stmt|;
name|memset
argument_list|(
operator|&
name|ut
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|utmp
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|line
condition|)
block|{
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
if|#
directive|if
name|DOUTMPX
operator|&&
name|defined
argument_list|(
name|_PATH_WTMPX
argument_list|)
name|close
argument_list|(
name|fdx
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DOUTMPX&& defined(_PATH_WTMPX) */
name|line
operator|=
literal|""
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|line
argument_list|,
literal|"/dev/"
argument_list|,
literal|5
argument_list|)
condition|)
name|line
operator|+=
literal|5
expr_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
operator|&&
operator|(
name|fd
operator|=
name|open
argument_list|(
name|_PATH_WTMP
argument_list|,
name|O_WRONLY
operator||
name|O_APPEND
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return;
if|if
condition|(
name|fstat
argument_list|(
name|fd
argument_list|,
operator|&
name|buf
argument_list|)
operator|==
literal|0
condition|)
block|{
if|#
directive|if
name|HAVE_UT_TYPE
operator|&&
name|defined
argument_list|(
name|USER_PROCESS
argument_list|)
name|ut
operator|.
name|ut_type
operator|=
name|USER_PROCESS
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_UT_TYPE&& defined(USER_PROCESS) */
if|#
directive|if
name|HAVE_UT_PID
name|ut
operator|.
name|ut_pid
operator|=
name|getpid
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_UT_PID */
name|strncpy
argument_list|(
name|ut
operator|.
name|ut_line
argument_list|,
name|line
argument_list|,
sizeof|sizeof
argument_list|(
name|ut
operator|.
name|ut_line
argument_list|)
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|ut
operator|.
name|ut_name
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|ut
operator|.
name|ut_name
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|HAVE_UT_HOST
name|strncpy
argument_list|(
name|ut
operator|.
name|ut_host
argument_list|,
name|host
argument_list|,
sizeof|sizeof
argument_list|(
name|ut
operator|.
name|ut_host
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_UT_HOST */
name|time
argument_list|(
operator|&
name|ut
operator|.
name|ut_time
argument_list|)
expr_stmt|;
if|if
condition|(
name|write
argument_list|(
name|fd
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|ut
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|utmp
argument_list|)
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
expr|struct
name|utmp
argument_list|)
condition|)
name|ftruncate
argument_list|(
name|fd
argument_list|,
name|buf
operator|.
name|st_size
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
name|DOUTMPX
operator|&&
name|defined
argument_list|(
name|_PATH_WTMPX
argument_list|)
name|memset
argument_list|(
operator|&
name|utx
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|utmpx
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|fdx
operator|<
literal|0
operator|&&
operator|(
name|fdx
operator|=
name|open
argument_list|(
name|_PATH_WTMPX
argument_list|,
name|O_WRONLY
operator||
name|O_APPEND
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return;
if|if
condition|(
name|fstat
argument_list|(
name|fdx
argument_list|,
operator|&
name|buf
argument_list|)
operator|==
literal|0
condition|)
block|{
name|strncpy
argument_list|(
name|utx
operator|.
name|ut_line
argument_list|,
name|line
argument_list|,
sizeof|sizeof
argument_list|(
name|utx
operator|.
name|ut_line
argument_list|)
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|utx
operator|.
name|ut_name
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|utx
operator|.
name|ut_name
argument_list|)
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|utx
operator|.
name|ut_host
argument_list|,
name|host
argument_list|,
sizeof|sizeof
argument_list|(
name|utx
operator|.
name|ut_host
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|HAVE_GETTIMEOFDAY
if|#
directive|if
name|HAVE_ONE_ARG_GETTIMEOFDAY
name|gettimeofday
argument_list|(
operator|&
name|utx
operator|.
name|ut_tv
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* HAVE_ONE_ARG_GETTIMEOFDAY */
name|gettimeofday
argument_list|(
operator|&
name|utx
operator|.
name|ut_tv
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_ONE_ARG_GETTIMEOFDAY */
endif|#
directive|endif
comment|/* HAVE_GETTIMEOFDAY */
if|if
condition|(
name|write
argument_list|(
name|fdx
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|utx
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|utmpx
argument_list|)
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
expr|struct
name|utmpx
argument_list|)
condition|)
name|ftruncate
argument_list|(
name|fdx
argument_list|,
name|buf
operator|.
name|st_size
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* DOUTMPX&& defined(_PATH_WTMPX) */
endif|#
directive|endif
comment|/* !DISABLE_WTMP */
block|}
end_decl_stmt

end_unit

