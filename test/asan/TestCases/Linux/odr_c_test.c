begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that we can properly report an ODR violation
end_comment

begin_comment
comment|// between an instrumented global and a non-instrumented global.
end_comment

begin_comment
comment|// RUN: %clang_asan %s -fPIC -shared -o %t-1.so  -DFILE1
end_comment

begin_comment
comment|// RUN: %clang_asan %s -fPIC -shared -o %t-2.so  -DFILE2
end_comment

begin_comment
comment|// RUN: %clang_asan %s -fPIE %t-1.so %t-2.so -Wl,-R`pwd` -o %t
end_comment

begin_comment
comment|// RUN: not %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// REQUIRES: x86_64-target-arch
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: The following global variable is not properly aligned.
end_comment

begin_comment
comment|// CHECK: ERROR: AddressSanitizer: odr-violation
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FILE1
argument_list|)
end_if

begin_macro
name|__attribute__
argument_list|(
argument|(aligned(
literal|8
argument|))
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_macro
name|__attribute__
argument_list|(
argument|(aligned(
literal|1
argument|))
argument_list|)
end_macro

begin_decl_stmt
name|char
name|y
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The gold linker puts ZZZ at the start of bss (where it is aligned)
end_comment

begin_comment
comment|// unless we have a large alternative like Displace:
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(aligned(
literal|1
argument|))
argument_list|)
end_macro

begin_decl_stmt
name|char
name|Displace
index|[
literal|105
index|]
decl_stmt|;
end_decl_stmt

begin_macro
name|__attribute__
argument_list|(
argument|(aligned(
literal|1
argument|))
argument_list|)
end_macro

begin_decl_stmt
name|char
name|ZZZ
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|FILE2
argument_list|)
end_elif

begin_decl_stmt
name|int
name|ZZZ
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|ZZZ
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
name|ZZZ
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

