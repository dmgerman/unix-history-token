begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* Configuration header file for Taylor UUCP.  -*- C -*-  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* If your compiler does not use const correctly, then undefine it    here.  This #undef is commented out by the configure script if it    determines that const is supported.  */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* If your compiler supports prototypes, set HAVE_PROTOTYPES to 1.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PROTOTYPES
value|1
end_define

begin_comment
comment|/* Set ECHO_PROGRAM to a program which echoes its arguments; if echo    is a shell builtin you can just use "echo".  */
end_comment

begin_define
define|#
directive|define
name|ECHO_PROGRAM
value|"echo"
end_define

begin_comment
comment|/* The following macros indicate what header files you have.  Set the    macro to 1 if you have the corresponding header file, or 0 if you    do not.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDDEF_H
value|1
end_define

begin_comment
comment|/*<stddef.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDARG_H
value|1
end_define

begin_comment
comment|/*<stdarg.h> */
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
name|HAVE_TERMIOS_H
value|1
end_define

begin_comment
comment|/*<termios.h> */
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
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/*<sys/time.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMES_H
value|1
end_define

begin_comment
comment|/*<sys/times.h> */
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
name|HAVE_TIUSER_H
value|0
end_define

begin_comment
comment|/*<tiuser.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_XTI_H
value|0
end_define

begin_comment
comment|/*<xti.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TLI_H
value|0
end_define

begin_comment
comment|/*<sys/tli.h> */
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

begin_define
define|#
directive|define
name|HAVE_FTW_H
value|0
end_define

begin_comment
comment|/*<ftw.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_GLOB_H
value|1
end_define

begin_comment
comment|/*<glob.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SELECT_H
value|0
end_define

begin_comment
comment|/*<sys/select.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_TCP_H
value|0
end_define

begin_comment
comment|/*<sys/types.tcp.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MOUNT_H
value|1
end_define

begin_comment
comment|/*<sys/mount.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_VFS_H
value|0
end_define

begin_comment
comment|/*<sys/vfs.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILSYS_H
value|0
end_define

begin_comment
comment|/*<sys/filsys.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STATFS_H
value|0
end_define

begin_comment
comment|/*<sys/statfs.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_DUSTAT_H
value|0
end_define

begin_comment
comment|/*<sys/dustat.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FS_TYPES_H
value|0
end_define

begin_comment
comment|/*<sys/fs_types.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_USTAT_H
value|0
end_define

begin_comment
comment|/*<ustat.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STATVFS_H
value|0
end_define

begin_comment
comment|/*<sys/statvfs.h> */
end_comment

begin_comment
comment|/* If major and minor are not defined in<sys/types.h>, but are in<sys/mkdev.h>, set MAJOR_IN_MKDEV to 1.  If they are in<sys/sysmacros.h>, set MAJOR_IN_SYSMACROS to 1.  */
end_comment

begin_define
define|#
directive|define
name|MAJOR_IN_MKDEV
value|0
end_define

begin_define
define|#
directive|define
name|MAJOR_IN_SYSMACROS
value|0
end_define

begin_comment
comment|/* If the macro offsetof is not defined in<stddef.h>, you may give it    a definition here.  If you do not, the code will use a definition    (in uucp.h) that should be fairly portable.  */
end_comment

begin_comment
comment|/* #define offsetof */
end_comment

begin_comment
comment|/* Set RETSIGTYPE to the return type of a signal handler.  On newer    systems this will be void; some older systems use int.  */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* If the macro S_ISDIR is defined in<sys/stat.h>, but is incorrect,    define STAT_MACROS_BROKEN to be 1.  This is said to be the case on    Tektronix UTekV, Amdahl UTS and Motorola System V/88.  */
end_comment

begin_define
define|#
directive|define
name|STAT_MACROS_BROKEN
value|0
end_define

begin_comment
comment|/* Set TIME_WITH_SYS_TIME to 1 if<time.h> and<sys/time.h> can both    be included in a single source file; if you don't have either or    both of them, it doesn't matter what you set this to.  */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Set TM_IN_SYS_TIME to 1 if struct tm is defined in<sys/time.h>    rather than in<time.h>.  */
end_comment

begin_define
define|#
directive|define
name|TM_IN_SYS_TIME
value|0
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
comment|/* The package needs several standard types.  If you are using the    configure script, it will look in standard places for these types,    and give default definitions for them here if it doesn't find them.    The default definitions should work on most systems, but you may    want to check them.  If you are configuring by hand, you will have    to figure out whether the types are defined on your system, and    what they should be defined to.     Any type that is not defined on your system should get a macro    definition.  The definition should be of the name of the type in    all capital letters.  For example, #define PID_T int.  If the type    is defined in a standard header file, the macro name should not be    defined.  */
end_comment

