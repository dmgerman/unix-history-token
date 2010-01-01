begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
struct|struct
name|foo
block|{
name|unsigned
name|a
range|:
literal|16
decl_stmt|;
name|unsigned
name|b
range|:
literal|32
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
block|}
name|x
struct|;
name|x
operator|.
name|b
operator|=
literal|0x56789abcL
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

