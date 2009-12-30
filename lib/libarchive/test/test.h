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

begin_define
define|#
directive|define
name|LOCALE_UTF8
value|NULL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOCALE_UTF8
value|"de_DE.UTF-8"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Visual Studio */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

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
comment|/* Cygwin */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_comment
comment|/* Cygwin-1.7.x is lazy about populating nlinks, so don't  * expect it to be accurate. */
end_comment

begin_define
define|#
directive|define
name|NLINKS_INACCURATE_FOR_DIRS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Haiku OS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__HAIKU__
argument_list|)
end_if

begin_comment
comment|/* Haiku has typedefs in stdint.h (needed for int64_t) */
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
value|assertion_equal_string(__FILE__, __LINE__, (v1), #v1, (v2), #v2, NULL)
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
comment|/* Assert two files are the same; allow printf-style expansion of second name.  * See below for comments about variable arguments here...  */
end_comment

begin_define
define|#
directive|define
name|assertEqualFile
define|\
value|assertion_setup(__FILE__, __LINE__);assertion_equal_file
end_define

begin_comment
comment|/* Assert that a file is empty; supports printf-style arguments. */
end_comment

begin_define
define|#
directive|define
name|assertEmptyFile
define|\
value|assertion_setup(__FILE__, __LINE__);assertion_empty_file
end_define

begin_comment
comment|/* Assert that a file is not empty; supports printf-style arguments. */
end_comment

begin_define
define|#
directive|define
name|assertNonEmptyFile
define|\
value|assertion_setup(__FILE__, __LINE__);assertion_non_empty_file
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
define|\
value|assertion_setup(__FILE__, __LINE__);assertion_file_exists
end_define

begin_comment
comment|/* Assert that a file exists; supports printf-style arguments. */
end_comment

begin_define
define|#
directive|define
name|assertFileNotExists
define|\
value|assertion_setup(__FILE__, __LINE__);assertion_file_not_exists
end_define

begin_comment
comment|/* Assert that file contents match a string; supports printf-style arguments. */
end_comment

begin_define
define|#
directive|define
name|assertFileContents
define|\
value|assertion_setup(__FILE__, __LINE__);assertion_file_contents
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
name|assertTextFileContents
define|\
value|assertion_setup(__FILE__, __LINE__);assertion_text_file_contents
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
value|assertion_make_file(__FILE__, __LINE__, path, mode, contents)
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
name|assertUmask
parameter_list|(
name|mask
parameter_list|)
define|\
value|assertion_umask(__FILE__, __LINE__, mask)
end_define

begin_comment
comment|/*  * This would be simple with C99 variadic macros, but I don't want to  * require that.  Instead, I insert a function call before each  * skipping() call to pass the file and line information down.  Crude,  * but effective.  */
end_comment

begin_define
define|#
directive|define
name|skipping
define|\
value|assertion_setup(__FILE__, __LINE__);test_skipping
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
name|assertion_empty_file
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
name|assertion_equal_file
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
name|assertion_file_contents
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
name|assertion_file_exists
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
modifier|...
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
specifier|const
name|char
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
modifier|...
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
name|void
name|assertion_setup
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
comment|/* Return true if this platform can run the "gunzip" program. */
end_comment

begin_function_decl
name|int
name|canGunzip
parameter_list|(
name|void
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
comment|/* "2" version exercises a slightly different set of libarchive APIs. */
end_comment

begin_function_decl
name|int
name|read_open_memory2
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
value|assertion_equal_string(__FILE__, __LINE__, (v1), #v1, (v2), #v2, (a))
end_define

end_unit

