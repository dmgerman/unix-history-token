begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RCS compile-time configuration */
end_comment

begin_comment
comment|/* $Id: conf.sh,v 5.14 1991/11/20 18:21:10 eggert Exp $ */
end_comment

begin_comment
comment|/*  * This file is generated automatically.  * If you edit it by hand your changes may be lost.  * Instead, please try to fix conf.sh,  * and send your fixes to rcs-bugs@cs.purdue.edu.  */
end_comment

begin_define
define|#
directive|define
name|exitmain
parameter_list|(
name|n
parameter_list|)
value|return n
end_define

begin_comment
comment|/* how to exit from main() */
end_comment

begin_comment
comment|/* #define _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Define this if Posix + strict Standard C.  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|/* Comment out #include lines below that do not work.  */
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

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<utime.h>
end_include

begin_comment
comment|/* #include<vfork.h> */
end_comment

begin_comment
comment|/* Define the following symbols to be 1 or 0.  */
end_comment

begin_define
define|#
directive|define
name|has_sys_dir_h
value|1
end_define

begin_comment
comment|/* Does #include<sys/dir.h> work?  */
end_comment

begin_define
define|#
directive|define
name|has_sys_param_h
value|1
end_define

begin_comment
comment|/* Does #include<sys/param.h> work?  */
end_comment

begin_define
define|#
directive|define
name|has_readlink
value|1
end_define

begin_comment
comment|/* Does readlink() work?  */
end_comment

begin_comment
comment|/* #undef NAME_MAX */
end_comment

begin_comment
comment|/* Uncomment this if NAME_MAX is broken.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NAME_MAX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_NAME_MAX
argument_list|)
end_if

begin_if
if|#
directive|if
name|has_sys_dir_h
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

begin_ifndef
ifndef|#
directive|ifndef
name|NAME_MAX
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|MAXNAMLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXNAMLEN
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NAME_MAX
value|MAXNAMLEN
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
name|PATH_MAX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_PATH_MAX
argument_list|)
end_if

begin_if
if|#
directive|if
name|has_sys_param_h
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_define
define|#
directive|define
name|included_sys_param_h
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_MAX
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PATH_MAX
value|(MAXPATHLEN-1)
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
name|has_readlink
operator|&&
operator|!
name|defined
argument_list|(
name|MAXSYMLINKS
argument_list|)
end_if

begin_if
if|#
directive|if
name|has_sys_param_h
operator|&&
operator|!
name|included_sys_param_h
end_if

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
name|MAXSYMLINKS
end_ifndef

begin_define
define|#
directive|define
name|MAXSYMLINKS
value|20
end_define

begin_comment
comment|/* BSD; not standard yet */
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
comment|/* Comment out the keyword definitions below if the keywords work.  */
end_comment

begin_comment
comment|/* #define const */
end_comment

begin_comment
comment|/* #define volatile */
end_comment

begin_comment
comment|/* Comment out the typedefs below if the types are already declared.  */
end_comment

begin_comment
comment|/* Fix any uncommented typedefs that are wrong.  */
end_comment

begin_comment
comment|/* typedef int mode_t; */
end_comment

begin_comment
comment|/* typedef int pid_t; */
end_comment

begin_typedef
typedef|typedef
name|int
name|sig_atomic_t
typedef|;
end_typedef

begin_comment
comment|/* typedef unsigned size_t; */
end_comment

begin_comment
comment|/* typedef int ssize_t; */
end_comment

begin_comment
comment|/* typedef long time_t; */
end_comment

begin_comment
comment|/* typedef int uid_t; */
end_comment

begin_comment
comment|/* Define the following symbols to be 1 or 0.  */
end_comment

begin_define
define|#
directive|define
name|has_prototypes
value|1
end_define

begin_comment
comment|/* Do function prototypes work?  */
end_comment

begin_define
define|#
directive|define
name|has_stdarg
value|1
end_define

begin_comment
comment|/* Does<stdarg.h> work?  */
end_comment

begin_define
define|#
directive|define
name|has_varargs
value|0
end_define

begin_comment
comment|/* Does<varargs.h> work?  */
end_comment

begin_define
define|#
directive|define
name|va_start_args
value|2
end_define

begin_comment
comment|/* How many args does va_start() take?  */
end_comment

