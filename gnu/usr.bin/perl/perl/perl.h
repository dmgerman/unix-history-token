begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: perl.h,v $$Revision: 1.2 $$Date: 1995/05/30 05:03:11 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: perl.h,v $  * Revision 1.2  1995/05/30 05:03:11  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1994/09/10  06:27:35  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:29:35  nate  * PERL!  *  * Revision 4.0.1.7  1993/02/05  19:40:30  lwall  * patch36: worked around certain busted compilers that don't init statics right  *  * Revision 4.0.1.6  92/06/08  14:55:10  lwall  * patch20: added Atari ST portability  * patch20: bcopy() and memcpy() now tested for overlap safety  * patch20: Perl now distinguishes overlapped copies from non-overlapped  * patch20: removed implicit int declarations on functions  *  * Revision 4.0.1.5  91/11/11  16:41:07  lwall  * patch19: uts wrongly defines S_ISDIR() et al  * patch19: too many preprocessors can't expand a macro right in #if  * patch19: added little-endian pack/unpack options  *  * Revision 4.0.1.4  91/11/05  18:06:10  lwall  * patch11: various portability fixes  * patch11: added support for dbz  * patch11: added some support for 64-bit integers  * patch11: hex() didn't understand leading 0x  *  * Revision 4.0.1.3  91/06/10  01:25:10  lwall  * patch10: certain pattern optimizations were botched  *  * Revision 4.0.1.2  91/06/07  11:28:33  lwall  * patch4: new copyright notice  * patch4: made some allowances for "semi-standard" C  * patch4: many, many itty-bitty portability fixes  *  * Revision 4.0.1.1  91/04/11  17:49:51  lwall  * patch1: hopefully straightened out some of the Xenix mess  *  * Revision 4.0  91/03/20  01:37:56  lwall  * 4.0 baseline.  *  */
end_comment

begin_define
define|#
directive|define
name|VOIDWANT
value|1
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MYMALLOC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HIDEMYMALLOC
end_ifdef

begin_define
define|#
directive|define
name|malloc
value|Mymalloc
end_define

begin_define
define|#
directive|define
name|realloc
value|Myremalloc
end_define

begin_define
define|#
directive|define
name|free
value|Myfree
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|safemalloc
value|malloc
end_define

begin_define
define|#
directive|define
name|saferealloc
value|realloc
end_define

begin_define
define|#
directive|define
name|safefree
value|free
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* work around some libPW problems */
end_comment

begin_define
define|#
directive|define
name|fatal
value|Myfatal
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_decl_stmt
name|char
name|Error
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* define this once if either system, instead of cluttering up the src */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|atarist
argument_list|)
end_if

begin_define
define|#
directive|define
name|DOSISH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DOSISH
end_ifdef

begin_comment
comment|/* This stuff now in the MS-DOS config.h file. */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !MSDOS */
end_comment

begin_comment
comment|/*  * The following symbols are defined if your operating system supports  * functions by that name.  All Unixes I know of support them, thus they  * are not checked by the configuration script, but are directly defined  * here.  */
end_comment

begin_define
define|#
directive|define
name|HAS_ALARM
end_define

begin_define
define|#
directive|define
name|HAS_CHOWN
end_define

begin_define
define|#
directive|define
name|HAS_CHROOT
end_define

begin_define
define|#
directive|define
name|HAS_FORK
end_define

begin_define
define|#
directive|define
name|HAS_GETLOGIN
end_define

begin_define
define|#
directive|define
name|HAS_GETPPID
end_define

begin_define
define|#
directive|define
name|HAS_KILL
end_define

begin_define
define|#
directive|define
name|HAS_LINK
end_define

begin_define
define|#
directive|define
name|HAS_PIPE
end_define

begin_define
define|#
directive|define
name|HAS_WAIT
end_define

begin_define
define|#
directive|define
name|HAS_UMASK
end_define

begin_comment
comment|/*  * The following symbols are defined if your operating system supports  * password and group functions in general.  All Unix systems do.  */
end_comment

begin_define
define|#
directive|define
name|HAS_GROUP
end_define

begin_define
define|#
directive|define
name|HAS_PASSWD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !MSDOS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|||
name|defined
argument_list|(
name|__stdc__
argument_list|)
end_if

