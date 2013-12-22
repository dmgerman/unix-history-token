begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-apple-darwin9 -target-abi apcs-gnu -emit-llvm -w -o - %s | FileCheck -check-prefix=DARWIN-APCS %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-apple-darwin9 -target-abi aapcs  -emit-llvm -w -o - %s | FileCheck -check-prefix=DARWIN-AAPCS %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-none-linux-gnueabi -target-abi apcs-gnu -emit-llvm -w -o - %s | FileCheck -check-prefix=LINUX-APCS %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-none-linux-gnueabi -target-abi aapcs  -emit-llvm -w -o - %s | FileCheck -check-prefix=LINUX-AAPCS %s
end_comment

begin_comment
comment|// DARWIN-APCS-LABEL: define void @f()
end_comment

begin_comment
comment|// DARWIN-APCS: call void @g
end_comment

begin_comment
comment|// DARWIN-AAPCS-LABEL: define arm_aapcscc void @f()
end_comment

begin_comment
comment|// DARWIN-AAPCS: call arm_aapcscc void @g
end_comment

begin_comment
comment|// LINUX-APCS-LABEL: define arm_apcscc void @f()
end_comment

begin_comment
comment|// LINUX-APCS: call arm_apcscc void @g
end_comment

begin_comment
comment|// LINUX-AAPCS-LABEL: define void @f()
end_comment

begin_comment
comment|// LINUX-AAPCS: call void @g
end_comment

begin_function_decl
name|void
name|g
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{
name|g
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