begin_if
if|#
directive|if
name|has_prototypes
end_if

begin_define
define|#
directive|define
name|P
parameter_list|(
name|params
parameter_list|)
value|params
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|params
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|has_stdarg
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|has_varargs
end_if

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|va_dcl
value|int va_alist;
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|)
value|((ap) = (va_list)&va_alist)
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|ap
parameter_list|,
name|t
parameter_list|)
value|(((t*) ((ap)+=sizeof(t)))  [-1])
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|ap
parameter_list|)
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
name|va_start_args
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|vararg_start
value|va_start
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vararg_start
parameter_list|(
name|ap
parameter_list|,
name|p
parameter_list|)
value|va_start(ap)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|text_equals_binary_stdio
value|1
end_define

begin_comment
comment|/* Does stdio treat text like binary?  */
end_comment

begin_define
define|#
directive|define
name|text_work_stdio
value|0
end_define

begin_comment
comment|/* Text i/o for working file, binary for RCS file?  */
end_comment

begin_if
if|#
directive|if
name|text_equals_binary_stdio
end_if

begin_comment
comment|/* Text and binary i/o behave the same, or binary i/o does not work.  */
end_comment

begin_define
define|#
directive|define
name|FOPEN_R
value|"r"
end_define

begin_define
define|#
directive|define
name|FOPEN_W
value|"w"
end_define

begin_define
define|#
directive|define
name|FOPEN_WPLUS
value|"w+"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Text and binary i/o behave differently.  */
end_comment

begin_comment
comment|/* This is incompatible with Posix and Unix.  */
end_comment

begin_define
define|#
directive|define
name|FOPEN_R
value|"rb"
end_define

begin_define
define|#
directive|define
name|FOPEN_W
value|"wb"
end_define

begin_define
define|#
directive|define
name|FOPEN_WPLUS
value|"w+b"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|text_work_stdio
end_if

begin_define
define|#
directive|define
name|FOPEN_R_WORK
value|"r"
end_define

begin_define
define|#
directive|define
name|FOPEN_W_WORK
value|"w"
end_define

begin_define
define|#
directive|define
name|FOPEN_WPLUS_WORK
value|"w+"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FOPEN_R_WORK
value|FOPEN_R
end_define

begin_define
define|#
directive|define
name|FOPEN_W_WORK
value|FOPEN_W
end_define

begin_define
define|#
directive|define
name|FOPEN_WPLUS_WORK
value|FOPEN_WPLUS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define or comment out the following symbols as needed.  */
end_comment

begin_define
define|#
directive|define
name|bad_fopen_wplus
value|0
end_define

begin_comment
comment|/* Does fopen(f,FOPEN_WPLUS) fail to truncate f?  */
end_comment

begin_define
define|#
directive|define
name|getlogin_is_secure
value|0
end_define

begin_comment
comment|/* Is getlogin() secure?  Usually it's not.  */
end_comment

begin_define
define|#
directive|define
name|has_dirent
value|1
end_define

begin_comment
comment|/* Do opendir(), readdir(), closedir() work?  */
end_comment

begin_define
define|#
directive|define
name|has_fchmod
value|0
end_define

begin_comment
comment|/* Does fchmod() work?  */
end_comment

begin_define
define|#
directive|define
name|has_fputs
value|0
end_define

begin_comment
comment|/* Does fputs() work?  */
end_comment

begin_define
define|#
directive|define
name|has_ftruncate
value|1
end_define

begin_comment
comment|/* Does ftruncate() work?  */
end_comment

begin_define
define|#
directive|define
name|has_getuid
value|1
end_define

begin_comment
comment|/* Does getuid() work?  */
end_comment

begin_define
define|#
directive|define
name|has_getpwuid
value|1
end_define

begin_comment
comment|/* Does getpwuid() work?  */
end_comment

begin_define
define|#
directive|define
name|has_link
value|1
end_define

begin_comment
comment|/* Does link() work?  */
end_comment

begin_define
define|#
directive|define
name|has_memcmp
value|1
end_define

begin_comment
comment|/* Does memcmp() work?  */
end_comment

begin_define
define|#
directive|define
name|has_memcpy
value|1
end_define

begin_comment
comment|/* Does memcpy() work?  */
end_comment

