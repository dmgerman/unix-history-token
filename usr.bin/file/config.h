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
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Define to empty if the keyword does not work.  */
end_comment

begin_comment
comment|/* #undef const */
end_comment

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
comment|/* Define if you have<sys/wait.h> that is POSIX.1 compatible.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define if major, minor, and makedev are declared in<mkdev.h>.  */
end_comment

begin_comment
comment|/* #undef MAJOR_IN_MKDEV */
end_comment

begin_comment
comment|/* Define if major, minor, and makedev are declared in<sysmacros.h>.  */
end_comment

begin_comment
comment|/* #undef MAJOR_IN_SYSMACROS */
end_comment

begin_comment
comment|/* Define to `long' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef off_t */
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
comment|/* Define if your<sys/time.h> declares struct tm.  */
end_comment

begin_comment
comment|/* #undef TM_IN_SYS_TIME */
end_comment

begin_comment
comment|/* Define if builtin ELF support is enabled.  */
end_comment

begin_define
define|#
directive|define
name|BUILTIN_ELF
value|1
end_define

begin_comment
comment|/* Define if ELF core file support is enabled.  */
end_comment

begin_define
define|#
directive|define
name|ELFCORE
value|1
end_define

begin_comment
comment|/* Define if the `long long' type works.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_LONG
value|1
end_define

begin_comment
comment|/* Define if we have "tm_isdst" in "struct tm".  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TM_ISDST
value|1
end_define

begin_comment
comment|/* Define if we have a global "int" variable "daylight".  */
end_comment

begin_comment
comment|/* #undef HAVE_DAYLIGHT */
end_comment

begin_comment
comment|/* Define to `unsigned char' if standard headers don't define.  */
end_comment

begin_comment
comment|/* #undef uint8_t */
end_comment

begin_comment
comment|/* Define to `unsigned short' if standard headers don't define.  */
end_comment

begin_comment
comment|/* #undef uint16_t */
end_comment

begin_comment
comment|/* Define to `unsigned int' if standard headers don't define.  */
end_comment

begin_comment
comment|/* #undef uint32_t */
end_comment

begin_comment
comment|/* Define to `unsigned long long', if available, or `unsigned long', if    standard headers don't define.  */
end_comment

begin_comment
comment|/* #undef uint64_t */
end_comment

begin_comment
comment|/* The number of bytes in a uint8_t.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_UINT8_T
value|1
end_define

begin_comment
comment|/* The number of bytes in a uint16_t.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_UINT16_T
value|2
end_define

begin_comment
comment|/* The number of bytes in a uint32_t.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_UINT32_T
value|4
end_define

begin_comment
comment|/* The number of bytes in a uint64_t.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_UINT64_T
value|8
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
comment|/* Define if you have the mmap function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP
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
comment|/* Define if you have the strtoul function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOUL
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
comment|/* Define if you have the<getopt.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETOPT_H */
end_comment

begin_comment
comment|/* Define if you have the<locale.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCALE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stdint.h> header file.  */
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
comment|/* Define if you have the<sys/mman.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MMAN_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/stat.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/types.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
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
comment|/* Define if you have the z library (-lz).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBZ
value|1
end_define

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
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"3.39"
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
comment|/* Number of bits in a file offset, on hosts where this is settable. */
end_comment

begin_comment
comment|/* #undef _FILE_OFFSET_BITS */
end_comment

begin_comment
comment|/* Define for large files, on AIX-style hosts. */
end_comment

begin_comment
comment|/* #undef _LARGE_FILES */
end_comment

end_unit

