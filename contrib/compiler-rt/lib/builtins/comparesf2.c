begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/comparesf2.c - Single-precision comparisons -----------*- C -*-===//
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
comment|// This file implements the following soft-fp_t comparison routines:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   __eqsf2   __gesf2   __unordsf2
end_comment

begin_comment
comment|//   __lesf2   __gtsf2
end_comment

begin_comment
comment|//   __ltsf2
end_comment

begin_comment
comment|//   __nesf2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The semantics of the routines grouped in each column are identical, so there
end_comment

begin_comment
comment|// is a single implementation for each, and wrappers to provide the other names.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The main routines behave as follows:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   __lesf2(a,b) returns -1 if a< b
end_comment

begin_comment
comment|//                         0 if a == b
end_comment

begin_comment
comment|//                         1 if a> b
end_comment

begin_comment
comment|//                         1 if either a or b is NaN
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   __gesf2(a,b) returns -1 if a< b
end_comment

begin_comment
comment|//                         0 if a == b
end_comment

begin_comment
comment|//                         1 if a> b
end_comment

begin_comment
comment|//                        -1 if either a or b is NaN
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   __unordsf2(a,b) returns 0 if both a and b are numbers
end_comment

begin_comment
comment|//                           1 if either a or b is NaN
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that __lesf2( ) and __gesf2( ) are identical except in their handling of
end_comment

begin_comment
comment|// NaN values.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_define
define|#
directive|define
name|SINGLE_PRECISION
end_define

begin_include
include|#
directive|include
file|"fp_lib.h"
end_include

begin_enum
enum|enum
name|LE_RESULT
block|{
name|LE_LESS
init|=
operator|-
literal|1
block|,
name|LE_EQUAL
init|=
literal|0
block|,
name|LE_GREATER
init|=
literal|1
block|,
name|LE_UNORDERED
init|=
literal|1
block|}
enum|;
end_enum

begin_function
name|COMPILER_RT_ABI
name|enum
name|LE_RESULT
name|__lesf2
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
block|{
specifier|const
name|srep_t
name|aInt
init|=
name|toRep
argument_list|(
name|a
argument_list|)
decl_stmt|;
specifier|const
name|srep_t
name|bInt
init|=
name|toRep
argument_list|(
name|b
argument_list|)
decl_stmt|;
specifier|const
name|rep_t
name|aAbs
init|=
name|aInt
operator|&
name|absMask
decl_stmt|;
specifier|const
name|rep_t
name|bAbs
init|=
name|bInt
operator|&
name|absMask
decl_stmt|;
comment|// If either a or b is NaN, they are unordered.
if|if
condition|(
name|aAbs
operator|>
name|infRep
operator|||
name|bAbs
operator|>
name|infRep
condition|)
return|return
name|LE_UNORDERED
return|;
comment|// If a and b are both zeros, they are equal.
if|if
condition|(
operator|(
name|aAbs
operator||
name|bAbs
operator|)
operator|==
literal|0
condition|)
return|return
name|LE_EQUAL
return|;
comment|// If at least one of a and b is positive, we get the same result comparing
comment|// a and b as signed integers as we would with a fp_ting-point compare.
if|if
condition|(
operator|(
name|aInt
operator|&
name|bInt
operator|)
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|aInt
operator|<
name|bInt
condition|)
return|return
name|LE_LESS
return|;
elseif|else
if|if
condition|(
name|aInt
operator|==
name|bInt
condition|)
return|return
name|LE_EQUAL
return|;
else|else
return|return
name|LE_GREATER
return|;
block|}
comment|// Otherwise, both are negative, so we need to flip the sense of the
comment|// comparison to get the correct result.  (This assumes a twos- or ones-
comment|// complement integer representation; if integers are represented in a
comment|// sign-magnitude representation, then this flip is incorrect).
else|else
block|{
if|if
condition|(
name|aInt
operator|>
name|bInt
condition|)
return|return
name|LE_LESS
return|;
elseif|else
if|if
condition|(
name|aInt
operator|==
name|bInt
condition|)
return|return
name|LE_EQUAL
return|;
else|else
return|return
name|LE_GREATER
return|;
block|}
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ELF__
argument_list|)
end_if

