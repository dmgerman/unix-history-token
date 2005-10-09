begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * INTERNET SOFTWARE CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,  * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: strerror.h,v 1.3 2001/11/20 01:45:47 gson Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_STRERROR_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_STRERROR_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
define|#
directive|define
name|ISC_STRERRORSIZE
value|128
comment|/*  * Provide a thread safe wrapper to strerrror().  *  * Requires:  * 	'buf' to be non NULL.  */
name|void
name|isc__strerror
parameter_list|(
name|int
name|num
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|bufsize
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
comment|/* ISC_STRERROR_H */
end_comment

end_unit

