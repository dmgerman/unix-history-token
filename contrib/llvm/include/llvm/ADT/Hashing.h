begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/ADT/Hashing.h - Utilities for hashing --------------*- C++ -*-===//
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
comment|// This file implements the newly proposed standard C++ interfaces for hashing
end_comment

begin_comment
comment|// arbitrary data and building hash functions for user-defined types. This
end_comment

begin_comment
comment|// interface was originally proposed in N3333[1] and is currently under review
end_comment

begin_comment
comment|// for inclusion in a future TR and/or standard.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The primary interfaces provide are comprised of one type and three functions:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  -- 'hash_code' class is an opaque type representing the hash code for some
end_comment

begin_comment
comment|//     data. It is the intended product of hashing, and can be used to implement
end_comment

begin_comment
comment|//     hash tables, checksumming, and other common uses of hashes. It is not an
end_comment

begin_comment
comment|//     integer type (although it can be converted to one) because it is risky
end_comment

begin_comment
comment|//     to assume much about the internals of a hash_code. In particular, each
end_comment

begin_comment
comment|//     execution of the program has a high probability of producing a different
end_comment

begin_comment
comment|//     hash_code for a given input. Thus their values are not stable to save or
end_comment

begin_comment
comment|//     persist, and should only be used during the execution for the
end_comment

begin_comment
comment|//     construction of hashing datastructures.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  -- 'hash_value' is a function designed to be overloaded for each
end_comment

begin_comment
comment|//     user-defined type which wishes to be used within a hashing context. It
end_comment

begin_comment
comment|//     should be overloaded within the user-defined type's namespace and found
end_comment

begin_comment
comment|//     via ADL. Overloads for primitive types are provided by this library.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  -- 'hash_combine' and 'hash_combine_range' are functions designed to aid
end_comment

begin_comment
comment|//      programmers in easily and intuitively combining a set of data into
end_comment

begin_comment
comment|//      a single hash_code for their object. They should only logically be used
end_comment

begin_comment
comment|//      within the implementation of a 'hash_value' routine or similar context.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that 'hash_combine_range' contains very special logic for hashing
end_comment

begin_comment
comment|// a contiguous array of integers or pointers. This logic is *extremely* fast,
end_comment

begin_comment
comment|// on a modern Intel "Gainestown" Xeon (Nehalem uarch) @2.2 GHz, these were
end_comment

begin_comment
comment|// benchmarked at over 6.5 GiB/s for large keys, and<20 cycles/hash for keys
end_comment

begin_comment
comment|// under 32-bytes.
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
name|LLVM_ADT_HASHING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_HASHING_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Host.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SwapByteOrder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/type_traits.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_comment
comment|// Allow detecting C++11 feature availability when building with Clang without
end_comment

begin_comment
comment|// breaking other compilers.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__has_feature
end_ifndef

