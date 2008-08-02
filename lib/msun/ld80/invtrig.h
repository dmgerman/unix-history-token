begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 David Schultz<das@FreeBSD.ORG>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_include
include|#
directive|include
file|"fpmath.h"
end_include

begin_define
define|#
directive|define
name|BIAS
value|(LDBL_MAX_EXP - 1)
end_define

begin_define
define|#
directive|define
name|MANH_SIZE
value|LDBL_MANH_SIZE
end_define

begin_comment
comment|/* Approximation thresholds. */
end_comment

begin_define
define|#
directive|define
name|ASIN_LINEAR
value|(BIAS - 32)
end_define

begin_comment
comment|/* 2**-32 */
end_comment

begin_define
define|#
directive|define
name|ACOS_CONST
value|(BIAS - 65)
end_define

begin_comment
comment|/* 2**-65 */
end_comment

begin_define
define|#
directive|define
name|ATAN_CONST
value|(BIAS + 65)
end_define

begin_comment
comment|/* 2**65 */
end_comment

begin_define
define|#
directive|define
name|ATAN_LINEAR
value|(BIAS - 32)
end_define

begin_comment
comment|/* 2**-32 */
end_comment

begin_comment
comment|/* 0.95 */
end_comment

begin_define
define|#
directive|define
name|THRESH
value|((0xe666666666666666ULL>>(64-(MANH_SIZE-1)))|LDBL_NBIT)
end_define

begin_comment
comment|/* Constants shared by the long double inverse trig functions. */
end_comment

begin_define
define|#
directive|define
name|pS0
value|_ItL_pS0
end_define

begin_define
define|#
directive|define
name|pS1
value|_ItL_pS1
end_define

begin_define
define|#
directive|define
name|pS2
value|_ItL_pS2
end_define

begin_define
define|#
directive|define
name|pS3
value|_ItL_pS3
end_define

begin_define
define|#
directive|define
name|pS4
value|_ItL_pS4
end_define

begin_define
define|#
directive|define
name|pS5
value|_ItL_pS5
end_define

begin_define
define|#
directive|define
name|pS6
value|_ItL_pS6
end_define

begin_define
define|#
directive|define
name|qS1
value|_ItL_qS1
end_define

begin_define
define|#
directive|define
name|qS2
value|_ItL_qS2
end_define

begin_define
define|#
directive|define
name|qS3
value|_ItL_qS3
end_define

begin_define
define|#
directive|define
name|qS4
value|_ItL_qS4
end_define

begin_define
define|#
directive|define
name|qS5
value|_ItL_qS5
end_define

begin_define
define|#
directive|define
name|atanhi
value|_ItL_atanhi
end_define

begin_define
define|#
directive|define
name|atanlo
value|_ItL_atanlo
end_define

begin_define
define|#
directive|define
name|aT
value|_ItL_aT
end_define

begin_define
define|#
directive|define
name|pi_lo
value|_ItL_pi_lo
end_define

begin_define
define|#
directive|define
name|pio2_hi
value|atanhi[3]
end_define

begin_define
define|#
directive|define
name|pio2_lo
value|atanlo[3]
end_define

begin_define
define|#
directive|define
name|pio4_hi
value|atanhi[1]
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|STRUCT_DECLS
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|longdouble
block|{
name|uint64_t
name|mant
decl_stmt|;
name|uint16_t
name|expsign
decl_stmt|;
block|}
name|LONGDOUBLE
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|long
name|double
name|LONGDOUBLE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|const
name|LONGDOUBLE
name|pS0
decl_stmt|,
name|pS1
decl_stmt|,
name|pS2
decl_stmt|,
name|pS3
decl_stmt|,
name|pS4
decl_stmt|,
name|pS5
decl_stmt|,
name|pS6
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|LONGDOUBLE
name|qS1
decl_stmt|,
name|qS2
decl_stmt|,
name|qS3
decl_stmt|,
name|qS4
decl_stmt|,
name|qS5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|LONGDOUBLE
name|atanhi
index|[]
decl_stmt|,
name|atanlo
index|[]
decl_stmt|,
name|aT
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|LONGDOUBLE
name|pi_lo
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|STRUCT_DECLS
end_ifndef

begin_function
specifier|static
specifier|inline
name|long
name|double
name|P
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
return|return
operator|(
name|x
operator|*
operator|(
name|pS0
operator|+
name|x
operator|*
operator|(
name|pS1
operator|+
name|x
operator|*
operator|(
name|pS2
operator|+
name|x
operator|*
operator|(
name|pS3
operator|+
name|x
operator|*
expr|\
operator|(
name|pS4
operator|+
name|x
operator|*
operator|(
name|pS5
operator|+
name|x
operator|*
name|pS6
operator|)
operator|)
operator|)
operator|)
operator|)
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|long
name|double
name|Q
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
return|return
operator|(
literal|1.0
operator|+
name|x
operator|*
operator|(
name|qS1
operator|+
name|x
operator|*
operator|(
name|qS2
operator|+
name|x
operator|*
operator|(
name|qS3
operator|+
name|x
operator|*
operator|(
name|qS4
operator|+
name|x
operator|*
name|qS5
operator|)
operator|)
operator|)
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|long
name|double
name|T_even
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
return|return
operator|(
name|aT
index|[
literal|0
index|]
operator|+
name|x
operator|*
operator|(
name|aT
index|[
literal|2
index|]
operator|+
name|x
operator|*
operator|(
name|aT
index|[
literal|4
index|]
operator|+
name|x
operator|*
operator|(
name|aT
index|[
literal|6
index|]
operator|+
name|x
operator|*
expr|\
operator|(
name|aT
index|[
literal|8
index|]
operator|+
name|x
operator|*
operator|(
name|aT
index|[
literal|10
index|]
operator|+
name|x
operator|*
name|aT
index|[
literal|12
index|]
operator|)
operator|)
operator|)
operator|)
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|long
name|double
name|T_odd
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
return|return
operator|(
name|aT
index|[
literal|1
index|]
operator|+
name|x
operator|*
operator|(
name|aT
index|[
literal|3
index|]
operator|+
name|x
operator|*
operator|(
name|aT
index|[
literal|5
index|]
operator|+
name|x
operator|*
operator|(
name|aT
index|[
literal|7
index|]
operator|+
name|x
operator|*
expr|\
operator|(
name|aT
index|[
literal|9
index|]
operator|+
name|x
operator|*
name|aT
index|[
literal|11
index|]
operator|)
operator|)
operator|)
operator|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

