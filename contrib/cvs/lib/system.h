begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* system-dependent definitions for CVS.    Copyright (C) 1989-1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|STAT_MACROS_BROKEN
end_ifdef

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
name|S_ISREG
end_undef

begin_undef
undef|#
directive|undef
name|S_ISFIFO
end_undef

begin_undef
undef|#
directive|undef
name|S_ISLNK
end_undef

begin_undef
undef|#
directive|undef
name|S_ISSOCK
end_undef

begin_undef
undef|#
directive|undef
name|S_ISMPB
end_undef

begin_undef
undef|#
directive|undef
name|S_ISMPC
end_undef

begin_undef
undef|#
directive|undef
name|S_ISNWK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Not all systems have S_IFMT, but we want to use it if we have it.    The S_IFMT code below looks right (it masks and compares).  The    non-S_IFMT code looks bogus (are there really systems on which    S_IFBLK, S_IFLNK,&c, each have their own bit?  I suspect it was    written for OS/2 using the IBM C/C++ Tools 2.01 compiler).     Of course POSIX systems will have S_IS*, so maybe the issue is    semi-moot.  */
end_comment

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFMT
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFBLK)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|m
parameter_list|)
value|((m)& S_IFBLK)
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFMT
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFCHR)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
value|((m)& S_IFCHR)
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
operator|!
name|defined
argument_list|(
name|S_ISDIR
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFDIR
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFMT
argument_list|)
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|((m)& S_IFDIR)
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
operator|!
name|defined
argument_list|(
name|S_ISREG
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFREG
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFMT
argument_list|)
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|((m)& S_IFREG)
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
operator|!
name|defined
argument_list|(
name|S_ISFIFO
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFIFO
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFMT
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFIFO)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|((m)& S_IFIFO)
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
operator|!
name|defined
argument_list|(
name|S_ISLNK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFLNK
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFMT
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFLNK)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|((m)& S_IFLNK)
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFMT
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFSOCK)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|((m)& S_IFSOCK)
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
operator|!
name|defined
argument_list|(
name|S_ISMPB
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFMPB
argument_list|)
end_if

