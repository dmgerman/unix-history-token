begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: context.h,v 1.14.206.1 2004/03/06 08:15:34 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LWRES_CONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LWRES_CONTEXT_H
value|1
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<lwres/lang.h>
end_include

begin_include
include|#
directive|include
file|<lwres/int.h>
end_include

begin_include
include|#
directive|include
file|<lwres/result.h>
end_include

begin_comment
comment|/*  * Used to set various options such as timeout, authentication, etc  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|lwres_context
name|lwres_context_t
typedef|;
end_typedef

begin_macro
name|LWRES_LANG_BEGINDECLS
end_macro

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|lwres_malloc_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|size_t
name|length
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|lwres_free_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|void
modifier|*
name|mem
parameter_list|,
name|size_t
name|length
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * XXXMLG  *  * Make the server reload /etc/resolv.conf periodically.  *  * Make the server do sortlist/searchlist.  *  * Client side can disable the search/sortlist processing.  *  * Use an array of addresses/masks and searchlist for client-side, and  * if added to the client disable the processing on the server.  *  * Share /etc/resolv.conf data between contexts.  */
end_comment

begin_comment
comment|/*  * _SERVERMODE  *	Don't allocate and connect a socket to the server, since the  *	caller _is_ a server.  */
end_comment

begin_define
define|#
directive|define
name|LWRES_CONTEXT_SERVERMODE
value|0x00000001U
end_define

begin_function_decl
name|lwres_result_t
name|lwres_context_create
parameter_list|(
name|lwres_context_t
modifier|*
modifier|*
name|contextp
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|lwres_malloc_t
name|malloc_function
parameter_list|,
name|lwres_free_t
name|free_function
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate a lwres context.  This is used in all lwres calls.  *  * Memory management can be replaced here by passing in two functions.  * If one is non-NULL, they must both be non-NULL.  "arg" is passed to  * these functions.  *  * Contexts are not thread safe.  Document at the top of the file.  * XXXMLG  *  * If they are NULL, the standard malloc() and free() will be used.  *  * Requires:  *  *	contextp != NULL&& contextp == NULL.  *  * Returns:  *  *	Returns 0 on success, non-zero on failure.  */
end_comment

begin_function_decl
name|void
name|lwres_context_destroy
parameter_list|(
name|lwres_context_t
modifier|*
modifier|*
name|contextp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Frees all memory associated with a lwres context.  *  * Requires:  *  *	contextp != NULL&& contextp == NULL.  */
end_comment

begin_function_decl
name|lwres_uint32_t
name|lwres_context_nextserial
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XXXMLG Document  */
end_comment

begin_function_decl
name|void
name|lwres_context_initserial
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_uint32_t
name|serial
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_context_freemem
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|void
modifier|*
name|mem
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|lwres_context_allocmem
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lwres_context_getsocket
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_context_send
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|void
modifier|*
name|sendbase
parameter_list|,
name|int
name|sendlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_context_recv
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|void
modifier|*
name|recvbase
parameter_list|,
name|int
name|recvlen
parameter_list|,
name|int
modifier|*
name|recvd_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_context_sendrecv
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|void
modifier|*
name|sendbase
parameter_list|,
name|int
name|sendlen
parameter_list|,
name|void
modifier|*
name|recvbase
parameter_list|,
name|int
name|recvlen
parameter_list|,
name|int
modifier|*
name|recvd_len
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|LWRES_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LWRES_CONTEXT_H */
end_comment

end_unit

