begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: lfsr.h,v 1.10.206.1 2004/03/06 08:14:43 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_LFSR_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_LFSR_H
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

begin_typedef
typedef|typedef
name|struct
name|isc_lfsr
name|isc_lfsr_t
typedef|;
end_typedef

begin_comment
comment|/*  * This function is called when reseeding is needed.  It is allowed to  * modify any state in the LFSR in any way it sees fit OTHER THAN "bits".  *  * It MUST set "count" to a new value or the lfsr will never reseed again.  *  * Also, a reseed will never occur in the middle of an extraction.  This  * is purely an optimization, and is probably what one would want.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|isc_lfsrreseed_t
function_decl|)
parameter_list|(
name|isc_lfsr_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * The members of this structure can be used by the application, but care  * needs to be taken to not change state once the lfsr is in operation.  */
end_comment

begin_struct
struct|struct
name|isc_lfsr
block|{
name|isc_uint32_t
name|state
decl_stmt|;
comment|/* previous state */
name|unsigned
name|int
name|bits
decl_stmt|;
comment|/* length */
name|isc_uint32_t
name|tap
decl_stmt|;
comment|/* bit taps */
name|unsigned
name|int
name|count
decl_stmt|;
comment|/* reseed count (in BITS!) */
name|isc_lfsrreseed_t
name|reseed
decl_stmt|;
comment|/* reseed function */
name|void
modifier|*
name|arg
decl_stmt|;
comment|/* reseed function argument */
block|}
struct|;
end_struct

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/*  * In all these functions it is important that the caller only use as many  * bits as the LFSR has state.  Also, it isn't guaranteed that an LFSR of  * bit length 32 will have 2^32 unique states before repeating.  */
name|void
name|isc_lfsr_init
parameter_list|(
name|isc_lfsr_t
modifier|*
name|lfsr
parameter_list|,
name|isc_uint32_t
name|state
parameter_list|,
name|unsigned
name|int
name|bits
parameter_list|,
name|isc_uint32_t
name|tap
parameter_list|,
name|unsigned
name|int
name|count
parameter_list|,
name|isc_lfsrreseed_t
name|reseed
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize an LFSR.  *  * Note:  *  *	Putting untrusted values into this function will cause the LFSR to  *	generate (perhaps) non-maximal length sequences.  *  * Requires:  *  *	lfsr != NULL  *  *	8<= bits<= 32  *  *	tap != 0  */
end_comment

begin_function_decl
name|void
name|isc_lfsr_generate
parameter_list|(
name|isc_lfsr_t
modifier|*
name|lfsr
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|unsigned
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns "count" bytes of data from the LFSR.  *  * Requires:  *  *	lfsr be valid.  *  *	data != NULL.  *  *	count> 0.  */
end_comment

begin_function_decl
name|void
name|isc_lfsr_skip
parameter_list|(
name|isc_lfsr_t
modifier|*
name|lfsr
parameter_list|,
name|unsigned
name|int
name|skip
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Skip "skip" states.  *  * Requires:  *  *	lfsr be valid.  */
end_comment

begin_function_decl
name|isc_uint32_t
name|isc_lfsr_generate32
parameter_list|(
name|isc_lfsr_t
modifier|*
name|lfsr1
parameter_list|,
name|isc_lfsr_t
modifier|*
name|lfsr2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Given two LFSRs, use the current state from each to skip entries in the  * other.  The next states are then xor'd together and returned.  *  * WARNING:  *  *	This function is used only for very, very low security data, such  *	as DNS message IDs where it is desired to have an unpredictable  *	stream of bytes that are harder to predict than a simple flooding  *	attack.  *  * Notes:  *  *	Since the current state from each of the LFSRs is used to skip  *	state in the other, it is important that no state be leaked  *	from either LFSR.  *  * Requires:  *  *	lfsr1 and lfsr2 be valid.  *  *	1<= skipbits<= 31  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_LFSR_H */
end_comment

end_unit

