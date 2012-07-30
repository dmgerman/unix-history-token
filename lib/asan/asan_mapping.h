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
comment|// http://code.google.com/p/address-sanitizer/wiki/AddressSanitizerAlgorithm
end_comment

begin_if
if|#
directive|if
name|ASAN_FLEXIBLE_MAPPING_AND_OFFSET
operator|==
literal|1
end_if

begin_extern
extern|extern __attribute__((visibility(
literal|"default"
end_extern

begin_decl_stmt
unit|)))
name|uptr
name|__asan_mapping_scale
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern __attribute__((visibility(
literal|"default"
end_extern

begin_decl_stmt
unit|)))
name|uptr
name|__asan_mapping_offset
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SHADOW_SCALE
value|(__asan_mapping_scale)
end_define

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|(__asan_mapping_offset)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|ANDROID
end_ifdef

begin_define
define|#
directive|define
name|SHADOW_SCALE
value|(3)
end_define

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SHADOW_SCALE
value|(3)
end_define

begin_if
if|#
directive|if
name|__WORDSIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|(1<< 29)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SHADOW_OFFSET
value|(1ULL<< 44)
end_define

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
comment|// ASAN_FLEXIBLE_MAPPING_AND_OFFSET
end_comment

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
value|(((mem)>> SHADOW_SCALE) | (SHADOW_OFFSET))
end_define

begin_define
define|#
directive|define
name|SHADOW_TO_MEM
parameter_list|(
name|shadow
parameter_list|)
value|(((shadow) - SHADOW_OFFSET)<< SHADOW_SCALE)
end_define

begin_if
if|#
directive|if
name|__WORDSIZE
operator|==
literal|64
end_if

begin_decl_stmt
specifier|static
specifier|const
name|uptr
name|kHighMemEnd
init|=
literal|0x00007fffffffffffUL
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|// __WORDSIZE == 32
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uptr
name|kHighMemEnd
init|=
literal|0xffffffff
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __WORDSIZE
end_comment

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
name|kShadowGapBeg
value|(kLowShadowEnd ? kLowShadowEnd + 1 : 16 * kPageSize)
end_define

begin_define
define|#
directive|define
name|kShadowGapEnd
value|(kHighShadowBeg - 1)
end_define

begin_define
define|#
directive|define
name|kGlobalAndStackRedzone
define|\
value|(SHADOW_GRANULARITY< 32 ? 32 : SHADOW_GRANULARITY)
end_define

begin_decl_stmt
name|namespace
name|__asan
block|{
specifier|static
specifier|inline
name|bool
name|AddrIsInLowMem
parameter_list|(
name|uptr
name|a
parameter_list|)
block|{
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
name|AddrIsInMem
parameter_list|(
name|uptr
name|a
parameter_list|)
block|{
return|return
name|AddrIsInLowMem
argument_list|(
name|a
argument_list|)
operator|||
name|AddrIsInHighMem
argument_list|(
name|a
argument_list|)
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
name|AddrIsInShadow
parameter_list|(
name|uptr
name|a
parameter_list|)
block|{
return|return
name|AddrIsInLowShadow
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
name|AddrIsInShadowGap
parameter_list|(
name|uptr
name|a
parameter_list|)
block|{
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
name|AddrIsAlignedByGranularity
parameter_list|(
name|uptr
name|a
parameter_list|)
block|{
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
name|MemToShadow
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

