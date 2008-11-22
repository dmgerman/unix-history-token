begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* safe-read.c -- an interface to read that retries after interrupts    Copyright (C) 1993, 1994, 1998 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.    */
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
file|<sys/types.h>
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
file|"safe-read.h"
end_include

begin_comment
comment|/* Read LEN bytes at PTR from descriptor DESC, retrying if interrupted.    Return the actual number of bytes read, zero for EOF, or negative    for an error.  */
end_comment

begin_function
name|ssize_t
name|safe_read
parameter_list|(
name|int
name|desc
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
name|ssize_t
name|n_chars
decl_stmt|;
if|if
condition|(
name|len
operator|<=
literal|0
condition|)
return|return
name|len
return|;
ifdef|#
directive|ifdef
name|EINTR
do|do
block|{
name|n_chars
operator|=
name|read
argument_list|(
name|desc
argument_list|,
name|ptr
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|n_chars
operator|<
literal|0
operator|&&
name|errno
operator|==
name|EINTR
condition|)
do|;
else|#
directive|else
name|n_chars
operator|=
name|read
argument_list|(
name|desc
argument_list|,
name|ptr
argument_list|,
name|len
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|n_chars
return|;
block|}
end_function

end_unit

