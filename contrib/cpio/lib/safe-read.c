begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* An interface to read and write that retries after interrupts.     Copyright (C) 1993, 1994, 1998, 2002, 2003, 2004 Free Software    Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_comment
comment|/* Specification.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SAFE_WRITE
end_ifdef

begin_include
include|#
directive|include
file|"safe-write.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"safe-read.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get ssize_t.  */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|EINTR
end_ifdef

begin_define
define|#
directive|define
name|IS_EINTR
parameter_list|(
name|x
parameter_list|)
value|((x) == EINTR)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IS_EINTR
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SAFE_WRITE
end_ifdef

begin_define
define|#
directive|define
name|safe_rw
value|safe_write
end_define

begin_define
define|#
directive|define
name|rw
value|write
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|safe_rw
value|safe_read
end_define

begin_define
define|#
directive|define
name|rw
value|read
end_define

begin_undef
undef|#
directive|undef
name|const
end_undef

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Read(write) up to COUNT bytes at BUF from(to) descriptor FD, retrying if    interrupted.  Return the actual number of bytes read(written), zero for EOF,    or SAFE_READ_ERROR(SAFE_WRITE_ERROR) upon error.  */
end_comment

begin_function
name|size_t
name|safe_rw
parameter_list|(
name|int
name|fd
parameter_list|,
name|void
specifier|const
modifier|*
name|buf
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
comment|/* Work around a bug in Tru64 5.1.  Attempting to read more than      INT_MAX bytes fails with errno == EINVAL.  See<http://lists.gnu.org/archive/html/bug-gnu-utils/2002-04/msg00010.html>.      When decreasing COUNT, keep it block-aligned.  */
enum|enum
block|{
name|BUGGY_READ_MAXIMUM
init|=
name|INT_MAX
operator|&
operator|~
literal|8191
block|}
enum|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|ssize_t
name|result
init|=
name|rw
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|count
argument_list|)
decl_stmt|;
if|if
condition|(
literal|0
operator|<=
name|result
condition|)
return|return
name|result
return|;
elseif|else
if|if
condition|(
name|IS_EINTR
argument_list|(
name|errno
argument_list|)
condition|)
continue|continue;
elseif|else
if|if
condition|(
name|errno
operator|==
name|EINVAL
operator|&&
name|BUGGY_READ_MAXIMUM
operator|<
name|count
condition|)
name|count
operator|=
name|BUGGY_READ_MAXIMUM
expr_stmt|;
else|else
return|return
name|result
return|;
block|}
block|}
end_function

end_unit

