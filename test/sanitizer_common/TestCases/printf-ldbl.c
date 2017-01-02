begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -o %t&& %run %t 2>&1
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
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
index|[
literal|20
index|]
decl_stmt|;
name|long
name|double
name|ld
init|=
literal|4.0
decl_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|,
literal|"%Lf %d"
argument_list|,
name|ld
argument_list|,
literal|123
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|strcmp
argument_list|(
name|buf
argument_list|,
literal|"4.000000 123"
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

