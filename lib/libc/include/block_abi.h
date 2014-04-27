begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 David T Chisnall  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__BLOCKS__
end_ifdef

begin_comment
comment|/**  * Declares a block variable.  This macro is defined in the trivial way for  * compilers that support blocks and exposing the ABI in the source for other  * compilers.  */
end_comment

begin_define
define|#
directive|define
name|DECLARE_BLOCK
parameter_list|(
name|retTy
parameter_list|,
name|name
parameter_list|,
name|argTys
parameter_list|,
modifier|...
parameter_list|)
define|\
value|retTy(^name)(argTys, ## __VA_ARGS__)
end_define

begin_comment
comment|/**  * Calls a block variable.  This macro is defined in the trivial way for  * compilers that support blocks and exposing the ABI in the source for other  * compilers.  */
end_comment

begin_define
define|#
directive|define
name|CALL_BLOCK
parameter_list|(
name|name
parameter_list|,
modifier|...
parameter_list|)
value|name(__VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// !__BLOCKS__
end_comment

begin_define
define|#
directive|define
name|DECLARE_BLOCK
parameter_list|(
name|retTy
parameter_list|,
name|name
parameter_list|,
name|argTys
parameter_list|,
modifier|...
parameter_list|)
define|\
value|struct {\ 		void *isa;\ 		int flags;\ 		int reserved;\ 		retTy (*invoke)(void *, ...);\ 	} *name
end_define

begin_define
define|#
directive|define
name|CALL_BLOCK
parameter_list|(
name|name
parameter_list|,
modifier|...
parameter_list|)
value|(name)->invoke(name, __VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __BLOCKS__
end_comment

begin_comment
comment|/**  * Returns the pointer to the block-invoke function.  This is used for passing  * blocks to functions that want a function pointer and a data pointer.  */
end_comment

begin_define
define|#
directive|define
name|GET_BLOCK_FUNCTION
parameter_list|(
name|x
parameter_list|)
define|\
value|(((struct {\ 		void *isa;\ 		int flags;\ 		int reserved;\ 		void (*invoke)(void *, ...);\ 	}*)(void*)x)->invoke)
end_define

end_unit

