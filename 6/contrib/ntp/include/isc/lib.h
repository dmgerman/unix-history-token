begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * INTERNET SOFTWARE CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,  * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: lib.h,v 1.7 2001/11/19 03:08:25 mayer Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_LIB_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_LIB_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_decl_stmt
name|ISC_LANG_BEGINDECLS
name|LIBISC_EXTERNAL_DATA
specifier|extern
name|isc_msgcat_t
modifier|*
name|isc_msgcat
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|isc_lib_initmsgcat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize the ISC library's message catalog, isc_msgcat, if it  * has not already been initialized.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_LIB_H */
end_comment

end_unit

