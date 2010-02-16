begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005, 2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: serial.h,v 1.10.18.4 2009/01/19 23:46:16 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_SERIAL_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_SERIAL_H
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
file|<isc/types.h>
end_include

begin_comment
comment|/*! \file isc/serial.h  *	\brief Implement 32 bit serial space arithmetic comparison functions.  *	Note: Undefined results are returned as ISC_FALSE.  */
end_comment

begin_comment
comment|/***  ***	Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_boolean_t
name|isc_serial_lt
parameter_list|(
name|isc_uint32_t
name|a
parameter_list|,
name|isc_uint32_t
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Return true if 'a'< 'b' otherwise false.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_serial_gt
parameter_list|(
name|isc_uint32_t
name|a
parameter_list|,
name|isc_uint32_t
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Return true if 'a'> 'b' otherwise false.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_serial_le
parameter_list|(
name|isc_uint32_t
name|a
parameter_list|,
name|isc_uint32_t
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Return true if 'a'<= 'b' otherwise false.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_serial_ge
parameter_list|(
name|isc_uint32_t
name|a
parameter_list|,
name|isc_uint32_t
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Return true if 'a'>= 'b' otherwise false.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_serial_eq
parameter_list|(
name|isc_uint32_t
name|a
parameter_list|,
name|isc_uint32_t
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Return true if 'a' == 'b' otherwise false.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_serial_ne
parameter_list|(
name|isc_uint32_t
name|a
parameter_list|,
name|isc_uint32_t
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Return true if 'a' != 'b' otherwise false.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_SERIAL_H */
end_comment

end_unit

