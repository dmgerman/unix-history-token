begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -flto=thin -emit-llvm-bc< %s | llvm-bcanalyzer -dump | FileCheck %s
end_comment

begin_comment
comment|// ; Check that the -flto=thin option emits a summary
end_comment

begin_comment
comment|// CHECK:<GLOBALVAL_SUMMARY_BLOCK
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{}
end_function

end_unit

