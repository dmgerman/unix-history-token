begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|/* Make sure the frontend is correctly marking static stuff as internal! */
end_comment

begin_decl_stmt
name|int
name|X
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|Y
init|=
literal|12
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|foo
parameter_list|(
name|int
name|Z
parameter_list|)
block|{
name|Y
operator|=
name|Z
expr_stmt|;
block|}
end_function

begin_function
name|void
modifier|*
name|test
parameter_list|()
block|{
name|foo
argument_list|(
literal|12
argument_list|)
expr_stmt|;
return|return
operator|&
name|Y
return|;
block|}
end_function

end_unit

