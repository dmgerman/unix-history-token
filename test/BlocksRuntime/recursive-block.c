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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<Block.h>
end_include

begin_include
include|#
directive|include
file|<Block_private.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|// CONFIG
end_comment

begin_decl_stmt
name|int
name|cumulation
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|doSomething
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|cumulation
operator|+=
name|i
expr_stmt|;
return|return
name|cumulation
return|;
block|}
end_function

begin_function
name|void
name|dirtyStack
parameter_list|()
block|{
name|int
name|i
init|=
name|random
argument_list|()
decl_stmt|;
name|int
name|j
init|=
name|doSomething
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|int
name|k
init|=
name|doSomething
argument_list|(
name|j
argument_list|)
decl_stmt|;
name|doSomething
argument_list|(
name|i
operator|+
name|j
operator|+
name|k
argument_list|)
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|^
name|voidVoid
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function
name|voidVoid
name|testFunction
parameter_list|()
block|{
name|int
name|i
init|=
name|random
argument_list|()
decl_stmt|;
specifier|__block
name|voidVoid
name|inner
init|=
lambda|^
block|{
name|doSomething
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
decl_stmt|;
comment|//printf("inner, on stack, is %p\n", (void*)inner);
comment|/*__block*/
name|voidVoid
name|outer
init|=
lambda|^
block|{
comment|//printf("will call inner block %p\n", (void *)inner);
name|inner
argument_list|()
expr_stmt|;
block|}
decl_stmt|;
comment|//printf("outer looks like: %s\n", _Block_dump(outer));
name|voidVoid
name|result
init|=
name|Block_copy
argument_list|(
name|outer
argument_list|)
decl_stmt|;
comment|//Block_release(inner);
return|return
name|result
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|voidVoid
name|block
init|=
name|testFunction
argument_list|()
decl_stmt|;
name|dirtyStack
argument_list|()
expr_stmt|;
name|block
argument_list|()
expr_stmt|;
name|Block_release
argument_list|(
name|block
argument_list|)
expr_stmt|;
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

