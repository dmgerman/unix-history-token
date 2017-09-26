begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_mapping.h ------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of AddressSanitizer, an address sanity checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Defines ASan memory mapping.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_MAPPING_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_MAPPING_H
end_define

begin_include
include|#
directive|include
file|"asan_internal.h"
end_include

begin_comment
comment|// The full explanation of the memory mapping could be found here:
end_comment

begin_comment
comment|// https://github.com/google/sanitizers/wiki/AddressSanitizerAlgorithm
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Typical shadow mapping on Linux/x86_64 with SHADOW_OFFSET == 0x00007fff8000:
end_comment

begin_comment
comment|// || `[0x10007fff8000, 0x7fffffffffff]` || HighMem    ||
end_comment

begin_comment
comment|// || `[0x02008fff7000, 0x10007fff7fff]` || HighShadow ||
end_comment

begin_comment
comment|// || `[0x00008fff7000, 0x02008fff6fff]` || ShadowGap  ||
end_comment

begin_comment
comment|// || `[0x00007fff8000, 0x00008fff6fff]` || LowShadow  ||
end_comment

begin_comment
comment|// || `[0x000000000000, 0x00007fff7fff]` || LowMem     ||
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// When SHADOW_OFFSET is zero (-pie):
end_comment

begin_comment
comment|// || `[0x100000000000, 0x7fffffffffff]` || HighMem    ||
end_comment

begin_comment
comment|// || `[0x020000000000, 0x0fffffffffff]` || HighShadow ||
end_comment

begin_comment
comment|// || `[0x000000040000, 0x01ffffffffff]` || ShadowGap  ||
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Special case when something is already mapped between
end_comment

begin_comment
comment|// 0x003000000000 and 0x005000000000 (e.g. when prelink is installed):
end_comment

begin_comment
comment|// || `[0x10007fff8000, 0x7fffffffffff]` || HighMem    ||
end_comment

begin_comment
comment|// || `[0x02008fff7000, 0x10007fff7fff]` || HighShadow ||
end_comment

begin_comment
comment|// || `[0x005000000000, 0x02008fff6fff]` || ShadowGap3 ||
end_comment

begin_comment
comment|// || `[0x003000000000, 0x004fffffffff]` || MidMem     ||
end_comment

begin_comment
comment|// || `[0x000a7fff8000, 0x002fffffffff]` || ShadowGap2 ||
end_comment

begin_comment
comment|// || `[0x00067fff8000, 0x000a7fff7fff]` || MidShadow  ||
end_comment

begin_comment
comment|// || `[0x00008fff7000, 0x00067fff7fff]` || ShadowGap  ||
end_comment

begin_comment
comment|// || `[0x00007fff8000, 0x00008fff6fff]` || LowShadow  ||
end_comment

begin_comment
comment|// || `[0x000000000000, 0x00007fff7fff]` || LowMem     ||
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Default Linux/i386 mapping on x86_64 machine:
end_comment

begin_comment
comment|// || `[0x40000000, 0xffffffff]` || HighMem    ||
end_comment

begin_comment
comment|// || `[0x28000000, 0x3fffffff]` || HighShadow ||
end_comment

begin_comment
comment|// || `[0x24000000, 0x27ffffff]` || ShadowGap  ||
end_comment

begin_comment
comment|// || `[0x20000000, 0x23ffffff]` || LowShadow  ||
end_comment

begin_comment
comment|// || `[0x00000000, 0x1fffffff]` || LowMem     ||
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Default Linux/i386 mapping on i386 machine
end_comment

begin_comment
comment|// (addresses starting with 0xc0000000 are reserved
end_comment

begin_comment
comment|// for kernel and thus not sanitized):
end_comment

begin_comment
comment|// || `[0x38000000, 0xbfffffff]` || HighMem    ||
end_comment

begin_comment
comment|// || `[0x27000000, 0x37ffffff]` || HighShadow ||
end_comment

begin_comment
comment|// || `[0x24000000, 0x26ffffff]` || ShadowGap  ||
end_comment

begin_comment
comment|// || `[0x20000000, 0x23ffffff]` || LowShadow  ||
end_comment

begin_comment
comment|// || `[0x00000000, 0x1fffffff]` || LowMem     ||
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Default Linux/MIPS32 mapping:
end_comment

