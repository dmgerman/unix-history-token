begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: bitstring.h,v 1.7.206.1 2004/03/06 08:14:38 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_BITSTRING_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_BITSTRING_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Bitstring  *  * A bitstring is a packed array of bits, stored in a contiguous  * sequence of octets.  The "most significant bit" (msb) of a bitstring  * is the high bit of the first octet.  The "least significant bit" of a  * bitstring is the low bit of the last octet.  *  * Two bit numbering schemes are supported, "msb0" and "lsb0".  *  * In the "msb0" scheme, bit number 0 designates the most significant bit,  * and any padding bits required to make the bitstring a multiple of 8 bits  * long are added to the least significant end of the last octet.  *  * In the "lsb0" scheme, bit number 0 designates the least significant bit,  * and any padding bits required to make the bitstring a multiple of 8 bits  * long are added to the most significant end of the first octet.  *  * E.g., consider the bitstring "11010001111".  This bitstring is 11 bits  * long and will take two octets.  Let "p" denote a pad bit.  In the msb0  * encoding, it would be  *  *             Octet 0           Octet 1  *                         |  *         1 1 0 1 0 0 0 1 | 1 1 1 p p p p p  *         ^               |               ^  *         |                               |  *         bit 0                           bit 15  *  * In the lsb0 encoding, it would be  *  *             Octet 0           Octet 1  *                         |  *         p p p p p 1 1 0 | 1 0 0 0 1 1 1 1   *         ^               |               ^  *         |                               |  *         bit 15                          bit 0  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

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

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_struct
struct|struct
name|isc_bitstring
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
name|unsigned
name|int
name|length
decl_stmt|;
name|unsigned
name|int
name|size
decl_stmt|;
name|isc_boolean_t
name|lsb0
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|void
name|isc_bitstring_init
parameter_list|(
name|isc_bitstring_t
modifier|*
name|bitstring
parameter_list|,
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|,
name|isc_boolean_t
name|lsb0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make 'bitstring' refer to the bitstring of 'size' bits starting  * at 'data'.  'length' bits of the bitstring are valid.  If 'lsb0'  * is set then, bit 0 refers to the least significant bit of the  * bitstring.  Otherwise bit 0 is the most significant bit.  *  * Requires:  *  *	'bitstring' points to a isc_bitstring_t.  *  *	'data' points to an array of unsigned char large enough to hold  *	'size' bits.  *  *	'length'<= 'size'.  *  * Ensures:  *  *	'bitstring' is a valid bitstring.  */
end_comment

begin_function_decl
name|void
name|isc_bitstring_invalidate
parameter_list|(
name|isc_bitstring_t
modifier|*
name|bitstring
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Invalidate 'bitstring'.  *  * Requires:  *  *	'bitstring' is a valid bitstring.  *  * Ensures:  *  *	'bitstring' is not a valid bitstring.  */
end_comment

begin_function_decl
name|void
name|isc_bitstring_copy
parameter_list|(
name|isc_bitstring_t
modifier|*
name|source
parameter_list|,
name|unsigned
name|int
name|sbitpos
parameter_list|,
name|isc_bitstring_t
modifier|*
name|target
parameter_list|,
name|unsigned
name|int
name|tbitpos
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Starting at bit 'sbitpos', copy 'n' bits from 'source' to  * the 'n' bits of 'target' starting at 'tbitpos'.  *  * Requires:  *  *	'source' and target are valid bitstrings with the same lsb0 setting.  *  *	'sbitpos' + 'n' is less than or equal to the length of 'source'.  *  *	'tbitpos' + 'n' is less than or equal to the size of 'target'.  *  * Ensures:  *  *	The specified bits have been copied, and the length of 'target'  *	adjusted (if required).  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_BITSTRING_H */
end_comment

end_unit

