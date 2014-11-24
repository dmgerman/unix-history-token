begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows-itanium -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-C -check-prefix CHECK
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows-itanium -emit-llvm -x c++ %s -o - \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-CXX -check-prefix CHECK
end_comment

begin_function
name|int
name|function
parameter_list|()
block|{
return|return
literal|32
return|;
block|}
end_function

begin_comment
comment|// CHECK-C: define i32 @function() {{.*}} {
end_comment

begin_comment
comment|// CHECK-CXX: define i32 @_Z8functionv() {{.*}} {
end_comment

begin_comment
comment|// CHECK:   ret i32 32
end_comment

begin_comment
comment|// CHECK: }
end_comment

end_unit

