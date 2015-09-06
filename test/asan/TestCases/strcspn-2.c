begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test stopset overflow in strcspn function
end_comment

begin_comment
comment|// RUN: %clang_asan %s -o %t&& env ASAN_OPTIONS=$ASAN_OPTIONS:strict_string_checks=true not %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// Test intercept_strcspn asan option
end_comment

begin_comment
comment|// RUN: env ASAN_OPTIONS=$ASAN_OPTIONS:intercept_strspn=false %run %t 2>&1
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
name|s1
index|[]
init|=
literal|"ab"
decl_stmt|;
name|char
name|s2
index|[]
init|=
block|{
literal|'a'
block|}
decl_stmt|;
name|char
name|s3
init|=
literal|0
decl_stmt|;
name|r
operator|=
name|strcspn
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
expr_stmt|;
comment|// CHECK:'s{{[2|3]}}'<== Memory access at offset {{[0-9]+ .*}}flows this variable
name|assert
argument_list|(
name|r
operator|==
literal|0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

