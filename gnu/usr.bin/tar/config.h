begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated automatically from configure.ac by autoheader.  */
end_comment

begin_comment
comment|/* Define if the `closedir' function returns void instead of `int'. */
end_comment

begin_comment
comment|/* #undef CLOSEDIR_VOID */
end_comment

begin_comment
comment|/* Define to one of `_getb67', `GETB67', `getb67' for Cray-2 and Cray-YMP    systems. This function is required for `alloca.c' support on those systems.    */
end_comment

begin_comment
comment|/* #undef CRAY_STACKSEG_END */
end_comment

begin_comment
comment|/* Define if using `alloca.c'. */
end_comment

begin_comment
comment|/* #undef C_ALLOCA */
end_comment

begin_comment
comment|/* Define to a string giving the full name of the default archive file. */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_ARCHIVE
value|_PATH_DEFTAPE
end_define

begin_comment
comment|/* Define to a number giving the default blocking size for archives. */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_BLOCKING
value|20
end_define

begin_comment
comment|/*    [Define], [to], [1], [if], [density], [may], [be], [indicated], [by], [[lmh]], [at], [end], [of], [device.]    */
end_comment

begin_comment
comment|/* #undef DENSITY_LETTER */
end_comment

begin_comment
comment|/* Define to a string giving the prefix of the default device, without the    part specifying the unit and density. */
end_comment

begin_define
define|#
directive|define
name|DEVICE_PREFIX
value|_PATH_DEFTAPE
end_define

begin_comment
comment|/* Define if there is a member named d_ino in the struct describing directory    headers. */
end_comment

begin_define
define|#
directive|define
name|D_INO_IN_DIRENT
value|1
end_define

begin_comment
comment|/* Define to 1 if translation of program messages to the user's native    language is requested. */
end_comment

begin_define
define|#
directive|define
name|ENABLE_NLS
value|0
end_define

begin_comment
comment|/* Define if you have the `alarm' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALARM
value|1
end_define

begin_comment
comment|/* Define if you have `alloca', as a function or macro. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
value|1
end_define

begin_comment
comment|/* Define if you have<alloca.h> and it should be used (not on Ultrix). */
end_comment

begin_comment
comment|/* #undef HAVE_ALLOCA_H */
end_comment

begin_comment
comment|/* Define if you have the<argz.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_ARGZ_H */
end_comment

begin_comment
comment|/* Define if you have the `clock_gettime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOCK_GETTIME
value|1
end_define

begin_comment
comment|/* Define if backslash-a works in C strings. */
end_comment

begin_define
define|#
directive|define
name|HAVE_C_BACKSLASH_A
value|1
end_define

begin_comment
comment|/* Define if you have the `dcgettext' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DCGETTEXT
value|1
end_define

begin_comment
comment|/* Define to 1 if free is declared. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_FREE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `getenv', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GETENV
value|1
end_define

begin_comment
comment|/* Define to 1 if getgrgid is declared. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GETGRGID
value|1
end_define

begin_comment
comment|/* Define to 1 if getpwuid is declared. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GETPWUID
value|1
end_define

begin_comment
comment|/* Define to 1 if malloc is declared. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_MALLOC
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `strerror_r', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRERROR_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `strtoul', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRTOUL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `strtoull', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRTOULL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `strtoumax', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRTOUMAX
value|1
end_define

begin_comment
comment|/* Define if you have the<dirent.h> header file, and it defines `DIR'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_comment
comment|/* Define if the malloc check has been performed. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DONE_WORKING_MALLOC_CHECK
value|1
end_define

begin_comment
comment|/* Define if the realloc check has been performed. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DONE_WORKING_REALLOC_CHECK
value|1
end_define

begin_comment
comment|/* Define if you don't have `vprintf' but do have `_doprnt.' */
end_comment

begin_comment
comment|/* #undef HAVE_DOPRNT */
end_comment

begin_comment
comment|/* Define if you have the `fchdir' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHDIR
value|1
end_define

begin_comment
comment|/* Define if you have the<fcntl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the `feof_unlocked' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FEOF_UNLOCKED */
end_comment

begin_comment
comment|/* Define if you have the `fgets_unlocked' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FGETS_UNLOCKED */
end_comment

begin_comment
comment|/* Define if your system has a working `fnmatch' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FNMATCH
value|1
end_define

begin_comment
comment|/* Define if you have the `fsync' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FSYNC
value|1
end_define

begin_comment
comment|/* Define if you have the `ftime' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FTIME */
end_comment

