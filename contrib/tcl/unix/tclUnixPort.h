begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * tclUnixPort.h --  *  *	This header file handles porting issues that occur because  *	of differences between systems.  It reads in UNIX-related  *	header files and sets up UNIX-related macros for Tcl's UNIX  *	core.  It should be the only file that contains #ifdefs to  *	handle different flavors of UNIX.  This file sets up the  *	union of all UNIX-related things needed by any of the Tcl  *	core files.  This file depends on configuration #defines such  *	as NO_DIRENT_H that are set up by the "configure" script.  *  *	Much of the material in this file was originally contributed  *	by Karl Lehenbauer, Mark Diekhans and Peter da Silva.  *  * Copyright (c) 1991-1994 The Regents of the University of California.  * Copyright (c) 1994-1995 Sun Microsystems, Inc.  *  * See the file "license.terms" for information on usage and redistribution  * of this file, and for a DISCLAIMER OF ALL WARRANTIES.  *  * SCCS: @(#) tclUnixPort.h 1.49 97/07/30 14:11:59  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TCLUNIXPORT
end_ifndef

begin_define
define|#
directive|define
name|_TCLUNIXPORT
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_TCLINT
end_ifndef

begin_include
include|#
directive|include
file|"tclInt.h"
end_include

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
name|HAVE_NET_ERRNO_H
end_ifdef

begin_include
include|#
directive|include
file|<net/errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_DIRENT2_H
end_ifdef

begin_include
include|#
directive|include
file|"../compat/dirent2.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|NO_DIRENT_H
end_ifdef

begin_include
include|#
directive|include
file|"../compat/dirent.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<dirent.h>
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
file|<sys/file.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SELECT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/select.h>
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

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SYS_WAIT_H
end_ifndef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"../compat/unistd.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_FIONBIO
end_ifdef

begin_comment
comment|/*      * Not using the Posix fcntl(...,O_NONBLOCK,...) interface, instead      * we are using ioctl(..,FIONBIO,..).      */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FILIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_comment
comment|/* For FIONBIO. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_IOCTL_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_comment
comment|/* For FIONBIO. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_FIONBIO */
end_comment

begin_comment
comment|/*  * Socket support stuff: This likely needs more work to parameterize for  * each system.  */
end_comment

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_comment
comment|/* struct sockaddr, SOCK_STREAM, ... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_UNAME
end_ifndef

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_comment
comment|/* uname system call. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/* struct in_addr, struct sockaddr_in */
end_comment

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_comment
comment|/* inet_ntoa() */
end_comment

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_comment
comment|/* gethostbyname() */
end_comment

begin_comment
comment|/*  * Some platforms (e.g. SunOS) don't define FLT_MAX and FLT_MIN, so we  * look for an alternative definition.  If no other alternative is available  * we use a reasonable guess.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_FLOAT_H
end_ifndef

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|NO_VALUES_H
end_ifndef

begin_include
include|#
directive|include
file|<values.h>
end_include

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
name|FLT_MAX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MAXFLOAT
end_ifdef

begin_define
define|#
directive|define
name|FLT_MAX
value|MAXFLOAT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FLT_MAX
value|3.402823466E+38F
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
name|FLT_MIN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MINFLOAT
end_ifdef

begin_define
define|#
directive|define
name|FLT_MIN
value|MINFLOAT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FLT_MIN
value|1.175494351E-38F
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
comment|/*  * NeXT doesn't define O_NONBLOCK, so #define it here if necessary.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|O_NONBLOCK
end_ifndef

begin_define
define|#
directive|define
name|O_NONBLOCK
value|0x80
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * HPUX needs the flag O_NONBLOCK to get the right non-blocking I/O  * semantics, while most other systems need O_NDELAY.  Define the  * constant NBIO_FLAG to be one of these  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX
end_ifdef

begin_define
define|#
directive|define
name|NBIO_FLAG
value|O_NONBLOCK
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NBIO_FLAG
value|O_NDELAY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following defines denote malloc and free as the system calls  * used to allocate new memory.  These defines are only used in the  * file tclCkalloc.c.  */
end_comment