begin_comment
comment|// || `[0x2aaa0000, 0xffffffff]` || HighMem    ||
end_comment

begin_comment
comment|// || `[0x0fff4000, 0x2aa9ffff]` || HighShadow ||
end_comment

begin_comment
comment|// || `[0x0bff4000, 0x0fff3fff]` || ShadowGap  ||
end_comment

begin_comment
comment|// || `[0x0aaa0000, 0x0bff3fff]` || LowShadow  ||
end_comment

begin_comment
comment|// || `[0x00000000, 0x0aa9ffff]` || LowMem     ||
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Default Linux/MIPS64 mapping:
end_comment

begin_comment
comment|// || `[0x4000000000, 0xffffffffff]` || HighMem    ||
end_comment

begin_comment
comment|// || `[0x2800000000, 0x3fffffffff]` || HighShadow ||
end_comment

begin_comment
comment|// || `[0x2400000000, 0x27ffffffff]` || ShadowGap  ||
end_comment

begin_comment
comment|// || `[0x2000000000, 0x23ffffffff]` || LowShadow  ||
end_comment

begin_comment
comment|// || `[0x0000000000, 0x1fffffffff]` || LowMem     ||
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Default Linux/AArch64 (39-bit VMA) mapping:
end_comment

begin_comment
comment|// || `[0x2000000000, 0x7fffffffff]` || highmem    ||
end_comment

begin_comment
comment|// || `[0x1400000000, 0x1fffffffff]` || highshadow ||
end_comment

begin_comment
comment|// || `[0x1200000000, 0x13ffffffff]` || shadowgap  ||
end_comment

begin_comment
comment|// || `[0x1000000000, 0x11ffffffff]` || lowshadow  ||
end_comment

begin_comment
comment|// || `[0x0000000000, 0x0fffffffff]` || lowmem     ||
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Default Linux/AArch64 (42-bit VMA) mapping:
end_comment

begin_comment
comment|// || `[0x10000000000, 0x3ffffffffff]` || highmem    ||
end_comment

begin_comment
comment|// || `[0x0a000000000, 0x0ffffffffff]` || highshadow ||
end_comment

begin_comment
comment|// || `[0x09000000000, 0x09fffffffff]` || shadowgap  ||
end_comment

begin_comment
comment|// || `[0x08000000000, 0x08fffffffff]` || lowshadow  ||
end_comment

begin_comment
comment|// || `[0x00000000000, 0x07fffffffff]` || lowmem     ||
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Default Linux/S390 mapping:
end_comment

begin_comment
comment|// || `[0x30000000, 0x7fffffff]` || HighMem    ||
end_comment

begin_comment
comment|// || `[0x26000000, 0x2fffffff]` || HighShadow ||
end_comment

begin_comment
comment|// || `[0x24000000, 0x25ffffff]` || ShadowGap  ||
end_comment

begin_comment
comment|// || `[0x20000000, 0x23ffffff]` || LowShadow  ||
end_comment

begin_comment
comment|// || `[0x00000000, 0x1fffffff]` || LowMem     ||
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Default Linux/SystemZ mapping:
end_comment

begin_comment
comment|// || `[0x14000000000000, 0x1fffffffffffff]` || HighMem    ||
end_comment

begin_comment
comment|// || `[0x12800000000000, 0x13ffffffffffff]` || HighShadow ||
end_comment

begin_comment
comment|// || `[0x12000000000000, 0x127fffffffffff]` || ShadowGap  ||
end_comment

begin_comment
comment|// || `[0x10000000000000, 0x11ffffffffffff]` || LowShadow  ||
end_comment

begin_comment
comment|// || `[0x00000000000000, 0x0fffffffffffff]` || LowMem     ||
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Shadow mapping on FreeBSD/x86-64 with SHADOW_OFFSET == 0x400000000000:
end_comment

begin_comment
comment|// || `[0x500000000000, 0x7fffffffffff]` || HighMem    ||
end_comment

begin_comment
comment|// || `[0x4a0000000000, 0x4fffffffffff]` || HighShadow ||
end_comment

begin_comment
comment|// || `[0x480000000000, 0x49ffffffffff]` || ShadowGap  ||
end_comment

begin_comment
comment|// || `[0x400000000000, 0x47ffffffffff]` || LowShadow  ||
end_comment

