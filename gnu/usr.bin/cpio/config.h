begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* config.h.  Generated from config.h.in by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated from configure.ac by autoheader.  */
end_comment

begin_comment
comment|/* Define this to an absolute name of<dirent.h>. */
end_comment

begin_comment
comment|/* #undef ABSOLUTE_DIRENT_H */
end_comment

begin_comment
comment|/* Define this to an absolute name of<fcntl.h>. */
end_comment

begin_define
define|#
directive|define
name|ABSOLUTE_FCNTL_H
value|"///usr/include/fcntl.h"
end_define

begin_comment
comment|/* Define this to an absolute name of<float.h>. */
end_comment

begin_comment
comment|/* #undef ABSOLUTE_FLOAT_H */
end_comment

begin_comment
comment|/* Define this to an absolute name of<inttypes.h>. */
end_comment

begin_define
define|#
directive|define
name|ABSOLUTE_INTTYPES_H
value|"///usr/include/inttypes.h"
end_define

begin_comment
comment|/* Define this to an absolute name of<stdint.h>. */
end_comment

begin_define
define|#
directive|define
name|ABSOLUTE_STDINT_H
value|"///usr/include/stdint.h"
end_define

begin_comment
comment|/* Define this to an absolute name of<stdio.h>. */
end_comment

begin_define
define|#
directive|define
name|ABSOLUTE_STDIO_H
value|"///usr/include/stdio.h"
end_define

begin_comment
comment|/* Define this to an absolute name of<stdlib.h>. */
end_comment

begin_define
define|#
directive|define
name|ABSOLUTE_STDLIB_H
value|"///usr/include/stdlib.h"
end_define

begin_comment
comment|/* Define this to an absolute name of<string.h>. */
end_comment

begin_define
define|#
directive|define
name|ABSOLUTE_STRING_H
value|"///usr/include/string.h"
end_define

begin_comment
comment|/* Define this to an absolute name of<sysexits.h>. */
end_comment

begin_define
define|#
directive|define
name|ABSOLUTE_SYSEXITS_H
value|"///usr/include/sysexits.h"
end_define

begin_comment
comment|/* Define this to an absolute name of<sys/stat.h>. */
end_comment

begin_define
define|#
directive|define
name|ABSOLUTE_SYS_STAT_H
value|"///usr/include/sys/stat.h"
end_define

begin_comment
comment|/* Define this to an absolute name of<sys/time.h>. */
end_comment

begin_define
define|#
directive|define
name|ABSOLUTE_SYS_TIME_H
value|"///usr/include/sys/time.h"
end_define

begin_comment
comment|/* Define this to an absolute name of<time.h>. */
end_comment

begin_define
define|#
directive|define
name|ABSOLUTE_TIME_H
value|"///usr/include/time.h"
end_define

begin_comment
comment|/* Define this to an absolute name of<unistd.h>. */
end_comment

begin_define
define|#
directive|define
name|ABSOLUTE_UNISTD_H
value|"///usr/include/unistd.h"
end_define

begin_comment
comment|/* Define this to an absolute name of<wchar.h>. */
end_comment

begin_comment
comment|/* #undef ABSOLUTE_WCHAR_H */
end_comment

begin_comment
comment|/* Define this to an absolute name of<wctype.h>. */
end_comment

begin_define
define|#
directive|define
name|ABSOLUTE_WCTYPE_H
value|"///usr/include/wctype.h"
end_define

begin_comment
comment|/* Define to the number of bits in type 'ptrdiff_t'. */
end_comment

begin_comment
comment|/* #undef BITSIZEOF_PTRDIFF_T */
end_comment

begin_comment
comment|/* Define to the number of bits in type 'sig_atomic_t'. */
end_comment

begin_comment
comment|/* #undef BITSIZEOF_SIG_ATOMIC_T */
end_comment

begin_comment
comment|/* Define to the number of bits in type 'size_t'. */
end_comment

begin_comment
comment|/* #undef BITSIZEOF_SIZE_T */
end_comment

