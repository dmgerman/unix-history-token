begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_UCONTEXT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_UCONTEXT_H_
end_define

begin_include
include|#
directive|include
file|<machine/ucontext.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|__ucontext
block|{
comment|/* 	 * Keep the order of the first two fields. Also, 	 * keep them the first two fields in the structure. 	 * This way we can have a union with struct 	 * sigcontext and ucontext_t. This allows us to 	 * support them both at the same time. 	 * note: the union is not defined, though. 	 */
name|sigset_t
name|uc_sigmask
decl_stmt|;
name|mcontext_t
name|uc_mcontext
decl_stmt|;
name|struct
name|__ucontext
modifier|*
name|uc_link
decl_stmt|;
name|stack_t
name|uc_stack
decl_stmt|;
name|int
name|__spare__
index|[
literal|8
index|]
decl_stmt|;
block|}
name|ucontext_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_UCONTEXT_H_ */
end_comment

end_unit

