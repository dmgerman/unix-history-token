begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MMAP
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_comment
comment|/* The Net-2 man pages says that a MAP_FILE flag is required. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAP_FILE
end_ifndef

begin_define
define|#
directive|define
name|MAP_FILE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|mapread
parameter_list|(
name|fd
parameter_list|,
name|nbytes
parameter_list|)
name|int
name|fd
decl_stmt|;
name|int
name|nbytes
decl_stmt|;
block|{
name|char
modifier|*
name|p
init|=
operator|(
name|char
operator|*
operator|)
name|mmap
argument_list|(
operator|(
name|caddr_t
operator|)
literal|0
argument_list|,
operator|(
name|size_t
operator|)
name|nbytes
argument_list|,
name|PROT_READ
argument_list|,
name|MAP_FILE
operator||
name|MAP_PRIVATE
argument_list|,
name|fd
argument_list|,
operator|(
name|off_t
operator|)
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|p
operator|==
operator|(
name|char
operator|*
operator|)
operator|-
literal|1
condition|)
return|return
literal|0
return|;
comment|/* mmap() shouldn't return 0 since MAP_FIXED wasn't specified. */
if|if
condition|(
name|p
operator|==
literal|0
condition|)
name|abort
argument_list|()
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

begin_function
name|int
name|unmap
parameter_list|(
name|p
parameter_list|,
name|len
parameter_list|)
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
return|return
name|munmap
argument_list|(
operator|(
name|caddr_t
operator|)
name|p
argument_list|,
name|len
argument_list|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_MMAP */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_function
name|char
modifier|*
name|mapread
parameter_list|(
name|fd
parameter_list|,
name|nbytes
parameter_list|)
name|int
name|fd
decl_stmt|;
name|int
name|nbytes
decl_stmt|;
block|{
name|errno
operator|=
name|ENODEV
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|unmap
parameter_list|(
name|p
parameter_list|,
name|len
parameter_list|)
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_MMAP */
end_comment

end_unit

