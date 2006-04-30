begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* posixstat.h -- Posix stat(2) definitions for systems that    don't have them. */
end_comment

begin_comment
comment|/* Copyright (C) 1987,1991 Free Software Foundation, Inc.     This file is part of GNU Bash, the Bourne Again SHell.     Bash is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     Bash is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with Bash; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_comment
comment|/* This file should be included instead of<sys/stat.h>.    It relies on the local sys/stat.h to work though. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIXSTAT_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_POSIXSTAT_H_
end_define

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
name|STAT_MACROS_BROKEN
argument_list|)
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
name|S_ISLNK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STAT_MACROS_BROKEN */
end_comment

begin_comment
comment|/* These are guaranteed to work only on isc386 */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_IFDIR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_ISDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_IFDIR
value|0040000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !S_IFDIR&& !S_ISDIR */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_IFMT
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_IFMT
value|0170000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !S_IFMT */
end_comment

begin_comment
comment|/* Posix 1003.1 5.6.1.1<sys/stat.h> file types */
end_comment

begin_comment
comment|/* Some Posix-wannabe systems define _S_IF* macros instead of S_IF*, but    do not provide the S_IS* macros that Posix requires. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_S_IFMT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_IFMT
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_IFMT
value|_S_IFMT
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
name|_S_IFIFO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_IFIFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_IFIFO
value|_S_IFIFO
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
name|_S_IFCHR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_IFCHR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_IFCHR
value|_S_IFCHR
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
name|_S_IFDIR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_IFDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_IFDIR
value|_S_IFDIR
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
name|_S_IFBLK
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_IFBLK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_IFBLK
value|_S_IFBLK
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
name|_S_IFREG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_IFREG
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_IFREG
value|_S_IFREG
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
name|_S_IFLNK
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_IFLNK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_IFLNK
value|_S_IFLNK
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
name|_S_IFSOCK
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_IFSOCK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_IFSOCK
value|_S_IFSOCK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Test for each symbol individually and define the ones necessary (some    systems claiming Posix compatibility define some but not all). */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFBLK
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_ISBLK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|m
parameter_list|)
value|(((m)&S_IFMT) == S_IFBLK)
end_define

begin_comment
comment|/* block device */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFCHR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_ISCHR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
value|(((m)&S_IFMT) == S_IFCHR)
end_define

begin_comment
comment|/* character device */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFDIR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_ISDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)&S_IFMT) == S_IFDIR)
end_define

begin_comment
comment|/* directory */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFREG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_ISREG
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|(((m)&S_IFMT) == S_IFREG)
end_define

begin_comment
comment|/* file */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFIFO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_ISFIFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|(((m)&S_IFMT) == S_IFIFO)
end_define

begin_comment
comment|/* fifo - named pipe */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFLNK
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_ISLNK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|(((m)&S_IFMT) == S_IFLNK)
end_define

begin_comment
comment|/* symbolic link */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFSOCK
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_ISSOCK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|(((m)&S_IFMT) == S_IFSOCK)
end_define

begin_comment
comment|/* socket */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * POSIX 1003.1 5.6.1.2<sys/stat.h> File Modes  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_IRWXU
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_IREAD
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_IREAD
value|00400
end_define

begin_define
define|#
directive|define
name|S_IWRITE
value|00200
end_define

begin_define
define|#
directive|define
name|S_IEXEC
value|00100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* S_IREAD */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_IRUSR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_IRUSR
value|S_IREAD
end_define

begin_comment
comment|/* read, owner */
end_comment

begin_define
define|#
directive|define
name|S_IWUSR
value|S_IWRITE
end_define

begin_comment
comment|/* write, owner */
end_comment

begin_define
define|#
directive|define
name|S_IXUSR
value|S_IEXEC
end_define

begin_comment
comment|/* execute, owner */
end_comment

begin_define
define|#
directive|define
name|S_IRGRP
value|(S_IREAD>> 3)
end_define

begin_comment
comment|/* read, group */
end_comment

begin_define
define|#
directive|define
name|S_IWGRP
value|(S_IWRITE>> 3)
end_define

begin_comment
comment|/* write, group */
end_comment

begin_define
define|#
directive|define
name|S_IXGRP
value|(S_IEXEC>> 3)
end_define

begin_comment
comment|/* execute, group */
end_comment

begin_define
define|#
directive|define
name|S_IROTH
value|(S_IREAD>> 6)
end_define

begin_comment
comment|/* read, other */
end_comment

begin_define
define|#
directive|define
name|S_IWOTH
value|(S_IWRITE>> 6)
end_define

begin_comment
comment|/* write, other */
end_comment

begin_define
define|#
directive|define
name|S_IXOTH
value|(S_IEXEC>> 6)
end_define

begin_comment
comment|/* execute, other */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !S_IRUSR */
end_comment

begin_define
define|#
directive|define
name|S_IRWXU
value|(S_IRUSR | S_IWUSR | S_IXUSR)
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
name|S_IRWXO
value|(S_IROTH | S_IWOTH | S_IXOTH)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !S_IRWXU */
end_comment

begin_comment
comment|/* These are non-standard, but are used in builtins.c$symbolic_umask() */
end_comment

begin_define
define|#
directive|define
name|S_IRUGO
value|(S_IRUSR | S_IRGRP | S_IROTH)
end_define

begin_define
define|#
directive|define
name|S_IWUGO
value|(S_IWUSR | S_IWGRP | S_IWOTH)
end_define

begin_define
define|#
directive|define
name|S_IXUGO
value|(S_IXUSR | S_IXGRP | S_IXOTH)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIXSTAT_H_ */
end_comment

end_unit

