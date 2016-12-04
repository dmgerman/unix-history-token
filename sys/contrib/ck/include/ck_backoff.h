begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009-2015 Samy Al Bahra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_BACKOFF_H
end_ifndef

begin_define
define|#
directive|define
name|CK_BACKOFF_H
end_define

begin_include
include|#
directive|include
file|<ck_cc.h>
end_include

begin_include
include|#
directive|include
file|<ck_pr.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|CK_BACKOFF_CEILING
end_ifndef

begin_define
define|#
directive|define
name|CK_BACKOFF_CEILING
value|((1<< 20) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CK_BACKOFF_INITIALIZER
value|(1<< 9)
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ck_backoff_t
typedef|;
end_typedef

begin_comment
comment|/*  * This is a exponential back-off implementation.  */
end_comment

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_backoff_eb
parameter_list|(
name|unsigned
name|int
modifier|*
name|c
parameter_list|)
block|{
name|unsigned
name|int
name|i
decl_stmt|,
name|ceiling
decl_stmt|;
name|ceiling
operator|=
operator|*
name|c
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ceiling
condition|;
name|i
operator|++
control|)
name|ck_pr_barrier
argument_list|()
expr_stmt|;
operator|*
name|c
operator|=
name|ceiling
operator|<<=
name|ceiling
operator|<
name|CK_BACKOFF_CEILING
expr_stmt|;
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_BACKOFF_H */
end_comment

end_unit

