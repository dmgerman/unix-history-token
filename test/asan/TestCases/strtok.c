begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_asan %s -o %t
end_comment

begin_comment
comment|// Test overflows with strict_string_checks
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=true not %run %t test1 2>&1 | \
end_comment

begin_comment
comment|// RUN:    FileCheck %s --check-prefix=CHECK1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=intercept_strtok=false%run %t test1 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=true not %run %t test2 2>&1 | \
end_comment

begin_comment
comment|// RUN:    FileCheck %s --check-prefix=CHECK2
end_comment

begin_comment
comment|// RUN: %env_asan_opts=intercept_strtok=false %run %t test2 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=true not %run %t test3 2>&1 | \
end_comment

begin_comment
comment|// RUN:    FileCheck %s --check-prefix=CHECK3
end_comment

begin_comment
comment|// RUN: %env_asan_opts=intercept_strtok=false %run %t test3 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=true %run %t test4 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=intercept_strtok=false %run %t test4 2>&1
end_comment

begin_comment
comment|// Test overflows with !strict_string_checks
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=false not %run %t test5 2>&1 | \
end_comment

begin_comment
comment|// RUN:    FileCheck %s --check-prefix=CHECK5
end_comment

begin_comment
comment|// RUN: %env_asan_opts=intercept_strtok=false %run %t test5 2>&1
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=false not %run %t test6 2>&1 | \
end_comment

begin_comment
comment|// RUN:    FileCheck %s --check-prefix=CHECK6
end_comment

begin_comment
comment|// RUN: %env_asan_opts=intercept_strtok=false %run %t test6 2>&1
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

begin_comment
comment|// Check that we find overflows in the delimiters on the first call
end_comment

begin_comment
comment|// with strict_string_checks.
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
name|char
modifier|*
name|token
decl_stmt|;
name|char
name|s
index|[
literal|4
index|]
init|=
literal|"abc"
decl_stmt|;
name|char
name|token_delimiter
index|[
literal|2
index|]
init|=
literal|"b"
decl_stmt|;
name|__asan_poison_memory_region
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|token_delimiter
index|[
literal|1
index|]
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|token
operator|=
name|strtok
argument_list|(
name|s
argument_list|,
name|token_delimiter
argument_list|)
expr_stmt|;
comment|// CHECK1: 'token_delimiter'{{.*}}<== Memory access at offset {{[0-9]+}} partially overflows this variable
block|}
end_function

begin_comment
comment|// Check that we find overflows in the delimiters on the second call (str == NULL)
end_comment

begin_comment
comment|// with strict_string_checks.
end_comment

begin_function
name|void
name|test2
parameter_list|()
block|{
name|char
modifier|*
name|token
decl_stmt|;
name|char
name|s
index|[
literal|4
index|]
init|=
literal|"abc"
decl_stmt|;
name|char
name|token_delimiter
index|[
literal|2
index|]
init|=
literal|"b"
decl_stmt|;
name|token
operator|=
name|strtok
argument_list|(
name|s
argument_list|,
name|token_delimiter
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|strcmp
argument_list|(
name|token
argument_list|,
literal|"a"
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
name|__asan_poison_memory_region
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|token_delimiter
index|[
literal|1
index|]
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|token
operator|=
name|strtok
argument_list|(
name|NULL
argument_list|,
name|token_delimiter
argument_list|)
expr_stmt|;
comment|// CHECK2: 'token_delimiter'{{.*}}<== Memory access at offset {{[0-9]+}} partially overflows this variable
block|}
end_function

begin_comment
comment|// Check that we find overflows in the string (only on the first call) with strict_string_checks.
end_comment

begin_function
name|void
name|test3
parameter_list|()
block|{
name|char
modifier|*
name|token
decl_stmt|;
name|char
name|s
index|[
literal|4
index|]
init|=
literal|"abc"
decl_stmt|;
name|char
name|token_delimiter
index|[
literal|2
index|]
init|=
literal|"b"
decl_stmt|;
name|__asan_poison_memory_region
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|s
index|[
literal|3
index|]
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|token
operator|=
name|strtok
argument_list|(
name|s
argument_list|,
name|token_delimiter
argument_list|)
expr_stmt|;
comment|// CHECK3: 's'{{.*}}<== Memory access at offset {{[0-9]+}} partially overflows this variable
block|}
end_function

begin_comment
comment|// Check that we do not crash when strtok returns NULL with strict_string_checks.
end_comment

begin_function
name|void
name|test4
parameter_list|()
block|{
name|char
modifier|*
name|token
decl_stmt|;
name|char
name|s
index|[]
init|=
literal|""
decl_stmt|;
name|char
name|token_delimiter
index|[]
init|=
literal|"a"
decl_stmt|;
name|token
operator|=
name|strtok
argument_list|(
name|s
argument_list|,
name|token_delimiter
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|token
operator|==
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Check that we find overflows in the string (only on the first call) with !strict_string_checks.
end_comment

begin_function
name|void
name|test5
parameter_list|()
block|{
name|char
modifier|*
name|token
decl_stmt|;
name|char
name|s
index|[
literal|4
index|]
init|=
literal|"abc"
decl_stmt|;
name|char
name|token_delimiter
index|[
literal|2
index|]
init|=
literal|"d"
decl_stmt|;
name|__asan_poison_memory_region
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|s
index|[
literal|2
index|]
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|__asan_poison_memory_region
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|token_delimiter
index|[
literal|1
index|]
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|token
operator|=
name|strtok
argument_list|(
name|s
argument_list|,
name|token_delimiter
argument_list|)
expr_stmt|;
comment|// CHECK5: 's'{{.*}}<== Memory access at offset {{[0-9]+}} partially overflows this variable
block|}
end_function

begin_comment
comment|// Check that we find overflows in the delimiters (only on the first call) with !strict_string_checks.
end_comment

begin_function
name|void
name|test6
parameter_list|()
block|{
name|char
modifier|*
name|token
decl_stmt|;
name|char
name|s
index|[
literal|4
index|]
init|=
literal|"abc"
decl_stmt|;
name|char
name|token_delimiter
index|[
literal|1
index|]
init|=
block|{
literal|'d'
block|}
decl_stmt|;
name|__asan_poison_memory_region
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|token_delimiter
index|[
literal|1
index|]
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|token
operator|=
name|strtok
argument_list|(
name|s
argument_list|,
operator|&
name|token_delimiter
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK6: 'token_delimiter'{{.*}}<== Memory access at offset {{[0-9]+}} overflows this variable
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
argument_list|()
expr_stmt|;
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
argument_list|()
expr_stmt|;
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
argument_list|()
expr_stmt|;
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
argument_list|()
expr_stmt|;
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
argument_list|()
expr_stmt|;
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
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

