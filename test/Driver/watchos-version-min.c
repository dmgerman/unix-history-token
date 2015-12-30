begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin10 -mwatchsimulator-version-min=2.0 -arch i386 -S -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7s-apple-darwin10 -mwatchos-version-min=2.0 -arch armv7k -S -o - %s | FileCheck %s
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: .watchos_version_min 2, 0
end_comment

end_unit

