begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_comment
comment|// PR2797
end_comment

begin_function
name|unsigned
name|int
name|func_48
parameter_list|(
name|signed
name|char
name|p_49
parameter_list|)
block|{
name|signed
name|char
name|l_340
decl_stmt|;
name|func_44
argument_list|(
literal|1
operator|&
operator|(
operator|(
literal|1
operator|^
literal|1
operator|==
operator|(
name|lshift_u_s
argument_list|(
literal|1
argument_list|)
operator|)
operator|!=
operator|(
name|l_340
operator|<
literal|1
operator|)
operator|)
operator|&
literal|1L
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

