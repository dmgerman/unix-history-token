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
name|defined
argument_list|(
name|__aarch64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips64
argument_list|)
end_if

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
comment|// FIXME: this value should be different on different platforms,
end_comment

begin_comment
comment|// e.g. on AArch64 it is most likely (1ULL<< 39). Larger values will still work
end_comment

begin_comment
comment|// but will consume more memory for TwoLevelByteMap.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_MMAP_RANGE_SIZE
value|FIRST_32_SECOND_64(1ULL<< 32, 1ULL<< 39)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SANITIZER_MMAP_RANGE_SIZE
value|FIRST_32_SECOND_64(1ULL<< 32, 1ULL<< 40)
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

begin_ifdef
ifdef|#
directive|ifdef
name|__mips__
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_PLATFORM_H
end_comment

end_unit

