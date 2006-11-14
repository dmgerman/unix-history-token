begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Invoke dup, but avoid some glitches.    Copyright (C) 2001, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert.  */
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
file|<errno.h>
end_include

begin_if
if|#
directive|if
name|HAVE_FCNTL_H
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
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

begin_ifndef
ifndef|#
directive|ifndef
name|STDERR_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<unistd-safer.h>
end_include

begin_comment
comment|/* Like dup, but do not return STDIN_FILENO, STDOUT_FILENO, or    STDERR_FILENO.  */
end_comment

begin_function
name|int
name|dup_safer
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|F_DUPFD
return|return
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_DUPFD
argument_list|,
name|STDERR_FILENO
operator|+
literal|1
argument_list|)
return|;
else|#
directive|else
name|int
name|f
init|=
name|dup
argument_list|(
name|fd
argument_list|)
decl_stmt|;
if|if
condition|(
literal|0
operator|<=
name|f
operator|&&
name|f
operator|<=
name|STDERR_FILENO
condition|)
block|{
name|int
name|f1
init|=
name|dup_safer
argument_list|(
name|f
argument_list|)
decl_stmt|;
name|int
name|e
init|=
name|errno
decl_stmt|;
name|close
argument_list|(
name|f
argument_list|)
expr_stmt|;
name|errno
operator|=
name|e
expr_stmt|;
name|f
operator|=
name|f1
expr_stmt|;
block|}
return|return
name|f
return|;
endif|#
directive|endif
block|}
end_function

end_unit