begin_comment
comment|/* The type pid_t is used to hold a process ID number.  It is normally    defined in<sys/types.h>.  This is the type returned by the    functions fork or getpid.  Usually int will work fine.  */
end_comment

begin_comment
comment|/* #undef PID_T */
end_comment

begin_comment
comment|/* The type uid_t is used to hold a user ID number.  It is normally    defined in<sys/types.h>.  This is the type returned by the getuid    function.  Usually int will work fine.  */
end_comment

begin_comment
comment|/* #undef UID_T */
end_comment

begin_comment
comment|/* The type gid_t is used to hold a group ID number.  It is sometimes    defined in<sys/types.h>.  This is the type returned by the getgid    function.  Usually int will work fine.  */
end_comment

begin_comment
comment|/* #undef GID_T */
end_comment

begin_comment
comment|/* The type off_t is used to hold an offset in a file.  It is sometimes    defined in<sys/types.h>.  This is the type of the second argument to    the lseek function.  Usually long will work fine.  */
end_comment

begin_comment
comment|/* #undef OFF_T */
end_comment

begin_comment
comment|/* Set HAVE_SIG_ATOMIC_T_IN_SIGNAL_H if the type sig_atomic_t is defined    in<signal.h> as required by ANSI C.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIG_ATOMIC_T_IN_SIGNAL_H
value|1
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
comment|/* The type sig_atomic_t is used to hold a value which may be    referenced in a single atomic operation.  If it is not defined in    either<signal.h> or<sys/types.h>, you may want to give it a    definition here.  If you don't, the code will use char.  If your    compiler does not support sig_atomic_t, there is no type which is    really correct; fortunately, for this package it does not really    matter very much.  */
end_comment

begin_comment
comment|/* #undef SIG_ATOMIC_T */
end_comment

begin_comment
comment|/* Set HAVE_SIZE_T_IN_STDDEF_H to 1 if the type size_t is defined in<stddef.h> as required by ANSI C.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIZE_T_IN_STDDEF_H
value|1
end_define

begin_comment
comment|/* Set HAVE_SIZE_T_IN_TYPES_H to 1 if the type size_t is defined in<sys/types.h>.  This is ignored if HAVE_SIZE_T_IN_STDDEF_H is set    to 1.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIZE_T_IN_TYPES_H
value|1
end_define

begin_comment
comment|/* The type size_t is used to hold the size of an object.  In    particular, an argument of this type is passed as the size argument    to the malloc and realloc functions.  If size_t is not defined in    either<stddef.h> or<sys/types.h>, you may want to give it a    definition here.  If you don't, the code will use unsigned.  */
end_comment

begin_comment
comment|/* #undef SIZE_T */
end_comment

begin_comment
comment|/* Set HAVE_TIME_T_IN_TIME_H to 1 if the type time_t is defined in<time.h>, as required by the ANSI C standard.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_T_IN_TIME_H
value|1
end_define

begin_comment
comment|/* Set HAVE_TIME_T_IN_TYPES_H to 1 if the type time_t is defined in<sys/types.h>.  This is ignored if HAVE_TIME_T_IN_TIME_H is set to    1.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_T_IN_TYPES_H
value|1
end_define

begin_comment
comment|/* When Taylor UUCP is talking to another instance of itself, it will    tell the other side the size of a file before it is transferred.    If the package can determine how much disk space is available, it    will use this information to avoid filling up the disk.  Define one    of the following macros to tell the code how to determine the    amount of available disk space.  It is possible that none of these    are appropriate; it will do no harm to use none of them, but, of    course, nothing will then prevent the package from filling up the    disk.  Note that this space check is only useful when talking to    another instance of Taylor UUCP.     STAT_STATVFS          statvfs function    STAT_STATFS3_OSF1	 three argument statfs function (OSF/1)    STAT_STATFS2_BSIZE    two argument statfs function with f_bsize field    STAT_STATFS2_FSIZE    two argument statfs function with f_fsize field    STAT_STATFS2_FS_DATA  two argument statfs function with fd_req field    STAT_STATFS4          four argument statfs function    STAT_DISK_SPACE	 disk_space function (QNX)    STAT_USTAT            the ustat function with 512 byte blocks.  */
end_comment

begin_define
define|#
directive|define
name|STAT_STATVFS
value|0
end_define

begin_define
define|#
directive|define
name|STAT_STATFS3_OSF1
value|0
end_define

begin_define
define|#
directive|define
name|STAT_STATFS2_BSIZE
value|1
end_define

begin_define
define|#
directive|define
name|STAT_STATFS2_FSIZE
value|0
end_define

begin_define
define|#
directive|define
name|STAT_STATFS2_FS_DATA
value|0
end_define

begin_define
define|#
directive|define
name|STAT_STATFS4
value|0
end_define

