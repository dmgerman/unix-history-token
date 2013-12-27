begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2005 Todd C. Miller<Todd.Miller@courtesan.com>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_CLOSEFROM
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FCNTL_H
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DIRENT_H
end_ifdef

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_define
define|#
directive|define
name|NAMLEN
parameter_list|(
name|dirent
parameter_list|)
value|strlen((dirent)->d_name)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dirent
value|direct
end_define

begin_define
define|#
directive|define
name|NAMLEN
parameter_list|(
name|dirent
parameter_list|)
value|(dirent)->d_namlen
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_NDIR_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/ndir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_DIR_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NDIR_H
end_ifdef

begin_include
include|#
directive|include
file|<ndir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPEN_MAX
end_ifndef

begin_define
define|#
directive|define
name|OPEN_MAX
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|__unused static const char rcsid[] = "$Sudo: closefrom.c,v 1.11 2006/08/17 15:26:54 millert Exp $";
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_comment
comment|/*  * Close all file descriptors greater than or equal to lowfd.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FCNTL_CLOSEM
end_ifdef

begin_function
name|void
name|closefrom
parameter_list|(
name|int
name|lowfd
parameter_list|)
block|{
operator|(
name|void
operator|)
name|fcntl
argument_list|(
name|lowfd
argument_list|,
name|F_CLOSEM
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|void
name|closefrom
parameter_list|(
name|int
name|lowfd
parameter_list|)
block|{
name|long
name|fd
decl_stmt|,
name|maxfd
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DIRFD
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_PROC_PID
argument_list|)
name|char
name|fdpath
index|[
name|PATH_MAX
index|]
decl_stmt|,
modifier|*
name|endp
decl_stmt|;
name|struct
name|dirent
modifier|*
name|dent
decl_stmt|;
name|DIR
modifier|*
name|dirp
decl_stmt|;
name|int
name|len
decl_stmt|;
comment|/* Check for a /proc/$$/fd directory. */
name|len
operator|=
name|snprintf
argument_list|(
name|fdpath
argument_list|,
sizeof|sizeof
argument_list|(
name|fdpath
argument_list|)
argument_list|,
literal|"/proc/%ld/fd"
argument_list|,
operator|(
name|long
operator|)
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|len
operator|>
literal|0
operator|&&
operator|(
name|size_t
operator|)
name|len
operator|<=
sizeof|sizeof
argument_list|(
name|fdpath
argument_list|)
operator|&&
operator|(
name|dirp
operator|=
name|opendir
argument_list|(
name|fdpath
argument_list|)
operator|)
condition|)
block|{
while|while
condition|(
operator|(
name|dent
operator|=
name|readdir
argument_list|(
name|dirp
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|fd
operator|=
name|strtol
argument_list|(
name|dent
operator|->
name|d_name
argument_list|,
operator|&
name|endp
argument_list|,
literal|10
argument_list|)
expr_stmt|;
if|if
condition|(
name|dent
operator|->
name|d_name
operator|!=
name|endp
operator|&&
operator|*
name|endp
operator|==
literal|'\0'
operator|&&
name|fd
operator|>=
literal|0
operator|&&
name|fd
operator|<
name|INT_MAX
operator|&&
name|fd
operator|>=
name|lowfd
operator|&&
name|fd
operator|!=
name|dirfd
argument_list|(
name|dirp
argument_list|)
condition|)
operator|(
name|void
operator|)
name|close
argument_list|(
operator|(
name|int
operator|)
name|fd
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|closedir
argument_list|(
name|dirp
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
comment|/* 	 * Fall back on sysconf() or getdtablesize().  We avoid checking 	 * resource limits since it is possible to open a file descriptor 	 * and then drop the rlimit such that it is below the open fd. 	 */
ifdef|#
directive|ifdef
name|HAVE_SYSCONF
name|maxfd
operator|=
name|sysconf
argument_list|(
name|_SC_OPEN_MAX
argument_list|)
expr_stmt|;
else|#
directive|else
name|maxfd
operator|=
name|getdtablesize
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_SYSCONF */
if|if
condition|(
name|maxfd
operator|<
literal|0
condition|)
name|maxfd
operator|=
name|OPEN_MAX
expr_stmt|;
for|for
control|(
name|fd
operator|=
name|lowfd
init|;
name|fd
operator|<
name|maxfd
condition|;
name|fd
operator|++
control|)
operator|(
name|void
operator|)
name|close
argument_list|(
operator|(
name|int
operator|)
name|fd
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_FCNTL_CLOSEM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CLOSEFROM */
end_comment

end_unit

