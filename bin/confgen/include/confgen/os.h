begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2009  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: os.h,v 1.3 2009-06-11 23:47:55 tbox Exp $ */
end_comment

begin_comment
comment|/*! \file */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RNDC_OS_H
end_ifndef

begin_define
define|#
directive|define
name|RNDC_OS_H
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
file|<stdio.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|int
name|set_user
parameter_list|(
name|FILE
modifier|*
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|user
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the owner of the file referenced by 'fd' to 'user'.  * Returns:  *   0 		success  *   -1 	insufficient permissions, or 'user' does not exist.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

