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
comment|/* How many MiB of RAM to assume if the real amount cannot be determined. */
end_comment

begin_define
define|#
directive|define
name|ASSUME_RAM
value|128
end_define

begin_comment
comment|/* Define to 1 if translation of program messages to the user's native    language is requested. */
end_comment

begin_comment
comment|/* FreeBSD - disabled intentionally */
end_comment

begin_comment
comment|/* #undef ENABLE_NLS */
end_comment

begin_comment
comment|/* Define to 1 if bswap_16 is available. */
end_comment

begin_comment
comment|/* #undef HAVE_BSWAP_16 */
end_comment

begin_comment
comment|/* Define to 1 if bswap_32 is available. */
end_comment

begin_comment
comment|/* #undef HAVE_BSWAP_32 */
end_comment

begin_comment
comment|/* Define to 1 if bswap_64 is available. */
end_comment

begin_comment
comment|/* #undef HAVE_BSWAP_64 */
end_comment

begin_comment
comment|/* Define to 1 if you have the<byteswap.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_BYTESWAP_H */
end_comment

begin_comment
comment|/* Define to 1 if Capsicum is available. */
end_comment

begin_comment
comment|/* #undef HAVE_CAPSICUM */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `CC_SHA256_CTX'. */
end_comment

begin_comment
comment|/* #undef HAVE_CC_SHA256_CTX */
end_comment

begin_comment
comment|/* Define to 1 if you have the `CC_SHA256_Init' function. */
end_comment

begin_comment
comment|/* #undef HAVE_CC_SHA256_INIT */
end_comment

begin_comment
comment|/* Define to 1 if you have the Mac OS X function CFLocaleCopyCurrent in the    CoreFoundation framework. */
end_comment

begin_comment
comment|/* #undef HAVE_CFLOCALECOPYCURRENT */
end_comment

begin_comment
comment|/* Define to 1 if you have the Mac OS X function CFPreferencesCopyAppValue in    the CoreFoundation framework. */
end_comment

begin_comment
comment|/* #undef HAVE_CFPREFERENCESCOPYAPPVALUE */
end_comment

begin_comment
comment|/* Define to 1 if crc32 integrity check is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CHECK_CRC32
value|1
end_define

begin_comment
comment|/* Define to 1 if crc64 integrity check is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CHECK_CRC64
value|1
end_define

begin_comment
comment|/* Define to 1 if sha256 integrity check is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CHECK_SHA256
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
comment|/* Define to 1 if you have the<CommonCrypto/CommonDigest.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_COMMONCRYPTO_COMMONDIGEST_H */
end_comment

begin_comment
comment|/* Define if the GNU dcgettext() function is already present or preinstalled.    */
end_comment

begin_comment
comment|/* FreeBSD - disabled intentionally */
end_comment

begin_comment
comment|/* #undef HAVE_DCGETTEXT */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `CLOCK_MONOTONIC', and to 0 if    you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_CLOCK_MONOTONIC
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `program_invocation_name', and    to 0 if you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_PROGRAM_INVOCATION_NAME
value|0
end_define

begin_comment
comment|/* Define to 1 if any of HAVE_DECODER_foo have been defined. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECODERS
value|1
end_define

begin_comment
comment|/* Define to 1 if arm decoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECODER_ARM
value|1
end_define

begin_comment
comment|/* Define to 1 if armthumb decoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECODER_ARMTHUMB
value|1
end_define

begin_comment
comment|/* Define to 1 if delta decoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECODER_DELTA
value|1
end_define

begin_comment
comment|/* Define to 1 if ia64 decoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECODER_IA64
value|1
end_define

begin_comment
comment|/* Define to 1 if lzma1 decoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECODER_LZMA1
value|1
end_define

begin_comment
comment|/* Define to 1 if lzma2 decoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECODER_LZMA2
value|1
end_define

begin_comment
comment|/* Define to 1 if powerpc decoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECODER_POWERPC
value|1
end_define

begin_comment
comment|/* Define to 1 if sparc decoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECODER_SPARC
value|1
end_define

begin_comment
comment|/* Define to 1 if x86 decoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECODER_X86
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
comment|/* Define to 1 if any of HAVE_ENCODER_foo have been defined. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ENCODERS
value|1
end_define

begin_comment
comment|/* Define to 1 if arm encoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ENCODER_ARM
value|1
end_define

begin_comment
comment|/* Define to 1 if armthumb encoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ENCODER_ARMTHUMB
value|1
end_define

begin_comment
comment|/* Define to 1 if delta encoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ENCODER_DELTA
value|1
end_define

begin_comment
comment|/* Define to 1 if ia64 encoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ENCODER_IA64
value|1
end_define

begin_comment
comment|/* Define to 1 if lzma1 encoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ENCODER_LZMA1
value|1
end_define

begin_comment
comment|/* Define to 1 if lzma2 encoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ENCODER_LZMA2
value|1
end_define

begin_comment
comment|/* Define to 1 if powerpc encoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ENCODER_POWERPC
value|1
end_define

begin_comment
comment|/* Define to 1 if sparc encoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ENCODER_SPARC
value|1
end_define

begin_comment
comment|/* Define to 1 if x86 encoder is enabled. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ENCODER_X86
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
comment|/* Define to 1 if you have the `futimens' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FUTIMENS 1 */
end_comment

