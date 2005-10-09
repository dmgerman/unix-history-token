begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: context_p.h,v 1.12.206.1 2004/03/06 08:15:30 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LWRES_CONTEXT_P_H
end_ifndef

begin_define
define|#
directive|define
name|LWRES_CONTEXT_P_H
value|1
end_define

begin_comment
comment|/*  * Helper functions, assuming the context is always called "ctx" in  * the scope these functions are called from.  */
end_comment

begin_define
define|#
directive|define
name|CTXMALLOC
parameter_list|(
name|len
parameter_list|)
value|ctx->malloc(ctx->arg, (len))
end_define

begin_define
define|#
directive|define
name|CTXFREE
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|)
value|ctx->free(ctx->arg, (addr), (len))
end_define

begin_define
define|#
directive|define
name|LWRES_DEFAULT_TIMEOUT
value|120
end_define

begin_comment
comment|/* 120 seconds for a reply */
end_comment

begin_comment
comment|/*  * Not all the attributes here are actually settable by the application at  * this time.  */
end_comment

begin_struct
struct|struct
name|lwres_context
block|{
name|unsigned
name|int
name|timeout
decl_stmt|;
comment|/* time to wait for reply */
name|lwres_uint32_t
name|serial
decl_stmt|;
comment|/* serial number state */
comment|/* 	 * For network I/O. 	 */
name|int
name|sock
decl_stmt|;
comment|/* socket to send on */
name|lwres_addr_t
name|address
decl_stmt|;
comment|/* address to send to */
comment|/* 	 * Function pointers for allocating memory. 	 */
name|lwres_malloc_t
name|malloc
decl_stmt|;
name|lwres_free_t
name|free
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
comment|/* 	 * resolv.conf-like data 	 */
name|lwres_conf_t
name|confdata
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LWRES_CONTEXT_P_H */
end_comment

end_unit

