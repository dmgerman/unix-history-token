begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mkrmdir.c -- BSD compatible directory functions for System V    Copyright (C) 1988, 1990 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.  */
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
name|STDC_HEADERS
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
comment|/* mkdir and rmdir adapted from GNU tar. */
end_comment

begin_comment
comment|/* Make directory DPATH, with permission mode DMODE.     Written by Robert Rother, Mariah Corporation, August 1985    (sdcsvax!rmr or rmr@uscd).  If you want it, it's yours.     Severely hacked over by John Gilmore to make a 4.2BSD compatible    subroutine.	11Mar86; hoptoad!gnu     Modified by rmtodd@uokmax 6-28-87 -- when making an already existing dir,    subroutine didn't return EEXIST.  It does now. */
end_comment

begin_function
name|int
name|mkdir
parameter_list|(
name|dpath
parameter_list|,
name|dmode
parameter_list|)
name|char
modifier|*
name|dpath
decl_stmt|;
name|int
name|dmode
decl_stmt|;
block|{
name|int
name|cpid
decl_stmt|,
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
operator|==
literal|0
condition|)
block|{
name|errno
operator|=
name|EEXIST
expr_stmt|;
comment|/* stat worked, so it already exists. */
return|return
operator|-
literal|1
return|;
block|}
comment|/* If stat fails for a reason other than non-existence, return error. */
if|if
condition|(
operator|!
name|existence_error
argument_list|(
name|errno
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
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
comment|/* Cannot fork. */
return|return
operator|-
literal|1
return|;
comment|/* errno is set already. */
case|case
literal|0
case|:
comment|/* Child process. */
comment|/* Cheap hack to set mode of new directory.  Since this child 	 process is going away anyway, we zap its umask. 	 This won't suffice to set SUID, SGID, etc. on this 	 directory, so the parent process calls chmod afterward. */
name|status
operator|=
name|umask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Get current umask. */
name|umask
argument_list|(
name|status
operator||
operator|(
literal|0777
operator|&
operator|~
name|dmode
operator|)
argument_list|)
expr_stmt|;
comment|/* Set for mkdir. */
name|execl
argument_list|(
literal|"/bin/mkdir"
argument_list|,
literal|"mkdir"
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
comment|/* Parent process. */
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
comment|/* Wait for kid to finish. */
comment|/* Do nothing. */
empty_stmt|;
if|if
condition|(
name|status
operator|&
literal|0xFFFF
condition|)
block|{
name|errno
operator|=
name|EIO
expr_stmt|;
comment|/* /bin/mkdir failed. */
return|return
operator|-
literal|1
return|;
block|}
return|return
name|chmod
argument_list|(
name|dpath
argument_list|,
name|dmode
argument_list|)
return|;
block|}
block|}
end_function

begin_comment
comment|/* Remove directory DPATH.    Return 0 if successful, -1 if not. */
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
name|int
name|cpid
decl_stmt|,
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
comment|/* stat set errno. */
if|if
condition|(
operator|(
name|statbuf
operator|.
name|st_mode
operator|&
name|S_IFMT
operator|)
operator|!=
name|S_IFDIR
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
comment|/* Cannot fork. */
return|return
operator|-
literal|1
return|;
comment|/* errno is set already. */
case|case
literal|0
case|:
comment|/* Child process. */
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
comment|/* Parent process. */
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
comment|/* Wait for kid to finish. */
comment|/* Do nothing. */
empty_stmt|;
if|if
condition|(
name|status
operator|&
literal|0xFFFF
condition|)
block|{
name|errno
operator|=
name|EIO
expr_stmt|;
comment|/* /bin/rmdir failed. */
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

