begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xgetcwd.c -- return current directory with unlimited length    Copyright (C) 1992, 1996, 2000, 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by David MacKenzie<djm@gnu.ai.mit.edu>.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
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
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|errno
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|HAVE_STDLIB_H
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|HAVE_GETCWD
end_if

begin_function_decl
name|char
modifier|*
name|getcwd
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"pathmax.h"
end_include

begin_define
define|#
directive|define
name|INITIAL_BUFFER_SIZE
value|(PATH_MAX + 1)
end_define

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
name|Buf
parameter_list|,
name|Max
parameter_list|)
value|getwd (Buf)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"xalloc.h"
end_include

begin_comment
comment|/* Return the current directory, newly allocated, arbitrarily long.    Return NULL and set errno on error. */
end_comment

begin_function
name|char
modifier|*
name|xgetcwd
parameter_list|()
block|{
if|#
directive|if
name|HAVE_GETCWD_NULL
name|char
modifier|*
name|cwd
init|=
name|getcwd
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|cwd
operator|&&
name|errno
operator|==
name|ENOMEM
condition|)
name|xalloc_die
argument_list|()
expr_stmt|;
return|return
name|cwd
return|;
else|#
directive|else
comment|/* The initial buffer size for the working directory.  A power of 2      detects arithmetic overflow earlier, but is not required.  */
ifndef|#
directive|ifndef
name|INITIAL_BUFFER_SIZE
define|#
directive|define
name|INITIAL_BUFFER_SIZE
value|128
endif|#
directive|endif
name|size_t
name|buf_size
init|=
name|INITIAL_BUFFER_SIZE
decl_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|char
modifier|*
name|buf
init|=
name|xmalloc
argument_list|(
name|buf_size
argument_list|)
decl_stmt|;
name|char
modifier|*
name|cwd
init|=
name|getcwd
argument_list|(
name|buf
argument_list|,
name|buf_size
argument_list|)
decl_stmt|;
name|int
name|saved_errno
decl_stmt|;
if|if
condition|(
name|cwd
condition|)
return|return
name|cwd
return|;
name|saved_errno
operator|=
name|errno
expr_stmt|;
name|free
argument_list|(
name|buf
argument_list|)
expr_stmt|;
if|if
condition|(
name|saved_errno
operator|!=
name|ERANGE
condition|)
return|return
name|NULL
return|;
name|buf_size
operator|*=
literal|2
expr_stmt|;
if|if
condition|(
name|buf_size
operator|==
literal|0
condition|)
name|xalloc_die
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function

end_unit

