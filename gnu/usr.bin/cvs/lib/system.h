begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* system-dependent definitions for CVS.    Copyright (C) 1989-1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* $CVSid: @(#)system.h 1.18 94/09/25 $ */
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
name|S_ISREG
end_ifndef

begin_comment
comment|/* Doesn't have POSIX.1 stat stuff. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|mode_t
end_ifndef

begin_define
define|#
directive|define
name|mode_t
value|unsigned short
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
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFBLK)
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
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFCHR)
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
name|S_ISDIR
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFDIR
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

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFIFO)
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
name|S_ISLNK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFLNK
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
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFSOCK)
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

begin_define
define|#
directive|define
name|S_ISNWK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFNWK)
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
name|HAVE_MKFIFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|mkfifo
parameter_list|(
name|path
parameter_list|,
name|mode
parameter_list|)
value|(mknod ((path), (mode) | S_IFIFO, 0))
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TM_IN_SYS_TIME
end_ifdef

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

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SYS_TIMEB_H
end_ifndef

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
ifdef|#
directive|ifdef
name|timezone
name|short
name|tzone
decl_stmt|;
else|#
directive|else
name|short
name|timezone
decl_stmt|;
endif|#
directive|endif
name|short
name|dstflag
decl_stmt|;
comment|/* Field not used		*/
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

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
comment|/* **  MAXPATHLEN and PATH_MAX ** **     On most systems MAXPATHLEN is defined in sys/param.h to be 1024. Of **     those that this is not true, again most define PATH_MAX in limits.h **     or sys/limits.h which usually gets included by limits.h. On the few **     remaining systems that neither statement is true, _POSIX_PATH_MAX **     is defined. ** **     So: **         1. If PATH_MAX is defined just use it. **         2. If MAXPATHLEN is defined but not PATH_MAX, then define **            PATH_MAX in terms of MAXPATHLEN. **         3. If neither is defined, include limits.h and check for **            PATH_MAX again. **         4. If PATH_MAX is still not defined but _POSIX_PATH_MAX is, **            then define PATH_MAX in terms of _POSIX_PATH_MAX. **         5. And if even _POSIX_PATH_MAX doesn't exist just put in **            a reasonable value. ** **     This works on: **         Sun Sparc 10        SunOS 4.1.3&  Solaris 1.2 **         HP 9000/700         HP/UX 8.07&  HP/UX 9.01 **         Tektronix XD88/10   UTekV 3.2e **         IBM RS6000          AIX 3.2 **         Dec Alpha           OSF 1 ???? **         Intel 386           BSDI BSD/386 **         Apollo              Domain 10.4 **         NEC                 SVR4 */
end_comment

begin_comment
comment|/* On MOST systems this will get you MAXPATHLEN */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

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
comment|/* _POSIX_PATH_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PATH_MAX   */
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UTIME_H
end_ifdef

begin_include
include|#
directive|include
file|<utime.h>
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

begin_comment
comment|/* An ANSI string.h and pre-ANSI memory.h might conflict. */
end_comment

begin_if
if|#
directive|if
operator|!
name|STDC_HEADERS
operator|&&
name|HAVE_MEMORY_H
end_if

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not STDC_HEADERS and HAVE_MEMORY_H */
end_comment

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

begin_comment
comment|/* index */
end_comment

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

begin_comment
comment|/* rindex */
end_comment

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
value|memcmp ((s1), (s2), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bcmp */
end_comment

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
value|memset ((s), 0, (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bzero */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not STDC_HJEADERS and not HAVE_STRING_H */
end_comment

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_comment
comment|/* memory.h and strings.h conflict on some systems. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not STDC_HEADERS and not HAVE_STRING_H */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|||
name|defined
argument_list|(
name|POSIX
argument_list|)
end_if

begin_function_decl
name|char
modifier|*
name|getcwd
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|getwd
parameter_list|()
function_decl|;
end_function_decl

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

begin_comment
comment|/* unistd.h defines _POSIX_VERSION on POSIX.1 systems.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DIRENT
argument_list|)
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

begin_define
define|#
directive|define
name|NLENGTH
parameter_list|(
name|dirent
parameter_list|)
value|(strlen((dirent)->d_name))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not (DIRENT or _POSIX_VERSION) */
end_comment

begin_define
define|#
directive|define
name|dirent
value|direct
end_define

begin_define
define|#
directive|define
name|NLENGTH
parameter_list|(
name|dirent
parameter_list|)
value|((dirent)->d_namlen)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_NDIR_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/ndir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_DIR_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NDIR_H
end_ifdef

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
comment|/* not (DIRENT or _POSIX_VERSION) */
end_comment

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

end_unit

