begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -o - -emit-llvm | FileCheck %s
end_comment

begin_comment
comment|// XFAIL: aarch64, arm64, x86_64-pc-win32, x86_64-w64-mingw32
end_comment

begin_comment
comment|// PR1513
end_comment

begin_comment
comment|// AArch64 ABI actually requires the reverse of what this is testing: the callee
end_comment

begin_comment
comment|// does any extensions and remaining bits are unspecified.
end_comment

begin_comment
comment|// Win64 ABI does expect extensions for type smaller than 64bits.
end_comment

begin_comment
comment|// Technically this test wasn't written to test that feature, but it's a
end_comment

begin_comment
comment|// valuable check nevertheless.
end_comment

begin_struct
struct|struct
name|s
block|{
name|long
name|a
decl_stmt|;
name|long
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f
parameter_list|(
name|struct
name|s
name|a
parameter_list|,
name|char
modifier|*
name|b
parameter_list|,
name|signed
name|char
name|C
parameter_list|)
block|{
comment|// CHECK: i8 signext
block|}
end_function

end_unit

