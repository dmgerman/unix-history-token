begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* System dependent declarations.    Copyright (C) 1988, 1989, 1992, 1993, 1994 Free Software Foundation, Inc.  This file is part of GNU DIFF.  GNU DIFF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU DIFF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU DIFF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* We must define `volatile' and `const' first (the latter inside config.h),    so that they're used consistently in all system includes.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|__STDC__
end_if

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

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_define
define|#
directive|define
name|VOID
value|void
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

begin_define
define|#
directive|define
name|VOID
value|char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|STAT_MACROS_BROKEN
end_if

begin_undef
undef|#
directive|undef
name|S_ISBLK
end_undef

begin_undef
undef|#
directive|undef
name|S_ISCHR
end_undef

begin_undef
undef|#
directive|undef
name|S_ISDIR
end_undef

begin_undef
undef|#
directive|undef
name|S_ISFIFO
end_undef

begin_undef
undef|#
directive|undef
name|S_ISREG
end_undef

begin_undef
undef|#
directive|undef
name|S_ISSOCK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISREG
end_ifndef

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFMT) == S_IFREG)
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
argument_list|(
name|S_ISBLK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFBLK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFMT) == S_IFBLK)
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
argument_list|(
name|S_ISCHR
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFCHR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFMT) == S_IFCHR)
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
argument_list|(
name|S_ISFIFO
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFFIFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFMT) == S_IFFIFO)
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
argument_list|(
name|S_ISSOCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFSOCK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFMT) == S_IFSOCK)
end_define

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
name|SEEK_CUR
end_ifndef

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
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
name|HAVE_TIME_H
end_if

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

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

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_FILE_H
end_if

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

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
operator|!
name|HAVE_DUP2
end_if

begin_define
define|#
directive|define
name|dup2
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|(close (t),  fcntl (f,F_DUPFD,t))
end_define

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

begin_if
if|#
directive|if
name|HAVE_SYS_WAIT_H
end_if

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WEXITSTATUS
end_ifndef

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|stat_val
parameter_list|)
value|((unsigned) (stat_val)>> 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WIFEXITED
end_ifndef

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|stat_val
parameter_list|)
value|(((stat_val)& 255) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAT_BLOCKSIZE
end_ifndef

begin_if
if|#
directive|if
name|HAVE_ST_BLKSIZE
end_if

begin_define
define|#
directive|define
name|STAT_BLOCKSIZE
parameter_list|(
name|s
parameter_list|)
value|(s).st_blksize
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STAT_BLOCKSIZE
parameter_list|(
name|s
parameter_list|)
value|(8 * 1024)
end_define

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
name|HAVE_DIRENT_H
end_if

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_define
define|#
directive|define
name|NAMLEN
parameter_list|(
name|dirent
parameter_list|)
value|strlen((dirent)->d_name)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dirent
value|direct
end_define

begin_define
define|#
directive|define
name|NAMLEN
parameter_list|(
name|dirent
parameter_list|)
value|((dirent)->d_namlen)
end_define

begin_if
if|#
directive|if
name|HAVE_SYS_NDIR_H
end_if

begin_include
include|#
directive|include
file|<sys/ndir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_DIR_H
end_if

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_NDIR_H
end_if

begin_include
include|#
directive|include
file|<ndir.h>
end_include

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
name|HAVE_VFORK_H
end_if

begin_include
include|#
directive|include
file|<vfork.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STDLIB_H
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
name|VOID
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|VOID
modifier|*
name|realloc
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
name|getenv
end_ifndef

begin_function_decl
name|char
modifier|*
name|getenv
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
name|CHAR_BIT
end_ifndef

begin_define
define|#
directive|define
name|CHAR_BIT
value|8
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|bzero
end_ifndef

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|memset (s, 0, n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|HAVE_STRCHR
end_if

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|strchr
argument_list|()
decl_stmt|,
modifier|*
name|strrchr
argument_list|()
decl_stmt|;
end_decl_stmt

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
name|void
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
name|ISPRINT
end_ifndef

begin_define
define|#
directive|define
name|ISPRINT
parameter_list|(
name|c
parameter_list|)
value|(CTYPE_DOMAIN (c)&& isprint (c))
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
name|ISUPPER
end_ifndef

begin_define
define|#
directive|define
name|ISUPPER
parameter_list|(
name|c
parameter_list|)
value|(CTYPE_DOMAIN (c)&& isupper (c))
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

begin_ifdef
ifdef|#
directive|ifdef
name|min
end_ifdef

begin_undef
undef|#
directive|undef
name|min
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|max
end_ifdef

begin_undef
undef|#
directive|undef
name|max
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)<= (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>= (b) ? (a) : (b))
end_define

begin_escape
end_escape

begin_comment
comment|/* This section contains Posix-compliant defaults for macros    that are meant to be overridden by hand in config.h as needed.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|filename_cmp
end_ifndef

begin_define
define|#
directive|define
name|filename_cmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strcmp (a, b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|filename_lastdirchar
end_ifndef

begin_define
define|#
directive|define
name|filename_lastdirchar
parameter_list|(
name|filename
parameter_list|)
value|strrchr (filename, '/')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FORK
end_ifndef

begin_define
define|#
directive|define
name|HAVE_FORK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETMODE
end_ifndef

begin_define
define|#
directive|define
name|HAVE_SETMODE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|initialize_main
end_ifndef

begin_define
define|#
directive|define
name|initialize_main
parameter_list|(
name|argcp
parameter_list|,
name|argvp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Do struct stat *S, *T describe the same file?  Answer -1 if unknown.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|same_file
end_ifndef

begin_define
define|#
directive|define
name|same_file
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|((s)->st_ino==(t)->st_ino&& (s)->st_dev==(t)->st_dev)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Place into Q a quoted version of A suitable for `popen' or `system',    incrementing Q and junking A.    Do not increment Q by more than 4 * strlen (A) + 2.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYSTEM_QUOTE_ARG
end_ifndef

begin_define
define|#
directive|define
name|SYSTEM_QUOTE_ARG
parameter_list|(
name|q
parameter_list|,
name|a
parameter_list|)
define|\
value|{ \     *(q)++ = '\''; \     for (;  *(a);  *(q)++ = *(a)++) \       if (*(a) == '\'') \ 	{ \ 	  *(q)++ = '\''; \ 	  *(q)++ = '\\'; \ 	  *(q)++ = '\''; \ 	} \     *(q)++ = '\''; \   }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

