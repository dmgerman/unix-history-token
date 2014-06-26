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
comment|/* Define if building universal (internal helper macro) */
end_comment

begin_comment
comment|/* #undef AC_APPLE_UNIVERSAL_BUILD */
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
comment|/* Define to 1 if you have the `asctime_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ASCTIME_R
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
comment|/* Define to 1 if you have the `ctime_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CTIME_R
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
comment|/* Define to 1 if you have the `fmtcheck' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FMTCHECK
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
comment|/* Define to 1 if you have the `getpagesize' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPAGESIZE
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `intptr_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTPTR_T
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
comment|/* Define to 1 if mbrtowc and mbstate_t are properly declared. */
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
comment|/* Define to 1 if you have the `mkostemp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKOSTEMP
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
comment|/* Define to 1 if you have a working `mmap' system call. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pread' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PREAD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stddef.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDDEF_H
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
comment|/* Define to 1 if you have the `strcasestr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCASESTR
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
comment|/* Define to 1 if the system has the type `uintptr_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINTPTR_T
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
comment|/* Define to 1 if you have the `vfork' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VFORK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<vfork.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_VFORK_H */
end_comment

begin_comment
comment|/* Define to 1 or 0, depending whether the compiler supports simple visibility    declarations. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VISIBILITY
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
comment|/* Define to 1 if `fork' works. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WORKING_FORK
value|1
end_define

begin_comment
comment|/* Define to 1 if `vfork' works. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WORKING_VFORK
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
value|"file 5.19"
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
value|"5.19"
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
value|"5.19"
end_define

begin_comment
comment|/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most    significant byte first (like Motorola and SPARC, unlike Intel). */
end_comment

begin_if
if|#
directive|if
name|defined
name|AC_APPLE_UNIVERSAL_BUILD
end_if

begin_if
if|#
directive|if
name|defined
name|__BIG_ENDIAN__
end_if

begin_define
define|#
directive|define
name|WORDS_BIGENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|WORDS_BIGENDIAN
end_ifndef

begin_comment
comment|/* #  undef WORDS_BIGENDIAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable large inode numbers on Mac OS X 10.5.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DARWIN_USE_64_BIT_INODE
end_ifndef

begin_define
define|#
directive|define
name|_DARWIN_USE_64_BIT_INODE
value|1
end_define

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
comment|/* Define for Solaris 2.5.1 so the uint32_t typedef from<sys/synch.h>,<pthread.h>, or<semaphore.h> is not used. If the typedef were allowed, the    #define below would cause a syntax error. */
end_comment

begin_comment
comment|/* #undef _UINT32_T */
end_comment

begin_comment
comment|/* Define for Solaris 2.5.1 so the uint64_t typedef from<sys/synch.h>,<pthread.h>, or<semaphore.h> is not used. If the typedef were allowed, the    #define below would cause a syntax error. */
end_comment

begin_comment
comment|/* #undef _UINT64_T */
end_comment

begin_comment
comment|/* Define for Solaris 2.5.1 so the uint8_t typedef from<sys/synch.h>,<pthread.h>, or<semaphore.h> is not used. If the typedef were allowed, the    #define below would cause a syntax error. */
end_comment

begin_comment
comment|/* #undef _UINT8_T */
end_comment

begin_comment
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to the type of a signed integer type of width exactly 32 bits if    such a type exists and the standard includes do not define it. */
end_comment

begin_comment
comment|/* #undef int32_t */
end_comment

begin_comment
comment|/* Define to the type of a signed integer type of width exactly 64 bits if    such a type exists and the standard includes do not define it. */
end_comment

begin_comment
comment|/* #undef int64_t */
end_comment

begin_comment
comment|/* Define to the type of a signed integer type wide enough to hold a pointer,    if such a type exists, and if the system does not define it. */
end_comment

begin_comment
comment|/* #undef intptr_t */
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
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* Define to the type of an unsigned integer type of width exactly 16 bits if    such a type exists and the standard includes do not define it. */
end_comment

begin_comment
comment|/* #undef uint16_t */
end_comment

begin_comment
comment|/* Define to the type of an unsigned integer type of width exactly 32 bits if    such a type exists and the standard includes do not define it. */
end_comment

begin_comment
comment|/* #undef uint32_t */
end_comment

begin_comment
comment|/* Define to the type of an unsigned integer type of width exactly 64 bits if    such a type exists and the standard includes do not define it. */
end_comment

begin_comment
comment|/* #undef uint64_t */
end_comment

begin_comment
comment|/* Define to the type of an unsigned integer type of width exactly 8 bits if    such a type exists and the standard includes do not define it. */
end_comment

begin_comment
comment|/* #undef uint8_t */
end_comment

begin_comment
comment|/* Define to the type of an unsigned integer type wide enough to hold a    pointer, if such a type exists, and if the system does not define it. */
end_comment

begin_comment
comment|/* #undef uintptr_t */
end_comment

begin_comment
comment|/* Define as `fork' if `vfork' does not work. */
end_comment

begin_comment
comment|/* #undef vfork */
end_comment

end_unit

