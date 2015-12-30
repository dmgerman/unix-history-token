begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown %s -debug-info-kind=limited -emit-llvm -o /dev/null
end_comment

begin_decl_stmt
name|int
name|v
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|e
block|{
name|MAX
block|}
enum|;
end_enum

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
name|v
operator|=
name|MAX
expr_stmt|;
block|}
end_function

end_unit