begin_define
define|#
directive|define
name|has_memmove
value|1
end_define

begin_comment
comment|/* Does memmove() work?  */
end_comment

begin_define
define|#
directive|define
name|has_madvise
value|0
end_define

begin_comment
comment|/* Does madvise() work?  */
end_comment

begin_define
define|#
directive|define
name|has_mmap
value|0
end_define

begin_comment
comment|/* Does mmap() work on regular files?  */
end_comment

begin_define
define|#
directive|define
name|has_rename
value|1
end_define

begin_comment
comment|/* Does rename() work?  */
end_comment

begin_define
define|#
directive|define
name|bad_a_rename
value|0
end_define

begin_comment
comment|/* Does rename(A,B) fail if A is unwritable?  */
end_comment

begin_define
define|#
directive|define
name|bad_b_rename
value|0
end_define

begin_comment
comment|/* Does rename(A,B) fail if B is unwritable?  */
end_comment

begin_define
define|#
directive|define
name|VOID
value|(void)
end_define

begin_comment
comment|/* 'VOID e;' discards the value of an expression 'e'.  */
end_comment

begin_define
define|#
directive|define
name|has_seteuid
value|0
end_define

begin_comment
comment|/* Does seteuid() work?  See README.  */
end_comment

begin_define
define|#
directive|define
name|has_setuid
value|1
end_define

begin_comment
comment|/* Does setuid() exist?  */
end_comment

begin_define
define|#
directive|define
name|has_signal
value|1
end_define

begin_comment
comment|/* Does signal() work?  */
end_comment

begin_define
define|#
directive|define
name|signal_args
value|P((int))
end_define

begin_comment
comment|/* arguments of signal handlers */
end_comment

begin_define
define|#
directive|define
name|signal_type
value|void
end_define

begin_comment
comment|/* type returned by signal handlers */
end_comment

begin_define
define|#
directive|define
name|sig_zaps_handler
value|0
end_define

begin_comment
comment|/* Must a signal handler reinvoke signal()?  */
end_comment

begin_define
define|#
directive|define
name|has_sigaction
value|1
end_define

begin_comment
comment|/* Does struct sigaction work?  */
end_comment

begin_comment
comment|/* #define has_sigblock ? */
end_comment

begin_comment
comment|/* Does sigblock() work?  */
end_comment

begin_comment
comment|/* #define sigmask(s) (1<< ((s)-1)) */
end_comment

begin_comment
comment|/* Yield mask for signal number.  */
end_comment

begin_define
define|#
directive|define
name|has_sys_siglist
value|0
end_define

begin_comment
comment|/* Does sys_siglist[] work?  */
end_comment

begin_typedef
typedef|typedef
name|ssize_t
name|fread_type
typedef|;
end_typedef

begin_comment
comment|/* type returned by fread() and fwrite() */
end_comment

begin_typedef
typedef|typedef
name|size_t
name|freadarg_type
typedef|;
end_typedef

begin_comment
comment|/* type of their size arguments */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|malloc_type
typedef|;
end_typedef

begin_comment
comment|/* type returned by malloc() */
end_comment

begin_define
define|#
directive|define
name|has_getcwd
value|1
end_define

begin_comment
comment|/* Does getcwd() work?  */
end_comment

begin_comment
comment|/* #define has_getwd ? */
end_comment

begin_comment
comment|/* Does getwd() work?  */
end_comment

begin_define
define|#
directive|define
name|has_mktemp
value|1
end_define

begin_comment
comment|/* Does mktemp() work?  */
end_comment

begin_define
define|#
directive|define
name|has_NFS
value|1
end_define

begin_comment
comment|/* Might NFS be used?  */
end_comment

begin_comment
comment|/* #define strchr index */
end_comment

begin_comment
comment|/* Use old-fashioned name for strchr()?  */
end_comment

begin_comment
comment|/* #define strrchr rindex */
end_comment

begin_comment
comment|/* Use old-fashioned name for strrchr()?  */
end_comment

begin_define
define|#
directive|define
name|bad_unlink
value|0
end_define

begin_comment
comment|/* Does unlink() fail on unwritable files?  */
end_comment

begin_define
define|#
directive|define
name|has_vfork
value|0
end_define

