begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/netnatm/sig/unisig.h,v 1.4 2004/07/08 08:22:26 brandt Exp $  *  * Utility functions for signalling stuff  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNATM_SIG_UNISIG_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNATM_SIG_UNISIG_H_
end_define

begin_include
include|#
directive|include
file|<netnatm/sig/unidef.h>
end_include

begin_comment
comment|/* names */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|uni_signame
parameter_list|(
name|enum
name|uni_sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|uni_facname
parameter_list|(
name|enum
name|uni_verb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return a string for the error code */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|uni_strerr
parameter_list|(
name|u_int
name|_err
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* format an API message */
end_comment

begin_function_decl
name|void
name|uni_print_api
parameter_list|(
name|char
modifier|*
name|_buf
parameter_list|,
name|size_t
name|_bufsiz
parameter_list|,
name|u_int
name|_type
parameter_list|,
name|u_int
name|_cookie
parameter_list|,
specifier|const
name|void
modifier|*
name|_msg
parameter_list|,
name|struct
name|unicx
modifier|*
name|_cx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

