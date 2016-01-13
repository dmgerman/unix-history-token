begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin10 -mappletvsimulator-version-min=9.0 -arch x86_64 -S -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7s-apple-darwin10 -mappletvos-version-min=9.0 -arch arm64 -S -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: env TVOS_DEPLOYMENT_TARGET=9.0 %clang -isysroot SDKs/MacOSX10.9.sdk -target i386-apple-darwin10  -arch x86_64 -S -o - %s | FileCheck %s
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
comment|// CHECK: .tvos_version_min 9, 0
end_comment

end_unit

