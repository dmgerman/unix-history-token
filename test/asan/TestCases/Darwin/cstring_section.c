begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that AddressSanitizer moves constant strings into a separate section.
end_comment

begin_comment
comment|// RUN: %clang_asan -c -o %t %s
end_comment

begin_comment
comment|// RUN: llvm-objdump -s %t | FileCheck %s
end_comment

begin_comment
comment|// Check that "Hello.\n" is in __asan_cstring and not in __cstring.
end_comment

begin_comment
comment|// CHECK: Contents of section __asan_cstring:
end_comment

begin_comment
comment|// CHECK: 48656c6c {{.*}} Hello.
end_comment

begin_comment
comment|// CHECK: Contents of section __const:
end_comment

begin_comment
comment|// CHECK-NOT: 48656c6c {{.*}} Hello.
end_comment

begin_comment
comment|// CHECK: Contents of section __cstring:
end_comment

begin_comment
comment|// CHECK-NOT: 48656c6c {{.*}} Hello.
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
name|argv
index|[
literal|0
index|]
operator|=
literal|"Hello.\n"
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

