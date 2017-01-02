begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test strict_string_checks option in strstr function
end_comment

begin_comment
comment|// RUN: %clang_asan %s -o %t&& %run %t 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=false %run %t 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=true not %run %t 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
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
name|size
init|=
literal|100
decl_stmt|;
name|char
name|fill
init|=
literal|'o'
decl_stmt|;
name|char
modifier|*
name|s1
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|char
modifier|*
name|s2
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|memset
argument_list|(
name|s1
argument_list|,
name|fill
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|s2
argument_list|,
name|fill
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|s2
index|[
name|size
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
name|char
modifier|*
name|r
init|=
name|strstr
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
decl_stmt|;
comment|// CHECK: {{.*ERROR: AddressSanitizer: heap-buffer-overflow on address}}
comment|// CHECK: READ of size {{101|100}}
name|assert
argument_list|(
name|r
operator|==
name|s1
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|s2
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