begin_comment
comment|/* Define if you have the `ftruncate' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FTRUNCATE
value|1
end_define

begin_comment
comment|/* Define if you have the `getcwd' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_comment
comment|/* Define if getcwd (NULL, 0) allocates memory for result. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD_NULL
value|1
end_define

begin_comment
comment|/* Define if you have the `getegid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETEGID
value|1
end_define

begin_comment
comment|/* Define if you have the `geteuid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETEUID
value|1
end_define

begin_comment
comment|/* Define if you have the `getgid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGID
value|1
end_define

begin_comment
comment|/* Define if you have the `getpagesize' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPAGESIZE
value|1
end_define

begin_comment
comment|/* Define if the GNU gettext() function is already present or preinstalled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTEXT
value|1
end_define

begin_comment
comment|/* Define if you have the `getuid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUID
value|1
end_define

begin_comment
comment|/* Define if you have the iconv() function. */
end_comment

begin_comment
comment|/* #undef HAVE_ICONV */
end_comment

begin_comment
comment|/* Define if you have the<inttypes.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the `isascii' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISASCII
value|1
end_define

begin_comment
comment|/* Define if you have the `iswprint' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ISWPRINT */
end_comment

begin_comment
comment|/* Define if you have<langinfo.h> and nl_langinfo(CODESET). */
end_comment

begin_define
define|#
directive|define
name|HAVE_LANGINFO_CODESET
value|1
end_define

begin_comment
comment|/* Define if you have the `lchown' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LCHOWN
value|1
end_define

begin_comment
comment|/* Define if your<locale.h> file defines LC_MESSAGES. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LC_MESSAGES
value|1
end_define

begin_comment
comment|/* Define if you have the<limits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<linux/fd.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_FD_H */
end_comment

begin_comment
comment|/* Define if you have the<locale.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCALE_H
value|1
end_define

begin_comment
comment|/* Define if you have the `localtime_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCALTIME_R
value|1
end_define

begin_comment
comment|/* Define if you support file names longer than 14 characters. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_FILE_NAMES
value|1
end_define

begin_comment
comment|/* Define if you have the long long type. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_LONG
value|1
end_define

begin_comment
comment|/* Define if you have the `lstat' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LSTAT
value|1
end_define

begin_comment
comment|/* Define if you have the<malloc.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MALLOC_H */
end_comment

begin_comment
comment|/* Define to 1 if mbrtowc and mbstate_t are properly declared. */
end_comment

begin_comment
comment|/* #undef HAVE_MBRTOWC */
end_comment

begin_comment
comment|/* Define if you have the `mbsinit' function. */
end_comment

begin_comment
comment|/* #undef HAVE_MBSINIT */
end_comment

begin_comment
comment|/* Define if you have the<memory.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define if you have the `mempcpy' function. */
end_comment

begin_comment
comment|/* #undef HAVE_MEMPCPY */
end_comment

begin_comment
comment|/* Define if you have the `memset' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMSET
value|1
end_define

begin_comment
comment|/* Define if you have the `mkfifo' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKFIFO
value|1
end_define

begin_comment
comment|/* Define to 1 if the mknod function is available. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKNOD
value|1
end_define

begin_comment
comment|/* Define if you have a working `mmap' system call. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP
value|1
end_define

begin_comment
comment|/* Define if you have the `munmap' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MUNMAP
value|1
end_define

begin_comment
comment|/* Define if you have the `nap' function. */
end_comment

begin_comment
comment|/* #undef HAVE_NAP */
end_comment

begin_comment
comment|/* Define if you have the `napms' function. */
end_comment

begin_comment
comment|/* #undef HAVE_NAPMS */
end_comment

begin_comment
comment|/* Define if you have the<ndir.h> header file, and it defines `DIR'. */
end_comment

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

begin_comment
comment|/* Define if you have the<netdb.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETDB_H */
end_comment

begin_comment
comment|/* Define if you have the<net/errno.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NET_ERRNO_H */
end_comment

begin_comment
comment|/* Define if you have the<nl_types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NL_TYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the `pathconf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PATHCONF
value|1
end_define

begin_comment
comment|/* Define if you have the `poll' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL
value|1
end_define

begin_comment
comment|/* Define if you have the<poll.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL_H
value|1
end_define

begin_comment
comment|/* Define if you have the `putenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PUTENV
value|1
end_define

begin_comment
comment|/* Define if you have the `readlink' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_READLINK
value|1
end_define

begin_comment
comment|/* Define if you have the `rename' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RENAME
value|1
end_define

begin_comment
comment|/* Define if you have the `rmdir' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RMDIR
value|1
end_define

begin_comment
comment|/* Define if you have the `select' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SELECT
value|1
end_define

begin_comment
comment|/* Define if you have the `setenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETENV
value|1
end_define

begin_comment
comment|/* Define if you have the `setlocale' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLOCALE
value|1
end_define

begin_comment
comment|/* Define if you have the<sgtty.h> header file. */
end_comment

