begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Whether strstr must be declared even if<string.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_STRSTR */
end_comment

begin_comment
comment|/* Whether fprintf must be declared even if<stdio.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_FPRINTF */
end_comment

begin_comment
comment|/* Whether sbrk must be declared even if<unistd.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_SBRK */
end_comment

begin_comment
comment|/* Whether getenv must be declared even if<stdlib.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_GETENV */
end_comment

begin_comment
comment|/* Define if using alloca.c.  */
end_comment

begin_comment
comment|/* #undef C_ALLOCA */
end_comment

begin_comment
comment|/* Define to one of _getb67, GETB67, getb67 for Cray-2 and Cray-YMP systems.    This function is required for alloca.c support on those systems.  */
end_comment

begin_comment
comment|/* #undef CRAY_STACKSEG_END */
end_comment

begin_comment
comment|/* Define if you have alloca, as a function or macro.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
value|1
end_define

begin_comment
comment|/* Define if you have<alloca.h> and it should be used (not on Ultrix).  */
end_comment

begin_comment
comment|/* #undef HAVE_ALLOCA_H */
end_comment

begin_comment
comment|/* Define if you have<sys/wait.h> that is POSIX.1 compatible.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define if you have<vfork.h>.  */
end_comment

begin_comment
comment|/* #undef HAVE_VFORK_H */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at run-time.  STACK_DIRECTION> 0 => grows toward higher addresses  STACK_DIRECTION< 0 => grows toward lower addresses  STACK_DIRECTION = 0 => direction of growth unknown  */
end_comment

begin_comment
comment|/* #undef STACK_DIRECTION */
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
comment|/* Define vfork as fork if vfork does not work.  */
end_comment

begin_comment
comment|/* #undef vfork */
end_comment

begin_comment
comment|/* Is the type time_t defined in<time.h>?  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_T_IN_TIME_H
value|1
end_define

begin_comment
comment|/* Is the type time_t defined in<sys/types.h>?  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_T_IN_TYPES_H
value|1
end_define

begin_comment
comment|/* Does<utime.h> define struct utimbuf?  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GOOD_UTIME_H
value|1
end_define

begin_comment
comment|/* Do we need to use the b modifier when opening binary files?  */
end_comment

begin_comment
comment|/* #undef USE_BINARY_FOPEN */
end_comment

begin_comment
comment|/* Define if you have the sbrk function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SBRK
value|1
end_define

begin_comment
comment|/* Define if you have the utimes function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIMES
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
comment|/* Define if you have the<strings.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/file.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
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

