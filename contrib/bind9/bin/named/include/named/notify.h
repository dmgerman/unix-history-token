begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: notify.h,v 1.9.208.1 2004/03/06 10:21:25 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_NOTIFY_H
end_ifndef

begin_define
define|#
directive|define
name|NAMED_NOTIFY_H
value|1
end_define

begin_include
include|#
directive|include
file|<named/types.h>
end_include

begin_include
include|#
directive|include
file|<named/client.h>
end_include

begin_comment
comment|/***  ***	Module Info  ***/
end_comment

begin_comment
comment|/*  *	RFC 1996  *	A Mechanism for Prompt Notification of Zone Changes (DNS NOTIFY)  */
end_comment

begin_comment
comment|/***  ***	Functions.  ***/
end_comment

begin_function_decl
name|void
name|ns_notify_start
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Examines the incoming message to determine apporiate zone.  *	Returns FORMERR if there is not exactly one question.  *	Returns REFUSED if we do not serve the listed zone.  *	Pass the message to the zone module for processing  *	and returns the return status.  *  * Requires  *	client to be valid.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_NOTIFY_H */
end_comment

end_unit

