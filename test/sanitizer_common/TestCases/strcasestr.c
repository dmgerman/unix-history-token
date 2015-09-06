begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -o %t&& %run %t 2>&1
end_comment

begin_comment
comment|// There's no interceptor for strcasestr on Windows
end_comment

begin_comment
comment|// XFAIL: win32
end_comment

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

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
name|char
modifier|*
name|r
init|=
literal|0
decl_stmt|;
name|char
name|s1
index|[]
init|=
literal|"aB"
decl_stmt|;
name|char
name|s2
index|[]
init|=
literal|"b"
decl_stmt|;
name|r
operator|=
name|strcasestr
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|r
operator|==
name|s1
operator|+
literal|1
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

