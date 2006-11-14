begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_SHA1_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_SHA1_H
value|1
end_define

begin_comment
comment|/* $Id: sha1.h,v 1.8.206.1 2004/03/06 08:14:48 marka Exp $ */
end_comment

begin_comment
comment|/*	$NetBSD: sha1.h,v 1.2 1998/05/29 22:55:44 thorpej Exp $	*/
end_comment

begin_comment
comment|/*  * SHA-1 in C  * By Steve Reid<steve@edmweb.com>  * 100% Public Domain  */
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_define
define|#
directive|define
name|ISC_SHA1_DIGESTLENGTH
value|20
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isc_uint32_t
name|state
index|[
literal|5
index|]
decl_stmt|;
name|isc_uint32_t
name|count
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|buffer
index|[
literal|64
index|]
decl_stmt|;
block|}
name|isc_sha1_t
typedef|;
end_typedef

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|void
name|isc_sha1_init
parameter_list|(
name|isc_sha1_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha1_invalidate
parameter_list|(
name|isc_sha1_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha1_update
parameter_list|(
name|isc_sha1_t
modifier|*
name|ctx
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha1_final
parameter_list|(
name|isc_sha1_t
modifier|*
name|ctx
parameter_list|,
name|unsigned
name|char
modifier|*
name|digest
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_SHA1_H */
end_comment

end_unit