begin_define
define|#
directive|define
name|TclpAlloc
parameter_list|(
name|size
parameter_list|)
value|malloc(size)
end_define

begin_define
define|#
directive|define
name|TclpFree
parameter_list|(
name|ptr
parameter_list|)
value|free(ptr)
end_define

begin_define
define|#
directive|define
name|TclpRealloc
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
value|realloc(ptr, size)
end_define

begin_comment
comment|/*  * The default platform eol translation on Unix is TCL_TRANSLATE_LF:  */
end_comment

begin_define
define|#
directive|define
name|TCL_PLATFORM_TRANSLATION
value|TCL_TRANSLATE_LF
end_define

begin_comment
comment|/*  * Not all systems declare the errno variable in errno.h. so this  * file does it explicitly.  The list of system error messages also  * isn't generally declared in a header file anywhere.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The type of the status returned by wait varies from UNIX system  * to UNIX system.  The macro below defines it:  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_define
define|#
directive|define
name|WAIT_STATUS_TYPE
value|pid_t
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|NO_UNION_WAIT
end_ifndef

begin_define
define|#
directive|define
name|WAIT_STATUS_TYPE
value|union wait
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WAIT_STATUS_TYPE
value|int
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
comment|/*  * Supply definitions for macros to query wait status, if not already  * defined in header files above.  */
end_comment

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
name|stat
parameter_list|)
value|(((*((int *)&(stat)))& 0xff) == 0)
end_define

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
name|stat
parameter_list|)
value|(((*((int *)&(stat)))>> 8)& 0xff)
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
name|stat
parameter_list|)
value|(((*((int *)&(stat))))&& ((*((int *)&(stat))) == ((*((int *)&(stat)))& 0x00ff)))
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
name|stat
parameter_list|)
value|((*((int *)&(stat)))& 0x7f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WIFSTOPPED
end_ifndef

begin_define
define|#
directive|define
name|WIFSTOPPED
parameter_list|(
name|stat
parameter_list|)
value|(((*((int *)&(stat)))& 0xff) == 0177)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WSTOPSIG
end_ifndef

begin_define
define|#
directive|define
name|WSTOPSIG
parameter_list|(
name|stat
parameter_list|)
value|(((*((int *)&(stat)))>> 8)& 0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define constants for waitpid() system call if they aren't defined  * by a system header file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WNOHANG
end_ifndef

begin_define
define|#
directive|define
name|WNOHANG
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WUNTRACED
end_ifndef

begin_define
define|#
directive|define
name|WUNTRACED
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Supply macros for seek offsets, if they're not already provided by  * an include file.  */
end_comment

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

begin_comment
comment|/*  * The stuff below is needed by the "time" command.  If this  * system has no gettimeofday call, then must use times and the  * CLK_TCK #define (from sys/param.h) to compute elapsed time.  * Unfortunately, some systems only have HZ and no CLK_TCK, and  * some might not even have HZ.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_GETTOD
end_ifdef

begin_include
include|#
directive|include
file|<sys/times.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|CLK_TCK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HZ
end_ifdef

begin_define
define|#
directive|define
name|CLK_TCK
value|HZ
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CLK_TCK
value|60
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BSDGETTIMEOFDAY
end_ifdef

begin_define
define|#
directive|define
name|gettimeofday
value|BSDgettimeofday
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
name|GETTOD_NOT_DECLARED
end_ifdef

begin_decl_stmt
name|EXTERN
name|int
name|gettimeofday
name|_ANSI_ARGS_
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
name|tp
operator|,
expr|struct
name|timezone
operator|*
name|tzp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define access mode constants if they aren't already defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|F_OK
end_ifndef

begin_define
define|#
directive|define
name|F_OK
value|00
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|X_OK
end_ifndef

begin_define
define|#
directive|define
name|X_OK
value|01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|W_OK
end_ifndef

begin_define
define|#
directive|define
name|W_OK
value|02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|R_OK
end_ifndef

begin_define
define|#
directive|define
name|R_OK
value|04
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define FD_CLOEEXEC (the close-on-exec flag bit) if it isn't  * already defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FD_CLOEXEC
end_ifndef

begin_define
define|#
directive|define
name|FD_CLOEXEC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * On systems without symbolic links (i.e. S_IFLNK isn't defined)  * define "lstat" to use "stat" instead.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFLNK
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
comment|/*  * Define macros to query file type bits, if they're not already  * defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISREG
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFREG
end_ifdef

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
name|S_ISDIR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFDIR
end_ifdef

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
comment|/*  * Make sure that MAXPATHLEN is defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PATH_MAX
end_ifdef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATH_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXPATHLEN
value|2048
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
comment|/*  * Make sure that L_tmpnam is defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|L_tmpnam
end_ifndef

begin_define
define|#
directive|define
name|L_tmpnam
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following macro defines the type of the mask arguments to  * select:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_FD_SET
end_ifndef

begin_define
define|#
directive|define
name|SELECT_MASK
value|fd_set
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|_AIX
end_ifndef

begin_typedef
typedef|typedef
name|long
name|fd_mask
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_IBMR2
argument_list|)
end_if

begin_define
define|#
directive|define
name|SELECT_MASK
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SELECT_MASK
value|int
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
comment|/*  * Define "NBBY" (number of bits per byte) if it's not already defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NBBY
end_ifndef

begin_define
define|#
directive|define
name|NBBY
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following macro defines the number of fd_masks in an fd_set:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FD_SETSIZE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|OPEN_MAX
end_ifdef

begin_define
define|#
directive|define
name|FD_SETSIZE
value|OPEN_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FD_SETSIZE
value|256
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
name|howmany
argument_list|)
end_if

begin_define
define|#
directive|define
name|howmany
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)+((y)-1))/(y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFDBITS
end_ifndef

begin_define
define|#
directive|define
name|NFDBITS
value|NBBY*sizeof(fd_mask)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MASK_SIZE
value|howmany(FD_SETSIZE, NFDBITS)
end_define

begin_comment
comment|/*  * The following implements the Unix method for exiting the process.  */
end_comment

begin_define
define|#
directive|define
name|TclPlatformExit
parameter_list|(
name|status
parameter_list|)
value|exit(status)
end_define

begin_comment
comment|/*  * The following functions always succeeds under Unix.  */
end_comment

begin_define
define|#
directive|define
name|TclHasSockets
parameter_list|(
name|interp
parameter_list|)
value|(TCL_OK)
end_define

begin_define
define|#
directive|define
name|TclHasPipes
parameter_list|()
value|(1)
end_define

begin_comment
comment|/*  * Variables provided by the C library:  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if

begin_define
define|#
directive|define
name|environ
value|_environ
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * At present (12/91) not all stdlib.h implementations declare strtod.  * The declaration below is here to ensure that it's declared, so that  * the compiler won't take the default approach of assuming it returns  * an int.  There's no ANSI prototype for it because there would end  * up being too many conflicts with slightly-different prototypes.  */
end_comment

begin_function_decl
specifier|extern
name|double
name|strtod
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * The following macros define time related functions in terms of  * standard Unix routines.  */
end_comment

begin_define
define|#
directive|define
name|TclpGetDate
parameter_list|(
name|t
parameter_list|,
name|u
parameter_list|)
value|((u) ? gmtime((t)) : localtime((t)))
end_define

begin_define
define|#
directive|define
name|TclStrftime
parameter_list|(
name|s
parameter_list|,
name|m
parameter_list|,
name|f
parameter_list|,
name|t
parameter_list|)
value|(strftime((s),(m),(f),(t)))
end_define

begin_define
define|#
directive|define
name|TclpGetPid
parameter_list|(
name|pid
parameter_list|)
value|((unsigned long) (pid))
end_define

begin_define
define|#
directive|define
name|TclpReleaseFile
parameter_list|(
name|file
parameter_list|)
end_define

begin_comment
comment|/*  * The following routine is only exported for testing purposes.  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|TclUnixWaitForFile
name|_ANSI_ARGS_
argument_list|(
operator|(
name|int
name|fd
operator|,
name|int
name|mask
operator|,
name|int
name|timeout
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TCLUNIXPORT */
end_comment

end_unit

