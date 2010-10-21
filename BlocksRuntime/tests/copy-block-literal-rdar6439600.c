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
comment|// CONFIG open rdar://6439600
end_comment

begin_empty
empty|#import<stdio.h>
end_empty

begin_empty
empty|#import<stdlib.h>
end_empty

begin_define
define|#
directive|define
name|NUMBER_OF_BLOCKS
value|100
end_define

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
name|x
index|[
name|NUMBER_OF_BLOCKS
index|]
function_decl|)
parameter_list|()
function_decl|;
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
name|NUMBER_OF_BLOCKS
condition|;
name|i
operator|++
control|)
name|x
index|[
name|i
index|]
operator|=
lambda|^
block|{
return|return
name|i
return|;
block|}
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NUMBER_OF_BLOCKS
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|x
index|[
name|i
index|]
operator|(
operator|)
operator|!=
name|i
condition|)
block|{
name|printf
argument_list|(
literal|"%s: failure, %d != %d\n"
argument_list|,
argument|argv[
literal|0
argument|]
argument_list|,
argument|x[i]()
argument_list|,
argument|i
argument_list|)
empty_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
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

