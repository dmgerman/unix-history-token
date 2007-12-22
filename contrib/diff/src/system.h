begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* System dependent declarations.     Copyright (C) 1988, 1989, 1992, 1993, 1994, 1995, 1998, 2001, 2002,    2004 Free Software Foundation, Inc.     This file is part of GNU DIFF.     GNU DIFF is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GNU DIFF is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_comment
comment|/* Don't bother to support K&R C compilers any more; it's not worth    the trouble.  These macros prevent some library modules from being    compiled in K&R C mode.  */
end_comment

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|Args
end_define

begin_define
define|#
directive|define
name|PROTOTYPES
value|1
end_define

begin_comment
comment|/* Define `__attribute__' and `volatile' first    so that they're used consistently in all system includes.  */
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

begin_if
if|#
directive|if
name|defined
specifier|const
operator|&&
operator|!
name|defined
specifier|volatile
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

begin_comment
comment|/* Verify a requirement at compile-time (unlike assert, which is runtime).  */
end_comment

begin_define
define|#
directive|define
name|verify
parameter_list|(
name|name
parameter_list|,
name|assertion
parameter_list|)
value|struct name { char a[(assertion) ? 1 : -1]; }
end_define

begin_comment
comment|/* Determine whether an integer type is signed, and its bounds.    This code assumes two's (or one's!) complement with no holes.  */
end_comment

begin_comment
comment|/* The extra casts work around common compiler bugs,    e.g. Cray C 5.0.3.0 when t == time_t.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_SIGNED
end_ifndef

begin_define
define|#
directive|define
name|TYPE_SIGNED
parameter_list|(
name|t
parameter_list|)
value|(! ((t) 0< (t) -1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_MINIMUM
end_ifndef

begin_define
define|#
directive|define
name|TYPE_MINIMUM
parameter_list|(
name|t
parameter_list|)
value|((t) (TYPE_SIGNED (t) \ 			       ? ~ (t) 0<< (sizeof (t) * CHAR_BIT - 1) \ 			       : (t) 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_MAXIMUM
end_ifndef

begin_define
define|#
directive|define
name|TYPE_MAXIMUM
parameter_list|(
name|t
parameter_list|)
value|((t) (~ (t) 0 - TYPE_MINIMUM (t)))
end_define

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
file|<sys/stat.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRWXU
end_ifndef

begin_define
define|#
directive|define
name|S_IRWXU
value|0700
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRWXG
end_ifndef

begin_define
define|#
directive|define
name|S_IRWXG
value|0070
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRWXO
end_ifndef

begin_define
define|#
directive|define
name|S_IRWXO
value|0007
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

begin_include
include|#
directive|include
file|<time.h>
end_include

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
value|(close (t), fcntl (f, F_DUPFD, t))
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
name|S_IRUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IRUSR
value|0400
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
value|0200
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
value|((unsigned int) (stat_val)>> 8)
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
name|HAVE_STRUCT_STAT_ST_BLKSIZE
end_if

begin_define
define|#
directive|define
name|STAT_BLOCKSIZE
parameter_list|(
name|s
parameter_list|)
value|((s).st_blksize)
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
value|strlen ((dirent)->d_name)
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

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|EXIT_TROUBLE
value|2
end_define

begin_include
include|#
directive|include
file|<limits.h>
end_include

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

begin_ifndef
ifndef|#
directive|ifndef
name|PTRDIFF_MAX
end_ifndef

begin_define
define|#
directive|define
name|PTRDIFF_MAX
value|TYPE_MAXIMUM (ptrdiff_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_MAX
end_ifndef

begin_define
define|#
directive|define
name|SIZE_MAX
value|TYPE_MAXIMUM (size_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UINTMAX_MAX
end_ifndef

begin_define
define|#
directive|define
name|UINTMAX_MAX
value|TYPE_MAXIMUM (uintmax_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_STRTOUMAX
operator|&&
operator|!
name|defined
name|strtoumax
end_if

begin_function_decl
name|uintmax_t
name|strtoumax
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_if
if|#
directive|if
operator|!
name|HAVE_STRCASECOLL
end_if

begin_if
if|#
directive|if
name|HAVE_STRICOLL
operator|||
name|defined
name|stricoll
end_if

begin_define
define|#
directive|define
name|strcasecoll
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|stricoll (a, b)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|strcasecoll
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strcasecmp (a, b)
end_define

begin_comment
comment|/* best we can do */
end_comment

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
operator|(
name|HAVE_STRCASECMP
operator|||
name|defined
name|strcasecmp
operator|)
end_if