begin_comment
comment|// Alias for libgcc compatibility
end_comment

begin_expr_stmt
name|FNALIAS
argument_list|(
name|__cmpsf2
argument_list|,
name|__lesf2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|GE_RESULT
block|{
name|GE_LESS
init|=
operator|-
literal|1
block|,
name|GE_EQUAL
init|=
literal|0
block|,
name|GE_GREATER
init|=
literal|1
block|,
name|GE_UNORDERED
init|=
operator|-
literal|1
comment|// Note: different from LE_UNORDERED
block|}
enum|;
end_enum

begin_function
name|COMPILER_RT_ABI
name|enum
name|GE_RESULT
name|__gesf2
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
block|{
specifier|const
name|srep_t
name|aInt
init|=
name|toRep
argument_list|(
name|a
argument_list|)
decl_stmt|;
specifier|const
name|srep_t
name|bInt
init|=
name|toRep
argument_list|(
name|b
argument_list|)
decl_stmt|;
specifier|const
name|rep_t
name|aAbs
init|=
name|aInt
operator|&
name|absMask
decl_stmt|;
specifier|const
name|rep_t
name|bAbs
init|=
name|bInt
operator|&
name|absMask
decl_stmt|;
if|if
condition|(
name|aAbs
operator|>
name|infRep
operator|||
name|bAbs
operator|>
name|infRep
condition|)
return|return
name|GE_UNORDERED
return|;
if|if
condition|(
operator|(
name|aAbs
operator||
name|bAbs
operator|)
operator|==
literal|0
condition|)
return|return
name|GE_EQUAL
return|;
if|if
condition|(
operator|(
name|aInt
operator|&
name|bInt
operator|)
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|aInt
operator|<
name|bInt
condition|)
return|return
name|GE_LESS
return|;
elseif|else
if|if
condition|(
name|aInt
operator|==
name|bInt
condition|)
return|return
name|GE_EQUAL
return|;
else|else
return|return
name|GE_GREATER
return|;
block|}
else|else
block|{
if|if
condition|(
name|aInt
operator|>
name|bInt
condition|)
return|return
name|GE_LESS
return|;
elseif|else
if|if
condition|(
name|aInt
operator|==
name|bInt
condition|)
return|return
name|GE_EQUAL
return|;
else|else
return|return
name|GE_GREATER
return|;
block|}
block|}
end_function

begin_function
name|COMPILER_RT_ABI
name|int
name|__unordsf2
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
block|{
specifier|const
name|rep_t
name|aAbs
init|=
name|toRep
argument_list|(
name|a
argument_list|)
operator|&
name|absMask
decl_stmt|;
specifier|const
name|rep_t
name|bAbs
init|=
name|toRep
argument_list|(
name|b
argument_list|)
operator|&
name|absMask
decl_stmt|;
return|return
name|aAbs
operator|>
name|infRep
operator|||
name|bAbs
operator|>
name|infRep
return|;
block|}
end_function

begin_comment
comment|// The following are alternative names for the preceding routines.
end_comment

begin_function
name|COMPILER_RT_ABI
name|enum
name|LE_RESULT
name|__eqsf2
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
block|{
return|return
name|__lesf2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|COMPILER_RT_ABI
name|enum
name|LE_RESULT
name|__ltsf2
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
block|{
return|return
name|__lesf2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|COMPILER_RT_ABI
name|enum
name|LE_RESULT
name|__nesf2
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
block|{
return|return
name|__lesf2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|COMPILER_RT_ABI
name|enum
name|GE_RESULT
name|__gtsf2
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
block|{
return|return
name|__gesf2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_EABI__
argument_list|)
end_if

begin_function
name|AEABI_RTABI
name|int
name|__aeabi_fcmpun
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
block|{
return|return
name|__unordsf2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