begin_define
define|#
directive|define
name|STANDARD_C
value|1
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
name|HASVOLATILE
argument_list|)
operator|||
name|defined
argument_list|(
name|STANDARD_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|VOLATILE
value|volatile
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VOLATILE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IAMSUID
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|TAINT
end_ifndef

begin_define
define|#
directive|define
name|TAINT
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
name|HAS_VFORK
end_ifndef

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_GETPGRP2
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_GETPGRP
end_ifndef

begin_define
define|#
directive|define
name|HAS_GETPGRP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getpgrp
value|getpgrp2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SETPGRP2
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_SETPGRP
end_ifndef

begin_define
define|#
directive|define
name|HAS_SETPGRP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|setpgrp
value|setpgrp2
end_define

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
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MSDOS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PARAM_NEEDS_TYPES
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STANDARD_C
end_ifdef

begin_comment
comment|/* Use all the "standard" definitions */
end_comment

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

begin_define
define|#
directive|define
name|MEM_SIZE
value|size_t
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|int
name|MEM_SIZE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STANDARD_C */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_MEMCMP
argument_list|)
operator|&&
name|defined
argument_list|(
name|mips
argument_list|)
operator|&&
name|defined
argument_list|(
name|ultrix
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAS_MEMCMP
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_MEMCPY
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|STANDARD_C
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|memcpy
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|memcpy
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

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|memcpy
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_BCOPY
end_ifdef

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|bcopy(s,d,l)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|my_bcopy(s,d,l)
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

begin_comment
comment|/* HAS_MEMCPY */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_MEMSET
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|STANDARD_C
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|memset
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|memset
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

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|d
parameter_list|,
name|l
parameter_list|)
value|memset(d,0,l)
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|memzero
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_BZERO
end_ifdef

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|d
parameter_list|,
name|l
parameter_list|)
value|bzero(d,l)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|d
parameter_list|,
name|l
parameter_list|)
value|my_bzero(d,l)
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

begin_comment
comment|/* HAS_MEMSET */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_MEMCMP
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|STANDARD_C
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|memcmp
end_ifndef

begin_function_decl
specifier|extern
name|int
name|memcmp
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

begin_else
else|#
directive|else
end_else

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
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|my_memcmp(s1,s2,l)
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
comment|/* HAS_MEMCMP */
end_comment

begin_comment
comment|/* we prefer bcmp slightly for comparisons that don't care about ordering */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_BCMP
end_ifndef

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
name|l
parameter_list|)
value|memcmp(s1,s2,l)
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
comment|/* HAS_BCMP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_MEMMOVE
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_BCOPY
argument_list|)
operator|&&
name|defined
argument_list|(
name|SAFE_BCOPY
argument_list|)
end_if

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|bcopy(s,d,l)
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
name|HAS_MEMCPY
argument_list|)
operator|&&
name|defined
argument_list|(
name|SAFE_MEMCPY
argument_list|)
end_if

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|memcpy(d,s,l)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|my_bcopy(s,d,l)
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
name|_TYPES_
end_ifndef

begin_comment
comment|/* If types.h defines this it's easy. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|major
end_ifndef

begin_comment
comment|/* Does everyone's types.h define this? */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
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
name|I_NETINET_IN
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
name|uts
argument_list|)
operator|||
name|defined
argument_list|(
name|UTekV
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|S_ISDIR
end_undef

begin_undef
undef|#
directive|undef
name|S_ISCHR
end_undef

begin_undef
undef|#
directive|undef
name|S_ISBLK
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

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|P
parameter_list|)
value|(((P)&S_IFMT)==S_IFDIR)
end_define

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|P
parameter_list|)
value|(((P)&S_IFMT)==S_IFCHR)
end_define

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|P
parameter_list|)
value|(((P)&S_IFMT)==S_IFBLK)
end_define

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|P
parameter_list|)
value|(((P)&S_IFMT)==S_IFREG)
end_define

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|P
parameter_list|)
value|(((P)&S_IFMT)==S_IFIFO)
end_define

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
name|P
parameter_list|)
value|(((P)&S_IFMT)==S_IFLNK)
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
file|<sys/mount.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|I_TIME
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_TIME
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSTIMEKERNEL
end_ifdef

begin_define
define|#
directive|define
name|KERNEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SYSTIMEKERNEL
end_ifdef

begin_undef
undef|#
directive|undef
name|KERNEL
end_undef

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
name|MSDOS
end_ifndef

begin_include
include|#
directive|include
file|<sys/times.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_STRERROR
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|HAS_MKDIR
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|HAS_RMDIR
argument_list|)
operator|)
end_if

begin_undef
undef|#
directive|undef
name|HAS_STRERROR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MSDOS
end_ifndef

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

begin_comment
comment|/* ANSI allows errno to be an lvalue expr */
end_comment

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
name|strerror
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_STRERROR
end_ifdef