begin_comment
comment|/* #define HAVE_SGTTY_H 1 */
end_comment

begin_comment
comment|/* Define if you have the<stdbool.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDBOOL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stddef.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDDEF_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stdint.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define if you have the `stpcpy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STPCPY
value|1
end_define

begin_comment
comment|/* Define if you have the `strcasecmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the `strchr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_comment
comment|/* Define if you have the `strdup' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_comment
comment|/* Define if you have the `strerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define if you have the `strerror_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR_R
value|1
end_define

begin_comment
comment|/* Define if you have the<strings.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<string.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define if you have the `strncasecmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the<stropts.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_STROPTS_H */
end_comment

begin_comment
comment|/* Define if you have the `strstr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSTR
value|1
end_define

begin_comment
comment|/* Define if you have the `strtol' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOL
value|1
end_define

begin_comment
comment|/* Define if you have the `strtoul' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOUL
value|1
end_define

begin_comment
comment|/* Define if you have the `strtoull' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STRTOULL */
end_comment

begin_comment
comment|/* Define if you have the `strtoumax' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOUMAX
value|1
end_define

begin_comment
comment|/* Define if `st_blksize' is member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_BLKSIZE
value|1
end_define

begin_comment
comment|/* Define if `st_blocks' is member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_BLOCKS
value|1
end_define

begin_comment
comment|/* Define if `tm_zone' is member of `struct tm'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_TM_TM_ZONE
value|1
end_define

begin_comment
comment|/* Define if your `struct stat' has `st_blksize'. Deprecated, use    `HAVE_STRUCT_STAT_ST_BLKSIZE' instead. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ST_BLKSIZE
value|1
end_define

begin_comment
comment|/* Define if your `struct stat' has `st_blocks'. Deprecated, use    `HAVE_STRUCT_STAT_ST_BLOCKS' instead. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ST_BLOCKS
value|1
end_define

begin_comment
comment|/* Define if struct stat has a char st_fstype[] member. */
end_comment

begin_comment
comment|/* #undef HAVE_ST_FSTYPE_STRING */
end_comment

begin_comment
comment|/* Define if you have the `symlink' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYMLINK
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/buf.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_BUF_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/device.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DEVICE_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/dir.h> header file, and it defines `DIR'. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DIR_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/gentape.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_GENTAPE_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/inet.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_INET_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/ioccom.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCCOM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/io/trioctl.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_IO_TRIOCTL_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/mtio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MTIO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ndir.h> header file, and it defines `DIR'. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/param.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/stat.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/tape.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_TAPE_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/timeb.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMEB_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/tprintf.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_TPRINTF_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have<sys/wait.h> that is POSIX.1 compatible. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define if your `struct tm' has `tm_zone'. Deprecated, use    `HAVE_STRUCT_TM_TM_ZONE' instead. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TM_ZONE
value|1
end_define

begin_comment
comment|/* Define if you have the `tsearch' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TSEARCH
value|1
end_define

begin_comment
comment|/* Define if you don't have `tm_zone' but do have the external array `tzname'.    */
end_comment

begin_comment
comment|/* #undef HAVE_TZNAME */
end_comment

begin_comment
comment|/* Define if you have the<unistd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define if you have the unsigned long long type. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNSIGNED_LONG_LONG
value|1
end_define

begin_comment
comment|/* Define if you have the `usleep' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_USLEEP
value|1
end_define

begin_comment
comment|/* Define to 1 if utime.h exists and declares struct utimbuf. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the `vprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the `waitpid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WAITPID
value|1
end_define

begin_comment
comment|/* Define if you have the<wchar.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCHAR_H
value|1
end_define

begin_comment
comment|/* Define if you have the<wctype.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCTYPE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if `strerror_r' returns a string. */
end_comment

begin_comment
comment|/* #undef HAVE_WORKING_STRERROR_R */
end_comment

begin_comment
comment|/* Define if you have the `__argz_count' function. */
end_comment

begin_comment
comment|/* #undef HAVE___ARGZ_COUNT */
end_comment

begin_comment
comment|/* Define if you have the `__argz_next' function. */
end_comment

begin_comment
comment|/* #undef HAVE___ARGZ_NEXT */
end_comment

begin_comment
comment|/* Define if you have the `__argz_stringify' function. */
end_comment

begin_comment
comment|/* #undef HAVE___ARGZ_STRINGIFY */
end_comment

begin_comment
comment|/* Define as const if the declaration of iconv() needs const. */
end_comment

begin_comment
comment|/* #undef ICONV_CONST */
end_comment

begin_comment
comment|/* Define if `major', `minor', and `makedev' are declared in<mkdev.h>. */
end_comment

begin_comment
comment|/* #undef MAJOR_IN_MKDEV */
end_comment

