begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* common definitions for `patch' */
end_comment

begin_comment
comment|/* $Id: common.h,v 1.18 1997/06/13 06:28:37 eggert Exp $ */
end_comment

begin_comment
comment|/* Copyright 1986, 1988 Larry Wall Copyright 1990, 1991, 1992, 1993, 1997 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; see the file COPYING. If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUGGING
end_ifndef

begin_define
define|#
directive|define
name|DEBUGGING
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We must define `volatile' and `const' first (the latter inside config.h),    so that they're used consistently in all system includes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|volatile
end_ifndef

begin_define
define|#
directive|define
name|volatile
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
comment|/* Enable support for fseeko and ftello on hosts    where it is available but is turned off by default.    This must be defined before any system file is included.  */
end_comment

begin_define
define|#
directive|define
name|_LARGEFILE_SOURCE
value|1
end_define

begin_include
include|#
directive|include
file|<config.h>
end_include

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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
name|S_ISDIR
operator|&&
name|defined
name|S_IFDIR
end_if

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|S_ISREG
operator|&&
name|defined
name|S_IFREG
end_if

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IXOTH
end_ifndef

begin_define
define|#
directive|define
name|S_IXOTH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWOTH
end_ifndef

begin_define
define|#
directive|define
name|S_IWOTH
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IROTH
end_ifndef

