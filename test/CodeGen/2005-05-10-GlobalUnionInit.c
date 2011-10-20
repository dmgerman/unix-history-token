begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_union
union|union
name|A
block|{
comment|// { uint }
union|union
name|B
block|{
name|double
modifier|*
name|C
decl_stmt|;
block|}
name|D
union|;
block|}
name|E
init|=
block|{
block|{
operator|(
name|double
operator|*
operator|)
literal|12312
block|}
block|}
union|;
end_union

end_unit

