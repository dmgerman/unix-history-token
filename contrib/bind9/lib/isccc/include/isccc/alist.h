begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Portions Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (C) 2001  Internet Software Consortium.  * Portions Copyright (C) 2001  Nominum, Inc.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC AND NOMINUM DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: alist.h,v 1.2.206.1 2004/03/06 08:15:21 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISCCC_ALIST_H
end_ifndef

begin_define
define|#
directive|define
name|ISCCC_ALIST_H
value|1
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isccc/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isccc_sexpr_t
modifier|*
name|isccc_alist_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|isccc_alist_alistp
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|alist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|isccc_alist_emptyp
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|alist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isccc_sexpr_t
modifier|*
name|isccc_alist_first
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|alist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isccc_sexpr_t
modifier|*
name|isccc_alist_assq
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|alist
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isccc_alist_delete
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|alist
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isccc_sexpr_t
modifier|*
name|isccc_alist_define
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|alist
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|isccc_sexpr_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isccc_sexpr_t
modifier|*
name|isccc_alist_definestring
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|alist
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isccc_sexpr_t
modifier|*
name|isccc_alist_definebinary
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|alist
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|isccc_region_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isccc_sexpr_t
modifier|*
name|isccc_alist_lookup
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|alist
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isccc_alist_lookupstring
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|alist
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|char
modifier|*
modifier|*
name|strp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isccc_alist_lookupbinary
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|alist
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|isccc_region_t
modifier|*
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isccc_alist_prettyprint
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|sexpr
parameter_list|,
name|unsigned
name|int
name|indent
parameter_list|,
name|FILE
modifier|*
name|stream
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
comment|/* ISCCC_ALIST_H */
end_comment

end_unit