begin_comment
comment|// || `[0x000000000000, 0x3fffffffffff]` || LowMem     ||
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Shadow mapping on FreeBSD/i386 with SHADOW_OFFSET == 0x40000000:
end_comment

begin_comment
comment|// || `[0x60000000, 0xffffffff]` || HighMem    ||
end_comment

begin_comment
comment|// || `[0x4c000000, 0x5fffffff]` || HighShadow ||
end_comment

begin_comment
comment|// || `[0x48000000, 0x4bffffff]` || ShadowGap  ||
end_comment

begin_comment
comment|// || `[0x40000000, 0x47ffffff]` || LowShadow  ||
end_comment

begin_comment
comment|// || `[0x00000000, 0x3fffffff]` || LowMem     ||
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Default Windows/i386 mapping:
end_comment

begin_comment
comment|// (the exact location of HighShadow/HighMem may vary depending
end_comment

begin_comment
comment|//  on WoW64, /LARGEADDRESSAWARE, etc).
end_comment

begin_comment
comment|// || `[0x50000000, 0xffffffff]` || HighMem    ||
end_comment

begin_comment
comment|// || `[0x3a000000, 0x4fffffff]` || HighShadow ||
end_comment

begin_comment
comment|// || `[0x36000000, 0x39ffffff]` || ShadowGap  ||
end_comment

begin_comment
comment|// || `[0x30000000, 0x35ffffff]` || LowShadow  ||
end_comment

begin_comment
comment|// || `[0x00000000, 0x2fffffff]` || LowMem     ||
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kDefaultShadowScale
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kDefaultShadowSentinel
init|=
operator|~
operator|(
name|uptr
operator|)
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kDefaultShadowOffset32
init|=
literal|1ULL
operator|<<
literal|29
decl_stmt|;
end_decl_stmt

begin_comment
comment|// 0x20000000
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kDefaultShadowOffset64
init|=
literal|1ULL
operator|<<
literal|44
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kDefaultShort64bitShadowOffset
init|=
literal|0x7FFF8000
decl_stmt|;
end_decl_stmt

begin_comment
comment|//< 2G.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kIosShadowOffset32
init|=
literal|1ULL
operator|<<
literal|30
decl_stmt|;
end_decl_stmt

begin_comment
comment|// 0x40000000
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kIosShadowOffset64
init|=
literal|0x120200000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kIosSimShadowOffset32
init|=
literal|1ULL
operator|<<
literal|30
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kIosSimShadowOffset64
init|=
name|kDefaultShadowOffset64
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kAArch64_ShadowOffset64
init|=
literal|1ULL
operator|<<
literal|36
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kMIPS32_ShadowOffset32
init|=
literal|0x0aaa0000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kMIPS64_ShadowOffset64
init|=
literal|1ULL
operator|<<
literal|37
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kPPC64_ShadowOffset64
init|=
literal|1ULL
operator|<<
literal|41
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kSystemZ_ShadowOffset64
init|=
literal|1ULL
operator|<<
literal|52
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kFreeBSD_ShadowOffset32
init|=
literal|1ULL
operator|<<
literal|30
decl_stmt|;
end_decl_stmt

begin_comment
comment|// 0x40000000
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kFreeBSD_ShadowOffset64
init|=
literal|1ULL
operator|<<
literal|46
decl_stmt|;
end_decl_stmt

begin_comment
comment|// 0x400000000000
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u64
name|kWindowsShadowOffset32
init|=
literal|3ULL
operator|<<
literal|28
decl_stmt|;
end_decl_stmt

begin_comment
comment|// 0x30000000
end_comment

begin_define
define|#
directive|define
name|SHADOW_SCALE
value|kDefaultShadowScale
end_define

begin_if
if|#
directive|if
name|SANITIZER_WORDSIZE
operator|==
literal|32
end_if

begin_if
if|#
directive|if
name|SANITIZER_ANDROID
end_if

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|(0)
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
name|SHADOW_OFFSET
value|kMIPS32_ShadowOffset32
end_define

begin_elif
elif|#
directive|elif
name|SANITIZER_FREEBSD
end_elif

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|kFreeBSD_ShadowOffset32
end_define

begin_elif
elif|#
directive|elif
name|SANITIZER_WINDOWS
end_elif

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|kWindowsShadowOffset32
end_define