begin_comment
comment|/* Define to the number of bits in type 'wchar_t'. */
end_comment

begin_comment
comment|/* #undef BITSIZEOF_WCHAR_T */
end_comment

begin_comment
comment|/* Define to the number of bits in type 'wint_t'. */
end_comment

begin_comment
comment|/* #undef BITSIZEOF_WINT_T */
end_comment

begin_comment
comment|/* Define if chown is not POSIX compliant regarding IDs of -1. */
end_comment

begin_comment
comment|/* #undef CHOWN_FAILS_TO_HONOR_ID_OF_NEGATIVE_ONE */
end_comment

begin_comment
comment|/* Define if chown modifies symlinks. */
end_comment

begin_comment
comment|/* #undef CHOWN_MODIFIES_SYMLINK */
end_comment

begin_comment
comment|/* Define to one of `_getb67', `GETB67', `getb67' for Cray-2 and Cray-YMP    systems. This function is required for `alloca.c' support on those systems.    */
end_comment

begin_comment
comment|/* #undef CRAY_STACKSEG_END */
end_comment

begin_comment
comment|/* Define to 1 if using `alloca.c'. */
end_comment

begin_comment
comment|/* #undef C_ALLOCA */
end_comment

begin_comment
comment|/* Define full file name of rmt program. */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_RMT_COMMAND
value|"/etc/rmt"
end_define

begin_comment
comment|/* the name of the file descriptor member of DIR */
end_comment

begin_comment
comment|/* #undef DIR_FD_MEMBER_NAME */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DIR_FD_MEMBER_NAME
end_ifdef

begin_define
define|#
directive|define
name|DIR_TO_FD
parameter_list|(
name|Dir_p
parameter_list|)
value|((Dir_p)->DIR_FD_MEMBER_NAME)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DIR_TO_FD
parameter_list|(
name|Dir_p
parameter_list|)
value|-1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to 1 if // is a file system root distinct from /. */
end_comment

begin_comment
comment|/* #undef DOUBLE_SLASH_IS_DISTINCT_ROOT */
end_comment

begin_comment
comment|/* Define if struct dirent has a member d_ino that actually works. */
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

begin_comment
comment|/* #undef ENABLE_NLS */
end_comment

begin_comment
comment|/* Define as good substitute value for EOVERFLOW. */
end_comment

begin_comment
comment|/* #undef EOVERFLOW */
end_comment

begin_comment
comment|/* Define if gnulib's fchdir() replacement is used. */
end_comment

begin_comment
comment|/* #undef FCHDIR_REPLACEMENT */
end_comment

begin_comment
comment|/* Define on systems for which file names may have a so-called `drive letter'    prefix, define this to compute the length of that prefix, including the    colon. */
end_comment

begin_define
define|#
directive|define
name|FILE_SYSTEM_ACCEPTS_DRIVE_LETTER_PREFIX
value|0
end_define

begin_comment
comment|/* Define if the backslash character may also serve as a file name component    separator. */
end_comment

begin_define
define|#
directive|define
name|FILE_SYSTEM_BACKSLASH_IS_FILE_NAME_SEPARATOR
value|0
end_define

begin_comment
comment|/* Define if a drive letter prefix denotes a relative path if it is not    followed by a file name component separator. */
end_comment

begin_define
define|#
directive|define
name|FILE_SYSTEM_DRIVE_PREFIX_CAN_BE_RELATIVE
value|0
end_define

begin_comment
comment|/* Define if gettimeofday clobbers the localtime buffer. */
end_comment

begin_comment
comment|/* #undef GETTIMEOFDAY_CLOBBERS_LOCALTIME */
end_comment

begin_comment
comment|/* Define to 1 when using the gnulib module close-stream. */
end_comment

begin_define
define|#
directive|define
name|GNULIB_CLOSE_STREAM
value|1
end_define

begin_comment
comment|/* Define to 1 when using the gnulib module fcntl-safer. */
end_comment

