begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -o %t -flto=thin -fthin-link-bitcode=%t.nodebug -triple x86_64-unknown-linux-gnu -emit-llvm-bc -debug-info-kind=limited %s
end_comment

begin_comment
comment|// RUN: llvm-bcanalyzer -dump %t | FileCheck %s
end_comment

begin_comment
comment|// RUN: llvm-bcanalyzer -dump %t.nodebug | FileCheck %s --check-prefix=NO_DEBUG
end_comment

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: COMPILE_UNIT
end_comment

begin_comment
comment|// NO_DEBUG-NOT: COMPILE_UNIT
end_comment

end_unit

