begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_msan -m64 -O0 %s -o %t&& %run %t>%t.out 2>&1
end_comment

begin_comment
comment|// RUN: %clang_msan -m64 -O1 %s -o %t&& %run %t>%t.out 2>&1
end_comment

begin_comment
comment|// RUN: %clang_msan -m64 -O2 %s -o %t&& %run %t>%t.out 2>&1
end_comment

begin_comment
comment|// RUN: %clang_msan -m64 -O3 %s -o %t&& %run %t>%t.out 2>&1
end_comment

begin_comment
comment|// Test that strdup in C programs is intercepted.
end_comment

begin_comment
comment|// GLibC headers translate strdup to __strdup at -O1 and higher.
end_comment

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
name|char
name|buf
index|[]
init|=
literal|"abc"
decl_stmt|;
name|char
modifier|*
name|p
init|=
name|strdup
argument_list|(
name|buf
argument_list|)
decl_stmt|;
if|if
condition|(
operator|*
name|p
condition|)
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

