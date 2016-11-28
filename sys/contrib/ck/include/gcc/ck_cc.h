begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009-2015 Samy Al Bahra.  * Copyright 2014 Paul Khuong.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_GCC_CC_H
end_ifndef

begin_define
define|#
directive|define
name|CK_GCC_CC_H
end_define

begin_include
include|#
directive|include
file|<ck_md.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__SUNPRO_C
end_ifdef

begin_define
define|#
directive|define
name|CK_CC_UNUSED
end_define

begin_define
define|#
directive|define
name|CK_CC_USED
end_define

begin_define
define|#
directive|define
name|CK_CC_IMM
end_define

begin_define
define|#
directive|define
name|CK_CC_IMM_U32
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CK_CC_UNUSED
value|__attribute__((unused))
end_define

begin_define
define|#
directive|define
name|CK_CC_USED
value|__attribute__((used))
end_define

begin_define
define|#
directive|define
name|CK_CC_IMM
value|"i"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86__
argument_list|)
end_if

begin_define
define|#
directive|define
name|CK_CC_IMM_U32
value|"Z"
end_define

begin_define
define|#
directive|define
name|CK_CC_IMM_S32
value|"e"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CK_CC_IMM_U32
value|CK_CC_IMM
end_define

begin_define
define|#
directive|define
name|CK_CC_IMM_S32
value|CK_CC_IMM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __x86_64__ || __x86__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_define
define|#
directive|define
name|CK_CC_INLINE
value|CK_CC_UNUSED inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CK_CC_INLINE
value|CK_CC_UNUSED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CK_CC_FORCE_INLINE
value|CK_CC_UNUSED __attribute__((always_inline)) inline
end_define

begin_define
define|#
directive|define
name|CK_CC_RESTRICT
value|__restrict__
end_define

begin_comment
comment|/*  * Packed attribute.  */
end_comment

begin_define
define|#
directive|define
name|CK_CC_PACKED
value|__attribute__((packed))
end_define

begin_comment
comment|/*  * Weak reference.  */
end_comment

begin_define
define|#
directive|define
name|CK_CC_WEAKREF
value|__attribute__((weakref))
end_define

begin_comment
comment|/*  * Alignment attribute.  */
end_comment

begin_define
define|#
directive|define
name|CK_CC_ALIGN
parameter_list|(
name|B
parameter_list|)
value|__attribute__((aligned(B)))
end_define

begin_comment
comment|/*  * Cache align.  */
end_comment

begin_define
define|#
directive|define
name|CK_CC_CACHELINE
value|CK_CC_ALIGN(CK_MD_CACHELINE)
end_define

begin_comment
comment|/*  * These are functions which should be avoided.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__freestanding__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|GCC
name|poison
name|malloc
name|free
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Branch execution hints.  */
end_comment

begin_define
define|#
directive|define
name|CK_CC_LIKELY
parameter_list|(
name|x
parameter_list|)
value|(__builtin_expect(!!(x), 1))
end_define

begin_define
define|#
directive|define
name|CK_CC_UNLIKELY
parameter_list|(
name|x
parameter_list|)
value|(__builtin_expect(!!(x), 0))
end_define

begin_comment
comment|/*  * Some compilers are overly strict regarding aliasing semantics.  * Unfortunately, in many cases it makes more sense to pay aliasing  * cost rather than overly expensive register spillage.  */
end_comment

begin_define
define|#
directive|define
name|CK_CC_ALIASED
value|__attribute__((__may_alias__))
end_define

begin_comment
comment|/*  * Compile-time typeof  */
end_comment

begin_define
define|#
directive|define
name|CK_CC_TYPEOF
parameter_list|(
name|X
parameter_list|,
name|DEFAULT
parameter_list|)
value|__typeof__(X)
end_define

begin_comment
comment|/*  * Portability wrappers for bitwise ops.  */
end_comment

begin_define
define|#
directive|define
name|CK_F_CC_FFS
end_define

begin_define
define|#
directive|define
name|CK_F_CC_CLZ
end_define

begin_define
define|#
directive|define
name|CK_F_CC_CTZ
end_define

begin_define
define|#
directive|define
name|CK_F_CC_POPCOUNT
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
return|return
name|__builtin_ffs
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

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
return|return
name|__builtin_clz
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

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
return|return
name|__builtin_ctz
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

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
return|return
name|__builtin_popcount
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_GCC_CC_H */
end_comment

end_unit