begin_define
define|#
directive|define
name|GNULIB_FCNTL_SAFER
value|1
end_define

begin_comment
comment|/* Define to 1 to add extern declaration of program_invocation_name to argp.h    */
end_comment

begin_define
define|#
directive|define
name|GNULIB_PROGRAM_INVOCATION_NAME
value|1
end_define

begin_comment
comment|/* Define to 1 to add extern declaration of program_invocation_short_name to    argp.h */
end_comment

begin_define
define|#
directive|define
name|GNULIB_PROGRAM_INVOCATION_SHORT_NAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `alarm' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALARM
value|1
end_define

begin_comment
comment|/* Define to 1 if you have 'alloca' after including<alloca.h>, a header that    may be supplied by this distribution. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
value|1
end_define

begin_comment
comment|/* Define HAVE_ALLOCA_H for backward compatibility with older code that    includes<alloca.h> only if HAVE_ALLOCA_H is defined. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `btowc' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_BTOWC
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `canonicalize_file_name' function. */
end_comment

begin_comment
comment|/* #undef HAVE_CANONICALIZE_FILE_NAME */
end_comment

begin_comment
comment|/* Define to 1 if you have the MacOS X function CFLocaleCopyCurrent in the    CoreFoundation framework. */
end_comment

begin_comment
comment|/* #undef HAVE_CFLOCALECOPYCURRENT */
end_comment

begin_comment
comment|/* Define to 1 if you have the MacOS X function CFPreferencesCopyAppValue in    the CoreFoundation framework. */
end_comment

begin_comment
comment|/* #undef HAVE_CFPREFERENCESCOPYAPPVALUE */
end_comment

begin_comment
comment|/* Define to 1 if your system has a working `chown' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CHOWN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `clock_gettime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOCK_GETTIME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `clock_settime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOCK_SETTIME
value|1
end_define

begin_comment
comment|/* Define if you have compound literals. */
end_comment

begin_comment
comment|/* #undef HAVE_COMPOUND_LITERALS */
end_comment

begin_comment
comment|/* Define if the GNU dcgettext() function is already present or preinstalled.    */
end_comment

begin_comment
comment|/* #undef HAVE_DCGETTEXT */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `atoi', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_ATOI
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `canonicalize_file_name', and to    0 if you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_CANONICALIZE_FILE_NAME
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `clearerr_unlocked', and to 0 if    you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_CLEARERR_UNLOCKED
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `dirfd', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_DIRFD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `errno', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_ERRNO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `exit', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_EXIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `feof_unlocked', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_FEOF_UNLOCKED
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `ferror_unlocked', and to 0 if    you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_FERROR_UNLOCKED
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `fflush_unlocked', and to 0 if    you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_FFLUSH_UNLOCKED
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `fgets_unlocked', and to 0 if    you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_FGETS_UNLOCKED
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `fputc_unlocked', and to 0 if    you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_FPUTC_UNLOCKED
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `fputs_unlocked', and to 0 if    you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_FPUTS_UNLOCKED
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `fread_unlocked', and to 0 if    you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_FREAD_UNLOCKED
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `fwrite_unlocked', and to 0 if    you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_FWRITE_UNLOCKED
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `getchar_unlocked', and to 0 if    you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GETCHAR_UNLOCKED
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `getcwd', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GETCWD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `getc_unlocked', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GETC_UNLOCKED
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
comment|/* Define to 1 if you have the declaration of `getgrgid', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GETGRGID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `getgrnam', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GETGRNAM
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `getpwnam', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GETPWNAM
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `imaxabs', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_IMAXABS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `imaxdiv', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_IMAXDIV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `isblank', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_ISBLANK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `lchown', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_LCHOWN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `memrchr', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_MEMRCHR
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `mkdir', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_MKDIR
value|1
end_define

begin_comment
comment|/* Define if program_invocation_name is declared */
end_comment

begin_comment
comment|/* #undef HAVE_DECL_PROGRAM_INVOCATION_NAME */
end_comment

