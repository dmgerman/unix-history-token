begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       fastpos.h
end_comment

begin_comment
comment|/// \brief      Kind of two-bit version of bit scan reverse
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//  Authors:    Igor Pavlov
end_comment

begin_comment
comment|//              Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_FASTPOS_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_FASTPOS_H
end_define

begin_comment
comment|// LZMA encodes match distances by storing the highest two bits using
end_comment

begin_comment
comment|// a six-bit value [0, 63], and then the missing lower bits.
end_comment

begin_comment
comment|// Dictionary size is also stored using this encoding in the .xz
end_comment

begin_comment
comment|// file format header.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// fastpos.h provides a way to quickly find out the correct six-bit
end_comment

begin_comment
comment|// values. The following table gives some examples of this encoding:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     dist   return
end_comment

begin_comment
comment|//       0       0
end_comment

begin_comment
comment|//       1       1
end_comment

begin_comment
comment|//       2       2
end_comment

begin_comment
comment|//       3       3
end_comment

begin_comment
comment|//       4       4
end_comment

begin_comment
comment|//       5       4
end_comment

begin_comment
comment|//       6       5
end_comment

begin_comment
comment|//       7       5
end_comment

begin_comment
comment|//       8       6
end_comment

begin_comment
comment|//      11       6
end_comment

begin_comment
comment|//      12       7
end_comment

begin_comment
comment|//     ...      ...
end_comment

begin_comment
comment|//      15       7
end_comment

begin_comment
comment|//      16       8
end_comment

begin_comment
comment|//      17       8
end_comment

begin_comment
comment|//     ...      ...
end_comment

begin_comment
comment|//      23       8
end_comment

begin_comment
comment|//      24       9
end_comment

begin_comment
comment|//      25       9
end_comment

begin_comment
comment|//     ...      ...
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Provided functions or macros
end_comment

begin_comment
comment|// ----------------------------
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// get_dist_slot(dist) is the basic version. get_dist_slot_2(dist)
end_comment

begin_comment
comment|// assumes that dist>= FULL_DISTANCES, thus the result is at least
end_comment

begin_comment
comment|// FULL_DISTANCES_BITS * 2. Using get_dist_slot(dist) instead of
end_comment

begin_comment
comment|// get_dist_slot_2(dist) would give the same result, but get_dist_slot_2(dist)
end_comment

begin_comment
comment|// should be tiny bit faster due to the assumption being made.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Size vs. speed
end_comment

begin_comment
comment|// --------------
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// With some CPUs that have fast BSR (bit scan reverse) instruction, the
end_comment

begin_comment
comment|// size optimized version is slightly faster than the bigger table based
end_comment

begin_comment
comment|// approach. Such CPUs include Intel Pentium Pro, Pentium II, Pentium III
end_comment

begin_comment
comment|// and Core 2 (possibly others). AMD K7 seems to have slower BSR, but that
end_comment

begin_comment
comment|// would still have speed roughly comparable to the table version. Older
end_comment

begin_comment
comment|// x86 CPUs like the original Pentium have very slow BSR; on those systems
end_comment

begin_comment
comment|// the table version is a lot faster.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// On some CPUs, the table version is a lot faster when using position
end_comment

begin_comment
comment|// dependent code, but with position independent code the size optimized
end_comment

begin_comment
comment|// version is slightly faster. This occurs at least on 32-bit SPARC (no
end_comment

begin_comment
comment|// ASM optimizations).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I'm making the table version the default, because that has good speed
end_comment

begin_comment
comment|// on all systems I have tried. The size optimized version is sometimes
end_comment

begin_comment
comment|// slightly faster, but sometimes it is a lot slower.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SMALL
end_ifdef

begin_define
define|#
directive|define
name|get_dist_slot
parameter_list|(
name|dist
parameter_list|)
define|\
value|((dist)<= 4 ? (dist) : get_dist_slot_2(dist))
end_define

begin_function
specifier|static
specifier|inline
name|uint32_t
name|get_dist_slot_2
parameter_list|(
name|uint32_t
name|dist
parameter_list|)
block|{
specifier|const
name|uint32_t
name|i
init|=
name|bsr32
argument_list|(
name|dist
argument_list|)
decl_stmt|;
return|return
operator|(
name|i
operator|+
name|i
operator|)
operator|+
operator|(
operator|(
name|dist
operator|>>
operator|(
name|i
operator|-
literal|1
operator|)
operator|)
operator|&
literal|1
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FASTPOS_BITS
value|13
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|uint8_t
name|lzma_fastpos
index|[
literal|1
operator|<<
name|FASTPOS_BITS
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|fastpos_shift
parameter_list|(
name|extra
parameter_list|,
name|n
parameter_list|)
define|\
value|((extra) + (n) * (FASTPOS_BITS - 1))
end_define

begin_define
define|#
directive|define
name|fastpos_limit
parameter_list|(
name|extra
parameter_list|,
name|n
parameter_list|)
define|\
value|(UINT32_C(1)<< (FASTPOS_BITS + fastpos_shift(extra, n)))
end_define

begin_define
define|#
directive|define
name|fastpos_result
parameter_list|(
name|dist
parameter_list|,
name|extra
parameter_list|,
name|n
parameter_list|)
define|\
value|lzma_fastpos[(dist)>> fastpos_shift(extra, n)] \ 			+ 2 * fastpos_shift(extra, n)
end_define

begin_function
specifier|static
specifier|inline
name|uint32_t
name|get_dist_slot
parameter_list|(
name|uint32_t
name|dist
parameter_list|)
block|{
comment|// If it is small enough, we can pick the result directly from
comment|// the precalculated table.
if|if
condition|(
name|dist
operator|<
name|fastpos_limit
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
return|return
name|lzma_fastpos
index|[
name|dist
index|]
return|;
if|if
condition|(
name|dist
operator|<
name|fastpos_limit
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
condition|)
return|return
name|fastpos_result
argument_list|(
name|dist
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
return|;
return|return
name|fastpos_result
argument_list|(
name|dist
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|FULL_DISTANCES_BITS
end_ifdef

begin_function
specifier|static
specifier|inline
name|uint32_t
name|get_dist_slot_2
parameter_list|(
name|uint32_t
name|dist
parameter_list|)
block|{
name|assert
argument_list|(
name|dist
operator|>=
name|FULL_DISTANCES
argument_list|)
expr_stmt|;
if|if
condition|(
name|dist
operator|<
name|fastpos_limit
argument_list|(
name|FULL_DISTANCES_BITS
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
condition|)
return|return
name|fastpos_result
argument_list|(
name|dist
argument_list|,
name|FULL_DISTANCES_BITS
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
return|;
if|if
condition|(
name|dist
operator|<
name|fastpos_limit
argument_list|(
name|FULL_DISTANCES_BITS
operator|-
literal|1
argument_list|,
literal|1
argument_list|)
condition|)
return|return
name|fastpos_result
argument_list|(
name|dist
argument_list|,
name|FULL_DISTANCES_BITS
operator|-
literal|1
argument_list|,
literal|1
argument_list|)
return|;
return|return
name|fastpos_result
argument_list|(
name|dist
argument_list|,
name|FULL_DISTANCES_BITS
operator|-
literal|1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

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

end_unit