begin_function_decl
name|char
modifier|*
name|strerror
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|strerror
parameter_list|(
name|e
parameter_list|)
value|((e)< 0 || (e)>= sys_nerr ? "(unknown)" : sys_errlist[e])
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
name|I_SYSIOCTL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_IOCTL_
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
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
name|defined
argument_list|(
name|mc300
argument_list|)
operator|||
name|defined
argument_list|(
name|mc500
argument_list|)
operator|||
name|defined
argument_list|(
name|mc700
argument_list|)
operator|||
name|defined
argument_list|(
name|mc6000
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SOCKETPAIR
end_ifdef

begin_undef
undef|#
directive|undef
name|HAS_SOCKETPAIR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_NDBM
end_ifdef

begin_undef
undef|#
directive|undef
name|HAS_NDBM
end_undef

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
name|WANT_DBZ
end_ifdef

begin_include
include|#
directive|include
file|<dbz.h>
end_include

begin_define
define|#
directive|define
name|SOME_DBM
end_define

begin_define
define|#
directive|define
name|dbm_fetch
parameter_list|(
name|db
parameter_list|,
name|dkey
parameter_list|)
value|fetch(dkey)
end_define

begin_define
define|#
directive|define
name|dbm_delete
parameter_list|(
name|db
parameter_list|,
name|dkey
parameter_list|)
value|fatal("dbz doesn't implement delete")
end_define

begin_define
define|#
directive|define
name|dbm_store
parameter_list|(
name|db
parameter_list|,
name|dkey
parameter_list|,
name|dcontent
parameter_list|,
name|flags
parameter_list|)
value|store(dkey,dcontent)
end_define

begin_define
define|#
directive|define
name|dbm_close
parameter_list|(
name|db
parameter_list|)
value|dbmclose()
end_define

begin_define
define|#
directive|define
name|dbm_firstkey
parameter_list|(
name|db
parameter_list|)
value|(fatal("dbz doesn't implement traversal"),fetch())
end_define

begin_define
define|#
directive|define
name|nextkey
parameter_list|()
value|(fatal("dbz doesn't implement traversal"),fetch())
end_define

begin_define
define|#
directive|define
name|dbm_nextkey
parameter_list|(
name|db
parameter_list|)
value|(fatal("dbz doesn't implement traversal"),fetch())
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_NDBM
end_ifdef

begin_undef
undef|#
directive|undef
name|HAS_NDBM
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_ODBM
end_ifndef

begin_define
define|#
directive|define
name|HAS_ODBM
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
name|HAS_GDBM
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|I_GDBM
end_ifdef

begin_include
include|#
directive|include
file|<gdbm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SOME_DBM
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_NDBM
end_ifdef

begin_undef
undef|#
directive|undef
name|HAS_NDBM
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_ODBM
end_ifdef

begin_undef
undef|#
directive|undef
name|HAS_ODBM
end_undef

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
name|HAS_NDBM
end_ifdef

begin_include
include|#
directive|include
file|<ndbm.h>
end_include

begin_define
define|#
directive|define
name|SOME_DBM
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_ODBM
end_ifdef

begin_undef
undef|#
directive|undef
name|HAS_ODBM
end_undef

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
name|HAS_ODBM
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NULL
end_ifdef

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_comment
comment|/* suppress redefinition message */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dbm.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NULL
end_ifdef

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_comment
comment|/* silly thing is, we don't even use this */
end_comment

begin_define
define|#
directive|define
name|SOME_DBM
end_define

begin_define
define|#
directive|define
name|dbm_fetch
parameter_list|(
name|db
parameter_list|,
name|dkey
parameter_list|)
value|fetch(dkey)
end_define

begin_define
define|#
directive|define
name|dbm_delete
parameter_list|(
name|db
parameter_list|,
name|dkey
parameter_list|)
value|delete(dkey)
end_define

begin_define
define|#
directive|define
name|dbm_store
parameter_list|(
name|db
parameter_list|,
name|dkey
parameter_list|,
name|dcontent
parameter_list|,
name|flags
parameter_list|)
value|store(dkey,dcontent)
end_define

begin_define
define|#
directive|define
name|dbm_close
parameter_list|(
name|db
parameter_list|)
value|dbmclose()
end_define

begin_define
define|#
directive|define
name|dbm_firstkey
parameter_list|(
name|db
parameter_list|)
value|firstkey()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_ODBM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_NDBM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_GDBM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WANT_DBZ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SOME_DBM
end_ifdef

begin_decl_stmt
name|EXT
name|char
modifier|*
name|dbmkey
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|dbmlen
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|INTSIZE
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|htoni
value|htons
end_define

begin_define
define|#
directive|define
name|ntohi
value|ntohs
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|htoni
value|htonl
end_define

begin_define
define|#
directive|define
name|ntohi
value|ntohl
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
name|I_DIRENT
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
name|DIRENT
value|dirent
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_NDIR
end_ifdef

begin_include
include|#
directive|include
file|<sys/ndir.h>
end_include

begin_define
define|#
directive|define
name|DIRENT
value|direct
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_DIR
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|hp9000s500
end_ifdef

begin_include
include|#
directive|include
file|<ndir.h>
end_include

begin_comment
comment|/* may be wrong in the future */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DIRENT
value|direct
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

begin_ifdef
ifdef|#
directive|ifdef
name|FPUTS_BOTCH
end_ifdef

begin_comment
comment|/* work around botch in SunOS 4.0.1 and 4.0.2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|fputs
end_ifndef

begin_define
define|#
directive|define
name|fputs
parameter_list|(
name|str
parameter_list|,
name|fp
parameter_list|)
value|fprintf(fp,"%s",str)
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
comment|/*  * The following gobbledygook brought to you on behalf of __STDC__.  * (I could just use #ifndef __STDC__, but this is more bulletproof  * in the face of half-implementations.)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFMT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_S_IFMT
end_ifdef

begin_define
define|#
directive|define
name|S_IFMT
value|_S_IFMT
end_define

begin_else
else|#
directive|else
end_else

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
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISCHR
end_ifndef

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFCHR)
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
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFBLK)
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
value|(0)
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
name|S_ISREG
end_ifndef

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFREG)
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
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFIFO)
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
value|(0)
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
name|_S_ISLNK
end_ifdef

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|_S_ISLNK(m)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_S_IFLNK
end_ifdef

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == _S_IFLNK)
end_define

begin_else
else|#
directive|else
end_else

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
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFLNK)
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
value|(0)
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
name|_S_ISSOCK
end_ifdef

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|_S_ISSOCK(m)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_S_IFSOCK
end_ifdef

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == _S_IFSOCK)
end_define

begin_else
else|#
directive|else
end_else

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
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFSOCK)
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
value|(0)
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRUSR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IREAD
end_ifdef

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

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|S_IRGRP
value|(S_IRUSR>>3)
end_define

begin_define
define|#
directive|define
name|S_IWGRP
value|(S_IWUSR>>3)
end_define

begin_define
define|#
directive|define
name|S_IXGRP
value|(S_IXUSR>>3)
end_define

begin_define
define|#
directive|define
name|S_IROTH
value|(S_IRUSR>>6)
end_define

begin_define
define|#
directive|define
name|S_IWOTH
value|(S_IWUSR>>6)
end_define

begin_define
define|#
directive|define
name|S_IXOTH
value|(S_IXUSR>>6)
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
value|04000
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
value|02000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|f_next
end_ifdef

begin_undef
undef|#
directive|undef
name|f_next
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|cray
argument_list|)
operator|||
name|defined
argument_list|(
name|gould
argument_list|)
operator|||
name|defined
argument_list|(
name|i860
argument_list|)
end_if

begin_define
define|#
directive|define
name|SLOPPYDIVIDE
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
name|cray
argument_list|)
operator|||
name|defined
argument_list|(
name|convex
argument_list|)
operator|||
name|defined
argument_list|(
name|uts
argument_list|)
operator|||
name|BYTEORDER
operator|>
literal|0xffff
end_if

begin_define
define|#
directive|define
name|QUAD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|QUAD
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|cray
end_ifdef

begin_define
define|#
directive|define
name|quad
value|int
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
name|convex
argument_list|)
operator|||
name|defined
argument_list|(
name|uts
argument_list|)
end_if

begin_define
define|#
directive|define
name|quad
value|long long
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|quad
value|long
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

begin_typedef
typedef|typedef
name|MEM_SIZE
name|STRLEN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|arg
name|ARG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cmd
name|CMD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|formcmd
name|FCMD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|scanpat
name|SPAT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|stio
name|STIO
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sub
name|SUBR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|string
name|STR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|atbl
name|ARRAY
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|htbl
name|HASH
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|regexp
name|REGEXP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|stabptrs
name|STBP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|stab
name|STAB
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|callsave
name|CSV
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"handy.h"
end_include

begin_include
include|#
directive|include
file|"regexp.h"
end_include

begin_include
include|#
directive|include
file|"str.h"
end_include

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_include
include|#
directive|include
file|"form.h"
end_include

begin_include
include|#
directive|include
file|"stab.h"
end_include

begin_include
include|#
directive|include
file|"spat.h"
end_include

begin_include
include|#
directive|include
file|"arg.h"
end_include

begin_include
include|#
directive|include
file|"cmd.h"
end_include

begin_include
include|#
directive|include
file|"array.h"
end_include

begin_include
include|#
directive|include
file|"hash.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|iAPX286
argument_list|)
operator|||
name|defined
argument_list|(
name|M_I286
argument_list|)
operator|||
name|defined
argument_list|(
name|I80286
argument_list|)
end_if

begin_define
define|#
directive|define
name|I286
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STANDARD_C
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|CHARSPRINTF
end_ifdef

begin_function_decl
name|char
modifier|*
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|sprintf
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

begin_decl_stmt
name|EXT
name|char
modifier|*
name|Yes
name|INIT
argument_list|(
literal|"1"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|No
name|INIT
argument_list|(
literal|""
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "gimme" values */
end_comment

begin_comment
comment|/* Note: cmd.c assumes that it can use&& to produce one of these values! */
end_comment

begin_define
define|#
directive|define
name|G_SCALAR
value|0
end_define

begin_define
define|#
directive|define
name|G_ARRAY
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CRIPPLED_CC
end_ifdef

begin_function_decl
name|int
name|str_true
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !CRIPPLED_CC */
end_comment

begin_define
define|#
directive|define
name|str_true
parameter_list|(
name|str
parameter_list|)
value|(Str = (str), \ 	(Str->str_pok ? \ 	    ((*Str->str_ptr> '0' || \ 	      Str->str_cur> 1 || \ 	      (Str->str_cur&& *Str->str_ptr != '0')) ? 1 : 0) \ 	: \ 	    (Str->str_nok ? (Str->str_u.str_nval != 0.0) : 0 ) ))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRIPPLED_CC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_define
define|#
directive|define
name|str_peek
parameter_list|(
name|str
parameter_list|)
value|(Str = (str), \ 	(Str->str_pok ? \ 	    Str->str_ptr : \ 	    (Str->str_nok ? \ 		(sprintf(tokenbuf,"num(%g)",Str->str_u.str_nval), \ 		    (char*)tokenbuf) : \ 		"" )))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CRIPPLED_CC
end_ifdef

begin_function_decl
name|char
modifier|*
name|str_get
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|TAINT
end_ifdef

begin_define
define|#
directive|define
name|str_get
parameter_list|(
name|str
parameter_list|)
value|(Str = (str), tainted |= Str->str_tainted, \ 	(Str->str_pok ? Str->str_ptr : str_2ptr(Str)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|str_get
parameter_list|(
name|str
parameter_list|)
value|(Str = (str), (Str->str_pok ? Str->str_ptr : str_2ptr(Str)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TAINT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRIPPLED_CC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CRIPPLED_CC
end_ifdef

begin_function_decl
name|double
name|str_gnum
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !CRIPPLED_CC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TAINT
end_ifdef

begin_define
define|#
directive|define
name|str_gnum
parameter_list|(
name|str
parameter_list|)
value|(Str = (str), tainted |= Str->str_tainted, \ 	(Str->str_nok ? Str->str_u.str_nval : str_2num(Str)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !TAINT */
end_comment

begin_define
define|#
directive|define
name|str_gnum
parameter_list|(
name|str
parameter_list|)
value|(Str = (str), (Str->str_nok ? Str->str_u.str_nval : str_2num(Str)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TAINT*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRIPPLED_CC */
end_comment

begin_decl_stmt
name|EXT
name|STR
modifier|*
name|Str
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GROWSTR
parameter_list|(
name|pp
parameter_list|,
name|lp
parameter_list|,
name|len
parameter_list|)
value|if (*(lp)< (len)) growstr(pp,lp,len)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DOSISH
end_ifndef

begin_define
define|#
directive|define
name|STR_GROW
parameter_list|(
name|str
parameter_list|,
name|len
parameter_list|)
value|if ((str)->str_len< (len)) str_grow(str,len)
end_define

begin_define
define|#
directive|define
name|Str_Grow
value|str_grow
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* extra parentheses intentionally NOT placed around "len"! */
end_comment

begin_define
define|#
directive|define
name|STR_GROW
parameter_list|(
name|str
parameter_list|,
name|len
parameter_list|)
value|if ((str)->str_len< (unsigned long)len) \ 		str_grow(str,(unsigned long)len)
end_define

begin_define
define|#
directive|define
name|Str_Grow
parameter_list|(
name|str
parameter_list|,
name|len
parameter_list|)
value|str_grow(str,(unsigned long)(len))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DOSISH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BYTEORDER
end_ifndef

begin_define
define|#
directive|define
name|BYTEORDER
value|0x1234
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
name|htonl
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAS_HTONL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAS_HTONL
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
name|htons
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAS_HTONS
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAS_HTONS
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
name|ntohl
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAS_NTOHL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAS_NTOHL
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
name|ntohs
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAS_NTOHS
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAS_NTOHS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_HTONL
end_ifndef

begin_if
if|#
directive|if
operator|(
name|BYTEORDER
operator|&
literal|0xffff
operator|)
operator|!=
literal|0x4321
end_if

begin_define
define|#
directive|define
name|HAS_HTONS
end_define

begin_define
define|#
directive|define
name|HAS_HTONL
end_define

begin_define
define|#
directive|define
name|HAS_NTOHS
end_define

begin_define
define|#
directive|define
name|HAS_NTOHL
end_define

begin_define
define|#
directive|define
name|MYSWAP
end_define

begin_define
define|#
directive|define
name|htons
value|my_swap
end_define

begin_define
define|#
directive|define
name|htonl
value|my_htonl
end_define

begin_define
define|#
directive|define
name|ntohs
value|my_swap
end_define

begin_define
define|#
directive|define
name|ntohl
value|my_ntohl
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
operator|(
name|BYTEORDER
operator|&
literal|0xffff
operator|)
operator|==
literal|0x4321
end_if

begin_undef
undef|#
directive|undef
name|HAS_HTONS
end_undef

begin_undef
undef|#
directive|undef
name|HAS_HTONL
end_undef

begin_undef
undef|#
directive|undef
name|HAS_NTOHS
end_undef

begin_undef
undef|#
directive|undef
name|HAS_NTOHL
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
comment|/*  * Little-endian byte order functions - 'v' for 'VAX', or 'reVerse'.  * -DWS  */
end_comment

begin_if
if|#
directive|if
name|BYTEORDER
operator|!=
literal|0x1234
end_if

begin_define
define|#
directive|define
name|HAS_VTOHL
end_define

begin_define
define|#
directive|define
name|HAS_VTOHS
end_define

begin_define
define|#
directive|define
name|HAS_HTOVL
end_define

begin_define
define|#
directive|define
name|HAS_HTOVS
end_define

begin_if
if|#
directive|if
name|BYTEORDER
operator|==
literal|0x4321
end_if

begin_define
define|#
directive|define
name|vtohl
parameter_list|(
name|x
parameter_list|)
value|((((x)&0xFF)<<24)	\ 			+(((x)>>24)&0xFF)	\ 			+(((x)&0x0000FF00)<<8)	\ 			+(((x)&0x00FF0000)>>8)	)
end_define

begin_define
define|#
directive|define
name|vtohs
parameter_list|(
name|x
parameter_list|)
value|((((x)&0xFF)<<8) + (((x)>>8)&0xFF))
end_define

begin_define
define|#
directive|define
name|htovl
parameter_list|(
name|x
parameter_list|)
value|vtohl(x)
end_define

begin_define
define|#
directive|define
name|htovs
parameter_list|(
name|x
parameter_list|)
value|vtohs(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* otherwise default to functions in util.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CASTNEGFLOAT
end_ifdef

begin_define
define|#
directive|define
name|U_S
parameter_list|(
name|what
parameter_list|)
value|((unsigned short)(what))
end_define

begin_define
define|#
directive|define
name|U_I
parameter_list|(
name|what
parameter_list|)
value|((unsigned int)(what))
end_define

begin_define
define|#
directive|define
name|U_L
parameter_list|(
name|what
parameter_list|)
value|((unsigned long)(what))
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|unsigned
name|long
name|castulong
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|U_S
parameter_list|(
name|what
parameter_list|)
value|((unsigned int)castulong(what))
end_define

begin_define
define|#
directive|define
name|U_I
parameter_list|(
name|what
parameter_list|)
value|((unsigned int)castulong(what))
end_define

begin_define
define|#
directive|define
name|U_L
parameter_list|(
name|what
parameter_list|)
value|(castulong(what))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|CMD
modifier|*
name|add_label
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|CMD
modifier|*
name|block_head
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|CMD
modifier|*
name|append_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|CMD
modifier|*
name|make_acmd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|CMD
modifier|*
name|make_ccmd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|CMD
modifier|*
name|make_icmd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|CMD
modifier|*
name|invert
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|CMD
modifier|*
name|addcond
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|CMD
modifier|*
name|addloop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|CMD
modifier|*
name|wopt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|CMD
modifier|*
name|over
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STAB
modifier|*
name|stabent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STAB
modifier|*
name|genstab
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|stab2arg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|op_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|make_op
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|make_match
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|make_split
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|rcatmaybe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|listish
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|maybelistish
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|localize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|fixeval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|jmaybe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|l
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|fixl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|mod_match
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|make_list
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|cmd_to_arg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|addflags
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|hide_ary
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|cval_to_arg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|str_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|stab_str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|apply
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_each
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_subr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_match
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_unpack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eval
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* this evaluates expressions */
end_comment

begin_function_decl
name|int
name|do_eval
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* this evaluates eval operator */
end_comment

begin_function_decl
name|int
name|do_assign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|SUBR
modifier|*
name|make_sub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FCMD
modifier|*
name|load_format
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|scanpat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|scansubst
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|scantrans
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|scanstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|scanident
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_append_till
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_gets
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_grow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|do_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|do_close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|do_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|do_aprint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|do_exec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|do_aexec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_subst
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cando
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ingroup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|whichsig
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|userinit
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CRYPTSCRIPT
end_ifdef

begin_function_decl
name|void
name|cryptswitch
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|str_replace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_inc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_dec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cmd_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arg_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|spat_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|regfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stab_clear
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_chop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_vop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_write
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_join
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_accept
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_pipe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_vecset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_unshift
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_execfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|magicalize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|magicname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|savelist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|saveitem
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|saveint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|savelong
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|savesptr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|savehptr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|restorelist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|repeatcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|make_form
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dehoist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|format
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|my_unexec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|warn
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_function_decl
name|void
name|dump_all
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dump_cmd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dump_arg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dump_flags
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dump_stab
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dump_spat
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
name|MSTATS
end_ifdef

begin_function_decl
name|void
name|mstats
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|HASH
modifier|*
name|savehash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARRAY
modifier|*
name|saveary
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|char
modifier|*
modifier|*
name|origargv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|origargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
modifier|*
name|origenviron
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|long
name|subline
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|STR
modifier|*
name|subname
name|INIT
parameter_list|(
name|Nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|int
name|arybase
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|outrec
block|{
name|long
name|o_lines
decl_stmt|;
name|char
modifier|*
name|o_str
decl_stmt|;
name|int
name|o_len
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|EXT
name|struct
name|outrec
name|outrec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|struct
name|outrec
name|toprec
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|STAB
modifier|*
name|stdinstab
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STAB
modifier|*
name|last_in_stab
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STAB
modifier|*
name|defstab
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STAB
modifier|*
name|argvstab
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STAB
modifier|*
name|envstab
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STAB
modifier|*
name|sigstab
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STAB
modifier|*
name|defoutstab
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STAB
modifier|*
name|curoutstab
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STAB
modifier|*
name|argvoutstab
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STAB
modifier|*
name|incstab
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STAB
modifier|*
name|leftstab
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STAB
modifier|*
name|amperstab
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STAB
modifier|*
name|rightstab
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STAB
modifier|*
name|DBstab
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STAB
modifier|*
name|DBline
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STAB
modifier|*
name|DBsub
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|HASH
modifier|*
name|defstash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* main symbol table */
end_comment

begin_decl_stmt
name|EXT
name|HASH
modifier|*
name|curstash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* symbol table for current package */
end_comment

begin_decl_stmt
name|EXT
name|HASH
modifier|*
name|debstash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* symbol table for perldb package */
end_comment

begin_decl_stmt
name|EXT
name|STR
modifier|*
name|curstname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of current package */
end_comment

begin_function_decl
name|EXT
name|STR
modifier|*
name|freestrroot
name|INIT
parameter_list|(
name|Nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STR
modifier|*
name|lastretstr
name|INIT
parameter_list|(
name|Nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STR
modifier|*
name|DBsingle
name|INIT
parameter_list|(
name|Nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STR
modifier|*
name|DBtrace
name|INIT
parameter_list|(
name|Nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STR
modifier|*
name|DBsignal
name|INIT
parameter_list|(
name|Nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STR
modifier|*
name|formfeed
name|INIT
parameter_list|(
name|Nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|int
name|lastspbase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|lastsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|hexdigit
name|INIT
argument_list|(
literal|"0123456789abcdef0123456789ABCDEFx"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|origfilename
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|FILE
modifier|*
name|VOLATILE
name|rsfp
name|INIT
parameter_list|(
name|Nullfp
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|char
name|buf
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|bufptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|oldbufptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|oldoldbufptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|bufend
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|STR
modifier|*
name|linestr
name|INIT
parameter_list|(
name|Nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|char
modifier|*
name|rs
name|INIT
argument_list|(
literal|"\n"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|rschar
name|INIT
argument_list|(
literal|'\n'
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* final char of rs, or 0777 if none */
end_comment

begin_decl_stmt
name|EXT
name|int
name|rslen
name|INIT
argument_list|(
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|bool
name|rspara
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|char
modifier|*
name|ofs
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|int
name|ofslen
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|char
modifier|*
name|ors
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|int
name|orslen
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|char
modifier|*
name|ofmt
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|char
modifier|*
name|inplace
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|char
modifier|*
name|nointrp
name|INIT
argument_list|(
literal|""
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|bool
name|preprocess
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|minus_n
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|minus_p
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|minus_l
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|minus_a
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|doswitches
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|dowarn
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|doextract
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|allstabs
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* init all customary symbols in symbol table?*/
end_comment

begin_function_decl
name|EXT
name|bool
name|sawampersand
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* must save all match strings */
end_comment

begin_function_decl
name|EXT
name|bool
name|sawstudy
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* do fbminstr on all strings */
end_comment

begin_function_decl
name|EXT
name|bool
name|sawi
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* study must assume case insensitive */
end_comment

begin_function_decl
name|EXT
name|bool
name|sawvec
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|localizing
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* are we processing a local() list? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXSYSFD
end_ifndef

begin_define
define|#
directive|define
name|MAXSYSFD
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|EXT
name|int
name|maxsysfd
name|INIT
parameter_list|(
name|MAXSYSFD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* top fd to pass to subprocesses */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CSH
end_ifdef

begin_function_decl
name|EXT
name|char
modifier|*
name|cshname
name|INIT
parameter_list|(
name|CSH
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|int
name|cshlen
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CSH */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TAINT
end_ifdef

begin_function_decl
name|EXT
name|bool
name|tainted
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* using variables controlled by $< */
end_comment

begin_function_decl
name|EXT
name|bool
name|taintanyway
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* force taint checks when !set?id */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|EXT
name|bool
name|nomemok
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* let malloc context handle nomem */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOSISH
end_ifndef

begin_define
define|#
directive|define
name|TMPPATH
value|"/tmp/perl-eXXXXXX"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TMPPATH
value|"plXXXXXX"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSDOS */
end_comment

begin_decl_stmt
name|EXT
name|char
modifier|*
name|e_tmpname
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|FILE
modifier|*
name|e_fp
name|INIT
parameter_list|(
name|Nullfp
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|char
name|tokenbuf
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|int
name|expectterm
name|INIT
parameter_list|(
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* how to interpret ambiguous tokens */
end_comment

begin_function_decl
name|EXT
name|VOLATILE
name|int
name|in_eval
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* trap fatal errors? */
end_comment

begin_decl_stmt
name|EXT
name|int
name|multiline
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $*--do strings hold>1 line? */
end_comment

begin_decl_stmt
name|EXT
name|int
name|forkprocess
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* so do_open |- can return proc# */
end_comment

begin_decl_stmt
name|EXT
name|int
name|do_undump
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -u or dump seen? */
end_comment

begin_decl_stmt
name|EXT
name|int
name|error_count
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how many errors so far, max 10 */
end_comment

begin_decl_stmt
name|EXT
name|int
name|multi_start
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1st line of multi-line string */
end_comment

begin_decl_stmt
name|EXT
name|int
name|multi_end
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last line of multi-line string */
end_comment

begin_decl_stmt
name|EXT
name|int
name|multi_open
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* delimiter of said string */
end_comment

begin_decl_stmt
name|EXT
name|int
name|multi_close
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* delimiter of said string */
end_comment

begin_function_decl
name|FILE
modifier|*
name|popen
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* char *str_get(); */
end_comment

begin_function_decl
name|STR
modifier|*
name|interp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_arg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STIO
modifier|*
name|stio_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hoistmust
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|scanconst
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|struct
name|stat
name|statbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|struct
name|stat
name|statcache
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|STAB
modifier|*
name|statstab
name|INIT
parameter_list|(
name|Nullstab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STR
modifier|*
name|statname
name|INIT
parameter_list|(
name|Nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|MSDOS
end_ifndef

begin_decl_stmt
name|EXT
name|struct
name|tms
name|timesbuf
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|int
name|uid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|euid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|gid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|egid
decl_stmt|;
end_decl_stmt

begin_function_decl
name|UIDTYPE
name|getuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|UIDTYPE
name|geteuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|GIDTYPE
name|getgid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|GIDTYPE
name|getegid
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|int
name|unsafe
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_decl_stmt
name|EXT
name|VOLATILE
name|int
name|debug
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|dlevel
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|dlmax
name|INIT
argument_list|(
literal|128
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|debname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|debdelim
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|YYDEBUG
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|int
name|perldb
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|YYMAXDEPTH
value|300
end_define

begin_function_decl
name|EXT
name|line_t
name|cmdline
name|INIT
parameter_list|(
name|NOLINE
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|STR
name|str_undef
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|STR
name|str_no
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|STR
name|str_yes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* runtime control stuff */
end_comment

begin_macro
name|EXT
end_macro

begin_struct
struct|struct
name|loop
block|{
name|char
modifier|*
name|loop_label
decl_stmt|;
comment|/* what the loop was called, if anything */
name|int
name|loop_sp
decl_stmt|;
comment|/* stack pointer to copy stuff down to */
name|jmp_buf
name|loop_env
decl_stmt|;
block|}
modifier|*
name|loop_stack
struct|;
end_struct

begin_decl_stmt
name|EXT
name|int
name|loop_ptr
name|INIT
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|loop_max
name|INIT
argument_list|(
literal|128
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|jmp_buf
name|top_env
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|char
modifier|*
name|VOLATILE
name|goto_targ
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cmd_exec gets strange when set */
end_comment

begin_struct
struct|struct
name|ufuncs
block|{
name|int
function_decl|(
modifier|*
name|uf_val
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|uf_set
function_decl|)
parameter_list|()
function_decl|;
name|int
name|uf_index
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|EXT
name|ARRAY
modifier|*
name|stack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* THE STACK */
end_comment

begin_decl_stmt
name|EXT
name|ARRAY
modifier|*
name|VOLATILE
name|savestack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* to save non-local values on */
end_comment

begin_decl_stmt
name|EXT
name|ARRAY
modifier|*
name|tosave
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* strings to save on recursive subroutine */
end_comment

begin_decl_stmt
name|EXT
name|ARRAY
modifier|*
name|lineary
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lines of script for debugger */
end_comment

begin_decl_stmt
name|EXT
name|ARRAY
modifier|*
name|dbargs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* args to call listed by caller function */
end_comment

begin_decl_stmt
name|EXT
name|ARRAY
modifier|*
name|fdpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keep fd-to-pid mappings for mypopen */
end_comment

begin_decl_stmt
name|EXT
name|HASH
modifier|*
name|pidstatus
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keep pid-to-status mappings for waitpid */
end_comment

begin_decl_stmt
name|EXT
name|int
modifier|*
name|di
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for tmp use in debuggers */
end_comment

begin_decl_stmt
name|EXT
name|char
modifier|*
name|dc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|short
modifier|*
name|ds
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fix these up for __STDC__ */
end_comment

begin_decl_stmt
name|EXT
name|time_t
name|basetime
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|mktemp
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|STANDARD_C
end_ifndef

begin_comment
comment|/* All of these are in stdlib.h or time.h for ANSI C */
end_comment

begin_function_decl
name|double
name|atof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|tm
modifier|*
name|gmtime
argument_list|()
decl_stmt|,
modifier|*
name|localtime
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|index
argument_list|()
decl_stmt|,
modifier|*
name|rindex
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|strcat
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! STANDARD_C */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EUNICE
end_ifdef

begin_define
define|#
directive|define
name|UNLINK
value|unlnk
end_define

begin_function_decl
name|int
name|unlnk
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNLINK
value|unlink
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_SETREUID
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SETRESUID
end_ifdef

begin_define
define|#
directive|define
name|setreuid
parameter_list|(
name|r
parameter_list|,
name|e
parameter_list|)
value|setresuid(r,e,-1)
end_define

begin_define
define|#
directive|define
name|HAS_SETREUID
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
name|HAS_SETREGID
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SETRESGID
end_ifdef

begin_define
define|#
directive|define
name|setregid
parameter_list|(
name|r
parameter_list|,
name|e
parameter_list|)
value|setresgid(r,e,-1)
end_define

begin_define
define|#
directive|define
name|HAS_SETREGID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SCAN_DEF
value|0
end_define

begin_define
define|#
directive|define
name|SCAN_TR
value|1
end_define

begin_define
define|#
directive|define
name|SCAN_REPL
value|2
end_define

end_unit

