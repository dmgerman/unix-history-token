begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995-1999 by Internet Software Consortium  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * $Id: misc.h,v 8.4 2000/12/23 08:14:52 vixie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISC_MISC_H
end_ifndef

begin_define
define|#
directive|define
name|_ISC_MISC_H
end_define

begin_define
define|#
directive|define
name|bitncmp
value|__bitncmp
end_define

begin_comment
comment|/*#define isc_movefile	__isc_movefile */
end_comment

begin_function_decl
specifier|extern
name|int
name|bitncmp
parameter_list|(
specifier|const
name|void
modifier|*
name|l
parameter_list|,
specifier|const
name|void
modifier|*
name|r
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isc_movefile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_ISC_MISC_H*/
end_comment

end_unit

