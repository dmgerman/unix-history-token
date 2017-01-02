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
name|long
name|double
name|ld
decl_stmt|;
name|memset
argument_list|(
operator|&
name|ld
argument_list|,
literal|255
argument_list|,
sizeof|sizeof
name|ld
argument_list|)
expr_stmt|;
name|sscanf
argument_list|(
literal|"4.0"
argument_list|,
literal|"%Lf"
argument_list|,
operator|&
name|ld
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|ld
operator|==
literal|4.0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

