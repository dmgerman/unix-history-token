begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Compare two open file descriptors to see if they refer to the same file.    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/*  @deftypefn Extension int fdmatch (int @var{fd1}, int @var{fd2})  Check to see if two open file descriptors refer to the same file. This is useful, for example, when we have an open file descriptor for an unnamed file, and the name of a file that we believe to correspond to that fd.  This can happen when we are exec'd with an already open file (@code{stdout} for example) or from the SVR4 @file{/proc} calls that return open file descriptors for mapped address spaces.  All we have to do is open the file by name and check the two file descriptors for a match, which is done by comparing major and minor device numbers and inode numbers.  @end deftypefn  BUGS  	(FIXME: does this work for networks?) 	It works for NFS, which assigns a device number to each mount.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_function
name|int
name|fdmatch
parameter_list|(
name|int
name|fd1
parameter_list|,
name|int
name|fd2
parameter_list|)
block|{
name|struct
name|stat
name|sbuf1
decl_stmt|;
name|struct
name|stat
name|sbuf2
decl_stmt|;
if|if
condition|(
operator|(
name|fstat
argument_list|(
name|fd1
argument_list|,
operator|&
name|sbuf1
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
name|fstat
argument_list|(
name|fd2
argument_list|,
operator|&
name|sbuf2
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
name|sbuf1
operator|.
name|st_dev
operator|==
name|sbuf2
operator|.
name|st_dev
operator|)
operator|&&
operator|(
name|sbuf1
operator|.
name|st_ino
operator|==
name|sbuf2
operator|.
name|st_ino
operator|)
condition|)
block|{
return|return
operator|(
literal|1
operator|)
return|;
block|}
else|else
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
end_function

end_unit

