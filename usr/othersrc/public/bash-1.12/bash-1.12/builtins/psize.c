begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* psize.c - Find pipe size. */
end_comment

begin_comment
comment|/* Copyright (C) 1987, 1991 Free Software Foundation, Inc.     This file is part of GNU Bash, the Bourne Again SHell.     Bash is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.     Bash is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with Bash; see the file COPYING.  If not, write to the Free    Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_comment
comment|/*  Write output in 128-byte chunks until we get a sigpipe or write gets an     EPIPE.  Then report how many bytes we wrote.  We assume that this is the     pipe size. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"../general.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nw
decl_stmt|;
end_decl_stmt

begin_function
name|sighandler
name|sigpipe
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%d\n"
argument_list|,
name|nw
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NeXT
argument_list|)
end_if

begin_function
name|char
modifier|*
name|memset
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
specifier|register
name|int
name|c
decl_stmt|,
name|n
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|p
init|=
name|s
decl_stmt|;
while|while
condition|(
operator|--
name|n
operator|>=
literal|0
condition|)
operator|*
name|s
operator|++
operator|=
name|c
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NeXT */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|char
name|buf
index|[
literal|128
index|]
decl_stmt|;
name|memset
argument_list|(
name|buf
argument_list|,
literal|' '
argument_list|,
literal|128
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGPIPE
argument_list|,
name|sigpipe
argument_list|)
expr_stmt|;
name|nw
operator|=
literal|0
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|int
name|n
decl_stmt|;
name|n
operator|=
name|write
argument_list|(
literal|1
argument_list|,
name|buf
argument_list|,
literal|128
argument_list|)
expr_stmt|;
name|nw
operator|+=
name|n
expr_stmt|;
block|}
block|}
end_function

end_unit