begin_define
define|#
directive|define
name|STAT_DISK_SPACE
value|0
end_define

begin_define
define|#
directive|define
name|STAT_USTAT
value|0
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
comment|/* Set HAVE_TXADDCD to 1 if TXADDCD is defined in<sys/ioctl.h>, as it    is on AIX.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TXADDCD
value|0
end_define

begin_comment
comment|/* Set HAVE_SOCKADDR_SA_LEN to 1 if struct sockaddr has sa_len member.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKADDR_SA_LEN
value|1
end_define

begin_comment
comment|/* There are now a number of functions to check for.  For each of    these, the macro HAVE_FUNC should be set to 1 if your system has    FUNC.  For example, HAVE_VFPRINTF should be set to 1 if your system    has vfprintf, 0 otherwise.  */
end_comment

begin_comment
comment|/* Taylor UUCP will take advantage of the following functions if they    are available, but knows how to deal with their absence.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
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
name|HAVE_WAITPID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WAIT4
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GLOB
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETREUID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETEUID
value|1
end_define

begin_comment
comment|/* There are several functions which are replaced in the subdirectory    lib.  If they are missing, the configure script will automatically    add them to lib/Makefile to force them to be recompiled.  If you    are configuring by hand, you will have to do this yourself.  The    string @LIBOBJS@ in lib/Makefile.in should be replaced by a list of    object files in lib/Makefile.  The following comments tell you    which object file names to add (they are generally fairly obvious,    given that the file names have no more than six characters before    the period).  */
end_comment

begin_comment
comment|/* For each of these functions, if it does not exist, the indicated    object file should be added to lib/Makefile.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_BSEARCH
value|1
end_define

begin_comment
comment|/* bsrch.o */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETLINE
value|0
end_define

begin_comment
comment|/* getlin.o */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCHR
value|1
end_define

begin_comment
comment|/* memchr.o */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_comment
comment|/* strdup.o */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSTR
value|1
end_define

begin_comment
comment|/* strstr.o */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOL
value|1
end_define

begin_comment
comment|/* strtol.o */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOUL
value|1
end_define

begin_comment
comment|/* strtou.o */
end_comment

begin_comment
comment|/* If neither of these functions exists, you should add bzero.o to    lib/Makefile.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_BZERO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MEMSET
value|1
end_define

begin_comment
comment|/* If neither of these functions exists, you should add memcmp.o to    lib/Makefile.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCMP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_BCMP
value|1
end_define

begin_comment
comment|/* If neither of these functions exists, you should add memcpy.o to    lib/Makefile.  */
end_comment

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

begin_comment
comment|/* If neither of these functions exists, you should add strcas.o to    lib/Makefile.  */
end_comment

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

begin_comment
comment|/* If neither of these functions exists, you should add strncs.o to    lib/Makefile.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNCASECMP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRNICMP
value|0
end_define

begin_comment
comment|/* If neither of these functions exists, you should add strchr.o to    lib/Makefile.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INDEX
value|1
end_define

begin_comment
comment|/* If neither of these functions exists, you should add strrch.o to    lib/Makefile.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRRCHR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_RINDEX
value|1
end_define

begin_comment
comment|/* If neither of these functions exists, you should add getaddrinfo.o to    lib/Makefile.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETADDRINFO
value|1
end_define

begin_comment
comment|/* There are also Unix specific functions which are replaced in the    subdirectory unix.  If they are missing, the configure script will    automatically add them to unix/Makefile to force them to be    recompiled.  If you are configuring by hand, you will have to do    this yourself.  The string @UNIXOBJS@ in unix/Makefile.in should be    replaced by a list of object files in unix/Makefile.  The following    comments tell you which object file names to add.  */
end_comment

begin_comment
comment|/* For each of these functions, if it does not exist, the indicated    object file should be added to unix/Makefile.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENDIR
value|1
end_define

begin_comment
comment|/* dirent.o */
end_comment

begin_define
define|#
directive|define
name|HAVE_DUP2
value|1
end_define

begin_comment
comment|/* dup2.o */
end_comment

begin_define
define|#
directive|define
name|HAVE_FTW
value|0
end_define

begin_comment
comment|/* ftw.o */
end_comment

begin_define
define|#
directive|define
name|HAVE_REMOVE
value|1
end_define

begin_comment
comment|/* remove.o */
end_comment

begin_define
define|#
directive|define
name|HAVE_RENAME
value|1
end_define

begin_comment
comment|/* rename.o */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* strerr.o */
end_comment

