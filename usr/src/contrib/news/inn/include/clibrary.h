begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.17 $ ** **  Here be declarations of routines and variables in the C library. **  You must #include<sys/types.h> and<stdio.h> before this file. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DO_HAVE_UNISTD
argument_list|)
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

begin_comment
comment|/* defined(DO_HAVE_UNISTD) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DO_HAVE_VFORK
argument_list|)
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

begin_comment
comment|/* defined(DO_HAVE_VFORK) */
end_comment

begin_comment
comment|/* Generic pointer, used by memcpy, malloc, etc. */
end_comment

begin_comment
comment|/* =()<typedef @<POINTER>@ *POINTER;>()= */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|POINTER
typedef|;
end_typedef

begin_comment
comment|/* What is a file offset?  Will not work unless long! */
end_comment

begin_comment
comment|/* =()<typedef @<OFFSET_T>@ OFFSET_T;>()= */
end_comment

begin_typedef
typedef|typedef
name|long
name|OFFSET_T
typedef|;
end_typedef

begin_comment
comment|/* What is the type of an object size? */
end_comment

begin_comment
comment|/* =()<typedef @<SIZE_T>@ SIZE_T;>()= */
end_comment

begin_typedef
typedef|typedef
name|size_t
name|SIZE_T
typedef|;
end_typedef

begin_comment
comment|/* What is the type of a passwd uid and gid, for use in chown(2)? */
end_comment

begin_comment
comment|/* =()<typedef @<UID_T>@ UID_T;>()= */
end_comment

begin_typedef
typedef|typedef
name|uid_t
name|UID_T
typedef|;
end_typedef

begin_comment
comment|/* =()<typedef @<GID_T>@ GID_T;>()= */
end_comment

begin_typedef
typedef|typedef
name|gid_t
name|GID_T
typedef|;
end_typedef

begin_comment
comment|/* =()<typedef @<PID_T>@ PID_T;>()= */
end_comment

begin_typedef
typedef|typedef
name|pid_t
name|PID_T
typedef|;
end_typedef

begin_comment
comment|/* What should a signal handler return? */
end_comment

begin_comment
comment|/* =()<#define SIGHANDLER	@<SIGHANDLER>@>()= */
end_comment

begin_define
define|#
directive|define
name|SIGHANDLER
value|void
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SIG_DFL
argument_list|)
end_if

begin_comment
comment|/* What types of variables can be modified in a signal handler? */
end_comment

begin_comment
comment|/* =()<typedef @<SIGVAR>@ SIGVAR;>()= */
end_comment

begin_typedef
typedef|typedef
name|sig_atomic_t
name|SIGVAR
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(SIG_DFL) */
end_comment

begin_comment
comment|/* =()<#include @<STR_HEADER>@>()= */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* =()<#include @<MEM_HEADER>@>()= */
end_comment

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_comment
comment|/* **  It's a pity we have to go through these contortions, for broken **  systems that have fd_set but not the FD_SET. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FD_SETSIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|FDSET
value|fd_set
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NOFILE
argument_list|)
end_if

begin_expr_stmt
name|error
operator|--
operator|#
name|define
name|NOFILE
name|to
name|the
name|number
name|of
name|files
name|allowed
name|on
name|your
name|machine
operator|!
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NOFILE) */
end_comment

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
value|(((x) + ((y) - 1)) / (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(howmany) */
end_comment

begin_define
define|#
directive|define
name|FD_SETSIZE
value|NOFILE
end_define

begin_define
define|#
directive|define
name|NFDBITS
value|(sizeof (long) * 8)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_FDSET
block|{
name|long
name|fds_bits
index|[
name|howmany
argument_list|(
name|FD_SETSIZE
argument_list|,
name|NFDBITS
argument_list|)
index|]
decl_stmt|;
block|}
name|FDSET
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|(p)->fds_bits[(n) / NFDBITS] |= (1<< ((n) % NFDBITS))
end_define

begin_define
define|#
directive|define
name|FD_CLR
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|(p)->fds_bits[(n) / NFDBITS]&= ~(1<< ((n) % NFDBITS))
end_define

begin_define
define|#
directive|define
name|FD_ISSET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n) / NFDBITS]& (1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|p
parameter_list|)
value|(void)memset((POINTER)(p), 0, sizeof *(p))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(FD_SETSIZE) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SEEK_SET
argument_list|)
end_if

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

begin_comment
comment|/* !defined(SEEK_SET) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SEEK_END
argument_list|)
end_if

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
comment|/* !defined(SEEK_END) */
end_comment

begin_comment
comment|/* **  We must use #define to set FREEVAL, since "typedef void FREEVAL;" doesn't **  work on some broken compilers, sigh. */
end_comment

begin_comment
comment|/* =()<#define FREEVAL @<FREEVAL>@>()= */
end_comment

begin_define
define|#
directive|define
name|FREEVAL
value|int
end_define

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
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

begin_comment
comment|/* !defined(__STDC__) */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|inet_ntoa
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|mktemp
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|strerror
argument_list|)
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|strerror
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(strerror) */
end_comment

begin_function_decl
specifier|extern
name|long
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|inet_addr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FREEVAL
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|POINTER
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|POINTER
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ACT_MMAP
argument_list|)
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|mmap
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(ACT_MMAP) */
end_comment

begin_comment
comment|/* Some backward systems need this. */
end_comment

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|popen
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* This is in<mystring.h>, but not in some system string headers,  * so we put it here just in case. */
end_comment

begin_function_decl
specifier|extern
name|int
name|strncasecmp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* =()<extern @<ABORTVAL>@	abort();>()= */
end_comment

begin_function_decl
specifier|extern
name|int
name|abort
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* =()<extern @<ALARMVAL>@	alarm();>()= */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|int
name|alarm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* =()<extern @<EXITVAL>@	exit();>()= */
end_comment

begin_function_decl
specifier|extern
name|void
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* =()<extern @<GETPIDVAL>@	getpid();>()= */
end_comment

begin_function_decl
specifier|extern
name|pid_t
name|getpid
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* =()<extern @<LSEEKVAL>@	lseek();>()= */
end_comment

begin_function_decl
specifier|extern
name|off_t
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* =()<extern @<QSORTVAL>@	qsort();>()= */
end_comment

begin_function_decl
specifier|extern
name|int
name|qsort
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* =()<extern @<SLEEPVAL>@	sleep();>()= */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|int
name|sleep
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* =()<extern @<_EXITVAL>@	_exit();>()= */
end_comment

begin_function_decl
specifier|extern
name|void
name|_exit
parameter_list|()
function_decl|;
end_function_decl

end_unit

