begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003-2006 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Every test program should #include "test.h" as the first thing. */
end_comment

begin_comment
comment|/*  * The goal of this file (and the matching test.c) is to  * simplify the very repetitive test-*.c test programs.  */
end_comment

begin_include
include|#
directive|include
file|<archive.h>
end_include

begin_include
include|#
directive|include
file|<archive_entry.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
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
file|<sys/stat.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CONFIG_H
argument_list|)
end_if

begin_comment
comment|/* Most POSIX platforms use the 'configure' script to build config.h */
end_comment

begin_include
include|#
directive|include
file|"../../config.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_comment
comment|/* Building as part of FreeBSD system requires a pre-built config.h. */
end_comment

begin_include
include|#
directive|include
file|"../config_freebsd.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_elif

begin_comment
comment|/* Win32 can't run the 'configure' script. */
end_comment

begin_include
include|#
directive|include
file|"../config_windows.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Warn if the library hasn't been (automatically or manually) configured. */
end_comment

begin_error
error|#
directive|error
error|Oops: No config.h and no pre-built configuration in test.h.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * "list.h" is simply created by "grep DEFINE_TEST"; it has  * a line like  *      DEFINE_TEST(test_function)  * for each test.  * Include it here with a suitable DEFINE_TEST to declare all of the  * test functions.  */
end_comment

begin_define
define|#
directive|define
name|DEFINE_TEST
parameter_list|(
name|name
parameter_list|)
value|void name(void);
end_define

begin_include
include|#
directive|include
file|"list.h"
end_include

begin_comment
comment|/*  * Redefine DEFINE_TEST for use in defining the test functions.  */
end_comment

begin_undef
undef|#
directive|undef
name|DEFINE_TEST
end_undef

begin_define
define|#
directive|define
name|DEFINE_TEST
parameter_list|(
name|name
parameter_list|)
value|void name(void)
end_define

begin_comment
comment|/* An implementation of the standard assert() macro */
end_comment

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|e
parameter_list|)
value|test_assert(__FILE__, __LINE__, (e), #e, NULL)
end_define

begin_comment
comment|/* As above, but reports any archive_error found in variable 'a' */
end_comment

begin_define
define|#
directive|define
name|assertA
parameter_list|(
name|e
parameter_list|)
value|test_assert(__FILE__, __LINE__, (e), #e, (a))
end_define

begin_comment
comment|/* Asserts that two values are the same.  Reports value of each one if not. */
end_comment

begin_define
define|#
directive|define
name|assertEqualIntA
parameter_list|(
name|a
parameter_list|,
name|v1
parameter_list|,
name|v2
parameter_list|)
define|\
value|test_assert_equal_int(__FILE__, __LINE__, (v1), #v1, (v2), #v2, (a))
end_define

begin_comment
comment|/* Asserts that two values are the same.  Reports value of each one if not. */
end_comment

begin_define
define|#
directive|define
name|assertEqualInt
parameter_list|(
name|v1
parameter_list|,
name|v2
parameter_list|)
define|\
value|test_assert_equal_int(__FILE__, __LINE__, (v1), #v1, (v2), #v2, NULL)
end_define

begin_comment
comment|/* Function declarations.  These are defined in test_utility.c. */
end_comment

begin_function_decl
name|void
name|failure
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_assert
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_assert_equal_int
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

