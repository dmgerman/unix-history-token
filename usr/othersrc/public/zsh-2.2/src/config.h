begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* this file is created automatically by buildzsh */
end_comment

begin_comment
comment|/* define this if you are sysvish */
end_comment

begin_comment
comment|/* #define SYSV */
end_comment

begin_define
define|#
directive|define
name|TERMIOS
end_define

begin_comment
comment|/* #define TTY_NEEDS_DRAINING */
end_comment

begin_comment
comment|/* #define CLOBBERS_TYPEAHEAD */
end_comment

begin_define
define|#
directive|define
name|HAS_STDLIB
end_define

begin_define
define|#
directive|define
name|HAS_STRING
end_define

begin_define
define|#
directive|define
name|HAS_LOCALE
end_define

begin_comment
comment|/* define this if you have a host field in utmp */
end_comment

begin_define
define|#
directive|define
name|UTMP_HOST
end_define

begin_comment
comment|/* define this if you have WAITPID */
end_comment

begin_comment
comment|/* #define WAITPID */
end_comment

begin_comment
comment|/* define this if you have SELECT */
end_comment

begin_define
define|#
directive|define
name|HAS_SELECT
end_define

begin_comment
comment|/* define this if you have<sys/select.h> */
end_comment

begin_comment
comment|/* #define HAS_SYS_SELECT */
end_comment

begin_comment
comment|/* we can't just test for S_IFIFO or check to see if the mknod worked,    because the NeXTs sold by a vendor which will remain nameless will    happily create the FIFO for you, and then panic when you try to do 	something weird with them, because they aren't supported by the OS. */
end_comment

begin_comment
comment|/* #define NO_FIFOS */
end_comment

begin_comment
comment|/* define this if you have strftime() */
end_comment

begin_define
define|#
directive|define
name|HAS_STRFTIME
end_define

begin_comment
comment|/* #define HAS_TCSETPGRP */
end_comment

begin_define
define|#
directive|define
name|HAS_TCCRAP
end_define

begin_define
define|#
directive|define
name|HAS_SETPGID
end_define

begin_comment
comment|/* #define HAS_SIGRELSE */
end_comment

begin_comment
comment|/* define this if you have RFS */
end_comment

begin_comment
comment|/* #define HAS_RFS */
end_comment

begin_comment
comment|/* define this if you have a working getrusage and wait3 */
end_comment

begin_define
define|#
directive|define
name|HAS_RUSAGE
end_define

begin_comment
comment|/* define this if your signal handlers return void */
end_comment

begin_define
define|#
directive|define
name|SIGVOID
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|sgi
end_ifdef

begin_undef
undef|#
directive|undef
name|SIGVOID
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* define this if signal handlers need to be reset each time */
end_comment

begin_comment
comment|/* #define RESETHANDNEEDED */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIGVOID
end_ifdef

begin_define
define|#
directive|define
name|HANDTYPE
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HANDTYPE
value|int
end_define

begin_define
define|#
directive|define
name|INTHANDTYPE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* a string corresponding to the host type */
end_comment

begin_define
define|#
directive|define
name|HOSTTYPE
value|"386BSD"
end_define

begin_comment
comment|/* the default editor for the fc builtin */
end_comment

begin_define
define|#
directive|define
name|DEFFCEDIT
value|"vi"
end_define

begin_comment
comment|/* the path of wtmp */
end_comment

begin_define
define|#
directive|define
name|WTMP_FILE
value|"/dev/null"
end_define

begin_comment
comment|/* the path of utmp */
end_comment

begin_define
define|#
directive|define
name|UTMP_FILE
value|"/etc/utmp"
end_define

begin_comment
comment|/* default prefix for temporary files */
end_comment

begin_define
define|#
directive|define
name|DEFTMPPREFIX
value|"/tmp/zsh"
end_define

begin_comment
comment|/* define if you prefer "suspended" to "stopped" */
end_comment

begin_define
define|#
directive|define
name|USE_SUSPENDED
end_define

begin_comment
comment|/* the file to source whenever zsh is run; if undefined, don't source 	anything */
end_comment

begin_define
define|#
directive|define
name|GLOBALZSHRC
value|"/etc/zshrc"
end_define

begin_comment
comment|/* the file to source whenever zsh is run as a login shell; if 	undefined, don't source anything */
end_comment

begin_define
define|#
directive|define
name|GLOBALZLOGIN
value|"/etc/zlogin"
end_define

begin_comment
comment|/* the file to source whenever zsh is run as a login shell, before 	zshrc is read; if undefined, don't source anything */
end_comment

begin_define
define|#
directive|define
name|GLOBALZPROFILE
value|"/etc/zprofile"
end_define

begin_comment
comment|/* the default HISTSIZE */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_HISTSIZE
value|30
end_define

begin_define
define|#
directive|define
name|_BSD_SIGNALS
end_define

begin_comment
comment|/* this could be an iris, you never know */
end_comment

begin_define
define|#
directive|define
name|_BSD
end_define

begin_comment
comment|/* this could be HP-UX, you never know */
end_comment

begin_define
define|#
directive|define
name|_BSD_INCLUDES
end_define

begin_comment
comment|/* this could be AIX, you never know */
end_comment

begin_comment
comment|/* if your compiler doesn't like void *, change this to char * 	and ignore all the warnings. */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|vptr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|JOB_CONTROL
end_define

end_unit