begin_elif
elif|#
directive|elif
name|SANITIZER_IOS
end_elif

begin_if
if|#
directive|if
name|SANITIZER_IOSSIM
end_if

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|kIosSimShadowOffset32
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|kIosShadowOffset32
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
name|SHADOW_OFFSET
value|kDefaultShadowOffset32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|SANITIZER_IOS
end_if

begin_if
if|#
directive|if
name|SANITIZER_IOSSIM
end_if

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|kIosSimShadowOffset64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|__asan_shadow_memory_dynamic_address
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|SHADOW_OFFSET
value|kAArch64_ShadowOffset64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|kPPC64_ShadowOffset64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__s390x__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|kSystemZ_ShadowOffset64
end_define

begin_elif
elif|#
directive|elif
name|SANITIZER_FREEBSD
end_elif

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|kFreeBSD_ShadowOffset64
end_define

begin_elif
elif|#
directive|elif
name|SANITIZER_MAC
end_elif

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|kDefaultShadowOffset64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips64
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|kMIPS64_ShadowOffset64
end_define

begin_elif
elif|#
directive|elif
name|SANITIZER_WINDOWS64
end_elif

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|__asan_shadow_memory_dynamic_address
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|kDefaultShort64bitShadowOffset
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
name|SHADOW_GRANULARITY
value|(1ULL<< SHADOW_SCALE)
end_define

begin_define
define|#
directive|define
name|MEM_TO_SHADOW
parameter_list|(
name|mem
parameter_list|)
value|(((mem)>> SHADOW_SCALE) + (SHADOW_OFFSET))
end_define

begin_define
define|#
directive|define
name|kLowMemBeg
value|0
end_define

begin_define
define|#
directive|define
name|kLowMemEnd
value|(SHADOW_OFFSET ? SHADOW_OFFSET - 1 : 0)
end_define

begin_define
define|#
directive|define
name|kLowShadowBeg
value|SHADOW_OFFSET
end_define

begin_define
define|#
directive|define
name|kLowShadowEnd
value|MEM_TO_SHADOW(kLowMemEnd)
end_define

begin_define
define|#
directive|define
name|kHighMemBeg
value|(MEM_TO_SHADOW(kHighMemEnd) + 1)
end_define

begin_define
define|#
directive|define
name|kHighShadowBeg
value|MEM_TO_SHADOW(kHighMemBeg)
end_define

begin_define
define|#
directive|define
name|kHighShadowEnd
value|MEM_TO_SHADOW(kHighMemEnd)
end_define

begin_define
define|#
directive|define
name|kMidShadowBeg
value|MEM_TO_SHADOW(kMidMemBeg)
end_define

begin_define
define|#
directive|define
name|kMidShadowEnd
value|MEM_TO_SHADOW(kMidMemEnd)
end_define

begin_comment
comment|// With the zero shadow base we can not actually map pages starting from 0.
end_comment

begin_comment
comment|// This constant is somewhat arbitrary.
end_comment

begin_define
define|#
directive|define
name|kZeroBaseShadowStart
value|0
end_define

begin_define
define|#
directive|define
name|kZeroBaseMaxShadowStart
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|kShadowGapBeg
value|(kLowShadowEnd ? kLowShadowEnd + 1 \                                        : kZeroBaseShadowStart)
end_define

begin_define
define|#
directive|define
name|kShadowGapEnd
value|((kMidMemBeg ? kMidShadowBeg : kHighShadowBeg) - 1)
end_define

begin_define
define|#
directive|define
name|kShadowGap2Beg
value|(kMidMemBeg ? kMidShadowEnd + 1 : 0)
end_define

begin_define
define|#
directive|define
name|kShadowGap2End
value|(kMidMemBeg ? kMidMemBeg - 1 : 0)
end_define

begin_define
define|#
directive|define
name|kShadowGap3Beg
value|(kMidMemBeg ? kMidMemEnd + 1 : 0)
end_define

begin_define
define|#
directive|define
name|kShadowGap3End
value|(kMidMemBeg ? kHighShadowBeg - 1 : 0)
end_define

begin_define
define|#
directive|define
name|DO_ASAN_MAPPING_PROFILE
value|0
end_define

begin_comment
comment|// Set to 1 to profile the functions below.
end_comment

