begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_define
define|#
directive|define
name|ASSUME_RAM
value|128
end_define

begin_define
define|#
directive|define
name|HAVE_CHECK_CRC32
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_CHECK_CRC64
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_CHECK_SHA256
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_CLOCK_GETTIME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_CLOCK_MONOTONIC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_PROGRAM_INVOCATION_NAME
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_DECODER_ARM
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECODER_ARMTHUMB
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECODER_DELTA
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECODER_IA64
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECODER_LZMA1
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECODER_LZMA2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECODER_POWERPC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECODER_SPARC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECODER_X86
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DLFCN_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ENCODER_ARM
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ENCODER_ARMTHUMB
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ENCODER_DELTA
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ENCODER_IA64
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ENCODER_LZMA1
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ENCODER_LZMA2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ENCODER_POWERPC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ENCODER_SPARC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ENCODER_X86
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FUTIMES
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETOPT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETOPT_LONG
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MBRTOWC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MF_BT2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MF_BT3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MF_BT4
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MF_HC3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MF_HC4
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_OPTRESET
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_POSIX_FADVISE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PTHREAD_CONDATTR_SETCLOCK
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PTHREAD_PRIO_INHERIT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDBOOL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_ATIMESPEC_TV_NSEC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_ATIM_TV_NSEC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_ENDIAN_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UINTPTR_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VISIBILITY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WCWIDTH
value|1
end_define

begin_define
define|#
directive|define
name|HAVE__BOOL
value|1
end_define

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

begin_define
define|#
directive|define
name|MYTHREAD_POSIX
value|1
end_define

begin_define
define|#
directive|define
name|NDEBUG
value|1
end_define

begin_define
define|#
directive|define
name|PACKAGE
value|"xz"
end_define

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|"lasse.collin@tukaani.org"
end_define

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"XZ Utils"
end_define

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"XZ Utils 5.2.0"
end_define

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"xz"
end_define

begin_define
define|#
directive|define
name|PACKAGE_URL
value|"http://tukaani.org/xz/"
end_define

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|"5.2.0"
end_define

begin_define
define|#
directive|define
name|SIZEOF_SIZE_T
value|8
end_define

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_define
define|#
directive|define
name|TUKLIB_CPUCORES_SYSCTL
value|1
end_define

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

begin_define
define|#
directive|define
name|TUKLIB_PHYSMEM_SYSCONF
value|1
end_define

begin_define
define|#
directive|define
name|VERSION
value|"5.2.0"
end_define

end_unit