begin_comment
comment|/* V7 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFMT
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISMPB
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFMPB)
end_define

begin_define
define|#
directive|define
name|S_ISMPC
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFMPC)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISMPB
parameter_list|(
name|m
parameter_list|)
value|((m)& S_IFMPB)
end_define

begin_define
define|#
directive|define
name|S_ISMPC
parameter_list|(
name|m
parameter_list|)
value|((m)& S_IFMPC)
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
operator|!
name|defined
argument_list|(
name|S_ISNWK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFNWK
argument_list|)
end_if

begin_comment
comment|/* HP/UX */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFMT
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISNWK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFNWK)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISNWK
parameter_list|(
name|m
parameter_list|)
value|((m)& S_IFNWK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECOY_PERMISSIONS
end_ifdef

begin_comment
comment|/* OS/2, really */
end_comment

begin_define
define|#
directive|define
name|S_IRUSR
value|S_IREAD
end_define

begin_define
define|#
directive|define
name|S_IWUSR
value|S_IWRITE
end_define

begin_define
define|#
directive|define
name|S_IXUSR
value|S_IEXEC
end_define

begin_define
define|#
directive|define
name|S_IRWXU
value|(S_IRUSR | S_IWUSR | S_IXUSR)
end_define

begin_define
define|#
directive|define
name|S_IRGRP
value|S_IREAD
end_define

begin_define
define|#
directive|define
name|S_IWGRP
value|S_IWRITE
end_define

begin_define
define|#
directive|define
name|S_IXGRP
value|S_IEXEC
end_define

begin_define
define|#
directive|define
name|S_IRWXG
value|(S_IRGRP | S_IWGRP | S_IXGRP)
end_define

begin_define
define|#
directive|define
name|S_IROTH
value|S_IREAD
end_define

begin_define
define|#
directive|define
name|S_IWOTH
value|S_IWRITE
end_define

begin_define
define|#
directive|define
name|S_IXOTH
value|S_IEXEC
end_define

begin_define
define|#
directive|define
name|S_IRWXO
value|(S_IROTH | S_IWOTH | S_IXOTH)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! NEED_DECOY_PERMISSIONS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IRUSR
value|0400
end_define

begin_define
define|#
directive|define
name|S_IWUSR
value|0200
end_define

begin_define
define|#
directive|define
name|S_IXUSR
value|0100
end_define

begin_comment
comment|/* Read, write, and execute by owner.  */
end_comment

begin_define
define|#
directive|define
name|S_IRWXU
value|(S_IRUSR|S_IWUSR|S_IXUSR)
end_define

begin_define
define|#
directive|define
name|S_IRGRP
value|(S_IRUSR>> 3)
end_define

begin_comment
comment|/* Read by group.  */
end_comment

begin_define
define|#
directive|define
name|S_IWGRP
value|(S_IWUSR>> 3)
end_define

begin_comment
comment|/* Write by group.  */
end_comment

begin_define
define|#
directive|define
name|S_IXGRP
value|(S_IXUSR>> 3)
end_define

begin_comment
comment|/* Execute by group.  */
end_comment

begin_comment
comment|/* Read, write, and execute by group.  */
end_comment

begin_define
define|#
directive|define
name|S_IRWXG
value|(S_IRWXU>> 3)
end_define

begin_define
define|#
directive|define
name|S_IROTH
value|(S_IRGRP>> 3)
end_define

begin_comment
comment|/* Read by others.  */
end_comment

begin_define
define|#
directive|define
name|S_IWOTH
value|(S_IWGRP>> 3)
end_define

begin_comment
comment|/* Write by others.  */
end_comment

begin_define
define|#
directive|define
name|S_IXOTH
value|(S_IXGRP>> 3)
end_define

begin_comment
comment|/* Execute by others.  */
end_comment

begin_comment
comment|/* Read, write, and execute by others.  */
end_comment

begin_define
define|#
directive|define
name|S_IRWXO
value|(S_IRWXG>> 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !def S_IRUSR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_DECOY_PERMISSIONS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|POSIX
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_UNISTD_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unistd.h>
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
name|off_t
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getcwd
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
name|TIME_WITH_SYS_TIME
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|HAVE_DIRECT_H
end_ifdef

begin_include
include|#
directive|include
file|<direct.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|timezone
end_ifdef

begin_undef
undef|#
directive|undef
name|timezone
end_undef

begin_comment
comment|/* needed for sgi */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIMEB_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|timeb
block|{
name|time_t
name|time
decl_stmt|;
comment|/* Seconds since the epoch	*/
name|unsigned
name|short
name|millitm
decl_stmt|;
comment|/* Field not used		*/
name|short
name|timezone
decl_stmt|;
name|short
name|dstflag
decl_stmt|;
comment|/* Field not used		*/
block|}
struct|;
end_struct

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
name|HAVE_FTIME
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_TIMEZONE
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|timezone
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|long
name|timezone
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  MAXPATHLEN and PATH_MAX ** **     On most systems MAXPATHLEN is defined in sys/param.h to be 1024. Of **     those that this is not true, again most define PATH_MAX in limits.h **     or sys/limits.h which usually gets included by limits.h. On the few **     remaining systems that neither statement is true, _POSIX_PATH_MAX  **     is defined. ** **     So: **         1. If PATH_MAX is defined just use it. **         2. If MAXPATHLEN is defined but not PATH_MAX, then define **            PATH_MAX in terms of MAXPATHLEN. **         3. If neither is defined, include limits.h and check for **            PATH_MAX again. **         3.1 If we now have PATHSIZE, define PATH_MAX in terms of that. **             and ignore the rest.  Since _POSIX_PATH_MAX (checked for **             next) is the *most* restrictive (smallest) value, if we **             trust _POSIX_PATH_MAX, several of our buffers are too small. **         4. If PATH_MAX is still not defined but _POSIX_PATH_MAX is, **            then define PATH_MAX in terms of _POSIX_PATH_MAX. **         5. And if even _POSIX_PATH_MAX doesn't exist just put in **            a reasonable value. **         *. All in all, this is an excellent argument for using pathconf() **            when at all possible.  Or better yet, dynamically allocate **            our buffers and use getcwd() not getwd(). ** **     This works on: **         Sun Sparc 10        SunOS 4.1.3&  Solaris 1.2 **         HP 9000/700         HP/UX 8.07&  HP/UX 9.01 **         Tektronix XD88/10   UTekV 3.2e **         IBM RS6000          AIX 3.2 **         Dec Alpha           OSF 1 ???? **         Intel 386           BSDI BSD/386 **         Intel 386           SCO OpenServer Release 5 **         Apollo              Domain 10.4 **         NEC                 SVR4 */
end_comment

begin_comment
comment|/* On MOST systems this will get you MAXPATHLEN.    Windows NT doesn't have this file, tho.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_MAX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MAXPATHLEN
end_ifdef

begin_define
define|#
directive|define
name|PATH_MAX
value|MAXPATHLEN
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_MAX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PATHSIZE
end_ifdef

begin_define
define|#
directive|define
name|PATH_MAX
value|PATHSIZE
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no PATHSIZE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_PATH_MAX
end_ifdef

begin_define
define|#
directive|define
name|PATH_MAX
value|_POSIX_PATH_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PATH_MAX
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no _POSIX_PATH_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no PATHSIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no PATH_MAX   */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXPATHLEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PATH_MAX   */
end_comment

begin_comment
comment|/* The NeXT (without _POSIX_SOURCE, which we don't want) has a utime.h    which doesn't define anything.  It would be cleaner to have configure    check for struct utimbuf, but for now I'm checking NeXT here (so I don't    have to debug the configure check across all the machines).  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_UTIME_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NeXT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<utime.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_UTIME_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/utime.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|ALTOS
end_ifndef

begin_struct
struct|struct
name|utimbuf
block|{
name|long
name|actime
decl_stmt|;
name|long
name|modtime
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|utime
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
file|<string.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|ERRNO_H_MISSING
end_ifndef

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Not all systems set the same error code on a non-existent-file    error.  This tries to ask the question somewhat portably.    On systems that don't have ENOTEXIST, this should behave just like    x == ENOENT.  "x" is probably errno, of course. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ENOTEXIST
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|EOS2ERR
end_ifdef

begin_define
define|#
directive|define
name|existence_error
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x) == ENOTEXIST) || ((x) == ENOENT) || ((x) == EOS2ERR))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|existence_error
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x) == ENOTEXIST) || ((x) == ENOENT))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|EVMSERR
end_ifdef

begin_define
define|#
directive|define
name|existence_error
parameter_list|(
name|x
parameter_list|)
define|\
value|((x) == ENOENT || (x) == EINVAL || (x) == EVMSERR)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|existence_error
parameter_list|(
name|x
parameter_list|)
value|((x) == ENOENT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
end_ifdef

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

begin_function_decl
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

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

begin_comment
comment|/* SunOS4 apparently does not define this in stdlib.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_FAILURE
end_ifndef

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* check for POSIX signals */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SIGACTION
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SIGPROCMASK
argument_list|)
end_if

begin_define
define|#
directive|define
name|POSIX_SIGNALS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIX 1.6 doesn't properly support sigaction */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MINIX
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|POSIX_SIGNALS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If !POSIX, try for BSD.. Reason: 4.4BSD implements these as wrappers */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|POSIX_SIGNALS
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SIGVEC
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SIGSETMASK
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SIGBLOCK
argument_list|)
end_if