begin_comment
comment|/* Does vfork() work?  */
end_comment

begin_define
define|#
directive|define
name|has_fork
value|1
end_define

begin_comment
comment|/* Does fork() work?  */
end_comment

begin_define
define|#
directive|define
name|has_spawn
value|0
end_define

begin_comment
comment|/* Does spawn*() work?  */
end_comment

begin_define
define|#
directive|define
name|has_wait
value|1
end_define

begin_comment
comment|/* Does wait() work?  */
end_comment

begin_define
define|#
directive|define
name|has_waitpid
value|0
end_define

begin_comment
comment|/* Does waitpid() work?  */
end_comment

begin_define
define|#
directive|define
name|RCS_SHELL
value|"/bin/sh"
end_define

begin_comment
comment|/* shell to run RCS subprograms */
end_comment

begin_define
define|#
directive|define
name|has_vfprintf
value|1
end_define

begin_comment
comment|/* Does vfprintf() work?  */
end_comment

begin_comment
comment|/* #define has__doprintf ? */
end_comment

begin_comment
comment|/* Does _doprintf() work?  */
end_comment

begin_comment
comment|/* #define has__doprnt ? */
end_comment

begin_comment
comment|/* Does _doprnt() work?  */
end_comment

begin_comment
comment|/* #undef EXIT_FAILURE */
end_comment

begin_comment
comment|/* Uncomment this if EXIT_FAILURE is broken.  */
end_comment

begin_define
define|#
directive|define
name|large_memory
value|0
end_define

begin_comment
comment|/* Can main memory hold entire RCS files?  */
end_comment

begin_comment
comment|/* #undef ULONG_MAX */
end_comment

begin_comment
comment|/* Uncomment this if ULONG_MAX is broken (e.g.< 0).  */
end_comment

begin_comment
comment|/* struct utimbuf { time_t actime, modtime; }; */
end_comment

begin_comment
comment|/* Uncomment this if needed.  */
end_comment

begin_define
define|#
directive|define
name|CO
value|"/usr/bin/co"
end_define

begin_comment
comment|/* name of 'co' program */
end_comment

begin_define
define|#
directive|define
name|COMPAT2
value|0
end_define

begin_comment
comment|/* Are version 2 files supported?  */
end_comment

begin_define
define|#
directive|define
name|DATEFORM
value|"%.2d.%.2d.%.2d.%.2d.%.2d.%.2d"
end_define

begin_comment
comment|/* e.g. 01.01.01.01.01.01 */
end_comment

begin_define
define|#
directive|define
name|DIFF
value|"/usr/bin/diff"
end_define

begin_comment
comment|/* name of 'diff' program */
end_comment

begin_define
define|#
directive|define
name|DIFF3
value|"/usr/bin/diff3"
end_define

begin_comment
comment|/* name of 'diff3' program */
end_comment

begin_define
define|#
directive|define
name|DIFF3_BIN
value|1
end_define

begin_comment
comment|/* Is diff3 user-visible (not the /usr/lib auxiliary)?  */
end_comment

begin_define
define|#
directive|define
name|DIFF_FLAGS
value|, "-an"
end_define

begin_comment
comment|/* Make diff output suitable for RCS.  */
end_comment

begin_define
define|#
directive|define
name|DIFF_L
value|1
end_define

begin_comment
comment|/* Does diff -L work? */
end_comment

begin_define
define|#
directive|define
name|DIFF_SUCCESS
value|0
end_define

begin_comment
comment|/* DIFF status if no differences are found */
end_comment

begin_define
define|#
directive|define
name|DIFF_FAILURE
value|1
end_define

begin_comment
comment|/* DIFF status if differences are found */
end_comment

begin_define
define|#
directive|define
name|DIFF_TROUBLE
value|2
end_define

begin_comment
comment|/* DIFF status if trouble */
end_comment

begin_define
define|#
directive|define
name|ED
value|"/bin/ed"
end_define

begin_comment
comment|/* name of 'ed' program (used only if !DIFF3_BIN) */
end_comment

begin_define
define|#
directive|define
name|MERGE
value|"/usr/bin/merge"
end_define

begin_comment
comment|/* name of 'merge' program */
end_comment

begin_define
define|#
directive|define
name|TMPDIR
value|"/tmp"
end_define

