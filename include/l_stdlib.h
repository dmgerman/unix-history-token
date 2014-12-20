begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Proto types for machines that are not ANSI and POSIX	 compliant.  * This is optional  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|L_STDLIB_H
end_ifndef

begin_define
define|#
directive|define
name|L_STDLIB_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Needed for speed_t. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TERMIOS_H
end_ifdef

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ERRNO_H
end_ifdef

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_include
include|#
directive|include
file|"ntp_proto.h"
end_include

begin_comment
comment|/* Let's try to keep this more or less alphabetized... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_ADJTIME_0
end_ifdef

begin_struct_decl
struct_decl|struct
name|timeval
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|adjtime
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_BCOPY_0
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|bcopy
end_ifndef

begin_function_decl
specifier|extern
name|void
name|bcopy
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_BZERO_0
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|bzero
end_ifndef

begin_function_decl
specifier|extern
name|void
name|bzero
parameter_list|(
name|char
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_CFSETISPEED_0
end_ifdef

begin_struct_decl
struct_decl|struct
name|termios
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|cfsetispeed
parameter_list|(
name|struct
name|termios
modifier|*
parameter_list|,
name|speed_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cfsetospeed
parameter_list|(
name|struct
name|termios
modifier|*
parameter_list|,
name|speed_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|getpass
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_HSTRERROR_0
end_ifdef

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|hstrerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_INET_NTOA_0
end_ifdef

begin_struct_decl
struct_decl|struct
name|in_addr
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|inet_ntoa
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_IOCTL_0
end_ifdef

begin_function_decl
specifier|extern
name|int
name|ioctl
parameter_list|(
name|int
parameter_list|,
name|u_long
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_IPC_0
end_ifdef

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|bind
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|connect
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|recv
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|recvfrom
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|send
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sendto
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setsockopt
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|socket
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_MEMMOVE_0
end_ifdef

begin_function_decl
specifier|extern
name|void
modifier|*
name|memmove
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_MEMSET_0
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|memset
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_MKSTEMP_0
end_ifdef

begin_function_decl
specifier|extern
name|int
name|mkstemp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_MKTEMP_0
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|mktemp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_NLIST_0
end_ifdef

begin_struct_decl
struct_decl|struct
name|nlist
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|nlist
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|nlist
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_PLOCK_0
end_ifdef

begin_function_decl
specifier|extern
name|int
name|plock
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_RENAME_0
end_ifdef

begin_function_decl
specifier|extern
name|int
name|rename
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_SELECT_0
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NTP_SELECT_H
end_ifdef

begin_function_decl
specifier|extern
name|int
name|select
parameter_list|(
name|int
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
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

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_SETITIMER_0
end_ifdef

begin_struct_decl
struct_decl|struct
name|itimerval
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|setitimer
parameter_list|(
name|int
parameter_list|,
name|struct
name|itimerval
modifier|*
parameter_list|,
name|struct
name|itimerval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PRIO_PROCESS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_SETPRIORITY_0
end_ifdef

begin_function_decl
specifier|extern
name|int
name|setpriority
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_SETPRIORITY_1
end_ifdef

begin_function_decl
specifier|extern
name|int
name|setpriority
parameter_list|(
name|int
parameter_list|,
name|id_t
parameter_list|,
name|int
parameter_list|)
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

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_SIGVEC_0
end_ifdef

begin_struct_decl
struct_decl|struct
name|sigvec
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|sigvec
parameter_list|(
name|int
parameter_list|,
name|struct
name|sigvec
modifier|*
parameter_list|,
name|struct
name|sigvec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_STDIO_0
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FILE
argument_list|)
operator|||
name|defined
argument_list|(
name|BUFSIZ
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|_flsbuf
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_filbuf
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fflush
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fscanf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fputs
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fputc
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fread
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|perror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setbuf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SETLINEBUF
end_ifdef

begin_function_decl
specifier|extern
name|int
name|setlinebuf
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|setvbuf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scanf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sscanf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vfprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vsprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
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

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_STIME_0
end_ifdef

begin_function_decl
specifier|extern
name|int
name|stime
parameter_list|(
specifier|const
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_STIME_1
end_ifdef

begin_function_decl
specifier|extern
name|int
name|stime
parameter_list|(
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_STRERROR_0
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strerror
parameter_list|(
name|int
name|errnum
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_STRTOL_0
end_ifdef

begin_function_decl
specifier|extern
name|long
name|strtol
parameter_list|(
specifier|const
name|char
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

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_SYSCALL
end_ifdef

begin_function_decl
specifier|extern
name|int
name|syscall
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_SYSLOG_0
end_ifdef

begin_function_decl
specifier|extern
name|void
name|closelog
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_DAEMON
end_ifndef

begin_function_decl
specifier|extern
name|void
name|openlog
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|openlog
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|setlogmask
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|syslog
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_TIME_0
end_ifdef

begin_function_decl
specifier|extern
name|time_t
name|time
parameter_list|(
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_TIMEOFDAY_0
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV_TIMEOFDAY
end_ifdef

begin_function_decl
specifier|extern
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|settimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not SYSV_TIMEOFDAY */
end_comment

begin_struct_decl
struct_decl|struct
name|timezone
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|,
name|struct
name|timezone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|settimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not SYSV_TIMEOFDAY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_TOLOWER_0
end_ifdef

begin_function_decl
specifier|extern
name|int
name|tolower
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_TOUPPER_0
end_ifdef

begin_function_decl
specifier|extern
name|int
name|toupper
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Necessary variable declarations.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_ERRNO
end_ifdef

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
name|DECL_H_ERRNO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|h_errno
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|h_errno
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
comment|/* L_STDLIB_H */
end_comment

end_unit

