begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Proto types for machines that are not ANSI and POSIX	 compliant.  * This is optional  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_l_stdlib_h
end_ifndef

begin_define
define|#
directive|define
name|_l_stdlib_h
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
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

begin_decl_stmt
specifier|extern
name|int
name|adjtime
name|P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
operator|,
expr|struct
name|timeval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|void
name|bcopy
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
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

begin_decl_stmt
specifier|extern
name|void
name|bzero
name|P
argument_list|(
operator|(
name|char
operator|*
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

begin_decl_stmt
specifier|extern
name|int
name|cfsetispeed
name|P
argument_list|(
operator|(
expr|struct
name|termios
operator|*
operator|,
name|speed_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cfsetospeed
name|P
argument_list|(
operator|(
expr|struct
name|termios
operator|*
operator|,
name|speed_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getpass
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|inet_ntoa
name|P
argument_list|(
operator|(
expr|struct
name|in_addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_IOCTL_0
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|ioctl
name|P
argument_list|(
operator|(
name|int
operator|,
name|u_long
operator|,
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

begin_decl_stmt
specifier|extern
name|int
name|bind
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|connect
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|recv
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|recvfrom
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|send
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sendto
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|setsockopt
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|socket
name|P
argument_list|(
operator|(
name|int
operator|,
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

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_MEMMOVE_0
end_ifdef

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|memmove
name|P
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|void
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

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_MEMSET_0
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|memset
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
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

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_MKSTEMP_0
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|mkstemp
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

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_MKTEMP_0
end_ifdef

begin_decl_stmt
specifier|extern
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_MRAND48_0
end_ifdef

begin_decl_stmt
specifier|extern
name|long
name|mrand48
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

begin_decl_stmt
specifier|extern
name|int
name|nlist
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
expr|struct
name|nlist
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_PLOCK_0
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|plock
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

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_RENAME_0
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|rename
name|P
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

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_SELECT_0
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_ntp_select_h
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|select
name|P
argument_list|(
operator|(
name|int
operator|,
name|fd_set
operator|*
operator|,
name|fd_set
operator|*
operator|,
name|fd_set
operator|*
operator|,
expr|struct
name|timeval
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

begin_decl_stmt
specifier|extern
name|int
name|setitimer
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|itimerval
operator|*
operator|,
expr|struct
name|itimerval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|int
name|setpriority
name|P
argument_list|(
operator|(
name|int
operator|,
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

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_SETPRIORITY_1
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|setpriority
name|P
argument_list|(
operator|(
name|int
operator|,
name|id_t
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

begin_decl_stmt
specifier|extern
name|int
name|sigvec
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sigvec
operator|*
operator|,
expr|struct
name|sigvec
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_SRAND48_0
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|srand48
name|P
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
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

begin_decl_stmt
specifier|extern
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

begin_decl_stmt
specifier|extern
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
specifier|extern
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
specifier|extern
name|int
name|fprintf
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fscanf
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fputs
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fputc
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

begin_decl_stmt
specifier|extern
name|int
name|fread
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|perror
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|printf
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|setbuf
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SETLINEBUF
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|setlinebuf
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|setvbuf
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scanf
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sscanf
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vfprintf
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vsprintf
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
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

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_STIME_0
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|stime
name|P
argument_list|(
operator|(
specifier|const
name|time_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_STIME_1
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|stime
name|P
argument_list|(
operator|(
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_STRERROR_0
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strerror
name|P
argument_list|(
operator|(
name|int
name|errnum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_STRTOL_0
end_ifdef

begin_decl_stmt
specifier|extern
name|long
name|strtol
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|*
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

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_SYSCALL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|syscall
name|P
argument_list|(
operator|(
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_SYSLOG_0
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|closelog
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_DAEMON
end_ifndef

begin_decl_stmt
specifier|extern
name|void
name|openlog
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|void
name|openlog
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
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

begin_decl_stmt
specifier|extern
name|int
name|setlogmask
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|syslog
name|P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_TIME_0
end_ifdef

begin_decl_stmt
specifier|extern
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

begin_decl_stmt
specifier|extern
name|int
name|gettimeofday
name|P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|settimeofday
name|P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|int
name|gettimeofday
name|P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
operator|,
expr|struct
name|timezone
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|settimeofday
name|P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
operator|,
name|void
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

begin_decl_stmt
specifier|extern
name|int
name|tolower
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

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_TOUPPER_0
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|toupper
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

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_H_ERRNO
end_ifdef

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

begin_comment
comment|/*******************************************************/
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * Unprotoyped	library functions for SunOS 4.x.x  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_SUNOS4
end_ifdef

begin_if
unit|extern	void	closelog	P((void)); extern	void	openlog		P((char *, int, int)); extern	void	syslog		P((int, char *, ...)); extern	int	setlogmask	P((int));  extern	char *	getpass		P((char *));  extern	int	setpriority	P((int ,int ,int));  extern	long	strtol		P((char *, char **, int));
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NTP_POSIX_SOURCE
argument_list|)
end_if

begin_endif
unit|extern	int	atoi		P((char *)); extern	int	dup2		P((int, int)); extern	int	execve		P((char *, char **,char **)); extern	int	fork		P((void)); extern	int	getdtablesize	P((void)); extern	int	qsort		(void *, int , int, 				   int P((*compar)(void *, void *))); extern	long	random		P((void)); extern	long	mrand48		P((void)); extern	int	setpgrp		P((int, int)); extern	void	srandom		P((unsigned int)); extern	void	bcopy		P((const char *, char *, int));
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bzero
end_ifndef

begin_comment
comment|/* XXX macro prototyping clash */
end_comment

begin_endif
unit|extern	void	bzero		P((char *, int)); extern	int	bcmp		P((char *, char *, int)); extern	void	bcopy		P((const char *, char *, int));
endif|#
directive|endif
end_endif

begin_if
unit|extern	char   *mktemp		P((char *));	  extern	int	tolower		P((int));  extern	int	isatty		P((int));  extern	unsigned sleep		P((unsigned )); extern	unsigned int alarm	P((unsigned int)); extern	int	pause		P((void));  extern	int	getpid		P((void)); extern	int	getppid		P((void));  extern	int	close		P((int)); extern	int	ioctl		P((int, int, char *)); extern	int	rename		P((char *, char *));
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern	int	read		P((int, void *, size_t)); extern	int	write		P((int, const void *, size_t));
endif|#
directive|endif
end_endif

begin_ifdef
unit|extern	int	unlink		P((const char *)); extern	int	link		P((const char *, const char *));
ifdef|#
directive|ifdef
name|FILE
end_ifdef

begin_ifdef
unit|extern	int	fclose		P((FILE *)); extern	int	fflush		P((FILE *)); extern	int	fprintf		P((FILE *, char *, ...)); extern	int	fscanf		P((FILE *, char *, ...)); extern	int	fputs		P((char *, FILE *)); extern	int	fputc		P((char, FILE *)); extern	int	fread		P((char *, int, int, FILE *)); extern	int	printf		P((char *, ...)); extern	int	setbuf		P((FILE *, char *)); extern	int	setvbuf		P((FILE *, char *, int, int)); extern	int	scanf		P((char *, ...)); extern	int	sscanf		P((char *, char *, ...)); extern	int	vsprintf	P((char *, char *, ...)); extern	int	_flsbuf		P((int, FILE *)); extern	int	_filbuf		P((FILE *)); extern	void	perror		P((char *));
ifdef|#
directive|ifdef
name|HAVE_SETLINEBUF
end_ifdef

begin_endif
unit|extern	int	setlinebuf	P((FILE *));
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
name|_ntp_string_h
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NTP_POSIX_SOURCE
end_ifdef

begin_comment
comment|/* these are builtins */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_NEED_BOPS
end_ifndef

begin_comment
comment|/* but may be emulated by bops */
end_comment

begin_endif
unit|extern	char	*memcpy P(()); extern	char	*memset P(()); extern	int	memcmp P(());
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
name|_sys_socket_h
end_ifdef

begin_endif
unit|extern	int	bind		P((int, struct sockaddr *, int)); extern	int	connect		P((int,	 struct sockaddr *, int)); extern	int	sendto		P((int, char *, int, int, struct sockaddr *, int)); extern	int	setsockopt	P((int, int, int, char *, int)); extern	int	socket		P((int, int, int)); extern	int	recvfrom	P((int, char *, int, int, struct sockaddr *, int *));
endif|#
directive|endif
end_endif

begin_comment
comment|/* _sys_socket_h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_ntp_select_h
end_ifdef

begin_endif
unit|extern	int	select		P((int, fd_set *, fd_set *, fd_set *, struct timeval *));
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_sys_time_h
end_ifdef

begin_ifdef
unit|extern	int	adjtime		P((struct timeval *, struct timeval *)); extern	int	setitimer	P((int , struct itimerval *, struct itimerval *));
ifdef|#
directive|ifdef
name|SYSV_TIMEOFDAY
end_ifdef

begin_else
unit|extern	int	gettimeofday	P((struct timeval *)); extern	int	settimeofday	P((struct timeval *));
else|#
directive|else
end_else

begin_comment
comment|/* ! SYSV_TIMEOFDAY */
end_comment

begin_endif
unit|extern	int	gettimeofday	P((struct timeval *, struct timezone *)); extern	int	settimeofday	P((struct timeval *, struct timezone *));
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSV_TIMEOFDAY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _sys_time_h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__time_h
end_ifdef

begin_endif
unit|extern	time_t	time		P((time_t *));
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__setjmp_h
end_ifdef

begin_endif
unit|extern	int	setjmp		P((jmp_buf)); extern	void	longjmp		P((jmp_buf, int));
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_sys_resource_h
end_ifdef

begin_endif
unit|extern	int	getrusage	P((int, struct rusage *));
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_nlist_h
end_ifdef

begin_endif
unit|extern int	nlist		P((char *, struct nlist *));
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_SUNOS4 */
end_comment

begin_comment
comment|/*  * Unprototyped library functions for DEC OSF/1  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_DECOSF1
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ENDIAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ENDIAN_H_
end_define

begin_endif
unit|extern u_short	htons		P((u_short)); extern u_short	ntohs		P((u_short)); extern u_int32	htonl		P((u_int32)); extern u_int32	ntohl		P((u_int32));
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_ENDIAN_H_ */
end_comment

begin_comment
comment|/* extern	char *	getpass		P((char *)); */
end_comment

begin_ifndef
unit|extern	char *	mktemp		P((char *));
ifndef|#
directive|ifndef
name|SYS_IX86OSF1
end_ifndef

begin_endif
unit|extern	int	ioctl		P((int, u_long, char *)); extern	void	bzero		P((char *, int));
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SOCK_DGRAM
end_ifdef

begin_endif
unit|extern	int	bind		P((int, const struct sockaddr *, int)); extern	int	connect		P((int, const struct sockaddr *, int)); extern	int	socket		P((int, int, int)); extern	int	sendto		P((int, const void *, int, int, const struct sockaddr *, int)); extern	int	setsockopt	P((int, int, int, const void *, int)); extern	int	recvfrom	P((int, void *, int, int, struct sockaddr *, int *));
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOCK_STREAM */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_ntp_select_h
end_ifdef

begin_endif
unit|extern	int	select		P((int, fd_set *, fd_set *, fd_set *, struct timeval *));
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DECOSF1 */
end_comment

begin_comment
comment|/*  * Unprototyped library functions for Ultrix  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_ULTRIX
end_ifdef

begin_ifndef
unit|extern	int	close		P((int)); extern	char *	getpass		P((char *)); extern	int	getpid		P((void)); extern	int	ioctl		P((int, int, char *)); extern	char   *mktemp		P((char *));	 extern	int	unlink		P((const char *)); extern	int	link		P((const char *, const char *));  extern	void	closelog	P((void)); extern	void	syslog		P((int, char *, ...));
ifndef|#
directive|ifndef
name|LOG_DAEMON
end_ifndef

begin_else
unit|extern	void	openlog		P((char *, int));
else|#
directive|else
end_else

begin_endif
unit|extern	void	openlog		P((char *, int, int));
endif|#
directive|endif
end_endif

begin_ifdef
unit|extern	int	setpriority	P((int ,int ,int ));
ifdef|#
directive|ifdef
name|SOCK_DGRAM
end_ifdef

begin_endif
unit|extern	int	bind		P((int, struct sockaddr *, int)); extern	int	connect		P((int,	 struct sockaddr *, int)); extern	int	socket		P((int, int, int)); extern	int	sendto		P((int, char *, int, int, struct sockaddr *, int)); extern	int	setsockopt	P((int, int, int, char *, int)); extern	int	recvfrom	P((int, char *, int, int, struct sockaddr *, int *));
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOCK_STREAM */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_TIME_H_
end_ifdef

begin_endif
unit|extern	int	gettimeofday	P((struct timeval *, struct timezone *)); extern	int	settimeofday	P((struct timeval *, struct timezone *)); extern	int	adjtime		P((struct timeval *, struct timeval *)); extern	int	select		P((int, fd_set *, fd_set *, fd_set *, struct timeval *)); extern	int	setitimer	P((int , struct itimerval *, struct itimerval *));
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TIME_H_ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|N_UNDF
end_ifdef

begin_endif
unit|extern int	nlist		P((char *, struct nlist *));
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bzero
end_ifndef

begin_comment
comment|/* XXX macro prototyping clash */
end_comment

begin_endif
unit|extern	void	bzero		P((char *, int)); extern	int	bcmp		P((char *, char *, int)); extern	void	bcopy		P((const char *, char *, int));
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_POSIX_SOURCE
end_ifndef

begin_ifdef
unit|extern	int	atoi		P((char *)); extern	void	bzero		P((char *, int)); extern	int	bcmp		P((char *, char *, int)); extern	void	bcopy		P((const char *, char *, int)); extern	int	execve		P((char *, char **,char **)); extern	int	fork		P((void)); extern	int	getdtablesize	P((void)); extern	int	ran		P((void)); extern	int	rand		P((void)); extern	void	srand		P((unsigned int));
ifdef|#
directive|ifdef
name|_TIME_H_
end_ifdef

begin_endif
unit|extern	int	gettimeofday	P((struct timeval *, struct timezone *)); extern	int	settimeofday	P((struct timeval *, struct timezone *));
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
name|_RESOURCE_H_
end_ifdef

begin_endif
unit|extern	int	getrusage	P((int, struct rusage *));
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_ULTRIX */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__convex__
argument_list|)
end_if

begin_endif
unit|extern	char *	getpass		P((char *));
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_IRIX4
end_ifdef

begin_endif
unit|extern	char *	getpass		P((char *));
endif|#
directive|endif
end_endif

begin_comment
comment|/* IRIX4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_VAX
end_ifdef

begin_endif
unit|extern	char *	getpass		P((char *));
endif|#
directive|endif
end_endif

begin_comment
comment|/* VAX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_DOMAINOS
end_ifdef

begin_endif
unit|extern	char *	getpass		P((char *));
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_DOMAINOS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_BSD
end_ifdef

begin_define
define|#
directive|define
name|IN_CLASSD
parameter_list|(
name|i
parameter_list|)
value|(((long)(i)& 0xf0000000) == 0xe0000000)
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
comment|/* 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* l_stdlib_h */
end_comment

end_unit

