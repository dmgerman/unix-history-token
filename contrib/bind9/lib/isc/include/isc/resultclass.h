begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: resultclass.h,v 1.11.206.1 2004/03/06 08:14:47 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_RESULTCLASS_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_RESULTCLASS_H
value|1
end_define

begin_comment
comment|/*****  ***** Registry of Predefined Result Type Classes  *****/
end_comment

begin_comment
comment|/*  * A result class number is an unsigned 16 bit number.  Each class may  * contain up to 65536 results.  A result code is formed by adding the  * result number within the class to the class number multiplied by 65536.  */
end_comment

begin_define
define|#
directive|define
name|ISC_RESULTCLASS_FROMNUM
parameter_list|(
name|num
parameter_list|)
value|((num)<< 16)
end_define

begin_define
define|#
directive|define
name|ISC_RESULTCLASS_TONUM
parameter_list|(
name|rclass
parameter_list|)
value|((rclass)>> 16)
end_define

begin_define
define|#
directive|define
name|ISC_RESULTCLASS_SIZE
value|65536
end_define

begin_define
define|#
directive|define
name|ISC_RESULTCLASS_INCLASS
parameter_list|(
name|rclass
parameter_list|,
name|result
parameter_list|)
define|\
value|((rclass) == ((result)& 0xFFFF0000))
end_define

begin_comment
comment|/*  * Classes< 1024 are reserved for ISC use.  */
end_comment

begin_define
define|#
directive|define
name|ISC_RESULTCLASS_ISC
value|ISC_RESULTCLASS_FROMNUM(0)
end_define

begin_define
define|#
directive|define
name|ISC_RESULTCLASS_DNS
value|ISC_RESULTCLASS_FROMNUM(1)
end_define

begin_define
define|#
directive|define
name|ISC_RESULTCLASS_DST
value|ISC_RESULTCLASS_FROMNUM(2)
end_define

begin_define
define|#
directive|define
name|ISC_RESULTCLASS_DNSRCODE
value|ISC_RESULTCLASS_FROMNUM(3)
end_define

begin_define
define|#
directive|define
name|ISC_RESULTCLASS_OMAPI
value|ISC_RESULTCLASS_FROMNUM(4)
end_define

begin_define
define|#
directive|define
name|ISC_RESULTCLASS_ISCCC
value|ISC_RESULTCLASS_FROMNUM(5)
end_define

begin_comment
comment|/*  * Result classes>= 1024 and<= 65535 are reserved for application use.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_RESULTCLASS_H */
end_comment

end_unit

