begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003-2017 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Every test program should #include "test.h" as the first thing. */
end_comment

begin_define
define|#
directive|define
name|KNOWNREF
value|"test_patterns_2.tar.uu"
end_define

begin_define
define|#
directive|define
name|ENVBASE
value|"BSDTAR"
end_define

begin_comment
comment|/* Prefix for environment variables. */
end_comment

begin_define
define|#
directive|define
name|PROGRAM
value|"bsdtar"
end_define

begin_comment
comment|/* Name of program being tested. */
end_comment

begin_define
define|#
directive|define
name|PROGRAM_ALIAS
value|"tar"
end_define

begin_comment
comment|/* Generic alias for program */
end_comment

begin_undef
undef|#
directive|undef
name|LIBRARY
end_undef

begin_comment
comment|/* Not testing a library. */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRA_DUMP
end_undef

begin_comment
comment|/* How to dump extra data */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRA_ERRNO
end_undef

begin_comment
comment|/* How to dump errno */
end_comment

begin_comment
comment|/* How to generate extra version info. */
end_comment

begin_define
define|#
directive|define
name|EXTRA_VERSION
value|(systemf("%s --version", testprog) ? "" : "")
end_define

begin_include
include|#
directive|include
file|"test_common.h"
end_include

end_unit

