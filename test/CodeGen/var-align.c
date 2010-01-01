begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | grep "align 16" | count 2
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(aligned(
literal|16
argument|))
argument_list|)
end_macro

begin_decl_stmt
name|float
name|a
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_union
union|union
block|{
name|int
name|a
index|[
literal|4
index|]
decl_stmt|;
name|__attribute
argument_list|(
argument|(aligned(
literal|16
argument|))
argument_list|)
name|float
name|b
index|[
literal|4
index|]
decl_stmt|;
block|}
name|u
union|;
end_union

end_unit

