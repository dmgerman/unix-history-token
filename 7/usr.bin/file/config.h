begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<osreldate.h>
end_include

begin_comment
comment|/* config.h.  Generated from config.h.in by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Use the builtin ELF recognition code */
end_comment

begin_define
define|#
directive|define
name|BUILTIN_ELF
value|1
end_define

begin_comment
comment|/* Recognize ELF core files */
end_comment

begin_define
define|#
directive|define
name|ELFCORE
value|1
end_define

begin_comment
comment|/* */
end_comment

begin_comment
comment|/* #undef HAVE_DAYLIGHT */
end_comment

begin_comment
comment|/* Define to 1 if you have the<dlfcn.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DLFCN_H
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
comment|/* Define to 1 if you have the<getopt.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETOPT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getopt_long' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETOPT_LONG
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
comment|/* Define to 1 if you have the `z' library (-lz). */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBZ
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<limits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

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
comment|/* */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_LONG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mbrtowc' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MBRTOWC
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
comment|/* Define to 1 if you have the `mkstemp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mmap' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP
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
comment|/* Define to 1 if you have the<stdint.h> header file. */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500019
end_if

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Define to 1 if you have the `strerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
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
comment|/* Define to 1 if you have the `strndup' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STRNDUP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `strtof' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strtoul' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOUL
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_rdev' is member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_RDEV
value|1
end_define

begin_comment
comment|/* Define to 1 if your `struct stat' has `st_rdev'. Deprecated, use    `HAVE_STRUCT_STAT_ST_RDEV' instead. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ST_RDEV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/mman.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MMAN_H
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
comment|/* Define to 1 if you have the<sys/time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

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
comment|/* Define to 1 if you have the<sys/utime.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_UTIME_H */
end_comment

begin_comment
comment|/* Define to 1 if you have<sys/wait.h> that is POSIX.1 compatible. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|HAVE_TM_ISDST
value|1
end_define

begin_comment
comment|/* HAVE_TM_ZONE */
end_comment

begin_define
define|#
directive|define
name|HAVE_TM_ZONE
value|1
end_define

begin_comment
comment|/* HAVE_TZNAME */
end_comment

begin_define
define|#
directive|define
name|HAVE_TZNAME
value|1
end_define

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
comment|/* Define to 1 if you have the `utime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `utimes' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIMES
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
comment|/* Define to 1 if you have the<wctype.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCTYPE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `wcwidth' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCWIDTH
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<zlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ZLIB_H
value|1
end_define

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
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"file"
end_define

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|""
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|""
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|""
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|""
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|""
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_INT64_T
value|8
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_UINT16_T
value|2
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_UINT32_T
value|4
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_UINT64_T
value|8
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_UINT8_T
value|1
end_define

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
comment|/* Define to 1 if your<sys/time.h> declares `struct tm'. */
end_comment

begin_comment
comment|/* #undef TM_IN_SYS_TIME */
end_comment

begin_comment
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"4.23"
end_define

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
name|__FreeBSD__
end_ifndef

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
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* */
end_comment

begin_comment
comment|/* #undef int32_t */
end_comment

begin_comment
comment|/* */
end_comment

begin_comment
comment|/* #undef int64_t */
end_comment

begin_comment
comment|/* Define to a type if<wchar.h> does not define. */
end_comment

begin_comment
comment|/* #undef mbstate_t */
end_comment

begin_comment
comment|/* Define to `long int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* */
end_comment

begin_comment
comment|/* #undef uint16_t */
end_comment

begin_comment
comment|/* */
end_comment

begin_comment
comment|/* #undef uint32_t */
end_comment

begin_comment
comment|/* */
end_comment

begin_comment
comment|/* #undef uint64_t */
end_comment

begin_comment
comment|/* */
end_comment

begin_comment
comment|/* #undef uint8_t */
end_comment

end_unit

