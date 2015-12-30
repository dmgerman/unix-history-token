begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test strict_string_checks option in strncat function
end_comment

begin_comment
comment|// RUN: %clang_asan %s -o %t
end_comment

begin_comment
comment|// RUN: not %run %t test1 2>&1 | FileCheck %s --check-prefix=CHECK1-NONSTRICT --check-prefix=CHECK1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=false not  %run %t test1 2>&1 | FileCheck %s --check-prefix=CHECK1-NONSTRICT --check-prefix=CHECK1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=true not %run %t test1 2>&1 | FileCheck %s --check-prefix=CHECK1-STRICT --check-prefix=CHECK1
end_comment

begin_comment
comment|// RUN: not %run %t test2 2>&1 | FileCheck %s --check-prefix=CHECK2-NONSTRICT --check-prefix=CHECK2
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=false not  %run %t test2 2>&1 | FileCheck %s --check-prefix=CHECK2-NONSTRICT --check-prefix=CHECK2
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=true not %run %t test2 2>&1 | FileCheck %s --check-prefix=CHECK2-STRICT --check-prefix=CHECK2
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
name|to
parameter_list|,
name|int
name|to_size
parameter_list|,
name|char
modifier|*
name|from
parameter_list|)
block|{
comment|// One of arguments points to not allocated memory.
name|char
modifier|*
name|r
init|=
name|strncat
argument_list|(
name|to
operator|+
name|to_size
argument_list|,
name|from
argument_list|,
literal|2
argument_list|)
decl_stmt|;
block|}
end_function

begin_function
name|void
name|test2
parameter_list|(
name|char
modifier|*
name|to
parameter_list|,
name|int
name|to_size
parameter_list|,
name|char
modifier|*
name|from
parameter_list|)
block|{
comment|// "to" is not zero-terminated.
name|memset
argument_list|(
name|to
argument_list|,
literal|'z'
argument_list|,
name|to_size
argument_list|)
expr_stmt|;
name|char
modifier|*
name|r
init|=
name|strncat
argument_list|(
name|to
argument_list|,
name|from
argument_list|,
literal|1
argument_list|)
decl_stmt|;
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
name|size_t
name|to_size
init|=
literal|100
decl_stmt|;
name|char
modifier|*
name|to
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|to_size
argument_list|)
decl_stmt|;
name|size_t
name|from_size
init|=
literal|20
decl_stmt|;
name|char
modifier|*
name|from
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|from_size
argument_list|)
decl_stmt|;
name|memset
argument_list|(
name|from
argument_list|,
literal|'z'
argument_list|,
name|from_size
argument_list|)
expr_stmt|;
name|from
index|[
name|from_size
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
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
name|to
argument_list|,
name|to_size
argument_list|,
name|from
argument_list|)
expr_stmt|;
comment|// CHECK1: {{.*ERROR: AddressSanitizer: heap-buffer-overflow on address}}
comment|// CHECK1-STRICT: READ of size 1
comment|// CHECK1-NONSTRICT: WRITE of size 3
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
name|to
argument_list|,
name|to_size
argument_list|,
name|from
argument_list|)
expr_stmt|;
comment|// CHECK2: {{.*ERROR: AddressSanitizer: heap-buffer-overflow on address}}
comment|// CHECK2-STRICT: READ of size 101
comment|// CHECK2-NONSTRICT: WRITE of size 2
name|free
argument_list|(
name|to
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|from
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

