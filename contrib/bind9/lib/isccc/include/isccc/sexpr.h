begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Portions Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (C) 2001  Internet Software Consortium.  * Portions Copyright (C) 2001  Nominum, Inc.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC AND NOMINUM DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: sexpr.h,v 1.3.206.1 2004/03/06 08:15:22 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISCCC_SEXPR_H
end_ifndef

begin_define
define|#
directive|define
name|ISCCC_SEXPR_H
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

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_struct
struct|struct
name|isccc_dottedpair
block|{
name|isccc_sexpr_t
modifier|*
name|car
decl_stmt|;
name|isccc_sexpr_t
modifier|*
name|cdr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|isccc_sexpr
block|{
name|unsigned
name|int
name|type
decl_stmt|;
union|union
block|{
name|char
modifier|*
name|as_string
decl_stmt|;
name|isccc_dottedpair_t
name|as_dottedpair
decl_stmt|;
name|isccc_region_t
name|as_region
decl_stmt|;
block|}
name|value
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISCCC_SEXPRTYPE_NONE
value|0x00
end_define

begin_comment
comment|/* Illegal. */
end_comment

begin_define
define|#
directive|define
name|ISCCC_SEXPRTYPE_T
value|0x01
end_define

begin_define
define|#
directive|define
name|ISCCC_SEXPRTYPE_STRING
value|0x02
end_define

begin_define
define|#
directive|define
name|ISCCC_SEXPRTYPE_DOTTEDPAIR
value|0x03
end_define

begin_define
define|#
directive|define
name|ISCCC_SEXPRTYPE_BINARY
value|0x04
end_define

begin_define
define|#
directive|define
name|ISCCC_SEXPR_CAR
parameter_list|(
name|s
parameter_list|)
value|(s)->value.as_dottedpair.car
end_define

begin_define
define|#
directive|define
name|ISCCC_SEXPR_CDR
parameter_list|(
name|s
parameter_list|)
value|(s)->value.as_dottedpair.cdr
end_define

begin_function_decl
name|isccc_sexpr_t
modifier|*
name|isccc_sexpr_cons
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|car
parameter_list|,
name|isccc_sexpr_t
modifier|*
name|cdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isccc_sexpr_t
modifier|*
name|isccc_sexpr_tconst
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isccc_sexpr_t
modifier|*
name|isccc_sexpr_fromstring
parameter_list|(
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
name|isccc_sexpr_frombinary
parameter_list|(
specifier|const
name|isccc_region_t
modifier|*
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isccc_sexpr_free
parameter_list|(
name|isccc_sexpr_t
modifier|*
modifier|*
name|sexprp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isccc_sexpr_print
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|sexpr
parameter_list|,
name|FILE
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isccc_sexpr_t
modifier|*
name|isccc_sexpr_car
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isccc_sexpr_t
modifier|*
name|isccc_sexpr_cdr
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isccc_sexpr_setcar
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|pair
parameter_list|,
name|isccc_sexpr_t
modifier|*
name|car
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isccc_sexpr_setcdr
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|pair
parameter_list|,
name|isccc_sexpr_t
modifier|*
name|cdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isccc_sexpr_t
modifier|*
name|isccc_sexpr_addtolist
parameter_list|(
name|isccc_sexpr_t
modifier|*
modifier|*
name|l1p
parameter_list|,
name|isccc_sexpr_t
modifier|*
name|l2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|isccc_sexpr_listp
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|sexpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|isccc_sexpr_emptyp
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|sexpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|isccc_sexpr_stringp
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|sexpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|isccc_sexpr_binaryp
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|sexpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|isccc_sexpr_tostring
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|sexpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isccc_region_t
modifier|*
name|isccc_sexpr_tobinary
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|sexpr
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
comment|/* ISCCC_SEXPR_H */
end_comment

end_unit

