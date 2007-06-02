begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: dst.h,v 1.1.6.5 2006/01/27 23:57:44 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DST_DST_H
end_ifndef

begin_define
define|#
directive|define
name|DST_DST_H
value|1
end_define

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_comment
comment|/*%  * The dst_key structure is opaque.  Applications should use the accessor  * functions provided to retrieve key attributes.  If an application needs  * to set attributes, new accessor functions will be written.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dst_key
name|dst_key_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dst_context
name|dst_context_t
typedef|;
end_typedef

begin_comment
comment|/* DST algorithm codes */
end_comment

begin_define
define|#
directive|define
name|DST_ALG_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|DST_ALG_RSAMD5
value|1
end_define

begin_define
define|#
directive|define
name|DST_ALG_RSA
value|DST_ALG_RSAMD5
end_define

begin_comment
comment|/*%< backwards compatibility */
end_comment

begin_define
define|#
directive|define
name|DST_ALG_DH
value|2
end_define

begin_define
define|#
directive|define
name|DST_ALG_DSA
value|3
end_define

begin_define
define|#
directive|define
name|DST_ALG_ECC
value|4
end_define

begin_define
define|#
directive|define
name|DST_ALG_RSASHA1
value|5
end_define

begin_define
define|#
directive|define
name|DST_ALG_HMACMD5
value|157
end_define

begin_define
define|#
directive|define
name|DST_ALG_GSSAPI
value|160
end_define

begin_define
define|#
directive|define
name|DST_ALG_HMACSHA1
value|161
end_define

begin_comment
comment|/* XXXMPA */
end_comment

begin_define
define|#
directive|define
name|DST_ALG_HMACSHA224
value|162
end_define

begin_comment
comment|/* XXXMPA */
end_comment

begin_define
define|#
directive|define
name|DST_ALG_HMACSHA256
value|163
end_define

begin_comment
comment|/* XXXMPA */
end_comment

begin_define
define|#
directive|define
name|DST_ALG_HMACSHA384
value|164
end_define

begin_comment
comment|/* XXXMPA */
end_comment

begin_define
define|#
directive|define
name|DST_ALG_HMACSHA512
value|165
end_define

begin_comment
comment|/* XXXMPA */
end_comment

begin_define
define|#
directive|define
name|DST_ALG_PRIVATE
value|254
end_define

begin_define
define|#
directive|define
name|DST_ALG_EXPAND
value|255
end_define

begin_define
define|#
directive|define
name|DST_MAX_ALGS
value|255
end_define

begin_comment
comment|/*% A buffer of this size is large enough to hold any key */
end_comment

begin_define
define|#
directive|define
name|DST_KEY_MAXSIZE
value|1280
end_define

begin_comment
comment|/*%  * A buffer of this size is large enough to hold the textual representation  * of any key  */
end_comment

begin_define
define|#
directive|define
name|DST_KEY_MAXTEXTSIZE
value|2048
end_define

begin_comment
comment|/*% 'Type' for dst_read_key() */
end_comment

begin_define
define|#
directive|define
name|DST_TYPE_KEY
value|0x1000000
end_define

begin_comment
comment|/* KEY key */
end_comment

begin_define
define|#
directive|define
name|DST_TYPE_PRIVATE
value|0x2000000
end_define

begin_define
define|#
directive|define
name|DST_TYPE_PUBLIC
value|0x4000000
end_define

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|isc_result_t
name|dst_lib_init
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_entropy_t
modifier|*
name|ectx
parameter_list|,
name|unsigned
name|int
name|eflags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Initializes the DST subsystem.  *  * Requires:  * \li 	"mctx" is a valid memory context  * \li	"ectx" is a valid entropy context  *  * Returns:  * \li	ISC_R_SUCCESS  * \li	ISC_R_NOMEMORY  *  * Ensures:  * \li	DST is properly initialized.  */
end_comment

