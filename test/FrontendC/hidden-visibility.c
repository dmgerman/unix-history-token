begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -o - | grep {hidden unnamed_addr global}
end_comment

begin_decl_stmt
name|int
name|X
name|__attribute__
argument_list|(
operator|(
name|__visibility__
argument_list|(
literal|"hidden"
argument_list|)
operator|)
argument_list|)
init|=
literal|123
decl_stmt|;
end_decl_stmt

end_unit

