begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm< %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-unknown-unknown -emit-llvm< %s | FileCheck %s
end_comment

begin_comment
comment|// Check that the preserve_most calling convention attribute at the source level
end_comment

begin_comment
comment|// is lowered to the corresponding calling convention attrribute at the LLVM IR
end_comment

begin_comment
comment|// level.
end_comment

begin_function
name|void
name|foo
parameter_list|()
function|__attribute__
parameter_list|(
function|(preserve_most
end_function

begin_block
unit|))
block|{
comment|// CHECK-LABEL: define preserve_mostcc void @foo()
block|}
end_block

begin_comment
comment|// Check that the preserve_most calling convention attribute at the source level
end_comment

begin_comment
comment|// is lowered to the corresponding calling convention attrribute at the LLVM IR
end_comment

begin_comment
comment|// level.
end_comment

begin_function
name|void
name|boo
parameter_list|()
function|__attribute__
parameter_list|(
function|(preserve_all
end_function

begin_block
unit|))
block|{
comment|// CHECK-LABEL: define preserve_allcc void @boo()
block|}
end_block

end_unit

