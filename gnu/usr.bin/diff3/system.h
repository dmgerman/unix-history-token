begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* System dependent declarations.    Copyright (C) 1988, 1989, 1992, 1993 Free Software Foundation, Inc.  This file is part of GNU DIFF.  GNU DIFF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU DIFF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU DIFF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

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

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

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

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_VERSION
end_ifndef

begin_comment
comment|/* Prevent the NeXT prototype using union wait from causing problems.  */
end_comment

begin_define
define|#
directive|define
name|wait
value|system_wait
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_VERSION
end_ifndef

begin_undef
undef|#
directive|undef
name|wait
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_WAIT_H */
end_comment

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
value|((unsigned)(stat_val)>> 8)
end_define

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_comment
comment|/* Avoid 4.3BSD incompatibility with Posix.  */
end_comment

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
value|(S_ISREG ((s).st_mode) ? 8192 : 4096)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|DIRENT
operator|||
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
end_if

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|direct
end_ifdef

begin_undef
undef|#
directive|undef
name|direct
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|direct
value|dirent
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! (DIRENT || defined (_POSIX_VERSION)) */
end_comment

begin_if
if|#
directive|if
name|SYSNDIR
end_if

begin_include
include|#
directive|include
file|<sys/ndir.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|SYSDIR
end_if

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! (DIRENT || defined (_POSIX_VERSION)) */
end_comment

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
name|HAVE_STRING_H
operator|||
name|STDC_HEADERS
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|index
end_ifndef

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|rindex
end_ifndef

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bcopy
end_ifndef

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|)
value|memcpy (d,s,n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bcmp
end_ifndef

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|memcmp (s1,s2,n)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|memset (s,0,n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_MEMCHR
operator|&&
operator|!
name|STDC_HEADERS
end_if

begin_function_decl
name|char
modifier|*
name|memchr
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
name|STDC_HEADERS
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|__GNUC__
end_if

begin_include
include|#
directive|include
file|"limits.h"
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INT_MAX
value|2147483647
end_define

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

begin_if
if|#
directive|if
operator|!
name|__STDC__
end_if

begin_define
define|#
directive|define
name|volatile
end_define

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

end_unit