begin_comment
comment|/* The code needs to know how to create directories.  If you have the    mkdir function, set HAVE_MKDIR to 1 and replace @UUDIR@ in    Makefile.in with '# ' (the configure script will set @UUDIR@    according to the variable UUDIR).  Otherwise, set HAVE_MKDIR to 0,    remove @UUDIR@ from Makefile.in, set MKDIR_PROGRAM to the name of    the program which will create a directory named on the command line    (e.g., "/bin/mkdir"), and add mkdir.o to the @UNIXOBJS@ string in    unix/Makefile.in.  */
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
comment|/* The code also needs to know how to remove directories.  If you have    the rmdir function, set HAVE_RMDIR to 1.  Otherwise, set    RMDIR_PROGRAM to the name of the program which will remove a    directory named on the command line (e.g., "/bin/rmdir") and add    rmdir.o to the @UNIXOBJS@ string in unix/Makefile.in.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RMDIR
value|1
end_define

begin_define
define|#
directive|define
name|RMDIR_PROGRAM
value|unused
end_define

begin_comment
comment|/* The code needs to know to how to get the name of the current    directory.  If getcwd is available it will be used, otherwise if    getwd is available it will be used.  Otherwise, set PWD_PROGRAM to    the name of the program which will print the name of the current    working directory (e.g., "/bin/pwd") and add getcwd.o to the    @UNIXOBJS@ string in unix/Makefile.in.  */
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
comment|/* If you have either sigsetjmp or setret, it will be used instead of    setjmp.  These functions will only be used if your system restarts    system calls after interrupts (see HAVE_RESTARTABLE_SYSCALLS,    below).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGSETJMP
value|1
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
comment|/* If the code is going to use sigvec (HAVE_SIGACTION is 0 and    HAVE_SIGVEC is 1), then HAVE_SIGVEC_SV_FLAGS must be set to 1 if    the sigvec structure contains the sv_flags field, or 0 if the    sigvec structure contains the sv_onstack field.  If the code is not    going to use sigvec, it doesn't matter what this is set to.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGVEC_SV_FLAGS
value|1
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
value|1
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
value|1
end_define

begin_comment
comment|/* The code will try to use each of the following functions in turn to    determine the current time.  If none are available, it will use    time, which is assumed to always exist.  */
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
comment|/* If the t_open function is available, TLI support code will be    compiled in.  This may require adding a library, such as -lnsl or    -lxti, to the Makefile variables LIBS.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_T_OPEN
value|0
end_define

begin_comment
comment|/* If the dev_info function is available (QNX only), it will be used    to determine if any other process has the serial port open, and    that will cause uucico and cu to presume the port is locked.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DEV_INFO
value|0
end_define

begin_comment
comment|/* That's the end of the list of the functions.  Now there are a few    last miscellaneous items.  */
end_comment

begin_comment
comment|/* On some systems the following functions are declared in such a way    that the code cannot make a simple extern.  On other systems, these    functions are not declared at all, and the extern is required.  If    a declaration of the function, as shown, compiles on your system,    set the value to 1.  Not all functions declared externally are    listed here, only the ones with which I have had trouble.  */
end_comment

begin_comment
comment|/* extern long times (); */
end_comment

begin_define
define|#
directive|define
name|TIMES_DECLARATION_OK
value|0
end_define

begin_comment
comment|/* extern struct passwd *getpwnam (); */
end_comment

begin_define
define|#
directive|define
name|GETPWNAM_DECLARATION_OK
value|1
end_define

begin_comment
comment|/* extern struct passwd *getpwuid (); */
end_comment

begin_define
define|#
directive|define
name|GETPWUID_DECLARATION_OK
value|1
end_define

begin_comment
comment|/* extern struct group *getgrent (); */
end_comment

begin_define
define|#
directive|define
name|GETGRENT_DECLARATION_OK
value|1
end_define

begin_comment
comment|/* Set HAVE_BSD_PGRP to 1 if your getpgrp call takes 1 argument and    your setpgrp calls takes 2 arguments (on System V they generally    take no arguments).  You can safely set this to 1 on System V,    provided the call will compile without any errors.  */
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
comment|/* Set HAVE_LONG_FILE_NAMES to 1 if the system supports file names    longer than 14 characters.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_FILE_NAMES
value|1
end_define

begin_comment
comment|/* If slow system calls are restarted after interrupts, set    HAVE_RESTARTABLE_SYSCALLS to 1.  This is ignored if HAVE_SIGACTION    is 1 or if HAVE_SIGVEC is 1 and HAVE_SIGVEC_SV_FLAGS is 1 and    SV_INTERRUPT is defined in<signal.h>.  In both of these cases    system calls can be prevented from restarting.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RESTARTABLE_SYSCALLS
value|1
end_define

begin_comment
comment|/* Some systems supposedly need the following macros to be defined.    These are handled by the configure script.  If you are configuring    by hand, you may add appropriate definitions here, or just add them    to CFLAGS when running make.  */
end_comment

begin_comment
comment|/* #undef _ALL_SOURCE */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
end_comment

end_unit