begin_comment
comment|/* Define if program_invocation_short_name is declared */
end_comment

begin_comment
comment|/* #undef HAVE_DECL_PROGRAM_INVOCATION_SHORT_NAME */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `putchar_unlocked', and to 0 if    you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_PUTCHAR_UNLOCKED
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `putc_unlocked', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_PUTC_UNLOCKED
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `strdup', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRDUP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `strerror', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRERROR
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
comment|/* Define to 1 if you have the declaration of `strncasecmp', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRNCASECMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `strndup', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRNDUP
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `strnlen', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRNLEN
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `strtoimax', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRTOIMAX
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
comment|/* Define to 1 if you have the declaration of `tzname', and to 0 if you don't.    */
end_comment

begin_comment
comment|/* #undef HAVE_DECL_TZNAME */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `vsnprintf', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_VSNPRINTF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `__fpending', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL___FPENDING
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the<dirent.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `dirfd' function. */
end_comment

begin_comment
comment|/* #undef HAVE_DIRFD */
end_comment

begin_comment
comment|/* Define to 1 if you have the `dup2' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DUP2
value|1
end_define

begin_comment
comment|/* Define if you have the declaration of environ. */
end_comment

begin_comment
comment|/* #undef HAVE_ENVIRON_DECL */
end_comment

begin_comment
comment|/* Define to 1 if you have the `fchdir' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHDIR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fchmod' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHMOD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fchmodat' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FCHMODAT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `fchown' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHOWN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<fcntl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fdopendir' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FDOPENDIR */
end_comment

begin_comment
comment|/* Define to 1 if you have the<features.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_FEATURES_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<float.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FLOAT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `flockfile' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FLOCKFILE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `funlockfile' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FUNLOCKFILE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `futimes' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FUTIMES
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `futimesat' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FUTIMESAT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getcwd' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<getopt.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETOPT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getopt_long_only' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETOPT_LONG_ONLY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpagesize' function. */
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

begin_comment
comment|/* #undef HAVE_GETTEXT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `gettimeofday' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_comment
comment|/* Define if you have the iconv() function and it works. */
end_comment

begin_comment
comment|/* #undef HAVE_ICONV */
end_comment

begin_comment
comment|/* Define to 1 if the compiler supports one of the keywords 'inline',    '__inline__', '__inline' and effectively inlines functions marked as such.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_INLINE
value|1
end_define

begin_comment
comment|/* Define if you have the 'intmax_t' type in<stdint.h> or<inttypes.h>. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTMAX_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<inttypes.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define if<inttypes.h> exists, doesn't clash with<sys/types.h>, and    declares uintmax_t. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H_WITH_UINTMAX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<io.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_IO_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `iswcntrl' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISWCNTRL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `iswctype' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISWCTYPE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `lchmod' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LCHMOD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `lchown' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LCHOWN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<libintl.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LIBINTL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<linewrap.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LINEWRAP_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<locale.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCALE_H
value|1
end_define

begin_comment
comment|/* Define if you have the 'long long' type. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_LONG
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `long long int'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_LONG_INT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `lstat' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LSTAT
value|1
end_define

begin_comment
comment|/* Define to 1 if your system has a GNU libc compatible `malloc' function, and    to 0 otherwise. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MALLOC
value|1
end_define

begin_comment
comment|/* Define to 1 if mbrtowc and mbstate_t are properly declared. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MBRTOWC
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mbsinit' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MBSINIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mbsrtowcs' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MBSRTOWCS
value|1
end_define

begin_comment
comment|/* Define to 1 if<wchar.h> declares mbstate_t. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MBSTATE_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<memory.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mempcpy' function. */
end_comment

begin_comment
comment|/* #undef HAVE_MEMPCPY */
end_comment

begin_comment
comment|/* Define to 1 if you have the `memrchr' function. */
end_comment

begin_comment
comment|/* #undef HAVE_MEMRCHR */
end_comment

