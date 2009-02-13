begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Tim J. Robbins.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNCP_NCPIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNCP_NCPIO_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|NCP_NAME
value|"ncp"
end_define

begin_struct_decl
struct_decl|struct
name|ncp_conn_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ncp_buf
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ncpioc_connect
block|{
name|struct
name|ncp_conn_args
modifier|*
name|ioc_li
decl_stmt|;
name|int
modifier|*
name|ioc_connhandle
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ncpioc_request
block|{
name|int
name|ioc_connhandle
decl_stmt|;
name|int
name|ioc_fn
decl_stmt|;
name|struct
name|ncp_buf
modifier|*
name|ioc_ncpbuf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ncpioc_connscan
block|{
name|struct
name|ncp_conn_args
modifier|*
name|ioc_li
decl_stmt|;
name|int
modifier|*
name|ioc_connhandle
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NCPIOC_CONNECT
value|_IOW('N',  100, struct ncpioc_connect)
end_define

begin_define
define|#
directive|define
name|NCPIOC_REQUEST
value|_IOW('N',  101, struct ncpioc_request)
end_define

begin_define
define|#
directive|define
name|NCPIOC_CONNSCAN
value|_IOW('N',  102, struct ncpioc_connscan)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETNCP_NCPIO_H_ */
end_comment

end_unit

