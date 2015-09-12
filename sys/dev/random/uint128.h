begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_DEV_RANDOM_UINT128_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|SYS_DEV_RANDOM_UINT128_H_INCLUDED
end_define

begin_comment
comment|/* This whole thing is a crock :-(  *  * Everyone knows you always need the __uint128_t types!  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__SIZEOF_INT128__
end_ifdef

begin_define
define|#
directive|define
name|USE_REAL_UINT128_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_REAL_UINT128_T
end_ifdef

begin_typedef
typedef|typedef
name|__uint128_t
name|uint128_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UINT128_ZERO
value|0ULL
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Ignore endianness */
name|uint64_t
name|u128t_word0
decl_stmt|;
name|uint64_t
name|u128t_word1
decl_stmt|;
block|}
name|uint128_t
typedef|;
end_typedef

begin_decl_stmt
specifier|static
specifier|const
name|uint128_t
name|very_long_zero
init|=
block|{
literal|0UL
block|,
literal|0UL
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UINT128_ZERO
value|very_long_zero
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|void
name|uint128_increment
parameter_list|(
name|uint128_t
modifier|*
name|big_uintp
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|USE_REAL_UINT128_T
operator|(
operator|*
name|big_uintp
operator|)
operator|++
expr_stmt|;
else|#
directive|else
name|big_uintp
operator|->
name|u128t_word0
operator|++
expr_stmt|;
if|if
condition|(
name|big_uintp
operator|->
name|u128t_word0
operator|==
literal|0UL
condition|)
name|big_uintp
operator|->
name|u128t_word1
operator|++
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|uint128_is_zero
parameter_list|(
name|uint128_t
name|big_uint
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|USE_REAL_UINT128_T
return|return
operator|(
name|big_uint
operator|==
name|UINT128_ZERO
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|big_uint
operator|.
name|u128t_word0
operator|==
literal|0UL
operator|&&
name|big_uint
operator|.
name|u128t_word1
operator|==
literal|0UL
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_DEV_RANDOM_UINT128_H_INCLUDED */
end_comment

end_unit

