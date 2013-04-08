begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Wuninitialized -fsyntax-only %s 2>&1 | FileCheck %s
end_comment

begin_function
name|void
name|pr14901
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|int
name|b
decl_stmt|,
name|c
decl_stmt|;
name|a
operator|=
name|b
expr_stmt|;
name|a
operator|=
name|c
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: 5:8: warning: variable 'b' is uninitialized when used here
end_comment

begin_comment
comment|// CHECK: 4:9: note: initialize the variable 'b' to silence this warning
end_comment

begin_comment
comment|// CHECK: 6:8: warning: variable 'c' is uninitialized when used here
end_comment

begin_comment
comment|// CHECK: 4:12: note: initialize the variable 'c' to silence this warning
end_comment

end_unit

