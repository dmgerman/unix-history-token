begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BSD compatible remove directory function for System V    Copyright (C) 1988, 1990 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_if
if|#
directive|if
name|STAT_MACROS_BROKEN
end_if

begin_undef
undef|#
directive|undef
name|S_ISDIR
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
name|S_ISDIR
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* rmdir adapted from GNU tar.  */
end_comment

begin_comment
comment|/* Remove directory DPATH.    Return 0 if successful, -1 if not.  */
end_comment

begin_function
name|int
name|rmdir
parameter_list|(
name|dpath
parameter_list|)
name|char
modifier|*
name|dpath
decl_stmt|;
block|{
name|pid_t
name|cpid
decl_stmt|;
name|int
name|status
decl_stmt|;
name|struct
name|stat
name|statbuf
decl_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|dpath
argument_list|,
operator|&
name|statbuf
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|-
literal|1
return|;
comment|/* errno already set */
if|if
condition|(
operator|!
name|S_ISDIR
argument_list|(
name|statbuf
operator|.
name|st_mode
argument_list|)
condition|)
block|{
name|errno
operator|=
name|ENOTDIR
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
name|cpid
operator|=
name|fork
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|cpid
condition|)
block|{
case|case
operator|-
literal|1
case|:
comment|/* cannot fork */
return|return
operator|-
literal|1
return|;
comment|/* errno already set */
case|case
literal|0
case|:
comment|/* child process */
name|execl
argument_list|(
literal|"/bin/rmdir"
argument_list|,
literal|"rmdir"
argument_list|,
name|dpath
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
default|default:
comment|/* parent process */
comment|/* Wait for kid to finish.  */
while|while
condition|(
name|wait
argument_list|(
operator|&
name|status
argument_list|)
operator|!=
name|cpid
condition|)
comment|/* Do nothing.  */
empty_stmt|;
if|if
condition|(
name|status
condition|)
block|{
comment|/* /bin/rmdir failed.  */
name|errno
operator|=
name|EIO
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
block|}
end_function

end_unit

