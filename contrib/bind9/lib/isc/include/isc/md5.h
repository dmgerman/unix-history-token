begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: md5.h,v 1.8.206.1 2004/03/06 08:14:43 marka Exp $ */
end_comment

begin_comment
comment|/*  * This is the header file for the MD5 message-digest algorithm.  * The algorithm is due to Ron Rivest.  This code was  * written by Colin Plumb in 1993, no copyright is claimed.  * This code is in the public domain; do with it what you wish.  *  * Equivalent code is available from RSA Data Security, Inc.  * This code has been tested against that, and is equivalent,  * except that you don't need to include two pages of legalese  * with every copy.  *  * To compute the message digest of a chunk of bytes, declare an  * MD5Context structure, pass it to MD5Init, call MD5Update as  * needed on buffers full of bytes, and then call MD5Final, which  * will fill a supplied 16-byte array with the digest.  *  * Changed so as no longer to depend on Colin Plumb's `usual.h'  * header definitions; now uses stuff from dpkg's config.h  *  - Ian Jackson<ijackson@nyx.cs.du.edu>.  * Still in the public domain.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_MD5_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_MD5_H
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
file|<isc/types.h>
end_include

begin_define
define|#
directive|define
name|ISC_MD5_DIGESTLENGTH
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isc_uint32_t
name|buf
index|[
literal|4
index|]
decl_stmt|;
name|isc_uint32_t
name|bytes
index|[
literal|2
index|]
decl_stmt|;
name|isc_uint32_t
name|in
index|[
literal|16
index|]
decl_stmt|;
block|}
name|isc_md5_t
typedef|;
end_typedef

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|void
name|isc_md5_init
parameter_list|(
name|isc_md5_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_md5_invalidate
parameter_list|(
name|isc_md5_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_md5_update
parameter_list|(
name|isc_md5_t
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
name|isc_md5_final
parameter_list|(
name|isc_md5_t
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
comment|/* ISC_MD5_H */
end_comment

end_unit

