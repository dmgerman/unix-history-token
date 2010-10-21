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
comment|// CONFIG error: incompatible block pointer types assigning
end_comment

begin_empty
empty|#import<stdio.h>
end_empty

begin_empty
empty|#import<stdlib.h>
end_empty

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
ifndef|#
directive|ifndef
name|__cplusplus
name|char
function_decl|(
modifier|^
name|rot13
function_decl|)
parameter_list|()
function_decl|;
name|rot13
operator|=
lambda|^
parameter_list|(
name|char
name|c
parameter_list|)
block|{
return|return
call|(
name|char
call|)
argument_list|(
operator|(
operator|(
name|c
operator|-
literal|'a'
operator|+
literal|13
operator|)
operator|%
literal|26
operator|)
operator|+
literal|'a'
argument_list|)
return|;
block|}
expr_stmt|;
name|char
name|n
init|=
name|rot13
argument_list|(
literal|'a'
argument_list|)
decl_stmt|;
name|char
name|c
init|=
name|rot13
argument_list|(
literal|'p'
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
operator|!=
literal|'n'
operator|||
name|c
operator|!=
literal|'c'
condition|)
block|{
name|printf
argument_list|(
literal|"%s: rot13('a') returned %c, rot13('p') returns %c\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|n
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
comment|// yield characteristic error message for C++
error|#
directive|error
error|incompatible block pointer types assigning
endif|#
directive|endif
ifndef|#
directive|ifndef
name|__clang__
comment|// yield characteristic error message for C++
error|#
directive|error
error|incompatible block pointer types assigning
endif|#
directive|endif
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
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

