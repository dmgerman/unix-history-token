begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -O3 -S -o - -emit-llvm %s | grep {align 1} | count 2
end_comment

begin_comment
comment|// RUN: %llvmgcc -O3 -S -o - -emit-llvm %s | llc
end_comment

begin_struct
struct|struct
name|p
block|{
name|char
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_decl_stmt
name|struct
name|p
name|t
init|=
block|{
literal|1
block|,
literal|10
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|p
name|u
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|tmp
init|=
name|t
operator|.
name|b
decl_stmt|;
name|u
operator|.
name|b
operator|=
name|tmp
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function

end_unit

