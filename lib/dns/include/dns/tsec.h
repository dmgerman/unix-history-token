begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2009, 2010  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: tsec.h,v 1.6 2010-12-09 00:54:34 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_TSEC_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_TSEC_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file  *  * \brief  * The TSEC (Transaction Security) module is an abstraction layer for managing  * DNS transaction mechanisms such as TSIG or SIG(0).  A TSEC structure is a  * mechanism-independent object containing key information specific to the  * mechanism, and is expected to be used as an argument to other modules  * that use transaction security in a mechanism-independent manner.  *  * MP:  *\li	A TSEC structure is expected to be thread-specific.  No inter-thread  *	synchronization is ensured in multiple access to a single TSEC  *	structure.  *  * Resources:  *\li	TBS  *  * Security:  *\li	This module does not handle any low-level data directly, and so no  *	security issue specific to this module is anticipated.  */
end_comment

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<dst/dst.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_comment
comment|/*%  * Transaction security types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dns_tsectype_none
block|,
name|dns_tsectype_tsig
block|,
name|dns_tsectype_sig0
block|}
name|dns_tsectype_t
typedef|;
end_typedef

begin_function_decl
name|isc_result_t
name|dns_tsec_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_tsectype_t
name|type
parameter_list|,
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|dns_tsec_t
modifier|*
modifier|*
name|tsecp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a TSEC structure and stores a type-dependent key structure in it.  * For a TSIG key (type is dns_tsectype_tsig), dns_tsec_create() creates a  * TSIG key structure from '*key' and keeps it in the structure.  For other  * types, this function simply retains '*key' in the structure.  In either  * case, the ownership of '*key' is transferred to the TSEC module; the caller  * must not modify or destroy it after the call to dns_tsec_create().  *  * Requires:  *  *\li	'mctx' is a valid memory context.  *  *\li	'type' is a valid value of dns_tsectype_t (see above).  *  *\li	'key' is a valid key.  *  *\li	tsecp != NULL&& *tsecp == NULL.  *  * Returns:  *  *\li	#ISC_R_SUCCESS				On success.  *  *\li	Anything else				Failure.  */
end_comment

begin_function_decl
name|void
name|dns_tsec_destroy
parameter_list|(
name|dns_tsec_t
modifier|*
modifier|*
name|tsecp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy the TSEC structure.  The stored key is also detached or destroyed.  *  * Requires  *  *\li	'*tsecp' is a valid TSEC structure.  *  * Ensures  *  *\li	*tsecp == NULL.  *  */
end_comment

begin_function_decl
name|dns_tsectype_t
name|dns_tsec_gettype
parameter_list|(
name|dns_tsec_t
modifier|*
name|tsec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the TSEC type of '*tsec'.  *  * Requires  *  *\li	'tsec' is a valid TSEC structure.  *  */
end_comment

begin_function_decl
name|void
name|dns_tsec_getkey
parameter_list|(
name|dns_tsec_t
modifier|*
name|tsec
parameter_list|,
name|void
modifier|*
name|keyp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the TSEC key of '*tsec' in '*keyp'.  *  * Requires  *  *\li	keyp != NULL  *  * Ensures  *  *\li	*tsecp points to a valid key structure depending on the TSEC type.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_TSEC_H */
end_comment

end_unit

