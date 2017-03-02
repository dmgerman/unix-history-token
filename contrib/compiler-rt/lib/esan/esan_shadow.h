begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- esan_shadow.h -------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of EfficiencySanitizer, a family of performance tuners.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Shadow memory mappings for the esan run-time.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ESAN_SHADOW_H
end_ifndef

begin_define
define|#
directive|define
name|ESAN_SHADOW_H
end_define

begin_include
include|#
directive|include
file|"esan.h"
end_include

begin_include
include|#
directive|include
file|<sanitizer_common/sanitizer_platform.h>
end_include

begin_if
if|#
directive|if
name|SANITIZER_WORDSIZE
operator|!=
literal|64
end_if

begin_error
error|#
directive|error
error|Only 64-bit is supported
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|__esan
block|{
struct|struct
name|ApplicationRegion
block|{
name|uptr
name|Start
decl_stmt|;
name|uptr
name|End
decl_stmt|;
name|bool
name|ShadowMergedWithPrev
decl_stmt|;
block|}
struct|;
if|#
directive|if
name|SANITIZER_LINUX
operator|&&
name|defined
argument_list|(
name|__x86_64__
argument_list|)
comment|// Linux x86_64
comment|//
comment|// Application memory falls into these 5 regions (ignoring the corner case
comment|// of PIE with a non-zero PT_LOAD base):
comment|//
comment|// [0x00000000'00000000, 0x00000100'00000000) non-PIE + heap
comment|// [0x00005500'00000000, 0x00005700'00000000) PIE
comment|// [0x00007e00'00000000, 0x00007fff'ff600000) libraries + stack, part 1
comment|// [0x00007fff'ff601000, 0x00008000'00000000) libraries + stack, part 2
comment|// [0xffffffff'ff600000, 0xffffffff'ff601000) vsyscall
comment|//
comment|// Although we can ignore the vsyscall for the most part as there are few data
comment|// references there (other sanitizers ignore it), we enforce a gap inside the
comment|// library region to distinguish the vsyscall's shadow, considering this gap to
comment|// be an invalid app region.
comment|// We disallow application memory outside of those 5 regions.
comment|// Our regions assume that the stack rlimit is less than a terabyte (otherwise
comment|// the Linux kernel's default mmap region drops below 0x7e00'), which we enforce
comment|// at init time (we can support larger and unlimited sizes for shadow
comment|// scaledowns, but it is difficult for 1:1 mappings).
comment|//
comment|// Our shadow memory is scaled from a 1:1 mapping and supports a scale
comment|// specified at library initialization time that can be any power-of-2
comment|// scaledown (1x, 2x, 4x, 8x, 16x, etc.).
comment|//
comment|// We model our shadow memory after Umbra, a library used by the Dr. Memory
comment|// tool: https://github.com/DynamoRIO/drmemory/blob/master/umbra/umbra_x64.c.
comment|// We use Umbra's scheme as it was designed to support different
comment|// offsets, it supports two different shadow mappings (which we may want to
comment|// use for future tools), and it ensures that the shadow of a shadow will
comment|// not overlap either shadow memory or application memory.
comment|//
comment|// This formula translates from application memory to shadow memory:
comment|//
comment|//   shadow(app) = ((app& 0x00000fff'ffffffff) + offset)>> scale
comment|//
comment|// Where the offset for 1:1 is 0x00001300'00000000.  For other scales, the
comment|// offset is shifted left by the scale, except for scales of 1 and 2 where
comment|// it must be tweaked in order to pass the double-shadow test
comment|// (see the "shadow(shadow)" comments below):
comment|//   scale == 0: 0x00001300'000000000
comment|//   scale == 1: 0x00002200'000000000
comment|//   scale == 2: 0x00004400'000000000
comment|//   scale>= 3: (0x00001300'000000000<< scale)
comment|//
comment|// Do not pass in the open-ended end value to the formula as it will fail.
comment|//
comment|// The resulting shadow memory regions for a 0 scaling are:
comment|//
comment|// [0x00001300'00000000, 0x00001400'00000000)
comment|// [0x00001800'00000000, 0x00001a00'00000000)
comment|// [0x00002100'00000000, 0x000022ff'ff600000)
comment|// [0x000022ff'ff601000, 0x00002300'00000000)
comment|// [0x000022ff'ff600000, 0x000022ff'ff601000]
comment|//
comment|// We also want to ensure that a wild access by the application into the shadow
comment|// regions will not corrupt our own shadow memory.  shadow(shadow) ends up
comment|// disjoint from shadow(app):
comment|//
comment|// [0x00001600'00000000, 0x00001700'00000000)
comment|// [0x00001b00'00000000, 0x00001d00'00000000)
comment|// [0x00001400'00000000, 0x000015ff'ff600000]
comment|// [0x000015ff'ff601000, 0x00001600'00000000]
comment|// [0x000015ff'ff600000, 0x000015ff'ff601000]
specifier|static
specifier|const
name|struct
name|ApplicationRegion
name|AppRegions
index|[]
init|=
block|{
block|{
literal|0x0000000000000000ull
block|,
literal|0x0000010000000000u
block|,
name|false
block|}
block|,
block|{
literal|0x0000550000000000u
block|,
literal|0x0000570000000000u
block|,
name|false
block|}
block|,
comment|// We make one shadow mapping to hold the shadow regions for all 3 of these
comment|// app regions, as the mappings interleave, and the gap between the 3rd and
comment|// 4th scales down below a page.
block|{
literal|0x00007e0000000000u
block|,
literal|0x00007fffff600000u
block|,
name|false
block|}
block|,
block|{
literal|0x00007fffff601000u
block|,
literal|0x0000800000000000u
block|,
name|true
block|}
block|,
block|{
literal|0xffffffffff600000u
block|,
literal|0xffffffffff601000u
block|,
name|true
block|}
block|, }
decl_stmt|;
elif|#
directive|elif
name|SANITIZER_LINUX
operator|&&
name|SANITIZER_MIPS64
comment|// Application memory falls into these 3 regions
comment|//
comment|// [0x00000001'00000000, 0x00000002'00000000) non-PIE + heap
comment|// [0x000000aa'00000000, 0x000000ab'00000000) PIE
comment|// [0x000000ff'00000000, 0x000000ff'ffffffff) libraries + stack
comment|//
comment|// This formula translates from application memory to shadow memory:
comment|//
comment|//   shadow(app) = ((app& 0x00000f'ffffffff) + offset)>> scale
comment|//
comment|// Where the offset for 1:1 is 0x000013'00000000.  For other scales, the
comment|// offset is shifted left by the scale, except for scales of 1 and 2 where
comment|// it must be tweaked in order to pass the double-shadow test
comment|// (see the "shadow(shadow)" comments below):
comment|//   scale == 0: 0x000013'00000000
comment|//   scale == 1: 0x000022'00000000
comment|//   scale == 2: 0x000044'00000000
comment|//   scale>= 3: (0x000013'00000000<< scale)
comment|//
comment|// The resulting shadow memory regions for a 0 scaling are:
comment|//
comment|// [0x00000014'00000000, 0x00000015'00000000)
comment|// [0x0000001d'00000000, 0x0000001e'00000000)
comment|// [0x00000022'00000000, 0x00000022'ffffffff)
comment|//
comment|// We also want to ensure that a wild access by the application into the shadow
comment|// regions will not corrupt our own shadow memory. shadow(shadow) ends up
comment|// disjoint from shadow(app):
comment|//
comment|// [0x00000017'00000000, 0x00000018'00000000)
comment|// [0x00000020'00000000, 0x00000021'00000000)
comment|// [0x00000015'00000000, 0x00000015'ffffffff]
specifier|static
specifier|const
name|struct
name|ApplicationRegion
name|AppRegions
index|[]
init|=
block|{
block|{
literal|0x0100000000u
block|,
literal|0x0200000000u
block|,
name|false
block|}
block|,
block|{
literal|0xaa00000000u
block|,
literal|0xab00000000u
block|,
name|false
block|}
block|,
block|{
literal|0xff00000000u
block|,
literal|0xffffffffffu
block|,
name|false
block|}
block|, }
decl_stmt|;
else|#
directive|else
error|#
directive|error
error|Platform not supported
endif|#
directive|endif
specifier|static
specifier|const
name|u32
name|NumAppRegions
init|=
sizeof|sizeof
argument_list|(
name|AppRegions
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|AppRegions
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
comment|// See the comment above: we do not currently support a stack size rlimit
comment|// equal to or larger than 1TB.
specifier|static
specifier|const
name|uptr
name|MaxStackSize
init|=
operator|(
literal|1ULL
operator|<<
literal|40
operator|)
operator|-
literal|4096
decl_stmt|;
name|class
name|ShadowMapping
block|{
name|public
label|:
comment|// The scale and offset vary by tool.
name|uptr
name|Scale
decl_stmt|;
name|uptr
name|Offset
decl_stmt|;
comment|// TODO(sagar.thakur): Try to hardcode the mask as done in the compiler
comment|// instrumentation to reduce the runtime cost of appToShadow.
struct|struct
name|ShadowMemoryMask40
block|{
specifier|static
specifier|const
name|uptr
name|Mask
init|=
literal|0x0000000fffffffffu
decl_stmt|;
block|}
struct|;
struct|struct
name|ShadowMemoryMask47
block|{
specifier|static
specifier|const
name|uptr
name|Mask
init|=
literal|0x00000fffffffffffu
decl_stmt|;
block|}
struct|;
name|void
name|initialize
parameter_list|(
name|uptr
name|ShadowScale
parameter_list|)
block|{
specifier|const
name|uptr
name|OffsetArray40
index|[
literal|3
index|]
init|=
block|{
literal|0x0000001300000000u
block|,
literal|0x0000002200000000u
block|,
literal|0x0000004400000000u
block|,     }
decl_stmt|;
specifier|const
name|uptr
name|OffsetArray47
index|[
literal|3
index|]
init|=
block|{
literal|0x0000130000000000u
block|,
literal|0x0000220000000000u
block|,
literal|0x0000440000000000u
block|,     }
decl_stmt|;
name|Scale
operator|=
name|ShadowScale
expr_stmt|;
switch|switch
condition|(
name|VmaSize
condition|)
block|{
case|case
literal|40
case|:
block|{
if|if
condition|(
name|Scale
operator|<=
literal|2
condition|)
name|Offset
operator|=
name|OffsetArray40
index|[
name|Scale
index|]
expr_stmt|;
else|else
name|Offset
operator|=
name|OffsetArray40
index|[
literal|0
index|]
operator|<<
name|Scale
expr_stmt|;
block|}
break|break;
case|case
literal|47
case|:
block|{
if|if
condition|(
name|Scale
operator|<=
literal|2
condition|)
name|Offset
operator|=
name|OffsetArray47
index|[
name|Scale
index|]
expr_stmt|;
else|else
name|Offset
operator|=
name|OffsetArray47
index|[
literal|0
index|]
operator|<<
name|Scale
expr_stmt|;
block|}
break|break;
default|default:
block|{
name|Printf
argument_list|(
literal|"ERROR: %d-bit virtual memory address size not supported\n"
argument_list|,
name|VmaSize
argument_list|)
expr_stmt|;
name|Die
argument_list|()
expr_stmt|;
block|}
block|}
block|}
block|}
empty_stmt|;
specifier|extern
name|ShadowMapping
name|Mapping
decl_stmt|;
specifier|static
specifier|inline
name|bool
name|getAppRegion
parameter_list|(
name|u32
name|i
parameter_list|,
name|uptr
modifier|*
name|Start
parameter_list|,
name|uptr
modifier|*
name|End
parameter_list|)
block|{
if|if
condition|(
name|i
operator|>=
name|NumAppRegions
condition|)
return|return
name|false
return|;
operator|*
name|Start
operator|=
name|AppRegions
index|[
name|i
index|]
operator|.
name|Start
expr_stmt|;
operator|*
name|End
operator|=
name|AppRegions
index|[
name|i
index|]
operator|.
name|End
expr_stmt|;
return|return
name|true
return|;
block|}
name|ALWAYS_INLINE
name|bool
name|isAppMem
parameter_list|(
name|uptr
name|Mem
parameter_list|)
block|{
for|for
control|(
name|u32
name|i
init|=
literal|0
init|;
name|i
operator|<
name|NumAppRegions
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|Mem
operator|>=
name|AppRegions
index|[
name|i
index|]
operator|.
name|Start
operator|&&
name|Mem
operator|<
name|AppRegions
index|[
name|i
index|]
operator|.
name|End
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|template
operator|<
name|typename
name|Params
operator|>
name|uptr
name|appToShadowImpl
argument_list|(
argument|uptr App
argument_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|App
operator|&
name|Params
operator|::
name|Mask
operator|)
operator|+
name|Mapping
operator|.
name|Offset
operator|)
operator|>>
name|Mapping
operator|.
name|Scale
operator|)
return|;
block|}
name|ALWAYS_INLINE
name|uptr
name|appToShadow
parameter_list|(
name|uptr
name|App
parameter_list|)
block|{
switch|switch
condition|(
name|VmaSize
condition|)
block|{
case|case
literal|40
case|:
return|return
name|appToShadowImpl
operator|<
name|ShadowMapping
operator|::
name|ShadowMemoryMask40
operator|>
operator|(
name|App
operator|)
return|;
case|case
literal|47
case|:
return|return
name|appToShadowImpl
operator|<
name|ShadowMapping
operator|::
name|ShadowMemoryMask47
operator|>
operator|(
name|App
operator|)
return|;
default|default:
block|{
name|Printf
argument_list|(
literal|"ERROR: %d-bit virtual memory address size not supported\n"
argument_list|,
name|VmaSize
argument_list|)
expr_stmt|;
name|Die
argument_list|()
expr_stmt|;
block|}
block|}
block|}
specifier|static
specifier|inline
name|bool
name|getShadowRegion
parameter_list|(
name|u32
name|i
parameter_list|,
name|uptr
modifier|*
name|Start
parameter_list|,
name|uptr
modifier|*
name|End
parameter_list|)
block|{
if|if
condition|(
name|i
operator|>=
name|NumAppRegions
condition|)
return|return
name|false
return|;
name|u32
name|UnmergedShadowCount
init|=
literal|0
decl_stmt|;
name|u32
name|AppIdx
decl_stmt|;
for|for
control|(
name|AppIdx
operator|=
literal|0
init|;
name|AppIdx
operator|<
name|NumAppRegions
condition|;
operator|++
name|AppIdx
control|)
block|{
if|if
condition|(
operator|!
name|AppRegions
index|[
name|AppIdx
index|]
operator|.
name|ShadowMergedWithPrev
condition|)
block|{
if|if
condition|(
name|UnmergedShadowCount
operator|==
name|i
condition|)
break|break;
name|UnmergedShadowCount
operator|++
expr_stmt|;
block|}
block|}
if|if
condition|(
name|AppIdx
operator|>=
name|NumAppRegions
operator|||
name|UnmergedShadowCount
operator|!=
name|i
condition|)
return|return
name|false
return|;
operator|*
name|Start
operator|=
name|appToShadow
argument_list|(
name|AppRegions
index|[
name|AppIdx
index|]
operator|.
name|Start
argument_list|)
expr_stmt|;
comment|// The formula fails for the end itself.
operator|*
name|End
operator|=
name|appToShadow
argument_list|(
name|AppRegions
index|[
name|AppIdx
index|]
operator|.
name|End
operator|-
literal|1
argument_list|)
operator|+
literal|1
expr_stmt|;
comment|// Merge with adjacent shadow regions:
for|for
control|(
operator|++
name|AppIdx
init|;
name|AppIdx
operator|<
name|NumAppRegions
condition|;
operator|++
name|AppIdx
control|)
block|{
if|if
condition|(
operator|!
name|AppRegions
index|[
name|AppIdx
index|]
operator|.
name|ShadowMergedWithPrev
condition|)
break|break;
operator|*
name|Start
operator|=
name|Min
argument_list|(
operator|*
name|Start
argument_list|,
name|appToShadow
argument_list|(
name|AppRegions
index|[
name|AppIdx
index|]
operator|.
name|Start
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|End
operator|=
name|Max
argument_list|(
operator|*
name|End
argument_list|,
name|appToShadow
argument_list|(
name|AppRegions
index|[
name|AppIdx
index|]
operator|.
name|End
operator|-
literal|1
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|true
return|;
block|}
name|ALWAYS_INLINE
name|bool
name|isShadowMem
parameter_list|(
name|uptr
name|Mem
parameter_list|)
block|{
comment|// We assume this is not used on any critical performance path and so there's
comment|// no need to hardcode the mapping results.
for|for
control|(
name|uptr
name|i
init|=
literal|0
init|;
name|i
operator|<
name|NumAppRegions
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|Mem
operator|>=
name|appToShadow
argument_list|(
name|AppRegions
index|[
name|i
index|]
operator|.
name|Start
argument_list|)
operator|&&
name|Mem
operator|<
name|appToShadow
argument_list|(
name|AppRegions
index|[
name|i
index|]
operator|.
name|End
operator|-
literal|1
argument_list|)
operator|+
literal|1
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace __esan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ESAN_SHADOW_H */
end_comment

end_unit

