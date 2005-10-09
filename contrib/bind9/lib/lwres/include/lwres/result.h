begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: result.h,v 1.14.206.1 2004/03/06 08:15:36 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LWRES_RESULT_H
end_ifndef

begin_define
define|#
directive|define
name|LWRES_RESULT_H
value|1
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|lwres_result_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LWRES_R_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|LWRES_R_NOMEMORY
value|1
end_define

begin_define
define|#
directive|define
name|LWRES_R_TIMEOUT
value|2
end_define

begin_define
define|#
directive|define
name|LWRES_R_NOTFOUND
value|3
end_define

begin_define
define|#
directive|define
name|LWRES_R_UNEXPECTEDEND
value|4
end_define

begin_comment
comment|/* unexpected end of input */
end_comment

begin_define
define|#
directive|define
name|LWRES_R_FAILURE
value|5
end_define

begin_comment
comment|/* generic failure */
end_comment

begin_define
define|#
directive|define
name|LWRES_R_IOERROR
value|6
end_define

begin_define
define|#
directive|define
name|LWRES_R_NOTIMPLEMENTED
value|7
end_define

begin_define
define|#
directive|define
name|LWRES_R_UNEXPECTED
value|8
end_define

begin_define
define|#
directive|define
name|LWRES_R_TRAILINGDATA
value|9
end_define

begin_define
define|#
directive|define
name|LWRES_R_INCOMPLETE
value|10
end_define

begin_define
define|#
directive|define
name|LWRES_R_RETRY
value|11
end_define

begin_define
define|#
directive|define
name|LWRES_R_TYPENOTFOUND
value|12
end_define

begin_define
define|#
directive|define
name|LWRES_R_TOOLARGE
value|13
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LWRES_RESULT_H */
end_comment

end_unit