begin_comment
comment|/* default directory for temporary files */
end_comment

begin_define
define|#
directive|define
name|SLASH
value|'/'
end_define

begin_comment
comment|/* principal pathname separator */
end_comment

begin_define
define|#
directive|define
name|SLASHes
value|'/'
end_define

begin_comment
comment|/* `case SLASHes:' labels all pathname separators */
end_comment

begin_define
define|#
directive|define
name|isSLASH
parameter_list|(
name|c
parameter_list|)
value|((c) == SLASH)
end_define

begin_comment
comment|/* Is arg a pathname separator?  */
end_comment

begin_define
define|#
directive|define
name|ROOTPATH
parameter_list|(
name|p
parameter_list|)
value|isSLASH((p)[0])
end_define

begin_comment
comment|/* Is p an absolute pathname?  */
end_comment

begin_define
define|#
directive|define
name|X_DEFAULT
value|",v/"
end_define

begin_comment
comment|/* default value for -x option */
end_comment

begin_define
define|#
directive|define
name|DIFF_ABSOLUTE
value|1
end_define

begin_comment
comment|/* Is ROOTPATH(DIFF) true?  */
end_comment

begin_define
define|#
directive|define
name|ALL_ABSOLUTE
value|1
end_define

begin_comment
comment|/* Are all subprograms absolute pathnames?  */
end_comment

begin_define
define|#
directive|define
name|SENDMAIL
value|"/usr/bin/mail"
end_define

begin_comment
comment|/* how to send mail */
end_comment

begin_define
define|#
directive|define
name|TZ_must_be_set
value|0
end_define

begin_comment
comment|/* Must TZ be set for gmtime() to work?  */
end_comment

begin_comment
comment|/* Adjust the following declarations as needed.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|&&
operator|!
name|__STRICT_ANSI__
end_if

begin_define
define|#
directive|define
name|exiting
value|volatile
end_define

begin_comment
comment|/* GCC extension: function cannot return */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|exiting
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|has_ftruncate
end_if