begin_comment
comment|/* Define to 1 if you have the `mkdirat' function. */
end_comment

begin_comment
comment|/* #undef HAVE_MKDIRAT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `mkfifo' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKFIFO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `nanotime' function. */
end_comment

begin_comment
comment|/* #undef HAVE_NANOTIME */
end_comment

begin_comment
comment|/* Define to 1 if you have the<ndir.h> header file, and it defines `DIR'. */
end_comment

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netdb.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETDB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<net/errno.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NET_ERRNO_H */
end_comment

begin_comment
comment|/* Define to 1 if libc includes obstacks. */
end_comment

begin_comment
comment|/* #undef HAVE_OBSTACK */
end_comment

begin_comment
comment|/* Define to 1 if you have the `openat' function. */
end_comment

begin_comment
comment|/* #undef HAVE_OPENAT */
end_comment

begin_comment
comment|/* Define to 1 if getcwd works, except it sometimes fails when it shouldn't,    setting errno to ERANGE, ENAMETOOLONG, or ENOENT. If __GETCWD_PREFIX is not    defined, it doesn't matter whether HAVE_PARTLY_WORKING_GETCWD is defined.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_PARTLY_WORKING_GETCWD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pipe' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PIPE
value|1
end_define

begin_comment
comment|/* Define if program_invocation_name is defined */
end_comment

begin_comment
comment|/* #undef HAVE_PROGRAM_INVOCATION_NAME */
end_comment

begin_comment
comment|/* Define if program_invocation_short_name is defined */
end_comment

begin_comment
comment|/* #undef HAVE_PROGRAM_INVOCATION_SHORT_NAME */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `ptrdiff_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTRDIFF_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `readlink' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_READLINK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<search.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SEARCH_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `setenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETENV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setlocale' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLOCALE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sgtty.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SGTTY_H */
end_comment

begin_comment
comment|/* Define to 1 if 'sig_atomic_t' is a signed integer type. */
end_comment

begin_comment
comment|/* #undef HAVE_SIGNED_SIG_ATOMIC_T */
end_comment

begin_comment
comment|/* Define to 1 if 'wchar_t' is a signed integer type. */
end_comment

begin_comment
comment|/* #undef HAVE_SIGNED_WCHAR_T */
end_comment

begin_comment
comment|/* Define to 1 if 'wint_t' is a signed integer type. */
end_comment

begin_comment
comment|/* #undef HAVE_SIGNED_WINT_T */
end_comment

begin_comment
comment|/* Define to 1 if you have the `sleep' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SLEEP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `snprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SNPRINTF
value|1
end_define

begin_comment
comment|/* Define to 1 if stdbool.h conforms to C99. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDBOOL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdint.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_comment
comment|/* Define if<stdint.h> exists, doesn't clash with<sys/types.h>, and declares    uintmax_t. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDINT_H_WITH_UINTMAX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdio_ext.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_STDIO_EXT_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<stdio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDIO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `stpcpy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STPCPY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strcasecmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCASECMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strchrnul' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STRCHRNUL */
end_comment

begin_comment
comment|/* Define to 1 if you have the `strdup' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strerror_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<strings.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<string.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strncasecmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the strndup() function and it works. */
end_comment

begin_comment
comment|/* #undef HAVE_STRNDUP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `strtol' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOL
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_blksize' is member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_BLKSIZE
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_blocks' is member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_BLOCKS
value|1
end_define

begin_comment
comment|/* Define to 1 if `tm_zone' is member of `struct tm'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_TM_TM_ZONE
value|1
end_define

begin_comment
comment|/* Define if struct utimbuf is declared -- usually in<utime.h>. Some systems    have utime.h but don't declare the struct anywhere. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_UTIMBUF
value|1
end_define

begin_comment
comment|/* Define to 1 if your `struct stat' has `st_blksize'. Deprecated, use    `HAVE_STRUCT_STAT_ST_BLKSIZE' instead. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ST_BLKSIZE
value|1
end_define

begin_comment
comment|/* Define to 1 if your `struct stat' has `st_blocks'. Deprecated, use    `HAVE_STRUCT_STAT_ST_BLOCKS' instead. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ST_BLOCKS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sysexits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSEXITS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/bitypes.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_BITYPES_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/buf.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_BUF_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/device.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DEVICE_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/dir.h> header file, and it defines `DIR'.    */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DIR_H */
end_comment