begin_comment
comment|/* Define to 1 if you have the `futimes' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FUTIMES */
end_comment

begin_comment
comment|/* Define to 1 if you have the `futimesat' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FUTIMESAT */
end_comment

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
comment|/* Define if the GNU gettext() function is already present or preinstalled. */
end_comment

begin_comment
comment|/* FreeBSD - disabled intentionally */
end_comment

begin_comment
comment|/* #undef HAVE_GETTEXT */
end_comment

begin_comment
comment|/* Define if you have the iconv() function and it works. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ICONV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<immintrin.h> header file. */
end_comment

begin_comment
comment|/* FreeBSD - only with clang because the base gcc does not support it */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_IMMINTRIN_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Define to 1 if you have the<limits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
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
comment|/* Define to 1 if you have the<memory.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define to 1 to enable bt2 match finder. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MF_BT2
value|1
end_define

begin_comment
comment|/* Define to 1 to enable bt3 match finder. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MF_BT3
value|1
end_define

begin_comment
comment|/* Define to 1 to enable bt4 match finder. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MF_BT4
value|1
end_define

begin_comment
comment|/* Define to 1 to enable hc3 match finder. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MF_HC3
value|1
end_define

begin_comment
comment|/* Define to 1 to enable hc4 match finder. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MF_HC4
value|1
end_define

begin_comment
comment|/* Define to 1 if getopt.h declares extern int optreset. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPTRESET
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `posix_fadvise' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POSIX_FADVISE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pthread_condattr_setclock' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_CONDATTR_SETCLOCK
value|1
end_define

begin_comment
comment|/* Have PTHREAD_PRIO_INHERIT. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_PRIO_INHERIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `SHA256Init' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SHA256INIT */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `SHA256_CTX'. */
end_comment

begin_comment
comment|/* FreeBSD - disabled libmd SHA256 for now */
end_comment

begin_comment
comment|/* #undef HAVE_SHA256_CTX */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sha256.h> header file. */
end_comment

begin_comment
comment|/* FreeBSD - disabled libmd SHA256 for now */
end_comment

begin_comment
comment|/* #undef HAVE_SHA256_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `SHA256_Init' function. */
end_comment

begin_comment
comment|/* FreeBSD - disabled libmd SHA256 for now */
end_comment

begin_comment
comment|/* #undef HAVE_SHA256_INIT */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `SHA2_CTX'. */
end_comment

begin_comment
comment|/* #undef HAVE_SHA2_CTX */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sha2.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SHA2_H */
end_comment

begin_comment
comment|/* Define to 1 if optimizing for size. */
end_comment

begin_comment
comment|/* #undef HAVE_SMALL */
end_comment

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
comment|/* Define to 1 if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
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
comment|/* Define to 1 if `st_atimensec' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_ATIMENSEC */
end_comment

begin_comment
comment|/* Define to 1 if `st_atimespec.tv_nsec' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_ATIMESPEC_TV_NSEC
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_atim.st__tim.tv_nsec' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_ATIM_ST__TIM_TV_NSEC */
end_comment

begin_comment
comment|/* Define to 1 if `st_atim.tv_nsec' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_ATIM_TV_NSEC
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_uatime' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_UATIME */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/byteorder.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_BYTEORDER_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/capsicum.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_CAPSICUM_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/endian.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_ENDIAN_H
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

begin_comment
comment|/* #undef HAVE_UTIME */
end_comment

begin_comment
comment|/* Define to 1 if you have the `utimes' function. */
end_comment

begin_comment
comment|/* #undef HAVE_UTIMES */
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
comment|/* Define to 1 if you have the `wcwidth' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCWIDTH
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
comment|/* Define to 1 if you have the `_futime' function. */
end_comment

begin_comment
comment|/* #undef HAVE__FUTIME */
end_comment

begin_comment
comment|/* Define to 1 if _mm_movemask_epi8 is available. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE__MM_MOVEMASK_EPI8
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to the sub-directory where libtool stores uninstalled libraries. */
end_comment

begin_define
define|#
directive|define
name|LT_OBJDIR
value|".libs/"
end_define

begin_comment
comment|/* Define to 1 when using POSIX threads (pthreads). */
end_comment

begin_define
define|#
directive|define
name|MYTHREAD_POSIX
value|1
end_define

