begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* The answer to this question is 24. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/* Copyright (C) 1987,1989 Free Software Foundation, Inc.  This file is part of GNU Bash, the Bourne Again SHell.  Bash is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  Bash is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with Bash; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
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
specifier|extern
name|char
modifier|*
name|sys_siglist
index|[]
decl_stmt|;
name|int
name|longest
decl_stmt|,
name|length
init|=
literal|0
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NSIG
condition|;
name|i
operator|++
control|)
block|{
name|printf
argument_list|(
literal|"%2d) %s\n"
argument_list|,
name|i
argument_list|,
name|sys_siglist
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|strlen
argument_list|(
name|sys_siglist
index|[
name|i
index|]
argument_list|)
operator|>
name|length
condition|)
block|{
name|longest
operator|=
name|i
expr_stmt|;
name|length
operator|=
name|strlen
argument_list|(
name|sys_siglist
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
name|printf
argument_list|(
literal|"The longest name is %d:\"%s\", which is %d chars in length.\n"
argument_list|,
name|longest
argument_list|,
name|sys_siglist
index|[
name|longest
index|]
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  * Local variables:  * compile-command: "cc -o longest_sig longest_sig.c"  * end:  */
end_comment

end_unit

