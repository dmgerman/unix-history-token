begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* conf.h */
end_comment

begin_comment
comment|/* Configuration header file for Taylor UUCP.    Generated on Mon Jun  1 16:01:13 PDT 1992.  */
end_comment

begin_comment
comment|/* Set MAIL_PROGRAM to a program which takes a mail address as an argument    and accepts a mail message to send to that address on stdin.  */
end_comment

begin_define
define|#
directive|define
name|MAIL_PROGRAM
value|"/bin/mail"
end_define

begin_comment
comment|/* Set ECHO_PROGRAM to a program which echoes its arguments; if echo    is a shell builtin you can just use "echo".  */
end_comment

begin_define
define|#
directive|define
name|ECHO_PROGRAM
value|"/bin/echo"
end_define

begin_comment
comment|/* The following macros indicate what header files you have.  Set the    macro to 1 if you have the corresponding header file, or 0 if you    do not.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/*<string.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/*<strings.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/*<unistd.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/*<stdlib.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/*<limits.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_H
value|1
end_define

begin_comment
comment|/*<time.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/*<sys/wait.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_comment
comment|/*<sys/ioctl.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_comment
comment|/*<dirent.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/*<memory.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/*<sys/param.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIME_H
value|1
end_define

begin_comment
comment|/*<utime.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/*<fcntl.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
value|1
end_define

begin_comment
comment|/*<sys/file.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBC_H
value|0
end_define

begin_comment
comment|/*<libc.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSEXITS_H
value|1
end_define

begin_comment
comment|/*<sysexits.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL_H
value|0
end_define

begin_comment
comment|/*<poll.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_STROPTS_H
value|0
end_define

begin_comment
comment|/*<stropts.h> */
end_comment

begin_comment
comment|/* Set SIGtype to the return type of a signal handler.  On newer systems    this will be void; some older systems use int.  */
end_comment

begin_define
define|#
directive|define
name|SIGtype
value|int
end_define

begin_comment
comment|/* Set HAVE_TIME_T to 1 if time_t is defined in<time.h>, as required by    the ANSI C standard.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_T
value|1
end_define

begin_comment
comment|/* Set HAVE_SYS_TIME_T to 1 if time_t is defined in<sys/types.h>;  this    is only checked if HAVE_TIME_T is 0.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_T
value|1
end_define

begin_comment
comment|/* Set HAVE_SYS_TIME_AND_TIME_H to 1 if<time.h> and<sys/time.h> can both    be included in a single source file; if you don't have either or both of    them, it doesn't matter what you set this to.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_AND_TIME_H
value|1
end_define

begin_comment
comment|/* Set HAVE_TERMIOS_AND_SYS_IOCTL_H to 1 if<termios.h> and<sys/ioctl.h>    can both be included in a single source file; if you don't have either    or both of them, it doesn't matter what you set this to.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS_AND_SYS_IOCTL_H
value|1
end_define

begin_comment
comment|/* If you are configuring by hand, you should set one of the terminal    driver options in policy.h.  If you are autoconfiguring, the script    will check whether your system defines CBREAK, which is a terminal    setting; if your system supports CBREAK, and you don't set a terminal    driver in policy.h, the code will assume that you have a BSD style    terminal driver.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CBREAK
value|1
end_define

begin_comment
comment|/* The package needs several standard types.  If you are using the    configure script, it will look in standard places for these types,    and give default definitions for them here if it doesn't find them.    The default definitions should work on most systems, but you may    want to check them.  If you are configuring by hand, you will have    to figure out whether the types are defined on your system, and    what they should be defined to.     Each of the types should be defined using #define.  For example,    #define pid_t int    */
end_comment

begin_comment
comment|/* The type pid_t is used to hold a process ID number.  It is normally    defined in<sys/types.h>.  This is the type returned by the    functions fork or getpid.  Usually int will work fine.  */
end_comment

begin_comment
comment|/* A definition of pid_t was found on your system.  */
end_comment

begin_comment
comment|/* The type uid_t is used to hold a user ID number.  It is normally    defined in<sys/types.h>.  This is the type returned by the getuid    function.  Usually int will work fine.  */
end_comment

begin_comment
comment|/* A definition of uid_t was found on your system.  */
end_comment

begin_comment
comment|/* The type gid_t is used to hold a group ID number.  It is sometimes    defined in<sys/types.h>.  This is the type returned by the getgid    function.  Usually int will work fine.  */
end_comment

begin_comment
comment|/* A definition of gid_t was found on your system.  */
end_comment

