begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xgetcwd.c -- return current directory with unlimited length    Copyright (C) 1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Written by David MacKenzie, djm@gnu.ai.mit.edu. */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
operator|||
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_LIMITS_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_VERSION&& !STDC_HEADERS&& !HAVE_LIMITS_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_PATH_MAX
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_PATH_MAX
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_MAX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_PC_PATH_MAX
end_ifdef

begin_define
define|#
directive|define
name|PATH_MAX
value|pathconf ("/", _PC_PATH_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_PC_PATH_MAX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAXPATHLEN
end_ifdef

begin_define
define|#
directive|define
name|PATH_MAX
value|MAXPATHLEN
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not MAXPATHLEN */
end_comment

begin_define
define|#
directive|define
name|PATH_MAX
value|_POSIX_PATH_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXPATHLEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PC_PATH_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !PATH_MAX */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USG
argument_list|)
end_if

begin_function_decl
name|char
modifier|*
name|getwd
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|getcwd
parameter_list|(
name|buf
parameter_list|,
name|max
parameter_list|)
value|getwd (buf)
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|getcwd
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Amount to increase buffer size by in each try. */
end_comment

begin_define
define|#
directive|define
name|PATH_INCR
value|32
end_define

begin_function_decl
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xrealloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the current directory, newly allocated, arbitrarily long.    Return NULL and set errno on error. */
end_comment

begin_function
name|char
modifier|*
name|xgetcwd
parameter_list|()
block|{
name|char
modifier|*
name|cwd
decl_stmt|;
name|char
modifier|*
name|ret
decl_stmt|;
name|long
name|path_max
decl_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|_POSIX_VERSION
name|path_max
operator|=
name|PATH_MAX
expr_stmt|;
if|if
condition|(
name|path_max
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
condition|)
return|return
name|NULL
return|;
name|path_max
operator|=
name|_POSIX_PATH_MAX
expr_stmt|;
block|}
else|#
directive|else
comment|/* !_POSIX_VERSION */
name|path_max
operator|=
name|PATH_MAX
expr_stmt|;
endif|#
directive|endif
comment|/* !_POSIX_VERSION */
name|path_max
operator|+=
literal|2
expr_stmt|;
comment|/* The getcwd docs say to do this. */
name|cwd
operator|=
operator|(
name|char
operator|*
operator|)
name|xmalloc
argument_list|(
name|path_max
argument_list|)
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|ret
operator|=
name|getcwd
argument_list|(
name|cwd
argument_list|,
name|path_max
argument_list|)
operator|)
operator|==
name|NULL
operator|&&
name|errno
operator|==
name|ERANGE
condition|)
block|{
name|path_max
operator|+=
name|PATH_INCR
expr_stmt|;
name|cwd
operator|=
name|xrealloc
argument_list|(
name|cwd
argument_list|,
name|path_max
argument_list|)
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|ret
operator|==
name|NULL
condition|)
block|{
name|int
name|save_errno
init|=
name|errno
decl_stmt|;
name|free
argument_list|(
name|cwd
argument_list|)
expr_stmt|;
name|errno
operator|=
name|save_errno
expr_stmt|;
return|return
name|NULL
return|;
block|}
return|return
name|cwd
return|;
block|}
end_function

end_unit