begin_comment
comment|/* Define to 1 when using Windows Vista compatible threads. This uses features    that are not available on Windows XP. */
end_comment

begin_comment
comment|/* #undef MYTHREAD_VISTA */
end_comment

begin_comment
comment|/* Define to 1 when using Windows 95 (and thus XP) compatible threads. This    avoids use of features that were added in Windows Vista. */
end_comment

begin_comment
comment|/* #undef MYTHREAD_WIN95 */
end_comment

begin_comment
comment|/* Define to 1 to disable debugging code. */
end_comment

begin_define
define|#
directive|define
name|NDEBUG
value|1
end_define

begin_comment
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"xz"
end_define

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|"lasse.collin@tukaani.org"
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"XZ Utils"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"XZ Utils 5.2.3"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"xz"
end_define

begin_comment
comment|/* Define to the home page for this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_URL
value|"http://tukaani.org/xz/"
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|"5.2.3"
end_define

begin_comment
comment|/* Define to necessary symbol if this constant uses a non-standard name on    your system. */
end_comment

begin_comment
comment|/* #undef PTHREAD_CREATE_JOINABLE */
end_comment

begin_comment
comment|/* The size of `size_t', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_SIZE_T
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
comment|/* Define to 1 if the number of available CPU cores can be detected with    cpuset(2). */
end_comment

begin_define
define|#
directive|define
name|TUKLIB_CPUCORES_CPUSET
value|1
end_define

begin_comment
comment|/* Define to 1 if the number of available CPU cores can be detected with    pstat_getdynamic(). */
end_comment

begin_comment
comment|/* #undef TUKLIB_CPUCORES_PSTAT_GETDYNAMIC */
end_comment

begin_comment
comment|/* Define to 1 if the number of available CPU cores can be detected with    sched_getaffinity() */
end_comment

begin_comment
comment|/* #undef TUKLIB_CPUCORES_SCHED_GETAFFINITY */
end_comment

begin_comment
comment|/* Define to 1 if the number of available CPU cores can be detected with    sysconf(_SC_NPROCESSORS_ONLN) or sysconf(_SC_NPROC_ONLN). */
end_comment

begin_comment
comment|/* #undef TUKLIB_CPUCORES_SYSCONF */
end_comment

begin_comment
comment|/* Define to 1 if the number of available CPU cores can be detected with    sysctl(). */
end_comment

begin_comment
comment|/* #undef TUKLIB_CPUCORES_SYSCTL */
end_comment

begin_comment
comment|/* Define to 1 if the system supports fast unaligned access to 16-bit and    32-bit integers. */
end_comment

begin_comment
comment|/* FreeBSD - derive from __NO_STRICT_ALIGNMENT */
end_comment

begin_comment
comment|/* #undef TUKLIB_FAST_UNALIGNED_ACCESS */
end_comment

begin_comment
comment|/* Define to 1 if the amount of physical memory can be detected with    _system_configuration.physmem. */
end_comment

begin_comment
comment|/* #undef TUKLIB_PHYSMEM_AIX */
end_comment

begin_comment
comment|/* Define to 1 if the amount of physical memory can be detected with    getinvent_r(). */
end_comment

begin_comment
comment|/* #undef TUKLIB_PHYSMEM_GETINVENT_R */
end_comment

begin_comment
comment|/* Define to 1 if the amount of physical memory can be detected with    getsysinfo(). */
end_comment

begin_comment
comment|/* #undef TUKLIB_PHYSMEM_GETSYSINFO */
end_comment

begin_comment
comment|/* Define to 1 if the amount of physical memory can be detected with    pstat_getstatic(). */
end_comment

begin_comment
comment|/* #undef TUKLIB_PHYSMEM_PSTAT_GETSTATIC */
end_comment

begin_comment
comment|/* Define to 1 if the amount of physical memory can be detected with    sysconf(_SC_PAGESIZE) and sysconf(_SC_PHYS_PAGES). */
end_comment

begin_define
define|#
directive|define
name|TUKLIB_PHYSMEM_SYSCONF
value|1
end_define

begin_comment
comment|/* Define to 1 if the amount of physical memory can be detected with sysctl().    */
end_comment

begin_comment
comment|/* #undef TUKLIB_PHYSMEM_SYSCTL */
end_comment

begin_comment
comment|/* Define to 1 if the amount of physical memory can be detected with Linux    sysinfo(). */
end_comment

begin_comment
comment|/* #undef TUKLIB_PHYSMEM_SYSINFO */
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
value|"5.2.3"
end_define

begin_comment
comment|/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most    significant byte first (like Motorola and SPARC, unlike Intel). */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NO_STRICT_ALIGNMENT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TUKLIB_FAST_UNALIGNED_ACCESS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
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
comment|/* Define to rpl_ if the getopt replacement functions and variables should be    used. */
end_comment

begin_comment
comment|/* #undef __GETOPT_PREFIX */
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

end_unit

