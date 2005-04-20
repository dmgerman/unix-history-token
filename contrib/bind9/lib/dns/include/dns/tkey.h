begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: tkey.h,v 1.18.206.1 2004/03/06 08:14:00 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_TKEY_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_TKEY_H
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
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<dst/dst.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/* Key agreement modes */
end_comment

begin_define
define|#
directive|define
name|DNS_TKEYMODE_SERVERASSIGNED
value|1
end_define

begin_define
define|#
directive|define
name|DNS_TKEYMODE_DIFFIEHELLMAN
value|2
end_define

begin_define
define|#
directive|define
name|DNS_TKEYMODE_GSSAPI
value|3
end_define

begin_define
define|#
directive|define
name|DNS_TKEYMODE_RESOLVERASSIGNED
value|4
end_define

begin_define
define|#
directive|define
name|DNS_TKEYMODE_DELETE
value|5
end_define

begin_struct
struct|struct
name|dns_tkeyctx
block|{
name|dst_key_t
modifier|*
name|dhkey
decl_stmt|;
name|dns_name_t
modifier|*
name|domain
decl_stmt|;
name|void
modifier|*
name|gsscred
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|isc_entropy_t
modifier|*
name|ectx
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|isc_result_t
name|dns_tkeyctx_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_entropy_t
modifier|*
name|ectx
parameter_list|,
name|dns_tkeyctx_t
modifier|*
modifier|*
name|tctxp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Create an empty TKEY context.  *  * 	Requires:  *		'mctx' is not NULL  *		'tctx' is not NULL  *		'*tctx' is NULL  *  *	Returns  *		ISC_R_SUCCESS  *		ISC_R_NOMEMORY  *		return codes from dns_name_fromtext()  */
end_comment

begin_function_decl
name|void
name|dns_tkeyctx_destroy
parameter_list|(
name|dns_tkeyctx_t
modifier|*
modifier|*
name|tctxp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *      Frees all data associated with the TKEY context  *  * 	Requires:  *		'tctx' is not NULL  *		'*tctx' is not NULL  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_tkey_processquery
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_tkeyctx_t
modifier|*
name|tctx
parameter_list|,
name|dns_tsig_keyring_t
modifier|*
name|ring
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Processes a query containing a TKEY record, adding or deleting TSIG  *	keys if necessary, and modifies the message to contain the response.  *  *	Requires:  *		'msg' is a valid message  *		'tctx' is a valid TKEY context  *		'ring' is a valid TSIG keyring  *  *	Returns  *		ISC_R_SUCCESS	msg was updated (the TKEY operation succeeded,  *				or msg now includes a TKEY with an error set)  *		DNS_R_FORMERR	the packet was malformed (missing a TKEY  *				or KEY).  *		other		An error occurred while processing the message  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_tkey_builddhquery
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_name_t
modifier|*
name|algorithm
parameter_list|,
name|isc_buffer_t
modifier|*
name|nonce
parameter_list|,
name|isc_uint32_t
name|lifetime
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Builds a query containing a TKEY that will generate a shared  *	secret using a Diffie-Hellman key exchange.  The shared key  *	will be of the specified algorithm (only DNS_TSIG_HMACMD5_NAME  *	is supported), and will be named either 'name',  *	'name' + server chosen domain, or random data + server chosen domain  *	if 'name' == dns_rootname.  If nonce is not NULL, it supplies  *	random data used in the shared secret computation.  The key is  *	requested to have the specified lifetime (in seconds)  *  *  *	Requires:  *		'msg' is a valid message  *		'key' is a valid Diffie Hellman dst key  *		'name' is a valid name  *		'algorithm' is a valid name  *  *	Returns:  *		ISC_R_SUCCESS	msg was successfully updated to include the  *				query to be sent  *		other		an error occurred while building the message  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_tkey_buildgssquery
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_name_t
modifier|*
name|gname
parameter_list|,
name|void
modifier|*
name|cred
parameter_list|,
name|isc_uint32_t
name|lifetime
parameter_list|,
name|void
modifier|*
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XXX  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_tkey_builddeletequery
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_tsigkey_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Builds a query containing a TKEY record that will delete the  *	specified shared secret from the server.  *  *	Requires:  *		'msg' is a valid message  *		'key' is a valid TSIG key  *  *	Returns:  *		ISC_R_SUCCESS	msg was successfully updated to include the  *				query to be sent  *		other		an error occurred while building the message  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_tkey_processdhresponse
parameter_list|(
name|dns_message_t
modifier|*
name|qmsg
parameter_list|,
name|dns_message_t
modifier|*
name|rmsg
parameter_list|,
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|isc_buffer_t
modifier|*
name|nonce
parameter_list|,
name|dns_tsigkey_t
modifier|*
modifier|*
name|outkey
parameter_list|,
name|dns_tsig_keyring_t
modifier|*
name|ring
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Processes a response to a query containing a TKEY that was  *	designed to generate a shared secret using a Diffie-Hellman key  *	exchange.  If the query was successful, a new shared key  *	is created and added to the list of shared keys.  *  *	Requires:  *		'qmsg' is a valid message (the query)  *		'rmsg' is a valid message (the response)  *		'key' is a valid Diffie Hellman dst key  *		'outkey' is either NULL or a pointer to NULL  *		'ring' is a valid keyring or NULL  *  *	Returns:  *		ISC_R_SUCCESS	the shared key was successfully added  *		ISC_R_NOTFOUND	an error occurred while looking for a  *				component of the query or response  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_tkey_processgssresponse
parameter_list|(
name|dns_message_t
modifier|*
name|qmsg
parameter_list|,
name|dns_message_t
modifier|*
name|rmsg
parameter_list|,
name|dns_name_t
modifier|*
name|gname
parameter_list|,
name|void
modifier|*
name|cred
parameter_list|,
name|void
modifier|*
modifier|*
name|context
parameter_list|,
name|dns_tsigkey_t
modifier|*
modifier|*
name|outkey
parameter_list|,
name|dns_tsig_keyring_t
modifier|*
name|ring
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XXX  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_tkey_processdeleteresponse
parameter_list|(
name|dns_message_t
modifier|*
name|qmsg
parameter_list|,
name|dns_message_t
modifier|*
name|rmsg
parameter_list|,
name|dns_tsig_keyring_t
modifier|*
name|ring
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Processes a response to a query containing a TKEY that was  *	designed to delete a shared secret.  If the query was successful,  *	the shared key is deleted from the list of shared keys.  *  *	Requires:  *		'qmsg' is a valid message (the query)  *		'rmsg' is a valid message (the response)  *		'ring' is not NULL  *  *	Returns:  *		ISC_R_SUCCESS	the shared key was successfully deleted  *		ISC_R_NOTFOUND	an error occurred while looking for a  *				component of the query or response  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_TKEY_H */
end_comment

end_unit