begin_if
if|#
directive|if
name|DO_ASAN_MAPPING_PROFILE
end_if

begin_define
define|#
directive|define
name|PROFILE_ASAN_MAPPING
parameter_list|()
value|AsanMappingProfile[__LINE__]++;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROFILE_ASAN_MAPPING
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// If 1, all shadow boundaries are constants.
end_comment

begin_comment
comment|// Don't set to 1 other than for testing.
end_comment

begin_define
define|#
directive|define
name|ASAN_FIXED_MAPPING
value|0
end_define

begin_decl_stmt
name|namespace
name|__asan
block|{
specifier|extern
name|uptr
name|AsanMappingProfile
index|[]
decl_stmt|;
if|#
directive|if
name|ASAN_FIXED_MAPPING
comment|// Fixed mapping for 64-bit Linux. Mostly used for performance comparison
comment|// with non-fixed mapping. As of r175253 (Feb 2013) the performance
comment|// difference between fixed and non-fixed mapping is below the noise level.
specifier|static
name|uptr
name|kHighMemEnd
init|=
literal|0x7fffffffffffULL
decl_stmt|;
specifier|static
name|uptr
name|kMidMemBeg
init|=
literal|0x3000000000ULL
decl_stmt|;
specifier|static
name|uptr
name|kMidMemEnd
init|=
literal|0x4fffffffffULL
decl_stmt|;
else|#
directive|else
specifier|extern
name|uptr
name|kHighMemEnd
decl_stmt|,
name|kMidMemBeg
decl_stmt|,
name|kMidMemEnd
decl_stmt|;
comment|// Initialized in __asan_init.
endif|#
directive|endif
specifier|static
specifier|inline
name|bool
name|AddrIsInLowMem
parameter_list|(
name|uptr
name|a
parameter_list|)
block|{
name|PROFILE_ASAN_MAPPING
argument_list|()
expr_stmt|;
return|return
name|a
operator|<
name|kLowMemEnd
return|;
block|}
specifier|static
specifier|inline
name|bool
name|AddrIsInLowShadow
parameter_list|(
name|uptr
name|a
parameter_list|)
block|{
name|PROFILE_ASAN_MAPPING
argument_list|()
expr_stmt|;
return|return
name|a
operator|>=
name|kLowShadowBeg
operator|&&
name|a
operator|<=
name|kLowShadowEnd
return|;
block|}
specifier|static
specifier|inline
name|bool
name|AddrIsInHighMem
parameter_list|(
name|uptr
name|a
parameter_list|)
block|{
name|PROFILE_ASAN_MAPPING
argument_list|()
expr_stmt|;
return|return
name|a
operator|>=
name|kHighMemBeg
operator|&&
name|a
operator|<=
name|kHighMemEnd
return|;
block|}
specifier|static
specifier|inline
name|bool
name|AddrIsInMidMem
parameter_list|(
name|uptr
name|a
parameter_list|)
block|{
name|PROFILE_ASAN_MAPPING
argument_list|()
expr_stmt|;
return|return
name|kMidMemBeg
operator|&&
name|a
operator|>=
name|kMidMemBeg
operator|&&
name|a
operator|<=
name|kMidMemEnd
return|;
block|}
specifier|static
specifier|inline
name|bool
name|AddrIsInShadowGap
parameter_list|(
name|uptr
name|a
parameter_list|)
block|{
name|PROFILE_ASAN_MAPPING
argument_list|()
expr_stmt|;
if|if
condition|(
name|kMidMemBeg
condition|)
block|{
if|if
condition|(
name|a
operator|<=
name|kShadowGapEnd
condition|)
return|return
name|SHADOW_OFFSET
operator|==
literal|0
operator|||
name|a
operator|>=
name|kShadowGapBeg
return|;
return|return
operator|(
name|a
operator|>=
name|kShadowGap2Beg
operator|&&
name|a
operator|<=
name|kShadowGap2End
operator|)
operator|||
operator|(
name|a
operator|>=
name|kShadowGap3Beg
operator|&&
name|a
operator|<=
name|kShadowGap3End
operator|)
return|;
block|}
comment|// In zero-based shadow mode we treat addresses near zero as addresses
comment|// in shadow gap as well.
if|if
condition|(
name|SHADOW_OFFSET
operator|==
literal|0
condition|)
return|return
name|a
operator|<=
name|kShadowGapEnd
return|;
return|return
name|a
operator|>=
name|kShadowGapBeg
operator|&&
name|a
operator|<=
name|kShadowGapEnd
return|;
block|}
specifier|static
specifier|inline
name|bool
name|AddrIsInMem
parameter_list|(
name|uptr
name|a
parameter_list|)
block|{
name|PROFILE_ASAN_MAPPING
argument_list|()
expr_stmt|;
return|return
name|AddrIsInLowMem
argument_list|(
name|a
argument_list|)
operator|||
name|AddrIsInMidMem
argument_list|(
name|a
argument_list|)
operator|||
name|AddrIsInHighMem
argument_list|(
name|a
argument_list|)
operator|||
operator|(
name|flags
argument_list|()
operator|->
name|protect_shadow_gap
operator|==
literal|0
operator|&&
name|AddrIsInShadowGap
argument_list|(
name|a
argument_list|)
operator|)
return|;
block|}
specifier|static
specifier|inline
name|uptr
name|MemToShadow
parameter_list|(
name|uptr
name|p
parameter_list|)
block|{
name|PROFILE_ASAN_MAPPING
argument_list|()
expr_stmt|;
name|CHECK
argument_list|(
name|AddrIsInMem
argument_list|(
name|p
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|MEM_TO_SHADOW
argument_list|(
name|p
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|AddrIsInHighShadow
parameter_list|(
name|uptr
name|a
parameter_list|)
block|{
name|PROFILE_ASAN_MAPPING
argument_list|()
expr_stmt|;
return|return
name|a
operator|>=
name|kHighShadowBeg
operator|&&
name|a
operator|<=
name|kHighMemEnd
return|;
block|}
specifier|static
specifier|inline
name|bool
name|AddrIsInMidShadow
parameter_list|(
name|uptr
name|a
parameter_list|)
block|{
name|PROFILE_ASAN_MAPPING
argument_list|()
expr_stmt|;
return|return
name|kMidMemBeg
operator|&&
name|a
operator|>=
name|kMidShadowBeg
operator|&&
name|a
operator|<=
name|kMidMemEnd
return|;
block|}
specifier|static
specifier|inline
name|bool
name|AddrIsInShadow
parameter_list|(
name|uptr
name|a
parameter_list|)
block|{
name|PROFILE_ASAN_MAPPING
argument_list|()
expr_stmt|;
return|return
name|AddrIsInLowShadow
argument_list|(
name|a
argument_list|)
operator|||
name|AddrIsInMidShadow
argument_list|(
name|a
argument_list|)
operator|||
name|AddrIsInHighShadow
argument_list|(
name|a
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|AddrIsAlignedByGranularity
parameter_list|(
name|uptr
name|a
parameter_list|)
block|{
name|PROFILE_ASAN_MAPPING
argument_list|()
expr_stmt|;
return|return
operator|(
name|a
operator|&
operator|(
name|SHADOW_GRANULARITY
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
return|;
block|}
specifier|static
specifier|inline
name|bool
name|AddressIsPoisoned
parameter_list|(
name|uptr
name|a
parameter_list|)
block|{
name|PROFILE_ASAN_MAPPING
argument_list|()
expr_stmt|;
specifier|const
name|uptr
name|kAccessSize
init|=
literal|1
decl_stmt|;
name|u8
modifier|*
name|shadow_address
init|=
operator|(
name|u8
operator|*
operator|)
name|MEM_TO_SHADOW
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|s8
name|shadow_value
init|=
operator|*
name|shadow_address
decl_stmt|;
if|if
condition|(
name|shadow_value
condition|)
block|{
name|u8
name|last_accessed_byte
init|=
operator|(
name|a
operator|&
operator|(
name|SHADOW_GRANULARITY
operator|-
literal|1
operator|)
operator|)
operator|+
name|kAccessSize
operator|-
literal|1
decl_stmt|;
return|return
operator|(
name|last_accessed_byte
operator|>=
name|shadow_value
operator|)
return|;
block|}
return|return
name|false
return|;
block|}
comment|// Must be after all calls to PROFILE_ASAN_MAPPING().
specifier|static
specifier|const
name|uptr
name|kAsanMappingProfileSize
init|=
name|__LINE__
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __asan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_MAPPING_H
end_comment

end_unit

