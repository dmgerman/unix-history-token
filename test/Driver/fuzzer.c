begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test flags inserted by -fsanitize=fuzzer.
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=fuzzer %s -target x86_64-apple-darwin14 -### 2>&1 | FileCheck --check-prefixes=CHECK-FUZZER-LIB,CHECK-COVERAGE-FLAGS %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-FUZZER-LIB: libLLVMFuzzer.a
end_comment

begin_comment
comment|// CHECK-COVERAGE: -fsanitize-coverage-trace-pc-guard
end_comment

begin_comment
comment|// CHECK-COVERAGE-SAME: -fsanitize-coverage-indirect-calls
end_comment

begin_comment
comment|// CHECK-COVERAGE-SAME: -fsanitize-coverage-trace-cmp
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=fuzzer -target i386-unknown-linux -stdlib=platform %s -### 2>&1 | FileCheck --check-prefixes=CHECK-LIBCXX-LINUX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LIBCXX-LINUX: -lstdc++
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin14 -fsanitize=fuzzer %s -### 2>&1 | FileCheck --check-prefixes=CHECK-LIBCXX-DARWIN %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LIBCXX-DARWIN: -lc++
end_comment

begin_function
name|int
name|LLVMFuzzerTestOneInput
parameter_list|(
specifier|const
name|char
modifier|*
name|Data
parameter_list|,
name|long
name|Size
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

