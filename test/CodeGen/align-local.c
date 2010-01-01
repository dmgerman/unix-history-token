begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s | grep "align 16" | count 2
end_comment

begin_typedef
typedef|typedef
name|struct
name|__attribute
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
block|{
name|int
name|x
index|[
literal|4
index|]
block|;}
end_typedef

begin_expr_stmt
name|ff
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|a
parameter_list|()
block|{
name|ff
name|a
decl_stmt|;
struct|struct
block|{
name|int
name|x
index|[
literal|4
index|]
decl_stmt|;
block|}
name|b
name|__attribute
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
struct|;
block|}
end_function

end_unit

