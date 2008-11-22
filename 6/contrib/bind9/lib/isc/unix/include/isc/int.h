begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: int.h,v 1.11.206.1 2004/03/06 08:15:04 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_INT_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_INT_H
value|1
end_define

begin_typedef
typedef|typedef
name|char
name|isc_int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|isc_uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|isc_int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|isc_uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|isc_int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|isc_uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|isc_int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|isc_uint64_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ISC_INT8_MIN
value|-128
end_define

begin_define
define|#
directive|define
name|ISC_INT8_MAX
value|127
end_define

begin_define
define|#
directive|define
name|ISC_UINT8_MAX
value|255
end_define

begin_define
define|#
directive|define
name|ISC_INT16_MIN
value|-32768
end_define

begin_define
define|#
directive|define
name|ISC_INT16_MAX
value|32767
end_define

begin_define
define|#
directive|define
name|ISC_UINT16_MAX
value|65535
end_define

begin_comment
comment|/*  * Note that "int" is 32 bits on all currently supported Unix-like operating  * systems, but "long" can be either 32 bits or 64 bits, thus the 32 bit  * constants are not qualified with "L".  */
end_comment

begin_define
define|#
directive|define
name|ISC_INT32_MIN
value|-2147483648
end_define

begin_define
define|#
directive|define
name|ISC_INT32_MAX
value|2147483647
end_define

begin_define
define|#
directive|define
name|ISC_UINT32_MAX
value|4294967295U
end_define

begin_define
define|#
directive|define
name|ISC_INT64_MIN
value|-9223372036854775808LL
end_define

begin_define
define|#
directive|define
name|ISC_INT64_MAX
value|9223372036854775807LL
end_define

begin_define
define|#
directive|define
name|ISC_UINT64_MAX
value|18446744073709551615ULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_INT_H */
end_comment

end_unit

