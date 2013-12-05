begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: types.h,v 1.13 2000/06/13 01:02:44 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,   *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,   *   this list of conditions and the following disclaimer in the documentation   *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its   *   contributors may be used to endorse or promote products derived   *   from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   * POSSIBILITY OF SUCH DAMAGE.  *  *	from: @(#)types.h 1.18 87/07/24 SMI  *	from: @(#)types.h	2.3 88/08/15 4.0 RPCSRC  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Rpc additions to<sys/types.h>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_TYPES_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/_null.h>
end_include

begin_typedef
typedef|typedef
name|int32_t
name|bool_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|enum_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|rpcprog_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|rpcvers_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|rpcproc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|rpcprot_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|rpcport_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|rpc_inline_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__dontcare__
value|-1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_MALLOC_H_
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_RPC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|mem_alloc
parameter_list|(
name|bsize
parameter_list|)
value|malloc(bsize, M_RPC,  M_WAITOK|M_ZERO)
end_define

begin_define
define|#
directive|define
name|mem_free
parameter_list|(
name|ptr
parameter_list|,
name|bsize
parameter_list|)
value|free(ptr, M_RPC)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mem_alloc
parameter_list|(
name|bsize
parameter_list|)
value|calloc(1, bsize)
end_define

begin_define
define|#
directive|define
name|mem_free
parameter_list|(
name|ptr
parameter_list|,
name|bsize
parameter_list|)
value|free(ptr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<rpc/netconfig.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<netconfig.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The netbuf structure is defined here, because FreeBSD / NetBSD only use  * it inside the RPC code. It's in<xti.h> on SVR4, but it would be confusing  * to have an xti.h, since FreeBSD / NetBSD does not support XTI/TLI.  */
end_comment

begin_comment
comment|/*  * The netbuf structure is used for transport-independent address storage.  */
end_comment

begin_struct
struct|struct
name|netbuf
block|{
name|unsigned
name|int
name|maxlen
decl_stmt|;
name|unsigned
name|int
name|len
decl_stmt|;
name|void
modifier|*
name|buf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The format of the addres and options arguments of the XTI t_bind call.  * Only provided for compatibility, it should not be used.  */
end_comment

begin_struct
struct|struct
name|t_bind
block|{
name|struct
name|netbuf
name|addr
decl_stmt|;
name|unsigned
name|int
name|qlen
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Internal library and rpcbind use. This is not an exported interface, do  * not use.  */
end_comment

begin_struct
struct|struct
name|__rpc_sockinfo
block|{
name|int
name|si_af
decl_stmt|;
name|int
name|si_proto
decl_stmt|;
name|int
name|si_socktype
decl_stmt|;
name|int
name|si_alen
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_TYPES_H */
end_comment

end_unit

