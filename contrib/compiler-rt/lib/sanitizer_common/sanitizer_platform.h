begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_platform.h ------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Common platform macros.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_PLATFORM_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_PLATFORM_H
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"This operating system is not supported"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_LINUX
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_LINUX
value|0
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

begin_define
define|#
directive|define
name|SANITIZER_FREEBSD
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_FREEBSD
value|0
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
name|__APPLE__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_MAC
value|1
end_define

begin_include
include|#
directive|include
file|<TargetConditionals.h>
end_include

begin_if
if|#
directive|if
name|TARGET_OS_IPHONE
end_if

begin_define
define|#
directive|define
name|SANITIZER_IOS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_IOS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_IPHONE_SIMULATOR
end_if

begin_define
define|#
directive|define
name|SANITIZER_IOSSIM
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_IOSSIM
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_MAC
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_IOS
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_IOSSIM
value|0
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
name|__APPLE__
argument_list|)
operator|&&
name|TARGET_OS_IPHONE
operator|&&
name|TARGET_OS_WATCH
end_if

begin_define
define|#
directive|define
name|SANITIZER_WATCHOS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_WATCHOS
value|0
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
name|__APPLE__
argument_list|)
operator|&&
name|TARGET_OS_IPHONE
operator|&&
name|TARGET_OS_TV
end_if

begin_define
define|#
directive|define
name|SANITIZER_TVOS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_TVOS
value|0
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
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_WINDOWS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_WINDOWS
value|0
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
name|_WIN64
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_WINDOWS64
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_WINDOWS64
value|0
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
name|__ANDROID__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_ANDROID
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_ANDROID
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SANITIZER_POSIX
value|(SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_MAC)
end_define

begin_if
if|#
directive|if
name|__LP64__
operator|||
name|defined
argument_list|(
name|_WIN64
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_WORDSIZE
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_WORDSIZE
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SANITIZER_WORDSIZE
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|FIRST_32_SECOND_64
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(b)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FIRST_32_SECOND_64
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a)
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
name|__x86_64__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_LP64
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_X32
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_X32
value|0
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
name|__mips__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_MIPS
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips64
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_MIPS32
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_MIPS64
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_MIPS32
value|1
end_define

begin_define
define|#
directive|define
name|SANITIZER_MIPS64
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_MIPS
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_MIPS32
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_MIPS64
value|0
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
name|__s390__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_S390
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__s390x__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_S390_31
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_S390_64
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_S390_31
value|1
end_define

begin_define
define|#
directive|define
name|SANITIZER_S390_64
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_S390
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_S390_31
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_S390_64
value|0
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
name|__powerpc__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_PPC
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_PPC32
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_PPC64
value|1
end_define

begin_comment
comment|// 64-bit PPC has two ABIs (v1 and v2).  The old powerpc64 target is
end_comment

begin_comment
comment|// big-endian, and uses v1 ABI (known for its function descriptors),
end_comment

begin_comment
comment|// while the new powerpc64le target is little-endian and uses v2.
end_comment

begin_comment
comment|// In theory, you could convince gcc to compile for their evil twins
end_comment

begin_comment
comment|// (eg. big-endian v2), but you won't find such combinations in the wild
end_comment

begin_comment
comment|// (it'd require bootstrapping a whole system, which would be quite painful
end_comment

begin_comment
comment|// - there's no target triple for that).  LLVM doesn't support them either.
end_comment

begin_if
if|#
directive|if
name|_CALL_ELF
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|SANITIZER_PPC64V1
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_PPC64V2
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_PPC64V1
value|1
end_define

begin_define
define|#
directive|define
name|SANITIZER_PPC64V2
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_PPC32
value|1
end_define

begin_define
define|#
directive|define
name|SANITIZER_PPC64
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_PPC64V1
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_PPC64V2
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_PPC
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_PPC32
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_PPC64
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_PPC64V1
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_PPC64V2
value|0
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
name|__arm__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_ARM
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_ARM
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// By default we allow to use SizeClassAllocator64 on 64-bit platform.
end_comment

begin_comment
comment|// But in some cases (e.g. AArch64's 39-bit address space) SizeClassAllocator64
end_comment

begin_comment
comment|// does not work well and we need to fallback to SizeClassAllocator32.
end_comment

begin_comment
comment|// For such platforms build this code with -DSANITIZER_CAN_USE_ALLOCATOR64=0 or
end_comment

begin_comment
comment|// change the definition of SANITIZER_CAN_USE_ALLOCATOR64 here.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_CAN_USE_ALLOCATOR64
end_ifndef

begin_if
if|#
directive|if
name|SANITIZER_ANDROID
operator|&&
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_CAN_USE_ALLOCATOR64
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips64
argument_list|)
operator|||
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SANITIZER_CAN_USE_ALLOCATOR64
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_CAN_USE_ALLOCATOR64
value|(SANITIZER_WORDSIZE == 64)
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
comment|// The range of addresses which can be returned my mmap.
end_comment

