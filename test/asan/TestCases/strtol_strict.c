begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test strict_string_checks option in strtol function
end_comment

begin_comment
comment|// RUN: %clang_asan -D_CRT_SECURE_NO_WARNINGS -DTEST1 %s -o %t
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

begin_comment
comment|// RUN: %run %t test4 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=false %run %t test4 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=true not %run %t test4 2>&1 | FileCheck %s --check-prefix=CHECK4
end_comment

begin_comment
comment|// RUN: %run %t test5 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=false %run %t test5 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=true not %run %t test5 2>&1 | FileCheck %s --check-prefix=CHECK5
end_comment

begin_comment
comment|// RUN: %run %t test6 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=false %run %t test6 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=true not %run %t test6 2>&1 | FileCheck %s --check-prefix=CHECK6
end_comment

begin_comment
comment|// RUN: %run %t test7 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=false %run %t test7 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=true not %run %t test7 2>&1 | FileCheck %s --check-prefix=CHECK7
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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sanitizer/asan_interface.h>
end_include

begin_function
name|void
name|test1
parameter_list|(
name|char
modifier|*
name|array
parameter_list|,
name|char
modifier|*
name|endptr
parameter_list|)
block|{
comment|// Buffer overflow if there is no terminating null (depends on base)
name|long
name|r
init|=
name|strtol
argument_list|(
name|array
argument_list|,
operator|&
name|endptr
argument_list|,
literal|3
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|array
operator|+
literal|2
operator|==
name|endptr
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|r
operator|==
literal|5
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
parameter_list|,
name|char
modifier|*
name|endptr
parameter_list|)
block|{
comment|// Buffer overflow if there is no terminating null (depends on base)
name|array
index|[
literal|2
index|]
operator|=
literal|'z'
expr_stmt|;
name|long
name|r
init|=
name|strtol
argument_list|(
name|array
argument_list|,
operator|&
name|endptr
argument_list|,
literal|35
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|array
operator|+
literal|2
operator|==
name|endptr
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|r
operator|==
literal|37
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
parameter_list|,
name|char
modifier|*
name|endptr
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|_MSC_VER
comment|// Using -1 for a strtol base causes MSVC to abort. Print the expected lines
comment|// to make the test pass.
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ERROR: AddressSanitizer: use-after-poison on address\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"READ of size 1\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|char
modifier|*
name|opts
init|=
name|getenv
argument_list|(
literal|"ASAN_OPTIONS"
argument_list|)
decl_stmt|;
name|exit
argument_list|(
name|opts
operator|&&
name|strstr
argument_list|(
name|opts
argument_list|,
literal|"strict_string_checks=true"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Buffer overflow if base is invalid.
name|memset
argument_list|(
name|array
argument_list|,
literal|0
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|ASAN_POISON_MEMORY_REGION
argument_list|(
name|array
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|long
name|r
init|=
name|strtol
argument_list|(
name|array
operator|+
literal|1
argument_list|,
name|NULL
argument_list|,
operator|-
literal|1
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|r
operator|==
literal|0
argument_list|)
expr_stmt|;
name|ASAN_UNPOISON_MEMORY_REGION
argument_list|(
name|array
argument_list|,
literal|8
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test4
parameter_list|(
name|char
modifier|*
name|array
parameter_list|,
name|char
modifier|*
name|endptr
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|_MSC_VER
comment|// Using -1 for a strtol base causes MSVC to abort. Print the expected lines
comment|// to make the test pass.
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ERROR: AddressSanitizer: heap-buffer-overflow on address\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"READ of size 1\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|char
modifier|*
name|opts
init|=
name|getenv
argument_list|(
literal|"ASAN_OPTIONS"
argument_list|)
decl_stmt|;
name|exit
argument_list|(
name|opts
operator|&&
name|strstr
argument_list|(
name|opts
argument_list|,
literal|"strict_string_checks=true"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Buffer overflow if base is invalid.
name|long
name|r
init|=
name|strtol
argument_list|(
name|array
operator|+
literal|3
argument_list|,
name|NULL
argument_list|,
literal|1
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
name|test5
parameter_list|(
name|char
modifier|*
name|array
parameter_list|,
name|char
modifier|*
name|endptr
parameter_list|)
block|{
comment|// Overflow if no digits are found.
name|array
index|[
literal|0
index|]
operator|=
literal|' '
expr_stmt|;
name|array
index|[
literal|1
index|]
operator|=
literal|'+'
expr_stmt|;
name|array
index|[
literal|2
index|]
operator|=
literal|'-'
expr_stmt|;
name|long
name|r
init|=
name|strtol
argument_list|(
name|array
argument_list|,
name|NULL
argument_list|,
literal|0
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
name|test6
parameter_list|(
name|char
modifier|*
name|array
parameter_list|,
name|char
modifier|*
name|endptr
parameter_list|)
block|{
comment|// Overflow if no digits are found.
name|array
index|[
literal|0
index|]
operator|=
literal|' '
expr_stmt|;
name|array
index|[
literal|1
index|]
operator|=
name|array
index|[
literal|2
index|]
operator|=
literal|'z'
expr_stmt|;
name|long
name|r
init|=
name|strtol
argument_list|(
name|array
argument_list|,
operator|&
name|endptr
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|array
operator|==
name|endptr
argument_list|)
expr_stmt|;
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
name|test7
parameter_list|(
name|char
modifier|*
name|array
parameter_list|,
name|char
modifier|*
name|endptr
parameter_list|)
block|{
comment|// Overflow if no digits are found.
name|array
index|[
literal|2
index|]
operator|=
literal|'z'
expr_stmt|;
name|long
name|r
init|=
name|strtol
argument_list|(
name|array
operator|+
literal|2
argument_list|,
name|NULL
argument_list|,
literal|0
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
name|array0
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|11
argument_list|)
decl_stmt|;
name|char
modifier|*
name|array
init|=
name|array0
operator|+
literal|8
decl_stmt|;
name|char
modifier|*
name|endptr
init|=
name|NULL
decl_stmt|;
name|array
index|[
literal|0
index|]
operator|=
literal|'1'
expr_stmt|;
name|array
index|[
literal|1
index|]
operator|=
literal|'2'
expr_stmt|;
name|array
index|[
literal|2
index|]
operator|=
literal|'3'
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
name|array
argument_list|,
name|endptr
argument_list|)
expr_stmt|;
comment|// CHECK1: {{.*ERROR: AddressSanitizer: heap-buffer-overflow on address}}
comment|// CHECK1: READ of size 4
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
argument_list|,
name|endptr
argument_list|)
expr_stmt|;
comment|// CHECK2: {{.*ERROR: AddressSanitizer: heap-buffer-overflow on address}}
comment|// CHECK2: READ of size 4
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
name|array0
argument_list|,
name|endptr
argument_list|)
expr_stmt|;
comment|// CHECK3: {{.*ERROR: AddressSanitizer: use-after-poison on address}}
comment|// CHECK3: READ of size 1
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
literal|"test4"
argument_list|)
condition|)
name|test4
argument_list|(
name|array
argument_list|,
name|endptr
argument_list|)
expr_stmt|;
comment|// CHECK4: {{.*ERROR: AddressSanitizer: heap-buffer-overflow on address}}
comment|// CHECK4: READ of size 1
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
literal|"test5"
argument_list|)
condition|)
name|test5
argument_list|(
name|array
argument_list|,
name|endptr
argument_list|)
expr_stmt|;
comment|// CHECK5: {{.*ERROR: AddressSanitizer: heap-buffer-overflow on address}}
comment|// CHECK5: READ of size 4
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
literal|"test6"
argument_list|)
condition|)
name|test6
argument_list|(
name|array
argument_list|,
name|endptr
argument_list|)
expr_stmt|;
comment|// CHECK6: {{.*ERROR: AddressSanitizer: heap-buffer-overflow on address}}
comment|// CHECK6: READ of size 4
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
literal|"test7"
argument_list|)
condition|)
name|test7
argument_list|(
name|array
argument_list|,
name|endptr
argument_list|)
expr_stmt|;
comment|// CHECK7: {{.*ERROR: AddressSanitizer: heap-buffer-overflow on address}}
comment|// CHECK7: READ of size 2
name|free
argument_list|(
name|array0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

