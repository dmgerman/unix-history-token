begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rename.c -- BSD compatible directory function for System V    Copyright (C) 1988, 1990 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.  */
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
comment|/* Rename file FROM to file TO.    Return 0 if successful, -1 if not. */
end_comment

begin_function
name|int
name|rename
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
name|char
modifier|*
name|from
decl_stmt|;
name|char
modifier|*
name|to
decl_stmt|;
block|{
name|struct
name|stat
name|from_stats
decl_stmt|;
name|int
name|pid
decl_stmt|,
name|status
decl_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|from
argument_list|,
operator|&
name|from_stats
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* We don't check existence_error because the systems which need it 	 have rename().  */
if|if
condition|(
name|unlink
argument_list|(
name|to
argument_list|)
operator|&&
name|errno
operator|!=
name|ENOENT
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
operator|(
name|from_stats
operator|.
name|st_mode
operator|&
name|S_IFMT
operator|)
operator|==
name|S_IFDIR
condition|)
block|{
ifdef|#
directive|ifdef
name|MVDIR
comment|/* I don't think MVDIR ever gets defined, but I don't think 	     it matters, because I don't think CVS ever calls rename() 	     on directories.  */
comment|/* Need a setuid root process to link and unlink directories. */
name|pid
operator|=
name|fork
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|pid
condition|)
block|{
case|case
operator|-
literal|1
case|:
comment|/* Error. */
name|error
argument_list|(
literal|1
argument_list|,
name|errno
argument_list|,
literal|"cannot fork"
argument_list|)
expr_stmt|;
case|case
literal|0
case|:
comment|/* Child. */
name|execl
argument_list|(
name|MVDIR
argument_list|,
literal|"mvdir"
argument_list|,
name|from
argument_list|,
name|to
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|error
argument_list|(
literal|255
argument_list|,
name|errno
argument_list|,
literal|"cannot run `%s'"
argument_list|,
name|MVDIR
argument_list|)
expr_stmt|;
default|default:
comment|/* Parent. */
while|while
condition|(
name|wait
argument_list|(
operator|&
name|status
argument_list|)
operator|!=
name|pid
condition|)
comment|/* Do nothing. */
empty_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
comment|/* mvdir printed the system error message. */
return|return
name|status
operator|!=
literal|0
condition|?
operator|-
literal|1
else|:
literal|0
return|;
block|}
else|#
directive|else
comment|/* no MVDIR */
name|error
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|"internal error: cannot move directories"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* no MVDIR */
block|}
else|else
block|{
comment|/* We don't check existence_error because the systems which need it 	     have rename().  */
if|if
condition|(
name|link
argument_list|(
name|from
argument_list|,
name|to
argument_list|)
operator|==
literal|0
operator|&&
operator|(
name|unlink
argument_list|(
name|from
argument_list|)
operator|==
literal|0
operator|||
name|errno
operator|==
name|ENOENT
operator|)
condition|)
return|return
literal|0
return|;
block|}
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function

end_unit

