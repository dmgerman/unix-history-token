begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown %s -O3 -emit-llvm -o - | grep 'ret i32 6'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -x c++ %s -O3 -emit-llvm -o - | grep 'ret i32 7'
end_comment

begin_enum
specifier|static
enum|enum
block|{
name|foo
block|,
name|bar
init|=
literal|1U
block|}
name|z
enum|;
end_enum

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|r
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|bar
operator|-
literal|2
operator|<
literal|0
condition|)
name|r
operator|+=
literal|4
expr_stmt|;
if|if
condition|(
name|foo
operator|-
literal|1
operator|<
literal|0
condition|)
name|r
operator|+=
literal|2
expr_stmt|;
if|if
condition|(
name|z
operator|-
literal|1
operator|<
literal|0
condition|)
name|r
operator|++
expr_stmt|;
return|return
name|r
return|;
block|}
end_function

end_unit

