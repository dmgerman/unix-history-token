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
comment|// CONFIG rdar://6396238
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|count
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_macro
name|void
argument_list|(
argument|^mkblock(void)
argument_list|)
end_macro

begin_expr_stmt
operator|(
name|void
operator|)
block|{
name|count
operator|++
block|;
return|return
lambda|^
block|{
name|count
operator|++
expr_stmt|;
block|}
expr_stmt|;
end_expr_stmt

begin_function
unit|}  int
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
name|mkblock
argument_list|()
argument_list|()
expr_stmt|;
if|if
condition|(
name|count
operator|!=
literal|2
condition|)
block|{
name|printf
argument_list|(
literal|"%s: failure, 2 != %d\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
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
return|return
literal|0
return|;
block|}
end_function

end_unit