begin_define
define|#
directive|define
name|BSD_SIGNALS
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
comment|/* Under OS/2, this must be included _after_ stdio.h; that's why we do    it here. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_OWN_TCPIP_H
end_ifdef

begin_include
include|#
directive|include
file|"tcpip.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FCNTL_H
end_ifdef

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

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|F_OK
end_ifndef

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

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
value|(dirent)->d_namlen
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

begin_comment
comment|/* Convert B 512-byte blocks to kilobytes if K is nonzero,    otherwise return it unchanged. */
end_comment

begin_define
define|#
directive|define
name|convert_blocks
parameter_list|(
name|b
parameter_list|,
name|k
parameter_list|)
value|((k) ? ((b) + 1) / 2 : (b))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISLNK
end_ifndef

begin_define
define|#
directive|define
name|lstat
value|stat
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Some UNIX distributions don't include these in their stat.h Defined here  * because "config.h" is always included last.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWRITE
end_ifndef

begin_define
define|#
directive|define
name|S_IWRITE
value|0000200
end_define

begin_comment
comment|/* write permission, owner */
end_comment

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
value|0000020
end_define

begin_comment
comment|/* write permission, grougroup */
end_comment

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
value|0000002
end_define

begin_comment
comment|/* write permission, other */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Under non-UNIX operating systems (MS-DOS, WinNT, MacOS), many filesystem    calls take  only one argument; permission is handled very differently on    those systems than in Unix.  So we leave such systems a hook on which they    can hang their own definitions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_ACCESS
end_ifndef

begin_define
define|#
directive|define
name|CVS_ACCESS
value|access
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_CHDIR
end_ifndef

begin_define
define|#
directive|define
name|CVS_CHDIR
value|chdir
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_CREAT
end_ifndef

begin_define
define|#
directive|define
name|CVS_CREAT
value|creat
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_FOPEN
end_ifndef

