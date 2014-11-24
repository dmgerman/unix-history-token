begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// Check that Cortex-M cores don't enable hwdiv-arm (and don't emit Tag_DIV_use)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This target feature doesn't affect C predefines, nor the generated IR;
end_comment

begin_comment
comment|// only the build attributes in generated assembly and object files are affected.
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m3 -S %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m4 -S %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK-NOT: .eabi_attribute	44
end_comment

end_unit

