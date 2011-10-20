begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// PR607
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_union
union|union
block|{
name|char
name|bytes
index|[
literal|8
index|]
decl_stmt|;
name|double
name|alignment
decl_stmt|;
block|}
name|EQ1
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
union|;
end_union

end_unit

