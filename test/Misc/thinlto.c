begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -flto=thin -emit-llvm-bc< %s | llvm-bcanalyzer -dump | FileCheck %s
end_comment

begin_comment
comment|// CHECK:<FUNCTION_SUMMARY_BLOCK
end_comment

begin_comment
comment|// CHECK-NEXT:<PERMODULE_ENTRY
end_comment

begin_comment
comment|// CHECK-NEXT:<PERMODULE_ENTRY
end_comment

begin_comment
comment|// CHECK-NEXT:</FUNCTION_SUMMARY_BLOCK
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|foo
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

