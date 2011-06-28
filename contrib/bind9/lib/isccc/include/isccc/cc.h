begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Portions Copyright (C) 2004-2007  Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (C) 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC AND NOMINUM DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Portions Copyright (C) 2001  Nominum, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC AND NOMINUM DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: cc.h,v 1.11 2007-08-28 07:20:43 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISCCC_CC_H
end_ifndef

begin_define
define|#
directive|define
name|ISCCC_CC_H
value|1
end_define

begin_comment
comment|/*! \file isccc/cc.h */
end_comment

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
comment|/*% Maximum Datagram Package */
define|#
directive|define
name|ISCCC_CC_MAXDGRAMPACKET
value|4096
comment|/*% Message Type String */
define|#
directive|define
name|ISCCC_CCMSGTYPE_STRING
value|0x00
comment|/*% Message Type Binary Data */
define|#
directive|define
name|ISCCC_CCMSGTYPE_BINARYDATA
value|0x01
comment|/*% Message Type Table */
define|#
directive|define
name|ISCCC_CCMSGTYPE_TABLE
value|0x02
comment|/*% Message Type List */
define|#
directive|define
name|ISCCC_CCMSGTYPE_LIST
value|0x03
comment|/*% Send to Wire */
name|isc_result_t
name|isccc_cc_towire
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|alist
parameter_list|,
name|isccc_region_t
modifier|*
name|target
parameter_list|,
name|isccc_region_t
modifier|*
name|secret
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*% Get From Wire */
end_comment

begin_function_decl
name|isc_result_t
name|isccc_cc_fromwire
parameter_list|(
name|isccc_region_t
modifier|*
name|source
parameter_list|,
name|isccc_sexpr_t
modifier|*
modifier|*
name|alistp
parameter_list|,
name|isccc_region_t
modifier|*
name|secret
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*% Create Message */
end_comment

begin_function_decl
name|isc_result_t
name|isccc_cc_createmessage
parameter_list|(
name|isc_uint32_t
name|version
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|,
specifier|const
name|char
modifier|*
name|to
parameter_list|,
name|isc_uint32_t
name|serial
parameter_list|,
name|isccc_time_t
name|now
parameter_list|,
name|isccc_time_t
name|expires
parameter_list|,
name|isccc_sexpr_t
modifier|*
modifier|*
name|alistp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*% Create Acknowledgment */
end_comment

begin_function_decl
name|isc_result_t
name|isccc_cc_createack
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|message
parameter_list|,
name|isc_boolean_t
name|ok
parameter_list|,
name|isccc_sexpr_t
modifier|*
modifier|*
name|ackp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*% Is Ack? */
end_comment

begin_function_decl
name|isc_boolean_t
name|isccc_cc_isack
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*% Is Reply? */
end_comment

begin_function_decl
name|isc_boolean_t
name|isccc_cc_isreply
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*% Create Response */
end_comment

begin_function_decl
name|isc_result_t
name|isccc_cc_createresponse
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|message
parameter_list|,
name|isccc_time_t
name|now
parameter_list|,
name|isccc_time_t
name|expires
parameter_list|,
name|isccc_sexpr_t
modifier|*
modifier|*
name|alistp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*% Define String */
end_comment

begin_function_decl
name|isccc_sexpr_t
modifier|*
name|isccc_cc_definestring
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

begin_comment
comment|/*% Define uint 32 */
end_comment

begin_function_decl
name|isccc_sexpr_t
modifier|*
name|isccc_cc_defineuint32
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
name|isc_uint32_t
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*% Lookup String */
end_comment

begin_function_decl
name|isc_result_t
name|isccc_cc_lookupstring
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

begin_comment
comment|/*% Lookup uint 32 */
end_comment

begin_function_decl
name|isc_result_t
name|isccc_cc_lookupuint32
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
name|isc_uint32_t
modifier|*
name|uintp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*% Create Symbol Table */
end_comment

begin_function_decl
name|isc_result_t
name|isccc_cc_createsymtab
parameter_list|(
name|isccc_symtab_t
modifier|*
modifier|*
name|symtabp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*% Clean up Symbol Table */
end_comment

begin_function_decl
name|void
name|isccc_cc_cleansymtab
parameter_list|(
name|isccc_symtab_t
modifier|*
name|symtab
parameter_list|,
name|isccc_time_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*% Check for Duplicates */
end_comment

begin_function_decl
name|isc_result_t
name|isccc_cc_checkdup
parameter_list|(
name|isccc_symtab_t
modifier|*
name|symtab
parameter_list|,
name|isccc_sexpr_t
modifier|*
name|message
parameter_list|,
name|isccc_time_t
name|now
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
comment|/* ISCCC_CC_H */
end_comment

end_unit

