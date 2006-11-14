begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: assert_p.h,v 1.9.206.1 2004/03/06 08:15:30 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LWRES_ASSERT_P_H
end_ifndef

begin_define
define|#
directive|define
name|LWRES_ASSERT_P_H
value|1
end_define

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_comment
comment|/* Required for assert() prototype. */
end_comment

begin_define
define|#
directive|define
name|REQUIRE
parameter_list|(
name|x
parameter_list|)
value|assert(x)
end_define

begin_define
define|#
directive|define
name|INSIST
parameter_list|(
name|x
parameter_list|)
value|assert(x)
end_define

begin_define
define|#
directive|define
name|UNUSED
parameter_list|(
name|x
parameter_list|)
value|((void)(x))
end_define

begin_define
define|#
directive|define
name|SPACE_OK
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|)
value|(LWRES_BUFFER_AVAILABLECOUNT(b)>= (s))
end_define

begin_define
define|#
directive|define
name|SPACE_REMAINING
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|)
value|(LWRES_BUFFER_REMAINING(b)>= (s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LWRES_ASSERT_P_H */
end_comment

end_unit