begin_comment
comment|/* Define if your system has sys_errlist global variable */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_ERRLIST
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/gentape.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_GENTAPE_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/inet.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_INET_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/inttypes.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_INTTYPES_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/io/trioctl.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_IO_TRIOCTL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/mtio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MTIO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/ndir.h> header file, and it defines `DIR'.    */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/param.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/stat.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/tape.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_TAPE_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/timeb.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_TIMEB_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/tprintf.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_TPRINTF_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/wait.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_H
value|1
end_define

begin_comment
comment|/* Define if struct tm has the tm_gmtoff member. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TM_GMTOFF
value|1
end_define

begin_comment
comment|/* Define to 1 if your `struct tm' has `tm_zone'. Deprecated, use    `HAVE_STRUCT_TM_TM_ZONE' instead. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TM_ZONE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `tsearch' function. */
end_comment

begin_comment
comment|/* #undef HAVE_TSEARCH */
end_comment

begin_comment
comment|/* Define to 1 if you don't have `tm_zone' but do have the external array    `tzname'. */
end_comment

begin_comment
comment|/* #undef HAVE_TZNAME */
end_comment

begin_comment
comment|/* Define to 1 if you have the<unistd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `unsetenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNSETENV
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `unsigned long long int'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNSIGNED_LONG_LONG_INT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<utime.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<utmp.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTMP_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `vasnprintf' function. */
end_comment

begin_comment
comment|/* #undef HAVE_VASNPRINTF */
end_comment

begin_comment
comment|/* Define to 1 if you have the `vsnprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VSNPRINTF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<wchar.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCHAR_H
value|1
end_define

begin_comment
comment|/* Define if you have the 'wchar_t' type. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCHAR_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `wcslen' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCSLEN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<wctype.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCTYPE_H
value|1
end_define

begin_comment
comment|/* Define if you have the 'wint_t' type. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WINT_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `wmemchr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WMEMCHR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `wmemcpy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WMEMCPY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `wmempcpy' function. */
end_comment

begin_comment
comment|/* #undef HAVE_WMEMPCPY */
end_comment

begin_comment
comment|/* Define to 1 if O_NOATIME works. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WORKING_O_NOATIME
value|0
end_define

begin_comment
comment|/* Define to 1 if O_NOFOLLOW works. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WORKING_O_NOFOLLOW
value|1
end_define

begin_comment
comment|/* Define if utimes works properly. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WORKING_UTIMES
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `_Bool'. */
end_comment

begin_define
define|#
directive|define
name|HAVE__BOOL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `_ftime' function. */
end_comment

begin_comment
comment|/* #undef HAVE__FTIME */
end_comment

begin_comment
comment|/* Define to 1 if you have the `__fpending' function. */
end_comment

begin_comment
comment|/* #undef HAVE___FPENDING */
end_comment

begin_if
if|#
directive|if
name|FILE_SYSTEM_BACKSLASH_IS_FILE_NAME_SEPARATOR
end_if

