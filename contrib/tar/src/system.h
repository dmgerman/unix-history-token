begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* System dependent definitions for GNU tar.     Copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001 Free Software    Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Declare alloca.  AIX requires this to be the first thing in the file.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
end_if

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_ALLOCA_H
end_if

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|alloca
end_pragma

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_function_decl
name|char
modifier|*
name|alloca
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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__attribute__
end_ifndef

begin_comment
comment|/* This feature is available in gcc versions 2.5 and later.  */
end_comment

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
literal|5
operator|)
operator|||
name|__STRICT_ANSI__
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|Spec
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_if
if|#
directive|if
name|HAVE_STDDEF_H
end_if

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|offsetof
end_ifndef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|type
parameter_list|,
name|ident
parameter_list|)
value|((size_t)&((type *) 0)->ident)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IN_CTYPE_DOMAIN (C) is nonzero if the unsigned char C can safely be given    as an argument to<ctype.h> macros like `isspace'.  */
end_comment

begin_if
if|#
directive|if
name|STDC_HEADERS
end_if

begin_define
define|#
directive|define
name|IN_CTYPE_DOMAIN
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
name|IN_CTYPE_DOMAIN
parameter_list|(
name|c
parameter_list|)
value|((unsigned) (c)<= 0177)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISDIGIT
parameter_list|(
name|c
parameter_list|)
value|((unsigned) (c) - '0'<= 9)
end_define

begin_define
define|#
directive|define
name|ISODIGIT
parameter_list|(
name|c
parameter_list|)
value|((unsigned) (c) - '0'<= 7)
end_define

begin_define
define|#
directive|define
name|ISPRINT
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isprint (c))
end_define

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isspace (c))
end_define

begin_comment
comment|/* Declare string and memory handling routines.  Take care that an ANSI    string.h and pre-ANSI memory.h might conflict, and that memory.h and    strings.h conflict on some systems.  */
end_comment

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

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|strchr
end_ifndef

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|strrchr
end_ifndef

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

begin_ifndef
ifndef|#
directive|ifndef
name|memcpy
end_ifndef

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
value|bcopy ((char const *) (s), (char *) (d), n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|memcmp
end_ifndef

begin_define
define|#
directive|define
name|memcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|bcmp ((char const *) (a), (char const *) (b), n)
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
comment|/* Declare errno.  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|errno
end_ifndef

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
comment|/* Declare open parameters.  */
end_comment

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

begin_comment
comment|/* Pick only one of the next three: */
end_comment

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

begin_comment
comment|/* only allow read */
end_comment

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

begin_comment
comment|/* only allow write */
end_comment

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

begin_comment
comment|/* both are allowed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_ACCMODE
end_ifndef

begin_define
define|#
directive|define
name|O_ACCMODE
value|(O_RDONLY | O_RDWR | O_WRONLY)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The rest can be OR-ed in to the above: */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|O_CREAT
end_ifndef

begin_define
define|#
directive|define
name|O_CREAT
value|8
end_define

begin_comment
comment|/* create file if needed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_EXCL
end_ifndef

begin_define
define|#
directive|define
name|O_EXCL
value|16
end_define

begin_comment
comment|/* file cannot already exist */
end_comment

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
value|32
end_define

begin_comment
comment|/* truncate file on open */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MS-DOG forever, with my love! */
end_comment

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
comment|/* Declare file status routines and bits.  */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_if
if|#
directive|if
operator|!
name|HAVE_LSTAT
operator|&&
operator|!
name|defined
name|lstat
end_if

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

begin_if
if|#
directive|if
name|STX_HIDDEN
operator|&&
operator|!
name|_LARGE_FILES
end_if

begin_comment
comment|/* AIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|stat
end_ifdef

begin_undef
undef|#
directive|undef
name|stat
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|stat
parameter_list|(
name|path
parameter_list|,
name|buf
parameter_list|)
value|statx (path, buf, STATSIZE, STX_HIDDEN)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|lstat
end_ifdef

begin_undef
undef|#
directive|undef
name|lstat
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|lstat
parameter_list|(
name|path
parameter_list|,
name|buf
parameter_list|)
value|statx (path, buf, STATSIZE, STX_HIDDEN | STX_LINK)
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
name|S_ISCTG
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
name|S_ISLNK
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

begin_comment
comment|/* On MSDOS, there are missing things from<sys/stat.h>.  */
end_comment

begin_if
if|#
directive|if
name|MSDOS
end_if

begin_define
define|#
directive|define
name|S_ISUID
value|0
end_define

begin_define
define|#
directive|define
name|S_ISGID
value|0
end_define

begin_define
define|#
directive|define
name|S_ISVTX
value|0
end_define

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
name|Mode
parameter_list|)
value|(((Mode)& S_IFMT) == S_IFDIR)
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
name|Mode
parameter_list|)
value|(((Mode)& S_IFMT) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISBLK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFBLK
end_ifdef

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|Mode
parameter_list|)
value|(((Mode)& S_IFMT) == S_IFBLK)
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
name|Mode
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISCHR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFCHR
end_ifdef

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|Mode
parameter_list|)
value|(((Mode)& S_IFMT) == S_IFCHR)
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
name|Mode
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISCTG
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFCTG
end_ifdef

begin_define
define|#
directive|define
name|S_ISCTG
parameter_list|(
name|Mode
parameter_list|)
value|(((Mode)& S_IFMT) == S_IFCTG)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISCTG
parameter_list|(
name|Mode
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDOOR
end_ifndef

begin_define
define|#
directive|define
name|S_ISDOOR
parameter_list|(
name|Mode
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
name|S_ISFIFO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFIFO
end_ifdef

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|Mode
parameter_list|)
value|(((Mode)& S_IFMT) == S_IFIFO)
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
name|Mode
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISLNK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFLNK
end_ifdef

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|Mode
parameter_list|)
value|(((Mode)& S_IFMT) == S_IFLNK)
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
name|Mode
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISSOCK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFSOCK
end_ifdef

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|Mode
parameter_list|)
value|(((Mode)& S_IFMT) == S_IFSOCK)
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
name|Mode
parameter_list|)
value|0
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
name|HAVE_MKFIFO
operator|&&
operator|!
name|defined
name|mkfifo
operator|&&
name|defined
name|S_IFIFO
end_if

begin_define
define|#
directive|define
name|mkfifo
parameter_list|(
name|Path
parameter_list|,
name|Mode
parameter_list|)
value|(mknod (Path, (Mode) | S_IFIFO, 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISUID
end_ifndef

begin_define
define|#
directive|define
name|S_ISUID
value|0004000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISGID
end_ifndef

begin_define
define|#
directive|define
name|S_ISGID
value|0002000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISVTX
end_ifndef

begin_define
define|#
directive|define
name|S_ISVTX
value|0001000
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
value|0000400
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
value|0000200
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
value|0000100
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
value|0000040
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
value|0000020
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
value|0000010
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
value|0000004
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
value|0000002
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
value|0000001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MODE_WXUSR
value|(S_IWUSR | S_IXUSR)
end_define

begin_define
define|#
directive|define
name|MODE_R
value|(S_IRUSR | S_IRGRP | S_IROTH)
end_define

begin_define
define|#
directive|define
name|MODE_RW
value|(S_IWUSR | S_IWGRP | S_IWOTH | MODE_R)
end_define

begin_define
define|#
directive|define
name|MODE_RWX
value|(S_IXUSR | S_IXGRP | S_IXOTH | MODE_RW)
end_define

begin_define
define|#
directive|define
name|MODE_ALL
value|(S_ISUID | S_ISGID | S_ISVTX | MODE_RWX)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include<unistd.h> before any preprocessor test of _POSIX_VERSION.  */
end_comment

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
name|SEEK_END
end_ifndef

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

begin_comment
comment|/* Declare make device, major and minor.  Since major is a function on    SVR4, we have to resort to GOT_MAJOR instead of just testing if    major is #define'd.  */
end_comment

begin_if
if|#
directive|if
name|MAJOR_IN_MKDEV
end_if

begin_include
include|#
directive|include
file|<sys/mkdev.h>
end_include

begin_define
define|#
directive|define
name|GOT_MAJOR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MAJOR_IN_SYSMACROS
end_if

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_define
define|#
directive|define
name|GOT_MAJOR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some<sys/types.h> defines the macros. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|major
end_ifdef

begin_define
define|#
directive|define
name|GOT_MAJOR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GOT_MAJOR
end_ifndef

begin_if
if|#
directive|if
name|MSDOS
end_if

begin_define
define|#
directive|define
name|major
parameter_list|(
name|Device
parameter_list|)
value|(Device)
end_define

begin_define
define|#
directive|define
name|minor
parameter_list|(
name|Device
parameter_list|)
value|(Device)
end_define

begin_define
define|#
directive|define
name|makedev
parameter_list|(
name|Major
parameter_list|,
name|Minor
parameter_list|)
value|(((Major)<< 8) | (Minor))
end_define

begin_define
define|#
directive|define
name|GOT_MAJOR
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
comment|/* For HP-UX before HP-UX 8, major/minor are not in<sys/sysmacros.h>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOT_MAJOR
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|__hpux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/mknod.h>
end_include

begin_define
define|#
directive|define
name|GOT_MAJOR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GOT_MAJOR
end_ifndef

begin_define
define|#
directive|define
name|major
parameter_list|(
name|Device
parameter_list|)
value|(((Device)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|minor
parameter_list|(
name|Device
parameter_list|)
value|((Device)& 0xff)
end_define

begin_define
define|#
directive|define
name|makedev
parameter_list|(
name|Major
parameter_list|,
name|Minor
parameter_list|)
value|(((Major)<< 8) | (Minor))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|GOT_MAJOR
end_undef

begin_comment
comment|/* Declare wait status.  */
end_comment

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
name|s
parameter_list|)
value|(((s)>> 8)& 0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WIFSIGNALED
end_ifndef

begin_define
define|#
directive|define
name|WIFSIGNALED
parameter_list|(
name|s
parameter_list|)
value|(((s)& 0xffff) - 1< (unsigned) 0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WTERMSIG
end_ifndef

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|s
parameter_list|)
value|((s)& 0x7f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FIXME: It is wrong to use BLOCKSIZE for buffers when the logical block    size is greater than 512 bytes; so ST_BLKSIZE code below, in preparation    for some cleanup in this area, later.  */
end_comment

begin_comment
comment|/* Get or fake the disk device blocksize.  Usually defined by sys/param.h    (if at all).  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEV_BSIZE
argument_list|)
operator|&&
name|defined
argument_list|(
name|BSIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEV_BSIZE
value|BSIZE
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
name|DEV_BSIZE
argument_list|)
operator|&&
name|defined
argument_list|(
name|BBSIZE
argument_list|)
end_if

begin_comment
comment|/* SGI */
end_comment

begin_define
define|#
directive|define
name|DEV_BSIZE
value|BBSIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_BSIZE
end_ifndef

begin_define
define|#
directive|define
name|DEV_BSIZE
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Extract or fake data from a `struct stat'.  ST_BLKSIZE gives the    optimal I/O blocksize for the file, in bytes.  Some systems, like    Sequents, return st_blksize of 0 on pipes.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_ST_BLKSIZE
end_if

