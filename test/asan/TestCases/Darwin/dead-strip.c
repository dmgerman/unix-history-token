begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that AddressSanitizer does not re-animate dead globals when dead
end_comment

begin_comment
comment|// stripping is turned on.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This test verifies that an out-of-bounds access on a global variable is
end_comment

begin_comment
comment|// detected after dead stripping has been performed. This proves that the
end_comment

begin_comment
comment|// runtime is able to register globals in the __DATA,__asan_globals section.
end_comment

begin_comment
comment|// REQUIRES: osx-ld64-live_support
end_comment

begin_comment
comment|// UNSUPPORTED: ios
end_comment

begin_comment
comment|// RUN: %clang_asan -mmacosx-version-min=10.11 -Xlinker -dead_strip -o %t %s
end_comment

begin_comment
comment|// RUN: llvm-nm -format=posix %t | FileCheck --check-prefix NM-CHECK %s
end_comment

begin_comment
comment|// RUN: not %run %t 2>&1 | FileCheck --check-prefix ASAN-CHECK %s
end_comment

begin_decl_stmt
name|int
name|alive
index|[
literal|1
index|]
init|=
block|{}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dead
index|[
literal|1
index|]
init|=
block|{}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// NM-CHECK: {{^_alive }}
end_comment

begin_comment
comment|// NM-CHECK-NOT: {{^_dead }}
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|alive
index|[
name|argc
index|]
operator|=
literal|0
expr_stmt|;
comment|// ASAN-CHECK: {{0x.* is located 0 bytes to the right of global variable}}
return|return
literal|0
return|;
block|}
end_function

end_unit

