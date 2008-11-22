begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PROFILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PROFILE_H_
end_define

begin_define
define|#
directive|define
name|_MCOUNT_DECL
value|void __mcount
end_define

begin_define
define|#
directive|define
name|MCOUNT
end_define

begin_define
define|#
directive|define
name|FUNCTION_ALIGNMENT
value|32
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|fptrdiff_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * The following two macros do splhigh and splx respectively.  */
end_comment

begin_define
define|#
directive|define
name|MCOUNT_ENTER
parameter_list|(
name|s
parameter_list|)
value|s = intr_disable()
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
parameter_list|(
name|s
parameter_list|)
value|intr_restore(s)
end_define

begin_define
define|#
directive|define
name|MCOUNT_DECL
parameter_list|(
name|s
parameter_list|)
value|register_t s;
end_define

begin_function_decl
name|void
name|bintr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|btrap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eintr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|user
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MCOUNT_FROMPC_USER
parameter_list|(
name|pc
parameter_list|)
define|\
value|((pc< (uintfptr_t)VM_MAXUSER_ADDRESS) ? ~0UL : pc)
end_define

begin_define
define|#
directive|define
name|MCOUNT_FROMPC_INTR
parameter_list|(
name|pc
parameter_list|)
value|(~0UL)
end_define

begin_expr_stmt
name|_MCOUNT_DECL
argument_list|(
name|uintfptr_t
argument_list|,
name|uintfptr_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|uintfptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PROFILE_H_ */
end_comment

end_unit

