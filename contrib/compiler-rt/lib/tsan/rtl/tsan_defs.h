begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_defs.h ---------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of ThreadSanitizer (TSan), a race detector.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_DEFS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_libc.h"
end_include

begin_include
include|#
directive|include
file|"tsan_stat.h"
end_include

begin_include
include|#
directive|include
file|"ubsan/ubsan_platform.h"
end_include

begin_comment
comment|// Setup defaults for compile definitions.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_NO_HISTORY
end_ifndef

begin_define
define|#
directive|define
name|TSAN_NO_HISTORY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_COLLECT_STATS
end_ifndef

begin_define
define|#
directive|define
name|TSAN_COLLECT_STATS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_CONTAINS_UBSAN
end_ifndef

begin_if
if|#
directive|if
name|CAN_SANITIZE_UB
operator|&&
operator|!
name|SANITIZER_GO
end_if

begin_define
define|#
directive|define
name|TSAN_CONTAINS_UBSAN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TSAN_CONTAINS_UBSAN
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

begin_decl_stmt
name|namespace
name|__tsan
block|{
specifier|const
name|int
name|kTidBits
init|=
literal|13
decl_stmt|;
specifier|const
name|unsigned
name|kMaxTid
init|=
literal|1
operator|<<
name|kTidBits
decl_stmt|;
if|#
directive|if
operator|!
name|SANITIZER_GO
specifier|const
name|unsigned
name|kMaxTidInClock
init|=
name|kMaxTid
operator|*
literal|2
decl_stmt|;
comment|// This includes msb 'freed' bit.
else|#
directive|else
specifier|const
name|unsigned
name|kMaxTidInClock
init|=
name|kMaxTid
decl_stmt|;
comment|// Go does not track freed memory.
endif|#
directive|endif
specifier|const
name|int
name|kClkBits
init|=
literal|42
decl_stmt|;
specifier|const
name|unsigned
name|kMaxTidReuse
init|=
operator|(
literal|1
operator|<<
operator|(
literal|64
operator|-
name|kClkBits
operator|)
operator|)
operator|-
literal|1
decl_stmt|;
specifier|const
name|uptr
name|kShadowStackSize
init|=
literal|64
operator|*
literal|1024
decl_stmt|;
comment|// Count of shadow values in a shadow cell.
specifier|const
name|uptr
name|kShadowCnt
init|=
literal|4
decl_stmt|;
comment|// That many user bytes are mapped onto a single shadow cell.
specifier|const
name|uptr
name|kShadowCell
init|=
literal|8
decl_stmt|;
comment|// Size of a single shadow value (u64).
specifier|const
name|uptr
name|kShadowSize
init|=
literal|8
decl_stmt|;
comment|// Shadow memory is kShadowMultiplier times larger than user memory.
specifier|const
name|uptr
name|kShadowMultiplier
init|=
name|kShadowSize
operator|*
name|kShadowCnt
operator|/
name|kShadowCell
decl_stmt|;
comment|// That many user bytes are mapped onto a single meta shadow cell.
comment|// Must be less or equal to minimal memory allocator alignment.
specifier|const
name|uptr
name|kMetaShadowCell
init|=
literal|8
decl_stmt|;
comment|// Size of a single meta shadow value (u32).
specifier|const
name|uptr
name|kMetaShadowSize
init|=
literal|4
decl_stmt|;
if|#
directive|if
name|TSAN_NO_HISTORY
specifier|const
name|bool
name|kCollectHistory
init|=
name|false
decl_stmt|;
else|#
directive|else
specifier|const
name|bool
name|kCollectHistory
init|=
name|true
decl_stmt|;
endif|#
directive|endif
specifier|const
name|unsigned
name|kInvalidTid
init|=
operator|(
name|unsigned
operator|)
operator|-
literal|1
decl_stmt|;
comment|// The following "build consistency" machinery ensures that all source files
comment|// are built in the same configuration. Inconsistent builds lead to
comment|// hard to debug crashes.
if|#
directive|if
name|SANITIZER_DEBUG
name|void
name|build_consistency_debug
parameter_list|()
function_decl|;
else|#
directive|else
name|void
name|build_consistency_release
parameter_list|()
function_decl|;
endif|#
directive|endif
if|#
directive|if
name|TSAN_COLLECT_STATS
name|void
name|build_consistency_stats
parameter_list|()
function_decl|;
else|#
directive|else
name|void
name|build_consistency_nostats
parameter_list|()
function_decl|;
endif|#
directive|endif
specifier|static
specifier|inline
name|void
name|USED
name|build_consistency
parameter_list|()
block|{
if|#
directive|if
name|SANITIZER_DEBUG
name|build_consistency_debug
argument_list|()
expr_stmt|;
else|#
directive|else
name|build_consistency_release
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|TSAN_COLLECT_STATS
name|build_consistency_stats
argument_list|()
expr_stmt|;
else|#
directive|else
name|build_consistency_nostats
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|min
argument_list|(
argument|T a
argument_list|,
argument|T b
argument_list|)
block|{
return|return
name|a
operator|<
name|b
operator|?
name|a
operator|:
name|b
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|max
argument_list|(
argument|T a
argument_list|,
argument|T b
argument_list|)
block|{
return|return
name|a
operator|>
name|b
operator|?
name|a
operator|:
name|b
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|RoundUp
argument_list|(
argument|T p
argument_list|,
argument|u64 align
argument_list|)
block|{
name|DCHECK_EQ
argument_list|(
name|align
operator|&
operator|(
name|align
operator|-
literal|1
operator|)
argument_list|,
literal|0
argument_list|)
block|;
return|return
call|(
name|T
call|)
argument_list|(
operator|(
operator|(
name|u64
operator|)
name|p
operator|+
name|align
operator|-
literal|1
operator|)
operator|&
operator|~
operator|(
name|align
operator|-
literal|1
operator|)
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|RoundDown
argument_list|(
argument|T p
argument_list|,
argument|u64 align
argument_list|)
block|{
name|DCHECK_EQ
argument_list|(
name|align
operator|&
operator|(
name|align
operator|-
literal|1
operator|)
argument_list|,
literal|0
argument_list|)
block|;
return|return
call|(
name|T
call|)
argument_list|(
operator|(
name|u64
operator|)
name|p
operator|&
operator|~
operator|(
name|align
operator|-
literal|1
operator|)
argument_list|)
return|;
block|}
comment|// Zeroizes high part, returns 'bits' lsb bits.
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|GetLsb
argument_list|(
argument|T v
argument_list|,
argument|int bits
argument_list|)
block|{
return|return
call|(
name|T
call|)
argument_list|(
operator|(
name|u64
operator|)
name|v
operator|&
operator|(
operator|(
literal|1ull
operator|<<
name|bits
operator|)
operator|-
literal|1
operator|)
argument_list|)
return|;
block|}
struct|struct
name|MD5Hash
block|{
name|u64
name|hash
index|[
literal|2
index|]
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|MD5Hash
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
block|}
struct|;
name|MD5Hash
name|md5_hash
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
struct_decl|struct
name|Processor
struct_decl|;
struct_decl|struct
name|ThreadState
struct_decl|;
name|class
name|ThreadContext
decl_stmt|;
struct_decl|struct
name|Context
struct_decl|;
struct_decl|struct
name|ReportStack
struct_decl|;
name|class
name|ReportDesc
decl_stmt|;
name|class
name|RegionAlloc
decl_stmt|;
comment|// Descriptor of user's memory block.
struct|struct
name|MBlock
block|{
name|u64
name|siz
range|:
literal|48
decl_stmt|;
name|u64
name|tag
range|:
literal|16
decl_stmt|;
name|u32
name|stk
decl_stmt|;
name|u16
name|tid
decl_stmt|;
block|}
struct|;
name|COMPILER_CHECK
argument_list|(
sizeof|sizeof
argument_list|(
name|MBlock
argument_list|)
operator|==
literal|16
argument_list|)
expr_stmt|;
enum|enum
name|ExternalTag
enum|:
name|uptr
block|{
name|kExternalTagNone
init|=
literal|0
block|,
name|kExternalTagSwiftModifyingAccess
init|=
literal|1
block|,
name|kExternalTagFirstUserAvailable
init|=
literal|2
block|,
name|kExternalTagMax
init|=
literal|1024
block|,
comment|// Don't set kExternalTagMax over 65,536, since MBlock only stores tags
comment|// as 16-bit values, see tsan_defs.h.
block|}
enum|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __tsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TSAN_DEFS_H
end_comment

end_unit

