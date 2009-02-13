begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* *****[ libU77 ]***** */
end_comment

begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.hin.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Define to empty if the keyword does not work.  */
end_comment

begin_comment
comment|/* #undef const */
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
comment|/* Define if your struct stat has st_blocks.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ST_BLOCKS
value|1
end_define

begin_comment
comment|/* Define if your struct stat has st_rdev.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ST_RDEV
value|1
end_define

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef mode_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define to `unsigned' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef size_t */
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
comment|/* Define if you can safely include both<sys/time.h> and<time.h>.  */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define if your<sys/time.h> declares struct tm.  */
end_comment

begin_comment
comment|/* #undef TM_IN_SYS_TIME */
end_comment

begin_comment
comment|/* Define as the path of the `chmod' program. */
end_comment

begin_define
define|#
directive|define
name|CHMOD_PATH
value|"/bin/chmod"
end_define

begin_comment
comment|/* Define if your gettimeofday takes only one argument. */
end_comment

begin_comment
comment|/* #undef GETTIMEOFDAY_ONE_ARGUMENT */
end_comment

begin_comment
comment|/* Define if your gettimeofday takes a time zome argument. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMEZONE
value|1
end_define

begin_comment
comment|/* Define if you have the alarm function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALARM
value|1
end_define

begin_comment
comment|/* Define if you have the clock function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOCK
value|1
end_define

begin_comment
comment|/* Define if you have the getcwd function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_comment
comment|/* Define if you have the getgid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGID
value|1
end_define

begin_comment
comment|/* Define if you have the gethostname function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTNAME
value|1
end_define

begin_comment
comment|/* Define if you have the getlogin function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETLOGIN
value|1
end_define

begin_comment
comment|/* Define if you have the getrusage function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETRUSAGE
value|1
end_define

begin_comment
comment|/* Define if you have the gettimeofday function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_comment
comment|/* Define if you have the getuid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUID
value|1
end_define

begin_comment
comment|/* Define if you have the getwd function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETWD
value|1
end_define

begin_comment
comment|/* Define if you have the kill function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_KILL
value|1
end_define

begin_comment
comment|/* Define if you have the link function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LINK
value|1
end_define

begin_comment
comment|/* Define if you have the lstat function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LSTAT
value|1
end_define

begin_comment
comment|/* Define if you have the strerror function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define if you have the symlink function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYMLINK
value|1
end_define

begin_comment
comment|/* Define if you have the times function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMES
value|1
end_define

begin_comment
comment|/* Define if you have the ttyname function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TTYNAME
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
comment|/* Define if you have the<sys/param.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/time.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/times.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMES_H
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

begin_comment
comment|/* Get Single Unix Specification semantics */
end_comment

begin_define
define|#
directive|define
name|_XOPEN_SOURCE
value|600L
end_define

begin_comment
comment|/* Get Single Unix Specification semantics */
end_comment

begin_define
define|#
directive|define
name|_XOPEN_SOURCE_EXTENDED
value|1
end_define

begin_comment
comment|/* Solaris extensions */
end_comment

begin_define
define|#
directive|define
name|__EXTENSIONS__
value|1
end_define

begin_comment
comment|/* Get 64-bit file size support */
end_comment

begin_define
define|#
directive|define
name|_FILE_OFFSET_BITS
value|64
end_define

begin_comment
comment|/* *****[ libI77 ]***** */
end_comment

begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Define to `long' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

begin_comment
comment|/* Define if you have the fseeko function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FSEEKO
value|1
end_define

begin_comment
comment|/* Define if you have the ftello function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FTELLO
value|1
end_define

begin_comment
comment|/* Define if you have the ftruncate function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FTRUNCATE
value|1
end_define

begin_comment
comment|/* Define if you have the mkstemp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
value|1
end_define

begin_comment
comment|/* Define if you have the tempnam function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TEMPNAM
value|1
end_define

begin_comment
comment|/* Define if you have the tmpnam function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TMPNAM
value|1
end_define

begin_comment
comment|/* Define for HP-UX ftello and fseeko extension. */
end_comment

begin_define
define|#
directive|define
name|_LARGEFILE_SOURCE
value|1
end_define

begin_comment
comment|/* Define if we do not have Unix Stdio. */
end_comment

begin_comment
comment|/* #undef NON_UNIX_STDIO */
end_comment

begin_comment
comment|/* Define if we use strlen. */
end_comment

begin_comment
comment|/* #undef USE_STRLEN */
end_comment

begin_comment
comment|/* Define if we have non ANSI RW modes. */
end_comment

begin_define
define|#
directive|define
name|NON_ANSI_RW_MODES
value|1
end_define

begin_comment
comment|/* Always defined. */
end_comment

begin_define
define|#
directive|define
name|NO_EOF_CHAR_CHECK
value|1
end_define

begin_comment
comment|/* Define to skip f2c undefs. */
end_comment

begin_define
define|#
directive|define
name|Skip_f2c_Undefs
value|1
end_define

end_unit