begin_decl_stmt
name|int
name|ftruncate
name|P
argument_list|(
operator|(
name|int
operator|,
name|off_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*<sys/mman.h> */
end_comment

begin_if
if|#
directive|if
name|has_madvise
end_if

begin_decl_stmt
name|int
name|madvise
name|P
argument_list|(
operator|(
name|caddr_t
operator|,
name|size_t
operator|,
name|int
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
name|has_mmap
end_if

begin_decl_stmt
name|caddr_t
name|mmap
name|P
argument_list|(
operator|(
name|caddr_t
operator|,
name|size_t
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|off_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|munmap
name|P
argument_list|(
operator|(
name|caddr_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Posix (ISO/IEC 9945-1: 1990 / IEEE Std 1003.1-1990) */
end_comment

begin_comment
comment|/* These definitions are for the benefit of non-Posix hosts, and */
end_comment

begin_comment
comment|/* Posix hosts that have Standard C compilers but traditional include files.  */
end_comment

begin_comment
comment|/* Unfortunately, mixed-up hosts are all too common.  */
end_comment

begin_comment
comment|/*<fcntl.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|F_DUPFD
end_ifdef

begin_decl_stmt
name|int
name|fcntl
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|dup2
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_BINARY
end_ifndef

begin_comment
comment|/* some non-Posix hosts need O_BINARY */
end_comment

begin_define
define|#
directive|define
name|O_BINARY
value|0
end_define

begin_comment
comment|/* no effect on Posix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|O_CREAT
end_ifdef

begin_define
define|#
directive|define
name|open_can_creat
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|open_can_creat
value|0
end_define

begin_define
define|#
directive|define
name|O_RDONLY
value|0
end_define

begin_define
define|#
directive|define
name|O_WRONLY
value|1
end_define

begin_define
define|#
directive|define
name|O_RDWR
value|2
end_define

begin_define
define|#
directive|define
name|O_CREAT
value|01000
end_define

begin_define
define|#
directive|define
name|O_TRUNC
value|02000
end_define

begin_decl_stmt
name|int
name|creat
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|mode_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*<pwd.h> */
end_comment

begin_if
if|#
directive|if
name|has_getpwuid
end_if

begin_decl_stmt
name|struct
name|passwd
modifier|*
name|getpwuid
name|P
argument_list|(
operator|(
name|uid_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*<signal.h> */
end_comment

begin_if
if|#
directive|if
name|has_sigaction
end_if

begin_decl_stmt
name|int
name|sigaction
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sigaction
specifier|const
operator|*
operator|,
expr|struct
name|sigaction
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigaddset
name|P
argument_list|(
operator|(
name|sigset_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigemptyset
name|P
argument_list|(
operator|(
name|sigset_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|has_sigblock
end_if

begin_comment
comment|/* BSD */
end_comment

begin_decl_stmt
name|int
name|sigblock
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigmask
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigsetmask
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
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
comment|/*<stdio.h> */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|fdopen
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fileno
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*<sys/stat.h> */
end_comment

begin_decl_stmt
name|int
name|chmod
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|mode_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fstat
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|stat
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mode_t
name|umask
name|P
argument_list|(
operator|(
name|mode_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|has_fchmod
end_if

begin_decl_stmt
name|int
name|fchmod
name|P
argument_list|(
operator|(
name|int
operator|,
name|mode_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|S_IWRITE
end_ifdef

begin_define
define|#
directive|define
name|S_IWUSR
value|S_IWRITE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_IWUSR
value|(S_IRUSR/2)
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
name|S_IRGRP
end_ifndef

begin_if
if|#
directive|if
name|has_getuid
end_if

begin_define
define|#
directive|define
name|S_IRGRP
value|(S_IRUSR / 0010)
end_define

begin_define
define|#
directive|define
name|S_IWGRP
value|(S_IWUSR / 0010)
end_define

begin_define
define|#
directive|define
name|S_IROTH
value|(S_IRUSR / 0100)
end_define

begin_define
define|#
directive|define
name|S_IWOTH
value|(S_IWUSR / 0100)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* single user OS -- not Posix or Unix */
end_comment

begin_define
define|#
directive|define
name|S_IRGRP
value|0
end_define

begin_define
define|#
directive|define
name|S_IWGRP
value|0
end_define

begin_define
define|#
directive|define
name|S_IROTH
value|0
end_define

begin_define
define|#
directive|define
name|S_IWOTH
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
name|S_ISREG
end_ifndef

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|n
parameter_list|)
value|(((n)& S_IFMT) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*<sys/wait.h> */
end_comment

begin_if
if|#
directive|if
name|has_wait
end_if

begin_decl_stmt
name|pid_t
name|wait
name|P
argument_list|(
operator|(
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|(!((stat_val)& 255))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*<unistd.h> */
end_comment

begin_decl_stmt
name|char
modifier|*
name|getlogin
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|close
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isatty
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|link
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|open
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unlink
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_filbuf
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keeps lint quiet in traditional C */
end_comment

begin_decl_stmt
name|int
name|_flsbuf
name|P
argument_list|(
operator|(
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keeps lint quiet in traditional C */
end_comment

begin_decl_stmt
name|long
name|pathconf
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|write
name|P
argument_list|(
operator|(
name|int
operator|,
name|void
specifier|const
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

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
name|has_fork
end_if

begin_if
if|#
directive|if
operator|!
name|has_vfork
end_if

begin_undef
undef|#
directive|undef
name|vfork
end_undef

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

begin_decl_stmt
name|pid_t
name|vfork
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vfork is nonstandard but faster */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|has_getcwd
operator|||
operator|!
name|has_getwd
end_if

begin_decl_stmt
name|char
modifier|*
name|getcwd
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|getwd
name|P
argument_list|(
operator|(
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
name|has_getuid
end_if

begin_decl_stmt
name|uid_t
name|getuid
name|P
argument_list|(
operator|(
name|void
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
name|has_readlink
end_if

begin_comment
comment|/* 	ssize_t readlink P((char const*,char*,size_t));  */
end_comment

begin_comment
comment|/* BSD; not standard yet */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|has_setuid
end_if

begin_if
if|#
directive|if
operator|!
name|has_seteuid
end_if

begin_undef
undef|#
directive|undef
name|seteuid
end_undef

begin_define
define|#
directive|define
name|seteuid
value|setuid
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|seteuid
name|P
argument_list|(
operator|(
name|uid_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uid_t
name|geteuid
name|P
argument_list|(
operator|(
name|void
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
name|has_spawn
end_if

begin_decl_stmt
name|int
name|spawnv
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
operator|*
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|ALL_ABSOLUTE
end_if

begin_define
define|#
directive|define
name|spawn_RCS
value|spawnv
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|spawn_RCS
value|spawnvp
end_define

begin_decl_stmt
name|int
name|spawnvp
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
operator|*
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|execv
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
operator|*
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|ALL_ABSOLUTE
end_if

begin_define
define|#
directive|define
name|exec_RCS
value|execv
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|exec_RCS
value|execvp
end_define

begin_decl_stmt
name|int
name|execvp
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
operator|*
specifier|const
operator|*
operator|)
argument_list|)
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
comment|/* utime.h */
end_comment

begin_decl_stmt
name|int
name|utime
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
expr|struct
name|utimbuf
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Standard C library */
end_comment

begin_comment
comment|/* These definitions are for the benefit of hosts that have */
end_comment

begin_comment
comment|/* traditional C include files, possibly with Standard C compilers.  */
end_comment

begin_comment
comment|/* Unfortunately, mixed-up hosts are all too common.  */
end_comment

begin_comment
comment|/*<errno.h> */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*<limits.h> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ULONG_MAX
end_ifndef

begin_comment
comment|/* This does not work in #ifs, but it's good enough for us.  */
end_comment

begin_define
define|#
directive|define
name|ULONG_MAX
value|((unsigned long)-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*<signal.h> */
end_comment

begin_if
if|#
directive|if
name|has_signal
end_if

begin_macro
name|signal_type
argument_list|(
argument|*signal P((int,signal_type(*)signal_args))
argument_list|)
end_macro

begin_expr_stmt
name|signal_args
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*<stdio.h> */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|fopen
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|fread_type
name|fread
name|P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|freadarg_type
operator|,
name|freadarg_type
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|fread_type
name|fwrite
name|P
argument_list|(
operator|(
name|void
specifier|const
operator|*
operator|,
name|freadarg_type
operator|,
name|freadarg_type
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fclose
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|feof
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ferror
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fflush
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fprintf
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fputs
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fseek
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|printf
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rename
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sprintf
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* long ftell P((FILE*)); */
end_comment

begin_decl_stmt
name|void
name|clearerr
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|perror
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|L_tmpnam
end_ifndef

begin_define
define|#
directive|define
name|L_tmpnam
value|32
end_define

begin_comment
comment|/* power of 2> sizeof("/usr/tmp/xxxxxxxxxxxxxxx") */
end_comment

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

begin_if
if|#
directive|if
name|has_mktemp
end_if

begin_decl_stmt
name|char
modifier|*
name|mktemp
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* traditional */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|tmpnam
name|P
argument_list|(
operator|(
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
name|has_vfprintf
end_if

begin_decl_stmt
name|int
name|vfprintf
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|has__doprintf
end_if

begin_decl_stmt
name|void
name|_doprintf
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Minix */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|void
name|_doprnt
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|va_list
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* BSD */
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
comment|/*<stdlib.h> */
end_comment

begin_decl_stmt
name|char
modifier|*
name|getenv
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exiting
name|void
name|_exit
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exiting
name|void
name|exit
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|malloc_type
name|malloc
name|P
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|malloc_type
name|realloc
name|P
argument_list|(
operator|(
name|malloc_type
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free
name|P
argument_list|(
operator|(
name|malloc_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|has_fork
operator|&&
operator|!
name|has_spawn
end_if

begin_decl_stmt
name|int
name|system
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*<string.h> */
end_comment

begin_decl_stmt
name|char
modifier|*
name|strcpy
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|strchr
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|strrchr
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|memcmp
name|P
argument_list|(
operator|(
name|void
specifier|const
operator|*
operator|,
name|void
specifier|const
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strcmp
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|strlen
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|memcpy
name|P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|void
specifier|const
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|has_memmove
end_if

begin_decl_stmt
name|void
modifier|*
name|memmove
name|P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|void
specifier|const
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*<time.h> */
end_comment

begin_decl_stmt
name|time_t
name|time
name|P
argument_list|(
operator|(
name|time_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

