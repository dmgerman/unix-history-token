begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: undefined.h,v 1.4 2001/12/20 01:20:23 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1995-1996 Mark Brinicombe.  * Copyright (c) 1995 Brini.  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Brini.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BRINI ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BRINI OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RiscBSD kernel project  *  * undefined.h  *  * Undefined instruction types, symbols and prototypes  *  * Created      : 08/02/95  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_UNDEFINED_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_UNDEFINED_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|undef_handler_t
function_decl|)
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|trapframe_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|FP_COPROC
value|1
end_define

begin_define
define|#
directive|define
name|FP_COPROC2
value|2
end_define

begin_define
define|#
directive|define
name|MAX_COPROCS
value|16
end_define

begin_comment
comment|/* Prototypes for undefined.c */
end_comment

begin_function_decl
name|void
modifier|*
name|install_coproc_handler
parameter_list|(
name|int
parameter_list|,
name|undef_handler_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|remove_coproc_handler
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|undefined_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XXX Stuff below here is for use before malloc() is available.  Most code  * shouldn't use it.  */
end_comment

begin_struct
struct|struct
name|undefined_handler
block|{
name|LIST_ENTRY
argument_list|(
argument|undefined_handler
argument_list|)
name|uh_link
expr_stmt|;
name|undef_handler_t
name|uh_handler
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Handlers installed using install_coproc_handler_static shouldn't be  * removed.  */
end_comment

begin_function_decl
name|void
name|install_coproc_handler_static
parameter_list|(
name|int
parameter_list|,
name|struct
name|undefined_handler
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Calls up to undefined.c from trap handlers */
end_comment

begin_function_decl
name|void
name|undefinedinstruction
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* End of undefined.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_UNDEFINED_H_ */
end_comment

end_unit

