begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2007, 2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: netscope.h,v 1.13 2009/06/25 23:48:02 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_NETSCOPE_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_NETSCOPE_H
value|1
end_define

begin_comment
comment|/*! \file isc/netscope.h */
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/*%  * Convert a string of an IPv6 scope zone to zone index.  If the conversion  * succeeds, 'zoneid' will store the index value.  *  * XXXJT: when a standard interface for this purpose is defined,  * we should use it.  *  * Returns:  * \li	ISC_R_SUCCESS: conversion succeeds  * \li	ISC_R_FAILURE: conversion fails  */
name|isc_result_t
name|isc_netscope_pton
parameter_list|(
name|int
name|af
parameter_list|,
name|char
modifier|*
name|scopename
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|isc_uint32_t
modifier|*
name|zoneid
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
comment|/* ISC_NETSCOPE_H */
end_comment

end_unit