begin_function_decl
name|void
name|dst_lib_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Releases all resources allocated by DST.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dst_algorithm_supported
parameter_list|(
name|unsigned
name|int
name|alg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Checks that a given algorithm is supported by DST.  *  * Returns:  * \li	ISC_TRUE  * \li	ISC_FALSE  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_context_create
parameter_list|(
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dst_context_t
modifier|*
modifier|*
name|dctxp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Creates a context to be used for a sign or verify operation.  *  * Requires:  * \li	"key" is a valid key.  * \li	"mctx" is a valid memory context.  * \li	dctxp != NULL&& *dctxp == NULL  *  * Returns:  * \li	ISC_R_SUCCESS  * \li	ISC_R_NOMEMORY  *  * Ensures:  * \li	*dctxp will contain a usable context.  */
end_comment

begin_function_decl
name|void
name|dst_context_destroy
parameter_list|(
name|dst_context_t
modifier|*
modifier|*
name|dctxp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroys all memory associated with a context.  *  * Requires:  * \li	*dctxp != NULL&& *dctxp == NULL  *  * Ensures:  * \li	*dctxp == NULL  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_context_adddata
parameter_list|(
name|dst_context_t
modifier|*
name|dctx
parameter_list|,
specifier|const
name|isc_region_t
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Incrementally adds data to the context to be used in a sign or verify  * operation.  *  * Requires:  * \li	"dctx" is a valid context  * \li	"data" is a valid region  *  * Returns:  * \li	ISC_R_SUCCESS  * \li	DST_R_SIGNFAILURE  * \li	all other errors indicate failure  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_context_sign
parameter_list|(
name|dst_context_t
modifier|*
name|dctx
parameter_list|,
name|isc_buffer_t
modifier|*
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Computes a signature using the data and key stored in the context.  *  * Requires:  * \li	"dctx" is a valid context.  * \li	"sig" is a valid buffer.  *  * Returns:  * \li	ISC_R_SUCCESS  * \li	DST_R_VERIFYFAILURE  * \li	all other errors indicate failure  *  * Ensures:  * \li	"sig" will contain the signature  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_context_verify
parameter_list|(
name|dst_context_t
modifier|*
name|dctx
parameter_list|,
name|isc_region_t
modifier|*
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Verifies the signature using the data and key stored in the context.  *  * Requires:  * \li	"dctx" is a valid context.  * \li	"sig" is a valid region.  *  * Returns:  * \li	ISC_R_SUCCESS  * \li	all other errors indicate failure  *  * Ensures:  * \li	"sig" will contain the signature  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_key_computesecret
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|pub
parameter_list|,
specifier|const
name|dst_key_t
modifier|*
name|priv
parameter_list|,
name|isc_buffer_t
modifier|*
name|secret
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Computes a shared secret from two (Diffie-Hellman) keys.  *  * Requires:  * \li	"pub" is a valid key that can be used to derive a shared secret  * \li	"priv" is a valid private key that can be used to derive a shared secret  * \li	"secret" is a valid buffer  *  * Returns:  * \li	ISC_R_SUCCESS  * \li	any other result indicates failure  *  * Ensures:  * \li	If successful, secret will contain the derived shared secret.  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_key_fromfile
parameter_list|(
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_keytag_t
name|id
parameter_list|,
name|unsigned
name|int
name|alg
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|directory
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dst_key_t
modifier|*
modifier|*
name|keyp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Reads a key from permanent storage.  The key can either be a public or  * private key, and is specified by name, algorithm, and id.  If a private key  * is specified, the public key must also be present.  If directory is NULL,  * the current directory is assumed.  *  * Requires:  * \li	"name" is a valid absolute dns name.  * \li	"id" is a valid key tag identifier.  * \li	"alg" is a supported key algorithm.  * \li	"type" is DST_TYPE_PUBLIC, DST_TYPE_PRIVATE, or the bitwise union.  *		  DST_TYPE_KEY look for a KEY record otherwise DNSKEY  * \li	"mctx" is a valid memory context.  * \li	"keyp" is not NULL and "*keyp" is NULL.  *  * Returns:  * \li	ISC_R_SUCCESS  * \li	any other result indicates failure  *  * Ensures:  * \li	If successful, *keyp will contain a valid key.  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_key_fromnamedfile
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|type
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dst_key_t
modifier|*
modifier|*
name|keyp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Reads a key from permanent storage.  The key can either be a public or  * key, and is specified by filename.  If a private key is specified, the  * public key must also be present.  *  * Requires:  * \li	"filename" is not NULL  * \li	"type" is DST_TYPE_PUBLIC, DST_TYPE_PRIVATE, or the bitwise union  *		  DST_TYPE_KEY look for a KEY record otherwise DNSKEY  * \li	"mctx" is a valid memory context  * \li	"keyp" is not NULL and "*keyp" is NULL.  *  * Returns:  * \li	ISC_R_SUCCESS  * \li	any other result indicates failure  *  * Ensures:  * \li	If successful, *keyp will contain a valid key.  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_key_read_public
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|type
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dst_key_t
modifier|*
modifier|*
name|keyp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Reads a public key from permanent storage.  The key must be a public key.  *  * Requires:  * \li	"filename" is not NULL  * \li	"type" is DST_TYPE_KEY look for a KEY record otherwise DNSKEY  * \li	"mctx" is a valid memory context  * \li	"keyp" is not NULL and "*keyp" is NULL.  *  * Returns:  * \li	ISC_R_SUCCESS  * \li	DST_R_BADKEYTYPE if the key type is not the expected one  * \li	ISC_R_UNEXPECTEDTOKEN if the file can not be parsed as a public key  * \li	any other result indicates failure  *  * Ensures:  * \li	If successful, *keyp will contain a valid key.  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_key_tofile
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|directory
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Writes a key to permanent storage.  The key can either be a public or  * private key.  Public keys are written in DNS format and private keys  * are written as a set of base64 encoded values.  If directory is NULL,  * the current directory is assumed.  *  * Requires:  * \li	"key" is a valid key.  * \li	"type" is DST_TYPE_PUBLIC, DST_TYPE_PRIVATE, or the bitwise union  *  * Returns:  * \li	ISC_R_SUCCESS  * \li	any other result indicates failure  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_key_fromdns
parameter_list|(
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|isc_buffer_t
modifier|*
name|source
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dst_key_t
modifier|*
modifier|*
name|keyp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Converts a DNS KEY record into a DST key.  *  * Requires:  * \li	"name" is a valid absolute dns name.  * \li	"source" is a valid buffer.  There must be at least 4 bytes available.  * \li	"mctx" is a valid memory context.  * \li	"keyp" is not NULL and "*keyp" is NULL.  *  * Returns:  * \li	ISC_R_SUCCESS  * \li	any other result indicates failure  *  * Ensures:  * \li	If successful, *keyp will contain a valid key, and the consumed  *	pointer in data will be advanced.  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_key_todns
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Converts a DST key into a DNS KEY record.  *  * Requires:  * \li	"key" is a valid key.  * \li	"target" is a valid buffer.  There must be at least 4 bytes unused.  *  * Returns:  * \li	ISC_R_SUCCESS  * \li	any other result indicates failure  *  * Ensures:  * \li	If successful, the used pointer in 'target' is advanced by at least 4.  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_key_frombuffer
parameter_list|(
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
name|alg
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|,
name|unsigned
name|int
name|protocol
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|isc_buffer_t
modifier|*
name|source
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dst_key_t
modifier|*
modifier|*
name|keyp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Converts a buffer containing DNS KEY RDATA into a DST key.  *  * Requires:  *\li	"name" is a valid absolute dns name.  *\li	"alg" is a supported key algorithm.  *\li	"source" is a valid buffer.  *\li	"mctx" is a valid memory context.  *\li	"keyp" is not NULL and "*keyp" is NULL.  *  * Returns:  *\li 	ISC_R_SUCCESS  * \li	any other result indicates failure  *  * Ensures:  *\li	If successful, *keyp will contain a valid key, and the consumed  *	pointer in source will be advanced.  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_key_tobuffer
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Converts a DST key into DNS KEY RDATA format.  *  * Requires:  *\li	"key" is a valid key.  *\li	"target" is a valid buffer.  *  * Returns:  *\li 	ISC_R_SUCCESS  * \li	any other result indicates failure  *  * Ensures:  *\li	If successful, the used pointer in 'target' is advanced.  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_key_privatefrombuffer
parameter_list|(
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|isc_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Converts a public key into a private key, reading the private key  * information from the buffer.  The buffer should contain the same data  * as the .private key file would.  *  * Requires:  *\li	"key" is a valid public key.  *\li	"buffer" is not NULL.  *  * Returns:  *\li 	ISC_R_SUCCESS  * \li	any other result indicates failure  *  * Ensures:  *\li	If successful, key will contain a valid private key.  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_key_fromgssapi
parameter_list|(
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|opaque
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dst_key_t
modifier|*
modifier|*
name|keyp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Converts a GSSAPI opaque context id into a DST key.  *  * Requires:  *\li	"name" is a valid absolute dns name.  *\li	"opaque" is a GSSAPI context id.  *\li	"mctx" is a valid memory context.  *\li	"keyp" is not NULL and "*keyp" is NULL.  *  * Returns:  *\li 	ISC_R_SUCCESS  * \li	any other result indicates failure  *  * Ensures:  *\li	If successful, *keyp will contain a valid key and be responsible for  *	the context id.  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_key_generate
parameter_list|(
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
name|alg
parameter_list|,
name|unsigned
name|int
name|bits
parameter_list|,
name|unsigned
name|int
name|param
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|,
name|unsigned
name|int
name|protocol
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dst_key_t
modifier|*
modifier|*
name|keyp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Generate a DST key (or keypair) with the supplied parameters.  The  * interpretation of the "param" field depends on the algorithm:  * \code  * 	RSA:	exponent  * 		0	use exponent 3  * 		!0	use Fermat4 (2^16 + 1)  * 	DH:	generator  * 		0	default - use well known prime if bits == 768 or 1024,  * 			otherwise use 2 as the generator.  * 		!0	use this value as the generator.  * 	DSA:	unused  * 	HMACMD5: entropy  *		0	default - require good entropy  *		!0	lack of good entropy is ok  *\endcode  *  * Requires:  *\li	"name" is a valid absolute dns name.  *\li	"keyp" is not NULL and "*keyp" is NULL.  *  * Returns:  *\li 	ISC_R_SUCCESS  * \li	any other result indicates failure  *  * Ensures:  *\li	If successful, *keyp will contain a valid key.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dst_key_compare
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key1
parameter_list|,
specifier|const
name|dst_key_t
modifier|*
name|key2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Compares two DST keys.  *  * Requires:  *\li	"key1" is a valid key.  *\li	"key2" is a valid key.  *  * Returns:  *\li 	ISC_TRUE  * \li	ISC_FALSE  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dst_key_paramcompare
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key1
parameter_list|,
specifier|const
name|dst_key_t
modifier|*
name|key2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Compares the parameters of two DST keys.  This is used to determine if  * two (Diffie-Hellman) keys can be used to derive a shared secret.  *  * Requires:  *\li	"key1" is a valid key.  *\li	"key2" is a valid key.  *  * Returns:  *\li 	ISC_TRUE  * \li	ISC_FALSE  */
end_comment

begin_function_decl
name|void
name|dst_key_free
parameter_list|(
name|dst_key_t
modifier|*
modifier|*
name|keyp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Release all memory associated with the key.  *  * Requires:  *\li	"keyp" is not NULL and "*keyp" is a valid key.  *  * Ensures:  *\li	All memory associated with "*keyp" will be freed.  *\li	*keyp == NULL  */
end_comment

begin_comment
comment|/*%<  * Accessor functions to obtain key fields.  *  * Require:  *\li	"key" is a valid key.  */
end_comment

begin_function_decl
name|dns_name_t
modifier|*
name|dst_key_name
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|dst_key_size
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|dst_key_proto
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|dst_key_alg
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_uint32_t
name|dst_key_flags
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dns_keytag_t
name|dst_key_id
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dns_rdataclass_t
name|dst_key_class
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|dst_key_isprivate
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|dst_key_iszonekey
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|dst_key_isnullkey
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dst_key_buildfilename
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|directory
parameter_list|,
name|isc_buffer_t
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Generates the filename used by dst to store the specified key.  * If directory is NULL, the current directory is assumed.  *  * Requires:  *\li	"key" is a valid key  *\li	"type" is either DST_TYPE_PUBLIC, DST_TYPE_PRIVATE, or 0 for no suffix.  *\li	"out" is a valid buffer  *  * Ensures:  *\li	the file name will be written to "out", and the used pointer will  *		be advanced.  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_key_sigsize
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|unsigned
name|int
modifier|*
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Computes the size of a signature generated by the given key.  *  * Requires:  *\li	"key" is a valid key.  *\li	"n" is not NULL  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	DST_R_UNSUPPORTEDALG  *  * Ensures:  *\li	"n" stores the size of a generated signature  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_key_secretsize
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|unsigned
name|int
modifier|*
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Computes the size of a shared secret generated by the given key.  *  * Requires:  *\li	"key" is a valid key.  *\li	"n" is not NULL  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	DST_R_UNSUPPORTEDALG  *  * Ensures:  *\li	"n" stores the size of a generated shared secret  */
end_comment

begin_function_decl
name|isc_uint16_t
name|dst_region_computeid
parameter_list|(
specifier|const
name|isc_region_t
modifier|*
name|source
parameter_list|,
name|unsigned
name|int
name|alg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Computes the key id of the key stored in the provided region with the  * given algorithm.  *  * Requires:  *\li	"source" contains a valid, non-NULL region.  *  * Returns:  *\li 	the key id  */
end_comment

begin_function_decl
name|isc_uint16_t
name|dst_key_getbits
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the number of digest bits required (0 == MAX).  *  * Requires:  *	"key" is a valid key.  */
end_comment

begin_function_decl
name|void
name|dst_key_setbits
parameter_list|(
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|isc_uint16_t
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the number of digest bits required (0 == MAX).  *  * Requires:  *	"key" is a valid key.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DST_DST_H */
end_comment

end_unit

