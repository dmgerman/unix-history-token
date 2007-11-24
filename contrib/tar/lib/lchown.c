begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Provide a stub lchown function for systems that lack it.    Copyright (C) 1998, 1999 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* written by Jim Meyering */
end_comment

begin_include
include|#
directive|include
file|<config.h>
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
file|"lchown.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|STAT_MACROS_BROKEN
end_ifdef

begin_undef
undef|#
directive|undef
name|S_ISLNK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISLNK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFLNK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFLNK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Declare chown to avoid a warning.  Don't include unistd.h,    because it may have a conflicting prototype for lchown.  */
end_comment

begin_function_decl
name|int
name|chown
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Work just like chown, except when FILE is a symbolic link.    In that case, set errno to ENOSYS and return -1.  */
end_comment

begin_function
name|int
name|lchown
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|uid_t
name|uid
parameter_list|,
name|gid_t
name|gid
parameter_list|)
block|{
name|struct
name|stat
name|stats
decl_stmt|;
if|if
condition|(
name|lstat
argument_list|(
name|file
argument_list|,
operator|&
name|stats
argument_list|)
operator|==
literal|0
operator|&&
name|S_ISLNK
argument_list|(
name|stats
operator|.
name|st_mode
argument_list|)
condition|)
block|{
name|errno
operator|=
name|ENOSYS
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
return|return
name|chown
argument_list|(
name|file
argument_list|,
name|uid
argument_list|,
name|gid
argument_list|)
return|;
block|}
end_function

end_unit