begin_define
define|#
directive|define
name|S_IROTH
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IXGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IXGRP
value|(S_IXOTH<< 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IWGRP
value|(S_IWOTH<< 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IRGRP
value|(S_IROTH<< 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IXUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IXUSR
value|(S_IXOTH<< 6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IWUSR
value|(S_IWOTH<< 6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IRUSR
value|(S_IROTH<< 6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_LIMITS_H
end_if

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT_MAX
end_ifndef

begin_define
define|#
directive|define
name|INT_MAX
value|2147483647
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_MIN
end_ifndef

begin_define
define|#
directive|define
name|LONG_MIN
value|(-1-2147483647L)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_comment
comment|/* CTYPE_DOMAIN (C) is nonzero if the unsigned char C can safely be given    as an argument to<ctype.h> macros like `isspace'.  */
end_comment

begin_if
if|#
directive|if
name|STDC_HEADERS
end_if

begin_define
define|#
directive|define
name|CTYPE_DOMAIN
parameter_list|(
name|c
parameter_list|)
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CTYPE_DOMAIN
parameter_list|(
name|c
parameter_list|)
value|((unsigned) (c)<= 0177)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISSPACE
end_ifndef

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|c
parameter_list|)
value|(CTYPE_DOMAIN (c)&& isspace (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISDIGIT
end_ifndef

begin_define
define|#
directive|define
name|ISDIGIT
parameter_list|(
name|c
parameter_list|)
value|((unsigned) (c) - '0'<= 9)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FILESYSTEM_PREFIX_LEN
end_ifndef

begin_define
define|#
directive|define
name|FILESYSTEM_PREFIX_LEN
parameter_list|(
name|f
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISSLASH
end_ifndef

begin_define
define|#
directive|define
name|ISSLASH
parameter_list|(
name|c
parameter_list|)
value|((c) == '/')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* constants */
end_comment

begin_comment
comment|/* AIX predefines these.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRUE
end_ifdef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FALSE
end_ifdef

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_comment
comment|/* handy definitions */
end_comment

begin_define
define|#
directive|define
name|strEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(!strcmp(s1, s2))
end_define

begin_define
define|#
directive|define
name|strnEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(!strncmp(s1, s2, l))
end_define

begin_comment
comment|/* typedefs */
end_comment

begin_typedef
typedef|typedef
name|int
name|bool
typedef|;
end_typedef

begin_comment
comment|/* must promote to itself */
end_comment

begin_typedef
typedef|typedef
name|long
name|LINENUM
typedef|;
end_typedef

begin_comment
comment|/* must be signed */
end_comment

begin_comment
comment|/* globals */
end_comment

begin_decl_stmt
specifier|extern
name|char
specifier|const
name|program_name
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* general purpose buffer */
end_comment

begin_decl_stmt
name|XTERN
name|size_t
name|bufsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* allocated size of buf */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|using_plan_a
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* try to keep everything in memory */
end_comment

begin_decl_stmt
name|XTERN
name|char
modifier|*
name|inname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|char
modifier|*
name|outfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|int
name|inerrno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|int
name|invc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|struct
name|stat
name|instat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|bool
name|dry_run
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|bool
name|posixly_correct
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|char
specifier|const
modifier|*
name|origprae
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|char
specifier|const
modifier|*
name|origbase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|char
specifier|const
modifier|*
specifier|volatile
name|TMPOUTNAME
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|char
specifier|const
modifier|*
specifier|volatile
name|TMPINNAME
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|char
specifier|const
modifier|*
specifier|volatile
name|TMPPATNAME
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_decl_stmt
name|XTERN
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|debug
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|XTERN
name|bool
name|force
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|bool
name|batch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|bool
name|noreverse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|int
name|reverse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|enum
type|{
name|DEFAULT_VERBOSITY
decl_stmt|,
name|SILENT
decl_stmt|,
name|VERBOSE
end_decl_stmt

begin_empty_stmt
unit|} verbosity
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|XTERN
name|bool
name|skip_rest_of_patch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|int
name|strippath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|bool
name|canonicalize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|int
name|patch_get
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|int
name|set_time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|int
name|set_utc
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|diff
block|{
name|NO_DIFF
block|,
name|CONTEXT_DIFF
block|,
name|NORMAL_DIFF
block|,
name|ED_DIFF
block|,
name|NEW_CONTEXT_DIFF
block|,
name|UNI_DIFF
block|}
enum|;
end_enum

begin_decl_stmt
name|XTERN
name|enum
name|diff
name|diff_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|char
modifier|*
name|revision
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prerequisite revision, if any */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|GENERIC_OBJECT
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GENERIC_OBJECT
value|char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|6
operator|)
operator|||
name|__STRICT_ANSI__
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PARAMS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|GENERIC_OBJECT
modifier|*
name|xmalloc
name|PARAMS
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fatal_exit
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
operator|!
name|STDC_HEADERS
operator|&&
operator|!
name|defined
name|errno
end_if

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|STDC_HEADERS
operator|||
name|HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|HAVE_MEMCHR
end_if

begin_define
define|#
directive|define
name|memcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|bcmp (s1, s2, n)
end_define

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|bcopy (s, d, n)
end_define

begin_function_decl
name|GENERIC_OBJECT
modifier|*
name|memchr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|STDC_HEADERS
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
name|long
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|GENERIC_OBJECT
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|GENERIC_OBJECT
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|lseek
end_ifndef

begin_function_decl
name|off_t
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDIN_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDOUT_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDERR_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_LFS_LARGEFILE
end_if

begin_typedef
typedef|typedef
name|off_t
name|file_offset
typedef|;
end_typedef

begin_define
define|#
directive|define
name|file_seek
value|fseeko
end_define

begin_define
define|#
directive|define
name|file_tell
value|ftello
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|long
name|file_offset
typedef|;
end_typedef

begin_define
define|#
directive|define
name|file_seek
value|fseek
end_define

begin_define
define|#
directive|define
name|file_tell
value|ftell
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_FCNTL_H
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_RDONLY
end_ifndef

begin_define
define|#
directive|define
name|O_RDONLY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_WRONLY
end_ifndef

begin_define
define|#
directive|define
name|O_WRONLY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_RDWR
end_ifndef

begin_define
define|#
directive|define
name|O_RDWR
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_O_BINARY
end_ifndef

begin_define
define|#
directive|define
name|_O_BINARY
value|0
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
value|_O_BINARY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_CREAT
end_ifndef

begin_define
define|#
directive|define
name|O_CREAT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_TRUNC
end_ifndef

begin_define
define|#
directive|define
name|O_TRUNC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SETMODE
end_if

begin_decl_stmt
name|XTERN
name|int
name|binary_transput
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* O_BINARY if binary i/o is desired */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|binary_transput
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL_DEVICE
end_ifndef

begin_define
define|#
directive|define
name|NULL_DEVICE
value|"/dev/null"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TTY_DEVICE
end_ifndef

begin_define
define|#
directive|define
name|TTY_DEVICE
value|"/dev/tty"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

