begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2008, 2014  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: iterated_hash.h,v 1.3 2008/09/25 04:02:39 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_ITERATED_HASH_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_ITERATED_HASH_H
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
file|<isc/sha1.h>
end_include

begin_comment
comment|/*  * The maximal hash length that can be encoded in a name  * using base32hex.  floor(255/8)*5  */
end_comment

begin_define
define|#
directive|define
name|NSEC3_MAX_HASH_LENGTH
value|155
end_define

begin_comment
comment|/*  * The maximum has that can be encoded in a single label using  * base32hex.  floor(63/8)*5  */
end_comment

begin_define
define|#
directive|define
name|NSEC3_MAX_LABEL_HASH
value|35
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|int
name|isc_iterated_hash
parameter_list|(
name|unsigned
name|char
name|out
index|[
name|NSEC3_MAX_HASH_LENGTH
index|]
parameter_list|,
name|unsigned
name|int
name|hashalg
parameter_list|,
name|int
name|iterations
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|salt
parameter_list|,
name|int
name|saltlength
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|in
parameter_list|,
name|int
name|inlength
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
comment|/* ISC_ITERATED_HASH_H */
end_comment

end_unit

