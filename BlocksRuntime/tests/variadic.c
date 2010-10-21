begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|/*  *  variadic.c  *  testObjects  *  *  Created by Blaine Garst on 2/17/09.  *  */
end_comment

begin_comment
comment|// PURPOSE Test that variadic arguments compile and work for Blocks
end_comment

begin_comment
comment|// CONFIG
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|long
function_decl|(
modifier|^
name|addthem
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
init|=
lambda|^
name|long
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|argp
function_decl|;
specifier|const
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|i
decl_stmt|;
name|char
name|c
decl_stmt|;
name|double
name|d
decl_stmt|;
name|long
name|result
init|=
literal|0
decl_stmt|;
name|va_start
argument_list|(
name|argp
argument_list|,
name|format
argument_list|)
expr_stmt|;
comment|//printf("starting...\n");
for|for
control|(
name|p
operator|=
name|format
init|;
operator|*
name|p
condition|;
name|p
operator|++
control|)
switch|switch
condition|(
operator|*
name|p
condition|)
block|{
case|case
literal|'i'
case|:
name|i
operator|=
name|va_arg
argument_list|(
name|argp
argument_list|,
name|int
argument_list|)
expr_stmt|;
comment|//printf("i: %d\n", i);
name|result
operator|+=
name|i
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
name|d
operator|=
name|va_arg
argument_list|(
name|argp
argument_list|,
name|double
argument_list|)
expr_stmt|;
comment|//printf("d: %g\n", d);
name|result
operator|+=
operator|(
name|int
operator|)
name|d
expr_stmt|;
break|break;
case|case
literal|'c'
case|:
name|c
operator|=
name|va_arg
argument_list|(
name|argp
argument_list|,
name|int
argument_list|)
expr_stmt|;
comment|//printf("c: '%c'\n", c);
name|result
operator|+=
name|c
expr_stmt|;
break|break;
block|}
comment|//printf("...done\n\n");
return|return
name|result
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|long
name|testresult
init|=
name|addthem
argument_list|(
literal|"ii"
argument_list|,
literal|10
argument_list|,
literal|20
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|testresult
operator|!=
literal|30
condition|)
block|{
name|printf
argument_list|(
literal|"got wrong result: %ld\n"
argument_list|,
name|testresult
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_if

begin_expr_stmt
name|testresult
operator|=
name|addthem
argument_list|(
literal|"idc"
argument_list|,
literal|30
argument_list|,
literal|40.0
argument_list|,
literal|'a'
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|testresult
operator|!=
operator|(
literal|70
operator|+
literal|'a'
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"got different wrong result: %ld\n"
argument_list|,
name|testresult
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_if

begin_expr_stmt
name|printf
argument_list|(
literal|"%s: Success\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
literal|0
return|;
end_return

unit|}
end_unit