begin_define
define|#
directive|define
name|CVS_FOPEN
value|fopen
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_MKDIR
end_ifndef

begin_define
define|#
directive|define
name|CVS_MKDIR
value|mkdir
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_OPEN
end_ifndef

begin_define
define|#
directive|define
name|CVS_OPEN
value|open
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_OPENDIR
end_ifndef

begin_define
define|#
directive|define
name|CVS_OPENDIR
value|opendir
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_RENAME
end_ifndef

begin_define
define|#
directive|define
name|CVS_RENAME
value|rename
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_RMDIR
end_ifndef

begin_define
define|#
directive|define
name|CVS_RMDIR
value|rmdir
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_STAT
end_ifndef

begin_define
define|#
directive|define
name|CVS_STAT
value|stat
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Open question: should CVS_STAT be lstat by default?  We need    to use lstat in order to handle symbolic links correctly with    the PreservePermissions option. -twp */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_LSTAT
end_ifndef

begin_define
define|#
directive|define
name|CVS_LSTAT
value|lstat
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_UNLINK
end_ifndef

begin_define
define|#
directive|define
name|CVS_UNLINK
value|unlink
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Wildcard matcher.  Should be case-insensitive if the system is.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_FNMATCH
end_ifndef

begin_define
define|#
directive|define
name|CVS_FNMATCH
value|fnmatch
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
name|__CYGWIN32__
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_comment
comment|/* Under Windows NT, filenames are case-insensitive, and both / and \    are path component separators.  */
end_comment

begin_define
define|#
directive|define
name|FOLD_FN_CHAR
parameter_list|(
name|c
parameter_list|)
value|(WNT_filename_classes[(unsigned char) (c)])
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|WNT_filename_classes
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FILENAMES_CASE_INSENSITIVE
value|1
end_define

begin_comment
comment|/* Is the character C a path name separator?  Under    Windows NT, you can use either / or \.  */
end_comment

begin_define
define|#
directive|define
name|ISDIRSEP
parameter_list|(
name|c
parameter_list|)
value|(FOLD_FN_CHAR(c) == '/')
end_define

begin_comment
comment|/* Like strcmp, but with the appropriate tweaks for file names.    Under Windows NT, filenames are case-insensitive but case-preserving,    and both \ and / are path element separators.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|fncmp
parameter_list|(
specifier|const
name|char
modifier|*
name|n1
parameter_list|,
specifier|const
name|char
modifier|*
name|n2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fold characters in FILENAME to their canonical forms.      If FOLD_FN_CHAR is not #defined, the system provides a default    definition for this.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|fnfold
parameter_list|(
name|char
modifier|*
name|FILENAME
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (__CYGWIN32__) || defined (WIN32) */
end_comment

begin_comment
comment|/* Some file systems are case-insensitive.  If FOLD_FN_CHAR is    #defined, it maps the character C onto its "canonical" form.  In a    case-insensitive system, it would map all alphanumeric characters    to lower case.  Under Windows NT, / and \ are both path component    separators, so FOLD_FN_CHAR would map them both to /.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FOLD_FN_CHAR
end_ifndef

begin_define
define|#
directive|define
name|FOLD_FN_CHAR
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_define
define|#
directive|define
name|fnfold
parameter_list|(
name|filename
parameter_list|)
value|(filename)
end_define

begin_define
define|#
directive|define
name|fncmp
value|strcmp
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Different file systems have different path component separators.    For the VMS port we might need to abstract further back than this.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISDIRSEP
end_ifndef

begin_define
define|#
directive|define
name|ISDIRSEP
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
comment|/* On some systems, we have to be careful about writing/reading files    in text or binary mode (so in text mode the system can handle CRLF    vs. LF, VMS text file conventions,&c).  We decide to just always    be careful.  That way we don't have to worry about whether text and    binary differ on this system.  We just have to worry about whether    the system has O_BINARY and "rb".  The latter is easy; all ANSI C    libraries have it, SunOS4 has it, and CVS has used it unguarded    some places for a while now without complaints (e.g. "rb" in    server.c (server_updated), since CVS 1.8).  The former is just an    #ifdef.  */
end_comment

begin_define
define|#
directive|define
name|FOPEN_BINARY_READ
value|("rb")
end_define

begin_define
define|#
directive|define
name|FOPEN_BINARY_WRITE
value|("wb")
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|O_BINARY
end_ifdef

begin_define
define|#
directive|define
name|OPEN_BINARY
value|(O_BINARY)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OPEN_BINARY
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

