begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003-2017 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TEST_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|TEST_COMMON_H
end_define

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
file|"config.h"
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
file|"config_freebsd.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_elif

begin_comment
comment|/* Win32 can't run the 'configure' script. */
end_comment

begin_include
include|#
directive|include
file|"config_windows.h"
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

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Windows requires this before sys/stat.h */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_if
if|#
directive|if
name|HAVE_DIRENT_H
end_if

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DIRECT_H
end_ifdef

begin_include
include|#
directive|include
file|<direct.h>
end_include

begin_define
define|#
directive|define
name|dirent
value|direct
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_IO_H
end_ifdef

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDINT_H
end_ifdef

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

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
name|HAVE_ACL_LIBACL_H
end_ifdef

begin_include
include|#
directive|include
file|<acl/libacl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_ACL_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/acl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_RICHACL_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/richacl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_WINDOWS_H
end_ifdef

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * System-specific tweaks.  We really want to minimize these  * as much as possible, since they make it harder to understand  * the mainline code.  */
end_comment

begin_comment
comment|/* Windows (including Visual Studio and MinGW but not Cygwin) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|chdir
end_undef

begin_define
define|#
directive|define
name|chdir
value|_chdir
end_define

begin_define
define|#
directive|define
name|strdup
value|_strdup
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Visual Studio */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|<
literal|1900
end_if

begin_define
define|#
directive|define
name|snprintf
value|sprintf_s
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|warn
name|-
name|8068
end_pragma

begin_comment
comment|/* Constant out of range in comparison. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Haiku OS and QNX */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__HAIKU__
argument_list|)
operator|||
name|defined
argument_list|(
name|__QNXNTO__
argument_list|)
end_if

begin_comment
comment|/* Haiku and QNX have typedefs in stdint.h (needed for int64_t) */
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get a real definition for __FBSDID if we can */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_CDEFS_H
end_if

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If not, define it so as to avoid dangling semicolons. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FBSDID
end_ifndef

begin_define
define|#
directive|define
name|__FBSDID
parameter_list|(
name|a
parameter_list|)
value|struct _undefined_hack
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

begin_include
include|#
directive|include
file|"archive_platform_acl.h"
end_include

begin_define
define|#
directive|define
name|ARCHIVE_TEST_ACL_TYPE_POSIX1E
value|1
end_define

begin_define
define|#
directive|define
name|ARCHIVE_TEST_ACL_TYPE_NFS4
value|2
end_define

