begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1< %s -emit-llvm -triple i686-pc-linux-gnu> %t
end_comment

begin_comment
comment|// RUN: grep "div i32" %t
end_comment

begin_comment
comment|// RUN: grep "shl i32" %t
end_comment

begin_decl_stmt
name|unsigned
name|char
name|a
decl_stmt|,
name|b
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|c
parameter_list|(
name|void
parameter_list|)
block|{
name|a
operator|<<=
name|b
expr_stmt|;
block|}
end_function

begin_function
name|void
name|d
parameter_list|(
name|void
parameter_list|)
block|{
name|a
operator|/=
name|b
expr_stmt|;
block|}
end_function

end_unit

