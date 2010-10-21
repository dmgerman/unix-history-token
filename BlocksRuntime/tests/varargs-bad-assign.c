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
comment|//  -*- mode:C; c-basic-offset:4; tab-width:4; intent-tabs-mode:nil;  -*-
end_comment

begin_comment
comment|// HACK ALERT: gcc and g++ give different errors, referencing the line number to ensure that it checks for the right error; MUST KEEP IN SYNC WITH THE TEST
end_comment

begin_comment
comment|// CONFIG 27: error:
end_comment

begin_empty
empty|#import<stdio.h>
end_empty

begin_empty
empty|#import<stdlib.h>
end_empty

begin_empty
empty|#import<string.h>
end_empty

begin_empty
empty|#import<stdarg.h>
end_empty

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
function_decl|(
modifier|^
name|sumn
function_decl|)
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
name|int
name|six
init|=
literal|0
decl_stmt|;
name|sumn
operator|=
lambda|^
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
block|{
name|int
name|result
init|=
literal|0
decl_stmt|;
name|va_list
name|numbers
decl_stmt|;
name|int
name|i
decl_stmt|;
name|va_start
argument_list|(
name|numbers
argument_list|,
name|n
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
name|i
operator|++
control|)
block|{
name|result
operator|+=
name|va_arg
argument_list|(
name|numbers
argument_list|,
name|int
argument_list|)
expr_stmt|;
block|}
name|va_end
argument_list|(
name|numbers
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
expr_stmt|;
name|six
operator|=
name|sumn
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
if|if
condition|(
name|six
operator|!=
literal|6
condition|)
block|{
name|printf
argument_list|(
literal|"%s: Expected 6 but got %d\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|six
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"%s: success\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

