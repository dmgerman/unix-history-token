begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Portions Copyright (C) 2004-2010, 2012  Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (C) 2000-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC AND NETWORK ASSOCIATES DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE  * FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR  * IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Portions Copyright (C) 1995-2000 by Network Associates, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC AND NETWORK ASSOCIATES DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE  * FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR  * IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: dst_parse.h,v 1.17 2010/12/23 23:47:08 tbox Exp $ */
end_comment

begin_comment
comment|/*! \file */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DST_DST_PARSE_H
end_ifndef

begin_define
define|#
directive|define
name|DST_DST_PARSE_H
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
file|<dst/dst.h>
end_include

begin_define
define|#
directive|define
name|MAXFIELDSIZE
value|512
end_define

begin_comment
comment|/*  * Maximum number of fields in a private file is 18 (12 algorithm-  * specific fields for RSA, plus 6 generic fields).  */
end_comment

begin_define
define|#
directive|define
name|MAXFIELDS
value|12+6
end_define

begin_define
define|#
directive|define
name|TAG_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|TAG_ALG
parameter_list|(
name|tag
parameter_list|)
value|((unsigned int)(tag)>> TAG_SHIFT)
end_define

begin_define
define|#
directive|define
name|TAG
parameter_list|(
name|alg
parameter_list|,
name|off
parameter_list|)
value|(((alg)<< TAG_SHIFT) + (off))
end_define

begin_comment
comment|/* These are used by both RSA-MD5 and RSA-SHA1 */
end_comment

begin_define
define|#
directive|define
name|RSA_NTAGS
value|11
end_define

begin_define
define|#
directive|define
name|TAG_RSA_MODULUS
value|((DST_ALG_RSAMD5<< TAG_SHIFT) + 0)
end_define

begin_define
define|#
directive|define
name|TAG_RSA_PUBLICEXPONENT
value|((DST_ALG_RSAMD5<< TAG_SHIFT) + 1)
end_define

begin_define
define|#
directive|define
name|TAG_RSA_PRIVATEEXPONENT
value|((DST_ALG_RSAMD5<< TAG_SHIFT) + 2)
end_define

begin_define
define|#
directive|define
name|TAG_RSA_PRIME1
value|((DST_ALG_RSAMD5<< TAG_SHIFT) + 3)
end_define

begin_define
define|#
directive|define
name|TAG_RSA_PRIME2
value|((DST_ALG_RSAMD5<< TAG_SHIFT) + 4)
end_define

begin_define
define|#
directive|define
name|TAG_RSA_EXPONENT1
value|((DST_ALG_RSAMD5<< TAG_SHIFT) + 5)
end_define

begin_define
define|#
directive|define
name|TAG_RSA_EXPONENT2
value|((DST_ALG_RSAMD5<< TAG_SHIFT) + 6)
end_define

begin_define
define|#
directive|define
name|TAG_RSA_COEFFICIENT
value|((DST_ALG_RSAMD5<< TAG_SHIFT) + 7)
end_define

begin_define
define|#
directive|define
name|TAG_RSA_ENGINE
value|((DST_ALG_RSAMD5<< TAG_SHIFT) + 8)
end_define

begin_define
define|#
directive|define
name|TAG_RSA_LABEL
value|((DST_ALG_RSAMD5<< TAG_SHIFT) + 9)
end_define

begin_define
define|#
directive|define
name|TAG_RSA_PIN
value|((DST_ALG_RSAMD5<< TAG_SHIFT) + 10)
end_define

begin_define
define|#
directive|define
name|DH_NTAGS
value|4
end_define

begin_define
define|#
directive|define
name|TAG_DH_PRIME
value|((DST_ALG_DH<< TAG_SHIFT) + 0)
end_define

begin_define
define|#
directive|define
name|TAG_DH_GENERATOR
value|((DST_ALG_DH<< TAG_SHIFT) + 1)
end_define

begin_define
define|#
directive|define
name|TAG_DH_PRIVATE
value|((DST_ALG_DH<< TAG_SHIFT) + 2)
end_define

begin_define
define|#
directive|define
name|TAG_DH_PUBLIC
value|((DST_ALG_DH<< TAG_SHIFT) + 3)
end_define

begin_define
define|#
directive|define
name|DSA_NTAGS
value|5
end_define

begin_define
define|#
directive|define
name|TAG_DSA_PRIME
value|((DST_ALG_DSA<< TAG_SHIFT) + 0)
end_define

begin_define
define|#
directive|define
name|TAG_DSA_SUBPRIME
value|((DST_ALG_DSA<< TAG_SHIFT) + 1)
end_define

begin_define
define|#
directive|define
name|TAG_DSA_BASE
value|((DST_ALG_DSA<< TAG_SHIFT) + 2)
end_define

