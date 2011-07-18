begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2007, 2009-2011  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: tkey.h,v 1.32 2011-01-08 23:47:01 tbox Exp $ */
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

begin_comment
comment|/*! \file dns/tkey.h */
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

begin_include
include|#
directive|include
file|<dst/dst.h>
end_include

begin_include
include|#
directive|include
file|<dst/gssapi.h>
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
name|gss_cred_id_t
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
name|char
modifier|*
name|gssapi_keytab
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
comment|/*%<  *	Create an empty TKEY context.  *  * 	Requires:  *\li		'mctx' is not NULL  *\li		'tctx' is not NULL  *\li		'*tctx' is NULL  *  *	Returns  *\li		#ISC_R_SUCCESS  *\li		#ISC_R_NOMEMORY  *\li		return codes from dns_name_fromtext()  */
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
comment|/*%<  *      Frees all data associated with the TKEY context  *  * 	Requires:  *\li		'tctx' is not NULL  *\li		'*tctx' is not NULL  */
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
comment|/*%<  *	Processes a query containing a TKEY record, adding or deleting TSIG  *	keys if necessary, and modifies the message to contain the response.  *  *	Requires:  *\li		'msg' is a valid message  *\li		'tctx' is a valid TKEY context  *\li		'ring' is a valid TSIG keyring  *  *	Returns  *\li		#ISC_R_SUCCESS	msg was updated (the TKEY operation succeeded,  *				or msg now includes a TKEY with an error set)  *		DNS_R_FORMERR	the packet was malformed (missing a TKEY  *				or KEY).  *\li		other		An error occurred while processing the message  */
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
comment|/*%<  *	Builds a query containing a TKEY that will generate a shared  *	secret using a Diffie-Hellman key exchange.  The shared key  *	will be of the specified algorithm (only DNS_TSIG_HMACMD5_NAME  *	is supported), and will be named either 'name',  *	'name' + server chosen domain, or random data + server chosen domain  *	if 'name' == dns_rootname.  If nonce is not NULL, it supplies  *	random data used in the shared secret computation.  The key is  *	requested to have the specified lifetime (in seconds)  *  *  *	Requires:  *\li		'msg' is a valid message  *\li		'key' is a valid Diffie Hellman dst key  *\li		'name' is a valid name  *\li		'algorithm' is a valid name  *  *	Returns:  *\li		#ISC_R_SUCCESS	msg was successfully updated to include the  *				query to be sent  *\li		other		an error occurred while building the message  */
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
name|isc_buffer_t
modifier|*
name|intoken
parameter_list|,
name|isc_uint32_t
name|lifetime
parameter_list|,
name|gss_ctx_id_t
modifier|*
name|context
parameter_list|,
name|isc_boolean_t
name|win2k
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|char
modifier|*
modifier|*
name|err_message
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Builds a query containing a TKEY that will generate a GSSAPI context.  *	The key is requested to have the specified lifetime (in seconds).  *  *	Requires:  *\li		'msg'	  is a valid message  *\li		'name'	  is a valid name  *\li		'gname'	  is a valid name  *\li		'context' is a pointer to a valid gss_ctx_id_t  *			  (which may have the value GSS_C_NO_CONTEXT)  *\li		'win2k'   when true says to turn on some hacks to work  *			  with the non-standard GSS-TSIG of Windows 2000  *  *	Returns:  *\li		ISC_R_SUCCESS	msg was successfully updated to include the  *				query to be sent  *\li		other		an error occurred while building the message  *\li		*err_message	optional error message  */
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
comment|/*%<  *	Builds a query containing a TKEY record that will delete the  *	specified shared secret from the server.  *  *	Requires:  *\li		'msg' is a valid message  *\li		'key' is a valid TSIG key  *  *	Returns:  *\li		#ISC_R_SUCCESS	msg was successfully updated to include the  *				query to be sent  *\li		other		an error occurred while building the message  */
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
comment|/*%<  *	Processes a response to a query containing a TKEY that was  *	designed to generate a shared secret using a Diffie-Hellman key  *	exchange.  If the query was successful, a new shared key  *	is created and added to the list of shared keys.  *  *	Requires:  *\li		'qmsg' is a valid message (the query)  *\li		'rmsg' is a valid message (the response)  *\li		'key' is a valid Diffie Hellman dst key  *\li		'outkey' is either NULL or a pointer to NULL  *\li		'ring' is a valid keyring or NULL  *  *	Returns:  *\li		#ISC_R_SUCCESS	the shared key was successfully added  *\li		#ISC_R_NOTFOUND	an error occurred while looking for a  *				component of the query or response  */
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
name|gss_ctx_id_t
modifier|*
name|context
parameter_list|,
name|isc_buffer_t
modifier|*
name|outtoken
parameter_list|,
name|dns_tsigkey_t
modifier|*
modifier|*
name|outkey
parameter_list|,
name|dns_tsig_keyring_t
modifier|*
name|ring
parameter_list|,
name|char
modifier|*
modifier|*
name|err_message
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * XXX  */
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
comment|/*%<  *	Processes a response to a query containing a TKEY that was  *	designed to delete a shared secret.  If the query was successful,  *	the shared key is deleted from the list of shared keys.  *  *	Requires:  *\li		'qmsg' is a valid message (the query)  *\li		'rmsg' is a valid message (the response)  *\li		'ring' is not NULL  *  *	Returns:  *\li		#ISC_R_SUCCESS	the shared key was successfully deleted  *\li		#ISC_R_NOTFOUND	an error occurred while looking for a  *				component of the query or response  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_tkey_gssnegotiate
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
name|server
parameter_list|,
name|gss_ctx_id_t
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
parameter_list|,
name|isc_boolean_t
name|win2k
parameter_list|,
name|char
modifier|*
modifier|*
name|err_message
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Client side negotiation of GSS-TSIG.  Process the response  *	to a TKEY, and establish a TSIG key if negotiation was successful.  *	Build a response to the input TKEY message.  Can take multiple  *	calls to successfully establish the context.  *  *	Requires:  *		'qmsg'    is a valid message, the original TKEY request;  *			     it will be filled with the new message to send  *		'rmsg'    is a valid message, the incoming TKEY message  *		'server'  is the server name  *		'context' is the input context handle  *		'outkey'  receives the established key, if non-NULL;  *			      if non-NULL must point to NULL  *		'ring'	  is the keyring in which to establish the key,  *			      or NULL  *		'win2k'   when true says to turn on some hacks to work  *			      with the non-standard GSS-TSIG of Windows 2000  *  *	Returns:  *		ISC_R_SUCCESS	context was successfully established  *		ISC_R_NOTFOUND  couldn't find a needed part of the query  *					or response  *		DNS_R_CONTINUE  additional context negotiation is required;  *					send the new qmsg to the server  */
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