begin_comment
comment|/* The type off_t is used to hold an offset in a file.  It is sometimes    defined in<sys/types.h>.  This is the type of the second argument to    the lseek function.  Usually long will work fine.  */
end_comment

begin_comment
comment|/* A definition of off_t was found on your system.  */
end_comment

begin_comment
comment|/* Set HAVE_SIG_ATOMIC_T_IN_SIGNAL_H if the type sig_atomic_t is defined    in<signal.h> as required by ANSI C.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIG_ATOMIC_T_IN_SIGNAL_H
value|0
end_define

begin_comment
comment|/* Set HAVE_SIG_ATOMIC_T_IN_TYPES_H if the type sig_atomic_t is defined    in<sys/types.h>.  This is ignored if HAVE_SIG_ATOMIC_T_IN_SIGNAL_H is    set to 1.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIG_ATOMIC_T_IN_TYPES_H
value|0
end_define

begin_comment
comment|/* The type sig_atomic_t is used to hold a value which may be    referenced in a single atomic operation.  If it is not defined in    either<signal.h> or<sys/types.h>, you may want to give it a    definition here (if you don't, the code will use char).  If your    compiler does not support sig_atomic_t, there is no type which is    really correct; fortunately, for this package it does not really    matter very much.  */
end_comment

begin_comment
comment|/* When Taylor UUCP is talking to another instance of itself, it will    tell the other side the size of a file before it is transferred.    If the package can determine how much disk space is available, it    will use this information to avoid filling up the disk.  Define one    of the following macros to tell the code how to determine the    amount of available disk space.  It is possible that none of these    are appropriate; it will do no harm to use none of them, but, of    course, nothing will then prevent the package from filling up the    disk.  Note that this space check is only useful when talking to    another instance of Taylor UUCP.     FS_STATVFS    the statvfs function    FS_USG_STATFS the four argument statfs function    FS_MNTENT     the two argument statfs function with the f_bsize field    FS_STATFS     the two argument statfs function with the f_fsize field    FS_GETMNT     the two argument statfs function with the fd_req field    FS_USTAT      the ustat function with 512 byte blocks.  */
end_comment

begin_define
define|#
directive|define
name|FS_STATFS
end_define

begin_comment
comment|/* Set HAVE_VOID to 1 if the compiler supports declaring functions with    a return type of void and casting values to void.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VOID
value|1
end_define

begin_comment
comment|/* Set HAVE_UNSIGNED_CHAR to 1 if the compiler supports the type unsigned    char.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNSIGNED_CHAR
value|1
end_define

begin_comment
comment|/* Set HAVE_ERRNO_DECLARATION to 1 if errno is declared in<errno.h>.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRNO_DECLARATION
value|1
end_define

begin_comment
comment|/* Set COMBINED_UNBLOCK to 1 if the flags O_NONBLOCK and O_NDELAY can    both be specified at once on a file descriptor.  If your system    does not support both flags, it doesn't matter what you set this    to.  */
end_comment

begin_define
define|#
directive|define
name|COMBINED_UNBLOCK
value|1
end_define

begin_comment
comment|/* There are now a number of functions to check for.  For each of these,    the macro HAVE_FUNC should be set to 1 if your system has FUNC.  For    example, HAVE_STRERROR should be set to 1 if your system has strerror,    0 otherwise.  */
end_comment

