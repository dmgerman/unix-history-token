begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MDDRIVER.C - test driver for MD2, MD4 and MD5  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Copyright (C) 1990-2, RSA Data Security, Inc. Created 1990. All    rights reserved.     RSA Data Security, Inc. makes no representations concerning either    the merchantability of this software or the suitability of this    software for any particular purpose. It is provided "as is"    without express or implied warranty of any kind.     These notices must be retained in any copies of any part of this    documentation and/or software.  */
end_comment

begin_comment
comment|/* The following makes MD default to MD5 if it has not already been      defined with C compiler flags.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MD
end_ifndef

begin_define
define|#
directive|define
name|MD
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|MD
operator|==
literal|2
end_if

begin_include
include|#
directive|include
file|"md2.h"
end_include

begin_define
define|#
directive|define
name|MDData
value|MD2Data
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MD
operator|==
literal|4
end_if

begin_include
include|#
directive|include
file|"md4.h"
end_include

begin_define
define|#
directive|define
name|MDData
value|MD4Data
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MD
operator|==
literal|5
end_if

begin_include
include|#
directive|include
file|"md5.h"
end_include

begin_define
define|#
directive|define
name|MDData
value|MD5Data
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Digests a string and prints the result.  */
end_comment

begin_function
specifier|static
name|void
name|MDString
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
literal|33
index|]
decl_stmt|;
name|printf
argument_list|(
literal|"MD%d (\"%s\") = %s\n"
argument_list|,
name|MD
argument_list|,
name|string
argument_list|,
name|MDData
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
literal|"MD%d test suite:\n"
argument_list|,
name|MD
argument_list|)
expr_stmt|;
name|MDString
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|MDString
argument_list|(
literal|"a"
argument_list|)
expr_stmt|;
name|MDString
argument_list|(
literal|"abc"
argument_list|)
expr_stmt|;
name|MDString
argument_list|(
literal|"message digest"
argument_list|)
expr_stmt|;
name|MDString
argument_list|(
literal|"abcdefghijklmnopqrstuvwxyz"
argument_list|)
expr_stmt|;
name|MDString
argument_list|(
literal|"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
argument_list|)
expr_stmt|;
name|MDString
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

