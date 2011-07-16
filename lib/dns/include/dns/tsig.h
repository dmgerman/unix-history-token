begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2007, 2009-2011  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: tsig.h,v 1.59 2011-01-11 23:47:13 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_TSIG_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_TSIG_H
value|1
end_define

begin_comment
comment|/*! \file dns/tsig.h */
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/refcount.h>
end_include

begin_include
include|#
directive|include
file|<isc/rwlock.h>
end_include

begin_include
include|#
directive|include
file|<isc/stdio.h>
end_include

begin_include
include|#
directive|include
file|<isc/stdtime.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/name.h>
end_include

begin_include
include|#
directive|include
file|<dst/dst.h>
end_include

begin_comment
comment|/*  * Algorithms.  */
end_comment

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
specifier|extern
name|dns_name_t
modifier|*
name|dns_tsig_hmacmd5_name
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DNS_TSIG_HMACMD5_NAME
value|dns_tsig_hmacmd5_name
end_define

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
specifier|extern
name|dns_name_t
modifier|*
name|dns_tsig_gssapi_name
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DNS_TSIG_GSSAPI_NAME
value|dns_tsig_gssapi_name
end_define

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
specifier|extern
name|dns_name_t
modifier|*
name|dns_tsig_gssapims_name
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DNS_TSIG_GSSAPIMS_NAME
value|dns_tsig_gssapims_name
end_define

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
specifier|extern
name|dns_name_t
modifier|*
name|dns_tsig_hmacsha1_name
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DNS_TSIG_HMACSHA1_NAME
value|dns_tsig_hmacsha1_name
end_define

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
specifier|extern
name|dns_name_t
modifier|*
name|dns_tsig_hmacsha224_name
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DNS_TSIG_HMACSHA224_NAME
value|dns_tsig_hmacsha224_name
end_define

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
specifier|extern
name|dns_name_t
modifier|*
name|dns_tsig_hmacsha256_name
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DNS_TSIG_HMACSHA256_NAME
value|dns_tsig_hmacsha256_name
end_define

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
specifier|extern
name|dns_name_t
modifier|*
name|dns_tsig_hmacsha384_name
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DNS_TSIG_HMACSHA384_NAME
value|dns_tsig_hmacsha384_name
end_define

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
specifier|extern
name|dns_name_t
modifier|*
name|dns_tsig_hmacsha512_name
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DNS_TSIG_HMACSHA512_NAME
value|dns_tsig_hmacsha512_name
end_define

begin_comment
comment|/*%  * Default fudge value.  */
end_comment

begin_define
define|#
directive|define
name|DNS_TSIG_FUDGE
value|300
end_define

