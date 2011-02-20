begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -O2 -o %t.s
end_comment

begin_comment
comment|// RUN: grep {call i32 .*printf.*argc} %t.s | count 3
end_comment

begin_comment
comment|// RUN: not grep __block_holder_tmp %t.s
end_comment

begin_comment
comment|// rdar://5865221
end_comment

begin_comment
comment|// All of these should be inlined equivalently into a single printf call.
end_comment

begin_function
specifier|static
name|int
name|fun
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
operator|+
literal|1
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|block
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
operator|(
lambda|^
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
operator|+
literal|1
return|;
block|}
operator|)
operator|(
name|x
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|print
parameter_list|(
name|int
name|result
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
end_function

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
name|x
init|=
name|argc
operator|-
literal|1
decl_stmt|;
name|print
argument_list|(
name|fun
argument_list|(
name|x
argument_list|)
argument_list|)
expr_stmt|;
name|print
argument_list|(
name|block
argument_list|(
name|x
argument_list|)
argument_list|)
expr_stmt|;
name|int
function_decl|(
modifier|^
name|block_inline
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
lambda|^
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
operator|+
literal|1
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|print
argument_list|(
name|block_inline
argument_list|(
name|x
argument_list|)
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