begin_comment
comment|/* Taylor UUCP provides its own versions of the following functions,    or knows how to work around their absence.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMSET
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MEMCMP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MEMCHR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MEMCPY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_BCOPY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_BCMP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_BZERO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRRCHR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_RINDEX
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRTOL
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRSTR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRCASECMP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRICMP
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_STRLWR
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_BSEARCH
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_REMOVE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FTRUNCATE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LTRUNC
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_RENAME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_OPENDIR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DUP2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WAITPID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WAIT4
value|1
end_define

begin_comment
comment|/* If you have either sigsetjmp or setret, it will be used instead of    setjmp.  These functions will only be used if your system restarts    system calls after interrupts (see HAVE_RESTARTABLE_SYSCALLS,    below).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGSETJMP
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_SETRET
value|0
end_define

begin_comment
comment|/* The code needs to know what function to use to set a signal    handler.  If will try to use each of the following functions in    turn.  If none are available, it will use signal, which is assumed    to always exist.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SIGVEC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SIGSET
value|0
end_define

begin_comment
comment|/* The code will try to use each of the following functions in turn    when blocking signals from delivery.  If none are available, a    relatively unimportant race condition will exist.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGPROCMASK
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SIGBLOCK
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SIGHOLD
value|0
end_define

begin_comment
comment|/* If you have either of the following functions, it will be used to    determine the number of file descriptors which may be open.    Otherwise, the code will use OPEN_MAX if defined, then NOFILE if    defined, then 20.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETDTABLESIZE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYSCONF
value|0
end_define

begin_comment
comment|/* The code will use one of the following functions when detaching    from a terminal.  One of these must exist.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPGRP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETSID
value|1
end_define

begin_comment
comment|/* If you do not specify the local node name in the main configuration    file, Taylor UUCP will try to use each of the following functions    in turn.  If neither is available, you must specify the local node    name in the configuration file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTNAME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNAME
value|0
end_define

begin_comment
comment|/* The code will try to use each of the following functions in turn to    determine the current time.  If none are available, it will use    time, which is assume to always exist.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FTIME
value|0
end_define

begin_comment
comment|/* If neither gettimeofday nor ftime is available, the code will use    times (if available) to measure a span of time.  See also the    discussion of TIMES_TICK in policy.h.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMES
value|1
end_define

begin_comment
comment|/* When a chat script requests a pause of less than a second with \p,    Taylor UUCP will try to use each of the following functions in    turn.  If none are available, it will sleep for a full second.    Also, the (non-portable) tstuu program requires either select or    poll.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NAPMS
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_NAP
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_USLEEP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_POLL
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_SELECT
value|1
end_define

begin_comment
comment|/* If the getgrent function is available, it will be used to determine    all the groups a user belongs to when checking file access    permissions.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGRENT
value|1
end_define

begin_comment
comment|/* If the socket function is available, TCP support code will be    compiled in.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKET
value|1
end_define

begin_comment
comment|/* The code needs to know to how to get the name of the current    directory.  If getcwd is available it will be used, otherwise if    getwd is available it will be used.  Otherwise, set PWD_PROGRAM to    the name of the program which will print the name of the current    working directory.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETWD
value|1
end_define

begin_define
define|#
directive|define
name|PWD_PROGRAM
value|unused
end_define

begin_comment
comment|/* The code needs to know how to create directories.  If you have the    mkdir function, set HAVE_MKDIR to 1 and replace @UUDIR@ in    Makefile.in with '# ' (the configure script will set @UUDIR@    according to the variable UUDIR).  Otherwise, set HAVE_MKDIR to 0,    remove @UUDIR@ from Makefile.in, and set MKDIR_PROGRAM to the name    of the program which will create a directory named on the command    line.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKDIR
value|1
end_define

begin_define
define|#
directive|define
name|MKDIR_PROGRAM
value|unused
end_define

begin_comment
comment|/* That's the end of the list of the functions.  Now there are a few    last miscellaneous items.  */
end_comment

begin_comment
comment|/* On some systems times is declared in<sys/times.h> as returning    int, so the code cannot safely declare it as returning long.  On    the other hand, on some systems times will not work unless it is    declared as returning long.  Set TIMES_DECLARATION_OK to 1 if times    can be safely declared as returning long.  If you will not be using    times, it doesn't matter what you set this to.  */
end_comment

begin_define
define|#
directive|define
name|TIMES_DECLARATION_OK
value|0
end_define

begin_comment
comment|/* Set HAVE_BSD_PGRP to 1 if your getpgrp call takes 1 argument and    your setpgrp calls takes 2 argument (on System V they generally    take no arguments).  You can safely set this to 1 on System V,    provided the call will compile without any errors.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_BSD_PGRP
value|0
end_define

begin_comment
comment|/* Set HAVE_UNION_WAIT to 1 if union wait is defined in the header    file<sys/wait.h>.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNION_WAIT
value|1
end_define

begin_comment
comment|/* Define UTIME_NULL_MISSING if utime with a NULL second argument does not    set the file times to the current time.  */
end_comment

begin_define
define|#
directive|define
name|UTIME_NULL_MISSING
end_define

begin_comment
comment|/* Set HAVE_LONG_NAMES to 1 if the system supports file names longer    than 14 characters.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_NAMES
value|1
end_define

begin_comment
comment|/* If slow system calls are restarted after interrupts, set    HAVE_RESTARTABLE_SYSCALLS to 1.  This is ignored if HAVE_SIGACTION    is 1 or if HAVE_SIGVEC is 1 and SV_INTERRUPT is defined in<signal.h>.  In both of these cases system calls can be prevented    from restarting.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RESTARTABLE_SYSCALLS
value|1
end_define

end_unit

