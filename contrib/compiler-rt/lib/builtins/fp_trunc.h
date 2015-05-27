begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== lib/fp_trunc.h - high precision -> low precision conversion *- C -*-===//
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
comment|// Set source and destination precision setting
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
name|FP_TRUNC_HEADER
end_ifndef

begin_define
define|#
directive|define
name|FP_TRUNC_HEADER
end_define

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_if
if|#
directive|if
name|defined
name|SRC_DOUBLE
end_if

begin_typedef
typedef|typedef
name|double
name|src_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|src_rep_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SRC_REP_C
value|UINT64_C
end_define

begin_decl_stmt
specifier|static
specifier|const
name|int
name|srcSigBits
init|=
literal|52
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
name|SRC_QUAD
end_elif

begin_typedef
typedef|typedef
name|long
name|double
name|src_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint128_t
name|src_rep_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SRC_REP_C
value|(__uint128_t)
end_define

begin_decl_stmt
specifier|static
specifier|const
name|int
name|srcSigBits
init|=
literal|112
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Source should be double precision or quad precision!
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//end source precision
end_comment

begin_if
if|#
directive|if
name|defined
name|DST_DOUBLE
end_if

begin_typedef
typedef|typedef
name|double
name|dst_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|dst_rep_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DST_REP_C
value|UINT64_C
end_define

begin_decl_stmt
specifier|static
specifier|const
name|int
name|dstSigBits
init|=
literal|52
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
name|DST_SINGLE
end_elif

begin_typedef
typedef|typedef
name|float
name|dst_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|dst_rep_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DST_REP_C
value|UINT32_C
end_define

begin_decl_stmt
specifier|static
specifier|const
name|int
name|dstSigBits
init|=
literal|23
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Destination should be single precision or double precision!
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//end destination precision
end_comment

begin_comment
comment|// End of specialization parameters.  Two helper routines for conversion to and
end_comment

begin_comment
comment|// from the representation of floating-point data as integer values follow.
end_comment

begin_function
specifier|static
specifier|inline
name|src_rep_t
name|srcToRep
parameter_list|(
name|src_t
name|x
parameter_list|)
block|{
specifier|const
union|union
block|{
name|src_t
name|f
decl_stmt|;
name|src_rep_t
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
name|dst_t
name|dstFromRep
parameter_list|(
name|dst_rep_t
name|x
parameter_list|)
block|{
specifier|const
union|union
block|{
name|dst_t
name|f
decl_stmt|;
name|dst_rep_t
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// FP_TRUNC_HEADER
end_comment

end_unit