begin_define
define|#
directive|define
name|ST_BLKSIZE
parameter_list|(
name|Statbuf
parameter_list|)
value|DEV_BSIZE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ST_BLKSIZE
parameter_list|(
name|Statbuf
parameter_list|)
define|\
value|((Statbuf).st_blksize> 0 ? (Statbuf).st_blksize : DEV_BSIZE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Extract or fake data from a `struct stat'.  ST_NBLOCKS gives the    number of ST_NBLOCKSIZE-byte blocks in the file (including indirect blocks).    HP-UX counts st_blocks in 1024-byte units,    this loses when mixing HP-UX and BSD filesystems with NFS.  AIX PS/2    counts st_blocks in 4K units.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_ST_BLOCKS
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|BSIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|ST_NBLOCKS
parameter_list|(
name|Statbuf
parameter_list|)
value|((Statbuf).st_size / ST_NBLOCKSIZE + ((Statbuf).st_size % ST_NBLOCKSIZE != 0))
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|off_t
name|st_blocks
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ST_NBLOCKS
parameter_list|(
name|Statbuf
parameter_list|)
value|(st_blocks ((Statbuf).st_size))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ST_NBLOCKS
parameter_list|(
name|Statbuf
parameter_list|)
value|((Statbuf).st_blocks)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|__hpux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_define
define|#
directive|define
name|ST_NBLOCKSIZE
value|1024
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|&&
name|defined
argument_list|(
name|_I386
argument_list|)
end_if

begin_define
define|#
directive|define
name|ST_NBLOCKSIZE
value|(4 * 1024)
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|ST_NBLOCKSIZE
end_ifndef

begin_define
define|#
directive|define
name|ST_NBLOCKSIZE
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is a real challenge to properly get MTIO* symbols :-(.  ISC uses<sys/gentape.h>.  SCO and BSDi uses<sys/tape.h>; BSDi also requires<sys/tprintf.h> and<sys/device.h> for defining tp_dev and tpr_t.  It    seems that the rest use<sys/mtio.h>, which itself requires other files,    depending on systems.  Pyramid defines _IOW in<sgtty.h>, for example.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_GENTAPE_H
end_if

begin_include
include|#
directive|include
file|<sys/gentape.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_TAPE_H
end_if

begin_if
if|#
directive|if
name|HAVE_SYS_DEVICE_H
end_if

begin_include
include|#
directive|include
file|<sys/device.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_BUF_H
end_if

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_TPRINTF_H
end_if

begin_include
include|#
directive|include
file|<sys/tprintf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/tape.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_MTIO_H
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_if
if|#
directive|if
name|HAVE_SGTTY_H
end_if

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_IO_TRIOCTL_H
end_if

begin_include
include|#
directive|include
file|<sys/io/trioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/mtio.h>
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
comment|/* Declare standard functions.  */
end_comment

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
name|void
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|realloc
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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STDBOOL_H
end_if

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
enum|enum
block|{
name|false
init|=
literal|0
block|,
name|true
init|=
literal|1
block|}
name|bool
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_VERSION
end_ifndef

begin_if
if|#
directive|if
name|MSDOS
end_if

begin_include
include|#
directive|include
file|<io.h>
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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|WITH_DMALLOC
end_if

begin_undef
undef|#
directive|undef
name|HAVE_VALLOC
end_undef

begin_define
define|#
directive|define
name|DMALLOC_FUNC_CHECK
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|CHAR_MAX
end_ifndef

begin_define
define|#
directive|define
name|CHAR_MAX
value|TYPE_MAXIMUM (char)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UCHAR_MAX
end_ifndef

begin_define
define|#
directive|define
name|UCHAR_MAX
value|TYPE_MAXIMUM (unsigned char)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|LONG_MAX
value|TYPE_MAXIMUM (long)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MB_LEN_MAX
end_ifndef

begin_define
define|#
directive|define
name|MB_LEN_MAX
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_INTTYPES_H
end_if

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These macros work even on ones'-complement hosts (!).    The extra casts work around common compiler bugs.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_SIGNED
parameter_list|(
name|t
parameter_list|)
value|(! ((t) 0< (t) -1))
end_define

begin_define
define|#
directive|define
name|TYPE_MINIMUM
parameter_list|(
name|t
parameter_list|)
value|(TYPE_SIGNED (t) \ 			 ? ~ (t) 0<< (sizeof (t) * CHAR_BIT - 1) \ 			 : (t) 0)
end_define

begin_define
define|#
directive|define
name|TYPE_MAXIMUM
parameter_list|(
name|t
parameter_list|)
value|((t) (~ (t) 0 - TYPE_MINIMUM (t)))
end_define

begin_comment
comment|/* Bound on length of the string representing an integer value of type t.    Subtract one for the sign bit if t is signed;    302 / 1000 is log10 (2) rounded up;    add one for integer division truncation;    add one more for a minus sign if t is signed.  */
end_comment

begin_define
define|#
directive|define
name|INT_STRLEN_BOUND
parameter_list|(
name|t
parameter_list|)
define|\
value|((sizeof (t) * CHAR_BIT - TYPE_SIGNED (t)) * 302 / 1000 \    + 1 + TYPE_SIGNED (t))
end_define

begin_define
define|#
directive|define
name|UINTMAX_STRSIZE_BOUND
value|(INT_STRLEN_BOUND (uintmax_t) + 1)
end_define

begin_escape
end_escape

begin_comment
comment|/* Prototypes for external functions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|PROTOTYPES
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|Args
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
name|Args
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

begin_if
if|#
directive|if
name|HAVE_LOCALE_H
end_if

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_SETLOCALE
end_if

begin_define
define|#
directive|define
name|setlocale
parameter_list|(
name|Category
parameter_list|,
name|Locale
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ENABLE_NLS
end_if

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|Text
parameter_list|)
value|gettext (Text)
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|bindtextdomain
end_undef

begin_define
define|#
directive|define
name|bindtextdomain
parameter_list|(
name|Domain
parameter_list|,
name|Directory
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_undef
undef|#
directive|undef
name|textdomain
end_undef

begin_define
define|#
directive|define
name|textdomain
parameter_list|(
name|Domain
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|_
parameter_list|(
name|Text
parameter_list|)
value|Text
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|Text
parameter_list|)
value|Text
end_define

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|time
end_ifndef

begin_function_decl
name|time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Library modules.  */
end_comment

begin_include
include|#
directive|include
file|<dirname.h>
end_include

begin_include
include|#
directive|include
file|<error.h>
end_include

begin_include
include|#
directive|include
file|<savedir.h>
end_include

begin_include
include|#
directive|include
file|<xalloc.h>
end_include

begin_if
if|#
directive|if
operator|!
name|HAVE_STRSTR
end_if

begin_decl_stmt
name|char
modifier|*
name|strstr
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_VALLOC
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|valloc
end_ifndef

begin_function_decl
name|void
modifier|*
name|valloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|valloc
parameter_list|(
name|Size
parameter_list|)
value|malloc (Size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|xstrdup
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

