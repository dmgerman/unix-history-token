begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows-itanium -mstack-probe-size=8096 -fms-extensions -O2 -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s -check-prefix CHECK-8096
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows-itanium -mstack-probe-size=4096 -fms-extensions -O2 -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s -check-prefix CHECK-4096
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows-itanium -fms-extensions -O2 -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|initialise
parameter_list|(
name|signed
name|char
name|buffer
index|[
literal|4096
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function
name|signed
name|char
name|function
parameter_list|(
name|unsigned
name|index
parameter_list|)
block|{
name|signed
name|char
name|buffer
index|[
literal|4096
index|]
decl_stmt|;
name|initialise
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
return|return
name|buffer
index|[
name|index
index|]
return|;
block|}
end_function

begin_comment
comment|// CHECK-8096: attributes #0 = {
end_comment

begin_comment
comment|// CHECK-8096: "stack-probe-size"="8096"
end_comment

begin_comment
comment|// CHECK-8096: }
end_comment

begin_comment
comment|// CHECK-4096: attributes #0 = {
end_comment

begin_comment
comment|// CHECK-4096-NOT: "stack-probe-size"=
end_comment

begin_comment
comment|// CHECK-4096: }
end_comment

begin_comment
comment|// CHECK: attributes #0 = {
end_comment

begin_comment
comment|// CHECK-NOT: "stack-probe-size"=
end_comment

begin_comment
comment|// CHECK: }
end_comment

end_unit

