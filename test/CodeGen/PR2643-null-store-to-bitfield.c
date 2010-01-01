begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s
end_comment

begin_comment
comment|// PR2643
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
struct|struct
block|{
name|int
name|a
range|:
literal|1
decl_stmt|;
name|int
name|b
range|:
literal|1
decl_stmt|;
block|}
name|entry
init|=
block|{
literal|0
block|}
struct|;
block|}
end_function

end_unit

