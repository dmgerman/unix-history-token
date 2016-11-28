begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009-2015 Samy Al Bahra.  * Copyright 2014 Paul Khuong.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_CC_H
end_ifndef

begin_define
define|#
directive|define
name|CK_CC_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SUNPRO_C
argument_list|)
end_if

begin_include
include|#
directive|include
file|"gcc/ck_cc.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_CC_RESTRICT
end_ifndef

begin_define
define|#
directive|define
name|CK_CC_RESTRICT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_CC_INLINE
end_ifndef

begin_define
define|#
directive|define
name|CK_CC_INLINE
value|inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_CC_FORCE_INLINE
end_ifndef

begin_define
define|#
directive|define
name|CK_CC_FORCE_INLINE
value|inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CK_CC_DECONST_PTR
parameter_list|(
name|X
parameter_list|)
value|((void *)(uintptr_t)(X))
end_define

begin_comment
comment|/*  * Container function.  * This relies on (compiler) implementation-defined behavior.  */
end_comment

begin_define
define|#
directive|define
name|CK_CC_CONTAINER
parameter_list|(
name|F
parameter_list|,
name|T
parameter_list|,
name|M
parameter_list|,
name|N
parameter_list|)
define|\
value|CK_CC_INLINE static T *							\ 	N(F *p)									\ 	{									\ 		F *n = p;							\ 		return (T *)(void *)(((char *)n) - ((size_t)&((T *)0)->M));	\ 	}
end_define

begin_define
define|#
directive|define
name|CK_CC_PAD
parameter_list|(
name|x
parameter_list|)
value|union { char pad[x]; }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CK_CC_ALIASED
end_ifndef

begin_define
define|#
directive|define
name|CK_CC_ALIASED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_CC_UNUSED
end_ifndef

begin_define
define|#
directive|define
name|CK_CC_UNUSED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_CC_USED
end_ifndef

begin_define
define|#
directive|define
name|CK_CC_USED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_CC_IMM
end_ifndef

begin_define
define|#
directive|define
name|CK_CC_IMM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_CC_PACKED
end_ifndef

begin_define
define|#
directive|define
name|CK_CC_PACKED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_CC_WEAKREF
end_ifndef

begin_define
define|#
directive|define
name|CK_CC_WEAKREF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_CC_ALIGN
end_ifndef

begin_define
define|#
directive|define
name|CK_CC_ALIGN
parameter_list|(
name|X
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_CC_CACHELINE
end_ifndef

begin_define
define|#
directive|define
name|CK_CC_CACHELINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_CC_LIKELY
end_ifndef

begin_define
define|#
directive|define
name|CK_CC_LIKELY
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_CC_UNLIKELY
end_ifndef

begin_define
define|#
directive|define
name|CK_CC_UNLIKELY
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_CC_TYPEOF
end_ifndef

begin_define
define|#
directive|define
name|CK_CC_TYPEOF
parameter_list|(
name|X
parameter_list|,
name|DEFAULT
parameter_list|)
value|(DEFAULT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_CC_FFS
end_ifndef

begin_define
define|#
directive|define
name|CK_F_CC_FFS
end_define

begin_function
name|CK_CC_INLINE
specifier|static
name|int
name|ck_cc_ffs
parameter_list|(
name|unsigned
name|int
name|x
parameter_list|)
block|{
name|unsigned
name|int
name|i
decl_stmt|;
if|if
condition|(
name|x
operator|==
literal|0
condition|)
return|return
literal|0
return|;
for|for
control|(
name|i
operator|=
literal|1
init|;
operator|(
name|x
operator|&
literal|1
operator|)
operator|==
literal|0
condition|;
name|i
operator|++
operator|,
name|x
operator|>>=
literal|1
control|)
empty_stmt|;
return|return
name|i
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_CC_CLZ
end_ifndef

begin_define
define|#
directive|define
name|CK_F_CC_CLZ
end_define

begin_include
include|#
directive|include
file|<ck_limits.h>
end_include

begin_function
name|CK_CC_INLINE
specifier|static
name|int
name|ck_cc_clz
parameter_list|(
name|unsigned
name|int
name|x
parameter_list|)
block|{
name|unsigned
name|int
name|count
decl_stmt|,
name|i
decl_stmt|;
for|for
control|(
name|count
operator|=
literal|0
operator|,
name|i
operator|=
expr|sizeof
operator|(
name|unsigned
name|int
operator|)
operator|*
name|CHAR_BIT
init|;
name|i
operator|>
literal|0
condition|;
name|count
operator|++
control|)
block|{
name|unsigned
name|int
name|bit
init|=
literal|1U
operator|<<
operator|--
name|i
decl_stmt|;
if|if
condition|(
name|x
operator|&
name|bit
condition|)
break|break;
block|}
return|return
name|count
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_CC_CTZ
end_ifndef

begin_define
define|#
directive|define
name|CK_F_CC_CTZ
end_define

begin_function
name|CK_CC_INLINE
specifier|static
name|int
name|ck_cc_ctz
parameter_list|(
name|unsigned
name|int
name|x
parameter_list|)
block|{
name|unsigned
name|int
name|i
decl_stmt|;
if|if
condition|(
name|x
operator|==
literal|0
condition|)
return|return
literal|0
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
operator|(
name|x
operator|&
literal|1
operator|)
operator|==
literal|0
condition|;
name|i
operator|++
operator|,
name|x
operator|>>=
literal|1
control|)
empty_stmt|;
return|return
name|i
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_CC_POPCOUNT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_CC_POPCOUNT
end_define

begin_function
name|CK_CC_INLINE
specifier|static
name|int
name|ck_cc_popcount
parameter_list|(
name|unsigned
name|int
name|x
parameter_list|)
block|{
name|unsigned
name|int
name|acc
decl_stmt|;
for|for
control|(
name|acc
operator|=
literal|0
init|;
name|x
operator|!=
literal|0
condition|;
name|x
operator|>>=
literal|1
control|)
name|acc
operator|+=
name|x
operator|&
literal|1
expr_stmt|;
return|return
name|acc
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|CK_CPP_CAST
parameter_list|(
name|type
parameter_list|,
name|arg
parameter_list|)
value|static_cast<type>(arg)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CK_CPP_CAST
parameter_list|(
name|type
parameter_list|,
name|arg
parameter_list|)
value|arg
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_CC_H */
end_comment

end_unit

