begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2007, 2009-2011, 2013  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: gssapi.h,v 1.16 2011/01/08 23:47:01 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DST_GSSAPI_H
end_ifndef

begin_define
define|#
directive|define
name|DST_GSSAPI_H
value|1
end_define

begin_comment
comment|/*! \file dst/gssapi.h */
end_comment

begin_include
include|#
directive|include
file|<isc/formatcheck.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|GSSAPI
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_comment
comment|/*  * MSVC does not like macros in #include lines.  */
end_comment

begin_include
include|#
directive|include
file|<gssapi/gssapi.h>
end_include

begin_include
include|#
directive|include
file|<gssapi/gssapi_krb5.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
include|ISC_PLATFORM_GSSAPIHEADER
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_GSSAPI_KRB5_HEADER
end_ifdef

begin_include
include|#
directive|include
include|ISC_PLATFORM_GSSAPI_KRB5_HEADER
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GSS_SPNEGO_MECHANISM
end_ifndef

begin_define
define|#
directive|define
name|GSS_SPNEGO_MECHANISM
value|((void*)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/***  *** Types  ***/
comment|/***  *** Functions  ***/
name|isc_result_t
name|dst_gssapi_acquirecred
parameter_list|(
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|isc_boolean_t
name|initiate
parameter_list|,
name|gss_cred_id_t
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Acquires GSS credentials.  *  *	Requires:  * 	'name' 	    is a valid name, preferably one known by the GSS provider  * 	'initiate'  indicates whether the credentials are for initiating or  *		    accepting contexts  *      'cred'      is a pointer to NULL, which will be allocated with the  *		    credential handle.  Call dst_gssapi_releasecred to free  *		    the memory.  *  *	Returns:  *		ISC_R_SUCCESS msg was successfully updated to include the  *				      query to be sent  *		other		  an error occurred while building the message  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_gssapi_releasecred
parameter_list|(
name|gss_cred_id_t
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Releases GSS credentials.  Calling this function does release the  *  memory allocated for the credential in dst_gssapi_acquirecred()  *  *	Requires:  *      'mctx'  is a valid memory context  *      'cred'  is a pointer to the credential to be released  *  *	Returns:  *		ISC_R_SUCCESS 	credential was released successfully  *		other		an error occurred while releaseing  *				the credential  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_gssapi_initctx
parameter_list|(
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|isc_buffer_t
modifier|*
name|intoken
parameter_list|,
name|isc_buffer_t
modifier|*
name|outtoken
parameter_list|,
name|gss_ctx_id_t
modifier|*
name|gssctx
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
comment|/*  *	Initiates a GSS context.  *  *	Requires:  * 	'name'     is a valid name, preferably one known by the GSS  * 	provider  * 	'intoken'  is a token received from the acceptor, or NULL if  *		   there isn't one  * 	'outtoken' is a buffer to receive the token generated by  *		   gss_init_sec_context() to be sent to the acceptor  *      'context'  is a pointer to a valid gss_ctx_id_t  *                 (which may have the value GSS_C_NO_CONTEXT)  *  *	Returns:  *		ISC_R_SUCCESS   msg was successfully updated to include the  * 				query to be sent  *		other		an error occurred while building the message  *		*err_message	optional error message  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_gssapi_acceptctx
parameter_list|(
name|gss_cred_id_t
name|cred
parameter_list|,
specifier|const
name|char
modifier|*
name|gssapi_keytab
parameter_list|,
name|isc_region_t
modifier|*
name|intoken
parameter_list|,
name|isc_buffer_t
modifier|*
modifier|*
name|outtoken
parameter_list|,
name|gss_ctx_id_t
modifier|*
name|context
parameter_list|,
name|dns_name_t
modifier|*
name|principal
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Accepts a GSS context.  *  *	Requires:  * 	'mctx'     is a valid memory context  *      'cred'     is the acceptor's valid GSS credential handle  * 	'intoken'  is a token received from the initiator  * 	'outtoken' is a pointer a buffer pointer used to return the token  *		   generated by gss_accept_sec_context() to be sent to the  *		   initiator  *      'context'  is a valid pointer to receive the generated context handle.  *                 On the initial call, it should be a pointer to NULL, which  *		   will be allocated as a gss_ctx_id_t.  Subsequent calls  *		   should pass in the handle generated on the first call.  *		   Call dst_gssapi_releasecred to delete the context and free  *		   the memory.  *  *	Requires:  *		'outtoken' to != NULL&& *outtoken == NULL.  *  *	Returns:  *		ISC_R_SUCCESS   msg was successfully updated to include the  * 				query to be sent  *		other 		an error occurred while building the message  */
end_comment

begin_function_decl
name|isc_result_t
name|dst_gssapi_deletectx
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|gss_ctx_id_t
modifier|*
name|gssctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Destroys a GSS context.  This function deletes the context from the GSS  *  	provider and then frees the memory used by the context pointer.  *  *	Requires:  *      'mctx'    is a valid memory context  *	'context' is a valid GSS context  *  *	Returns:  *		ISC_R_SUCCESS  */
end_comment

begin_function_decl
name|void
name|gss_log
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Logging function for GSS.  *  *  Requires  *      'level' is the log level to be used, as an integer  *      'fmt'   is a printf format specifier  */
end_comment

begin_function_decl
name|char
modifier|*
name|gss_error_tostring
parameter_list|(
name|isc_uint32_t
name|major
parameter_list|,
name|isc_uint32_t
name|minor
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Render a GSS major status/minor status pair into a string  *  *	Requires:  *      'major' is a GSS major status code  * 	'minor' is a GSS minor status code  *  *	Returns:  *		A string containing the text representation of the error codes.  *      	Users should copy the string if they wish to keep it.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dst_gssapi_identitymatchesrealmkrb5
parameter_list|(
name|dns_name_t
modifier|*
name|signer
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_name_t
modifier|*
name|realm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Compare a "signer" (in the format of a Kerberos-format Kerberos5  *	principal: host/example.com@EXAMPLE.COM) to the realm name stored  *	in "name" (which represents the realm name).  *  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dst_gssapi_identitymatchesrealmms
parameter_list|(
name|dns_name_t
modifier|*
name|signer
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_name_t
modifier|*
name|realm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Compare a "signer" (in the format of a Kerberos-format Kerberos5  *	principal: host/example.com@EXAMPLE.COM) to the realm name stored  *	in "name" (which represents the realm name).  *  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DST_GSSAPI_H */
end_comment

end_unit

