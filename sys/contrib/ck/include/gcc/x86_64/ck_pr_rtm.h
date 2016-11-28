begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2013-2015 Samy Al Bahra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2012,2013 Intel Corporation  * Author: Andi Kleen  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_X86_64_RTM_H
end_ifndef

begin_define
define|#
directive|define
name|CK_PR_X86_64_RTM_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_X86_64_H
end_ifndef

begin_error
error|#
directive|error
error|Do not include this file directly, use ck_pr.h
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CK_F_PR_RTM
end_define

begin_include
include|#
directive|include
file|<ck_cc.h>
end_include

begin_include
include|#
directive|include
file|<ck_stdbool.h>
end_include

begin_define
define|#
directive|define
name|CK_PR_RTM_STARTED
value|(~0U)
end_define

begin_define
define|#
directive|define
name|CK_PR_RTM_EXPLICIT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|CK_PR_RTM_RETRY
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CK_PR_RTM_CONFLICT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|CK_PR_RTM_CAPACITY
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|CK_PR_RTM_DEBUG
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|CK_PR_RTM_NESTED
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|CK_PR_RTM_CODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0xFF)
end_define

begin_function
name|CK_CC_INLINE
specifier|static
name|unsigned
name|int
name|ck_pr_rtm_begin
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|int
name|r
init|=
name|CK_PR_RTM_STARTED
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(".byte 0xc7,0xf8;" 			     ".long 0;" 				: "+a" (r) 				: 				: "memory");
return|return
name|r
return|;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_pr_rtm_end
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(".byte 0x0f,0x01,0xd5" ::: "memory");
return|return;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_pr_rtm_abort
parameter_list|(
specifier|const
name|unsigned
name|int
name|status
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(".byte 0xc6,0xf8,%P0" :: "i" (status) : "memory");
return|return;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|bool
name|ck_pr_rtm_test
parameter_list|(
name|void
parameter_list|)
block|{
name|bool
name|r
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(".byte 0x0f,0x01,0xd6;" 			     "setnz %0" 				: "=r" (r) 				: 				: "memory");
return|return
name|r
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_PR_X86_64_RTM_H */
end_comment

end_unit

