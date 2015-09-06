begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: lto
end_comment

begin_comment
comment|// RUN: %clang_lto_safestack %s -o %t
end_comment

begin_comment
comment|// RUN: %run %t
end_comment

begin_comment
comment|// Test that safe stack works with LTO.
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|char
name|c
index|[]
init|=
literal|"hello world"
decl_stmt|;
name|puts
argument_list|(
name|c
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

