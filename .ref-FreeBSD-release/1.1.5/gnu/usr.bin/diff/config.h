begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Define if using alloca.c.  */
end_comment

begin_comment
comment|/* #undef C_ALLOCA */
end_comment

begin_comment
comment|/* Define to empty if the keyword does not work.  */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to one of _getb67, GETB67, getb67 for Cray-2 and Cray-YMP systems.    This function is required for alloca.c support on those systems.  */
end_comment

begin_comment
comment|/* #undef CRAY_STACKSEG_END */
end_comment

begin_comment
comment|/* Define if you have dirent.h.  */
end_comment

begin_define
define|#
directive|define
name|DIRENT
value|1
end_define

begin_comment
comment|/* Define if you have alloca.h and it should be used (not Ultrix).  */
end_comment

begin_comment
comment|/* #undef HAVE_ALLOCA_H */
end_comment

begin_comment
comment|/* Define if you don't have vprintf but do have _doprnt.  */
end_comment

begin_comment
comment|/* #undef HAVE_DOPRNT */
end_comment

begin_comment
comment|/* Define if your struct stat has st_blksize.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ST_BLKSIZE
value|1
end_define

begin_comment
comment|/* Define if you have vfork.h.  */
end_comment

begin_comment
comment|/* #undef HAVE_VFORK_H */
end_comment

begin_comment
comment|/* Define if you have the vprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VPRINTF
value|1
end_define

begin_comment
comment|/* Define if on MINIX.  */
end_comment

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_comment
comment|/* Define if you don't have dirent.h, but have ndir.h.  */
end_comment

begin_comment
comment|/* #undef NDIR */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define if the system does not provide POSIX.1 features except    with this defined.  */
end_comment

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
end_comment

begin_comment
comment|/* Define if you need to in order for stat and other things to work.  */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Define as the return type of signal handlers (int or void).  */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at run-time. 	STACK_DIRECTION> 0 => grows toward higher addresses 	STACK_DIRECTION< 0 => grows toward lower addresses 	STACK_DIRECTION = 0 => direction of growth unknown  */
end_comment

begin_comment
comment|/* #undef STACK_DIRECTION */
end_comment

begin_comment
comment|/* Define if the `S_IS*' macros in<sys/stat.h> do not work properly.  */
end_comment

begin_comment
comment|/* #undef STAT_MACROS_BROKEN */
end_comment

begin_comment
comment|/* Define if you have the ANSI C header files.  */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define if you don't have dirent.h, but have sys/dir.h.  */
end_comment

begin_comment
comment|/* #undef SYSDIR */
end_comment

begin_comment
comment|/* Define if you don't have dirent.h, but have sys/ndir.h.  */
end_comment

begin_comment
comment|/* #undef SYSNDIR */
end_comment

begin_comment
comment|/* Define vfork as fork if vfork does not work.  */
end_comment

begin_comment
comment|/* #undef vfork */
end_comment

begin_comment
comment|/* Define if the closedir function returns void instead of int.  */
end_comment

begin_comment
comment|/* #undef VOID_CLOSEDIR */
end_comment

begin_comment
comment|/* Define if you have dup2.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DUP2
value|1
end_define

begin_comment
comment|/* Define if you have memchr.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCHR
value|1
end_define

begin_comment
comment|/* Define if you have sigaction.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_comment
comment|/* Define if you have strerror.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define if you have waitpid.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_WAITPID
value|1
end_define

begin_comment
comment|/* Define if you have the<fcntl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<limits.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stdlib.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define if you have the<string.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/wait.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<time.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<unistd.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

end_unit

