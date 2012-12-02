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
comment|/* Define in built-in ELF support is used */
end_comment

begin_define
define|#
directive|define
name|BUILTIN_ELF
value|1
end_define

begin_comment
comment|/* Define for ELF core file support */
end_comment

begin_define
define|#
directive|define
name|ELFCORE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `asprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ASPRINTF
value|1
end_define

begin_comment
comment|/* HAVE_DAYLIGHT */
end_comment

begin_comment
comment|/* #undef HAVE_DAYLIGHT */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `daylight', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_DAYLIGHT
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `tzname', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_TZNAME
value|1
end_define

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
comment|/* Define to 1 if you have the<err.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERR_H
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
comment|/* Define to 1 if you have the `fork' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FORK
value|1
end_define

begin_comment
comment|/* Define to 1 if fseeko (and presumably ftello) exists and is declared. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FSEEKO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getline' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETLINE
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
comment|/* Define to 1 if the system has the type `int32_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INT32_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `int64_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INT64_T
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
comment|/* Define to 1 if you have the `gnurx' library (-lgnurx). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBGNURX */
end_comment

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
comment|/* Define to 1 if the system has the type `pid_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PID_T
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
comment|/* Define to 1 if you have the `strlcat' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCAT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strlcpy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCPY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strndup' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNDUP
value|1
end_define

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
comment|/* HAVE_STRUCT_OPTION */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_OPTION
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_rdev' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_RDEV
value|1
end_define

begin_comment
comment|/* Define to 1 if `tm_gmtoff' is a member of `struct tm'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_TM_TM_GMTOFF
value|1
end_define

begin_comment
comment|/* Define to 1 if `tm_zone' is a member of `struct tm'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_TM_TM_ZONE
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
comment|/* HAVE_TM_ISDST */
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
comment|/* Define to 1 if the system has the type `uint16_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINT16_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `uint32_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINT32_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `uint64_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINT64_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `uint8_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINT8_T
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
comment|/* Define to 1 if you have the `vasprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VASPRINTF
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
comment|/* Define to the sub-directory in which libtool stores uninstalled libraries.    */
end_comment

begin_define
define|#
directive|define
name|LT_OBJDIR
value|".libs/"
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
comment|/* Define to 1 if your C compiler doesn't accept -c and -o together. */
end_comment

begin_comment
comment|/* #undef NO_MINUS_C_MINUS_O */
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
value|"christos@astron.com"
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"file"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"file 5.11"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"file"
end_define

begin_comment
comment|/* Define to the home page for this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_URL
value|""
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|"5.11"
end_define

begin_comment
comment|/* The size of `long long', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_LONG_LONG
value|8
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
comment|/* Enable extensions on AIX 3, Interix.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALL_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_ALL_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Enable threading extensions on Solaris.  */
end_comment

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

begin_comment
comment|/* Enable extensions on HP NonStop.  */
end_comment

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
comment|/* Enable general extensions on Solaris.  */
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

begin_comment
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"5.11"
end_define

begin_comment
comment|/* Number of bits in a file offset, on hosts where this is settable. */
end_comment

begin_comment
comment|/* #undef _FILE_OFFSET_BITS */
end_comment

begin_comment
comment|/* Define to 1 to make fseeko visible on some hosts (e.g. glibc 2.2). */
end_comment

begin_comment
comment|/* #undef _LARGEFILE_SOURCE */
end_comment

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
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_FREEBSD_UNUSED_
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UINT8_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UINT16_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UINT32_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INT32_T
end_ifndef

begin_typedef
typedef|typedef
name|int
name|int32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UINT64_T
end_ifndef

begin_if
if|#
directive|if
name|SIZEOF_LONG_LONG
operator|==
literal|8
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|uint64_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|uint64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INT64_T
end_ifndef

begin_if
if|#
directive|if
name|SIZEOF_LONG_LONG
operator|==
literal|8
end_if

begin_typedef
typedef|typedef
name|long
name|long
name|int64_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|long
name|int64_t
typedef|;
end_typedef

begin_endif
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

begin_comment
comment|/* _FREEBSD_UNUSED_ */
end_comment

end_unit