begin_define
define|#
directive|define
name|__has_feature
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief An opaque object representing a hash code.
comment|///
comment|/// This object represents the result of hashing some entity. It is intended to
comment|/// be used to implement hashtables or other hashing-based data structures.
comment|/// While it wraps and exposes a numeric value, this value should not be
comment|/// trusted to be stable or predictable across processes or executions.
comment|///
comment|/// In order to obtain the hash_code for an object 'x':
comment|/// \code
comment|///   using llvm::hash_value;
comment|///   llvm::hash_code code = hash_value(x);
comment|/// \endcode
name|class
name|hash_code
block|{
name|size_t
name|value
decl_stmt|;
name|public
label|:
comment|/// \brief Default construct a hash_code.
comment|/// Note that this leaves the value uninitialized.
name|hash_code
argument_list|()
block|{}
comment|/// \brief Form a hash code directly from a numerical value.
name|hash_code
argument_list|(
argument|size_t value
argument_list|)
block|:
name|value
argument_list|(
argument|value
argument_list|)
block|{}
comment|/// \brief Convert the hash code to its numerical value for use.
comment|/*explicit*/
name|operator
name|size_t
argument_list|()
specifier|const
block|{
return|return
name|value
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|hash_code
operator|&
name|lhs
operator|,
specifier|const
name|hash_code
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|value
operator|==
name|rhs
operator|.
name|value
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|hash_code
operator|&
name|lhs
operator|,
specifier|const
name|hash_code
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|value
operator|!=
name|rhs
operator|.
name|value
return|;
block|}
comment|/// \brief Allow a hash_code to be directly run through hash_value.
name|friend
name|size_t
name|hash_value
parameter_list|(
specifier|const
name|hash_code
modifier|&
name|code
parameter_list|)
block|{
return|return
name|code
operator|.
name|value
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Compute a hash_code for any integer value.
comment|///
comment|/// Note that this function is intended to compute the same hash_code for
comment|/// a particular value without regard to the pre-promotion type. This is in
comment|/// contrast to hash_combine which may produce different hash_codes for
comment|/// differing argument types even if they would implicit promote to a common
comment|/// type without changing the value.
name|template
operator|<
name|typename
name|T
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|is_integral_or_enum
operator|<
name|T
operator|>
operator|::
name|value
operator|,
name|hash_code
operator|>
operator|::
name|type
name|hash_value
argument_list|(
argument|T value
argument_list|)
expr_stmt|;
comment|/// \brief Compute a hash_code for a pointer's address.
comment|///
comment|/// N.B.: This hashes the *address*. Not the value and not the type.
name|template
operator|<
name|typename
name|T
operator|>
name|hash_code
name|hash_value
argument_list|(
specifier|const
name|T
operator|*
name|ptr
argument_list|)
expr_stmt|;
comment|/// \brief Compute a hash_code for a pair of objects.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|hash_code
name|hash_value
argument_list|(
specifier|const
name|std
operator|::
name|pair
operator|<
name|T
argument_list|,
name|U
operator|>
operator|&
name|arg
argument_list|)
expr_stmt|;
comment|/// \brief Compute a hash_code for a standard string.
name|template
operator|<
name|typename
name|T
operator|>
name|hash_code
name|hash_value
argument_list|(
specifier|const
name|std
operator|::
name|basic_string
operator|<
name|T
operator|>
operator|&
name|arg
argument_list|)
expr_stmt|;
comment|/// \brief Override the execution seed with a fixed value.
comment|///
comment|/// This hashing library uses a per-execution seed designed to change on each
comment|/// run with high probability in order to ensure that the hash codes are not
comment|/// attackable and to ensure that output which is intended to be stable does
comment|/// not rely on the particulars of the hash codes produced.
comment|///
comment|/// That said, there are use cases where it is important to be able to
comment|/// reproduce *exactly* a specific behavior. To that end, we provide a function
comment|/// which will forcibly set the seed to a fixed value. This must be done at the
comment|/// start of the program, before any hashes are computed. Also, it cannot be
comment|/// undone. This makes it thread-hostile and very hard to use outside of
comment|/// immediately on start of a simple program designed for reproducible
comment|/// behavior.
name|void
name|set_fixed_execution_hash_seed
parameter_list|(
name|size_t
name|fixed_value
parameter_list|)
function_decl|;
comment|// All of the implementation details of actually computing the various hash
comment|// code values are held within this namespace. These routines are included in
comment|// the header file mainly to allow inlining and constant propagation.
name|namespace
name|hashing
block|{
name|namespace
name|detail
block|{
specifier|inline
name|uint64_t
name|fetch64
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
block|{
name|uint64_t
name|result
decl_stmt|;
name|memcpy
argument_list|(
operator|&
name|result
argument_list|,
name|p
argument_list|,
sizeof|sizeof
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|sys
operator|::
name|IsBigEndianHost
condition|)
name|sys
operator|::
name|swapByteOrder
argument_list|(
name|result
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
specifier|inline
name|uint32_t
name|fetch32
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
block|{
name|uint32_t
name|result
decl_stmt|;
name|memcpy
argument_list|(
operator|&
name|result
argument_list|,
name|p
argument_list|,
sizeof|sizeof
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|sys
operator|::
name|IsBigEndianHost
condition|)
name|sys
operator|::
name|swapByteOrder
argument_list|(
name|result
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
comment|/// Some primes between 2^63 and 2^64 for various uses.
specifier|static
specifier|const
name|uint64_t
name|k0
init|=
literal|0xc3a5c85c97cb3127ULL
decl_stmt|;
specifier|static
specifier|const
name|uint64_t
name|k1
init|=
literal|0xb492b66fbe98f273ULL
decl_stmt|;
specifier|static
specifier|const
name|uint64_t
name|k2
init|=
literal|0x9ae16a3b2f90404fULL
decl_stmt|;
specifier|static
specifier|const
name|uint64_t
name|k3
init|=
literal|0xc949d7c7509e6557ULL
decl_stmt|;
comment|/// \brief Bitwise right rotate.
comment|/// Normally this will compile to a single instruction, especially if the
comment|/// shift is a manifest constant.
specifier|inline
name|uint64_t
name|rotate
parameter_list|(
name|uint64_t
name|val
parameter_list|,
name|size_t
name|shift
parameter_list|)
block|{
comment|// Avoid shifting by 64: doing so yields an undefined result.
return|return
name|shift
operator|==
literal|0
condition|?
name|val
else|:
operator|(
operator|(
name|val
operator|>>
name|shift
operator|)
operator||
operator|(
name|val
operator|<<
operator|(
literal|64
operator|-
name|shift
operator|)
operator|)
operator|)
return|;
block|}
specifier|inline
name|uint64_t
name|shift_mix
parameter_list|(
name|uint64_t
name|val
parameter_list|)
block|{
return|return
name|val
operator|^
operator|(
name|val
operator|>>
literal|47
operator|)
return|;
block|}
specifier|inline
name|uint64_t
name|hash_16_bytes
parameter_list|(
name|uint64_t
name|low
parameter_list|,
name|uint64_t
name|high
parameter_list|)
block|{
comment|// Murmur-inspired hashing.
specifier|const
name|uint64_t
name|kMul
init|=
literal|0x9ddfea08eb382d69ULL
decl_stmt|;
name|uint64_t
name|a
init|=
operator|(
name|low
operator|^
name|high
operator|)
operator|*
name|kMul
decl_stmt|;
name|a
operator|^=
operator|(
name|a
operator|>>
literal|47
operator|)
expr_stmt|;
name|uint64_t
name|b
init|=
operator|(
name|high
operator|^
name|a
operator|)
operator|*
name|kMul
decl_stmt|;
name|b
operator|^=
operator|(
name|b
operator|>>
literal|47
operator|)
expr_stmt|;
name|b
operator|*=
name|kMul
expr_stmt|;
return|return
name|b
return|;
block|}
specifier|inline
name|uint64_t
name|hash_1to3_bytes
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|len
parameter_list|,
name|uint64_t
name|seed
parameter_list|)
block|{
name|uint8_t
name|a
init|=
name|s
index|[
literal|0
index|]
decl_stmt|;
name|uint8_t
name|b
init|=
name|s
index|[
name|len
operator|>>
literal|1
index|]
decl_stmt|;
name|uint8_t
name|c
init|=
name|s
index|[
name|len
operator|-
literal|1
index|]
decl_stmt|;
name|uint32_t
name|y
init|=
name|static_cast
operator|<
name|uint32_t
operator|>
operator|(
name|a
operator|)
operator|+
operator|(
name|static_cast
operator|<
name|uint32_t
operator|>
operator|(
name|b
operator|)
operator|<<
literal|8
operator|)
decl_stmt|;
name|uint32_t
name|z
init|=
name|len
operator|+
operator|(
name|static_cast
operator|<
name|uint32_t
operator|>
operator|(
name|c
operator|)
operator|<<
literal|2
operator|)
decl_stmt|;
return|return
name|shift_mix
argument_list|(
name|y
operator|*
name|k2
operator|^
name|z
operator|*
name|k3
operator|^
name|seed
argument_list|)
operator|*
name|k2
return|;
block|}
specifier|inline
name|uint64_t
name|hash_4to8_bytes
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|len
parameter_list|,
name|uint64_t
name|seed
parameter_list|)
block|{
name|uint64_t
name|a
init|=
name|fetch32
argument_list|(
name|s
argument_list|)
decl_stmt|;
return|return
name|hash_16_bytes
argument_list|(
name|len
operator|+
operator|(
name|a
operator|<<
literal|3
operator|)
argument_list|,
name|seed
operator|^
name|fetch32
argument_list|(
name|s
operator|+
name|len
operator|-
literal|4
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
name|uint64_t
name|hash_9to16_bytes
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|len
parameter_list|,
name|uint64_t
name|seed
parameter_list|)
block|{
name|uint64_t
name|a
init|=
name|fetch64
argument_list|(
name|s
argument_list|)
decl_stmt|;
name|uint64_t
name|b
init|=
name|fetch64
argument_list|(
name|s
operator|+
name|len
operator|-
literal|8
argument_list|)
decl_stmt|;
return|return
name|hash_16_bytes
argument_list|(
name|seed
operator|^
name|a
argument_list|,
name|rotate
argument_list|(
name|b
operator|+
name|len
argument_list|,
name|len
argument_list|)
argument_list|)
operator|^
name|b
return|;
block|}
specifier|inline
name|uint64_t
name|hash_17to32_bytes
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|len
parameter_list|,
name|uint64_t
name|seed
parameter_list|)
block|{
name|uint64_t
name|a
init|=
name|fetch64
argument_list|(
name|s
argument_list|)
operator|*
name|k1
decl_stmt|;
name|uint64_t
name|b
init|=
name|fetch64
argument_list|(
name|s
operator|+
literal|8
argument_list|)
decl_stmt|;
name|uint64_t
name|c
init|=
name|fetch64
argument_list|(
name|s
operator|+
name|len
operator|-
literal|8
argument_list|)
operator|*
name|k2
decl_stmt|;
name|uint64_t
name|d
init|=
name|fetch64
argument_list|(
name|s
operator|+
name|len
operator|-
literal|16
argument_list|)
operator|*
name|k0
decl_stmt|;
return|return
name|hash_16_bytes
argument_list|(
name|rotate
argument_list|(
name|a
operator|-
name|b
argument_list|,
literal|43
argument_list|)
operator|+
name|rotate
argument_list|(
name|c
operator|^
name|seed
argument_list|,
literal|30
argument_list|)
operator|+
name|d
argument_list|,
name|a
operator|+
name|rotate
argument_list|(
name|b
operator|^
name|k3
argument_list|,
literal|20
argument_list|)
operator|-
name|c
operator|+
name|len
operator|+
name|seed
argument_list|)
return|;
block|}
specifier|inline
name|uint64_t
name|hash_33to64_bytes
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|len
parameter_list|,
name|uint64_t
name|seed
parameter_list|)
block|{
name|uint64_t
name|z
init|=
name|fetch64
argument_list|(
name|s
operator|+
literal|24
argument_list|)
decl_stmt|;
name|uint64_t
name|a
init|=
name|fetch64
argument_list|(
name|s
argument_list|)
operator|+
operator|(
name|len
operator|+
name|fetch64
argument_list|(
name|s
operator|+
name|len
operator|-
literal|16
argument_list|)
operator|)
operator|*
name|k0
decl_stmt|;
name|uint64_t
name|b
init|=
name|rotate
argument_list|(
name|a
operator|+
name|z
argument_list|,
literal|52
argument_list|)
decl_stmt|;
name|uint64_t
name|c
init|=
name|rotate
argument_list|(
name|a
argument_list|,
literal|37
argument_list|)
decl_stmt|;
name|a
operator|+=
name|fetch64
argument_list|(
name|s
operator|+
literal|8
argument_list|)
expr_stmt|;
name|c
operator|+=
name|rotate
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|a
operator|+=
name|fetch64
argument_list|(
name|s
operator|+
literal|16
argument_list|)
expr_stmt|;
name|uint64_t
name|vf
init|=
name|a
operator|+
name|z
decl_stmt|;
name|uint64_t
name|vs
init|=
name|b
operator|+
name|rotate
argument_list|(
name|a
argument_list|,
literal|31
argument_list|)
operator|+
name|c
decl_stmt|;
name|a
operator|=
name|fetch64
argument_list|(
name|s
operator|+
literal|16
argument_list|)
operator|+
name|fetch64
argument_list|(
name|s
operator|+
name|len
operator|-
literal|32
argument_list|)
expr_stmt|;
name|z
operator|=
name|fetch64
argument_list|(
name|s
operator|+
name|len
operator|-
literal|8
argument_list|)
expr_stmt|;
name|b
operator|=
name|rotate
argument_list|(
name|a
operator|+
name|z
argument_list|,
literal|52
argument_list|)
expr_stmt|;
name|c
operator|=
name|rotate
argument_list|(
name|a
argument_list|,
literal|37
argument_list|)
expr_stmt|;
name|a
operator|+=
name|fetch64
argument_list|(
name|s
operator|+
name|len
operator|-
literal|24
argument_list|)
expr_stmt|;
name|c
operator|+=
name|rotate
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|a
operator|+=
name|fetch64
argument_list|(
name|s
operator|+
name|len
operator|-
literal|16
argument_list|)
expr_stmt|;
name|uint64_t
name|wf
init|=
name|a
operator|+
name|z
decl_stmt|;
name|uint64_t
name|ws
init|=
name|b
operator|+
name|rotate
argument_list|(
name|a
argument_list|,
literal|31
argument_list|)
operator|+
name|c
decl_stmt|;
name|uint64_t
name|r
init|=
name|shift_mix
argument_list|(
operator|(
name|vf
operator|+
name|ws
operator|)
operator|*
name|k2
operator|+
operator|(
name|wf
operator|+
name|vs
operator|)
operator|*
name|k0
argument_list|)
decl_stmt|;
return|return
name|shift_mix
argument_list|(
operator|(
name|seed
operator|^
operator|(
name|r
operator|*
name|k0
operator|)
operator|)
operator|+
name|vs
argument_list|)
operator|*
name|k2
return|;
block|}
specifier|inline
name|uint64_t
name|hash_short
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|length
parameter_list|,
name|uint64_t
name|seed
parameter_list|)
block|{
if|if
condition|(
name|length
operator|>=
literal|4
operator|&&
name|length
operator|<=
literal|8
condition|)
return|return
name|hash_4to8_bytes
argument_list|(
name|s
argument_list|,
name|length
argument_list|,
name|seed
argument_list|)
return|;
if|if
condition|(
name|length
operator|>
literal|8
operator|&&
name|length
operator|<=
literal|16
condition|)
return|return
name|hash_9to16_bytes
argument_list|(
name|s
argument_list|,
name|length
argument_list|,
name|seed
argument_list|)
return|;
if|if
condition|(
name|length
operator|>
literal|16
operator|&&
name|length
operator|<=
literal|32
condition|)
return|return
name|hash_17to32_bytes
argument_list|(
name|s
argument_list|,
name|length
argument_list|,
name|seed
argument_list|)
return|;
if|if
condition|(
name|length
operator|>
literal|32
condition|)
return|return
name|hash_33to64_bytes
argument_list|(
name|s
argument_list|,
name|length
argument_list|,
name|seed
argument_list|)
return|;
if|if
condition|(
name|length
operator|!=
literal|0
condition|)
return|return
name|hash_1to3_bytes
argument_list|(
name|s
argument_list|,
name|length
argument_list|,
name|seed
argument_list|)
return|;
return|return
name|k2
operator|^
name|seed
return|;
block|}
comment|/// \brief The intermediate state used during hashing.
comment|/// Currently, the algorithm for computing hash codes is based on CityHash and
comment|/// keeps 56 bytes of arbitrary state.
struct|struct
name|hash_state
block|{
name|uint64_t
name|h0
decl_stmt|,
name|h1
decl_stmt|,
name|h2
decl_stmt|,
name|h3
decl_stmt|,
name|h4
decl_stmt|,
name|h5
decl_stmt|,
name|h6
decl_stmt|;
comment|/// \brief Create a new hash_state structure and initialize it based on the
comment|/// seed and the first 64-byte chunk.
comment|/// This effectively performs the initial mix.
specifier|static
name|hash_state
name|create
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|uint64_t
name|seed
parameter_list|)
block|{
name|hash_state
name|state
init|=
block|{
literal|0
block|,
name|seed
block|,
name|hash_16_bytes
argument_list|(
name|seed
argument_list|,
name|k1
argument_list|)
block|,
name|rotate
argument_list|(
name|seed
operator|^
name|k1
argument_list|,
literal|49
argument_list|)
block|,
name|seed
operator|*
name|k1
block|,
name|shift_mix
argument_list|(
name|seed
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
name|state
operator|.
name|h6
operator|=
name|hash_16_bytes
argument_list|(
name|state
operator|.
name|h4
argument_list|,
name|state
operator|.
name|h5
argument_list|)
expr_stmt|;
name|state
operator|.
name|mix
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
name|state
return|;
block|}
comment|/// \brief Mix 32-bytes from the input sequence into the 16-bytes of 'a'
comment|/// and 'b', including whatever is already in 'a' and 'b'.
specifier|static
name|void
name|mix_32_bytes
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|uint64_t
modifier|&
name|a
parameter_list|,
name|uint64_t
modifier|&
name|b
parameter_list|)
block|{
name|a
operator|+=
name|fetch64
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|uint64_t
name|c
init|=
name|fetch64
argument_list|(
name|s
operator|+
literal|24
argument_list|)
decl_stmt|;
name|b
operator|=
name|rotate
argument_list|(
name|b
operator|+
name|a
operator|+
name|c
argument_list|,
literal|21
argument_list|)
expr_stmt|;
name|uint64_t
name|d
init|=
name|a
decl_stmt|;
name|a
operator|+=
name|fetch64
argument_list|(
name|s
operator|+
literal|8
argument_list|)
operator|+
name|fetch64
argument_list|(
name|s
operator|+
literal|16
argument_list|)
expr_stmt|;
name|b
operator|+=
name|rotate
argument_list|(
name|a
argument_list|,
literal|44
argument_list|)
operator|+
name|d
expr_stmt|;
name|a
operator|+=
name|c
expr_stmt|;
block|}
comment|/// \brief Mix in a 64-byte buffer of data.
comment|/// We mix all 64 bytes even when the chunk length is smaller, but we
comment|/// record the actual length.
name|void
name|mix
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
name|h0
operator|=
name|rotate
argument_list|(
name|h0
operator|+
name|h1
operator|+
name|h3
operator|+
name|fetch64
argument_list|(
name|s
operator|+
literal|8
argument_list|)
argument_list|,
literal|37
argument_list|)
operator|*
name|k1
expr_stmt|;
name|h1
operator|=
name|rotate
argument_list|(
name|h1
operator|+
name|h4
operator|+
name|fetch64
argument_list|(
name|s
operator|+
literal|48
argument_list|)
argument_list|,
literal|42
argument_list|)
operator|*
name|k1
expr_stmt|;
name|h0
operator|^=
name|h6
expr_stmt|;
name|h1
operator|+=
name|h3
operator|+
name|fetch64
argument_list|(
name|s
operator|+
literal|40
argument_list|)
expr_stmt|;
name|h2
operator|=
name|rotate
argument_list|(
name|h2
operator|+
name|h5
argument_list|,
literal|33
argument_list|)
operator|*
name|k1
expr_stmt|;
name|h3
operator|=
name|h4
operator|*
name|k1
expr_stmt|;
name|h4
operator|=
name|h0
operator|+
name|h5
expr_stmt|;
name|mix_32_bytes
argument_list|(
name|s
argument_list|,
name|h3
argument_list|,
name|h4
argument_list|)
expr_stmt|;
name|h5
operator|=
name|h2
operator|+
name|h6
expr_stmt|;
name|h6
operator|=
name|h1
operator|+
name|fetch64
argument_list|(
name|s
operator|+
literal|16
argument_list|)
expr_stmt|;
name|mix_32_bytes
argument_list|(
name|s
operator|+
literal|32
argument_list|,
name|h5
argument_list|,
name|h6
argument_list|)
expr_stmt|;
name|std
operator|::
name|swap
argument_list|(
name|h2
argument_list|,
name|h0
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Compute the final 64-bit hash code value based on the current
comment|/// state and the length of bytes hashed.
name|uint64_t
name|finalize
parameter_list|(
name|size_t
name|length
parameter_list|)
block|{
return|return
name|hash_16_bytes
argument_list|(
name|hash_16_bytes
argument_list|(
name|h3
argument_list|,
name|h5
argument_list|)
operator|+
name|shift_mix
argument_list|(
name|h1
argument_list|)
operator|*
name|k1
operator|+
name|h2
argument_list|,
name|hash_16_bytes
argument_list|(
name|h4
argument_list|,
name|h6
argument_list|)
operator|+
name|shift_mix
argument_list|(
name|length
argument_list|)
operator|*
name|k1
operator|+
name|h0
argument_list|)
return|;
block|}
block|}
struct|;
comment|/// \brief A global, fixed seed-override variable.
comment|///
comment|/// This variable can be set using the \see llvm::set_fixed_execution_seed
comment|/// function. See that function for details. Do not, under any circumstances,
comment|/// set or read this variable.
specifier|extern
name|size_t
name|fixed_seed_override
decl_stmt|;
specifier|inline
name|size_t
name|get_execution_seed
parameter_list|()
block|{
comment|// FIXME: This needs to be a per-execution seed. This is just a placeholder
comment|// implementation. Switching to a per-execution seed is likely to flush out
comment|// instability bugs and so will happen as its own commit.
comment|//
comment|// However, if there is a fixed seed override set the first time this is
comment|// called, return that instead of the per-execution seed.
specifier|const
name|uint64_t
name|seed_prime
init|=
literal|0xff51afd7ed558ccdULL
decl_stmt|;
specifier|static
name|size_t
name|seed
init|=
name|fixed_seed_override
condition|?
name|fixed_seed_override
else|:
operator|(
name|size_t
operator|)
name|seed_prime
decl_stmt|;
return|return
name|seed
return|;
block|}
comment|/// \brief Trait to indicate whether a type's bits can be hashed directly.
comment|///
comment|/// A type trait which is true if we want to combine values for hashing by
comment|/// reading the underlying data. It is false if values of this type must
comment|/// first be passed to hash_value, and the resulting hash_codes combined.
comment|//
comment|// FIXME: We want to replace is_integral_or_enum and is_pointer here with
comment|// a predicate which asserts that comparing the underlying storage of two
comment|// values of the type for equality is equivalent to comparing the two values
comment|// for equality. For all the platforms we care about, this holds for integers
comment|// and pointers, but there are platforms where it doesn't and we would like to
comment|// support user-defined types which happen to satisfy this property.
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_hashable_data
operator|:
name|std
operator|::
name|integral_constant
operator|<
name|bool
operator|,
operator|(
operator|(
name|is_integral_or_enum
operator|<
name|T
operator|>
operator|::
name|value
operator|||
name|std
operator|::
name|is_pointer
operator|<
name|T
operator|>
operator|::
name|value
operator|)
operator|&&
literal|64
operator|%
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|==
literal|0
operator|)
operator|>
block|{}
expr_stmt|;
comment|// Special case std::pair to detect when both types are viable and when there
comment|// is no alignment-derived padding in the pair. This is a bit of a lie because
comment|// std::pair isn't truly POD, but it's close enough in all reasonable
comment|// implementations for our use case of hashing the underlying data.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
expr|struct
name|is_hashable_data
operator|<
name|std
operator|::
name|pair
operator|<
name|T
operator|,
name|U
operator|>
expr|>
operator|:
name|std
operator|::
name|integral_constant
operator|<
name|bool
operator|,
operator|(
name|is_hashable_data
operator|<
name|T
operator|>
operator|::
name|value
operator|&&
name|is_hashable_data
operator|<
name|U
operator|>
operator|::
name|value
operator|&&
operator|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|U
argument_list|)
operator|)
operator|==
sizeof|sizeof
argument_list|(
name|std
operator|::
name|pair
operator|<
name|T
argument_list|,
name|U
operator|>
argument_list|)
operator|)
operator|>
block|{}
expr_stmt|;
comment|/// \brief Helper to get the hashable data representation for a type.
comment|/// This variant is enabled when the type itself can be used.
name|template
operator|<
name|typename
name|T
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|is_hashable_data
operator|<
name|T
operator|>
operator|::
name|value
operator|,
name|T
operator|>
operator|::
name|type
name|get_hashable_data
argument_list|(
argument|const T&value
argument_list|)
block|{
return|return
name|value
return|;
block|}
comment|/// \brief Helper to get the hashable data representation for a type.
comment|/// This variant is enabled when we must first call hash_value and use the
comment|/// result as our data.
name|template
operator|<
name|typename
name|T
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
operator|!
name|is_hashable_data
operator|<
name|T
operator|>
operator|::
name|value
operator|,
name|size_t
operator|>
operator|::
name|type
name|get_hashable_data
argument_list|(
argument|const T&value
argument_list|)
block|{
name|using
operator|::
name|llvm
operator|::
name|hash_value
block|;
return|return
name|hash_value
argument_list|(
name|value
argument_list|)
return|;
block|}
comment|/// \brief Helper to store data from a value into a buffer and advance the
comment|/// pointer into that buffer.
comment|///
comment|/// This routine first checks whether there is enough space in the provided
comment|/// buffer, and if not immediately returns false. If there is space, it
comment|/// copies the underlying bytes of value into the buffer, advances the
comment|/// buffer_ptr past the copied bytes, and returns true.
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|store_and_advance
argument_list|(
argument|char *&buffer_ptr
argument_list|,
argument|char *buffer_end
argument_list|,
argument|const T& value
argument_list|,
argument|size_t offset =
literal|0
argument_list|)
block|{
name|size_t
name|store_size
operator|=
sizeof|sizeof
argument_list|(
name|value
argument_list|)
operator|-
name|offset
block|;
if|if
condition|(
name|buffer_ptr
operator|+
name|store_size
operator|>
name|buffer_end
condition|)
return|return
name|false
return|;
specifier|const
name|char
operator|*
name|value_data
operator|=
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
operator|&
name|value
operator|)
expr_stmt|;
name|memcpy
argument_list|(
name|buffer_ptr
argument_list|,
name|value_data
operator|+
name|offset
argument_list|,
name|store_size
argument_list|)
expr_stmt|;
name|buffer_ptr
operator|+=
name|store_size
expr_stmt|;
return|return
name|true
return|;
block|}
comment|/// \brief Implement the combining of integral values into a hash_code.
comment|///
comment|/// This overload is selected when the value type of the iterator is
comment|/// integral. Rather than computing a hash_code for each object and then
comment|/// combining them, this (as an optimization) directly combines the integers.
name|template
operator|<
name|typename
name|InputIteratorT
operator|>
name|hash_code
name|hash_combine_range_impl
argument_list|(
argument|InputIteratorT first
argument_list|,
argument|InputIteratorT last
argument_list|)
block|{
specifier|const
name|size_t
name|seed
operator|=
name|get_execution_seed
argument_list|()
block|;
name|char
name|buffer
index|[
literal|64
index|]
block|,
operator|*
name|buffer_ptr
operator|=
name|buffer
block|;
name|char
operator|*
specifier|const
name|buffer_end
operator|=
name|std
operator|::
name|end
argument_list|(
name|buffer
argument_list|)
block|;
while|while
condition|(
name|first
operator|!=
name|last
operator|&&
name|store_and_advance
argument_list|(
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|get_hashable_data
argument_list|(
operator|*
name|first
argument_list|)
argument_list|)
condition|)
operator|++
name|first
expr_stmt|;
if|if
condition|(
name|first
operator|==
name|last
condition|)
return|return
name|hash_short
argument_list|(
name|buffer
argument_list|,
name|buffer_ptr
operator|-
name|buffer
argument_list|,
name|seed
argument_list|)
return|;
name|assert
argument_list|(
name|buffer_ptr
operator|==
name|buffer_end
argument_list|)
expr_stmt|;
name|hash_state
name|state
init|=
name|state
operator|.
name|create
argument_list|(
name|buffer
argument_list|,
name|seed
argument_list|)
decl_stmt|;
name|size_t
name|length
init|=
literal|64
decl_stmt|;
while|while
condition|(
name|first
operator|!=
name|last
condition|)
block|{
comment|// Fill up the buffer. We don't clear it, which re-mixes the last round
comment|// when only a partial 64-byte chunk is left.
name|buffer_ptr
operator|=
name|buffer
expr_stmt|;
while|while
condition|(
name|first
operator|!=
name|last
operator|&&
name|store_and_advance
argument_list|(
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|get_hashable_data
argument_list|(
operator|*
name|first
argument_list|)
argument_list|)
condition|)
operator|++
name|first
expr_stmt|;
comment|// Rotate the buffer if we did a partial fill in order to simulate doing
comment|// a mix of the last 64-bytes. That is how the algorithm works when we
comment|// have a contiguous byte sequence, and we want to emulate that here.
name|std
operator|::
name|rotate
argument_list|(
name|buffer
argument_list|,
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|)
expr_stmt|;
comment|// Mix this chunk into the current state.
name|state
operator|.
name|mix
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
name|length
operator|+=
name|buffer_ptr
operator|-
name|buffer
expr_stmt|;
block|}
empty_stmt|;
return|return
name|state
operator|.
name|finalize
argument_list|(
name|length
argument_list|)
return|;
block|}
comment|/// \brief Implement the combining of integral values into a hash_code.
comment|///
comment|/// This overload is selected when the value type of the iterator is integral
comment|/// and when the input iterator is actually a pointer. Rather than computing
comment|/// a hash_code for each object and then combining them, this (as an
comment|/// optimization) directly combines the integers. Also, because the integers
comment|/// are stored in contiguous memory, this routine avoids copying each value
comment|/// and directly reads from the underlying memory.
name|template
operator|<
name|typename
name|ValueT
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|is_hashable_data
operator|<
name|ValueT
operator|>
operator|::
name|value
operator|,
name|hash_code
operator|>
operator|::
name|type
name|hash_combine_range_impl
argument_list|(
argument|ValueT *first
argument_list|,
argument|ValueT *last
argument_list|)
block|{
specifier|const
name|size_t
name|seed
operator|=
name|get_execution_seed
argument_list|()
block|;
specifier|const
name|char
operator|*
name|s_begin
operator|=
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|first
operator|)
block|;
specifier|const
name|char
operator|*
name|s_end
operator|=
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|last
operator|)
block|;
specifier|const
name|size_t
name|length
operator|=
name|std
operator|::
name|distance
argument_list|(
name|s_begin
argument_list|,
name|s_end
argument_list|)
block|;
if|if
condition|(
name|length
operator|<=
literal|64
condition|)
return|return
name|hash_short
argument_list|(
name|s_begin
argument_list|,
name|length
argument_list|,
name|seed
argument_list|)
return|;
specifier|const
name|char
operator|*
name|s_aligned_end
operator|=
name|s_begin
operator|+
operator|(
name|length
operator|&
operator|~
literal|63
operator|)
expr_stmt|;
name|hash_state
name|state
init|=
name|state
operator|.
name|create
argument_list|(
name|s_begin
argument_list|,
name|seed
argument_list|)
decl_stmt|;
name|s_begin
operator|+=
literal|64
expr_stmt|;
while|while
condition|(
name|s_begin
operator|!=
name|s_aligned_end
condition|)
block|{
name|state
operator|.
name|mix
argument_list|(
name|s_begin
argument_list|)
expr_stmt|;
name|s_begin
operator|+=
literal|64
expr_stmt|;
block|}
if|if
condition|(
name|length
operator|&
literal|63
condition|)
name|state
operator|.
name|mix
argument_list|(
name|s_end
operator|-
literal|64
argument_list|)
expr_stmt|;
return|return
name|state
operator|.
name|finalize
argument_list|(
name|length
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
unit|}
comment|// namespace detail
end_comment

begin_comment
unit|}
comment|// namespace hashing
end_comment

begin_comment
comment|/// \brief Compute a hash_code for a sequence of values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This hashes a sequence of values. It produces the same hash_code as
end_comment

begin_comment
comment|/// 'hash_combine(a, b, c, ...)', but can run over arbitrary sized sequences
end_comment

begin_comment
comment|/// and is significantly faster given pointers and types which can be hashed as
end_comment

begin_comment
comment|/// a sequence of bytes.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|InputIteratorT
operator|>
name|hash_code
name|hash_combine_range
argument_list|(
argument|InputIteratorT first
argument_list|,
argument|InputIteratorT last
argument_list|)
block|{
return|return
operator|::
name|llvm
operator|::
name|hashing
operator|::
name|detail
operator|::
name|hash_combine_range_impl
argument_list|(
name|first
argument_list|,
name|last
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Implementation details for hash_combine.
end_comment

begin_decl_stmt
name|namespace
name|hashing
block|{
name|namespace
name|detail
block|{
comment|/// \brief Helper class to manage the recursive combining of hash_combine
comment|/// arguments.
comment|///
comment|/// This class exists to manage the state and various calls involved in the
comment|/// recursive combining of arguments used in hash_combine. It is particularly
comment|/// useful at minimizing the code in the recursive calls to ease the pain
comment|/// caused by a lack of variadic functions.
struct|struct
name|hash_combine_recursive_helper
block|{
name|char
name|buffer
index|[
literal|64
index|]
decl_stmt|;
name|hash_state
name|state
decl_stmt|;
specifier|const
name|size_t
name|seed
decl_stmt|;
name|public
label|:
comment|/// \brief Construct a recursive hash combining helper.
comment|///
comment|/// This sets up the state for a recursive hash combine, including getting
comment|/// the seed and buffer setup.
name|hash_combine_recursive_helper
argument_list|()
operator|:
name|seed
argument_list|(
argument|get_execution_seed()
argument_list|)
block|{}
comment|/// \brief Combine one chunk of data into the current in-flight hash.
comment|///
comment|/// This merges one chunk of data into the hash. First it tries to buffer
comment|/// the data. If the buffer is full, it hashes the buffer into its
comment|/// hash_state, empties it, and then merges the new chunk in. This also
comment|/// handles cases where the data straddles the end of the buffer.
name|template
operator|<
name|typename
name|T
operator|>
name|char
operator|*
name|combine_data
argument_list|(
argument|size_t&length
argument_list|,
argument|char *buffer_ptr
argument_list|,
argument|char *buffer_end
argument_list|,
argument|T data
argument_list|)
block|{
if|if
condition|(
operator|!
name|store_and_advance
argument_list|(
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|data
argument_list|)
condition|)
block|{
comment|// Check for skew which prevents the buffer from being packed, and do
comment|// a partial store into the buffer to fill it. This is only a concern
comment|// with the variadic combine because that formation can have varying
comment|// argument types.
name|size_t
name|partial_store_size
init|=
name|buffer_end
operator|-
name|buffer_ptr
decl_stmt|;
name|memcpy
argument_list|(
name|buffer_ptr
argument_list|,
operator|&
name|data
argument_list|,
name|partial_store_size
argument_list|)
expr_stmt|;
comment|// If the store fails, our buffer is full and ready to hash. We have to
comment|// either initialize the hash state (on the first full buffer) or mix
comment|// this buffer into the existing hash state. Length tracks the *hashed*
comment|// length, not the buffered length.
if|if
condition|(
name|length
operator|==
literal|0
condition|)
block|{
name|state
operator|=
name|state
operator|.
name|create
argument_list|(
name|buffer
argument_list|,
name|seed
argument_list|)
expr_stmt|;
name|length
operator|=
literal|64
expr_stmt|;
block|}
else|else
block|{
comment|// Mix this chunk into the current state and bump length up by 64.
name|state
operator|.
name|mix
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
name|length
operator|+=
literal|64
expr_stmt|;
block|}
comment|// Reset the buffer_ptr to the head of the buffer for the next chunk of
comment|// data.
name|buffer_ptr
operator|=
name|buffer
expr_stmt|;
comment|// Try again to store into the buffer -- this cannot fail as we only
comment|// store types smaller than the buffer.
if|if
condition|(
operator|!
name|store_and_advance
argument_list|(
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|data
argument_list|,
name|partial_store_size
argument_list|)
condition|)
name|abort
argument_list|()
expr_stmt|;
block|}
return|return
name|buffer_ptr
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|__has_feature
argument_list|)
operator|&&
name|__has_feature
argument_list|(
name|__cxx_variadic_templates__
argument_list|)
comment|/// \brief Recursive, variadic combining method.
comment|///
comment|/// This function recurses through each argument, combining that argument
comment|/// into a single hash.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
operator|...
name|Ts
operator|>
name|hash_code
name|combine
argument_list|(
argument|size_t length
argument_list|,
argument|char *buffer_ptr
argument_list|,
argument|char *buffer_end
argument_list|,
argument|const T&arg
argument_list|,
argument|const Ts&...args
argument_list|)
block|{
name|buffer_ptr
operator|=
name|combine_data
argument_list|(
name|length
argument_list|,
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|get_hashable_data
argument_list|(
name|arg
argument_list|)
argument_list|)
block|;
comment|// Recurse to the next argument.
return|return
name|combine
argument_list|(
name|length
argument_list|,
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|args
operator|...
argument_list|)
return|;
block|}
else|#
directive|else
comment|// Manually expanded recursive combining methods. See variadic above for
comment|// documentation.
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|,
name|typename
name|T6
operator|>
name|hash_code
name|combine
argument_list|(
argument|size_t length
argument_list|,
argument|char *buffer_ptr
argument_list|,
argument|char *buffer_end
argument_list|,
argument|const T1&arg1
argument_list|,
argument|const T2&arg2
argument_list|,
argument|const T3&arg3
argument_list|,
argument|const T4&arg4
argument_list|,
argument|const T5&arg5
argument_list|,
argument|const T6&arg6
argument_list|)
block|{
name|buffer_ptr
operator|=
name|combine_data
argument_list|(
name|length
argument_list|,
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|get_hashable_data
argument_list|(
name|arg1
argument_list|)
argument_list|)
block|;
return|return
name|combine
argument_list|(
name|length
argument_list|,
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|,
name|arg4
argument_list|,
name|arg5
argument_list|,
name|arg6
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|>
name|hash_code
name|combine
argument_list|(
argument|size_t length
argument_list|,
argument|char *buffer_ptr
argument_list|,
argument|char *buffer_end
argument_list|,
argument|const T1&arg1
argument_list|,
argument|const T2&arg2
argument_list|,
argument|const T3&arg3
argument_list|,
argument|const T4&arg4
argument_list|,
argument|const T5&arg5
argument_list|)
block|{
name|buffer_ptr
operator|=
name|combine_data
argument_list|(
name|length
argument_list|,
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|get_hashable_data
argument_list|(
name|arg1
argument_list|)
argument_list|)
block|;
return|return
name|combine
argument_list|(
name|length
argument_list|,
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|,
name|arg4
argument_list|,
name|arg5
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|>
name|hash_code
name|combine
argument_list|(
argument|size_t length
argument_list|,
argument|char *buffer_ptr
argument_list|,
argument|char *buffer_end
argument_list|,
argument|const T1&arg1
argument_list|,
argument|const T2&arg2
argument_list|,
argument|const T3&arg3
argument_list|,
argument|const T4&arg4
argument_list|)
block|{
name|buffer_ptr
operator|=
name|combine_data
argument_list|(
name|length
argument_list|,
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|get_hashable_data
argument_list|(
name|arg1
argument_list|)
argument_list|)
block|;
return|return
name|combine
argument_list|(
name|length
argument_list|,
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|,
name|arg4
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|>
name|hash_code
name|combine
argument_list|(
argument|size_t length
argument_list|,
argument|char *buffer_ptr
argument_list|,
argument|char *buffer_end
argument_list|,
argument|const T1&arg1
argument_list|,
argument|const T2&arg2
argument_list|,
argument|const T3&arg3
argument_list|)
block|{
name|buffer_ptr
operator|=
name|combine_data
argument_list|(
name|length
argument_list|,
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|get_hashable_data
argument_list|(
name|arg1
argument_list|)
argument_list|)
block|;
return|return
name|combine
argument_list|(
name|length
argument_list|,
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|hash_code
name|combine
argument_list|(
argument|size_t length
argument_list|,
argument|char *buffer_ptr
argument_list|,
argument|char *buffer_end
argument_list|,
argument|const T1&arg1
argument_list|,
argument|const T2&arg2
argument_list|)
block|{
name|buffer_ptr
operator|=
name|combine_data
argument_list|(
name|length
argument_list|,
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|get_hashable_data
argument_list|(
name|arg1
argument_list|)
argument_list|)
block|;
return|return
name|combine
argument_list|(
name|length
argument_list|,
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|arg2
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T1
operator|>
name|hash_code
name|combine
argument_list|(
argument|size_t length
argument_list|,
argument|char *buffer_ptr
argument_list|,
argument|char *buffer_end
argument_list|,
argument|const T1&arg1
argument_list|)
block|{
name|buffer_ptr
operator|=
name|combine_data
argument_list|(
name|length
argument_list|,
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|,
name|get_hashable_data
argument_list|(
name|arg1
argument_list|)
argument_list|)
block|;
return|return
name|combine
argument_list|(
name|length
argument_list|,
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|/// \brief Base case for recursive, variadic combining.
comment|///
comment|/// The base case when combining arguments recursively is reached when all
comment|/// arguments have been handled. It flushes the remaining buffer and
comment|/// constructs a hash_code.
name|hash_code
name|combine
parameter_list|(
name|size_t
name|length
parameter_list|,
name|char
modifier|*
name|buffer_ptr
parameter_list|,
name|char
modifier|*
name|buffer_end
parameter_list|)
block|{
comment|// Check whether the entire set of values fit in the buffer. If so, we'll
comment|// use the optimized short hashing routine and skip state entirely.
if|if
condition|(
name|length
operator|==
literal|0
condition|)
return|return
name|hash_short
argument_list|(
name|buffer
argument_list|,
name|buffer_ptr
operator|-
name|buffer
argument_list|,
name|seed
argument_list|)
return|;
comment|// Mix the final buffer, rotating it if we did a partial fill in order to
comment|// simulate doing a mix of the last 64-bytes. That is how the algorithm
comment|// works when we have a contiguous byte sequence, and we want to emulate
comment|// that here.
name|std
operator|::
name|rotate
argument_list|(
name|buffer
argument_list|,
name|buffer_ptr
argument_list|,
name|buffer_end
argument_list|)
expr_stmt|;
comment|// Mix this chunk into the current state.
name|state
operator|.
name|mix
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
name|length
operator|+=
name|buffer_ptr
operator|-
name|buffer
expr_stmt|;
return|return
name|state
operator|.
name|finalize
argument_list|(
name|length
argument_list|)
return|;
block|}
block|}
struct|;
block|}
comment|// namespace detail
block|}
end_decl_stmt

begin_comment
comment|// namespace hashing
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|__cxx_variadic_templates__
argument_list|)
end_if

begin_comment
comment|/// \brief Combine values into a single hash_code.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine accepts a varying number of arguments of any type. It will
end_comment

begin_comment
comment|/// attempt to combine them into a single hash_code. For user-defined types it
end_comment

begin_comment
comment|/// attempts to call a \see hash_value overload (via ADL) for the type. For
end_comment

begin_comment
comment|/// integer and pointer types it directly combines their data into the
end_comment

begin_comment
comment|/// resulting hash_code.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The result is suitable for returning from a user's hash_value
end_comment

begin_comment
comment|/// *implementation* for their user-defined type. Consumers of a type should
end_comment

begin_comment
comment|/// *not* call this routine, they should instead call 'hash_value'.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
name|hash_code
name|hash_combine
argument_list|(
argument|const Ts&...args
argument_list|)
block|{
comment|// Recursively hash each argument using a helper class.
operator|::
name|llvm
operator|::
name|hashing
operator|::
name|detail
operator|::
name|hash_combine_recursive_helper
name|helper
block|;
return|return
name|helper
operator|.
name|combine
argument_list|(
literal|0
argument_list|,
name|helper
operator|.
name|buffer
argument_list|,
name|helper
operator|.
name|buffer
operator|+
literal|64
argument_list|,
name|args
operator|...
argument_list|)
return|;
block|}
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|// What follows are manually exploded overloads for each argument width. See
end_comment

begin_comment
comment|// the above variadic definition for documentation and specification.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|,
name|typename
name|T6
operator|>
name|hash_code
name|hash_combine
argument_list|(
argument|const T1&arg1
argument_list|,
argument|const T2&arg2
argument_list|,
argument|const T3&arg3
argument_list|,
argument|const T4&arg4
argument_list|,
argument|const T5&arg5
argument_list|,
argument|const T6&arg6
argument_list|)
block|{
operator|::
name|llvm
operator|::
name|hashing
operator|::
name|detail
operator|::
name|hash_combine_recursive_helper
name|helper
block|;
return|return
name|helper
operator|.
name|combine
argument_list|(
literal|0
argument_list|,
name|helper
operator|.
name|buffer
argument_list|,
name|helper
operator|.
name|buffer
operator|+
literal|64
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|,
name|arg4
argument_list|,
name|arg5
argument_list|,
name|arg6
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|>
name|hash_code
name|hash_combine
argument_list|(
argument|const T1&arg1
argument_list|,
argument|const T2&arg2
argument_list|,
argument|const T3&arg3
argument_list|,
argument|const T4&arg4
argument_list|,
argument|const T5&arg5
argument_list|)
block|{
operator|::
name|llvm
operator|::
name|hashing
operator|::
name|detail
operator|::
name|hash_combine_recursive_helper
name|helper
block|;
return|return
name|helper
operator|.
name|combine
argument_list|(
literal|0
argument_list|,
name|helper
operator|.
name|buffer
argument_list|,
name|helper
operator|.
name|buffer
operator|+
literal|64
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|,
name|arg4
argument_list|,
name|arg5
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|>
name|hash_code
name|hash_combine
argument_list|(
argument|const T1&arg1
argument_list|,
argument|const T2&arg2
argument_list|,
argument|const T3&arg3
argument_list|,
argument|const T4&arg4
argument_list|)
block|{
operator|::
name|llvm
operator|::
name|hashing
operator|::
name|detail
operator|::
name|hash_combine_recursive_helper
name|helper
block|;
return|return
name|helper
operator|.
name|combine
argument_list|(
literal|0
argument_list|,
name|helper
operator|.
name|buffer
argument_list|,
name|helper
operator|.
name|buffer
operator|+
literal|64
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|,
name|arg4
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|>
name|hash_code
name|hash_combine
argument_list|(
argument|const T1&arg1
argument_list|,
argument|const T2&arg2
argument_list|,
argument|const T3&arg3
argument_list|)
block|{
operator|::
name|llvm
operator|::
name|hashing
operator|::
name|detail
operator|::
name|hash_combine_recursive_helper
name|helper
block|;
return|return
name|helper
operator|.
name|combine
argument_list|(
literal|0
argument_list|,
name|helper
operator|.
name|buffer
argument_list|,
name|helper
operator|.
name|buffer
operator|+
literal|64
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|hash_code
name|hash_combine
argument_list|(
argument|const T1&arg1
argument_list|,
argument|const T2&arg2
argument_list|)
block|{
operator|::
name|llvm
operator|::
name|hashing
operator|::
name|detail
operator|::
name|hash_combine_recursive_helper
name|helper
block|;
return|return
name|helper
operator|.
name|combine
argument_list|(
literal|0
argument_list|,
name|helper
operator|.
name|buffer
argument_list|,
name|helper
operator|.
name|buffer
operator|+
literal|64
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|>
name|hash_code
name|hash_combine
argument_list|(
argument|const T1&arg1
argument_list|)
block|{
operator|::
name|llvm
operator|::
name|hashing
operator|::
name|detail
operator|::
name|hash_combine_recursive_helper
name|helper
block|;
return|return
name|helper
operator|.
name|combine
argument_list|(
literal|0
argument_list|,
name|helper
operator|.
name|buffer
argument_list|,
name|helper
operator|.
name|buffer
operator|+
literal|64
argument_list|,
name|arg1
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Implementation details for implementations of hash_value overloads provided
end_comment

begin_comment
comment|// here.
end_comment

begin_decl_stmt
name|namespace
name|hashing
block|{
name|namespace
name|detail
block|{
comment|/// \brief Helper to hash the value of a single integer.
comment|///
comment|/// Overloads for smaller integer types are not provided to ensure consistent
comment|/// behavior in the presence of integral promotions. Essentially,
comment|/// "hash_value('4')" and "hash_value('0' + 4)" should be the same.
specifier|inline
name|hash_code
name|hash_integer_value
parameter_list|(
name|uint64_t
name|value
parameter_list|)
block|{
comment|// Similar to hash_4to8_bytes but using a seed instead of length.
specifier|const
name|uint64_t
name|seed
init|=
name|get_execution_seed
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|s
init|=
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
operator|&
name|value
operator|)
decl_stmt|;
specifier|const
name|uint64_t
name|a
init|=
name|fetch32
argument_list|(
name|s
argument_list|)
decl_stmt|;
return|return
name|hash_16_bytes
argument_list|(
name|seed
operator|+
operator|(
name|a
operator|<<
literal|3
operator|)
argument_list|,
name|fetch32
argument_list|(
name|s
operator|+
literal|4
argument_list|)
argument_list|)
return|;
block|}
block|}
comment|// namespace detail
block|}
end_decl_stmt

begin_comment
comment|// namespace hashing
end_comment

begin_comment
comment|// Declared and documented above, but defined here so that any of the hashing
end_comment

begin_comment
comment|// infrastructure is available.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|is_integral_or_enum
operator|<
name|T
operator|>
operator|::
name|value
operator|,
name|hash_code
operator|>
operator|::
name|type
name|hash_value
argument_list|(
argument|T value
argument_list|)
block|{
return|return
operator|::
name|llvm
operator|::
name|hashing
operator|::
name|detail
operator|::
name|hash_integer_value
argument_list|(
name|value
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Declared and documented above, but defined here so that any of the hashing
end_comment

begin_comment
comment|// infrastructure is available.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|hash_code
name|hash_value
argument_list|(
argument|const T *ptr
argument_list|)
block|{
return|return
operator|::
name|llvm
operator|::
name|hashing
operator|::
name|detail
operator|::
name|hash_integer_value
argument_list|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|ptr
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Declared and documented above, but defined here so that any of the hashing
end_comment

begin_comment
comment|// infrastructure is available.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|hash_code
name|hash_value
argument_list|(
argument|const std::pair<T
argument_list|,
argument|U>&arg
argument_list|)
block|{
return|return
name|hash_combine
argument_list|(
name|arg
operator|.
name|first
argument_list|,
name|arg
operator|.
name|second
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Declared and documented above, but defined here so that any of the hashing
end_comment

begin_comment
comment|// infrastructure is available.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|hash_code
name|hash_value
argument_list|(
argument|const std::basic_string<T>&arg
argument_list|)
block|{
return|return
name|hash_combine_range
argument_list|(
name|arg
operator|.
name|begin
argument_list|()
argument_list|,
name|arg
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

