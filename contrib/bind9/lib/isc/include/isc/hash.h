begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: hash.h,v 1.2.2.1.2.2 2004/03/06 08:14:41 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_HASH_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_HASH_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Hash  *  * The hash API  *  *	Provides an unpredictable hash value for variable length data.  *	A hash object contains a random vector (which is hidden from clients  *	of this API) to make the actual hash value unpredictable.  *  *	The algorithm used in the API guarantees the probability of hash  *	collision; in the current implementation, as long as the values stored  *	in the random vector are unpredictable, the probability of hash  *	collision between arbitrary two different values is at most 1/2^16.  *  *	Altough the API is generic about the hash keys, it mainly expects  *	DNS names (and sometimes IPv4/v6 addresses) as inputs.  It has an  *	upper limit of the input length, and may run slow to calculate the  *	hash values for large inputs.  *  *	This API is designed to be general so that it can provide multiple  *	different hash contexts that have different random vectors.  However,  *	it should be typical to have a single context for an entire system.  *	To support such cases, the API also provides a single-context mode.  *  * MP:  *	The hash object is almost read-only.  Once the internal random vector  *	is initialized, no write operation will occur, and there will be no  *	need to lock the object to calculate actual hash values.  *  * Reliability:  *	In some cases this module uses low-level data copy to initialize the  *	random vector.  Errors in this part are likely to crash the server or  *	corrupt memory.  *  * Resources:  *	A buffer, used as a random vector for calculating hash values.  *  * Security:  *	This module intends to provide unpredictable hash values in  *	adversarial environments in order to avoid denial of service attacks  *	to hash buckets.  *	Its unpredictability relies on the quality of entropy to build the  *	random vector.  *  * Standards:  *	None.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|isc_hash_ctxcreate
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_entropy_t
modifier|*
name|entropy
parameter_list|,
name|unsigned
name|int
name|limit
parameter_list|,
name|isc_hash_t
modifier|*
modifier|*
name|hctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_hash_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_entropy_t
modifier|*
name|entropy
parameter_list|,
name|size_t
name|limit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new hash object.  *  * isc_hash_ctxcreate() creates a different object.  * isc_hash_create() creates a module-internal object to support the  * single-context mode.  It should be called only once.  *  * 'entropy' must be NULL or a valid entropy object.  If 'entropy' is NULL,  * pseudo random values will be used to build the random vector, which may  * weaken security.  *  * 'limit' specifies the maximum number of hash keys.  If it is too large,  * these functions may fail.  */
end_comment

begin_function_decl
name|void
name|isc_hash_ctxattach
parameter_list|(
name|isc_hash_t
modifier|*
name|hctx
parameter_list|,
name|isc_hash_t
modifier|*
modifier|*
name|hctxp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach to a hash object.  * This function is only necessary for the multiple-context mode.  */
end_comment

begin_function_decl
name|void
name|isc_hash_ctxdetach
parameter_list|(
name|isc_hash_t
modifier|*
modifier|*
name|hctxp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach from a hash object.  *  * This function  is for the multiple-context mode, and takes a valid  * hash object as an argument.  */
end_comment

begin_function_decl
name|void
name|isc_hash_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This function is for the single-context mode, and is expected to be used  * as a counterpart of isc_hash_create().  * A valid module-internal hash object must have been created, and this  * function should be called only once.  */
end_comment

begin_function_decl
name|void
name|isc_hash_ctxinit
parameter_list|(
name|isc_hash_t
modifier|*
name|hctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_hash_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize a hash object.  It fills in the random vector with a proper  * source of entropy, which is typically from the entropy object specified  * at the creation.  Thus, it is desirable to call these functions after  * initializing the entropy object with some good entropy sources.  *  * These functions should be called before the first hash calculation.  *  * isc_hash_ctxinit() is for the multiple-context mode, and takes a valid hash  * object as an argument.  * isc_hash_init() is for the single-context mode.  A valid module-internal  * hash object must have been created, and this function should be called only  * once.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_hash_ctxcalc
parameter_list|(
name|isc_hash_t
modifier|*
name|hctx
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|unsigned
name|int
name|keylen
parameter_list|,
name|isc_boolean_t
name|case_sensitive
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|isc_hash_calc
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|unsigned
name|int
name|keylen
parameter_list|,
name|isc_boolean_t
name|case_sensitive
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Calculate a hash value.  *  * isc_hash_ctxinit() is for the multiple-context mode, and takes a valid hash  * object as an argument.  * isc_hash_init() is for the single-context mode.  A valid module-internal  * hash object must have been created.  *  * 'key' is the hash key, which is a variable length buffer.  * 'keylen' specifies the key length, which must not be larger than the limit  * specified for the corresponding hash object.  *  * 'case_sensitive' specifies whether the hash key should be treated as  * case_sensitive values.  It should typically be ISC_FALSE if the hash key  * is a DNS name.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_HASH_H */
end_comment

end_unit

