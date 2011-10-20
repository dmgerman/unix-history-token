begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// PR947
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
name|label
label|:
name|ptr
operator|=
operator|&&
name|label
expr_stmt|;
goto|goto *
name|ptr
goto|;
block|}
end_function

end_unit

