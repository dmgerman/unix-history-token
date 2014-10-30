begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_LOG2_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_LOG2_H_
end_define

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|roundup_pow_of_two
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|)
block|{
return|return
operator|(
literal|1UL
operator|<<
name|flsl
argument_list|(
name|x
operator|-
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|is_power_of_2
parameter_list|(
name|unsigned
name|long
name|n
parameter_list|)
block|{
return|return
operator|(
name|n
operator|==
name|roundup_pow_of_two
argument_list|(
name|n
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|rounddown_pow_of_two
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|)
block|{
return|return
operator|(
literal|1UL
operator|<<
operator|(
name|flsl
argument_list|(
name|x
argument_list|)
operator|-
literal|1
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * deal with unrepresentable constant logarithms  */
end_comment

begin_extern
extern|extern __attribute__((const
operator|,
extern|noreturn
end_extern

begin_function_decl
unit|))
name|int
name|____ilog2_NaN
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * non-constant log of base 2 calculators  * - the arch may override these in asm/bitops.h if they can be implemented  *   more efficiently than using fls() and fls64()  * - the arch is not required to handle n==0 if implementing the fallback  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_ARCH_HAS_ILOG2_U32
end_ifndef

begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(const)
argument_list|)
name|int
name|__ilog2_u32
argument_list|(
argument|u32 n
argument_list|)
block|{
return|return
name|flsl
argument_list|(
name|n
argument_list|)
operator|-
literal|1
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_ARCH_HAS_ILOG2_U64
end_ifndef

begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(const)
argument_list|)
name|int
name|__ilog2_u64
argument_list|(
argument|u64 n
argument_list|)
block|{
return|return
name|flsl
argument_list|(
name|n
argument_list|)
operator|-
literal|1
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * ilog2 - log of base 2 of 32-bit or a 64-bit unsigned value  * @n - parameter  *  * constant-capable log of base 2 calculation  * - this can be used to initialise global variables from constant data, hence  *   the massive ternary operator construction  *  * selects the appropriately-sized optimised version depending on sizeof(n)  */
end_comment

begin_define
define|#
directive|define
name|ilog2
parameter_list|(
name|n
parameter_list|)
define|\
value|(						\ 	__builtin_constant_p(n) ? (		\ 		(n)< 1 ? ____ilog2_NaN() :	\ 		(n)& (1ULL<< 63) ? 63 :	\ 		(n)& (1ULL<< 62) ? 62 :	\ 		(n)& (1ULL<< 61) ? 61 :	\ 		(n)& (1ULL<< 60) ? 60 :	\ 		(n)& (1ULL<< 59) ? 59 :	\ 		(n)& (1ULL<< 58) ? 58 :	\ 		(n)& (1ULL<< 57) ? 57 :	\ 		(n)& (1ULL<< 56) ? 56 :	\ 		(n)& (1ULL<< 55) ? 55 :	\ 		(n)& (1ULL<< 54) ? 54 :	\ 		(n)& (1ULL<< 53) ? 53 :	\ 		(n)& (1ULL<< 52) ? 52 :	\ 		(n)& (1ULL<< 51) ? 51 :	\ 		(n)& (1ULL<< 50) ? 50 :	\ 		(n)& (1ULL<< 49) ? 49 :	\ 		(n)& (1ULL<< 48) ? 48 :	\ 		(n)& (1ULL<< 47) ? 47 :	\ 		(n)& (1ULL<< 46) ? 46 :	\ 		(n)& (1ULL<< 45) ? 45 :	\ 		(n)& (1ULL<< 44) ? 44 :	\ 		(n)& (1ULL<< 43) ? 43 :	\ 		(n)& (1ULL<< 42) ? 42 :	\ 		(n)& (1ULL<< 41) ? 41 :	\ 		(n)& (1ULL<< 40) ? 40 :	\ 		(n)& (1ULL<< 39) ? 39 :	\ 		(n)& (1ULL<< 38) ? 38 :	\ 		(n)& (1ULL<< 37) ? 37 :	\ 		(n)& (1ULL<< 36) ? 36 :	\ 		(n)& (1ULL<< 35) ? 35 :	\ 		(n)& (1ULL<< 34) ? 34 :	\ 		(n)& (1ULL<< 33) ? 33 :	\ 		(n)& (1ULL<< 32) ? 32 :	\ 		(n)& (1ULL<< 31) ? 31 :	\ 		(n)& (1ULL<< 30) ? 30 :	\ 		(n)& (1ULL<< 29) ? 29 :	\ 		(n)& (1ULL<< 28) ? 28 :	\ 		(n)& (1ULL<< 27) ? 27 :	\ 		(n)& (1ULL<< 26) ? 26 :	\ 		(n)& (1ULL<< 25) ? 25 :	\ 		(n)& (1ULL<< 24) ? 24 :	\ 		(n)& (1ULL<< 23) ? 23 :	\ 		(n)& (1ULL<< 22) ? 22 :	\ 		(n)& (1ULL<< 21) ? 21 :	\ 		(n)& (1ULL<< 20) ? 20 :	\ 		(n)& (1ULL<< 19) ? 19 :	\ 		(n)& (1ULL<< 18) ? 18 :	\ 		(n)& (1ULL<< 17) ? 17 :	\ 		(n)& (1ULL<< 16) ? 16 :	\ 		(n)& (1ULL<< 15) ? 15 :	\ 		(n)& (1ULL<< 14) ? 14 :	\ 		(n)& (1ULL<< 13) ? 13 :	\ 		(n)& (1ULL<< 12) ? 12 :	\ 		(n)& (1ULL<< 11) ? 11 :	\ 		(n)& (1ULL<< 10) ? 10 :	\ 		(n)& (1ULL<<  9) ?  9 :	\ 		(n)& (1ULL<<  8) ?  8 :	\ 		(n)& (1ULL<<  7) ?  7 :	\ 		(n)& (1ULL<<  6) ?  6 :	\ 		(n)& (1ULL<<  5) ?  5 :	\ 		(n)& (1ULL<<  4) ?  4 :	\ 		(n)& (1ULL<<  3) ?  3 :	\ 		(n)& (1ULL<<  2) ?  2 :	\ 		(n)& (1ULL<<  1) ?  1 :	\ 		(n)& (1ULL<<  0) ?  0 :	\ 		____ilog2_NaN()			\ 				   ) :		\ 	(sizeof(n)<= 4) ?			\ 	__ilog2_u32(n) :			\ 	__ilog2_u64(n)				\  )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_LOG2_H_ */
end_comment

end_unit

