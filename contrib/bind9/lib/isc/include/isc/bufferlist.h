begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: bufferlist.h,v 1.10.206.1 2004/03/06 08:14:39 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_BUFFERLIST_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_BUFFERLIST_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Buffer Lists  *  *	Buffer lists have no synchronization.  Clients must ensure exclusive  *	access.  *  * Reliability:  *	No anticipated impact.   * Security:  *	No anticipated impact.  *  * Standards:  *	None.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
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
comment|/***  *** Functions  ***/
name|unsigned
name|int
name|isc_bufferlist_usedcount
parameter_list|(
name|isc_bufferlist_t
modifier|*
name|bl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the length of the sum of all used regions of all buffers in  * the buffer list 'bl'  *  * Requires:  *  *	'bl' is not NULL.  *  * Returns:  *	sum of all used regions' lengths.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_bufferlist_availablecount
parameter_list|(
name|isc_bufferlist_t
modifier|*
name|bl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the length of the sum of all available regions of all buffers in  * the buffer list 'bl'  *  * Requires:  *  *	'bl' is not NULL.  *  * Returns:  *	sum of all available regions' lengths.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_BUFFERLIST_H */
end_comment

end_unit

