begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: msgcat.h,v 1.8.206.1 2004/03/06 08:14:44 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_MSGCAT_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_MSGCAT_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * ISC Message Catalog  *  * Message catalogs aid internationalization of applications by allowing  * messages to be retrieved from locale-specific files instead of  * hardwiring them into the application.  This allows translations of  * messages appropriate to the locale to be supplied without recompiling  * the application.  *  * Notes:  *	It's very important that message catalogs work, even if only the  *	default_text can be used.  *  * MP:  *	The caller must ensure appropriate synchronization of  *	isc_msgcat_open() and isc_msgcat_close().  isc_msgcat_get()  *	ensures appropriate synchronization.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *<TBS>  *  * Security:  *	No anticipated impact.  *  * Standards:  *	None.  */
end_comment

begin_comment
comment|/*****  ***** Imports  *****/
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

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/*****  ***** Methods  *****/
name|void
name|isc_msgcat_open
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|isc_msgcat_t
modifier|*
modifier|*
name|msgcatp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Open a message catalog.  *  * Notes:  *  *	If memory cannot be allocated or other failures occur, *msgcatp  *	will be set to NULL.  If a NULL msgcat is given to isc_msgcat_get(),  *	the default_text will be returned, ensuring that some message text  *	will be available, no matter what's going wrong.  *  * Requires:  *  *	'name' is a valid string.  *  *	msgcatp != NULL&& *msgcatp == NULL  */
end_comment

begin_function_decl
name|void
name|isc_msgcat_close
parameter_list|(
name|isc_msgcat_t
modifier|*
modifier|*
name|msgcatp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Close a message catalog.  *  * Notes:  *  *	Any string pointers returned by prior calls to isc_msgcat_get() are  *	invalid after isc_msgcat_close() has been called and must not be  *	used.  *  * Requires:  *  *	*msgcatp is a valid message catalog or is NULL.  *  * Ensures:  *  *	All resources associated with the message catalog are released.  *  *	*msgcatp == NULL  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|isc_msgcat_get
parameter_list|(
name|isc_msgcat_t
modifier|*
name|msgcat
parameter_list|,
name|int
name|set
parameter_list|,
name|int
name|message
parameter_list|,
specifier|const
name|char
modifier|*
name|default_text
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get message 'message' from message set 'set' in 'msgcat'.  If it  * is not available, use 'default_text'.  *  * Requires:  *  *	'msgcat' is a valid message catalog or is NULL.  *  *	set> 0  *  *	message> 0  *  *	'default_text' is a valid string.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_MSGCAT_H */
end_comment

end_unit

