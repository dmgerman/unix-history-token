begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015  Peter Grehan<grehan@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FWCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_FWCTL_H_
end_define

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_comment
comment|/*  * Linker set api for export of information to guest firmware via  * a sysctl-like OID interface  */
end_comment

begin_struct
struct|struct
name|ctl
block|{
specifier|const
name|char
modifier|*
name|c_oid
decl_stmt|;
specifier|const
name|void
modifier|*
name|c_data
decl_stmt|;
specifier|const
name|int
name|c_len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CTL_NODE
parameter_list|(
name|oid
parameter_list|,
name|data
parameter_list|,
name|len
parameter_list|)
define|\
value|static struct ctl __CONCAT(__ctl, __LINE__) = {		\ 		oid,						\ 		(data),						\ 		(len),						\ 	};							\ 	DATA_SET(ctl_set, __CONCAT(__ctl, __LINE__))
end_define

begin_function_decl
name|void
name|fwctl_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FWCTL_H_ */
end_comment

end_unit