begin_struct
struct|struct
name|dns_tsig_keyring
block|{
name|dns_rbt_t
modifier|*
name|keys
decl_stmt|;
name|unsigned
name|int
name|writecount
decl_stmt|;
name|isc_rwlock_t
name|lock
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
comment|/* 	 * LRU list of generated key along with a count of the keys on the 	 * list and a maximum size. 	 */
name|unsigned
name|int
name|generated
decl_stmt|;
name|unsigned
name|int
name|maxgenerated
decl_stmt|;
name|ISC_LIST
argument_list|(
argument|dns_tsigkey_t
argument_list|)
name|lru
expr_stmt|;
name|unsigned
name|int
name|references
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dns_tsigkey
block|{
comment|/* Unlocked */
name|unsigned
name|int
name|magic
decl_stmt|;
comment|/*%< Magic number. */
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|dst_key_t
modifier|*
name|key
decl_stmt|;
comment|/*%< Key */
name|dns_name_t
name|name
decl_stmt|;
comment|/*%< Key name */
name|dns_name_t
modifier|*
name|algorithm
decl_stmt|;
comment|/*%< Algorithm name */
name|dns_name_t
modifier|*
name|creator
decl_stmt|;
comment|/*%< name that created secret */
name|isc_boolean_t
name|generated
decl_stmt|;
comment|/*%< was this generated? */
name|isc_stdtime_t
name|inception
decl_stmt|;
comment|/*%< start of validity period */
name|isc_stdtime_t
name|expire
decl_stmt|;
comment|/*%< end of validity period */
name|dns_tsig_keyring_t
modifier|*
name|ring
decl_stmt|;
comment|/*%< the enclosing keyring */
name|isc_refcount_t
name|refs
decl_stmt|;
comment|/*%< reference counter */
name|ISC_LINK
argument_list|(
argument|dns_tsigkey_t
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|dns_tsigkey_identity
parameter_list|(
name|tsigkey
parameter_list|)
define|\
value|((tsigkey) == NULL ? NULL : \ 	 (tsigkey)->generated ? ((tsigkey)->creator) : \ 	 (&((tsigkey)->name)))
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_tsigkey_create
parameter_list|(
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_name_t
modifier|*
name|algorithm
parameter_list|,
name|unsigned
name|char
modifier|*
name|secret
parameter_list|,
name|int
name|length
parameter_list|,
name|isc_boolean_t
name|generated
parameter_list|,
name|dns_name_t
modifier|*
name|creator
parameter_list|,
name|isc_stdtime_t
name|inception
parameter_list|,
name|isc_stdtime_t
name|expire
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_tsig_keyring_t
modifier|*
name|ring
parameter_list|,
name|dns_tsigkey_t
modifier|*
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_tsigkey_createfromkey
parameter_list|(
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_name_t
modifier|*
name|algorithm
parameter_list|,
name|dst_key_t
modifier|*
name|dstkey
parameter_list|,
name|isc_boolean_t
name|generated
parameter_list|,
name|dns_name_t
modifier|*
name|creator
parameter_list|,
name|isc_stdtime_t
name|inception
parameter_list|,
name|isc_stdtime_t
name|expire
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_tsig_keyring_t
modifier|*
name|ring
parameter_list|,
name|dns_tsigkey_t
modifier|*
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Creates a tsig key structure and saves it in the keyring.  If key is  *	not NULL, *key will contain a copy of the key.  The keys validity  *	period is specified by (inception, expire), and will not expire if  *	inception == expire.  If the key was generated, the creating identity,  *	if there is one, should be in the creator parameter.  Specifying an  *	unimplemented algorithm will cause failure only if dstkey != NULL; this  *	allows a transient key with an invalid algorithm to exist long enough  *	to generate a BADKEY response.  *  *	If dns_tsigkey_createfromkey is successful a new reference to 'dstkey'  *	will have been made.  *  *	Requires:  *\li		'name' is a valid dns_name_t  *\li		'algorithm' is a valid dns_name_t  *\li		'secret' is a valid pointer  *\li		'length' is an integer>= 0  *\li		'dstkey' is a valid dst key or NULL  *\li		'creator' points to a valid dns_name_t or is NULL  *\li		'mctx' is a valid memory context  *\li		'ring' is a valid TSIG keyring or NULL  *\li		'key' or '*key' must be NULL  *  *	Returns:  *\li		#ISC_R_SUCCESS  *\li		#ISC_R_EXISTS - a key with this name already exists  *\li		#ISC_R_NOTIMPLEMENTED - algorithm is not implemented  *\li		#ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|void
name|dns_tsigkey_attach
parameter_list|(
name|dns_tsigkey_t
modifier|*
name|source
parameter_list|,
name|dns_tsigkey_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Attach '*targetp' to 'source'.  *  *	Requires:  *\li		'key' is a valid TSIG key  *  *	Ensures:  *\li		*targetp is attached to source.  */
end_comment

begin_function_decl
name|void
name|dns_tsigkey_detach
parameter_list|(
name|dns_tsigkey_t
modifier|*
modifier|*
name|keyp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Detaches from the tsig key structure pointed to by '*key'.  *  *	Requires:  *\li		'keyp' is not NULL and '*keyp' is a valid TSIG key  *  *	Ensures:  *\li		'keyp' points to NULL  */
end_comment

begin_function_decl
name|void
name|dns_tsigkey_setdeleted
parameter_list|(
name|dns_tsigkey_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Prevents this key from being used again.  It will be deleted when  *	no references exist.  *  *	Requires:  *\li		'key' is a valid TSIG key on a keyring  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_tsig_sign
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Generates a TSIG record for this message  *  *	Requires:  *\li		'msg' is a valid message  *\li		'msg->tsigkey' is a valid TSIG key  *\li		'msg->tsig' is NULL  *  *	Returns:  *\li		#ISC_R_SUCCESS  *\li		#ISC_R_NOMEMORY  *\li		#ISC_R_NOSPACE  *\li		#DNS_R_EXPECTEDTSIG  *			- this is a response& msg->querytsig is NULL  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_tsig_verify
parameter_list|(
name|isc_buffer_t
modifier|*
name|source
parameter_list|,
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_tsig_keyring_t
modifier|*
name|ring1
parameter_list|,
name|dns_tsig_keyring_t
modifier|*
name|ring2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Verifies the TSIG record in this message  *  *	Requires:  *\li		'source' is a valid buffer containing the unparsed message  *\li		'msg' is a valid message  *\li		'msg->tsigkey' is a valid TSIG key if this is a response  *\li		'msg->tsig' is NULL  *\li		'msg->querytsig' is not NULL if this is a response  *\li		'ring1' and 'ring2' are each either a valid keyring or NULL  *  *	Returns:  *\li		#ISC_R_SUCCESS  *\li		#ISC_R_NOMEMORY  *\li		#DNS_R_EXPECTEDTSIG - A TSIG was expected but not seen  *\li		#DNS_R_UNEXPECTEDTSIG - A TSIG was seen but not expected  *\li		#DNS_R_TSIGERRORSET - the TSIG verified but ->error was set  *				     and this is a query  *\li		#DNS_R_CLOCKSKEW - the TSIG failed to verify because of  *				  the time was out of the allowed range.  *\li		#DNS_R_TSIGVERIFYFAILURE - the TSIG failed to verify  *\li		#DNS_R_EXPECTEDRESPONSE - the message was set over TCP and  *					 should have been a response,  *					 but was not.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_tsigkey_find
parameter_list|(
name|dns_tsigkey_t
modifier|*
modifier|*
name|tsigkey
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_name_t
modifier|*
name|algorithm
parameter_list|,
name|dns_tsig_keyring_t
modifier|*
name|ring
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Returns the TSIG key corresponding to this name and (possibly)  *	algorithm.  Also increments the key's reference counter.  *  *	Requires:  *\li		'tsigkey' is not NULL  *\li		'*tsigkey' is NULL  *\li		'name' is a valid dns_name_t  *\li		'algorithm' is a valid dns_name_t or NULL  *\li		'ring' is a valid keyring  *  *	Returns:  *\li		#ISC_R_SUCCESS  *\li		#ISC_R_NOTFOUND  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_tsigkeyring_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_tsig_keyring_t
modifier|*
modifier|*
name|ringp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Create an empty TSIG key ring.  *  *	Requires:  *\li		'mctx' is not NULL  *\li		'ringp' is not NULL, and '*ringp' is NULL  *  *	Returns:  *\li		#ISC_R_SUCCESS  *\li		#ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_tsigkeyring_add
parameter_list|(
name|dns_tsig_keyring_t
modifier|*
name|ring
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_tsigkey_t
modifier|*
name|tkey
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *      Place a TSIG key onto a key ring.  *  *	Requires:  *\li		'ring', 'name' and 'tkey' are not NULL  *  *	Returns:  *\li		#ISC_R_SUCCESS  *\li		Any other value indicates failure.  */
end_comment

begin_function_decl
name|void
name|dns_tsigkeyring_attach
parameter_list|(
name|dns_tsig_keyring_t
modifier|*
name|source
parameter_list|,
name|dns_tsig_keyring_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_tsigkeyring_detach
parameter_list|(
name|dns_tsig_keyring_t
modifier|*
modifier|*
name|ringp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_tsigkeyring_dumpanddetach
parameter_list|(
name|dns_tsig_keyring_t
modifier|*
modifier|*
name|ringp
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Destroy a TSIG key ring.  *  *	Requires:  *\li		'ringp' is not NULL  */
end_comment

begin_function_decl
name|void
name|dns_keyring_restore
parameter_list|(
name|dns_tsig_keyring_t
modifier|*
name|ring
parameter_list|,
name|FILE
modifier|*
name|fp
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
comment|/* DNS_TSIG_H */
end_comment

end_unit

