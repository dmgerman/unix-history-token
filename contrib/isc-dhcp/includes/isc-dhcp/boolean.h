begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1998, 1999  Internet Software Consortium.  *   * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_BOOLEAN_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_BOOLEAN_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc-dhcp/lang.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_typedef
typedef|typedef
enum|enum
block|{
name|isc_boolean_false
init|=
literal|0
block|,
name|isc_boolean_true
init|=
literal|1
block|}
name|isc_boolean_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ISC_FALSE
value|isc_boolean_false
end_define

begin_define
define|#
directive|define
name|ISC_TRUE
value|isc_boolean_true
end_define

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_BOOLEAN_H */
end_comment

end_unit

