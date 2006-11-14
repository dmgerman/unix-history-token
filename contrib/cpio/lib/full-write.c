begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* An interface to read and write that retries (if necessary) until complete.     Copyright (C) 1993, 1994, 1997, 1998, 1999, 2000, 2001, 2002, 2003,    2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|FULL_READ
end_ifdef

begin_include
include|#
directive|include
file|"full-read.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"full-write.h"
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
name|FULL_READ
end_ifdef

begin_include
include|#
directive|include
file|"safe-read.h"
end_include

begin_define
define|#
directive|define
name|safe_rw
value|safe_read
end_define

begin_define
define|#
directive|define
name|full_rw
value|full_read
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

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"safe-write.h"
end_include

begin_define
define|#
directive|define
name|safe_rw
value|safe_write
end_define

begin_define
define|#
directive|define
name|full_rw
value|full_write
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FULL_READ
end_ifdef

begin_comment
comment|/* Set errno to zero upon EOF.  */
end_comment

begin_define
define|#
directive|define
name|ZERO_BYTE_TRANSFER_ERRNO
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Some buggy drivers return 0 when one tries to write beyond    a device's end.  (Example: Linux 1.2.13 on /dev/fd0.)    Set errno to ENOSPC so they get a sensible diagnostic.  */
end_comment

begin_define
define|#
directive|define
name|ZERO_BYTE_TRANSFER_ERRNO
value|ENOSPC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Write(read) COUNT bytes at BUF to(from) descriptor FD, retrying if    interrupted or if a partial write(read) occurs.  Return the number    of bytes transferred.    When writing, set errno if fewer than COUNT bytes are written.    When reading, if fewer than COUNT bytes are read, you must examine    errno to distinguish failure from EOF (errno == 0).  */
end_comment

begin_function
name|size_t
name|full_rw
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
name|size_t
name|total
init|=
literal|0
decl_stmt|;
specifier|const
name|char
modifier|*
name|ptr
init|=
name|buf
decl_stmt|;
while|while
condition|(
name|count
operator|>
literal|0
condition|)
block|{
name|size_t
name|n_rw
init|=
name|safe_rw
argument_list|(
name|fd
argument_list|,
name|ptr
argument_list|,
name|count
argument_list|)
decl_stmt|;
if|if
condition|(
name|n_rw
operator|==
operator|(
name|size_t
operator|)
operator|-
literal|1
condition|)
break|break;
if|if
condition|(
name|n_rw
operator|==
literal|0
condition|)
block|{
name|errno
operator|=
name|ZERO_BYTE_TRANSFER_ERRNO
expr_stmt|;
break|break;
block|}
name|total
operator|+=
name|n_rw
expr_stmt|;
name|ptr
operator|+=
name|n_rw
expr_stmt|;
name|count
operator|-=
name|n_rw
expr_stmt|;
block|}
return|return
name|total
return|;
block|}
end_function

end_unit

