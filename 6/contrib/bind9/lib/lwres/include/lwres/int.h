begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: int.h,v 1.7.206.1 2004/03/06 08:15:34 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LWRES_INT_H
end_ifndef

begin_define
define|#
directive|define
name|LWRES_INT_H
value|1
end_define

begin_typedef
typedef|typedef
name|char
name|lwres_int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|lwres_uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|lwres_int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|lwres_uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|lwres_int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|lwres_uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|lwres_int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|lwres_uint64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LWRES_INT_H */
end_comment

end_unit

