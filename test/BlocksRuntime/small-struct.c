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
comment|// CONFIG
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

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
name|MiniStruct
typedef|;
end_typedef

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
name|MiniStruct
name|inny
decl_stmt|;
name|MiniStruct
name|outty
decl_stmt|;
name|MiniStruct
function_decl|(
modifier|^
name|copyStruct
function_decl|)
parameter_list|(
name|MiniStruct
parameter_list|)
function_decl|;
name|memset
argument_list|(
operator|&
name|inny
argument_list|,
literal|0xA5
argument_list|,
sizeof|sizeof
argument_list|(
name|inny
argument_list|)
argument_list|)
expr_stmt|;
name|memset
argument_list|(
operator|&
name|outty
argument_list|,
literal|0x2A
argument_list|,
sizeof|sizeof
argument_list|(
name|outty
argument_list|)
argument_list|)
expr_stmt|;
name|inny
operator|.
name|a
operator|=
literal|12
expr_stmt|;
name|inny
operator|.
name|b
operator|=
literal|42
expr_stmt|;
name|copyStruct
operator|=
lambda|^
parameter_list|(
name|MiniStruct
name|aTinyStruct
parameter_list|)
block|{
return|return
name|aTinyStruct
return|;
block|}
expr_stmt|;
comment|// pass-by-value intrinsically copies the argument
name|outty
operator|=
name|copyStruct
argument_list|(
name|inny
argument_list|)
expr_stmt|;
if|if
condition|(
operator|&
name|inny
operator|==
operator|&
name|outty
condition|)
block|{
name|printf
argument_list|(
literal|"%s: struct wasn't copied."
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|inny
operator|.
name|a
operator|!=
name|outty
operator|.
name|a
operator|)
operator|||
operator|(
name|inny
operator|.
name|b
operator|!=
name|outty
operator|.
name|b
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"%s: struct contents did not match."
argument_list|,
name|argv
index|[
literal|0
index|]
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

