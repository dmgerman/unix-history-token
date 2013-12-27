begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* unlink-if-ordinary.c - remove link to a file unless it is special    Copyright (C) 2004, 2005 Free Software Foundation, Inc.  This file is part of the libiberty library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License. */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental int unlink_if_ordinary (const char*)  Unlinks the named file, unless it is special (e.g. a device file). Returns 0 when the file was unlinked, a negative value (and errno set) when there was an error deleting the file, and a positive value if no attempt was made to unlink the file because it is special.  @end deftypefn  */
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
file|<sys/types.h>
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
name|HAVE_SYS_STAT_H
end_if

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISLNK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFLNK
end_ifdef

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFLNK)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|lstat
value|stat
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|unlink_if_ordinary
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|struct
name|stat
name|st
decl_stmt|;
if|if
condition|(
name|lstat
argument_list|(
name|name
argument_list|,
operator|&
name|st
argument_list|)
operator|==
literal|0
operator|&&
operator|(
name|S_ISREG
argument_list|(
name|st
operator|.
name|st_mode
argument_list|)
operator|||
name|S_ISLNK
argument_list|(
name|st
operator|.
name|st_mode
argument_list|)
operator|)
condition|)
return|return
name|unlink
argument_list|(
name|name
argument_list|)
return|;
return|return
literal|1
return|;
block|}
end_function

end_unit

