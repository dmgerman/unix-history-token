begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: hmacmd5.h,v 1.4.206.1 2004/03/06 08:14:42 marka Exp $ */
end_comment

begin_comment
comment|/*  * This is the header file for the HMAC-MD5 keyed hash algorithm  * described in RFC 2104.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_HMACMD5_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_HMACMD5_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/md5.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_define
define|#
directive|define
name|ISC_HMACMD5_KEYLENGTH
value|64
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isc_md5_t
name|md5ctx
decl_stmt|;
name|unsigned
name|char
name|key
index|[
name|ISC_HMACMD5_KEYLENGTH
index|]
decl_stmt|;
block|}
name|isc_hmacmd5_t
typedef|;
end_typedef

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|void
name|isc_hmacmd5_init
parameter_list|(
name|isc_hmacmd5_t
modifier|*
name|ctx
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_hmacmd5_invalidate
parameter_list|(
name|isc_hmacmd5_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_hmacmd5_update
parameter_list|(
name|isc_hmacmd5_t
modifier|*
name|ctx
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_hmacmd5_sign
parameter_list|(
name|isc_hmacmd5_t
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

begin_function_decl
name|isc_boolean_t
name|isc_hmacmd5_verify
parameter_list|(
name|isc_hmacmd5_t
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
comment|/* ISC_HMACMD5_H */
end_comment

end_unit

