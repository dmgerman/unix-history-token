begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Portions Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (C) 2001, 2003  Internet Software Consortium.  * Portions Copyright (C) 2001  Nominum, Inc.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC AND NOMINUM DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: result.h,v 1.3.2.2.2.1 2004/03/06 08:15:22 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISCCC_RESULT_H
end_ifndef

begin_define
define|#
directive|define
name|ISCCC_RESULT_H
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

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_include
include|#
directive|include
file|<isccc/types.h>
end_include

begin_define
define|#
directive|define
name|ISCCC_R_UNKNOWNVERSION
value|(ISC_RESULTCLASS_ISCCC + 0)
end_define

begin_define
define|#
directive|define
name|ISCCC_R_SYNTAX
value|(ISC_RESULTCLASS_ISCCC + 1)
end_define

begin_define
define|#
directive|define
name|ISCCC_R_BADAUTH
value|(ISC_RESULTCLASS_ISCCC + 2)
end_define

begin_define
define|#
directive|define
name|ISCCC_R_EXPIRED
value|(ISC_RESULTCLASS_ISCCC + 3)
end_define

begin_define
define|#
directive|define
name|ISCCC_R_CLOCKSKEW
value|(ISC_RESULTCLASS_ISCCC + 4)
end_define

begin_define
define|#
directive|define
name|ISCCC_R_DUPLICATE
value|(ISC_RESULTCLASS_ISCCC + 5)
end_define

begin_define
define|#
directive|define
name|ISCCC_R_NRESULTS
value|6
end_define

begin_comment
comment|/* Number of results */
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
specifier|const
name|char
modifier|*
name|isccc_result_totext
parameter_list|(
name|isc_result_t
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert a isccc_result_t into a string message describing the result.  */
end_comment

begin_function_decl
name|void
name|isccc_result_register
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
comment|/* ISCCC_RESULT_H */
end_comment

end_unit