begin_function_decl
name|int
name|strcasecmp
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|setlocale
parameter_list|(
name|category
parameter_list|,
name|locale
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<gettext.h>
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|msgid
parameter_list|)
value|gettext (msgid)
end_define

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|msgid
parameter_list|)
value|msgid
end_define

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_comment
comment|/* ISDIGIT differs from isdigit, as follows:    - Its arg may be any int or unsigned int; it need not be an unsigned char.    - It's guaranteed to evaluate its argument exactly once.    - It's typically faster.    POSIX 1003.1-2001 says that only '0' through '9' are digits.    Prefer ISDIGIT to isdigit unless it's important to use the locale's    definition of `digit' even when the host does not conform to POSIX.  */
end_comment

begin_define
define|#
directive|define
name|ISDIGIT
parameter_list|(
name|c
parameter_list|)
value|((unsigned int) (c) - '0'<= 9)
end_define

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SA_RESTART
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SA_INTERRUPT
end_ifdef

begin_comment
comment|/* e.g. SunOS 4.1.x */
end_comment

begin_define
define|#
directive|define
name|SA_RESTART
value|SA_INTERRUPT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SA_RESTART
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
name|defined
name|SIGCHLD
operator|&&
name|defined
name|SIGCLD
end_if

begin_define
define|#
directive|define
name|SIGCHLD
value|SIGCLD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|MIN
end_undef

begin_undef
undef|#
directive|undef
name|MAX
end_undef

begin_define
define|#
directive|define
name|MIN
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
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>= (b) ? (a) : (b))
end_define

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

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
operator|!
name|HAVE_WORKING_VFORK
end_if

begin_define
define|#
directive|define
name|vfork
value|fork
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Type used for fast comparison of several bytes at a time.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|word
end_ifndef

begin_define
define|#
directive|define
name|word
value|uintmax_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The integer type of a line number.  Since files are read into main    memory, ptrdiff_t should be wide enough.  */
end_comment

begin_typedef
typedef|typedef
name|ptrdiff_t
name|lin
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LIN_MAX
value|PTRDIFF_MAX
end_define

begin_expr_stmt
name|verify
argument_list|(
name|lin_is_signed
argument_list|,
name|TYPE_SIGNED
argument_list|(
name|lin
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|verify
argument_list|(
name|lin_is_wide_enough
argument_list|,
sizeof|sizeof
argument_list|(
name|ptrdiff_t
argument_list|)
operator|<=
sizeof|sizeof
argument_list|(
name|lin
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|verify
argument_list|(
name|lin_is_printable_as_long_int
argument_list|,
sizeof|sizeof
argument_list|(
name|lin
argument_list|)
operator|<=
expr|sizeof
operator|(
name|long
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_escape
end_escape

begin_comment
comment|/* This section contains POSIX-compliant defaults for macros    that are meant to be overridden by hand in config.h as needed.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|file_name_cmp
end_ifndef

begin_define
define|#
directive|define
name|file_name_cmp
value|strcmp
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

begin_comment
comment|/* Do struct stat *S, *T describe the same special file?  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|same_special_file
end_ifndef

begin_if
if|#
directive|if
name|HAVE_ST_RDEV
operator|&&
name|defined
name|S_ISBLK
operator|&&
name|defined
name|S_ISCHR
end_if

begin_define
define|#
directive|define
name|same_special_file
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
define|\
value|(((S_ISBLK ((s)->st_mode)&& S_ISBLK ((t)->st_mode)) \        || (S_ISCHR ((s)->st_mode)&& S_ISCHR ((t)->st_mode))) \&& (s)->st_rdev == (t)->st_rdev)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|same_special_file
parameter_list|(
name|s
parameter_list|,
name|t
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
define|\
value|((((s)->st_ino == (t)->st_ino)&& ((s)->st_dev == (t)->st_dev)) \      || same_special_file (s, t))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Do struct stat *S, *T have the same file attributes?     POSIX says that two files are identical if st_ino and st_dev are    the same, but many filesystems incorrectly assign the same (device,    inode) pair to two distinct files, including:     - GNU/Linux NFS servers that export all local filesystems as a      single NFS filesystem, if a local device number (st_dev) exceeds      255, or if a local inode number (st_ino) exceeds 16777215.     - Network Appliance NFS servers in snapshot directories; see      Network Appliance bug #195.     - ClearCase MVFS; see bug id ATRia04618.     Check whether two files that purport to be the same have the same    attributes, to work around instances of this common bug.  Do not    inspect all attributes, only attributes useful in checking for this    bug.     It's possible for two distinct files on a buggy filesystem to have    the same attributes, but it's not worth slowing down all    implementations (or complicating the configuration) to cater to    these rare cases in buggy implementations.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|same_file_attributes
end_ifndef

begin_define
define|#
directive|define
name|same_file_attributes
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
define|\
value|((s)->st_mode == (t)->st_mode \&& (s)->st_nlink == (t)->st_nlink \&& (s)->st_uid == (t)->st_uid \&& (s)->st_gid == (t)->st_gid \&& (s)->st_size == (t)->st_size \&& (s)->st_mtime == (t)->st_mtime \&& (s)->st_ctime == (t)->st_ctime)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

