begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux-gnu -emit-llvm -o - %s | grep thread_local | count 4
end_comment

begin_decl_stmt
name|__thread
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|__thread
name|int
name|b
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|c
parameter_list|()
block|{
return|return
operator|&
name|b
return|;
block|}
end_function

begin_function
name|int
name|d
parameter_list|()
block|{
name|__thread
specifier|static
name|int
name|e
decl_stmt|;
name|__thread
specifier|static
expr|union
block|{
name|float
name|a
block|;
name|int
name|b
block|;}
name|f
operator|=
block|{
operator|.
name|b
operator|=
literal|1
block|}
expr_stmt|;
block|}
end_function

end_unit

