begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* full-write.c -- an interface to write that retries after interrupts     Copyright 1993, 1994, 1997, 1998, 1999, 2000, 2001 Free Software    Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Paul Eggert.  */
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

begin_include
include|#
directive|include
file|"full-write.h"
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

begin_comment
comment|/* Write LEN bytes at PTR to descriptor DESC, retrying if interrupted    or if partial writes occur.  Return the number of bytes successfully    written, setting errno if that is less than LEN.  */
end_comment

begin_function
name|size_t
name|full_write
parameter_list|(
name|int
name|desc
parameter_list|,
specifier|const
name|char
modifier|*
name|ptr
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
name|size_t
name|total_written
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|len
operator|>
literal|0
condition|)
block|{
name|ssize_t
name|written
init|=
name|write
argument_list|(
name|desc
argument_list|,
name|ptr
argument_list|,
name|len
argument_list|)
decl_stmt|;
if|if
condition|(
name|written
operator|<=
literal|0
condition|)
block|{
comment|/* Some buggy drivers return 0 when you fall off a device's end.  */
if|if
condition|(
name|written
operator|==
literal|0
condition|)
name|errno
operator|=
name|ENOSPC
expr_stmt|;
ifdef|#
directive|ifdef
name|EINTR
if|if
condition|(
name|errno
operator|==
name|EINTR
condition|)
continue|continue;
endif|#
directive|endif
break|break;
block|}
name|total_written
operator|+=
name|written
expr_stmt|;
name|ptr
operator|+=
name|written
expr_stmt|;
name|len
operator|-=
name|written
expr_stmt|;
block|}
return|return
name|total_written
return|;
block|}
end_function

end_unit

