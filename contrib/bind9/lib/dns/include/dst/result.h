begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: result.h,v 1.1.4.1 2004/12/09 04:07:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DST_RESULT_H
end_ifndef

begin_define
define|#
directive|define
name|DST_RESULT_H
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
file|<isc/resultclass.h>
end_include

begin_comment
comment|/*  * Nothing in this file truly depends on<isc/result.h>, but the  * DST result codes are considered to be publicly derived from  * the ISC result codes, so including this file buys you the ISC_R_  * namespace too.  */
end_comment

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_comment
comment|/* Contractual promise. */
end_comment

begin_define
define|#
directive|define
name|DST_R_UNSUPPORTEDALG
value|(ISC_RESULTCLASS_DST + 0)
end_define

begin_define
define|#
directive|define
name|DST_R_OPENSSLFAILURE
value|(ISC_RESULTCLASS_DST + 1)
end_define

begin_define
define|#
directive|define
name|DST_R_NOCRYPTO
value|(ISC_RESULTCLASS_DST + 2)
end_define

begin_define
define|#
directive|define
name|DST_R_NULLKEY
value|(ISC_RESULTCLASS_DST + 3)
end_define

begin_define
define|#
directive|define
name|DST_R_INVALIDPUBLICKEY
value|(ISC_RESULTCLASS_DST + 4)
end_define

begin_define
define|#
directive|define
name|DST_R_INVALIDPRIVATEKEY
value|(ISC_RESULTCLASS_DST + 5)
end_define

begin_comment
comment|/* 6 is unused */
end_comment

begin_define
define|#
directive|define
name|DST_R_WRITEERROR
value|(ISC_RESULTCLASS_DST + 7)
end_define

begin_define
define|#
directive|define
name|DST_R_INVALIDPARAM
value|(ISC_RESULTCLASS_DST + 8)
end_define

begin_comment
comment|/* 9 is unused */
end_comment

begin_comment
comment|/* 10 is unused */
end_comment

begin_define
define|#
directive|define
name|DST_R_SIGNFAILURE
value|(ISC_RESULTCLASS_DST + 11)
end_define

begin_comment
comment|/* 12 is unused */
end_comment

begin_comment
comment|/* 13 is unused */
end_comment

begin_define
define|#
directive|define
name|DST_R_VERIFYFAILURE
value|(ISC_RESULTCLASS_DST + 14)
end_define

begin_define
define|#
directive|define
name|DST_R_NOTPUBLICKEY
value|(ISC_RESULTCLASS_DST + 15)
end_define

begin_define
define|#
directive|define
name|DST_R_NOTPRIVATEKEY
value|(ISC_RESULTCLASS_DST + 16)
end_define

begin_define
define|#
directive|define
name|DST_R_KEYCANNOTCOMPUTESECRET
value|(ISC_RESULTCLASS_DST + 17)
end_define

begin_define
define|#
directive|define
name|DST_R_COMPUTESECRETFAILURE
value|(ISC_RESULTCLASS_DST + 18)
end_define

begin_define
define|#
directive|define
name|DST_R_NORANDOMNESS
value|(ISC_RESULTCLASS_DST + 19)
end_define

begin_define
define|#
directive|define
name|DST_R_BADKEYTYPE
value|(ISC_RESULTCLASS_DST + 20)
end_define

begin_define
define|#
directive|define
name|DST_R_NRESULTS
value|21
end_define

begin_comment
comment|/* Number of results */
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
specifier|const
name|char
modifier|*
name|dst_result_totext
parameter_list|(
name|isc_result_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dst_result_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DST_RESULT_H */
end_comment

end_unit

