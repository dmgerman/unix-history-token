begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_INTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_INTR_H_
end_define

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|alpha_intr_list
argument_list|,
name|alpha_intr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|alpha_intr
block|{
name|LIST_ENTRY
argument_list|(
argument|alpha_intr
argument_list|)
name|list
expr_stmt|;
comment|/* chain handlers in this hash bucket */
name|int
name|vector
decl_stmt|;
comment|/* vector to match */
name|driver_intr_t
modifier|*
name|intr
decl_stmt|;
comment|/* handler function */
name|void
modifier|*
name|arg
decl_stmt|;
comment|/* argument to handler */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|alpha_intr
modifier|*
name|alpha_create_intr
parameter_list|(
name|int
name|vector
parameter_list|,
name|driver_intr_t
modifier|*
name|intr
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|alpha_connect_intr
parameter_list|(
name|struct
name|alpha_intr
modifier|*
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|alpha_dispatch_intr
parameter_list|(
name|int
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_INTR_H_ */
end_comment

end_unit

