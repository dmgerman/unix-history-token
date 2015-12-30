begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test strict_string_checks option in atol function
end_comment

begin_comment
comment|// RUN: %clang_asan %s -o %t
end_comment

begin_comment
comment|// RUN: %run %t test1 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=false %run %t test1 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=true not %run %t test1 2>&1 | FileCheck %s --check-prefix=CHECK1
end_comment

begin_comment
comment|// RUN: %run %t test2 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=false %run %t test2 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=true not %run %t test2 2>&1 | FileCheck %s --check-prefix=CHECK2
end_comment

begin_comment
comment|// RUN: %run %t test3 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=false %run %t test3 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=true not %run %t test3 2>&1 | FileCheck %s --check-prefix=CHECK3
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
name|void
name|test1
parameter_list|(
name|char
modifier|*
name|array
parameter_list|)
block|{
comment|// Last symbol is non-digit
name|memset
argument_list|(
name|array
argument_list|,
literal|'1'
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|array
index|[
literal|9
index|]
operator|=
literal|'a'
expr_stmt|;
name|long
name|r
init|=
name|atol
argument_list|(
name|array
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|r
operator|==
literal|111111111
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test2
parameter_list|(
name|char
modifier|*
name|array
parameter_list|)
block|{
comment|// Single non-digit symbol
name|array
index|[
literal|9
index|]
operator|=
literal|'a'
expr_stmt|;
name|long
name|r
init|=
name|atol
argument_list|(
name|array
operator|+
literal|9
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|r
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test3
parameter_list|(
name|char
modifier|*
name|array
parameter_list|)
block|{
comment|// Incorrect number format
name|memset
argument_list|(
name|array
argument_list|,
literal|' '
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|array
index|[
literal|9
index|]
operator|=
literal|'-'
expr_stmt|;
name|array
index|[
literal|8
index|]
operator|=
literal|'-'
expr_stmt|;
name|long
name|r
init|=
name|atol
argument_list|(
name|array
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|r
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

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
name|char
modifier|*
name|array
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|10
argument_list|)
decl_stmt|;
if|if
condition|(
name|argc
operator|!=
literal|2
condition|)
return|return
literal|1
return|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"test1"
argument_list|)
condition|)
name|test1
argument_list|(
name|array
argument_list|)
expr_stmt|;
comment|// CHECK1: {{.*ERROR: AddressSanitizer: heap-buffer-overflow on address}}
comment|// CHECK1: READ of size 11
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"test2"
argument_list|)
condition|)
name|test2
argument_list|(
name|array
argument_list|)
expr_stmt|;
comment|// CHECK2: {{.*ERROR: AddressSanitizer: heap-buffer-overflow on address}}
comment|// CHECK2: READ of size 2
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"test3"
argument_list|)
condition|)
name|test3
argument_list|(
name|array
argument_list|)
expr_stmt|;
comment|// CHECK3: {{.*ERROR: AddressSanitizer: heap-buffer-overflow on address}}
comment|// CHECK3: READ of size 11
name|free
argument_list|(
name|array
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

