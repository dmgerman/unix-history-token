begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RIPEMD160DRIVER.C - test driver for RIPEMD160  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Copyright (C) 1990-2, RSA Data Security, Inc. Created 1990. All    rights reserved.     RSA Data Security, Inc. makes no representations concerning either    the merchantability of this software or the suitability of this    software for any particular purpose. It is provided "as is"    without express or implied warranty of any kind.     These notices must be retained in any copies of any part of this    documentation and/or software.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"ripemd.h"
end_include

begin_comment
comment|/* Digests a string and prints the result.  */
end_comment

begin_function
specifier|static
name|void
name|RIPEMD160String
parameter_list|(
name|string
parameter_list|)
name|char
modifier|*
name|string
decl_stmt|;
block|{
name|char
name|buf
index|[
literal|2
operator|*
literal|20
operator|+
literal|1
index|]
decl_stmt|;
name|printf
argument_list|(
literal|"RIPEMD160 (\"%s\") = %s\n"
argument_list|,
name|string
argument_list|,
name|RIPEMD160_Data
argument_list|(
name|string
argument_list|,
name|strlen
argument_list|(
name|string
argument_list|)
argument_list|,
name|buf
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Digests a reference suite of strings and prints the results.  */
end_comment

begin_function
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"RIPEMD160 test suite:\n"
argument_list|)
expr_stmt|;
name|RIPEMD160String
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|RIPEMD160String
argument_list|(
literal|"abc"
argument_list|)
expr_stmt|;
name|RIPEMD160String
argument_list|(
literal|"message digest"
argument_list|)
expr_stmt|;
name|RIPEMD160String
argument_list|(
literal|"abcdefghijklmnopqrstuvwxyz"
argument_list|)
expr_stmt|;
name|RIPEMD160String
argument_list|(
literal|"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
argument_list|)
expr_stmt|;
name|RIPEMD160String
argument_list|(
literal|"1234567890123456789012345678901234567890\ 1234567890123456789012345678901234567890"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