begin_define
define|#
directive|define
name|TAG_DSA_PRIVATE
value|((DST_ALG_DSA<< TAG_SHIFT) + 3)
end_define

begin_define
define|#
directive|define
name|TAG_DSA_PUBLIC
value|((DST_ALG_DSA<< TAG_SHIFT) + 4)
end_define

begin_define
define|#
directive|define
name|GOST_NTAGS
value|1
end_define

begin_define
define|#
directive|define
name|TAG_GOST_PRIVASN1
value|((DST_ALG_ECCGOST<< TAG_SHIFT) + 0)
end_define

begin_define
define|#
directive|define
name|ECDSA_NTAGS
value|1
end_define

begin_define
define|#
directive|define
name|TAG_ECDSA_PRIVATEKEY
value|((DST_ALG_ECDSA256<< TAG_SHIFT) + 0)
end_define

begin_define
define|#
directive|define
name|OLD_HMACMD5_NTAGS
value|1
end_define

begin_define
define|#
directive|define
name|HMACMD5_NTAGS
value|2
end_define

begin_define
define|#
directive|define
name|TAG_HMACMD5_KEY
value|((DST_ALG_HMACMD5<< TAG_SHIFT) + 0)
end_define

begin_define
define|#
directive|define
name|TAG_HMACMD5_BITS
value|((DST_ALG_HMACMD5<< TAG_SHIFT) + 1)
end_define

begin_define
define|#
directive|define
name|HMACSHA1_NTAGS
value|2
end_define

begin_define
define|#
directive|define
name|TAG_HMACSHA1_KEY
value|((DST_ALG_HMACSHA1<< TAG_SHIFT) + 0)
end_define

begin_define
define|#
directive|define
name|TAG_HMACSHA1_BITS
value|((DST_ALG_HMACSHA1<< TAG_SHIFT) + 1)
end_define

begin_define
define|#
directive|define
name|HMACSHA224_NTAGS
value|2
end_define

begin_define
define|#
directive|define
name|TAG_HMACSHA224_KEY
value|((DST_ALG_HMACSHA224<< TAG_SHIFT) + 0)
end_define

begin_define
define|#
directive|define
name|TAG_HMACSHA224_BITS
value|((DST_ALG_HMACSHA224<< TAG_SHIFT) + 1)
end_define

begin_define
define|#
directive|define
name|HMACSHA256_NTAGS
value|2
end_define

begin_define
define|#
directive|define
name|TAG_HMACSHA256_KEY
value|((DST_ALG_HMACSHA256<< TAG_SHIFT) + 0)
end_define

begin_define
define|#
directive|define
name|TAG_HMACSHA256_BITS
value|((DST_ALG_HMACSHA256<< TAG_SHIFT) + 1)
end_define

begin_define
define|#
directive|define
name|HMACSHA384_NTAGS
value|2
end_define

begin_define
define|#
directive|define
name|TAG_HMACSHA384_KEY
value|((DST_ALG_HMACSHA384<< TAG_SHIFT) + 0)
end_define

begin_define
define|#
directive|define
name|TAG_HMACSHA384_BITS
value|((DST_ALG_HMACSHA384<< TAG_SHIFT) + 1)
end_define

begin_define
define|#
directive|define
name|HMACSHA512_NTAGS
value|2
end_define

begin_define
define|#
directive|define
name|TAG_HMACSHA512_KEY
value|((DST_ALG_HMACSHA512<< TAG_SHIFT) + 0)
end_define

begin_define
define|#
directive|define
name|TAG_HMACSHA512_BITS
value|((DST_ALG_HMACSHA512<< TAG_SHIFT) + 1)
end_define

begin_struct
struct|struct
name|dst_private_element
block|{
name|unsigned
name|short
name|tag
decl_stmt|;
name|unsigned
name|short
name|length
decl_stmt|;
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|dst_private_element
name|dst_private_element_t
typedef|;
end_typedef

begin_struct
struct|struct
name|dst_private
block|{
name|unsigned
name|short
name|nelements
decl_stmt|;
name|dst_private_element_t
name|elements
index|[
name|MAXFIELDS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|dst_private
name|dst_private_t
typedef|;
end_typedef

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|void
name|dst__privstruct_free
parameter_list|(
name|dst_private_t
modifier|*
name|priv
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dst__privstruct_parse
parameter_list|(
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|unsigned
name|int
name|alg
parameter_list|,
name|isc_lex_t
modifier|*
name|lex
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dst_private_t
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dst__privstruct_writefile
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|,
specifier|const
name|dst_private_t
modifier|*
name|priv
parameter_list|,
specifier|const
name|char
modifier|*
name|directory
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
comment|/* DST_DST_PARSE_H */
end_comment

end_unit

