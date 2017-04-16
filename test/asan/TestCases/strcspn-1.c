begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test string s1 overflow in strcspn function
end_comment

begin_comment
comment|// RUN: %clang_asan %s -o %t&& %env_asan_opts=strict_string_checks=true not %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// Test intercept_strspn asan option
end_comment

begin_comment
comment|// RUN: %env_asan_opts=intercept_strspn=false %run %t 2>&1
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sanitizer/asan_interface.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|size_t
name|r
decl_stmt|;
name|char
name|s2
index|[]
init|=
literal|"ab"
decl_stmt|;
name|char
name|s1
index|[
literal|4
index|]
init|=
literal|"caB"
decl_stmt|;
name|__asan_poison_memory_region
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|s1
index|[
literal|2
index|]
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|r
operator|=
name|strcspn
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
expr_stmt|;
comment|// CHECK:'s1'{{.*}}<== Memory access at offset {{[0-9]+}} partially overflows this variable
name|assert
argument_list|(
name|r
operator|==
literal|1
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