begin_define
define|#
directive|define
name|ISSLASH
parameter_list|(
name|C
parameter_list|)
value|((C) == '/' || (C) == '\\')
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISSLASH
parameter_list|(
name|C
parameter_list|)
value|((C) == '/')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to 1 if `lstat' dereferences a symlink specified with a trailing    slash. */
end_comment

begin_comment
comment|/* #undef LSTAT_FOLLOWS_SLASHED_SYMLINK */
end_comment

begin_comment
comment|/* Define to 1 if `major', `minor', and `makedev' are declared in<mkdev.h>.    */
end_comment

begin_comment
comment|/* #undef MAJOR_IN_MKDEV */
end_comment

begin_comment
comment|/* Define to 1 if `major', `minor', and `makedev' are declared in<sysmacros.h>. */
end_comment

begin_comment
comment|/* #undef MAJOR_IN_SYSMACROS */
end_comment

begin_comment
comment|/* If malloc(0) is != NULL, define this to 1. Otherwise define this to 0. */
end_comment

begin_define
define|#
directive|define
name|MALLOC_0_IS_NONNULL
value|1
end_define

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
value|"cpio"
end_define

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|"bug-cpio@gnu.org"
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"GNU cpio"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"GNU cpio 2.8-FreeBSD"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"cpio"
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|"2.8-FreeBSD"
end_define

begin_comment
comment|/* the number of pending output bytes on stream `fp' */
end_comment

begin_define
define|#
directive|define
name|PENDING_OUTPUT_N_BYTES
value|fp->_p - fp->_bf._base
end_define

begin_comment
comment|/* Define if<inttypes.h> exists and defines unusable PRI* macros. */
end_comment

begin_comment
comment|/* #undef PRI_MACROS_BROKEN */
end_comment

begin_comment
comment|/* Define to 1 if the C compiler supports function prototypes. */
end_comment

begin_define
define|#
directive|define
name|PROTOTYPES
value|1
end_define

begin_comment
comment|/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type    'ptrdiff_t'. */
end_comment

begin_comment
comment|/* #undef PTRDIFF_T_SUFFIX */
end_comment

begin_comment
comment|/* Define if vasnprintf exists but is overridden by gnulib. */
end_comment

begin_comment
comment|/* #undef REPLACE_VASNPRINTF */
end_comment

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
comment|/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type    'sig_atomic_t'. */
end_comment

begin_comment
comment|/* #undef SIG_ATOMIC_T_SUFFIX */
end_comment

begin_comment
comment|/* Define as the maximum value of type 'size_t', if the system doesn't define    it. */
end_comment

begin_comment
comment|/* #undef SIZE_MAX */
end_comment

begin_comment
comment|/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type    'size_t'. */
end_comment

begin_comment
comment|/* #undef SIZE_T_SUFFIX */
end_comment

begin_comment
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at runtime. 	STACK_DIRECTION> 0 => grows toward higher addresses 	STACK_DIRECTION< 0 => grows toward lower addresses 	STACK_DIRECTION = 0 => direction of growth unknown */
end_comment

begin_comment
comment|/* #undef STACK_DIRECTION */
end_comment

begin_comment
comment|/* Define to 1 if the `S_IS*' macros in<sys/stat.h> do not work properly. */
end_comment

begin_comment
comment|/* #undef STAT_MACROS_BROKEN */
end_comment

begin_comment
comment|/* Define to 1 if you have the ANSI C header files. */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define to 1 if strerror_r returns char *. */
end_comment

begin_comment
comment|/* #undef STRERROR_R_CHAR_P */
end_comment

begin_comment
comment|/* Define to 1 if you can safely include both<sys/time.h> and<time.h>. */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define to 1 if your<sys/time.h> declares `struct tm'. */
end_comment

begin_comment
comment|/* #undef TM_IN_SYS_TIME */
end_comment

begin_comment
comment|/* Define to 1 if you want getc etc. to use unlocked I/O if available.    Unlocked I/O can improve performance in unithreaded apps, but it is not    safe for multithreaded apps. */
end_comment

begin_define
define|#
directive|define
name|USE_UNLOCKED_IO
value|1
end_define

begin_comment
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"2.8-FreeBSD"
end_define

begin_comment
comment|/* Define if unsetenv() returns void, not int. */
end_comment

begin_comment
comment|/* #undef VOID_UNSETENV */
end_comment

begin_comment
comment|/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type    'wchar_t'. */
end_comment

begin_comment
comment|/* #undef WCHAR_T_SUFFIX */
end_comment

begin_comment
comment|/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type    'wint_t'. */
end_comment

begin_comment
comment|/* #undef WINT_T_SUFFIX */
end_comment

begin_comment
comment|/* Define to 1 if on AIX 3.    System headers sometimes define this.    We just want to avoid a redefinition error message.  */
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
comment|/* Enable GNU extensions on systems that have them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_GNU_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define for large files, on AIX-style hosts. */
end_comment

begin_comment
comment|/* #undef _LARGE_FILES */
end_comment

begin_comment
comment|/* Define to 1 if on MINIX. */
end_comment

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_comment
comment|/* Define to 2 if the system does not provide POSIX.1 features except with    this defined. */
end_comment

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
end_comment

begin_comment
comment|/* Define to 1 if you need to in order for `stat' and other things to work. */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Enable extensions on Solaris.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EXTENSIONS__
end_ifndef

