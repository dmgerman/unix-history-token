begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* clib.c: Functions which we normally expect to find in the C library.    $Id: clib.c,v 1.2 1996/10/03 16:58:31 karl Exp $     This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1995 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_UNISTD_H
argument_list|)
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STDLIB_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STRING_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|xmalloc
argument_list|()
decl_stmt|,
modifier|*
name|xrealloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"general.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|errno
argument_list|)
end_if

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
operator|!
name|defined
argument_list|(
name|HAVE_STRERROR
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|strerror
parameter_list|(
name|num
parameter_list|)
name|int
name|num
decl_stmt|;
block|{
if|if
condition|(
name|num
operator|>=
name|sys_nerr
condition|)
return|return
operator|(
literal|""
operator|)
return|;
else|else
return|return
operator|(
name|sys_errlist
index|[
name|num
index|]
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_STRERROR */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_STRCASECMP
argument_list|)
end_if

begin_comment
comment|/* This Unix doesn't have the strcasecmp () function. */
end_comment

begin_function
name|int
name|strcasecmp
parameter_list|(
name|string1
parameter_list|,
name|string2
parameter_list|)
name|char
modifier|*
name|string1
decl_stmt|,
decl|*
name|string2
decl_stmt|;
end_function

begin_block
block|{
name|char
name|ch1
decl_stmt|,
name|ch2
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|ch1
operator|=
operator|*
name|string1
operator|++
expr_stmt|;
name|ch2
operator|=
operator|*
name|string2
operator|++
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|ch1
operator||
name|ch2
operator|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|ch1
operator|=
name|info_toupper
argument_list|(
name|ch1
argument_list|)
expr_stmt|;
name|ch2
operator|=
name|info_toupper
argument_list|(
name|ch2
argument_list|)
expr_stmt|;
if|if
condition|(
name|ch1
operator|!=
name|ch2
condition|)
return|return
operator|(
name|ch1
operator|-
name|ch2
operator|)
return|;
block|}
block|}
end_block

begin_comment
comment|/* Compare at most COUNT characters from string1 to string2.  Case    doesn't matter. */
end_comment

begin_function
name|int
name|strncasecmp
parameter_list|(
name|string1
parameter_list|,
name|string2
parameter_list|,
name|count
parameter_list|)
name|char
modifier|*
name|string1
decl_stmt|,
decl|*
name|string2
decl_stmt|;
end_function

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
name|ch1
decl_stmt|,
name|ch2
decl_stmt|;
while|while
condition|(
name|count
condition|)
block|{
name|ch1
operator|=
operator|*
name|string1
operator|++
expr_stmt|;
name|ch2
operator|=
operator|*
name|string2
operator|++
expr_stmt|;
name|ch1
operator|=
name|info_toupper
argument_list|(
name|ch1
argument_list|)
expr_stmt|;
name|ch2
operator|=
name|info_toupper
argument_list|(
name|ch2
argument_list|)
expr_stmt|;
if|if
condition|(
name|ch1
operator|==
name|ch2
condition|)
name|count
operator|--
expr_stmt|;
else|else
break|break;
block|}
return|return
operator|(
name|count
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !STRCASECMP */
end_comment

end_unit

