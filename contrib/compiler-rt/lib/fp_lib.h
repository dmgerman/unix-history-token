begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/fp_lib.h - Floating-point utilities -------------------*- C -*-===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
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
comment|// This file is a configuration header for soft-float routines in compiler-rt.
end_comment

begin_comment
comment|// This file does not provide any part of the compiler-rt interface, but defines
end_comment

begin_comment
comment|// many useful constants and utility routines that are used in the
end_comment

begin_comment
comment|// implementation of the soft-float routines in compiler-rt.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Assumes that float and double correspond to the IEEE-754 binary32 and
end_comment

begin_comment
comment|// binary64 types, respectively, and that integer endianness matches floating
end_comment

begin_comment
comment|// point endianness on the target platform.
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
name|FP_LIB_HEADER
end_ifndef

begin_define
define|#
directive|define
name|FP_LIB_HEADER
end_define

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_if
if|#
directive|if
name|defined
name|SINGLE_PRECISION
end_if

begin_typedef
typedef|typedef
name|uint32_t
name|rep_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|srep_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|fp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|REP_C
value|UINT32_C
end_define

begin_define
define|#
directive|define
name|significandBits
value|23
end_define

begin_function
specifier|static
specifier|inline
name|int
name|rep_clz
parameter_list|(
name|rep_t
name|a
parameter_list|)
block|{
return|return
name|__builtin_clz
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// 32x32 --> 64 bit multiply
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|wideMultiply
parameter_list|(
name|rep_t
name|a
parameter_list|,
name|rep_t
name|b
parameter_list|,
name|rep_t
modifier|*
name|hi
parameter_list|,
name|rep_t
modifier|*
name|lo
parameter_list|)
block|{
specifier|const
name|uint64_t
name|product
init|=
operator|(
name|uint64_t
operator|)
name|a
operator|*
name|b
decl_stmt|;
operator|*
name|hi
operator|=
name|product
operator|>>
literal|32
expr_stmt|;
operator|*
name|lo
operator|=
name|product
expr_stmt|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
name|DOUBLE_PRECISION
end_elif

begin_typedef
typedef|typedef
name|uint64_t
name|rep_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|srep_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|fp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|REP_C
value|UINT64_C
end_define

begin_define
define|#
directive|define
name|significandBits
value|52
end_define

begin_function
specifier|static
specifier|inline
name|int
name|rep_clz
parameter_list|(
name|rep_t
name|a
parameter_list|)
block|{
if|#
directive|if
name|defined
name|__LP64__
return|return
name|__builtin_clzl
argument_list|(
name|a
argument_list|)
return|;
else|#
directive|else
if|if
condition|(
name|a
operator|&
name|REP_C
argument_list|(
literal|0xffffffff00000000
argument_list|)
condition|)
return|return
name|__builtin_clz
argument_list|(
name|a
operator|>>
literal|32
argument_list|)
return|;
else|else
return|return
literal|32
operator|+
name|__builtin_clz
argument_list|(
name|a
operator|&
name|REP_C
argument_list|(
literal|0xffffffff
argument_list|)
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function

begin_define
define|#
directive|define
name|loWord
parameter_list|(
name|a
parameter_list|)
value|(a& 0xffffffffU)
end_define

begin_define
define|#
directive|define
name|hiWord
parameter_list|(
name|a
parameter_list|)
value|(a>> 32)
end_define

begin_comment
comment|// 64x64 -> 128 wide multiply for platforms that don't have such an operation;
end_comment

begin_comment
comment|// many 64-bit platforms have this operation, but they tend to have hardware
end_comment

begin_comment
comment|// floating-point, so we don't bother with a special case for them here.
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|wideMultiply
parameter_list|(
name|rep_t
name|a
parameter_list|,
name|rep_t
name|b
parameter_list|,
name|rep_t
modifier|*
name|hi
parameter_list|,
name|rep_t
modifier|*
name|lo
parameter_list|)
block|{
comment|// Each of the component 32x32 -> 64 products
specifier|const
name|uint64_t
name|plolo
init|=
name|loWord
argument_list|(
name|a
argument_list|)
operator|*
name|loWord
argument_list|(
name|b
argument_list|)
decl_stmt|;
specifier|const
name|uint64_t
name|plohi
init|=
name|loWord
argument_list|(
name|a
argument_list|)
operator|*
name|hiWord
argument_list|(
name|b
argument_list|)
decl_stmt|;
specifier|const
name|uint64_t
name|philo
init|=
name|hiWord
argument_list|(
name|a
argument_list|)
operator|*
name|loWord
argument_list|(
name|b
argument_list|)
decl_stmt|;
specifier|const
name|uint64_t
name|phihi
init|=
name|hiWord
argument_list|(
name|a
argument_list|)
operator|*
name|hiWord
argument_list|(
name|b
argument_list|)
decl_stmt|;
comment|// Sum terms that contribute to lo in a way that allows us to get the carry
specifier|const
name|uint64_t
name|r0
init|=
name|loWord
argument_list|(
name|plolo
argument_list|)
decl_stmt|;
specifier|const
name|uint64_t
name|r1
init|=
name|hiWord
argument_list|(
name|plolo
argument_list|)
operator|+
name|loWord
argument_list|(
name|plohi
argument_list|)
operator|+
name|loWord
argument_list|(
name|philo
argument_list|)
decl_stmt|;
operator|*
name|lo
operator|=
name|r0
operator|+
operator|(
name|r1
operator|<<
literal|32
operator|)
expr_stmt|;
comment|// Sum terms contributing to hi with the carry from lo
operator|*
name|hi
operator|=
name|hiWord
argument_list|(
name|plohi
argument_list|)
operator|+
name|hiWord
argument_list|(
name|philo
argument_list|)
operator|+
name|hiWord
argument_list|(
name|r1
argument_list|)
operator|+
name|phihi
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Either SINGLE_PRECISION or DOUBLE_PRECISION must be defined.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|typeWidth
value|(sizeof(rep_t)*CHAR_BIT)
end_define

begin_define
define|#
directive|define
name|exponentBits
value|(typeWidth - significandBits - 1)
end_define

begin_define
define|#
directive|define
name|maxExponent
value|((1<< exponentBits) - 1)
end_define

begin_define
define|#
directive|define
name|exponentBias
value|(maxExponent>> 1)
end_define

begin_define
define|#
directive|define
name|implicitBit
value|(REP_C(1)<< significandBits)
end_define

begin_define
define|#
directive|define
name|significandMask
value|(implicitBit - 1U)
end_define

begin_define
define|#
directive|define
name|signBit
value|(REP_C(1)<< (significandBits + exponentBits))
end_define

begin_define
define|#
directive|define
name|absMask
value|(signBit - 1U)
end_define

begin_define
define|#
directive|define
name|exponentMask
value|(absMask ^ significandMask)
end_define

begin_define
define|#
directive|define
name|oneRep
value|((rep_t)exponentBias<< significandBits)
end_define

begin_define
define|#
directive|define
name|infRep
value|exponentMask
end_define

begin_define
define|#
directive|define
name|quietBit
value|(implicitBit>> 1)
end_define

begin_define
define|#
directive|define
name|qnanRep
value|(exponentMask | quietBit)
end_define

begin_function
specifier|static
specifier|inline
name|rep_t
name|toRep
parameter_list|(
name|fp_t
name|x
parameter_list|)
block|{
specifier|const
union|union
block|{
name|fp_t
name|f
decl_stmt|;
name|rep_t
name|i
decl_stmt|;
block|}
name|rep
init|=
block|{
operator|.
name|f
operator|=
name|x
block|}
union|;
return|return
name|rep
operator|.
name|i
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|fp_t
name|fromRep
parameter_list|(
name|rep_t
name|x
parameter_list|)
block|{
specifier|const
union|union
block|{
name|fp_t
name|f
decl_stmt|;
name|rep_t
name|i
decl_stmt|;
block|}
name|rep
init|=
block|{
operator|.
name|i
operator|=
name|x
block|}
union|;
return|return
name|rep
operator|.
name|f
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|normalize
parameter_list|(
name|rep_t
modifier|*
name|significand
parameter_list|)
block|{
specifier|const
name|int
name|shift
init|=
name|rep_clz
argument_list|(
operator|*
name|significand
argument_list|)
operator|-
name|rep_clz
argument_list|(
name|implicitBit
argument_list|)
decl_stmt|;
operator|*
name|significand
operator|<<=
name|shift
expr_stmt|;
return|return
literal|1
operator|-
name|shift
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wideLeftShift
parameter_list|(
name|rep_t
modifier|*
name|hi
parameter_list|,
name|rep_t
modifier|*
name|lo
parameter_list|,
name|int
name|count
parameter_list|)
block|{
operator|*
name|hi
operator|=
operator|*
name|hi
operator|<<
name|count
operator||
operator|*
name|lo
operator|>>
operator|(
name|typeWidth
operator|-
name|count
operator|)
expr_stmt|;
operator|*
name|lo
operator|=
operator|*
name|lo
operator|<<
name|count
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wideRightShiftWithSticky
parameter_list|(
name|rep_t
modifier|*
name|hi
parameter_list|,
name|rep_t
modifier|*
name|lo
parameter_list|,
name|unsigned
name|int
name|count
parameter_list|)
block|{
if|if
condition|(
name|count
operator|<
name|typeWidth
condition|)
block|{
specifier|const
name|bool
name|sticky
init|=
operator|*
name|lo
operator|<<
operator|(
name|typeWidth
operator|-
name|count
operator|)
decl_stmt|;
operator|*
name|lo
operator|=
operator|*
name|hi
operator|<<
operator|(
name|typeWidth
operator|-
name|count
operator|)
operator||
operator|*
name|lo
operator|>>
name|count
operator||
name|sticky
expr_stmt|;
operator|*
name|hi
operator|=
operator|*
name|hi
operator|>>
name|count
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|count
operator|<
literal|2
operator|*
name|typeWidth
condition|)
block|{
specifier|const
name|bool
name|sticky
init|=
operator|*
name|hi
operator|<<
operator|(
literal|2
operator|*
name|typeWidth
operator|-
name|count
operator|)
operator||
operator|*
name|lo
decl_stmt|;
operator|*
name|lo
operator|=
operator|*
name|hi
operator|>>
operator|(
name|count
operator|-
name|typeWidth
operator|)
operator||
name|sticky
expr_stmt|;
operator|*
name|hi
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|bool
name|sticky
init|=
operator|*
name|hi
operator||
operator|*
name|lo
decl_stmt|;
operator|*
name|lo
operator|=
name|sticky
expr_stmt|;
operator|*
name|hi
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// FP_LIB_HEADER
end_comment

end_unit