begin_comment
comment|/* Define if `major', `minor', and `makedev' are declared in<sysmacros.h>. */
end_comment

begin_comment
comment|/* #undef MAJOR_IN_SYSMACROS */
end_comment

begin_comment
comment|/* Define to mt_model (v.g., for DG/UX), else to mt_type. */
end_comment

begin_define
define|#
directive|define
name|MTIO_CHECK_FIELD
value|mt_type
end_define

begin_comment
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"tar"
end_define

begin_comment
comment|/* Define if the C compiler supports function prototypes. */
end_comment

begin_define
define|#
directive|define
name|PROTOTYPES
value|1
end_define

begin_comment
comment|/* Define to the full path of your rsh, if any. */
end_comment

begin_define
define|#
directive|define
name|REMOTE_SHELL
value|_PATH_RSH
end_define

begin_comment
comment|/* Define as the return type of signal handlers (`int' or `void'). */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at run-time.         STACK_DIRECTION> 0 => grows toward higher addresses         STACK_DIRECTION< 0 => grows toward lower addresses         STACK_DIRECTION = 0 => direction of growth unknown */
end_comment

begin_comment
comment|/* #undef STACK_DIRECTION */
end_comment

begin_comment
comment|/* Define if the `S_IS*' macros in<sys/stat.h> do not work properly. */
end_comment

begin_comment
comment|/* #undef STAT_MACROS_BROKEN */
end_comment

begin_comment
comment|/* Define if you have the ANSI C header files. */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define if you can safely include both<sys/time.h> and<time.h>. */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define if your<sys/time.h> declares `struct tm'. */
end_comment

begin_comment
comment|/* #undef TM_IN_SYS_TIME */
end_comment

begin_comment
comment|/* Define to 1 if using the included libintl implementation. */
end_comment

begin_comment
comment|/* #undef USE_INCLUDED_LIBINTL */
end_comment

begin_comment
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"1.13.25"
end_define

begin_comment
comment|/* Define if on AIX 3.    System headers sometimes define this.    We just want to avoid a redefinition error message.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALL_SOURCE
end_ifndef

begin_comment
comment|/* # undef _ALL_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in a file offset, on hosts where this is settable. */
end_comment

begin_comment
comment|/* #undef _FILE_OFFSET_BITS */
end_comment

begin_comment
comment|/* Define unconditionally for setting a GNU environment. */
end_comment

begin_define
define|#
directive|define
name|_GNU_SOURCE
value|1
end_define

begin_comment
comment|/* Define for large files, on AIX-style hosts. */
end_comment

begin_comment
comment|/* #undef _LARGE_FILES */
end_comment

begin_comment
comment|/* Define if on MINIX. */
end_comment

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_comment
comment|/* Define if the system does not provide POSIX.1 features except with this    defined. */
end_comment

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
end_comment

begin_comment
comment|/* Define if you need to in order for `stat' and other things to work. */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define. */
end_comment

begin_comment
comment|/* #undef gid_t */
end_comment

begin_comment
comment|/* Define as `__inline' if that's what the C compiler calls it, or to nothing    if it is not supported. */
end_comment

begin_comment
comment|/* #undef inline */
end_comment

begin_comment
comment|/* Define to widest signed type if<inttypes.h> doesn't define. */
end_comment

begin_comment
comment|/* #undef intmax_t */
end_comment

begin_comment
comment|/* Type of major device numbers. */
end_comment

begin_define
define|#
directive|define
name|major_t
value|int
end_define

begin_comment
comment|/* Define to rpl_malloc if the replacement function should be used. */
end_comment

begin_comment
comment|/* #undef malloc */
end_comment

begin_comment
comment|/* Define to a type if<wchar.h> does not define. */
end_comment

begin_comment
comment|/* #undef mbstate_t */
end_comment

begin_comment
comment|/* Type of minor device numbers. */
end_comment

begin_define
define|#
directive|define
name|minor_t
value|int
end_define

begin_comment
comment|/* Define to rpl_mktime if the replacement function should be used. */
end_comment

begin_define
define|#
directive|define
name|mktime
value|rpl_mktime
end_define

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef mode_t */
end_comment

begin_comment
comment|/* Define to `long' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define to rpl_realloc if the replacement function should be used. */
end_comment

begin_comment
comment|/* #undef realloc */
end_comment

begin_comment
comment|/* Define to `unsigned' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* Type of sizes or error indications. */
end_comment

begin_comment
comment|/* #undef ssize_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define. */
end_comment

begin_comment
comment|/* #undef uid_t */
end_comment

begin_comment
comment|/* Define to widest unsigned type if<inttypes.h> doesn't define. */
end_comment

begin_comment
comment|/* #undef uintmax_t */
end_comment

end_unit

