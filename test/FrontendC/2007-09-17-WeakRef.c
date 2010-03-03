begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -O1 -S %s -o - | grep icmp
end_comment

begin_comment
comment|// PR1678
end_comment

begin_function_decl
specifier|extern
name|void
name|B
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|__typeof
argument_list|(
argument|B
argument_list|)
name|A
name|__attribute__
argument_list|(
operator|(
name|__weakref__
argument_list|(
literal|"B"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|active
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|void
modifier|*
specifier|const
name|p
init|=
name|__extension__
argument_list|(
name|void
operator|*
argument_list|)
operator|&
name|A
decl_stmt|;
return|return
name|p
operator|!=
literal|0
return|;
block|}
end_function

end_unit

