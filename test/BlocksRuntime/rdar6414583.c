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
comment|// CONFIG rdar://6414583
end_comment

begin_comment
comment|// a smaller case of byrefcopyint
end_comment

begin_include
include|#
directive|include
file|<Block.h>
end_include

begin_include
include|#
directive|include
file|<dispatch/dispatch.h>
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
specifier|__block
name|int
name|c
init|=
literal|1
decl_stmt|;
comment|//printf("&c = %p - c = %i\n",&c, c);
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
literal|2
condition|;
name|i
operator|++
control|)
block|{
name|dispatch_block_t
name|block
init|=
name|Block_copy
argument_list|(
lambda|^
block|{
name|c
operator|=
name|i
expr_stmt|;
block|}
argument_list|)
decl_stmt|;
name|block
argument_list|()
expr_stmt|;
comment|//        printf("%i:&c = %p - c = %i\n", i,&c, c);
name|Block_release
argument_list|(
name|block
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