begin_comment
comment|// FIXME: this value should be different on different platforms.  Larger values
end_comment

begin_comment
comment|// will still work but will consume more memory for TwoLevelByteMap.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_MMAP_RANGE_SIZE
value|FIRST_32_SECOND_64(1ULL<< 32, 1ULL<< 40)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SANITIZER_MMAP_RANGE_SIZE
value|FIRST_32_SECOND_64(1ULL<< 32, 1ULL<< 48)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_MMAP_RANGE_SIZE
value|FIRST_32_SECOND_64(1ULL<< 32, 1ULL<< 47)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// The AArch64 linux port uses the canonical syscall set as mandated by
end_comment

begin_comment
comment|// the upstream linux community for all new ports. Other ports may still
end_comment

begin_comment
comment|// use legacy syscalls.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__aarch64__
argument_list|)
operator|&&
name|SANITIZER_LINUX
end_if

begin_define
define|#
directive|define
name|SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
value|0
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
comment|// udi16 syscalls can only be used when the following conditions are
end_comment

begin_comment
comment|// met:
end_comment

begin_comment
comment|// * target is one of arm32, x86-32, sparc32, sh or m68k
end_comment

begin_comment
comment|// * libc version is libc5, glibc-2.0, glibc-2.1 or glibc-2.2 to 2.15
end_comment

begin_comment
comment|//   built against> linux-2.2 kernel headers
end_comment

begin_comment
comment|// Since we don't want to include libc headers here, we check the
end_comment

begin_comment
comment|// target only.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
name|SANITIZER_X32
operator|||
name|defined
argument_list|(
name|__sparc__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_USES_UID16_SYSCALLS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_USES_UID16_SYSCALLS
value|0
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
name|__mips__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_POINTER_FORMAT_LENGTH
value|FIRST_32_SECOND_64(8, 10)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_POINTER_FORMAT_LENGTH
value|FIRST_32_SECOND_64(8, 12)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Assume obsolete RPC headers are available by default
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_RPC_XDR_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_TIRPC_RPC_XDR_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_RPC_XDR_H
value|(SANITIZER_LINUX&& !SANITIZER_ANDROID)
end_define

begin_define
define|#
directive|define
name|HAVE_TIRPC_RPC_XDR_H
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \macro MSC_PREREQ
end_comment

begin_comment
comment|/// \brief Is the compiler MSVC of at least the specified version?
end_comment

begin_comment
comment|/// The common \param version values to check for are:
end_comment

begin_comment
comment|///  * 1800: Microsoft Visual Studio 2013 / 12.0
end_comment

begin_comment
comment|///  * 1900: Microsoft Visual Studio 2015 / 14.0
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|MSC_PREREQ
parameter_list|(
name|version
parameter_list|)
value|(_MSC_VER>= (version))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MSC_PREREQ
parameter_list|(
name|version
parameter_list|)
value|0
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
name|__arm64__
argument_list|)
operator|&&
name|SANITIZER_IOS
end_if

begin_define
define|#
directive|define
name|SANITIZER_NON_UNIQUE_TYPEINFO
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_NON_UNIQUE_TYPEINFO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// On linux, some architectures had an ABI transition from 64-bit long double
end_comment

begin_comment
comment|// (ie. same as double) to 128-bit long double.  On those, glibc symbols
end_comment

begin_comment
comment|// involving long doubles come in two versions, and we need to pass the
end_comment

begin_comment
comment|// correct one to dlvsym when intercepting them.
end_comment

begin_if
if|#
directive|if
name|SANITIZER_LINUX
operator|&&
operator|(
name|SANITIZER_S390
operator|||
name|SANITIZER_PPC32
operator|||
name|SANITIZER_PPC64V1
operator|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_NLDBL_VERSION
value|"GLIBC_2.4"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SANITIZER_GO
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|SANITIZER_GO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// On PowerPC and ARM Thumb, calling pthread_exit() causes LSan to detect leaks.
end_comment

begin_comment
comment|// pthread_exit() performs unwinding that leads to dlopen'ing libgcc_s.so.
end_comment

begin_comment
comment|// dlopen mallocs "libgcc_s.so" string which confuses LSan, it fails to realize
end_comment

begin_comment
comment|// that this allocation happens in dynamic linker and should be ignored.
end_comment

begin_if
if|#
directive|if
name|SANITIZER_PPC
operator|||
name|defined
argument_list|(
name|__thumb__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_SUPPRESS_LEAK_ON_PTHREAD_EXIT
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_SUPPRESS_LEAK_ON_PTHREAD_EXIT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__GLIBC_PREREQ
end_ifndef

begin_define
define|#
directive|define
name|__GLIBC_PREREQ
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SANITIZER_LINUX
operator|&&
name|__GLIBC_PREREQ
argument_list|(
literal|2
operator|,
literal|16
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_USE_GETAUXVAL
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_USE_GETAUXVAL
value|0
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
comment|// SANITIZER_PLATFORM_H
end_comment

end_unit