begin_define
define|#
directive|define
name|__EXTENSIONS__
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_PTHREAD_SEMANTICS
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_PTHREAD_SEMANTICS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_TANDEM_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_TANDEM_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to rpl_ if the getopt replacement functions and variables should be    used. */
end_comment

begin_define
define|#
directive|define
name|__GETOPT_PREFIX
value|rpl_
end_define

begin_comment
comment|/* Define to rpl_ if the openat replacement function should be used. */
end_comment

begin_define
define|#
directive|define
name|__OPENAT_PREFIX
value|rpl_
end_define

begin_comment
comment|/* Define like PROTOTYPES; this can be used by system headers. */
end_comment

begin_define
define|#
directive|define
name|__PROTOTYPES
value|1
end_define

begin_comment
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to rpl_fchownat if the replacement function should be used. */
end_comment

begin_define
define|#
directive|define
name|fchownat
value|rpl_fchownat
end_define

begin_comment
comment|/* Define to a replacement function name for fnmatch(). */
end_comment

begin_comment
comment|/* #define fnmatch gnu_fnmatch */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef gid_t */
end_comment

begin_comment
comment|/* A replacement for va_copy, if needed.  */
end_comment

begin_define
define|#
directive|define
name|gl_va_copy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) = (b))
end_define

begin_comment
comment|/* Define to rpl_gmtime if the replacement function should be used. */
end_comment

begin_comment
comment|/* #undef gmtime */
end_comment

begin_comment
comment|/* Define to `__inline__' or `__inline' if that's what the C compiler    calls it, or to nothing if 'inline' is not supported under any name.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_comment
comment|/* #undef inline */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to long or long long if<stdint.h> and<inttypes.h> don't define. */
end_comment

begin_comment
comment|/* #undef intmax_t */
end_comment

begin_comment
comment|/* Define to rpl_localtime if the replacement function should be used. */
end_comment

begin_comment
comment|/* #undef localtime */
end_comment

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
comment|/* Define to rpl_mktime if the replacement function should be used. */
end_comment

begin_define
define|#
directive|define
name|mktime
value|rpl_mktime
end_define

begin_comment
comment|/* Define to `long int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

begin_comment
comment|/* Define to a replacement function name for realpath(). */
end_comment

begin_define
define|#
directive|define
name|realpath
value|rpl_realpath
end_define

begin_comment
comment|/* Define to equivalent of C99 restrict keyword, or to nothing if this is not    supported. Do not define if restrict is supported directly. */
end_comment

begin_comment
comment|/* #undef restrict */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* Define as a signed type of the same size as size_t. */
end_comment

begin_comment
comment|/* #undef ssize_t */
end_comment

begin_comment
comment|/* Define to rpl_strnlen if the replacement function should be used. */
end_comment

begin_define
define|#
directive|define
name|strnlen
value|rpl_strnlen
end_define

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define. */
end_comment

begin_comment
comment|/* #undef uid_t */
end_comment

begin_comment
comment|/* Define as a macro for copying va_list variables. */
end_comment

begin_comment
comment|/* #undef va_copy */
end_comment

end_unit

