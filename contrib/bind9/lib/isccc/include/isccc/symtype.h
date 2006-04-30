begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Portions Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (C) 2001  Internet Software Consortium.  * Portions Copyright (C) 2001  Nominum, Inc.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC AND NOMINUM DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: symtype.h,v 1.2.206.1 2004/03/06 08:15:22 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISCCC_SYMTYPE_H
end_ifndef

begin_define
define|#
directive|define
name|ISCCC_SYMTYPE_H
value|1
end_define

begin_define
define|#
directive|define
name|ISCCC_SYMTYPE_ZONESTATS
value|0x0001
end_define

begin_define
define|#
directive|define
name|ISCCC_SYMTYPE_CCDUP
value|0x0002
end_define

begin_define
define|#
directive|define
name|ISCCC_SYMTYPE_TELLSERVICE
value|0x0003
end_define

begin_define
define|#
directive|define
name|ISCCC_SYMTYPE_TELLRESPONSE
value|0x0004
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISCCC_SYMTYPE_H */
end_comment

end_unit