begin_include
include|#
directive|include
file|"archive_platform_xattr.h"
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
value|assertion_assert(__FILE__, __LINE__, (e), #e, NULL)
end_define

begin_comment
comment|/* chdir() and error if it fails */
end_comment

begin_define
define|#
directive|define
name|assertChdir
parameter_list|(
name|path
parameter_list|)
define|\
value|assertion_chdir(__FILE__, __LINE__, path)
end_define

begin_comment
comment|/* Assert two files have the same file flags */
end_comment

begin_define
define|#
directive|define
name|assertEqualFflags
parameter_list|(
name|patha
parameter_list|,
name|pathb
parameter_list|)
define|\
value|assertion_compare_fflags(__FILE__, __LINE__, patha, pathb, 0)
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
value|assertion_equal_int(__FILE__, __LINE__, (v1), #v1, (v2), #v2, NULL)
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
value|assertion_equal_string(__FILE__, __LINE__, (v1), #v1, (v2), #v2, NULL, 0)
end_define

begin_define
define|#
directive|define
name|assertEqualUTF8String
parameter_list|(
name|v1
parameter_list|,
name|v2
parameter_list|)
define|\
value|assertion_equal_string(__FILE__, __LINE__, (v1), #v1, (v2), #v2, NULL, 1)
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
value|assertion_equal_wstring(__FILE__, __LINE__, (v1), #v1, (v2), #v2, NULL)
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
value|assertion_equal_mem(__FILE__, __LINE__, (v1), #v1, (v2), #v2, (l), #l, NULL)
end_define

begin_comment
comment|/* Assert that memory is full of a specified byte */
end_comment

begin_define
define|#
directive|define
name|assertMemoryFilledWith
parameter_list|(
name|v1
parameter_list|,
name|l
parameter_list|,
name|b
parameter_list|)
define|\
value|assertion_memory_filled_with(__FILE__, __LINE__, (v1), #v1, (l), #l, (b), #b, NULL)
end_define

begin_comment
comment|/* Assert two files are the same. */
end_comment

begin_define
define|#
directive|define
name|assertEqualFile
parameter_list|(
name|f1
parameter_list|,
name|f2
parameter_list|)
define|\
value|assertion_equal_file(__FILE__, __LINE__, (f1), (f2))
end_define

begin_comment
comment|/* Assert that a file is empty. */
end_comment

begin_define
define|#
directive|define
name|assertEmptyFile
parameter_list|(
name|pathname
parameter_list|)
define|\
value|assertion_empty_file(__FILE__, __LINE__, (pathname))
end_define

begin_comment
comment|/* Assert that a file is not empty. */
end_comment

begin_define
define|#
directive|define
name|assertNonEmptyFile
parameter_list|(
name|pathname
parameter_list|)
define|\
value|assertion_non_empty_file(__FILE__, __LINE__, (pathname))
end_define

begin_define
define|#
directive|define
name|assertFileAtime
parameter_list|(
name|pathname
parameter_list|,
name|sec
parameter_list|,
name|nsec
parameter_list|)
define|\
value|assertion_file_atime(__FILE__, __LINE__, pathname, sec, nsec)
end_define

begin_define
define|#
directive|define
name|assertFileAtimeRecent
parameter_list|(
name|pathname
parameter_list|)
define|\
value|assertion_file_atime_recent(__FILE__, __LINE__, pathname)
end_define

begin_define
define|#
directive|define
name|assertFileBirthtime
parameter_list|(
name|pathname
parameter_list|,
name|sec
parameter_list|,
name|nsec
parameter_list|)
define|\
value|assertion_file_birthtime(__FILE__, __LINE__, pathname, sec, nsec)
end_define

begin_define
define|#
directive|define
name|assertFileBirthtimeRecent
parameter_list|(
name|pathname
parameter_list|)
define|\
value|assertion_file_birthtime_recent(__FILE__, __LINE__, pathname)
end_define

begin_comment
comment|/* Assert that a file exists; supports printf-style arguments. */
end_comment

begin_define
define|#
directive|define
name|assertFileExists
parameter_list|(
name|pathname
parameter_list|)
define|\
value|assertion_file_exists(__FILE__, __LINE__, pathname)
end_define

begin_comment
comment|/* Assert that a file exists. */
end_comment

begin_define
define|#
directive|define
name|assertFileNotExists
parameter_list|(
name|pathname
parameter_list|)
define|\
value|assertion_file_not_exists(__FILE__, __LINE__, pathname)
end_define

begin_comment
comment|/* Assert that file contents match a string. */
end_comment

begin_define
define|#
directive|define
name|assertFileContents
parameter_list|(
name|data
parameter_list|,
name|data_size
parameter_list|,
name|pathname
parameter_list|)
define|\
value|assertion_file_contents(__FILE__, __LINE__, data, data_size, pathname)
end_define

begin_comment
comment|/* Verify that a file does not contain invalid strings */
end_comment

begin_define
define|#
directive|define
name|assertFileContainsNoInvalidStrings
parameter_list|(
name|pathname
parameter_list|,
name|strings
parameter_list|)
define|\
value|assertion_file_contains_no_invalid_strings(__FILE__, __LINE__, pathname, strings)
end_define

begin_define
define|#
directive|define
name|assertFileMtime
parameter_list|(
name|pathname
parameter_list|,
name|sec
parameter_list|,
name|nsec
parameter_list|)
define|\
value|assertion_file_mtime(__FILE__, __LINE__, pathname, sec, nsec)
end_define

begin_define
define|#
directive|define
name|assertFileMtimeRecent
parameter_list|(
name|pathname
parameter_list|)
define|\
value|assertion_file_mtime_recent(__FILE__, __LINE__, pathname)
end_define

begin_define
define|#
directive|define
name|assertFileNLinks
parameter_list|(
name|pathname
parameter_list|,
name|nlinks
parameter_list|)
define|\
value|assertion_file_nlinks(__FILE__, __LINE__, pathname, nlinks)
end_define

begin_define
define|#
directive|define
name|assertFileSize
parameter_list|(
name|pathname
parameter_list|,
name|size
parameter_list|)
define|\
value|assertion_file_size(__FILE__, __LINE__, pathname, size)
end_define

begin_define
define|#
directive|define
name|assertFileMode
parameter_list|(
name|pathname
parameter_list|,
name|mode
parameter_list|)
define|\
value|assertion_file_mode(__FILE__, __LINE__, pathname, mode)
end_define

begin_define
define|#
directive|define
name|assertTextFileContents
parameter_list|(
name|text
parameter_list|,
name|pathname
parameter_list|)
define|\
value|assertion_text_file_contents(__FILE__, __LINE__, text, pathname)
end_define

begin_define
define|#
directive|define
name|assertFileContainsLinesAnyOrder
parameter_list|(
name|pathname
parameter_list|,
name|lines
parameter_list|)
define|\
value|assertion_file_contains_lines_any_order(__FILE__, __LINE__, pathname, lines)
end_define

begin_define
define|#
directive|define
name|assertIsDir
parameter_list|(
name|pathname
parameter_list|,
name|mode
parameter_list|)
define|\
value|assertion_is_dir(__FILE__, __LINE__, pathname, mode)
end_define

begin_define
define|#
directive|define
name|assertIsHardlink
parameter_list|(
name|path1
parameter_list|,
name|path2
parameter_list|)
define|\
value|assertion_is_hardlink(__FILE__, __LINE__, path1, path2)
end_define

begin_define
define|#
directive|define
name|assertIsNotHardlink
parameter_list|(
name|path1
parameter_list|,
name|path2
parameter_list|)
define|\
value|assertion_is_not_hardlink(__FILE__, __LINE__, path1, path2)
end_define

begin_define
define|#
directive|define
name|assertIsReg
parameter_list|(
name|pathname
parameter_list|,
name|mode
parameter_list|)
define|\
value|assertion_is_reg(__FILE__, __LINE__, pathname, mode)
end_define

begin_define
define|#
directive|define
name|assertIsSymlink
parameter_list|(
name|pathname
parameter_list|,
name|contents
parameter_list|)
define|\
value|assertion_is_symlink(__FILE__, __LINE__, pathname, contents)
end_define

begin_comment
comment|/* Create a directory, report error if it fails. */
end_comment

begin_define
define|#
directive|define
name|assertMakeDir
parameter_list|(
name|dirname
parameter_list|,
name|mode
parameter_list|)
define|\
value|assertion_make_dir(__FILE__, __LINE__, dirname, mode)
end_define

begin_define
define|#
directive|define
name|assertMakeFile
parameter_list|(
name|path
parameter_list|,
name|mode
parameter_list|,
name|contents
parameter_list|)
define|\
value|assertion_make_file(__FILE__, __LINE__, path, mode, -1, contents)
end_define

begin_define
define|#
directive|define
name|assertMakeBinFile
parameter_list|(
name|path
parameter_list|,
name|mode
parameter_list|,
name|csize
parameter_list|,
name|contents
parameter_list|)
define|\
value|assertion_make_file(__FILE__, __LINE__, path, mode, csize, contents)
end_define

begin_define
define|#
directive|define
name|assertMakeHardlink
parameter_list|(
name|newfile
parameter_list|,
name|oldfile
parameter_list|)
define|\
value|assertion_make_hardlink(__FILE__, __LINE__, newfile, oldfile)
end_define

begin_define
define|#
directive|define
name|assertMakeSymlink
parameter_list|(
name|newfile
parameter_list|,
name|linkto
parameter_list|)
define|\
value|assertion_make_symlink(__FILE__, __LINE__, newfile, linkto)
end_define

begin_define
define|#
directive|define
name|assertSetNodump
parameter_list|(
name|path
parameter_list|)
define|\
value|assertion_set_nodump(__FILE__, __LINE__, path)
end_define

begin_define
define|#
directive|define
name|assertUmask
parameter_list|(
name|mask
parameter_list|)
define|\
value|assertion_umask(__FILE__, __LINE__, mask)
end_define

begin_comment
comment|/* Assert that two files have unequal file flags */
end_comment

begin_define
define|#
directive|define
name|assertUnequalFflags
parameter_list|(
name|patha
parameter_list|,
name|pathb
parameter_list|)
define|\
value|assertion_compare_fflags(__FILE__, __LINE__, patha, pathb, 1)
end_define

begin_define
define|#
directive|define
name|assertUtimes
parameter_list|(
name|pathname
parameter_list|,
name|atime
parameter_list|,
name|atime_nsec
parameter_list|,
name|mtime
parameter_list|,
name|mtime_nsec
parameter_list|)
define|\
value|assertion_utimes(__FILE__, __LINE__, pathname, atime, atime_nsec, mtime, mtime_nsec)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PROGRAM
end_ifndef

begin_define
define|#
directive|define
name|assertEntrySetAcls
parameter_list|(
name|entry
parameter_list|,
name|acls
parameter_list|,
name|count
parameter_list|)
define|\
value|assertion_entry_set_acls(__FILE__, __LINE__, entry, acls, count)
end_define

begin_define
define|#
directive|define
name|assertEntryCompareAcls
parameter_list|(
name|entry
parameter_list|,
name|acls
parameter_list|,
name|count
parameter_list|,
name|type
parameter_list|,
name|mode
parameter_list|)
define|\
value|assertion_entry_compare_acls(__FILE__, __LINE__, entry, acls, count, type, mode)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This would be simple with C99 variadic macros, but I don't want to  * require that.  Instead, I insert a function call before each  * skipping() call to pass the file and line information down.  Crude,  * but effective.  */
end_comment

begin_define
define|#
directive|define
name|skipping
define|\
value|skipping_setup(__FILE__, __LINE__);test_skipping
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
name|int
name|assertion_assert
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
name|assertion_chdir
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_compare_fflags
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
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_empty_file
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_equal_file
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_equal_int
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|long
name|long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|long
name|long
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
name|assertion_equal_mem
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|void
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
name|assertion_memory_filled_with
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|void
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
name|char
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
name|assertion_equal_string
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
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_equal_wstring
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
name|assertion_file_atime
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
name|long
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_file_atime_recent
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_file_birthtime
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
name|long
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_file_birthtime_recent
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_file_contains_lines_any_order
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
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_file_contains_no_invalid_strings
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
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_file_contents
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_file_exists
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_file_mode
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
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_file_mtime
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
name|long
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_file_mtime_recent
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_file_nlinks
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
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_file_not_exists
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_file_size
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
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_is_dir
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
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_is_hardlink
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_is_not_hardlink
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_is_reg
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
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_is_symlink
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_make_dir
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
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_make_file
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
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_make_hardlink
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
name|newpath
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_make_symlink
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
name|newpath
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_non_empty_file
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_set_nodump
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_text_file_contents
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
name|buff
parameter_list|,
specifier|const
name|char
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_umask
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_utimes
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
name|long
parameter_list|,
name|long
parameter_list|,
name|long
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|assertion_version
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|skipping_setup
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
comment|/* Delay until time() returns a value after this. */
end_comment

begin_function_decl
name|void
name|sleepUntilAfter
parameter_list|(
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if this platform can create symlinks. */
end_comment

begin_function_decl
name|int
name|canSymlink
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if this platform can run the "bzip2" program. */
end_comment

begin_function_decl
name|int
name|canBzip2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if this platform can run the "grzip" program. */
end_comment

begin_function_decl
name|int
name|canGrzip
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if this platform can run the "gzip" program. */
end_comment

begin_function_decl
name|int
name|canGzip
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if this platform can run the specified command. */
end_comment

begin_function_decl
name|int
name|canRunCommand
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if this platform can run the "lrzip" program. */
end_comment

begin_function_decl
name|int
name|canLrzip
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if this platform can run the "lz4" program. */
end_comment

begin_function_decl
name|int
name|canLz4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if this platform can run the "zstd" program. */
end_comment

begin_function_decl
name|int
name|canZstd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if this platform can run the "lzip" program. */
end_comment

begin_function_decl
name|int
name|canLzip
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if this platform can run the "lzma" program. */
end_comment

begin_function_decl
name|int
name|canLzma
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if this platform can run the "lzop" program. */
end_comment

begin_function_decl
name|int
name|canLzop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if this platform can run the "xz" program. */
end_comment

begin_function_decl
name|int
name|canXz
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if this filesystem can handle nodump flags. */
end_comment

begin_function_decl
name|int
name|canNodump
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set test ACLs */
end_comment

begin_function_decl
name|int
name|setTestAcl
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get extended attribute */
end_comment

begin_function_decl
name|void
modifier|*
name|getXattr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set extended attribute */
end_comment

begin_function_decl
name|int
name|setXattr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if the file has large i-node number(>0xffffffff). */
end_comment

begin_function_decl
name|int
name|is_LargeInode
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|ARCHIVE_ACL_SUNOS
end_if

begin_comment
comment|/* Fetch ACLs on Solaris using acl() or facl() */
end_comment

begin_function_decl
name|void
modifier|*
name|sunacl_get
parameter_list|(
name|int
name|cmd
parameter_list|,
name|int
modifier|*
name|aclcnt
parameter_list|,
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Dump block of bytes to a file. */
end_comment

begin_function_decl
name|void
name|dumpfile
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
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
comment|/* Copies named reference file to the current directory. */
end_comment

begin_function_decl
name|void
name|copy_reference_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Extracts a list of files to the current directory.  * List must be NULL terminated.  */
end_comment

begin_function_decl
name|void
name|extract_reference_files
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Subtract umask from mode */
end_comment

begin_function_decl
name|mode_t
name|umasked
parameter_list|(
name|mode_t
name|expected_mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Path to working directory for current test */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|testworkdir
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|PROGRAM
end_ifndef

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
comment|/* ACL structure */
end_comment

begin_struct
struct|struct
name|archive_test_acl_t
block|{
name|int
name|type
decl_stmt|;
comment|/* Type of ACL */
name|int
name|permset
decl_stmt|;
comment|/* Permissions for this class of users. */
name|int
name|tag
decl_stmt|;
comment|/* Owner, User, Owning group, group, other, etc. */
name|int
name|qual
decl_stmt|;
comment|/* GID or UID of user/group, depending on tag. */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of user/group, depending on tag. */
block|}
struct|;
end_struct

begin_comment
comment|/* Set ACLs */
end_comment

begin_function_decl
name|int
name|assertion_entry_set_acls
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|archive_entry
modifier|*
parameter_list|,
name|struct
name|archive_test_acl_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compare ACLs */
end_comment

begin_function_decl
name|int
name|assertion_entry_compare_acls
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|archive_entry
modifier|*
parameter_list|,
name|struct
name|archive_test_acl_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

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
specifier|const
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
comment|/* _minimal version exercises a slightly different set of libarchive APIs. */
end_comment

begin_function_decl
name|int
name|read_open_memory_minimal
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
specifier|const
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
comment|/* _seek version produces a seekable file. */
end_comment

begin_function_decl
name|int
name|read_open_memory_seek
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
specifier|const
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
comment|/* Versions of above that accept an archive argument for additional info. */
end_comment

begin_define
define|#
directive|define
name|assertA
parameter_list|(
name|e
parameter_list|)
value|assertion_assert(__FILE__, __LINE__, (e), #e, (a))
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
value|assertion_equal_int(__FILE__, __LINE__, (v1), #v1, (v2), #v2, (a))
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
value|assertion_equal_string(__FILE__, __LINE__, (v1), #v1, (v2), #v2, (a), 0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(PROGRAM) */
end_comment

begin_comment
comment|/*  * Special interfaces for program test harness.  */
end_comment

begin_comment
comment|/* Pathname of exe to be tested. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|testprogfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of exe to use in printf-formatted command strings. */
end_comment

begin_comment
comment|/* On Windows, this includes leading/trailing quotes. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|testprog
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|assertVersion
parameter_list|(
specifier|const
name|char
modifier|*
name|prog
parameter_list|,
specifier|const
name|char
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(PROGRAM) */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TEST_COMMON_H */
end_comment

end_unit

