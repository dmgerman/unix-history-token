begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o -
end_comment

begin_comment
comment|// PR4082
end_comment

begin_union
union|union
name|U
block|{
name|int
name|I
decl_stmt|;
name|double
name|F
decl_stmt|;
block|}
union|;
end_union

begin_decl_stmt
name|union
name|U
name|arr
index|[]
init|=
block|{
block|{
operator|.
name|I
operator|=
literal|4
block|}
block|,
block|{
operator|.
name|F
operator|=
literal|123.
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|U
modifier|*
name|P
init|=
operator|&
name|arr
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

end_unit

