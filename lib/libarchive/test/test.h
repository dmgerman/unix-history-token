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

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32
end_ifndef

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<direct.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
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

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32
end_ifndef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_DMALLOC
end_ifdef

begin_include
include|#
directive|include
file|<dmalloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* No non-FreeBSD platform will have __FBSDID, so just define it here. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* For __FBSDID */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__FBSDID
parameter_list|(
name|a
parameter_list|)
end_define

begin_comment
comment|/* null */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_define
define|#
directive|define
name|LOCALE_DE
value|"deu"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOCALE_DE
value|"de_DE.UTF-8"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_BINARY
end_ifndef

begin_define
define|#
directive|define
name|O_BINARY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|void name(void); void name(void)
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
comment|/* Assert two integers are the same.  Reports value of each one if not. */
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
comment|/* Assert two strings are the same.  Reports value of each one if not. */
end_comment

begin_define
define|#
directive|define
name|assertEqualString
parameter_list|(
name|v1
parameter_list|,
name|v2
parameter_list|)
define|\
value|test_assert_equal_string(__FILE__, __LINE__, (v1), #v1, (v2), #v2, NULL)
end_define

begin_comment
comment|/* As above, but v1 and v2 are wchar_t * */
end_comment

begin_define
define|#
directive|define
name|assertEqualWString
parameter_list|(
name|v1
parameter_list|,
name|v2
parameter_list|)
define|\
value|test_assert_equal_wstring(__FILE__, __LINE__, (v1), #v1, (v2), #v2, NULL)
end_define

begin_comment
comment|/* As above, but raw blocks of bytes. */
end_comment

begin_define
define|#
directive|define
name|assertEqualMem
parameter_list|(
name|v1
parameter_list|,
name|v2
parameter_list|,
name|l
parameter_list|)
define|\
value|test_assert_equal_mem(__FILE__, __LINE__, (v1), #v1, (v2), #v2, (l), #l, NULL)
end_define

begin_comment
comment|/* Assert two files are the same; allow printf-style expansion of second name.  * See below for comments about variable arguments here...  */
end_comment

begin_define
define|#
directive|define
name|assertEqualFile
define|\
value|test_setup(__FILE__, __LINE__);test_assert_equal_file
end_define

begin_comment
comment|/* Assert that a file is empty; supports printf-style arguments. */
end_comment

begin_define
define|#
directive|define
name|assertEmptyFile
define|\
value|test_setup(__FILE__, __LINE__);test_assert_empty_file
end_define

begin_comment
comment|/* Assert that a file exists; supports printf-style arguments. */
end_comment

begin_define
define|#
directive|define
name|assertFileExists
define|\
value|test_setup(__FILE__, __LINE__);test_assert_file_exists
end_define

begin_comment
comment|/* Assert that a file exists; supports printf-style arguments. */
end_comment

begin_define
define|#
directive|define
name|assertFileNotExists
define|\
value|test_setup(__FILE__, __LINE__);test_assert_file_not_exists
end_define

begin_comment
comment|/* Assert that file contents match a string; supports printf-style arguments. */
end_comment

begin_define
define|#
directive|define
name|assertFileContents
define|\
value|test_setup(__FILE__, __LINE__);test_assert_file_contents
end_define

begin_comment
comment|/*  * This would be simple with C99 variadic macros, but I don't want to  * require that.  Instead, I insert a function call before each  * skipping() call to pass the file and line information down.  Crude,  * but effective.  */
end_comment

begin_define
define|#
directive|define
name|skipping
define|\
value|test_setup(__FILE__, __LINE__);test_skipping
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
name|test_setup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_skipping
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
name|int
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
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_assert_empty_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_assert_equal_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
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
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_assert_equal_string
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
name|v1
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|v2
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_assert_equal_wstring
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|v1
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|v2
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_assert_equal_mem
parameter_list|(
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
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_assert_file_contents
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_assert_file_exists
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_assert_file_not_exists
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Like sprintf, then system() */
end_comment

begin_function_decl
name|int
name|systemf
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

begin_comment
comment|/* Suck file into string allocated via malloc(). Call free() when done. */
end_comment

begin_comment
comment|/* Supports printf-style args: slurpfile(NULL, "%s/myfile", refdir); */
end_comment

begin_function_decl
name|char
modifier|*
name|slurpfile
parameter_list|(
name|size_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Extracts named reference file to the current directory. */
end_comment

begin_function_decl
name|void
name|extract_reference_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Special interfaces for libarchive test harness.  */
end_comment

begin_include
include|#
directive|include
file|"archive.h"
end_include

begin_include
include|#
directive|include
file|"archive_entry.h"
end_include

begin_comment
comment|/* Special customized read-from-memory interface. */
end_comment

begin_function_decl
name|int
name|read_open_memory
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ARCHIVE_VERSION_STAMP first appeared in 1.9 and libarchive 2.2.4.  * We can approximate it for earlier versions, though.  * This is used to disable tests of features not present in the current  * version.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_VERSION_STAMP
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_VERSION_STAMP
define|\
value|(ARCHIVE_API_VERSION * 1000000 + ARCHIVE_API_FEATURE * 1000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Versions of above that accept an archive argument for additional info. */
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

begin_define
define|#
directive|define
name|assertEqualStringA
parameter_list|(
name|a
parameter_list|,
name|v1
parameter_list|,
name|v2
parameter_list|)
define|\
value|test_assert_equal_string(__FILE__, __LINE__, (v1), #v1, (v2), #v2, (a))
end_define

end_unit

