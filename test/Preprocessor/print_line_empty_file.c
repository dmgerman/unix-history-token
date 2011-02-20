begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck %s
end_comment

begin_line
line|#
directive|line
number|21
file|""
end_line

begin_function
name|int
name|foo
parameter_list|()
block|{
return|return
literal|42
return|;
block|}
end_function

begin_line
line|#
directive|line
number|4
file|"bug.c"
end_line

begin_function
name|int
name|bar
parameter_list|()
block|{
return|return
literal|21
return|;
block|}
end_function

begin_comment
comment|// CHECK: # 21 ""
end_comment

begin_comment
comment|// CHECK: int foo() { return 42; }
end_comment

begin_comment
comment|// CHECK: # 4 "bug.c"
end_comment

begin_comment
comment|// CHECK: int bar() { return 21; }
end_comment

end_unit

