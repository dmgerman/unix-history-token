begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm %s -o - -triple i686-pc-linux-gnu | grep "bitcast (%0\* @r to %union.x\*), \[4 x i8\] undef"
end_comment

begin_comment
comment|// Make sure we generate something sane instead of a ptrtoint
end_comment

begin_union
union|union
name|x
block|{
name|long
name|long
name|b
decl_stmt|;
name|union
name|x
modifier|*
name|a
decl_stmt|;
block|}
name|r
init|=
block|{
operator|.
name|a
operator|=
operator|&
name|r
block|}
union|;
end_union

end_unit

