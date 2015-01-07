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

begin_include
include|#
directive|include
file|<Block.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|// CONFIG rdar://6225809
end_comment

begin_comment
comment|// fixed in 5623
end_comment

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
specifier|__block
name|int
name|a
init|=
literal|42
decl_stmt|;
name|int
modifier|*
name|ap
init|=
operator|&
name|a
decl_stmt|;
comment|// just to keep the address on the stack.
name|void
function_decl|(
modifier|^
name|b
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
comment|//a;              // workaround, a should be implicitly imported
name|Block_copy
argument_list|(
lambda|^
block|{
name|a
operator|=
literal|2
function_decl|;
block|}
end_function

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_expr_stmt
unit|};
name|Block_copy
argument_list|(
name|b
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|&
name|a
operator|==
name|ap
condition|)
block|{
name|printf
argument_list|(
literal|"**** __block heap storage should have been created at this point\n"
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

